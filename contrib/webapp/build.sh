#!/bin/bash
# Build Gmsh for WebAssembly with Emscripten (experimental): the library and
# the graphics, without the graphical interface (FLTK) and without
# OpenCASCADE, in ./build
#
# Usage: ./build.sh [extra cmake options]
# EMSDK: where emsdk is installed (default: ~/src/emsdk)
#
# Testing:
#   python3 -m http.server 8000 --bind 127.0.0.1 --directory ~/src/gmsh
#   browse http://localhost:8000/utils/wasm/viewer.html

set -e
HERE=$(cd "$(dirname "$0")" && pwd)
SRC=$(cd "$HERE/../.." && pwd)
EMSDK=${EMSDK:-$HOME/src/emsdk}

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

mkdir -p "$HERE/build"
cd "$HERE/build"
# WebGL 2 (OpenGL ES 3.0), whose entry points glApi looks up by name
LINK="-sMIN_WEBGL_VERSION=2 -sMAX_WEBGL_VERSION=2"
LINK="$LINK -sGL_ENABLE_GET_PROC_ADDRESS=1"
# C++ exceptions caught (Gmsh reports errors through them), with the native
# exception handling of WebAssembly
EXC="-fwasm-exceptions"
emcmake cmake "$SRC" -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_C_FLAGS="$EXC" -DCMAKE_CXX_FLAGS="$EXC" \
  -DENABLE_FLTK=0 -DENABLE_GRAPHICS=1 -DENABLE_OCC=0 -DENABLE_OPENMP=0 \
  -DENABLE_BUILD_DYNAMIC=0 -DENABLE_FFMPEG=0 \
  -DCMAKE_EXE_LINKER_FLAGS="$EXC $LINK -Wl,--error-limit=0" "$@"
# the library and its JavaScript API (the gmsh target is the program,
# build/gmsh.js)
emmake make -j"$(sysctl -n hw.ncpu 2>/dev/null || nproc)" libgmsh
