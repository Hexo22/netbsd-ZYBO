#	$NetBSD: Makefile,v 1.4 2002/01/27 01:07:44 minoura Exp $

NOMAN=		# defined

PROG=		installboot
SRCS=		installboot.c
BINDIR=		/usr/mdec
WARNS=		2
LDSTATIC=	-static
#MANSUBDIR=	/x68k

DISKLABELDIR=	${.CURDIR}/../../../../../sbin/disklabel

CPPFLAGS+=	-I${DISKLABELDIR}
.PATH:		${DISKLABELDIR}
SRCS+=		dkcksum.c

.include <bsd.prog.mk>
