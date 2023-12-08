#/usr/bin/env bash

appname=Onelab
enable_occ=1
enable_simulator=0
#buildtype=Debug
buildtype=Release
version=2.3.5
build=58 # must be incremented for each submitted build

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

# modify iOS/Onelab/Onelab-Info.plist
#
# <key>CFBundleShortVersionString</key><string>XXX</string>
# <key>CFBundleVersion</key><string>YYY</string>
mobile="${HOME}/src/gmsh/contrib/mobile"
sed -i "" "s/.*CFBundleShortVersionString.*/    <key>CFBundleShortVersionString<\/key><string>${version}<\/string>/" ${mobile}/iOS/Onelab/Onelab-Info.plist
sed -i "" "s/.*CFBundleVersion.*/    <key>CFBundleVersion<\/key><string>${build}<\/string>/" ${mobile}/iOS/Onelab/Onelab-Info.plist

ios=ios
iphoneos=iphoneos
#iphoneos_version_min=-miphoneos-version-min=8.0
iphoneos_version_min="-target arm64-apple-ios9.0" # iOS 13 SDK
if [ $enable_simulator != 0 ]; then
  ios=iossimulator
  iphoneos=iphonesimulator
  iphoneos_version_min="-target x86_64-apple-ios9.0" # iOS 14 SDK
fi

gmsh_git="${HOME}/src/gmsh/"
getdp_git="${HOME}/src/getdp/"
frameworks_dir="${HOME}/src/gmsh/contrib/mobile/frameworks_${ios}/"
petsc_framework="$frameworks_dir/petsc.framework"
slepc_framework="$frameworks_dir/slepc.framework"
gmsh_framework="$frameworks_dir/gmsh.framework"
getdp_framework="$frameworks_dir/getdp.framework"
occt_framework="$frameworks_dir/occt.framework"

if [ "$appname" != "Onelab" ] ; then
  models_dir="${HOME}/src/getdp/benchmarks_private"
else
  models_dir="${HOME}/src/onelab_doc"
fi
if [ -f ${models_dir}/cleanup.sh ]; then
  cd ${models_dir} && ./cleanup.sh
fi

if [ $enable_simulator != 0 ]; then
  cmake_default="-DDEFAULT=0 -DENABLE_PRIVATE_API=1 -DCMAKE_TOOLCHAIN_FILE=$gmsh_git/contrib/mobile/utils/iOS.cmake -DIOS_PLATFORM=SIMULATOR -DENABLE_BUILD_IOS=1 -DCMAKE_BUILD_TYPE=${buildtype} -DCMAKE_OSX_ARCHITECTURES=x86_64 -GXcode"
else
  cmake_default="-DDEFAULT=0 -DENABLE_PRIVATE_API=1 -DCMAKE_TOOLCHAIN_FILE=$gmsh_git/contrib/mobile/utils/iOS.cmake -DIOS_PLATFORM=OS -DENABLE_BUILD_IOS=1 -DCMAKE_BUILD_TYPE=${buildtype} -DCMAKE_OSX_ARCHITECTURES=arm64 -GXcode"
fi

# iOS 13 SDK is 64 bit only...
# -DCMAKE_OSX_ARCHITECTURES=armv7;armv7s;arm64

build_cmd="xcodebuild -target lib -configuration ${buildtype}"
headers_cmd="xcodebuild -target get_headers -configuration ${buildtype}"

function check {
  return_code=$?
  if [ $return_code != 0 ]; then
    echo "last command failed (return $return_code)"
    exit $return_code
  fi
}

