/*	$NetBSD: ka680.c,v 1.17 2010/12/14 23:44:49 matt Exp $	*/
/*
 * Copyright (c) 2002 Hugh Graham.
 * Copyright (c) 2000 Ludd, University of Lule}, Sweden.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Done by Michael Kukat (michael@unixiron.org) */
/* minor modifications for KA690 cache support by isildur@vaxpower.org */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: ka680.c,v 1.17 2010/12/14 23:44:49 matt Exp $");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/cpu.h>
#include <sys/device.h>
#include <sys/kernel.h>

#include <machine/sid.h>
#include <machine/nexus.h>
#include <machine/ka680.h>
#include <machine/clock.h>
#include <machine/scb.h>

static void	ka680_conf(void);
static void	ka680_attach_cpu(device_t);
static void	ka680_cache_enable(void);
static void	ka680_softmem(void *);
static void	ka680_hardmem(void *);
static void	ka680_steal_pages(void);
static void	ka680_memerr(void);
static int	ka680_mchk(void *);
 
/*
 * KA680-specific IPRs. KA680 has the funny habit to control all caches
 * via IPRs.
 */
#define PR_CCTL	 0xa0
#define CCTL_ENABLE	0x00000001
#define CCTL_SW_ETM	0x40000000
#define CCTL_HW_ETM	0x80000000

#define PR_BCETSTS	0xa3
#define PR_BCEDSTS	0xa6
#define PR_NESTS	0xae

#define PR_VMAR	 0xd0
#define PR_VTAG	 0xd1
#define PR_ICSR	 0xd3
#define ICSR_ENABLE	0x01

#define PR_PCCTL	0xf8
#define PCCTL_P_EN	0x10
#define PCCTL_I_EN	0x02
#define PCCTL_D_EN	0x01

 
static const char * const ka680_devs[] = { "cpu", "sgec", "shac", "uba", NULL };

/* 
 * Declaration of KA680-specific calls.
 */
const struct cpu_dep ka680_calls = {
	.cpu_steal_pages = ka680_steal_pages,
	.cpu_mchk	= ka680_mchk,
	.cpu_memerr	= ka680_memerr, 
	.cpu_conf	= ka680_conf,
	.cpu_gettime	= generic_gettime,
	.cpu_settime	= generic_settime,
	.cpu_vups	= 24,	 /* ~VUPS */
	.cpu_scbsz	= 2,	/* SCB pages */
	.cpu_halt	= generic_halt,
	.cpu_reboot	= generic_reboot,
	.cpu_flags	= CPU_RAISEIPL,
	.cpu_devs	= ka680_devs,
	.cpu_attach_cpu	= ka680_attach_cpu,
};


void
ka680_conf(void)
{
	/* Don't ask why, but we seem to need this... */

	volatile int *hej = (void *)mfpr(PR_ISP);
	*hej = *hej;
	hej[-1] = hej[-1];

	cpmbx = (struct cpmbx *)vax_map_physmem(0x20140400, 1);

}

void
ka680_attach_cpu(device_t self)
{
	const char *cpuname;

	switch (vax_boardtype) {
		case VAX_BTYP_680:
			switch((vax_siedata & 0xff00) >> 8) {
			case VAX_STYP_675: cpuname = "KA675"; break;
			case VAX_STYP_680: cpuname = "KA680"; break;
			case VAX_STYP_690: cpuname = "KA690"; break;
			default: cpuname = "unknown KA680-class";
			}
			break;
		case VAX_BTYP_681:
			switch ((vax_siedata & 0xff00) >> 8) {
			case VAX_STYP_681: cpuname = "KA681"; break;
			case VAX_STYP_691: cpuname = "KA691"; break;
			case VAX_STYP_694: cpuname = (vax_cpudata & 0x1000) ?
				"KA694" : "KA692"; break;
			default: cpuname = "unknown KA681-class";
			}
			break;
		default: cpuname = "unknown class"; break;
	}

	aprint_normal("%s, NVAX (ucode rev %d)\n", cpuname, vax_cpudata & 0xff);
}

