#/usr/bin/env bash

appname=Onelab
enable_occt=1
if [ $# -eq 1 ] ; then
  appname=${1}
  echo "Rebranding Onelab app as ${appname}"
  enable_occt=0
fi

gmsh_git="${HOME}/src/gmsh/"
getdp_git="${HOME}/src/getdp/"
frameworks_dir="${HOME}/src/gmsh/contrib/mobile/frameworks_iossimulator/"

if [ -f ${getdp_git}/benchmarks/cleanup.sh ]; then
  cd ${getdp_git}/benchmarks && ./cleanup.sh
fi
if [ -f ${getdp_git}/benchmarks_private/cleanup.sh ]; then
  cd ${getdp_git}/benchmarks_private && ./cleanup.sh
fi

petsc_framework="$frameworks_dir/petsc.framework"
slepc_framework="$frameworks_dir/slepc.framework"
gmsh_framework="$frameworks_dir/Gmsh.framework"
getdp_framework="$frameworks_dir/GetDP.framework"
occt_framework="$frameworks_dir/OCCT.framework"

cmake_default="-DDEFAULT=0 -DCMAKE_TOOLCHAIN_FILE=$gmsh_git/contrib/mobile/utils/iOS.cmake -DIOS_PLATFORM=SIMULATOR -DENABLE_BUILD_IOS=1 -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES=i386;x86_64 -GXcode"

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
cd $gmsh_git && git pull
mkdir -p $gmsh_git/build_iossimulator
cd $gmsh_git/build_iossimulator
cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_LIB=1 -DENABLE_MATHEX=1 -DENABLE_MESH=1 -DENABLE_ONELAB=1 -DENABLE_PARSER=1 -DENABLE_POST=1 -DENABLE_PLUGINS=1 -DENABLE_ANN=1 -DENABLE_TETGEN=1 -DENABLE_KBIPACK=1 -DENABLE_GMP=0 -DENABLE_ZIPPER=1 -DENABLE_OCC=$enable_occt -DOCC_LIBS="$occt_framework/OCCT" -DOCC_INC="$occt_framework/Headers/" ..
check
$build_cmd OTHER_CFLAGS="-mios-simulator-version-min=8.0" OTHER_CPLUSPLUSFLAGS="-mios-simulator-version-min=8.0 -std=c++11"
check
$headers_cmd
mkdir -p $gmsh_framework/Headers
cp $gmsh_git/build_iossimulator/Release-iphonesimulator/libGmsh.a $gmsh_framework/Gmsh
cd $gmsh_framework/Headers
cp $gmsh_git/build_iossimulator/Headers/gmsh/* .
ln -s . gmsh

# build getdp framework
cd $getdp_git && git pull
mkdir -p $getdp_git/build_iossimulator
cd $getdp_git/build_iossimulator
PETSC_DIR= PETSC_ARCH= SLEPC_DIR= cmake $cmake_default -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_LIB=1 -DENABLE_GMSH=1 -DENABLE_KERNEL=1 -DENABLE_PETSC=1 -DPETSC_INC="$petsc_framework/Headers/" -DPETSC_LIBS="$petsc_framework/petsc" -DENABLE_SLEPC=1 -DSLEPC_INC="$slepc_framework/Headers/" -DSLEPC_LIB="$slepc_framework/slepc" -DGMSH_INC="$gmsh_framework/Headers/" -DGMSH_LIB="$gmsh_framework/Gmsh" ..
check
$build_cmd OTHER_CFLAGS="-mios-simulator-version-min=8.0" OTHER_CPLUSPLUSFLAGS="-mios-simulator-version-min=8.0"
check
$headers_cmd
mkdir -p $getdp_framework/Headers
cp $getdp_git/build_iossimulator/Release-iphonesimulator/libGetDP.a $getdp_framework/GetDP
cd $getdp_framework/Headers
cp $getdp_git/build_iossimulator/Headers/getdp/* .

# create xcode project
mkdir $gmsh_git/contrib/mobile/build_iossimulator_${appname}
cd $gmsh_git/contrib/mobile/build_iossimulator_${appname}
cmake -DCMAKE_INCLUDE_PATH="$frameworks_dir;$getdp_git" -DAPPNAME:STRING=${appname} ..
make xcodeProject

# change blas/lapack for simulator
sed -e "s|lastKnownFileType = archive.ar; name = libf2cblas.a; path = Onelab/frameworks/petsc.framework/libf2cblas.a;|lastKnownFileType = wrapper.framework; name = Accelerate.framework; path = System/Library/Frameworks/Accelerate.framework;|" -i "" $gmsh_git/contrib/mobile/build_iossimulator_${appname}/${appname}/${appname}.xcodeproj/project.pbxproj
sed -e "s|lastKnownFileType = archive.ar; name = libf2clapack.a; path = Onelab/frameworks/petsc.framework/libf2clapack.a;|lastKnownFileType = wrapper.framework; name = Accelerate.framework; path = System/Library/Frameworks/Accelerate.framework;|" -i "" $gmsh_git/contrib/mobile/build_iossimulator_${appname}/${appname}/${appname}.xcodeproj/project.pbxproj
