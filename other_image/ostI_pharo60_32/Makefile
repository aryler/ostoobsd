# $OpenBSD$

N =		pharo

V =		6.0
R =		60528

T =		Pharo
D =		${T}${V}-${R}
B =		-32

DISTNAME =	${D}${B}{${R}}
OST_DISTNAME =	${D}${B}
OST_PKGNAME =	${N}${B:S/-/_/}-${V}

HOMEPAGE =	http://pharo.org/

OST_SITE =	http://files.pharo.org/
OST_SITE_DIR =	image/${V:S/.//}

OST_OLD_NAME =	${T}-${R}
OST_NEW_NAME =	${D}${B}bit

post-install: rename

.include <bsd.port.mk>
