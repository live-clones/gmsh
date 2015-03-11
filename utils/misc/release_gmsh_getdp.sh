#!/bin/sh

if [ $# -lt 1 ]; then
  echo "Usage: $0 arch" 1>&2;
  echo "  with arch in [mac,linux32,linux64,win32,win64]" 1>&2;
  exit 1;
fi

cd ${HOME}/src/gmsh
svn update
cd utils/nightly
ctest -VV -S ./gmsh_$1.ctest

cd ${HOME}/src/getdp
svn update
cd utils/nightly
ctest -VV -S ./getdp_$1.ctest