void
ka680_cache_enable(void)
{
	int start, pslut, fslut, cslut, havevic;

	/*
	 * Turn caches off.
	 */
	mtpr(0, PR_ICSR);
	mtpr(0, PR_PCCTL);
	mtpr(mfpr(PR_CCTL) | CCTL_SW_ETM, PR_CCTL);

	/*
	 * Invalidate caches.
	 */
	mtpr(mfpr(PR_CCTL) | 6, PR_CCTL);	/* Set cache size and speed */
	mtpr(mfpr(PR_BCETSTS), PR_BCETSTS);	/* Clear error bits */
	mtpr(mfpr(PR_BCEDSTS), PR_BCEDSTS);	/* Clear error bits */
	mtpr(mfpr(PR_NESTS), PR_NESTS);	 /* Clear error bits */


	start = 0x01400000;
	/* fallback, use smallest known cache on unknown models */
	fslut = 0x01420000;
	cslut = 0x01020000;
	havevic = 0;
  
	switch(vax_boardtype) {
		case VAX_BTYP_680:
			switch((vax_siedata & 0xff00) >> 8) {
			case VAX_STYP_675:
				fslut = 0x01420000;
				cslut = 0x01020000;
				havevic = 0;
				break;
			case VAX_STYP_680:
				fslut = 0x01420000;
				cslut = 0x01020000;
				havevic = 1;
				break;
			case VAX_STYP_690:
				fslut = 0x01440000;
				cslut = 0x01040000;
				havevic = 1;
				break;
		}
		case VAX_BTYP_681:
			switch((vax_siedata & 0xff00) >> 8) {
			case VAX_STYP_681:
				fslut = 0x01420000;
				cslut = 0x01020000;
				havevic = 1;
				break;
			case VAX_STYP_691:
				fslut = 0x01420000;
				cslut = 0x01020000;
				havevic = 1;
				break;
			case VAX_STYP_694:
				fslut = 0x01440000;
				cslut = 0x01040000;
				havevic = 1;
				break;
		}
	}

	/* Flush cache lines */
	for (; start < fslut; start += 0x20)
		mtpr(0, start);

	mtpr((mfpr(PR_CCTL) & ~(CCTL_SW_ETM|CCTL_ENABLE)) | CCTL_HW_ETM,
	    PR_CCTL);

	start = 0x01000000;

	/* clear tag and valid */
	for (; start < cslut; start += 0x20)
		mtpr(0, start);

	mtpr(mfpr(PR_CCTL) | 6 | CCTL_ENABLE, PR_CCTL); /* enab. bcache */

	start = 0x01800000;
	pslut  = 0x01802000;

	/* Clear primary cache */
	for (; start < pslut; start += 0x20)
		mtpr(0, start);

	/* Flush the pipes (via REI) */
	__asm("movpsl -(%sp); movab 1f,-(%sp); rei; 1:;");

	/* Enable primary cache */
	mtpr(PCCTL_P_EN|PCCTL_I_EN|PCCTL_D_EN, PR_PCCTL);

	/* Enable the VIC */
	if (havevic) {
		int slut;

		start = 0;
		slut  = 0x800;
		for (; start < slut; start += 0x20) {
			mtpr(start, PR_VMAR);
			mtpr(0, PR_VTAG);
		}
		mtpr(ICSR_ENABLE, PR_ICSR);
	}
}

/*
 * Why may we get memory errors during startup???
 */

void
ka680_hardmem(void *arg)
{
	if (cold == 0)
		printf("Hard memory error\n");
	splhigh();
}

void
ka680_softmem(void *arg)
{
	if (cold == 0)
		printf("Soft memory error\n");
	splhigh();
}

void
ka680_steal_pages(void)
{
	/*
	 * Get the soft and hard memory error vectors now.
	 */
	scb_vecalloc(0x54, ka680_softmem, NULL, 0, NULL);
	scb_vecalloc(0x60, ka680_hardmem, NULL, 0, NULL);

	/* Turn on caches (to speed up execution a bit) */
	ka680_cache_enable();
}

void
ka680_memerr(void)
{
	printf("Memory err!\n");
}

int
ka680_mchk(void *addr)
{
	panic("Machine check");
	return 0;
}
