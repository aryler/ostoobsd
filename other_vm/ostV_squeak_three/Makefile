# $OpenBSD$

OST_IN =		squeak
OST_VM =
OST_OR =
V =			3.10-1
N = 			${OST_IN}

COMMENT =		${OST_IN} interpreter

DISTNAME =		Squeak-${V}
OST_PKGNAME =		${N}-${V:S/-/./}
CATEGORIES =		lang
HOMEPAGE =		http://opensmalltalk.org/
MAINTAINER =		Stuart Cassoff <stwo@users.sourceforge.net>

# ?
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		GL ICE SM X11 Xext Xrender c m pthread util

MASTER_SITES =		http://files.squeak.org/3.10/unix-linux/
DISTFILES =		Squeak-${V:S/-/./g}-{${DISTNAME}.}src${EXTRACT_SUFX}

SEPARATE_BUILD =	Yes
USE_GMAKE =		Yes
#LIBTOOL =		${WRKBUILD}/libtool
USE_LIBTOOL =		No
CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	ac_cv_socklen_t=yes --without-npsqueak LDFLAGS='${SQ_LDFLAGS}' LIBS='${SQ_LIBS}' --libdir=${PREFIX}/lib/opensmalltalk
#CFLAGS =		-g -pipe -pthread -msse2 -DNDEBUG -DDEBUGVM=0 -D_GNU_SOURCE -I/usr/local/include
#CFLAGS =		-g -pipe -pthread -msse2 -DNDEBUG -DDEBUGVM=0 -D_GNU_SOURCE -I/usr/local/include -DNO_VM_PROFILE=1
#CFLAGS =		-g -pipe -pthread -msse2 -DDEBUGVM=1 -D_GNU_SOURCE -I/usr/local/include
CFLAGS =		-pipe -pthread
CFLAGS += -Wno-return-type -Wno-int-to-pointer-cast -Wno-implicit-function-declaration
COPTS ?=		-O2
WRKSRC =		${WRKDIST}/platforms/unix/config
DESTDIRNAME =		ROOT
ALL_TARGET =		squeak plugins
INSTALL_TARGET =	install-squeak install-plugins
NO_TEST =		Yes

SQ_LDFLAGS =		-L/usr/local/lib
SQ_LIBS =		-lpthread

OST_VM_VER =		${V}${P}

.include <bsd.port.arch.mk>

#CC =			clang

.if ${PROPERTIES:Mlp64}
SQ_ARCH =		64x64
# Builds gnu-interp
CONFIGURE_ARGS +=	--with-gnu-awk=yes
.else
SQ_ARCH =		32x86
CFLAGS +=		-D_FILE_OFFSET_BITS=64
.endif

pre-build:
	@perl -pi -e s,dprintf,debugprintf, ${WRKDIST}/platforms/unix/vm/*.c
	@perl -pi -e s,"define dprintf","define debugprintf", ${WRKDIST}/platforms/unix/vm/debug.h

post-install:
	rm -f  ${WRKINST}/usr/local/squeak
	rm -f  ${WRKINST}/usr/local/bin/squeak
	rm -fr ${WRKINST}/usr/local/doc
	rm -f  ${WRKINST}/usr/local/man/man1/{,ini}squeak.1

.include <bsd.port.mk>
