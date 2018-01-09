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

#CFLAGS +=		-Wno-unused-value -Wno-int-conversion -Wno-implicit-function-declaration -Wno-return-type -Wno-tautological-compare -Wno-incompatible-pointer-types -Wno-parentheses -Wno-parentheses-equality -Wno-dangling-else -Wno-tautological-pointer-compare -Wno-incompatible-function-pointer-types -Wno-unused-function -Wno-unused-variable -Wno-conditional-type-mismatch -Wno-tautological-constant-out-of-range-compare -Wno-logical-op-parentheses -Wno-shift-op-parentheses -Wno-compare-distinct-pointer-types -Wno-format -Wno-comment -Wno-undefined-inline
CFLAGS +=		-Wno-unused-value -Wno-int-conversion                                    -Wno-return-type -Wno-tautological-compare -Wno-incompatible-pointer-types -Wno-parentheses -Wno-parentheses-equality -Wno-dangling-else -Wno-tautological-pointer-compare -Wno-incompatible-function-pointer-types -Wno-unused-function -Wno-unused-variable -Wno-conditional-type-mismatch -Wno-tautological-constant-out-of-range-compare -Wno-logical-op-parentheses -Wno-shift-op-parentheses -Wno-compare-distinct-pointer-types -Wno-format              -Wno-undefined-inline
CFLAGS +=		-Wno-strlcpy-strlcat-size

.include <bsd.port.mk>
