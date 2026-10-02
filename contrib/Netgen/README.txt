This directory contains a minimal subset of Joachim Sch\"oberl's NETGEN mesh
generator (https://github.com/NGSolve/netgen), version v6.2.2608 (commit
96e5682f6ea43ba77ba3bb2ae4bb4bd1791f506e), with only what Gmsh uses: the 3D
tetrahedral mesher (MeshVolume) and the 3D mesh optimizer (OptimizeVolume).

The files in libsrc/ are unmodified copies of the upstream files, except:

* libsrc/core/ngcore_api.hpp: NGCORE_API_EXPORT and NGCORE_API_IMPORT are
  empty, so that Netgen symbols are not exported (or imported) from Gmsh
* libsrc/core/simd.hpp: simd_arm64.hpp is only used with clang and the ARMv8.3
  complex instructions (it does not compile with gcc without
  -flax-vector-conversions, nor without vcmla); MakeSimd() gives the template
  arguments of MakeSimdCl explicitly (older Apple clang)
* libsrc/core/utils.cpp: cast the result of GetProcAddress() to void* (MinGW)
* libsrc/meshing/global.cpp: Ng_PrintDest() calls ng_print_dest_callback()
  if it is set, so that Gmsh can redirect Netgen's messages

The other files are:

* rules/rule_*.cpp: generated from upstream rules/*.rls with upstream
  rules/makerlsfile.cpp ("makerls hexrules.rls rule_hexrules.cpp hexrules")
* netgen_config.hpp and netgen_version.hpp: written by hand from upstream
  cmake/generate_version_file.cmake (no Python, MPI, OCC or GUI)
* nglib_gmsh.h and nglib_gmsh.cpp: Gmsh's interface to Netgen, modelled after
  upstream nglib/nglib.h and nglib/nglib.cpp. It also defines intersect(),
  which is only needed for 2D boundary layers and would otherwise require
  the 2D CSG and spline geometry (libsrc/geom2d)

The .cpp files listed in CMakeLists.txt are the ones the link of
nglib_gmsh.cpp needs; the headers are the ones they include (including all
the simd_*.hpp, used on other architectures). To update, copy the same files
from a new upstream version, regenerate the rules, reapply the patches
above, update the version in netgen_version.hpp, then check for new
dependencies by linking (add a .cpp file for each undefined symbol). Link
with both gcc and clang, at -O0 and -O2: the references differ with the
compiler and the optimization level (e.g. gcc -O2 keeps a copy of
LocalHeap::Alloc, which needs localheap.cpp, while clang -O2 inlines it).

Netgen needs zlib (libsrc/general/gzstream.cpp).

See the LICENSE file for license information.
