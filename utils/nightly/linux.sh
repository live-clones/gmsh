#!/bin/sh

EXTRA_VERSION=$1
GMSH=${HOME}/src/gmsh
LOG=${GMSH}/nightly.log
WEB_BIN=geuzaine@geuz.org:/home/www/geuz.org/gmsh/bin/Linux
CMAKE=/usr/local/bin/cmake
export PETSC_DIR=${HOME}/src/petsc-3.0.0-p12
export SLEPC_DIR=${HOME}/src/slepc-3.0.0-p7
export PETSC_ARCH=linux_complex_umfpack

rm -f ${LOG}
rm -rf ${GMSH}/bin
echo "BUILD BEGIN: `date`" > ${LOG}
cd ${GMSH} && svn update >> ${LOG} 2>&1
mkdir ${GMSH}/bin
cd ${GMSH}/bin && \
  ${CMAKE} -DGMSH_EXTRA_VERSION:string="${EXTRA_VERSION}"\
           -DCMAKE_PREFIX_PATH:path="/usr/local/med;/usr/local/opencascade;/usr/local"\
           -DENABLE_NATIVE_FILE_CHOOSER:bool=FALSE\
           -DENABLE_SWIG:bool=FALSE\
  ${GMSH} >> ${LOG} 2>&1
cd ${GMSH}/bin && make html >> ${LOG} 2>&1
cd ${GMSH}/bin && make package >> ${LOG} 2>&1
echo "BUILD END: `date`" >> ${LOG}

FILE=`ls ${GMSH}/bin/gmsh-*.tar.gz`
if [ -f ${FILE} ]; then
  if [[ ${EXTRA_VERSION} == "-svn" ]]; then
    scp -C ${FILE} ${WEB_BIN}/gmsh-svn-Linux.tgz
  else
    scp -C ${FILE} ${WEB_BIN}/
  fi
fi
scp -C ${LOG} ${WEB_BIN}/
