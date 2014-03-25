#/usr/bin/env bash

#gmsh_svn=""
#getdp_svn=""
#frameworks_dir=""
gmsh_svn="/Users/maxime/Documents/gmsh-svn"
getdp_svn="/Users/maxime/Documents/getdp-svn"
frameworks_dir="/tmp/x86/"

# petsc; arch: i386 + blas/lapack
petsc_framework="$frameworks_dir/petsc.framework"

cmake_default="-DDEFAULT=0 -DCMAKE_C_FLAGS='-m32' -DCMAKE_CXX_FLAGS='-m32'"

build_cmd="make framework -j3"

function build_gmsh {
  if [ ! -d "$gmsh_svn/build_ios_$1" ]; then
    mkdir $gmsh_svn/build_ios_$1
    cd $gmsh_svn/build_ios_$1
    cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_LIB=1 -DENABLE_MATHEX=1 -DENABLE_MESH=1 -DENABLE_ONELAB=1 -DENABLE_PARSER=1 -DENABLE_POST=1 -DENABLE_TETGEN=1 ../
    cd -
  fi
  cd $gmsh_svn/build_ios_$1
  $build_cmd
  cd -
}
function build_getdp {
  if [ ! -d "$getdp_svn/build_ios_$1" ]; then
    mkdir $getdp_svn/build_ios_$1
    cd $getdp_svn/build_ios_$1
    cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_LIB=1 -DENABLE_GMSH=1 -DENABLE_LEGACY=1 -DENABLE_PETSC=1 -DPETSC_INC="$petsc_framework/Headers/" -DPETSC_LIBS="$petsc_framework/petsc" -DGMSH_INC="$frameworks_dir/Gmsh.framework/Headers/" -DGMSH_LIB="$frameworks_dir/Gmsh.framework/Gmsh" ../
    cd -
  fi
  cd $getdp_svn/build_ios_$1
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

#build xcode project
mkdir $gmsh_svn/contrib/mobile/xcode_project_simu
cd $gmsh_svn/contrib/mobile/xcode_project_simu
cmake -DCMAKE_INCLUDE_PATH="$frameworks_dir;$getdp_svn" ..
make xcodeProject
