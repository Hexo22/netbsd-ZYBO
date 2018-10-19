/*	$NetBSD: altqconf.h,v 1.3 2002/09/06 13:18:45 gehenna Exp $	*/

#ifdef _KERNEL

#if defined(_KERNEL_OPT)
#include "opt_altq_enabled.h"
#endif

#include <sys/conf.h>

#ifdef ALTQ
#define	NALTQ	1
#else
#define	NALTQ	0
#endif

#endif /* _KERNEL */