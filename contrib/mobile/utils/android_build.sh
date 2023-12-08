#!/usr/bin/env bash

appname=Onelab
enable_occ=1
enable_simulator=0
version=2.3.6
build=62 # must be incremented for each submitted build

while [[ $# -gt 0 ]]; do
  key="$1"
  case $key in
    -n|--name)
      appname=$2
      enable_occ=0
      echo "Rebranding Onelab app as ${appname}"
      shift # past argument
      ;;
    -s|--simulator)
      enable_simulator=1
      ;;
    --no-occ)
      enable_occ=0
      ;;
    *)
      echo "Usage: $0 [-n|--name appname] [-s|--simulator] [--no-occ]"
      exit 1
      ;;
  esac
  shift # past argument or value
done

# modify Android/app/src/main/AndroidManifest.xml
#
#   android:versionName="XXX"
#   android:versionCode="YYY"
mobile="${HOME}/src/gmsh/contrib/mobile"
sed -i "" "s/.*android:versionName.*/          android:versionName=\"${version}\"/" ${mobile}/Android/app/src/main/AndroidManifest.xml
sed -i "" "s/.*android:versionCode.*/          android:versionCode=\"${build}\"/" ${mobile}/Android/app/src/main/AndroidManifest.xml

android=android
if [ $enable_simulator != 0 ]; then
  android=androidsimulator
fi

gmsh_git="${HOME}/src/gmsh"
getdp_git="${HOME}/src/getdp"
frameworks_dir="${HOME}/src/gmsh/contrib/mobile/frameworks_${android}"

petsc_lib="$frameworks_dir/petsc"
slepc_lib="$frameworks_dir/slepc"
occ_lib="$frameworks_dir/occt/lib"
occ_inc="$frameworks_dir/occt/include/opencascade"
android_ndk="${HOME}/Library/Android/sdk/ndk/25.2.9519653/"
android_sdk="${HOME}/Library/Android/sdk/"

if [ "$appname" != "Onelab" ] ; then
  models_dir="${HOME}/src/getdp/benchmarks_private"
else
  models_dir="${HOME}/src/onelab_doc"
fi
if [ -f ${models_dir}/cleanup.sh ]; then
  cd ${models_dir} && ./cleanup.sh
fi

cmake_default="-DDEFAULT=0 -DENABLE_PRIVATE_API=1 -DCMAKE_TOOLCHAIN_FILE=${android_ndk}/build/cmake/android.toolchain.cmake -DANDROID_STL_FORCE_FEATURES=1 -DENABLE_BUILD_ANDROID=1 -DCMAKE_BUILD_TYPE=Release"

if [ $enable_simulator != 0 ]; then
  cmake_default="${cmake_default} -DANDROID_ABI=x86_64"
else
  cmake_default="${cmake_default} -DANDROID_ABI=arm64-v8a"
  # for old 32 bit app: -DANDROID_ABI=armeabi-v7a
fi

cmake_thread=6

function check {
  return_code=$?
  if [ $return_code != 0 ]; then
    echo "last command failed (return $return_code)"
    exit $return_code
  fi
}

# Gmsh
cd $gmsh_git
git pull
if [ ! -d "$gmsh_git/build_${android}" ] || [ ! -f "$gmsh_git/build_${android}/CMakeCache.txt" ]; then
  mkdir $gmsh_git/build_${android}
fi
cd $gmsh_git/build_${android}
cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_SHARED=1 -DENABLE_MATHEX=1 -DENABLE_MESH=1 -DENABLE_ONELAB=1 -DENABLE_PARSER=1 -DENABLE_POST=1 -DENABLE_PLUGINS=1 -DENABLE_ANN=1 -DENABLE_KBIPACK=1 -DENABLE_GMP=0 -DENABLE_ZIPPER=1 -DBLAS_LAPACK_LIBRARIES="$petsc_lib/libf2cblas.so;$petsc_lib/libf2clapack.so" -DENABLE_OCC=$enable_occ -DOCC_LIBS="${occ_lib}/libTKSTEP.a;${occ_lib}/libTKSTEP209.a;${occ_lib}/libTKSTEPAttr.a;${occ_lib}/libTKSTEPBase.a;${occ_lib}/libTKIGES.a;${occ_lib}/libTKXSBase.a;${occ_lib}/libTKOffset.a;${occ_lib}/libTKFeat.a;${occ_lib}/libTKFillet.a;${occ_lib}/libTKBool.a;${occ_lib}/libTKMesh.a;${occ_lib}/libTKHLR.a;${occ_lib}/libTKBO.a;${occ_lib}/libTKShHealing.a;${occ_lib}/libTKPrim.a;${occ_lib}/libTKTopAlgo.a;${occ_lib}/libTKGeomAlgo.a;${occ_lib}/libTKBRep.a;${occ_lib}/libTKGeomBase.a;${occ_lib}/libTKG3d.a;${occ_lib}/libTKG2d.a;${occ_lib}/libTKMath.a;${occ_lib}/libTKernel.a" -DOCC_INC=${occ_inc} ..
check
make androidGmsh -j$cmake_thread
check
make get_headers
check

# GetDP
cd $getdp_git
git pull
if [ ! -d "$getdp_git/build_${android}" ] || [ ! -f "$getdp_git/build_${android}/CMakeCache.txt" ]; then
  mkdir $getdp_git/build_${android}
