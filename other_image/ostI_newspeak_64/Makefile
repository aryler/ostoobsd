# $OpenBSD$

N =		newspeak
V =		2017.02.25
B =		64

DISTNAME =	ns-${V:S/./-/g}.${B}
OST_PKGNAME =	${N}_${B}-${V}

OST_SITE =	https://bitbucket.org/newspeaklanguage/newspeak/
OST_SITE_DIR =	downloads
OST_EXCLUDE =	newspeaktip nsboottip

OST_OLD_NAME =	${DISTNAME}
OST_NEW_NAME =	Newspeak-${V}-${B}bit

post-install: rename

.include <bsd.port.mk>
