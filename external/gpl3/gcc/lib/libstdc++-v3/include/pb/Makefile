#	$NetBSD: Makefile,v 1.1 2014/03/01 10:00:48 mrg Exp $

.include <bsd.init.mk>

.include "${.CURDIR}/../../arch/${GCC_MACHINE_ARCH}/defs.mk"

.cc: # disable .cc->NULL transform

DIST=		${GCCDIST}
GNUHOSTDIST=	${DIST}

INCS=		${G_pb_headers1} ${G_pb_headers2} ${G_pb_headers3} ${G_pb_headers4}
INCS+=		${G_pb_headers5} ${G_pb_headers6} ${G_pb_headers7}
INCSDIR=	/usr/include/g++

.PATH:	${DIST}/libstdc++-v3/include

# Get default targets including <bsd.inc.mk>.
.include <bsd.prog.mk>
