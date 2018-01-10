# $OpenBSD$

# VM, Image and Sources must already be installed.
# The Smalltalk scripts will download ... things?
# Ajdust V,R,B as needed. Try building with different VMs!

N =			vmmaker

V =			6.0alpha
R =			17595
B =			_64

BS =			${B:S/_/-/}bit

T =			VMMaker

OST_VM_VER =		5.0
OST_VM =		Cog
OST_OR =		Spur

VM =			${OST_VM_VER}-${OST_VM}${OST_OR}VM
SQ =			${LOCALBASE}/lib/opensmalltalk/squeak/${VM}/squeak

DISTFILES =
SEPARATE_BUILD =	Yes
NO_BUILD =		No

do-build:
	cp ${OST_INSTALL_DIR}/SqueakV50.sources ${WRKBUILD}
	cp ${OST_INSTALL_DIR}/Squeak${OST_IMG_VER}.image   ${WRKBUILD}/${T}${OST_IMG_VER}.image
	cp ${OST_INSTALL_DIR}/Squeak${OST_IMG_VER}.changes ${WRKBUILD}/${T}${OST_IMG_VER}.changes
.for SCRIPT in NukePreferenceWizardMorph.st UpdateSqueakTrunkImage.st BuildSqueakSpurTrunkVMMakerImage.st
	${SQ} -headless ${WRKBUILD}/${T}${OST_IMG_VER}.image ${FILESDIR}/${SCRIPT}
.endfor

do-install:
	${INSTALL_DATA_DIR} ${OST_INSTALL_DIR}
	${INSTALL_DATA} ${WRKBUILD}/${T}${OST_IMG_VER}.* ${OST_INSTALL_DIR}

.include <bsd.port.mk>
