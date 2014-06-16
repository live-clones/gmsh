#/usr/bin/env bash

gmsh_svn="/Users/geuzaine/src/gmsh/"
getdp_svn="/Users/geuzaine/src/getdp/"
frameworks_dir="/Users/geuzaine/src/gmsh/contrib/mobile/frameworks_simulator/"

petsc_framework="$frameworks_dir/petsc.framework"
slepc_framework="$frameworks_dir/slepc.framework"

cmake_default="-DDEFAULT=0 -DCMAKE_C_FLAGS='-m32' -DCMAKE_CXX_FLAGS='-m32'"

build_cmd="make framework -j4"

function build_gmsh {
  if [ ! -d "$gmsh_svn/build_ios_$1" ]; then
    mkdir $gmsh_svn/build_ios_$1
  fi
  cd $gmsh_svn/build_ios_$1
  cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_LIB=1 -DENABLE_MATHEX=1 -DENABLE_MESH=1 -DENABLE_ONELAB=1 -DENABLE_PARSER=1 -DENABLE_POST=1 -DENABLE_TETGEN=1 ..
  $build_cmd
  cd -
}
function build_getdp {
  if [ ! -d "$getdp_svn/build_ios_$1" ]; then
    mkdir $getdp_svn/build_ios_$1
  fi
  cd $getdp_svn/build_ios_$1
  PETSC_DIR= PETSC_ARCH= SLEPC_DIR= cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_LIB=1 -DENABLE_GMSH=1 -DENABLE_LEGACY=1 -DENABLE_PETSC=1 -DPETSC_INC="$petsc_framework/Headers/" -DPETSC_LIBS="$petsc_framework/petsc" -DENABLE_SLEPC=1 -DSLEPC_INC="$slepc_framework/Headers/" -DSLEPC_LIB="$slepc_framework/slepc" -DGMSH_INC="$frameworks_dir/Gmsh.framework/Headers/" -DGMSH_LIB="$frameworks_dir/Gmsh.framework/Gmsh" ..
  $build_cmd
  cd -
}

# build gmsh's framework
cd $gmsh_svn && svn up
build_gmsh x86
cp -r $gmsh_svn/build_ios_x86/Gmsh.framework/ $frameworks_dir/Gmsh.framework
cd $frameworks_dir/Gmsh.framework/Headers/;ln -s . gmsh; cd -

# build getdp's framework
cd $getdp_svn && svn up
build_getdp x86
cp -r $getdp_svn/build_ios_x86/GetDP.framework/ $frameworks_dir/GetDP.framework

# create xcode project
mkdir $gmsh_svn/contrib/mobile/xcode_project_simulator
cd $gmsh_svn/contrib/mobile/xcode_project_simulator
cmake -DCMAKE_INCLUDE_PATH="$frameworks_dir;$getdp_svn" ..
make xcodeProject
