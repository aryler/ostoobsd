# $OpenBSD$

NOT_FOR_ARCHS =		${LP64_ARCHS}

OST_IN =		Squeak
OST_VM =		Stack
OST_OR =		V3

.include <bsd.port.arch.mk>

CONFIGURE_ARGS +=	--with-src=stacksrc --disable-cogit --without-vm-display-fbdev

# Any combination of one or more will build a non-crashing vm.
#CC =			clang
#CFLAGS +=		-fno-pie
MAKE_FLAGS +=		INTERP=interp

.include <bsd.port.mk>
