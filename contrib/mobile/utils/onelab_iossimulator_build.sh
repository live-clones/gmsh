#/usr/bin/env bash

gmsh_svn="${HOME}/src/gmsh/"
getdp_svn="${HOME}/src/getdp/"
frameworks_dir="${HOME}/src/gmsh/contrib/mobile/frameworks_iossimulator/"

petsc_framework="$frameworks_dir/petsc.framework"
slepc_framework="$frameworks_dir/slepc.framework"

cmake_default="-DDEFAULT=0 -DCMAKE_C_FLAGS='-m32' -DCMAKE_CXX_FLAGS='-m32'"

build_cmd="make lib -j4"
headers_cmd="make get_headers"

function build_gmsh {
  if [ ! -d "$gmsh_svn/build_iossimulator" ]; then
    mkdir $gmsh_svn/build_iossimulator
  fi
  cd $gmsh_svn/build_iossimulator
  cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_LIB=1 -DENABLE_MATHEX=1 -DENABLE_MESH=1 -DENABLE_ONELAB=1 -DENABLE_PARSER=1 -DENABLE_POST=1 -DENABLE_TETGEN=1 ..
  $build_cmd
  $headers_cmd
  cd -
}
function build_getdp {
  if [ ! -d "$getdp_svn/build_iossimulator" ]; then
    mkdir $getdp_svn/build_iossimulator
  fi
  cd $getdp_svn/build_iossimulator
  PETSC_DIR= PETSC_ARCH= SLEPC_DIR= cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_LIB=1 -DENABLE_GMSH=1 -DENABLE_LEGACY=1 -DENABLE_PETSC=1 -DPETSC_INC="$petsc_framework/Headers/" -DPETSC_LIBS="$petsc_framework/petsc" -DENABLE_SLEPC=1 -DSLEPC_INC="$slepc_framework/Headers/" -DSLEPC_LIB="$slepc_framework/slepc" -DGMSH_INC="$gmsh_svn/build_iossimulator/Headers/" -DGMSH_LIB="$gmsh_svn/build_iossimulator/libGmsh.a" ..
  $build_cmd
  $headers_cmd
  cd -
}

# build gmsh framework
cd $gmsh_svn && svn up
build_gmsh
mkdir -p $frameworks_dir/Gmsh.framework/Headers
cp $gmsh_svn/build_iossimulator/libGmsh.a $frameworks_dir/Gmsh.framework/Gmsh
cd $frameworks_dir/Gmsh.framework/Headers
cp $gmsh_svn/build_iossimulator/Headers/gmsh/* .
ln -s . gmsh

# build getdp framework
cd $getdp_svn && svn up
build_getdp
mkdir -p $frameworks_dir/GetDP.framework/Headers
cp $getdp_svn/build_iossimulator/libGetDP.a $frameworks_dir/GetDP.framework/GetDP
cd $frameworks_dir/GetDP.framework/Headers
cp $getdp_svn/build_iossimulator/Headers/getdp/* .

# create xcode project
mkdir $gmsh_svn/contrib/mobile/build_iossimulator
cd $gmsh_svn/contrib/mobile/build_iossimulator
cmake -DCMAKE_INCLUDE_PATH="$frameworks_dir;$getdp_svn" ..
make xcodeProject
