#!/bin/sh

GMSH=${HOME}/src/gmsh
LOG=${GMSH}/nightly.log
WEB_BIN=geuzaine@geuz.org:/home/www/geuz.org/gmsh/bin/Linux
CMAKE=cmake

rm -f ${LOG}
rm -rf ${GMSH}/bin
echo "BUILD BEGIN: `date`" > ${LOG}
cd ${GMSH} && export CVS_RSH=ssh && cvs update -dPA >> ${LOG} 2>&1
mkdir ${GMSH}/bin
cd ${GMSH}/bin && \
  ${CMAKE} -DGMSH_EXTRA_VERSION="-cvs"\
           -DCMAKE_PREFIX_PATH:path="/usr/local;/usr/local/opencascade"\
           -DENABLE_KBIPACK=0\
           -DENABLE_NATIVE_FILE_CHOOSER:bool=FALSE\
  ${GMSH} >> ${LOG} 2>&1
cd ${GMSH}/bin && make package >> ${LOG} 2>&1
echo "BUILD END: `date`" >> ${LOG}
scp -C ${GMSH}/bin/gmsh-*.tar.gz ${WEB_BIN}/gmsh-nightly-Linux.tgz
scp -C ${LOG} ${WEB_BIN}/

