#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Usage: $0 arch [gmsh|getdp]" 1>&2;
  echo "  with arch in [mac,linux64,win64,win32][_test]" 1>&2;
  exit 1;
fi

if [ $# -lt 2 ] || [ $2 == "gmsh" ]; then
  echo "========= Building Gmsh =========="
  cd ${HOME}/src/gmsh
  git pull
  cd utils/nightly
  ctest -VV -S ./gmsh_$1.ctest
fi

if [ $# -lt 2 ] || [ $2 == "getdp" ]; then
  echo "========= Building GetDP =========="
  cd ${HOME}/src/getdp
  git pull
  cd utils/nightly
  ctest -VV -S ./getdp_$1.ctest
fi
