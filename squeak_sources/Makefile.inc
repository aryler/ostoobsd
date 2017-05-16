# $OpenBSD$

COMMENT =		opensmalltalk sources

N =			ostS_squeak

SQ_SITE =		http://files.squeak.org/
SQ_SITE_DIR ?=		${V}
SQ_INSTALL_DIR =	${PREFIX}/share/opensmalltalk

DISTNAME ?=		SqueakV${V:S/.//}.sources
PKGNAME =		${N}-${V}
CATEGORIES =		lang
HOMEPAGE =		http://opensmalltalk.org/
MAINTAINER =		Stuart Cassoff <stwo@users.sourceforge.net>

# ?
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =		${SQ_SITE:=${SQ_SITE_DIR}/}
EXTRACT_ONLY =
EXTRACT_SUFX ?=		.zip
DIST_SUBDIR =		${OST_HOME}
NO_BUILD =		Yes
PKG_ARCH =		*
SUBST_VARS =		OST_HOME OST_SRC_VER

OST_HOME =		opensmalltalk
OST_SRC_VER ?=		V${V:S/.//g:C/0*$//}

do-install:
	${INSTALL_DATA_DIR} ${SQ_INSTALL_DIR}
.if ${EXTRACT_SUFX:M.gz}
	gunzip < ${FULLDISTDIR}/${DISTFILES} > ${SQ_INSTALL_DIR}/${DISTNAME}
.else
	unzip -q -j ${FULLDISTDIR}/${DISTFILES} -d ${SQ_INSTALL_DIR}
.endif
