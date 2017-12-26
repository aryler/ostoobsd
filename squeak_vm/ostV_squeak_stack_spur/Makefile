# $OpenBSD$

OST_IN =		Squeak
OST_VM =		Stack
OST_OR =		Spur

.include <bsd.port.arch.mk>

.if ${PROPERTIES:Mlp64}
CONFIGURE_ARGS +=	--with-src=spurstack64src
COPTS =			-O1 -fwrapv
.else
CONFIGURE_ARGS +=	--with-src=spurstacksrc
.endif

CONFIGURE_ARGS +=	--with-vmversion=5.0 --disable-cogit --without-vm-display-fbdev

# 2017/12/25 cointerp doesn't build
MAKE_FLAGS +=		INTERP=interp

.include <bsd.port.mk>
