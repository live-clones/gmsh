#!/bin/bash
# Build Gmsh for WebAssembly with Emscripten (experimental), without FLTK and
# without OpenCASCADE:
#
#   ./build.sh [extra cmake options]
#     the library and the graphics, driven by viewer.html, in ./build
#   ./build.sh page [extra cmake options]
#     the browser interface with Gmsh running inside the page, gmsh.html, in
#     ./build-page
#
# Emscripten: the emcc on the PATH, or in /usr/lib/emscripten where
# distributions put theirs, or else that of emsdk in $EMSDK (default:
# ~/src/emsdk). JOBS: how many files are compiled at once (default: all the
# processors).
#
# Testing:
#   python3 -m http.server 8000 --bind 127.0.0.1 --directory ~/src/gmsh
#   browse http://localhost:8000/utils/wasm/viewer.html
#   python3 -m http.server 8000 --bind 127.0.0.1 \
#     --directory ~/src/gmsh/utils/wasm/build-page
#   browse http://localhost:8000/gmsh.html?open=tutorials/t1.geo

set -e
HERE=$(cd "$(dirname "$0")" && pwd)
SRC=$(cd "$HERE/../.." && pwd)

MODE=viewer
if [ "$1" = page ]; then
  MODE=page
  shift
fi

if ! command -v emcc > /dev/null && [ -x /usr/lib/emscripten/emcc ]; then
  export PATH=$PATH:/usr/lib/emscripten
fi
if ! command -v emcc > /dev/null; then
  EMSDK=${EMSDK:-$HOME/src/emsdk}
  # emsdk needs Python >= 3.10: use the one it installs, as the system one may
  # be older (and then emsdk_env.sh leaves emcc off the PATH without a word)
  if [ -z "$EMSDK_PYTHON" ]; then
    EMSDK_PYTHON=$(ls -d "$EMSDK"/python/*/bin/python3 2>/dev/null | tail -1)
  fi
  export EMSDK_PYTHON
  source "$EMSDK/emsdk_env.sh" > /dev/null 2>&1 || true
fi
if ! command -v emcc > /dev/null; then
  echo "emcc not found: install Emscripten, or emsdk in $EMSDK"
  exit 1
fi
echo "Using $(emcc --version | head -1)"

# C++ exceptions caught (Gmsh reports errors through them), with the native
# exception handling of WebAssembly
EXC="-fwasm-exceptions"
if [ $MODE = page ]; then
  # main() runs the interface; CMake adds what the page needs
  DIR="$HERE/build-page"
  LINK=""
  OPTIONS="-DENABLE_BROWSER=1 -DENABLE_IMGUI=0"
else
  DIR="$HERE/build"
  # WebGL 2 (OpenGL ES 3.0), whose entry points glApi looks up by name
  LINK="-sMIN_WEBGL_VERSION=2 -sMAX_WEBGL_VERSION=2"
  LINK="$LINK -sGL_ENABLE_GET_PROC_ADDRESS=1"
  # the page initializes Gmsh itself (see viewer.html), main() is not run
  LINK="$LINK -sINVOKE_RUN=0"
  OPTIONS=""
fi

mkdir -p "$DIR"
cd "$DIR"
emcmake cmake "$SRC" -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_C_FLAGS="$EXC" -DCMAKE_CXX_FLAGS="$EXC" \
  -DENABLE_FLTK=0 -DENABLE_GRAPHICS=1 -DENABLE_OCC=0 -DENABLE_OPENMP=0 \
  -DENABLE_BUILD_DYNAMIC=0 -DENABLE_FFMPEG=0 $OPTIONS \
  -DCMAKE_EXE_LINKER_FLAGS="$EXC $LINK -Wl,--error-limit=0" "$@"
emmake make -j"${JOBS:-$(sysctl -n hw.ncpu 2>/dev/null || nproc)}" gmsh