# build gmsh framework
cd $gmsh_git && git pull
mkdir -p $gmsh_git/build_${ios}
cd $gmsh_git/build_${ios}
cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_LIB=1 -DENABLE_MATHEX=1 -DENABLE_MESH=1 -DENABLE_ONELAB=1 -DENABLE_PARSER=1 -DENABLE_POST=1 -DENABLE_PLUGINS=1 -DENABLE_ANN=1 -DENABLE_KBIPACK=1 -DENABLE_GMP=0 -DENABLE_ZIPPER=1 -DENABLE_OCC=$enable_occ -DOCC_LIBS="$occt_framework/occt" -DOCC_INC="$occt_framework/Headers/" ..
check
$build_cmd OTHER_CFLAGS="${iphoneos_version_min} -fembed-bitcode" OTHER_CPLUSPLUSFLAGS="${iphoneos_version_min} -fembed-bitcode -std=c++11"
check
$headers_cmd
mkdir -p $gmsh_framework/Headers
cp $gmsh_git/build_${ios}/${buildtype}-${iphoneos}/libgmsh.a $gmsh_framework/gmsh
cd $gmsh_framework/Headers
cp -R $gmsh_git/build_${ios}/Headers/*.h $gmsh_git/build_${ios}/Headers/gmsh/* .
ln -s . gmsh

# build getdp framework
cd $getdp_git && git pull
mkdir -p $getdp_git/build_${ios}
cd $getdp_git/build_${ios}
PETSC_DIR= PETSC_ARCH= SLEPC_DIR= cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_LIB=1 -DENABLE_GMSH=1 -DENABLE_KERNEL=1 -DENABLE_PETSC=1 -DPETSC_INC="$petsc_framework/Headers/" -DPETSC_LIBS="$petsc_framework/petsc" -DENABLE_SLEPC=1 -DSLEPC_INC="$slepc_framework/Headers/" -DSLEPC_LIB="$slepc_framework/slepc" -DGMSH_INC="$gmsh_framework/Headers/" -DGMSH_LIB="$gmsh_framework/gmsh" ..
check
$build_cmd OTHER_CFLAGS="${iphoneos_version_min} -fembed-bitcode" OTHER_CPLUSPLUSFLAGS="${iphoneos_version_min} -fembed-bitcode -std=c++11"
check
$headers_cmd
mkdir -p $getdp_framework/Headers
cp $getdp_git/build_${ios}/${buildtype}-${iphoneos}/libgetdp.a $getdp_framework/getdp
cd $getdp_framework/Headers
cp $getdp_git/build_${ios}/Headers/*.h $getdp_git/build_${ios}/Headers/getdp/* .

# create xcode project
mkdir $gmsh_git/contrib/mobile/build_${ios}_${appname}
cd $gmsh_git/contrib/mobile/build_${ios}_${appname}
cmake -DMODELS_DIR="$models_dir" -DCMAKE_INCLUDE_PATH="$frameworks_dir" -DAPPNAME:STRING=${appname} ..
make xcodeProject

if [ $enable_simulator != 0 ]; then
  # change blas/lapack for simulator
  sed -e "s|lastKnownFileType = archive.ar; name = libf2cblas.a; path = ${appname}/frameworks/petsc.framework/libf2cblas.a;|lastKnownFileType = wrapper.framework; name = Accelerate.framework; path = System/Library/Frameworks/Accelerate.framework;|" -i "" $gmsh_git/contrib/mobile/build_iossimulator_${appname}/${appname}/${appname}.xcodeproj/project.pbxproj;
  sed -e "s|lastKnownFileType = archive.ar; name = libf2clapack.a; path = ${appname}/frameworks/petsc.framework/libf2clapack.a;|lastKnownFileType = wrapper.framework; name = Accelerate.framework; path = System/Library/Frameworks/Accelerate.framework;|" -i "" $gmsh_git/contrib/mobile/build_iossimulator_${appname}/${appname}/${appname}.xcodeproj/project.pbxproj;
  # change VALID_ARCHS
  sed -e "s|VALID_ARCHS = arm64|VALID_ARCHS = x86_64|" -i "" $gmsh_git/contrib/mobile/build_iossimulator_${appname}/${appname}/${appname}.xcodeproj/project.pbxproj;
fi

# TODO:
#
# xcodebuild -project "Onelab" -target "Onelab" -configuration Release
# xcrun -sdk iphoneos PackageApplication -v "Onelab.app" -o "Onelab.ipa" --sign "iPhone Distribution: Your Signature\" --embed enterprise.mobileprovision

# FIXME:
#
# When uploading the app to the AppStore, make sure to disable sending the
# bitcode. For some reason this leads to crashing installs (sometimes?)
