#!/bin/sh

GMSH=${HOME}/src/gmsh
LOG=${GMSH}/nightly.log
WEB_BIN=geuzaine@geuz.org:/home/www/geuz.org/gmsh/bin/Windows
CMAKE=cmake

rm -f ${LOG}
rm -rf ${GMSH}/bin
echo "BUILD BEGIN: `date`" > ${LOG}
cd ${GMSH} && export CVS_RSH=ssh && cvs update -dPA >> ${LOG} 2>&1
mkdir ${GMSH}/bin
cd ${GMSH}/bin && \
  ${CMAKE} -DGMSH_EXTRA_VERSION="-cvs"\
           -DCMAKE_PREFIX_PATH:path="/usr/local;/usr/local/opencascade"\
           -DCMAKE_CXX_FLAGS="-mno-cygwin"\
           -DCMAKE_C_FLAGS="-mno-cygwin"\
           -DENABLE_KBIPACK=0\
  ${GMSH} >> ${LOG} 2>&1
cd ${GMSH}/bin && make package >> ${LOG} 2>&1
echo "BUILD END: `date`" >> ${LOG}
scp -C ${GMSH}/bin/gmsh-*.zip ${WEB_BIN}/gmsh-nightly-Windows.zip
scp -C ${LOG} ${WEB_BIN}/
