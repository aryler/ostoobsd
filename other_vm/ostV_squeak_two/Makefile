# $OpenBSD$

OST_IN =		squeak
OST_VM =
OST_OR =
V =			2.4
N = 			${OST_IN}

COMMENT =		${OST_IN} interpreter

DISTNAME =		${V}
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
ALL_TARGET =		interp plugins
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

SQ_BIN_DIR =	${OST_BIN_DIR}/${OST_IN}/${V}

pre-build:
	perl -pi -e 's,\(char\*\),,' ${WRKSRC}/Squeak3D/b3dRemap.c

do-install:
	${INSTALL_DATA_DIR} ${SQ_BIN_DIR}
	${INSTALL_PROGRAM}  ${WRKSRC}/squeak             ${SQ_BIN_DIR}/
	${INSTALL_DATA}     ${WRKSRC}/SoundCodecPrims.so ${SQ_BIN_DIR}/
	${INSTALL_DATA}     ${WRKSRC}/Squeak3D.so        ${SQ_BIN_DIR}/

.include <bsd.port.mk>
