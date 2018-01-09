# $OpenBSD$

COMMENT =		ost ${OST_IN} interp with ${OST_VM} vm and ${OST_OR} objects

N = 			${SQ_IN}_${SQ_VM}_${SQ_OR:S/3/three/:S/./_/}

V =			5.1

DISTNAME =		opensmalltalk-${V}pl0
PKGNAME =		ostV_${N}-${V}
CATEGORIES =		lang
HOMEPAGE =		http://opensmalltalk.org/
MAINTAINER =		Stuart Cassoff <stwo@users.sourceforge.net>

# ?
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		GL ICE SM X11 Xext c crypto execinfo m pthread
WANTLIB +=		ssl util

GH_ACCOUNT =		opensmalltalk
GH_PROJECT =		opensmalltalk-vm
GH_COMMIT =		9d39149b257141914497d9c7454e3a2ce6193ec8

DIST_SUBDIR =		${OST_HOME}
BUILD_DEPENDS =		net/curl	# For st src building/fetching
LIB_DEPENDS =		devel/libexecinfo converters/libiconv
SEPARATE_BUILD =	Yes
USE_GMAKE =		Yes
LIBTOOL =		${WRKBUILD}/libtool
CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	ac_cv_socklen_t=yes --without-npsqueak LDFLAGS='${SQ_LDFLAGS}' LIBS='${SQ_LIBS}' --libdir='${PREFIX}/lib/${OST_HOME}'
CFLAGS =		-g -pipe -pthread -msse2 -DNDEBUG -DDEBUGVM=0 -D_GNU_SOURCE -I/usr/local/include
#CFLAGS =		-g -pipe -pthread -msse2 -DNDEBUG -DDEBUGVM=0 -D_GNU_SOURCE -I/usr/local/include -DNO_VM_PROFILE=1
#CFLAGS =		-g -pipe -pthread -msse2 -DDEBUGVM=1 -D_GNU_SOURCE -I/usr/local/include

# So that autoconf finds iconv.h.
# Others?
CONFIGURE_ENV +=	CPPFLAGS=-I/usr/local/include

COPTS ?=		-O2
SQ_LDFLAGS =		-L/usr/local/lib -Wl,-z,now
SQ_LIBS =		-lpthread -lexecinfo
WRKSRC =		${WRKDIST}/platforms/unix/config
DESTDIRNAME =		ROOT
ALL_TARGET =		getversion squeak plugins
INSTALL_TARGET =	install-squeak install-plugins
NO_TEST =		Yes
CHECKSUM_FILE =		${PKGDIR:H:H}/distinfo
PATCHDIR =		${PKGDIR:H:H}/patches
SUBST_VARS =		OST_HOME OST_VM_VER OST_INTERP

OST_HOME =		opensmalltalk
OST_VM_VER ?=		5.0
OST_INTERP ?=		${SQ_IN}

SQ_IN =			${OST_IN:L}
SQ_VM =			${OST_VM:L}
SQ_OR =			${OST_OR:L}

.include <bsd.port.arch.mk>

.if ${PROPERTIES:Mlp64}
SQ_ARCH =		64x64
.else
SQ_ARCH =		32x86
CFLAGS +=		-D_FILE_OFFSET_BITS=64
.endif

.if ${SQ_VM:Mcog}
USE_WXNEEDED =		Yes
SQ_LDFLAGS +=		-Wl,-z,wxneeded
.endif

pre-configure:
	cp ${WRKDIST}/build.linux${SQ_ARCH}/${SQ_IN}.${SQ_VM}.${SQ_OR}/plugins.{int,ext} ${WRKBUILD}

post-install: squeak-post-install
squeak-post-install:
	rm -f  ${WRKINST}/usr/local/squeak
	rm -f  ${WRKINST}/usr/local/bin/squeak
	rm -fr ${WRKINST}/usr/local/doc
	rm -f  ${WRKINST}/usr/local/man/man1/{,ini}squeak.1

demenage:
	mv ${PREFIX}/lib/${OST_HOME}/squeak ${PREFIX}/lib/${OST_HOME}/${SQ_IN}
	mv ${PREFIX}/lib/${OST_HOME}/${SQ_IN}/${OST_VM_VER}-${OST_VM}${OST_OR}VM/squeak \
	   ${PREFIX}/lib/${OST_HOME}/${SQ_IN}/${OST_VM_VER}-${OST_VM}${OST_OR}VM/${SQ_IN}

.PHONY: squeak-post-install demenage
