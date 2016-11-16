#/usr/bin/env bash

appname=Onelab
if [ $# -eq 1 ] ; then
  appname=${1}
  echo "Rebranding Onelab app as ${appname}"
fi

gmsh_svn="${HOME}/src/gmsh/"
getdp_svn="${HOME}/src/getdp/"
frameworks_dir="${HOME}/src/gmsh/contrib/mobile/frameworks_iossimulator/"

if [ -f ${getdp_svn}/benchmarks/cleanup.sh ]; then
  cd ${getdp_svn}/benchmarks && ./cleanup.sh
fi
if [ -f ${getdp_svn}/benchmarks_private/cleanup.sh ]; then
  cd ${getdp_svn}/benchmarks_private && ./cleanup.sh
fi

petsc_framework="$frameworks_dir/petsc.framework"
slepc_framework="$frameworks_dir/slepc.framework"
gmsh_framework="$frameworks_dir/Gmsh.framework"
getdp_framework="$frameworks_dir/GetDP.framework"

cmake_default="-DDEFAULT=0 -DCMAKE_TOOLCHAIN_FILE=$gmsh_svn/contrib/mobile/utils/iOS.cmake -DIOS_PLATFORM=SIMULATOR -DENABLE_BUILD_IOS=1 -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES=i386;x86_64 -GXcode"

build_cmd="xcodebuild -target lib -configuration Release"
headers_cmd="xcodebuild -target get_headers -configuration Release"

function check {
  return_code=$?
  if [ $return_code != 0 ]; then
    echo "last command failed (return $return_code)"
    exit $return_code
  fi
}

# build gmsh framework
cd $gmsh_svn && svn up
mkdir -p $gmsh_svn/build_iossimulator
cd $gmsh_svn/build_iossimulator
cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_LIB=1 -DENABLE_MATHEX=1 -DENABLE_MESH=1 -DENABLE_ONELAB=1 -DENABLE_PARSER=1 -DENABLE_POST=1 -DENABLE_PLUGINS=1 -DENABLE_ANN=1 -DENABLE_TETGEN=1 -DENABLE_KBIPACK=1 -DENABLE_GMP=0 -DENABLE_ZIPPER=1 ..
check
$build_cmd OTHER_CFLAGS="-mios-simulator-version-min=8.0" OTHER_CPLUSPLUSFLAGS="-mios-simulator-version-min=8.0"
check
$headers_cmd
mkdir -p $gmsh_framework/Headers
cp $gmsh_svn/build_iossimulator/Release-iphonesimulator/libGmsh.a $gmsh_framework/Gmsh
cd $gmsh_framework/Headers
cp $gmsh_svn/build_iossimulator/Headers/gmsh/* .
ln -s . gmsh

# build getdp framework
cd $getdp_svn && svn up
mkdir -p $getdp_svn/build_iossimulator
cd $getdp_svn/build_iossimulator
PETSC_DIR= PETSC_ARCH= SLEPC_DIR= cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_LIB=1 -DENABLE_GMSH=1 -DENABLE_KERNEL=1 -DENABLE_PETSC=1 -DPETSC_INC="$petsc_framework/Headers/" -DPETSC_LIBS="$petsc_framework/petsc" -DENABLE_SLEPC=1 -DSLEPC_INC="$slepc_framework/Headers/" -DSLEPC_LIB="$slepc_framework/slepc" -DGMSH_INC="$gmsh_framework/Headers/" -DGMSH_LIB="$gmsh_framework/Gmsh" ..
check
$build_cmd OTHER_CFLAGS="-mios-simulator-version-min=8.0" OTHER_CPLUSPLUSFLAGS="-mios-simulator-version-min=8.0"
check
$headers_cmd
mkdir -p $getdp_framework/Headers
cp $getdp_svn/build_iossimulator/Release-iphonesimulator/libGetDP.a $getdp_framework/GetDP
cd $getdp_framework/Headers
cp $getdp_svn/build_iossimulator/Headers/getdp/* .

# create xcode project
mkdir $gmsh_svn/contrib/mobile/build_iossimulator_${appname}
cd $gmsh_svn/contrib/mobile/build_iossimulator_${appname}
cmake -DCMAKE_INCLUDE_PATH="$frameworks_dir;$getdp_svn" -DAPPNAME:STRING=${appname} ..
make xcodeProject

# change blas/lapack for simulator
sed -e "s|lastKnownFileType = archive.ar; name = libf2cblas.a; path = ../../frameworks_ios/libf2cblas.a;|lastKnownFileType = wrapper.framework; name = Accelerate.framework; path = System/Library/Frameworks/Accelerate.framework;|" -i "" $gmsh_svn/contrib/mobile/build_iossimulator_${appname}/${appname}/${appname}.xcodeproj/project.pbxproj
sed -e "s|lastKnownFileType = archive.ar; name = libf2clapack.a; path = ../../frameworks_ios/libf2clapack.a;|lastKnownFileType = wrapper.framework; name = Accelerate.framework; path = System/Library/Frameworks/Accelerate.framework;|" -i "" $gmsh_svn/contrib/mobile/build_iossimulator_${appname}/${appname}/${appname}.xcodeproj/project.pbxproj
