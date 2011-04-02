#!/bin/sh

EXTRA_VERSION=$1
GMSH=${HOME}/src/gmsh
LOG=${GMSH}/nightly.log
WEB_BIN=geuzaine@geuz.org:/home/www/geuz.org/gmsh/bin/Windows
CMAKE=cmake
export CC=/usr/bin/i686-w64-mingw32-gcc.exe
export CXX=/usr/bin/i686-w64-mingw32-g++.exe
export FC=/usr/bin/i686-w64-mingw32-gfortran.exe
export PETSC_DIR=${HOME}/src/petsc-3.0.0-p12
export SLEPC_DIR=${HOME}/src/slepc-3.0.0-p7
export PETSC_ARCH=win32_complex_umfpack

rm -f ${LOG}
rm -rf ${GMSH}/bin
echo "BUILD BEGIN: `date`" > ${LOG}
cd ${GMSH} && svn update >> ${LOG} 2>&1
mkdir ${GMSH}/bin
cd ${GMSH}/bin && \
  ${CMAKE} -DGMSH_EXTRA_VERSION:string="${EXTRA_VERSION}"\
           -DCMAKE_PREFIX_PATH:path="/usr/local;/usr/local/opencascade;/usr/i686-w64-mingw32/sys-root/mingw"\
           -DENABLE_SWIG:bool=FALSE\
  ${GMSH} >> ${LOG} 2>&1
cd ${GMSH}/bin && make html >> ${LOG} 2>&1
cd ${GMSH}/bin && make package >> ${LOG} 2>&1
echo "BUILD END: `date`" >> ${LOG}
scp -C ${GMSH}/bin/gmsh-*.zip ${WEB_BIN}/gmsh-nightly-Windows.zip
scp -C ${LOG} ${WEB_BIN}/
