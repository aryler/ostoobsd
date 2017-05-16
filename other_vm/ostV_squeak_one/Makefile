# $OpenBSD$

OST_IN =		squeak
OST_VM =
OST_OR =
V =			1.3
P =			1
N = 			${OST_IN}

COMMENT =		${SQ_IN} interpreter

DISTNAME =		${V}${P}
OST_PKGNAME =		${N}-${V:S/-/./}
CATEGORIES =		lang
HOMEPAGE =		http://opensmalltalk.org/
MAINTAINER =		Stuart Cassoff <stwo@users.sourceforge.net>

# ?
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		X11 Xext c m pthread

MASTER_SITES =		http://files.squeak.org/${V}/
DISTFILES =		Squeak-${V}-src{${V}}${EXTRACT_SUFX}

USE_GMAKE =		Yes
MAKE_FLAGS =		VM=squeak -I ${WRKSRC}
#CFLAGS =		-msse2 -DNDEBUG -DDEBUGVM=0 -D_GNU_SOURCE -DNO_VM_PROFILE=1
MAKE_FILE =		GNUmakefile
WRKSRC =		${WRKDIST}/src
ALL_TARGET =		interp
NO_TEST =		Yes

.include <bsd.port.arch.mk>

.if ${PROPERTIES:Mlp64}
#SQ_ARCH =		64x64
CC +=			-m64
CXX +=			-m64
.else
#SQ_ARCH =		32x86
CC +=			-m32
CXX +=			-m32
#CFLAGS +=		-D_FILE_OFFSET_BITS=64
.endif

SQ_BIN_DIR =		${OST_BIN_DIR}/squeak/${V}${P}

do-install:
	${INSTALL_DATA_DIR} ${SQ_BIN_DIR}
	${INSTALL_PROGRAM}  ${WRKSRC}/squeak ${SQ_BIN_DIR}/

.include <bsd.port.mk>
