# $OpenBSD$

OST_IN =		Newspeak
OST_VM =		Stack
OST_OR =		Spur

.include <bsd.port.arch.mk>

.if ${PROPERTIES:Mlp64}
CONFIGURE_ARGS +=	--with-src=nsspurstack64src
.else
CONFIGURE_ARGS +=	--with-src=nsspurstacksrc
.endif

CONFIGURE_ARGS +=	--with-vmversion=5.0 --disable-cogit --without-vm-display-fbdev

# 2017/12/25 cointerp doesn't build
MAKE_FLAGS +=		INTERP=interp

post-install: demenage

.include <bsd.port.mk>
