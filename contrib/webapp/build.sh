#!/bin/bash
# Build the Gmsh web app with Emscripten (experimental), in ./build: the Gmsh
# library and its JavaScript API with the WebGL drawing, with OpenCASCADE, and with GetDP run in-process as the ONELAB solver
# (onelab.html). The dependencies (OpenCASCADE, and PETSc and SLEPc with
# SuiteSparse and f2c BLAS/LAPACK for GetDP, all without Fortran or MPI) are
# downloaded and built once, in ./build/deps.
#
# Usage: ./build.sh [--no-occ] [--no-getdp] [extra cmake options for Gmsh]
# EMSDK: where emsdk is installed (default: ~/src/emsdk)
# GETDP: the GetDP sources (default: getdp next to the Gmsh sources)
# BUILD: the build directory (default: ./build)
#
# Testing:
#   python3 -m http.server 8000 --bind 127.0.0.1 --directory ~/src/gmsh
#   browse http://localhost:8000/contrib/webapp/onelab.html

set -e
HERE=$(cd "$(dirname "$0")" && pwd)
SRC=$(cd "$HERE/../.." && pwd)
EMSDK=${EMSDK:-$HOME/src/emsdk}
GETDP=${GETDP:-$SRC/../getdp}
JOBS=${JOBS:-$(sysctl -n hw.ncpu 2>/dev/null || nproc)}
OCCT_VERSION=8_0_1
PETSC_VERSION=3.25.1
SUITESPARSE_VERSION=7.12.2
SLEPC_VERSION=3.25.0

OCC=1
WITH_GETDP=1
while [[ "$1" == --no-* ]]; do
  case "$1" in
    --no-occ) OCC=0 ;;
    --no-getdp) WITH_GETDP=0 ;;
    *) echo "Usage: $0 [--no-occ] [--no-getdp] [cmake options]"; exit 1 ;;
  esac
  shift
done
if [ $WITH_GETDP == 1 -a ! -f "$GETDP/src/kernel/getdp.h" ]; then
  echo "GetDP sources not found in $GETDP: building without GetDP"
  WITH_GETDP=0
fi

