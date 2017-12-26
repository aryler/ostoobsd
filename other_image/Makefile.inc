# $OpenBSD$

COMMENT =		opensmalltalk image

DISTNAME ?=
OST_DISTNAME ?=		${DISTNAME}
PKGNAME ?=		ostI_${OST_PKGNAME}

CATEGORIES =		lang
HOMEPAGE ?=		http://opensmalltalk.org/
MAINTAINER =		Stuart Cassoff <stwo@users.sourceforge.net>

# ?
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =		${OST_SITE:=${OST_SITE_DIR}/}
EXTRACT_ONLY =
EXTRACT_SUFX =		.zip
DIST_SUBDIR =		${OST_HOME}
NO_BUILD =		Yes
PKG_ARCH =		*
SUBST_VARS =		OST_HOME OST_IMG_VER OST_IMG_REL

OST_SITE ?=		http://files.squeak.org/
OSR_SITE_DIR ?=

V ?=
OST_HOME =		opensmalltalk
OST_IMG_VER ?=		${V}
OST_IMG_REL ?=		${R}
OST_INSTALL_DIR =	${PREFIX}/share/${OST_HOME}
OST_EXCLUDE ?=

OST_OLD_NAME ?=
OST_NEW_NAME ?=

do-install:
	${INSTALL_DATA_DIR} ${OST_INSTALL_DIR}
	unzip -q -j ${FULLDISTDIR}/${OST_DISTNAME}${EXTRACT_SUFX} ${OST_EXCLUDE:S/^/-x /1} -d ${OST_INSTALL_DIR}

rename:
	mv ${OST_INSTALL_DIR}/${OST_OLD_NAME}.image   ${OST_INSTALL_DIR}/${OST_NEW_NAME}.image
	mv ${OST_INSTALL_DIR}/${OST_OLD_NAME}.changes ${OST_INSTALL_DIR}/${OST_NEW_NAME}.changes

post-install: ost-post-install
ost-post-install:

.PHONY: ost-post-install rename
