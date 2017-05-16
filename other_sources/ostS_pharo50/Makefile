# $OpenBSD$

COMMENT =		opensmalltalk sources

N =			pharo

V =			5.0
D =			PharoV${V:S/.//}.sources

DISTNAME =		${D}{sources}
PKGNAME =		ostS_${N}-${V}
CATEGORIES =		lang
HOMEPAGE =		http://pharo.org/
MAINTAINER =		Stuart Cassoff <stwo@users.sourceforge.net>

# ?
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =		http://files.pharo.org/get-files/${V:S/.//}/
EXTRACT_ONLY =
EXTRACT_SUFX =		.zip
NO_BUILD =		Yes

SQ_INSTALL_DIR =	${PREFIX}/share/opensmalltalk

do-install:
	${INSTALL_DATA_DIR} ${SQ_INSTALL_DIR}
	unzip -q -j ${FULLDISTDIR}/${D} -d ${SQ_INSTALL_DIR}

.include <bsd.port.mk>
