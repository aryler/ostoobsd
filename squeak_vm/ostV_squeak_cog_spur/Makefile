# $OpenBSD$

OST_IN =		Squeak
OST_VM =		Cog
OST_OR =		Spur

.include <bsd.port.arch.mk>

.if ${PROPERTIES:Mlp64}
CONFIGURE_ARGS +=	--with-src=spur64src
.else
CONFIGURE_ARGS +=	--with-src=spursrc
.endif

CONFIGURE_ARGS +=	--with-vmversion=5.0

CFLAGS +=		-DCOGMTVM=0

.if ! ${PROPERTIES:Mlp64}
# Any combination of one or more will build a non-crashing vm.
#CC =			clang
#CFLAGS +=		-fno-pie
MAKE_FLAGS +=		INTERP=cointerp
.endif

.include <bsd.port.mk>
