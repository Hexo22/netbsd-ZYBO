/*	$NetBSD: infinity.c,v 1.7 2000/09/13 22:32:27 msaitoh Exp $	*/

#include <sys/cdefs.h>
#if defined(LIBC_SCCS) && !defined(lint)
__RCSID("$NetBSD: infinity.c,v 1.7 2000/09/13 22:32:27 msaitoh Exp $");
#endif /* LIBC_SCCS and not lint */
/*
 * XXX - This is not correct, but what can we do about it???
 */

/* infinity.c */

#include <math.h>

/* The highest D float on a vax. */
const union __double_u __infinity =
	{ { 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff } };