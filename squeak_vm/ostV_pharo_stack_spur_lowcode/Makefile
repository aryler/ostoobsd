# $OpenBSD$

OST_IN =		Pharo
OST_VM =		Stack
OST_OR =		Spur.Lowcode

.include <bsd.port.arch.mk>

.if ${PROPERTIES:Mlp64}
CONFIGURE_ARGS +=	--with-src=spurlowcodestack64src
.else
CONFIGURE_ARGS +=	--with-src=spurlowcodestacksrc
.endif

CONFIGURE_ARGS +=	--with-vmversion=5.0 --disable-cogit

CFLAGS +=		-DPharoVM -DIMMUTABILITY=1

.if ! ${PROPERTIES:Mlp64}
# Any combination of one or more will build a non-crashing vm.
#CFLAGS +=		-fno-pie
MAKE_FLAGS +=		INTERP=interp
.endif

post-extract:
.if ${PROPERTIES:Mlp64}
	mkdir ${WRKDIST}/build.linux${SQ_ARCH}/${SQ_IN}.${SQ_VM}.${SQ_OR}
	cp ${WRKDIST}/build.linux32x86/${SQ_IN}.${SQ_VM}.${SQ_OR}/plugins.{int,ext} \
	   ${WRKDIST}/build.linux${SQ_ARCH}/${SQ_IN}.${SQ_VM}.${SQ_OR}/
.endif

post-install:
	mv ${PREFIX}/lib/${OST_HOME}/squeak ${PREFIX}/lib/${OST_HOME}/${SQ_IN}
	mv ${PREFIX}/lib/${OST_HOME}/${SQ_IN}/${OST_VM_VER}-SistaSpurVM/squeak \
	   ${PREFIX}/lib/${OST_HOME}/${SQ_IN}/${OST_VM_VER}-SistaSpurVM/${SQ_IN}

.include <bsd.port.mk>
