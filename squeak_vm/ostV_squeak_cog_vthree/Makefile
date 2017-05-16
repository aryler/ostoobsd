# $OpenBSD$

NOT_FOR_ARCHS =		${LP64_ARCHS}

OST_IN =		Squeak
OST_VM =		Cog
OST_OR =		V3

OST_VM_VER =		4.5

.include <bsd.port.arch.mk>

CFLAGS +=		-DCOGMTVM=0

# Any combination of one or more will build a non-crashing vm.
#CC =			clang
#CFLAGS +=		-fno-pie
MAKE_FLAGS +=		INTERP=cointerp

.include <bsd.port.mk>
