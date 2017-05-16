# $OpenBSD$

N =		pharo

V =		5.0
R =		50772

T =		Pharo
D =		${T}${V}-${R}
B =		-64

DISTNAME =	${D}{${R}}${B}
OST_DISTNAME =	${D}${B}
OST_PKGNAME =	${N}${B:S/-/_/}-${V}

HOMEPAGE =	http://pharo.org/

OST_SITE =	http://files.pharo.org/
OST_SITE_DIR =	image/${V:S/.//}

OST_OLD_NAME =	${T}${B:S/-//}-${R}
OST_NEW_NAME =	${D}${B}bit

post-install: rename

.include <bsd.port.mk>
