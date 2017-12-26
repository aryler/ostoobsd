# $OpenBSD$

OST_IN =		Newspeak
OST_VM =		Cog
OST_OR =		Spur

.include <bsd.port.arch.mk>

.if ${PROPERTIES:Mlp64}
CONFIGURE_ARGS +=	--with-src=nsspur64src
.else
CONFIGURE_ARGS +=	--with-src=nsspursrc
.endif

CONFIGURE_ARGS +=	--with-vmversion=5.0 --without-vm-display-fbdev

post-install: demenage

.include <bsd.port.mk>
