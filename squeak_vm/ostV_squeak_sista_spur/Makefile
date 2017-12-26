# $OpenBSD$

NOT_FOR_ARCHS =		${LP64_ARCHS}

OST_IN =		Squeak
OST_VM =		Sista
OST_OR =		Spur

.include <bsd.port.arch.mk>

CONFIGURE_ARGS +=	--with-src=spursistasrc --with-vmversion=5.0

CFLAGS +=		-DCOGMTVM=0

USE_WXNEEDED =		Yes
SQ_LDFLAGS +=		-Wl,-z,wxneeded

.include <bsd.port.mk>
