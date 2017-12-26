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

#CFLAGS +=		-Wno-unused-value -Wno-int-conversion -Wno-implicit-function-declaration -Wno-return-type

.include <bsd.port.mk>
