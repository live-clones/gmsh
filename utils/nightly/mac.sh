#!/bin/sh

GMSH=${HOME}/src/gmsh
LOG=${GMSH}/nightly.log
WEB_BIN=geuzaine@geuz.org:/home/www/geuz.org/gmsh/bin/MacOSX

rm -f ${LOG}
rm -rf ${GMSH}/bin
mkdir ${GMSH}/bin
echo "BUILD BEGIN: `date`" > ${LOG}
cd ${GMSH} && export CVS_RSH=ssh && cvs update -dPA >> ${LOG} 2>&1
cd ${GMSH}/bin && \
  cmake -DGMSH_EXTRA_VERSION="-cvs"\
        -DCMAKE_PREFIX_PATH:path="/usr/local;/usr/local/opencascade"\
  ${GMSH} >> ${LOG} 2>&1
cd ${GMSH}/bin && make package >> ${LOG} 2>&1
echo "BUILD END: `date`" >> ${LOG}
scp -C ${GMSH}/bin/gmsh-*.dmg ${WEB_BIN}/gmsh-nightly-MacOSX.dmg
scp -C ${LOG} ${WEB_BIN}/