fi
cd $getdp_git/build_${android}
PETSC_DIR= PETSC_ARCH= SLEPC_DIR= cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_SHARED=1 -DENABLE_GMSH=1 -DENABLE_KERNEL=1 -DENABLE_PETSC=1 -DPETSC_INC="$petsc_lib/Headers;$petsc_lib/Headers/mpiuni" -DPETSC_LIBS="$petsc_lib/libpetsc.so" -DENABLE_SLEPC=1 -DSLEPC_INC="$slepc_lib/Headers/" -DSLEPC_LIB="$slepc_lib/libslepc.so" -DGMSH_INC="$gmsh_git/build_${android}/Headers/" -DGMSH_LIB="$gmsh_git/build_${android}/libs/libgmsh.so" -DBLAS_LAPACK_LIBRARIES="$petsc_lib/libf2cblas.so;$petsc_lib/libf2clapack.so" ..
check
make androidGetdp -j$cmake_thread
check
make get_headers
check

# Onelab/Mobile interface
if [ ! -d "$gmsh_git/contrib/mobile/build_${android}_${appname}" ]; then
  mkdir $gmsh_git/contrib/mobile/build_${android}_${appname}
fi
cd $gmsh_git/contrib/mobile/build_${android}_${appname}

cmake $cmake_default -DAPPNAME:STRING=${appname} \
      -DMODELS_DIR="$models_dir" \
      -DBLAS_LIB="$petsc_lib/libf2cblas.so" -DLAPACK_LIB="$petsc_lib/libf2clapack.so" \
      -DPETSC_LIB="$petsc_lib/libpetsc.so" -DSLEPC_LIB="$slepc_lib/libslepc.so" \
      -DGMSH_INC="$gmsh_git/build_${android}/Headers" -DGMSH_LIB="$gmsh_git/build_${android}/libs/libgmsh.so" \
      -DGETDP_INC="$getdp_git/build_${android}/Headers" -DGETDP_LIB="$getdp_git/build_${android}/libs/libgetdp.so" ..
check
make androidOnelab -j$cmake_thread
check
make androidProject
check

cd $appname

if [ "$appname" != "Onelab" ] ; then
  # change package name
  rm -rf app/src/main/java/org/geuz/$appname
  mv app/src/main/java/org/geuz/onelab/ app/src/main/java/org/geuz/$appname
  # Gmsh.java and StringTexture.java are accessed from C++ as onelab packages
  mkdir app/src/main/java/org/geuz/onelab
  mv app/src/main/java/org/geuz/$appname/Gmsh.java app/src/main/java/org/geuz/onelab
  mv app/src/main/java/org/geuz/$appname/StringTexture.java app/src/main/java/org/geuz/onelab
  sed -e "s/org\.geuz\.onelab/org\.geuz\.$appname/g" -i "" app/src/main/AndroidManifest.xml
  find app/src/main/java/org/geuz/$appname -type f -name '*.java' -exec sed -e "s/package org\.geuz\.onelab/package org\.geuz\.$appname/g" -i "" {} \;
  find app/src/main/res -type f -name '*.xml' -exec sed -e "s/org\.geuz\.onelab/org\.geuz\.$appname/g" -i "" {} \;
  # change app name and icons
  sed -e "s/Onelab/$appname/" -i "" app/src/main/res/values/strings.xml
  sed -e "s/Onelab\/Mobile/$appname/" -i "" app/src/main/java/org/geuz/$appname/AboutActivity.java
  if [ "$appname" == "BBEMG" ] ; then
    sed -e "s/onelab\.info/www\.bbemg\.be/g" -i "" app/src/main/java/org/geuz/$appname/AboutActivity.java
    cp $HOME/tex/proposals/bbemg/icons/bbemg-logo-128x128.png app/src/main/res/drawable-hdpi/ic_launcher.png
    cp $HOME/tex/proposals/bbemg/icons/bbemg-logo-64x64.png app/src/main/res/drawable-mdpi/ic_launcher.png
    cp $HOME/tex/proposals/bbemg/icons/bbemg-logo-48x48.png app/src/main/res/drawable-ldpi/ic_launcher.png
  fi
fi

# we should generate this here:
#echo "ndk.dir=${android_ndk}" > local.properties
#echo "sdk.dir=${android_sdk}" >> local.properties
# as well as the keystore config in app/build.gradle

check

# old-style APK
gradle --warning-mode all assembleRelease

# new-style APP bundle
#gradle bundleRelease

check

# to install on the device:
# ~/Library/Android/sdk/platform-tools/adb install -r build_android_Onelab/Onelab/app/build/outputs/apk/app-release.apk

# to launch the app on the device:
# ~/Library/Android/sdk/platform-tools/adb shell am start -n org.geuz.onelab/org.geuz.onelab.SplashScreen

# to debug and check the log:
# ~/Library/Android/sdk/tools/monitor

# to see stack traces after crashes:
# ~/Library/Android/sdk/platform-tools/adb logcat | ~/Library/Android/ndk-bundle/ndk-stack -sym build_android_Onelab/

# to run the emulator (this one uses a real ARM image - slower but allows to test the actual build!)
# ~/Library/Android/sdk/tools/emulator -netdelay none -netspeed full -avd Nexus_6P_API_25
