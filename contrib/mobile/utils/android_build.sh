#!/usr/bin/env bash

appname=Onelab
if [ $# -eq 1 ] ; then
  appname=${1}
  echo "Rebranding Onelab app as ${appname}"
fi

gmsh_svn="${HOME}/src/gmsh"
getdp_svn="${HOME}/src/getdp"
frameworks_dir="${HOME}/src/gmsh/contrib/mobile/frameworks_android"

if [ -f ${getdp_svn}/benchmarks/cleanup.sh ]; then
  cd ${getdp_svn}/benchmarks && ./cleanup.sh
fi
if [ -f ${getdp_svn}/benchmarks_private/cleanup.sh ]; then
  cd ${getdp_svn}/benchmarks_private && ./cleanup.sh
fi

petsc_lib="$frameworks_dir/petsc"
slepc_lib="$frameworks_dir/slepc"
android_ndk="${HOME}/android-ndk-r8b/" 
android_sdk="${HOME}/android-sdk/"

cmake_default="-DDEFAULT=0 -DCMAKE_TOOLCHAIN_FILE=$gmsh_svn/contrib/mobile/utils/Android.cmake -DENABLE_BUILD_ANDROID=1 -DCMAKE_BUILD_TYPE=Release"
cmake_thread=6

function check {
  return_code=$?
  if [ $return_code != 0 ]; then
    echo "last command failed (return $return_code)"
    exit $return_code
  fi
}

export ANDROID_NDK=$android_ndk 

# Gmsh
cd $gmsh_svn
svn up
if [ ! -d "$gmsh_svn/build_android" ] || [ ! -f "$gmsh_svn/build_android/CMakeCache.txt" ]; then
  mkdir $gmsh_svn/build_android
fi
cd $gmsh_svn/build_android
cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_SHARED=1 -DENABLE_MATHEX=1 -DENABLE_MESH=1 -DENABLE_ONELAB=1 -DENABLE_PARSER=1 -DENABLE_POST=1 -DENABLE_PLUGINS=1 -DENABLE_ANN=1 -DENABLE_TETGEN=1 -DENABLE_KBIPACK=1 -DENABLE_GMP=0 -DENABLE_ZIPPER=1 -DBLAS_LIB="$petsc_lib/libf2cblas.so" -DLAPACK_LIB="$petsc_lib/libf2clapack.so" ..
check
make androidGmsh -j$cmake_thread
check
make get_headers
check

# GetDP
cd $getdp_svn
svn up
if [ ! -d "$getdp_svn/build_android" ] || [ ! -f "$getdp_svn/build_android/CMakeCache.txt" ]; then
  mkdir $getdp_svn/build_android
fi
cd $getdp_svn/build_android
PETSC_DIR= PETSC_ARCH= SLEPC_DIR= cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_SHARED=1 -DENABLE_GMSH=1 -DENABLE_KERNEL=1 -DENABLE_PETSC=1 -DPETSC_INC="$petsc_lib/Headers;$petsc_lib/Headers/mpiuni" -DPETSC_LIBS="$petsc_lib/libpetsc.so" -DENABLE_SLEPC=1 -DSLEPC_INC="$slepc_lib/Headers/" -DSLEPC_LIB="$slepc_lib/libslepc.so" -DGMSH_INC="$gmsh_svn/build_android/Headers/" -DGMSH_LIB="$gmsh_svn/build_android/libs/libGmsh.so" -DBLAS_LAPACK_LIBRARIES="$petsc_lib/libf2cblas.so;$petsc_lib/libf2clapack.so" ..
check
make androidGetdp -j$cmake_thread
check
make get_headers
check

# Onelab/Mobile interface
if [ ! -d "$gmsh_svn/contrib/mobile/build_android_${appname}" ]; then
  mkdir $gmsh_svn/contrib/mobile/build_android_${appname}
fi
cd $gmsh_svn/contrib/mobile/build_android_${appname}

cmake $cmake_default -DAPPNAME:STRING=${appname} \
      -DCMAKE_INCLUDE_PATH="$getdp_svn/" \
      -DBLAS_LIB="$petsc_lib/libf2cblas.so" -DLAPACK_LIB="$petsc_lib/libf2clapack.so" \
      -DPETSC_LIB="$petsc_lib/libpetsc.so" -DSLEPC_LIB="$slepc_lib/libslepc.so" \
      -DGMSH_INC="$gmsh_svn/build_android/Headers" -DGMSH_LIB="$gmsh_svn/build_android/libs/libGmsh.so" \
      -DBENCHMARKSDIR="$getdp_svn/" \
      -DGETDP_INC="$getdp_svn/build_android/Headers" -DGETDP_LIB="$getdp_svn/build_android/libs/libGetDP.so" ..
check
make androidOnelab -j$cmake_thread
check
make androidProject
check

if [ $# -eq 1 ] ; then
  cd $appname
  # change package name
  rm -rf src/org/geuz/$appname
  mv src/org/geuz/onelab/ src/org/geuz/$appname
  # Gmsh.java and StringTexture.java are accessed from C++ as onelab packages
  mkdir src/org/geuz/onelab
  mv src/org/geuz/$appname/Gmsh.java src/org/geuz/onelab
  mv src/org/geuz/$appname/StringTexture.java src/org/geuz/onelab
  sed -e "s/org\.geuz\.onelab/org\.geuz\.$appname/g" -i "" AndroidManifest.xml
  find src/org/geuz/$appname -type f -name '*.java' -exec sed -e "s/package org\.geuz\.onelab/package org\.geuz\.$appname/g" -i "" {} \;
  find res -type f -name '*.xml' -exec sed -e "s/org\.geuz\.onelab/org\.geuz\.$appname/g" -i "" {} \;
  # change app name and icons
  sed -e "s/Onelab/$appname/" -i "" res/values/strings.xml
  sed -e "s/Onelab\/Mobile/$appname/" -i "" src/org/geuz/$appname/AboutActivity.java
  if [ "$appname" == "BBEMG" ] ; then
      sed -e "s/onelab\.info/www\.bbemg\.be/g" -i "" src/org/geuz/$appname/AboutActivity.java
  fi
  cp $HOME/tex/proposals/bbemg/icons/bbemg-logo-128x128.png res/drawable-hdpi/ic_launcher.png
  cp $HOME/tex/proposals/bbemg/icons/bbemg-logo-64x64.png res/drawable-mdpi/ic_launcher.png
  cp $HOME/tex/proposals/bbemg/icons/bbemg-logo-48x48.png res/drawable-ldpi/ic_launcher.png
  $android_sdk/tools/android update project --name $appname --path . --target 1 --subprojects
else
  cd Onelab
  $android_sdk/tools/android update project --name Onelab --path . --target 1 --subprojects
fi

check
if [ ! -f "ant.properties" ]; then
    cp $gmsh_svn/contrib/mobile/utils/ant.properties .
fi
ant release
check

# to install on the device:
# ~/android-sdk/platform-tools/adb install -r build_android_Onelab/Onelab/bin/Onelab-release.apk

# to launch the app on the device:
# ~/android-sdk/platform-tools/adb shell am start -n org.geuz.onelab/org.geuz.onelab.SplashScreen

# to debug and check the log:
# ~/android-sdk/tools/ddms

# to see stack traces after crashes:
# ~/android-sdk/platform-tools/adb logcat | ~/android-ndk-r8b/ndk-stack -sym build_android_Onelab/
