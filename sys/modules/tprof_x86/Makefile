#	$NetBSD: Makefile,v 1.1 2018/07/16 06:18:31 maxv Exp $

.include "../Makefile.inc"

CPPFLAGS+=

.PATH:	${S}/dev/tprof

KMOD=	tprof_x86
SRCS=	tprof_x86.c tprof_x86_amd.c tprof_x86_intel.c

.include <bsd.kmodule.mk>
