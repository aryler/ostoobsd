# $OpenBSD$

NOT_FOR_ARCHS =		${LP64_ARCHS}

OST_IN =		Pharo
OST_VM =		Cog
OST_OR =		Spur.Lowcode

.include <bsd.port.arch.mk>

CONFIGURE_ARGS +=	--with-src=spurlowcodesrc --with-vmversion=5.0

CFLAGS +=		-DCOGMTVM=0 -DPharoVM -DIMMUTABILITY=1

post-install:
	mv ${PREFIX}/lib/${OST_HOME}/squeak ${PREFIX}/lib/${OST_HOME}/${SQ_IN}
	mv ${PREFIX}/lib/${OST_HOME}/${SQ_IN}/${OST_VM_VER}-SistaSpurVM/squeak \
	   ${PREFIX}/lib/${OST_HOME}/${SQ_IN}/${OST_VM_VER}-SistaSpurVM/${SQ_IN}

.include <bsd.port.mk>
