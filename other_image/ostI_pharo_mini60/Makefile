# $OpenBSD$

N =		pharo_mini

V =		6.0
R =		60528${L}
L =		-minimal

T =		Pharo
D =		${T}${V}-${R}

DISTNAME =	${D}{${R}}
OST_DISTNAME =	${D}
OST_PKGNAME =	${N}-${V}

HOMEPAGE =	http://pharo.org/

OST_SITE =	http://files.pharo.org/
OST_SITE_DIR =	image/${V:S/.//}

OST_OLD_NAME =	${T}${L}
OST_NEW_NAME =	${D}

post-install: rename

.include <bsd.port.mk>
