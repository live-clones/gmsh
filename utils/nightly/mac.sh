#!/bin/sh

EXTRA_VERSION=$1
GMSH=${HOME}/src/gmsh
LOG=${GMSH}/nightly.log
WEB_BIN=geuzaine@geuz.org:/home/www/geuz.org/gmsh/bin/MacOSX
CMAKE=/usr/local/bin/cmake
export PETSC_DIR=${HOME}/src/petsc-3.0.0-p7
export PETSC_ARCH=umfpack-cxx-opt
export SLEPC_DIR=${HOME}/src/slepc-3.0.0-p7

rm -f ${LOG}
rm -rf ${GMSH}/bin
echo "BUILD BEGIN: `date`" > ${LOG}
cd ${GMSH} && svn update >> ${LOG} 2>&1
mkdir ${GMSH}/bin
cd ${GMSH}/bin &&\
  ${CMAKE} -DGMSH_EXTRA_VERSION:string="${EXTRA_VERSION}"\
           -DCMAKE_PREFIX_PATH:path="/usr/local;/usr/local/opencascade"\
           -DENABLE_SWIG:bool=FALSE\
  ${GMSH} >> ${LOG} 2>&1
cd ${GMSH}/bin && make html >> ${LOG} 2>&1
cd ${GMSH}/bin && make package -j 4 >> ${LOG} 2>&1
echo "BUILD END: `date`" >> ${LOG}
scp -C ${GMSH}/bin/gmsh-*.dmg ${WEB_BIN}/gmsh-nightly-MacOSX.dmg
scp -C ${LOG} ${WEB_BIN}/
