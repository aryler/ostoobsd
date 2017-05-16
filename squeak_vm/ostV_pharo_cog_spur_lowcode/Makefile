# $OpenBSD$

NOT_FOR_ARCHS =		${LP64_ARCHS}

OST_IN =		Pharo
OST_VM =		Cog
OST_OR =		Spur.Lowcode

.include <bsd.port.arch.mk>

CONFIGURE_ARGS +=	--with-src=spurlowcodesrc --with-vmversion=5.0

CFLAGS +=		-DCOGMTVM=0 -DPharoVM -DIMMUTABILITY=1

.if ! ${PROPERTIES:Mlp64}
# Any combination of one or more will build a non-crashing vm.
#CFLAGS +=		-fno-pie
MAKE_FLAGS +=		INTERP=cointerp
.endif

post-install:
	mv ${PREFIX}/lib/squeak ${PREFIX}/lib/pharo
	mv ${PREFIX}/lib/pharo/5.0-SistaSpurVM/squeak ${PREFIX}/lib/pharo/5.0-SistaSpurVM/pharo

post-install:
	mv ${PREFIX}/lib/${OST_HOME}/squeak ${PREFIX}/lib/${OST_HOME}/${SQ_IN}
	mv ${PREFIX}/lib/${OST_HOME}/${SQ_IN}/${OST_VM_VER}-SistaSpurVM/squeak \
	   ${PREFIX}/lib/${OST_HOME}/${SQ_IN}/${OST_VM_VER}-SistaSpurVM/${SQ_IN}

.include <bsd.port.mk>
