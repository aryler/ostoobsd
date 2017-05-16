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

.if ! ${PROPERTIES:Mlp64}
# Any combination of one or more will build a non-crashing vm.
#CC =			clang
#CFLAGS +=		-fno-pie
MAKE_FLAGS +=		INTERP=cointerp
.endif

post-install: demenage

.include <bsd.port.mk>
