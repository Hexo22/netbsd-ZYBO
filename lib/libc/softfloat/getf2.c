/* $NetBSD: getf2.c,v 1.1 2000/06/06 08:15:05 bjh21 Exp $ */

/*
 * Written by Matt Thomas, 2011.  This file is in the Public Domain.
 */

#include "softfloat-for-gcc.h"
#include "milieu.h"
#include "softfloat.h"

#include <sys/cdefs.h>
#if defined(LIBC_SCCS) && !defined(lint)
__RCSID("$NetBSD: getf2.c,v 1.1 2000/06/06 08:15:05 bjh21 Exp $");
#endif /* LIBC_SCCS and not lint */

#ifdef FLOAT128

flag __getf2(float128, float128);

flag
__getf2(float128 a, float128 b)
{

	/* libgcc1.c says (a >= b) - 1 */
	return float128_le(b, a) - 1;
}

#endif /* FLOAT128 */