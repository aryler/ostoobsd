# $OpenBSD$

NOT_FOR_ARCHS =		${LP64_ARCHS}

OST_IN =		Squeak
OST_VM =		Stack
OST_OR =		V3

OST_VM_VER =		4.5

.include <bsd.port.arch.mk>

CONFIGURE_ARGS +=	--with-src=stacksrc --disable-cogit --without-vm-display-fbdev

# 2017/12/25 cointerp doesn't build
MAKE_FLAGS +=		INTERP=interp

.include <bsd.port.mk>
