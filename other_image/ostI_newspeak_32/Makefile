# $OpenBSD$

N =		newspeak
V =		2017.09.05
B =		32

DISTNAME =	ns-${V:S/./-/g}.${B}
OST_PKGNAME =	${N}_${B}-${V}

OST_SITE =	https://bitbucket.org/newspeaklanguage/newspeak/
OST_SITE_DIR =	downloads
OST_EXCLUDE =	'*newspeaktip' '*nsboottip' '*README.md' '*SqueakV50.sources'

OST_OLD_NAME =	${DISTNAME}
OST_NEW_NAME =	Newspeak-${V}-${B}bit

post-install: rename

.include <bsd.port.mk>
