# $OpenBSD$

COMMENT =		opensmalltalk image

N ?=			squeak

DISTNAME =		Squeak${V}${R:S/^/-/}${BS}
PKGNAME =		ostI_${N}${B}-${V}
CATEGORIES =		lang
HOMEPAGE =		http://opensmalltalk.org/
MAINTAINER =		Stuart Cassoff <stwo@users.sourceforge.net>

# ?
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =		${SQ_SITE:=${SQ_SITE_DIR}/}
EXTRACT_ONLY =
EXTRACT_SUFX =		.zip
DIST_SUBDIR =		${OST_HOME}
NO_BUILD =		Yes
SUBST_VARS =		OST_HOME OST_IMG_VER

SQ_SITE =		http://files.squeak.org/
SQ_SITE_DIR ?=		${V}

OST_HOME =		opensmalltalk
OST_IMG_VER ?=		${V}${R:S/^/-/}${BS}
OST_INSTALL_DIR =	${PREFIX}/share/${OST_HOME}
OST_EXCLUDE ?=

do-install:
	${INSTALL_DATA_DIR} ${OST_INSTALL_DIR}
	unzip -q -j ${FULLDISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${OST_EXCLUDE:S/^/-x /1} -d ${OST_INSTALL_DIR}
