#!/usr/bin/env bash

android_ndk="${HOME}/android-ndk-r8b/"
android_sdk="${HOME}/android-sdk/"

gmsh_svn="${HOME}/src/gmsh"
getdp_svn="${HOME}/src/getdp"
petsc_lib="${HOME}/petsc"

cmake_default="-DDEFAULT=0 -DCMAKE_TOOLCHAIN_FILE=$gmsh_svn/contrib/mobile/utils/Android.cmake -DENABLE_BUILD_ANDROID=1 -DCMAKE_BUILD_TYPE=Release"
cmake_thread=6

function check {
  return_code=$?
  if [ $return_code != 0 ]; then
    echo "last command failed (return $return_code)"
    exit $return_cod
  fi
}

# PETSc and BLAS/LAPACK
if [ ! -f "$petsc_lib/libpetsc.so" ] || [ ! -f "$petsc_lib/libf2clapack.so" ] || [ ! -f "$petsc_lib/libf2cblas.so" ] || [ ! -d "$petsc_lib/Headers/" ]; then 
  echo "ERROR: Need BLAS (f2c), LAPACK (f2c) and PETSc\n check android_petsc_reconfigure-armv7-android-linux.py for compile options\n"
  exit 1
fi

export ANDROID_NDK=$android_ndk 

# Gmsh
cd $gmsh_svn
svn up
if [ ! -d "$gmsh_svn/build_android" ] || [ ! -f "$gmsh_svn/build_android/CMakeCache.txt" ]; then
  mkdir $gmsh_svn/build_android
  cd $gmsh_svn/build_android
  cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_SHARED=1 -DENABLE_MATHEX=1 -DENABLE_MESH=1 -DENABLE_ONELAB=1 -DENABLE_PARSER=1 -DENABLE_POST=1 -DENABLE_TETGEN=1 -DBLAS_LIB="$petsc_lib/libf2cblas.so" -DLAPACK_LIB="$petsc_lib/libf2clapack.so" ..
  check
fi
cd $gmsh_svn/build_android
make androidGmsh -j$cmake_thread
check
make getHeaders
check

# GetDP
cd $getdp_svn
svn up
if [ ! -d "$getdp_svn/build_android" ] || [ ! -f "$getdp_svn/build_android/CMakeCache.txt" ]; then
  mkdir $getdp_svn/build_android
  cd $getdp_svn/build_android
  export PETSC_DIR=
  export PETSC_ARCH=
  cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_SHARED=1 -DENABLE_GMSH=1 -DENABLE_LEGACY=1 -DENABLE_PETSC=1 -DPETSC_INC="$petsc_lib/Headers;$petsc_lib/Headers/mpiuni" -DPETSC_LIBS="$petsc_lib/libpetsc.so" -DGMSH_INC="$gmsh_svn/build_android/Headers/" -DGMSH_LIB="$gmsh_svn/build_android/libs/libGmsh.so" -DBLAS_LAPACK_LIBRARIES="$petsc_lib/libf2cblas.so;$petsc_lib/libf2clapack.so" ..
  check
fi
cd $getdp_svn/build_android
make androidGetdp -j$cmake_thread
check
make getHeaders
check

# Onelab/Mobile interface
if [ ! -d "$gmsh_svn/contrib/mobile/build_android" ] || [ ! -f "$gmsh_svn/contrib/mobile/build_android/CMakeCache.txt" ]; then
  mkdir $gmsh_svn/contrib/mobile/build_android
  cd $gmsh_svn/contrib/mobile/build_android
  cmake $cmake_default \
	-DCMAKE_INCLUDE_PATH="$getdp_svn/" \
	-DBLAS_LIB="$petsc_lib/libf2cblas.so" -DLAPACK_LIB="$petsc_lib/libf2clapack.so" \
	-DPETSC_LIB="$petsc_lib/libpetsc.so" \
	-DGMSH_INC="$gmsh_svn/build_android/Headers" -DGMSH_LIB="$gmsh_svn/build_android/libs/libGmsh.so" \
	-DBENCHMARKSDIR="$getdp_svn/" \
	-DGETDP_INC="$getdp_svn/build_android/Headers" -DGETDP_LIB="$getdp_svn/build_android/libs/libGetDP.so" ..
fi
cd $gmsh_svn/contrib/mobile/build_android
make androidOnelab -j$cmake_thread
check
make androidProject
check

# Onelab/Mobile package
cd Onelab
if [ ! -d "libs/armeabi-v7a/" ]; then mkdir -p libs/armeabi-v7a/; fi
target=1
while read line; do
  read line # Name
  target_name=$(echo $line | awk '{print $2}')
  target_version=$(echo $line | awk '{print $3}')
  read line # Type
  read line # API level
  target_api=$(echo $line | awk '{print $3}')
  read line # Revision
  read line # Skins
  if [ $target_api -ge 14 ]; then
    $android_sdk/tools/android update project --name Onelab --path . --target $target
    check
    ant release
    check
    break
  fi
  read line # HACK
  target=$(($target+1))
done < <($android_sdk/tools/android list target | grep -A 5 "id:")

# to re-install on the device:
# $android_sdk/platform-tools/adb install -r $gmsh_svn/contrib/mobile/build_android/Onelab/bin/Onelab-release.apk

# to debug and check the log:
# $android_sdk/tools/ddms
