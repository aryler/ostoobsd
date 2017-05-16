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

.if ! ${PROPERTIES:Mlp64}
# Any combination of one or more will build a non-crashing vm.
#CFLAGS +=		-fno-pie
MAKE_FLAGS +=		INTERP=interp
.endif

.include <bsd.port.mk>
