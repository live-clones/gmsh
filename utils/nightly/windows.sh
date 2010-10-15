#!/bin/sh

GMSH=${HOME}/src/gmsh
LOG=${GMSH}/nightly.log
WEB_BIN=geuzaine@geuz.org:/home/www/geuz.org/gmsh/bin/Windows
CMAKE=cmake
PETSC_DIR=${HOME}/src/petsc-3.0.0-p7
PETSC_ARCH=umfpack-cxx-opt
SLEPC_DIR=${HOME}/src/slepc-3.0.0-p7

rm -f ${LOG}
rm -rf ${GMSH}/bin
echo "BUILD BEGIN: `date`" > ${LOG}
cd ${GMSH} && svn update >> ${LOG} 2>&1
mkdir ${GMSH}/bin
cd ${GMSH}/bin && \
  ${CMAKE} -DGMSH_EXTRA_VERSION:string="-svn"\
           -DCMAKE_PREFIX_PATH:path="/usr/local;/usr/local/opencascade"\
           -DCMAKE_CXX_FLAGS:string="-mno-cygwin"\
           -DCMAKE_C_FLAGS:string="-mno-cygwin"\
  ${GMSH} >> ${LOG} 2>&1
cd ${GMSH}/bin && make package >> ${LOG} 2>&1
echo "BUILD END: `date`" >> ${LOG}
scp -C ${GMSH}/bin/gmsh-*.zip ${WEB_BIN}/gmsh-nightly-Windows.zip
scp -C ${LOG} ${WEB_BIN}/
