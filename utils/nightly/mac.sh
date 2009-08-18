#!/bin/sh

GMSH=${HOME}/src/gmsh
LOG=${GMSH}/nightly.log
WEB_BIN=geuzaine@geuz.org:/home/www/geuz.org/gmsh/bin/MacOSX
CMAKE=/usr/local/bin/cmake

rm -f ${LOG}
rm -rf ${GMSH}/bin
echo "BUILD BEGIN: `date`" > ${LOG}
cd ${GMSH} && export CVS_RSH=ssh && cvs update -dPA >> ${LOG} 2>&1
mkdir ${GMSH}/bin
cd ${GMSH}/bin && \
  ${CMAKE} -DGMSH_EXTRA_VERSION:string="-cvs"\
           -DCMAKE_PREFIX_PATH:path="/usr/local;/usr/local/opencascade"\
           -DENABLE_KBIPACK:bool=FALSE\
  ${GMSH} >> ${LOG} 2>&1
cd ${GMSH}/bin && make package -j 4 >> ${LOG} 2>&1
echo "BUILD END: `date`" >> ${LOG}
scp -C ${GMSH}/bin/gmsh-*.dmg ${WEB_BIN}/gmsh-nightly-MacOSX.dmg
scp -C ${LOG} ${WEB_BIN}/


