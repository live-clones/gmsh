#!/bin/sh

GMSH=${HOME}/src/gmsh
LOG=${GMSH}/nightly.log
WEB_BIN=geuzaine@geuz.org:/home/www/geuz.org/gmsh/bin/Linux

rm -f ${LOG}
rm -rf ${GMSH}/build
echo "BUILD BEGIN: `date`" > ${LOG}
cd ${GMSH} && export CVS_RSH=ssh && cvs update -dPA >> ${LOG} 2>&1
cd ${GMSH}/build && \
  cmake -DGMSH_EXTRA_VERSION="-cvs"\
        -DCMAKE_PREFIX_PATH:path="/usr/local;/usr/local/opencascade"\
        -DENABLE_NATIVE_FILE_CHOOSER:bool=FALSE\
  ${GMSH} >> ${LOG} 2>&1
cd ${GMSH}/build && make package >> ${LOG} 2>&1
echo "BUILD END: `date`" >> ${LOG}
scp -C ${GMSH}/build/gmsh-*cvs*.tar.gz ${WEB_BIN}/gmsh-nightly-Linux.tgz
scp -C ${LOG} ${WEB_BIN}/

