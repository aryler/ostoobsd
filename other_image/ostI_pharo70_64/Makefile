# $OpenBSD$

N =		pharo

V =		7.0
R =		d0d44c1

T =		Pharo
D =		${T}${V}-${R}
B =		-64

DISTNAME =	${D}${B}{${T}${V}${B}bit-${R}}
OST_DISTNAME =	${D}${B}
OST_PKGNAME =	${N}${B:S/-/_/}-${V}

HOMEPAGE =	http://pharo.org/

OST_SITE =	http://files.pharo.org/
OST_SITE_DIR =	image/${V:S/.//}
OST_EXCLUDE =	${T}${V}-32bit-${R}.sources

OST_OLD_NAME =	${T}${V}${B}bit-${R}
OST_NEW_NAME =	${D}${B}bit

post-install: rename

.include <bsd.port.mk>
