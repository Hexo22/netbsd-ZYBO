/* $NetBSD: display_timing.h,v 1.1 2017/06/03 14:48:02 jmcneill Exp $ */

/*-
 * Copyright (c) 2018 Jared McNeill <jmcneill@invisible.ca>
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
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _FDT_SYSCON_H
#define _FDT_SYSCON_H

struct syscon {
	void		*priv;

	void		(*lock)(void *);
	void		(*unlock)(void *);
	uint32_t	(*read_4)(void *, bus_size_t);
	void		(*write_4)(void *, bus_size_t, uint32_t);
};

#define	syscon_lock(_syscon)					\
	(_syscon)->lock((_syscon)->priv)

#define	syscon_unlock(_syscon)					\
	(_syscon)->unlock((_syscon)->priv)

#define	syscon_read_4(_syscon, _reg)				\
	(_syscon)->read_4((_syscon)->priv, (_reg))

#define	syscon_write_4(_syscon, _reg, _val)			\
	(_syscon)->write_4((_syscon)->priv, (_reg), (_val))


#endif /* !_FDT_SYSCON_H */