# emsdk needs Python >= 3.10: use the one it installs, as the system one may
# be older (and then emsdk_env.sh leaves emcc off the PATH without a word)
if [ -z "$EMSDK_PYTHON" ]; then
  EMSDK_PYTHON=$(ls -d "$EMSDK"/python/*/bin/python3 2>/dev/null | tail -1)
fi
export EMSDK_PYTHON
source "$EMSDK/emsdk_env.sh" > /dev/null 2>&1
if ! command -v emcc > /dev/null; then
  echo "emcc not found: is emsdk installed and activated in $EMSDK?"
  exit 1
fi
echo "Using $(emcc --version | head -1)"
# a Fortran compiler in the environment would be used by SuiteSparse's CMake,
# which cannot work with Emscripten
unset FC F77 F90

B=${BUILD:-$HERE/build}
DEPS="$B/deps"
mkdir -p "$DEPS/src"
# C++ exceptions caught (Gmsh, GetDP and OpenCASCADE report errors through
# them), with the native exception handling of WebAssembly
EXC="-fwasm-exceptions"
# the Emscripten toolchain only looks for packages in its own sysroot
FIND="-DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=BOTH -DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=BOTH"

download() # url, directory it extracts to
{
  if [ ! -d "$DEPS/src/$2" ]; then
    echo "Downloading $1"
    curl -L --fail "$1" | tar -xz -C "$DEPS/src"
  fi
}

# OpenCASCADE: static, modeling algorithms and STEP/IGES, no visualization;
# without the conversion of signals to exceptions (there are no signals), as
# its setjmp next to C++ exceptions makes code that Binaryen cannot read; with
# <mutex>, which some of its sources use without including it, as the libc++
# of Emscripten 7 no longer brings it in through other headers
NOSIG="-UOCC_CONVERT_SIGNALS"
MUTEX="-include mutex"
if [ $OCC == 1 -a ! -f "$DEPS/occt/lib/libTKernel.a" ]; then
  download https://github.com/Open-Cascade-SAS/OCCT/archive/refs/tags/V$OCCT_VERSION.tar.gz \
    OCCT-$OCCT_VERSION
  mkdir -p "$DEPS/build/occt" && cd "$DEPS/build/occt"
  emcmake cmake "$DEPS/src/OCCT-$OCCT_VERSION" -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_LIBRARY_TYPE=Static -DBUILD_RELEASE_DISABLE_EXCEPTIONS=0 \
    -DUSE_OPENGL=0 -DUSE_GLES2=0 -DUSE_FREETYPE=0 -DUSE_TK=0 -DUSE_XLIB=0 \
    -DBUILD_MODULE_Draw=0 -DBUILD_MODULE_Visualization=0 \
    -DBUILD_MODULE_ApplicationFramework=0 -DBUILD_DOC_Overview=0 \
    -DCMAKE_C_FLAGS="$EXC $NOSIG" -DCMAKE_CXX_FLAGS="$EXC $NOSIG $MUTEX" \
    -DCMAKE_INSTALL_PREFIX="$DEPS/occt"
  emmake make -j$JOBS
  emmake make install
fi

# PETSc, sequential (no MPI) and C only (no Fortran), with f2c BLAS/LAPACK,
# SuiteSparse (UMFPACK is GetDP's default direct solver when MUMPS is absent)
# and SLEPc (eigenvalue problems); complex arithmetic, which GetDP's frequency
# domain and eigenvalue models need (real problems are solved as complex ones)
if [ $WITH_GETDP == 1 -a ! -f "$DEPS/petsc/lib/libslepc.a" ]; then
  download https://web.cels.anl.gov/projects/petsc/download/release-snapshots/petsc-$PETSC_VERSION.tar.gz \
    petsc-$PETSC_VERSION
  cd "$DEPS/src/petsc-$PETSC_VERSION"
  export PETSC_DIR=$PWD PETSC_ARCH=arch-wasm
  python3 ./configure --prefix="$DEPS/petsc" \
    --with-cc=emcc --with-cxx=em++ --with-fc=0 --with-ranlib=emranlib \
    --with-ar=emar --with-shared-libraries=0 --with-mpi=0 --with-batch \
    --with-debugging=0 --COPTFLAGS=-O2 --CXXOPTFLAGS=-O2 \
    --CFLAGS="$EXC" --CXXFLAGS="$EXC" --with-x=0 --with-ssl=0 \
    --with-pthread=0 --with-openmp=0 --with-scalar-type=complex \
    --known-sdot-returns-double=0 --known-snrm2-returns-double=0 \
    --download-f2cblaslapack=1 \
    --download-suitesparse=https://github.com/DrTimothyAldenDavis/SuiteSparse/archive/v$SUITESPARSE_VERSION.tar.gz \
    --download-slepc=https://gitlab.com/slepc/slepc/-/archive/v$SLEPC_VERSION/slepc-v$SLEPC_VERSION.tar.gz \
    --download-suitesparse-cmake-arguments="-DCMAKE_TOOLCHAIN_FILE=$EMSDK/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake -DSUITESPARSE_USE_FORTRAN=OFF"
  # Emscripten's sys/procfs.h does not compile on its own, but configure only
  # preprocesses it
  sed -i.bak 's|^#define PETSC_HAVE_SYS_PROCFS_H 1|/* #undef PETSC_HAVE_SYS_PROCFS_H */|' \
    $PETSC_ARCH/include/petscconf.h
  # PETSc's list of SuiteSparse libraries leaves out those a static link
  # needs (SLEPc, and then GetDP, link with that list)
  sed -i.bak 's|-lamd|-lamd -lcolamd -lccolamd -lcamd -lbtf -lsuitesparseconfig|g' \
    $PETSC_ARCH/lib/petsc/conf/petscvariables $PETSC_ARCH/lib/pkgconfig/PETSc.pc
  make all
  make install
  unset PETSC_DIR PETSC_ARCH
fi

# zlib (for compressed files and zip archives), from Emscripten's ports
embuilder build zlib > /dev/null

# Gmsh
GMSH_OPTIONS="-DENABLE_FLTK=0 -DENABLE_GRAPHICS=1 -DENABLE_OPENMP=0"
GMSH_OPTIONS="$GMSH_OPTIONS -DENABLE_BUILD_DYNAMIC=0 -DENABLE_FFMPEG=0"
GMSH_OPTIONS="$GMSH_OPTIONS -DENABLE_ZIPPER=1 -DENABLE_PRIVATE_API=1"
if [ $OCC == 1 ]; then
  export CASROOT="$DEPS/occt"
  GMSH_OPTIONS="$GMSH_OPTIONS -DENABLE_OCC=1 -DENABLE_OCC_CAF=0"
else
  GMSH_OPTIONS="$GMSH_OPTIONS -DENABLE_OCC=0"
fi
# WebGL 2 (OpenGL ES 3.0), whose entry points glApi looks up by name
LINK="-sMIN_WEBGL_VERSION=2 -sMAX_WEBGL_VERSION=2"
LINK="$LINK -sGL_ENABLE_GET_PROC_ADDRESS=1"
cd "$B"
gmsh_cmake()
{
  emcmake cmake "$SRC" -DCMAKE_BUILD_TYPE=Release $FIND \
    -DCMAKE_C_FLAGS="$EXC -sUSE_ZLIB=1" -DCMAKE_CXX_FLAGS="$EXC -sUSE_ZLIB=1" \
    $GMSH_OPTIONS \
    -DCMAKE_EXE_LINKER_FLAGS="$EXC -sUSE_ZLIB=1 $LINK -Wl,--error-limit=0" "$@"
}
# configured once, with GetDP's paths (its library is built below, before
# Gmsh's), as configuring again with other settings rewrites the compile
# flags all of Gmsh depends on, and recompiles it
if [ $WITH_GETDP == 1 ]; then
  LIBS="$B/getdp/libgetdp.a"
  for l in slepc petsc spqr umfpack klu cholmod amd colamd ccolamd camd btf \
           suitesparseconfig f2clapack f2cblas; do
    LIBS="$LIBS;$DEPS/petsc/lib/lib$l.a"
  done
  gmsh_cmake -DWEBAPP_GETDP_INC="$GETDP/src/kernel" -DWEBAPP_GETDP_LIBS="$LIBS" "$@"
else
  gmsh_cmake -UWEBAPP_GETDP_INC -UWEBAPP_GETDP_LIBS "$@"
fi

# GetDP, as a static library using Gmsh's headers (its private API)
if [ $WITH_GETDP == 1 ]; then
  emmake make get_headers > /dev/null
  mkdir -p "$B/getdp" && cd "$B/getdp"
  PETSC_DIR="$DEPS/petsc" PETSC_ARCH= SLEPC_DIR="$DEPS/petsc" \
    emcmake cmake "$GETDP" \
    -DCMAKE_BUILD_TYPE=Release $FIND -DDEFAULT=0 -DENABLE_KERNEL=1 \
    -DENABLE_PETSC=1 -DENABLE_SLEPC=1 -DENABLE_NR=1 -DENABLE_BLAS_LAPACK=0 -DENABLE_FORTRAN=0 \
    -DENABLE_GMSH=1 -DGMSH_INC="$B/Headers" -DGMSH_LIB="$B/libgmsh.mjs" \
    -DENABLE_BUILD_LIB=1 -DCMAKE_C_FLAGS="$EXC" -DCMAKE_CXX_FLAGS="$EXC"
  emmake make -j$JOBS lib
  cd "$B"
  # GetDP's templates (Interactive.pro and the libraries it includes), which
  # onelab.html merges onto a geometry, and their list
  mkdir -p "$B/templates"
  cp "$GETDP"/templates/Interactive*.pro "$GETDP"/templates/Lib_*.pro "$B/templates"
  (cd "$B/templates" && ls *.pro | sed 's/.*/"&"/' | paste -sd, - |
     sed 's/.*/[&]/' > index.json)
fi

# the library (libgmsh.mjs, libgmsh.wasm) and its JavaScript API (gmsh.mjs);
# the gmsh target is the program (gmsh.js)
emmake make -j$JOBS libgmsh
