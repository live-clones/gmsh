# Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

# if CMAKE_BUILD_TYPE is specified use it; otherwise set the default
# build type to "RelWithDebInfo" ("-O2 -g" with gcc) prior to calling
# project()
if(DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose build type")
else()
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose build type")
endif()

project(gmsh CXX C)

# require C++14 and request C99
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)

# this variable controls the default value of the options which are normally set
# to ON (useful if you want to configure a minimal version of Gmsh: e.g. "cmake
# -DDEFAULT=0 -DENABLE_POST=1 -DENABLE_PARSER=1")
set(DEFAULT ON CACHE INTERNAL "Default value for enabled-by-default options")

macro(opt OPTION HELP VALUE)
  option(ENABLE_${OPTION} ${HELP} ${VALUE})
  set(OPT_TEXI "${OPT_TEXI}\n@item ENABLE_${OPTION}\n${HELP} (default: ${VALUE})")
endmacro()

opt(3M "Enable proprietary 3M extension" OFF)
opt(ALGLIB "Enable ALGLIB (used by some mesh optimizers)" ${DEFAULT})
opt(ANN "Enable ANN (used for fast point search in mesh/post)" ${DEFAULT})
opt(BAMG "Enable Bamg 2D anisotropic mesh generator" ${DEFAULT})
opt(BLAS_LAPACK "Enable BLAS/Lapack for linear algebra (if Eigen if disabled)" OFF)
opt(BLOSSOM "Enable Blossom algorithm (needed for full quad meshing)" ${DEFAULT})
opt(BUILD_LIB "Enable 'lib' target for building static Gmsh library" OFF)
opt(BUILD_SHARED "Enable 'shared' target for building shared Gmsh library" OFF)
opt(BUILD_DYNAMIC "Enable dynamic Gmsh executable (linked with shared library)" OFF)
opt(BUILD_ANDROID "Enable Android NDK library target (experimental)" OFF)
opt(BUILD_IOS "Enable iOS library target (experimental)" OFF)
opt(CGNS "Enable CGNS import/export (experimental)" ${DEFAULT})
opt(CGNS_CPEX0045 "Enable high-order CGNS import/export following CPEX0045 (experimental)" OFF)
opt(CAIRO "Enable Cairo to render fonts (experimental)" ${DEFAULT})
opt(PROFILE "Enable profiling compiler flags" OFF)
opt(DINTEGRATION "Enable discrete integration (needed for levelsets)" ${DEFAULT})
opt(DOMHEX "Enable experimental DOMHEX code" ${DEFAULT})
opt(EIGEN "Enable Eigen for linear algebra (instead of Blas/Lapack)" ON)
opt(FLTK "Enable FLTK graphical user interface (requires mesh/post)" ${DEFAULT})
opt(GEOMETRYCENTRAL "Enable geometry-central library (experimental)" ${DEFAULT})
opt(GETDP "Enable GetDP solver (linked as a library, experimental)" ${DEFAULT})
opt(GMM "Enable GMM linear solvers (simple alternative to PETSc)" ${DEFAULT})
opt(GMP "Enable GMP for Kbipack (advanced)" ON)
opt(GRAPHICS "Enable building graphics lib even without GUI (advanced)" OFF)
opt(HXT "Enable HXT library (for reparametrization and meshing)" ${DEFAULT})
opt(KBIPACK "Enable Kbipack (neeeded by homology solver)" ${DEFAULT})
opt(MATHEX "Enable Mathex expression parser (used by plugins and options)" ${DEFAULT})
opt(MED "Enable MED mesh and post file formats" ${DEFAULT})
opt(MESH "Enable mesh module" ${DEFAULT})
opt(MESQUITE "Enable mesquite" ${DEFAULT})
opt(METIS "Enable Metis mesh partitioner" ${DEFAULT})
opt(MMG "Enable Mmg mesh adaptation interface" ${DEFAULT})
opt(MPEG_ENCODE "Enable built-in MPEG movie encoder" ${DEFAULT})
opt(MPI "Enable MPI (experimental, not used for meshing)" OFF)
opt(MSVC_STATIC_RUNTIME "Enable static Visual C++ runtime" OFF)
opt(MUMPS "Enable MUMPS sparse direct linear solver" OFF)
opt(NETGEN "Enable Netgen 3D frontal mesh generator" ${DEFAULT})
opt(NII2MESH "Enable 3D voxel image to a triangulated mesh" ${DEFAULT})
opt(NUMPY "Enable fullMatrix and numpy array conversion for private API" OFF)
opt(PETSC4PY "Enable petsc4py wrappers for petsc matrices for private API" OFF)
opt(OCC "Enable OpenCASCADE CAD kernel" ${DEFAULT})
opt(OCC_CAF "Enable OpenCASCADE CAF module (for STEP/IGES attributes)" ${DEFAULT})
opt(OCC_STATIC "Link OpenCASCADE static instead of dynamic libraries (requires ENABLE_OCC)" OFF)
opt(OCC_TBB "Add TBB libraries in list of OCC libraries" OFF)
opt(ONELAB "Enable ONELAB solver interface" ${DEFAULT})
opt(ONELAB_METAMODEL "Enable ONELAB metamodels (experimental)" ${DEFAULT})
opt(OPENACC "Enable OpenACC" OFF)
opt(OPENMP "Enable OpenMP" ${DEFAULT})
opt(OPTHOM "Enable high-order mesh optimization tools" ${DEFAULT})
opt(OS_SPECIFIC_INSTALL "Enable OS-specific (e.g. app bundle) installation" OFF)
opt(OSMESA "Enable OSMesa for offscreen rendering (experimental)" OFF)
opt(P4EST "Enable p4est for enabling automatic mesh size field (experimental)" OFF)
opt(PACKAGE_STRIP "Strip symbols in install packages to reduce install size" ON)
opt(PARSER "Enable GEO file parser (required for .geo/.pos scripts)" ${DEFAULT})
opt(PETSC "Enable PETSc linear solvers (required for SLEPc)" OFF)
opt(PLUGINS "Enable post-processing plugins" ${DEFAULT})
opt(POST "Enable post-processing module (required by GUI)" ${DEFAULT})
opt(POPPLER "Enable Poppler for displaying PDF documents (experimental)" OFF)
opt(PRIVATE_API "Enable private API" OFF)
opt(PRO "Enable PRO extensions" ${DEFAULT})
opt(QUADMESHINGTOOLS "Enable QuadMeshingTools extensions" ${DEFAULT})
opt(QUADTRI "Enable QuadTri structured meshing extensions" ${DEFAULT})
opt(REVOROPT "Enable Revoropt (used for CVT remeshing)" OFF)
opt(RPATH "Use RPATH in dynamically linked targets" ON)
opt(SLEPC "Enable SLEPc eigensolvers" OFF)
opt(SOLVER "Enable built-in finite element solvers (required for reparametrization)" ${DEFAULT})
opt(SYSTEM_CONTRIB "Use system versions of contrib libraries, when possible" OFF)
opt(TCMALLOC "Enable libtcmalloc (fast malloc that does not release memory)" OFF)
opt(TESTS "Enable tests" ${DEFAULT})
opt(TINYXML2 "Enable TinyXML2 parser (used by XAO reader)" ${DEFAULT})
opt(TOUCHBAR "Enable Apple Touch bar" ${DEFAULT})
opt(UNTANGLE "Enable 2D and 3D UNTANGLER" ${DEFAULT})
opt(VISUDEV "Enable additional visualization capabilities for development purposes" OFF)
opt(VOROPP "Enable voro++ (for hex meshing, experimental)" ${DEFAULT})
opt(WINSLOWUNTANGLER "Enable WinslowUntangler extensions (requires ALGLIB)" ${DEFAULT})
opt(WRAP_JAVA "Generate SWIG Java wrappers for private API" OFF)
opt(WRAP_PYTHON "Generate SWIG Python wrappers for private API (not used by public API)" OFF)
opt(ZIPPER "Enable Zip file compression/decompression" OFF)

set(GMSH_MAJOR_VERSION 4)
set(GMSH_MINOR_VERSION 13)
set(GMSH_PATCH_VERSION 0)
if(NOT GMSH_EXTRA_VERSION)
  set(GMSH_EXTRA_VERSION "")
endif()
set(GMSH_EXTRA_VERSION_TEXI "${GMSH_EXTRA_VERSION}")
set(GMSH_EXTRA_VERSION_ORIG ${GMSH_EXTRA_VERSION})

if(NOT GMSH_RELEASE)
  find_package(Git)
  if(GIT_FOUND)
    execute_process(COMMAND ${GIT_EXECUTABLE} log -1 --format=%h
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} ERROR_QUIET
                    OUTPUT_VARIABLE GIT_COMMIT_HASH
                    OUTPUT_STRIP_TRAILING_WHITESPACE)
  endif()
  if(GIT_COMMIT_HASH)
    set(GMSH_EXTRA_VERSION "${GMSH_EXTRA_VERSION}-git-${GIT_COMMIT_HASH}")
  endif()
  set(GMSH_EXTRA_VERSION_TEXI "${GMSH_EXTRA_VERSION_TEXI} (development version)")
endif()

set(GMSH_SHORT_VERSION
    "${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION}.${GMSH_PATCH_VERSION}")
set(GMSH_VERSION "${GMSH_SHORT_VERSION}${GMSH_EXTRA_VERSION}")
set(GMSH_SHORT_LICENSE "GNU General Public License")

set(GMSH_GITLAB_PREFIX "https://gitlab.onelab.info/gmsh/gmsh")
if(GMSH_RELEASE)
  string(REPLACE "\." "_" GMSH_SHORT_VERSION_ ${GMSH_SHORT_VERSION})
  set(GMSH_GITLAB_PREFIX "${GMSH_GITLAB_PREFIX}/blob/gmsh_${GMSH_SHORT_VERSION_}")
else()
  set(GMSH_GITLAB_PREFIX "${GMSH_GITLAB_PREFIX}/blob/master")
endif()

set(GMSH_API api/gmsh.h api/gmshc.h api/gmsh.h_cwrap api/gmsh.f90)

if(ENABLE_PRIVATE_API)
  message(WARNING "The private API is unsupported and undocumented. It is meant "
          "for expert Gmsh developers, not for regular Gmsh users, who should rely "
          "on the stable public API (gmsh/api) instead.")
  file(GLOB_RECURSE HEADERS src/common/*.h src/numeric/*.h src/numeric/*.hpp
       src/geo/*.h src/mesh/*.h src/solver/*.h src/post/*.h src/plugin/*.h
       src/graphics/*.h contrib/kbipack/*.h contrib/DiscreteIntegration/*.h
       contrib/HighOrderMeshOptimizer/*.h contrib/MeshOptimizer/*.h
       contrib/MeshQualityOptimizer/*.h)
  set(GMSH_PRIVATE_API ${CMAKE_CURRENT_BINARY_DIR}/src/common/GmshConfig.h
      ${CMAKE_CURRENT_BINARY_DIR}/src/common/GmshVersion.h ${HEADERS})
  get_property(IAMCHILD DIRECTORY PROPERTY PARENT_DIRECTORY)
  if(IAMCHILD)
    set(GMSH_PRIVATE_API ${GMSH_PRIVATE_API} PARENT_SCOPE)
  endif()
  if(ENABLE_WRAP_PYTHON OR ENABLE_WRAP_JAVA)
    set(ENABLE_BUILD_DYNAMIC ON)
    message(WARNING "SWIG wrappers for the private API are unsupported and "
            "undocumented. The stable public Python API does not required SWIG.")
  endif()
endif()

set(ONELAB_PY contrib/onelab/python/onelab.py)
set(GMSH_PY api/gmsh.py)
set(GMSH_JL api/gmsh.jl)

if(${CMAKE_MAJOR_VERSION} GREATER 2)
  string(TIMESTAMP DATE "%Y%m%d")
else()
  execute_process(COMMAND date "+%Y%m%d" OUTPUT_VARIABLE DATE
                  OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()

if(NOT DATE)
  set(DATE "unknown")
endif()
set(GMSH_DATE "${DATE}")

if(NOT GMSH_HOST)
  execute_process(COMMAND hostname OUTPUT_VARIABLE HOST
                  OUTPUT_STRIP_TRAILING_WHITESPACE)
  if(NOT HOST)
    set(HOST "unknown")
  endif()
  set(GMSH_HOST "${HOST}")
endif()

if(NOT GMSH_PACKAGER)
  execute_process(COMMAND whoami OUTPUT_VARIABLE PACKAGER
                  OUTPUT_STRIP_TRAILING_WHITESPACE)
  if(NOT PACKAGER)
    set(PACKAGER "unknown")
  endif()
  string(REPLACE "\\" " " PACKAGER ${PACKAGER})
  set(GMSH_PACKAGER "${PACKAGER}")
endif()

if(APPLE)
  if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm64")
    set(GMSH_OS "MacOSARM")
  else()
    set(GMSH_OS "MacOSX")
  endif()
  # build universal binary
  #SET(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "Build architectures for macOS" FORCE)
elseif(CYGWIN OR MSYS)
  # detect if we use the MinGW compilers on Cygwin - if we do, handle the build
  # as a pure Windows build and make cmake find pure Windows import libraries
  # (.lib)
  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR
     CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpmachine
                    OUTPUT_VARIABLE CXX_COMPILER_MACHINE
                    OUTPUT_STRIP_TRAILING_WHITESPACE)
    if(CXX_COMPILER_MACHINE MATCHES "mingw")
      set(GMSH_OS "Windows")
      set(WIN32 1)
      add_definitions(-DWIN32)
      set(CMAKE_FIND_LIBRARY_PREFIXES "lib" "")
      set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" ".so" ".lib" ".LIB" ".dll" ".DLL" ".dll.a")
    endif()
  endif()
endif()
if(NOT GMSH_OS)
  set(GMSH_OS "${CMAKE_SYSTEM_NAME}")
endif()

include(CheckTypeSize)
include(CheckSymbolExists)
include(CheckIncludeFile)
include(CheckCXXCompilerFlag)
include(CheckCCompilerFlag)

macro(set_config_option VARNAME STRING)
  set(${VARNAME} TRUE)
  list(APPEND CONFIG_OPTIONS ${STRING})
  message(STATUS "Found " ${STRING})
endmacro()

# check the size of size_t
check_type_size("size_t" SIZEOF_SIZE_T)
if(SIZEOF_SIZE_T EQUAL 8)
  set_config_option(HAVE_64BIT_SIZE_T "64Bit")
endif()

# append 32/64 to the build name on Linux and Windows
if(NOT APPLE)
  if(HAVE_64BIT_SIZE_T)
    set(GMSH_OS "${GMSH_OS}64")
  else()
    set(GMSH_OS "${GMSH_OS}32")
  endif()
endif()

if(ENABLE_BUILD_DYNAMIC)
  set(GMSH_OS "${GMSH_OS}-sdk")
endif()

if(ENABLE_RPATH)
  set(CMAKE_MACOSX_RPATH 1)

  # make sure that dynamic libraries can be found when installing/ displacing
  # the binaries: from https://gitlab.kitware.com/cmake/community/wikis/doc/
  # cmake/RPATH-handling:

  # use, i.e. don't skip the full RPATH for the build tree
  set(CMAKE_SKIP_BUILD_RPATH FALSE)

  # when building, don't use the install RPATH already (but later on when
  # installing)
  set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
  set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

  # add the automatically determined parts of the RPATH which point to
  # directories outside the build tree to the install RPATH
  set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

  # the RPATH to be used when installing, but only if it's not a system directory
  list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib"
       isSystemDir)
  if("${isSystemDir}" STREQUAL "-1")
    if(APPLE)
      set(CMAKE_INSTALL_RPATH "@executable_path/../lib")
    else()
      set(CMAKE_INSTALL_RPATH "\\\$ORIGIN/../lib")
    endif()
  endif()
else()
  set(CMAKE_MACOSX_RPATH 0)
  set(CMAKE_SKIP_BUILD_RPATH TRUE)
endif()

if(MSVC)
  # remove annoying warning about bool/int cast performance
  set(GMSH_CONFIG_PRAGMAS "#pragma warning(disable:4800 4244 4267)")
  foreach(VAR
          CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
          CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
          CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
          CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
    if(ENABLE_MSVC_STATIC_RUNTIME AND ${VAR} MATCHES "/MD")
      string(REGEX REPLACE "/MD" "/MT" ${VAR} "${${VAR}}")
    endif()
    if(NOT ${VAR} MATCHES "/MP") # enable parallel compilation
      set(${VAR} "${${VAR}} /MP")
    endif()
  endforeach()
  if(ENABLE_PRIVATE_API)
    if(ENABLE_BUILD_DYNAMIC OR ENABLE_BUILD_SHARED)
      # automatically export .def file with all symbols (requires CMake 3.4);
      # depending on the compiling options this might lead to more than 64k export
      # symbols; just trim the .def file to keep the ones you need
      set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    endif()
  endif()
endif()

# reduce memory usage of GCC on 32 bit systems
if(NOT HAVE_64BIT_SIZE_T AND CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} --param ggc-min-expand=1 --param ggc-min-heapsize=512000")
endif()

if(ENABLE_OPENMP)
  find_package(OpenMP)
  if(OpenMP_FOUND OR OPENMP_FOUND)
    set_config_option(HAVE_OPENMP "OpenMP")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    list(APPEND EXTERNAL_LIBRARIES "${OpenMP_CXX_LIBRARIES}")
  elseif(APPLE AND EXISTS "/opt/local/lib/libomp")
    # official Apple compiler with macports' libomp
    set_config_option(HAVE_OPENMP "OpenMP[MacPorts]")
    set(CMAKE_C_FLAGS
        "${CMAKE_C_FLAGS} -Xpreprocessor -fopenmp -I/opt/local/include/libomp")
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp -I/opt/local/include/libomp")
    list(APPEND EXTERNAL_LIBRARIES "-L/opt/local/lib/libomp -lomp")
  elseif(APPLE AND EXISTS "/usr/local/lib/libomp.dylib")
    # official Apple compiler with homebrew's libomp on Intel
    set_config_option(HAVE_OPENMP "OpenMP[Homebrew]")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Xpreprocessor -fopenmp")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp")
    list(APPEND EXTERNAL_LIBRARIES "-L/usr/local/lib -lomp")
  elseif(APPLE AND EXISTS "/opt/homebrew/opt/libomp")
    # official Apple compiler with homebrew's libomp on M processors
    set_config_option(HAVE_OPENMP "OpenMP[Homebrew]")
    set(CMAKE_C_FLAGS
        "${CMAKE_C_FLAGS} -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include")
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include")
    list(APPEND EXTERNAL_LIBRARIES "-L/opt/homebrew/opt/libomp/lib -lomp")
  elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux" AND EXISTS "/usr/local/lib64/libgomp.a")
    # custom static openmp for official linux builds
    set_config_option(HAVE_OPENMP "OpenMP[static]")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Xpreprocessor -fopenmp")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp")
    list(APPEND EXTERNAL_LIBRARIES "/usr/local/lib64/libgomp.a")
  endif()
endif()

if(ENABLE_OPENACC)
  find_package(OpenACC)
  if(OpenACC_C_FOUND AND OpenACC_CXX_FOUND)
    set_config_option(HAVE_OPENACC "OpenACC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenACC_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenACC_CXX_FLAGS}")
  endif()
endif()

if(ENABLE_PROFILE)
    # Using the perf set of profiling tools doesn't work without the frame
    # pointer and a common optimisation is to remove it
    check_cxx_compiler_flag("-fno-omit-frame-pointer" FNOFP)
    if(FNOFP)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer")
    endif()
endif()

macro(append_gmsh_src DIRNAME FILES)
  foreach(FILE ${FILES})
    list(APPEND LIST ${DIRNAME}/${FILE})
  endforeach()
  set(GMSH_SRC ${GMSH_SRC};${LIST} PARENT_SCOPE)
  set(GMSH_DIRS ${GMSH_DIRS};${DIRNAME} PARENT_SCOPE)
endmacro()

macro(find_all_libraries VARNAME LISTNAME PATH SUFFIX)
  set(${VARNAME})
  list(LENGTH ${LISTNAME} NUM_LIST)
  foreach(LIB ${${LISTNAME}})
    if("${PATH}" STREQUAL "")
      find_library(FOUND_LIB ${LIB} PATH_SUFFIXES ${SUFFIX})
    else()
      find_library(FOUND_LIB ${LIB} PATHS ${PATH} NO_DEFAULT_PATH)
    endif()
    if(FOUND_LIB)
      list(APPEND ${VARNAME} ${FOUND_LIB})
    endif()
    unset(FOUND_LIB CACHE)
  endforeach()
  list(LENGTH ${VARNAME} NUM_FOUND_LIBRARIES)
  if(NUM_FOUND_LIBRARIES LESS NUM_LIST)
    set(${VARNAME})
  endif()
endmacro()

macro(set_compile_flags LISTNAME FLAGS)
  foreach(FILE ${${LISTNAME}})
    get_source_file_property(PROP ${FILE} COMPILE_FLAGS)
    if(PROP)
      set_source_files_properties(${FILE} PROPERTIES COMPILE_FLAGS "${PROP} ${FLAGS}")
    else()
      set_source_files_properties(${FILE} PROPERTIES COMPILE_FLAGS "${FLAGS}")
    endif()
  endforeach()
endmacro()

if(ENABLE_GEOMETRYCENTRAL)
  find_library(GEOMETRYCENTRAL_LIB NAMES geometry-central)
  find_path(GEOMETRYCENTRAL_INC "surface/meshio.h" PATH_SUFFIXES geometrycentral)
  if(GEOMETRYCENTRAL_LIB AND GEOMETRYCENTRAL_INC)
    list(APPEND EXTERNAL_LIBRARIES ${GEOMETRYCENTRAL_LIB})
    list(APPEND EXTERNAL_INCLUDES ${GEOMETRYCENTRAL_INC})
    set_config_option(HAVE_GEOMETRYCENTRAL "geometry-central")
  endif()
endif()

if(ENABLE_EIGEN)
  if(ENABLE_SYSTEM_CONTRIB)
    find_path(EIGEN_INC "Eigen/Dense" PATH_SUFFIXES eigen3)
    if(EIGEN_INC)
      include_directories(${EIGEN_INC})
      set_config_option(HAVE_EIGEN "Eigen")
      set(HAVE_CONTRIB_EIGEN FALSE)
    endif()
  endif()
  if(NOT HAVE_EIGEN AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/eigen)
    include_directories(contrib/eigen)
    set_config_option(HAVE_EIGEN "Eigen[contrib]")
    set(HAVE_CONTRIB_EIGEN TRUE)
  endif()
  # We could also add an option to use BLAS with Eigen
  # add_definitions(-DEIGEN_USE_BLAS)
endif()

if(NOT HAVE_EIGEN AND ENABLE_BLAS_LAPACK)
  if(BLAS_LAPACK_LIBRARIES)
    # use libs as specified in the BLAS_LAPACK_LIBRARIES variable
    set_config_option(HAVE_BLAS "Blas[custom]")
    set_config_option(HAVE_LAPACK "Lapack[custom]")
    set(LAPACK_LIBRARIES ${BLAS_LAPACK_LIBRARIES})
  else()
    if(MSVC)
      # on Windows with Visual C++ try really hard to find blas/lapack *without*
      # requiring a Fortran compiler: 1) try to find the Intel MKL libs using
      # the standard search path; if not found 2) try to get the reference
      # blas/lapack libs (useful for users with no Fortran compiler and no MKL
      # license, who can just download our precompiled "gmsh-dep" package)
      if(HAVE_64BIT_SIZE_T)
        set(MKL_PATH em64t/lib)
        set(MKL_LIBS_REQUIRED libguide40 mkl_intel_lp64 mkl_intel_thread mkl_core)
      else()
        set(MKL_PATH ia32/lib)
        set(MKL_LIBS_REQUIRED libguide40 mkl_intel_c mkl_intel_thread mkl_core)
      endif()
      find_all_libraries(LAPACK_LIBRARIES MKL_LIBS_REQUIRED "" ${MKL_PATH})
      if(LAPACK_LIBRARIES)
        set_config_option(HAVE_BLAS "Blas[mkl]")
        set_config_option(HAVE_LAPACK "Lapack[mkl]")
      else()
        set(REFLAPACK_LIBS_REQUIRED lapack blas g2c gcc)
        find_all_libraries(LAPACK_LIBRARIES REFLAPACK_LIBS_REQUIRED "" "")
        if(LAPACK_LIBRARIES)
          set_config_option(HAVE_BLAS "Blas[ref]")
          set_config_option(HAVE_LAPACK "Lapack[ref]")
        endif()
      endif()
    elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
      # on Linux try to find the Intel MKL without a Fortran compiler
      if(HAVE_64BIT_SIZE_T)
        set(MKL_PATH lib/em64t)
      else()
        set(MKL_PATH lib/32)
      endif()
      set(MKL_LIBS_REQUIRED mkl_gf_lp64 iomp5 mkl_gnu_thread mkl_core guide pthread)
      find_all_libraries(LAPACK_LIBRARIES MKL_LIBS_REQUIRED "" ${MKL_PATH})
      if(NOT LAPACK_LIBRARIES)
        # match lapack 9.0 on 64bit
        set(MKL_LIBS_REQUIRED mkl_lapack mkl_em64t guide)
        find_all_libraries(LAPACK_LIBRARIES MKL_LIBS_REQUIRED "" ${MKL_PATH})
      endif()
      if(LAPACK_LIBRARIES)
        set_config_option(HAVE_BLAS "Blas[mkl]")
        set_config_option(HAVE_LAPACK "Lapack[mkl]")
      else()
        # on Linux also try to find ATLAS without a Fortran compiler, because
        # cmake ships with a buggy FindBLAS e.g. on Ubuntu Lucid Lynx
        set(ATLAS_LIBS_REQUIRED lapack f77blas cblas atlas)
        find_all_libraries(LAPACK_LIBRARIES ATLAS_LIBS_REQUIRED "" "")
        if(LAPACK_LIBRARIES)
          set_config_option(HAVE_BLAS "Blas[atlas]")
          set_config_option(HAVE_LAPACK "Lapack[atlas]")
        else()
          # try with generic names
          set(GENERIC_LIBS_REQUIRED lapack blas pthread)
          find_all_libraries(LAPACK_LIBRARIES GENERIC_LIBS_REQUIRED "" "")
          if(LAPACK_LIBRARIES)
            set_config_option(HAVE_BLAS "Blas[generic]")
            set_config_option(HAVE_LAPACK "Lapack[generic]")
            find_library(GFORTRAN_LIB gfortran)
            if(GFORTRAN_LIB)
              list(APPEND LAPACK_LIBRARIES ${GFORTRAN_LIB})
            endif()
          endif()
        endif()
      endif()
    elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
      # on SunOS we know blas and lapack are available in sunperf
      set(LAPACK_LIBRARIES -library=sunperf)
      set_config_option(HAVE_BLAS "Blas[sunperf]")
      set_config_option(HAVE_LAPACK "Lapack[sunperf]")
    elseif(APPLE)
      # on Mac we also know that blas and lapack are available
      set(LAPACK_LIBRARIES "-llapack -lblas")
      set_config_option(HAVE_BLAS "Blas[veclib]")
      set_config_option(HAVE_LAPACK "Lapack[veclib]")
    endif()

    if(NOT HAVE_BLAS OR NOT HAVE_LAPACK)
      # if we haven't found blas and lapack check for OpenBlas
      set(OPENBLAS_LIBS_REQUIRED openblas)
      find_all_libraries(LAPACK_LIBRARIES OPENBLAS_LIBS_REQUIRED "" "")
      if(LAPACK_LIBRARIES)
        set_config_option(HAVE_BLAS "Blas[openblas]")
        set_config_option(HAVE_LAPACK "Lapack[openblas]")
        find_library(GFORTRAN_LIB gfortran)
        if(GFORTRAN_LIB)
          list(APPEND LAPACK_LIBRARIES ${GFORTRAN_LIB})
        endif()
      endif()
    endif()

    if(NOT HAVE_BLAS OR NOT HAVE_LAPACK)
      # if we still haven't found blas and lapack, use the standard cmake tests,
      # which require a working Fortran compiler
      enable_language(Fortran)
      find_package(BLAS)
      if(BLAS_FOUND)
        set_config_option(HAVE_BLAS "Blas")
        find_package(LAPACK)
        if(LAPACK_FOUND)
          set_config_option(HAVE_LAPACK "Lapack")
        else()
          set(LAPACK_LIBRARIES ${BLAS_LIBRARIES})
        endif()
        if(CMAKE_Fortran_COMPILER_ID MATCHES "GNU")
          if(CMAKE_Fortran_COMPILER MATCHES "gfortran")
            list(APPEND LAPACK_LIBRARIES gfortran)
          elseif(CMAKE_Fortran_COMPILER MATCHES "f95")
            list(APPEND LAPACK_LIBRARIES gfortran)
          elseif(CMAKE_Fortran_COMPILER MATCHES "g77")
            list(APPEND LAPACK_LIBRARIES g2c)
          endif()
        elseif(CMAKE_Fortran_COMPILER MATCHES "pgi")
          list(APPEND LAPACK_LIBRARIES -pgf77libs)
        endif()
      endif()
    endif()
  endif()
endif()

if(ENABLE_TCMALLOC)
  find_library(TCMALLOC tcmalloc)
  if(TCMALLOC)
    set_config_option(HAVE_TCMALLOC "TCMalloc")
    list(APPEND EXTERNAL_LIBRARIES ${TCMALLOC})
  endif()
endif()

add_subdirectory(src/common)
add_subdirectory(src/numeric)
add_subdirectory(src/geo)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/mesh AND ENABLE_MESH)
  add_subdirectory(src/mesh)
  set_config_option(HAVE_MESH "Mesh")
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/solver AND ENABLE_SOLVER)
  add_subdirectory(src/solver)
  set_config_option(HAVE_SOLVER "Solver")
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/post AND ENABLE_POST)
  add_subdirectory(src/post)
  set_config_option(HAVE_POST "Post")
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/plugin AND ENABLE_PLUGINS)
    add_subdirectory(src/plugin)
    set_config_option(HAVE_PLUGINS "Plugins")
  endif()
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/parser AND ENABLE_PARSER)
  add_subdirectory(src/parser)
  set_config_option(HAVE_PARSER "Parser")
endif()

if(ENABLE_VISUDEV)
  set_config_option(HAVE_VISUDEV "VisuDev")
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/fltk AND ENABLE_FLTK)
  # first, try to use fltk-config for fltk >= 1.3 (FindFLTK is buggy on Unix,
  # where e.g. xft and xinerama options are not dealt with)
  find_program(FLTK_CONFIG_SCRIPT fltk-config)
  if(FLTK_CONFIG_SCRIPT)
    execute_process(COMMAND ${FLTK_CONFIG_SCRIPT} --api-version
                    OUTPUT_VARIABLE FLTK_VERSION)
    string(STRIP "${FLTK_VERSION}" FLTK_VERSION)
    if(FLTK_VERSION VERSION_GREATER 1.3)
      add_subdirectory(src/fltk)
      set_config_option(HAVE_FLTK "Fltk")
      message(STATUS "Using fltk-config script for Fltk " ${FLTK_VERSION})
      execute_process(COMMAND ${FLTK_CONFIG_SCRIPT} --use-gl --use-images --includedir
                      OUTPUT_VARIABLE FLTK_INCLUDE_DIR)
      string(STRIP ${FLTK_INCLUDE_DIR} FLTK_INCLUDE_DIR)
      list(APPEND EXTERNAL_INCLUDES ${FLTK_INCLUDE_DIR})
      execute_process(COMMAND ${FLTK_CONFIG_SCRIPT} --use-gl --use-images --ldflags
                      OUTPUT_VARIABLE FLTK_LIBRARIES)
      string(STRIP ${FLTK_LIBRARIES} FLTK_LIBRARIES)
    endif()
  endif()
  # then try the built-in FindFLTK module
  if(NOT HAVE_FLTK)
    set(FLTK_SKIP_FORMS TRUE)
    set(FLTK_SKIP_FLUID TRUE)
    find_package(FLTK)
    if(FLTK_FOUND)
      add_subdirectory(src/fltk)
      set_config_option(HAVE_FLTK "Fltk")
      list(APPEND EXTERNAL_INCLUDES ${FLTK_INCLUDE_DIR})
    endif()
  endif()
  # workaround for Fedora/Suse messing up fltk-config (see issue #417)
  if(HAVE_FLTK AND ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string(REGEX MATCH "X11" FLTK_X11 ${FLTK_LIBRARIES})
    if(NOT FLTK_X11)
      find_package(X11)
      if(X11_FOUND)
        list(APPEND EXTERNAL_INCLUDES ${X11_INCLUDE_DIR})
        list(APPEND EXTERNAL_LIBRARIES ${X11_LIBRARIES})
      endif()
    endif()
  endif()
endif()

if(APPLE AND HAVE_FLTK AND ENABLE_TOUCHBAR)
  STRING(REGEX MATCH "([0-9]+.[0-9]+)" OSX_SDK_VERSION "${CMAKE_OSX_SYSROOT}")
  if(OSX_SDK_VERSION)
    if(${OSX_SDK_VERSION} VERSION_GREATER 10.11)
      set(GMSH_SRC ${GMSH_SRC};src/fltk/touchBar.mm)
      set_config_option(HAVE_TOUCHBAR "TouchBar")
    endif()
  endif()
endif()

if(ENABLE_ONELAB)
  set_config_option(HAVE_ONELAB "ONELAB")
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/onelab)
    if(ENABLE_ONELAB_METAMODEL)
      add_subdirectory(contrib/onelab)
      include_directories(contrib/onelab)
      set_config_option(HAVE_ONELAB_METAMODEL "ONELABMetamodel")
    endif()
    file(COPY ${ONELAB_PY} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  endif()
endif()

if(ENABLE_BUILD_IOS)
  find_file(CMAKE_TOOLCHAIN_FILE "ios.cmake")
  if(NOT CMAKE_TOOLCHAIN_FILE)
    message(FATAL_ERROR "Cannot compile Gmsh for iOS without a toolchain")
  endif()
  add_definitions(-DBUILD_IOS)
endif()

if(HAVE_FLTK OR ENABLE_GRAPHICS)
  if(NOT HAVE_POST OR NOT HAVE_PLUGINS OR NOT HAVE_ONELAB)
    message(SEND_ERROR "Cannot compile GUI without Post, Plugin and ONELAB")
  endif()

  find_package(JPEG)
  if(JPEG_FOUND)
    set_config_option(HAVE_LIBJPEG "Jpeg")
    list(APPEND EXTERNAL_LIBRARIES ${JPEG_LIBRARIES})
    list(APPEND EXTERNAL_INCLUDES ${JPEG_INCLUDE_DIR})
  endif()

  find_package(ZLIB)
  if(ZLIB_FOUND)
    set_config_option(HAVE_LIBZ "Zlib")
    list(APPEND EXTERNAL_LIBRARIES ${ZLIB_LIBRARIES})
    list(APPEND EXTERNAL_INCLUDES ${ZLIB_INCLUDE_DIR})
  endif()

  if(HAVE_LIBZ)
    find_package(PNG)
    if(PNG_FOUND)
      set_config_option(HAVE_LIBPNG "Png")
      list(APPEND EXTERNAL_LIBRARIES ${PNG_LIBRARIES})
      list(APPEND EXTERNAL_INCLUDES ${PNG_INCLUDE_DIR})
    endif()
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/mpeg_encode AND
     ENABLE_MPEG_ENCODE)
    add_subdirectory(contrib/mpeg_encode)
    include_directories(contrib/mpeg_encode/headers)
    set_config_option(HAVE_MPEG_ENCODE "Mpeg")
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/3M AND ENABLE_3M)
    add_subdirectory(contrib/3M)
    include_directories(contrib/3M)
    set_config_option(HAVE_3M "3M")
  endif()

  if(ENABLE_OSMESA)
    find_library(OSMESA_LIB OSMesa)
    if(OSMESA_LIB)
      set_config_option(HAVE_OSMESA "OSMesa")
      list(APPEND EXTERNAL_LIBRARIES ${OSMESA_LIB})
    endif()
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics)
    set(OpenGL_GL_PREFERENCE "LEGACY")
    find_package(OpenGL REQUIRED)
    if(OPENGL_GLU_FOUND AND OPENGL_FOUND)
      add_subdirectory(src/graphics)
      set_config_option(HAVE_OPENGL "OpenGL")
    else()
      message(SEND_ERROR "Could not find GLU: disabling OpenGL support")
    endif()
  endif()
endif()

if(ENABLE_ANN)
  find_library(ANN_LIB ANN PATH_SUFFIXES lib)
  find_path(ANN_INC "ANN.h" PATH_SUFFIXES src include ANN)
  if(ENABLE_SYSTEM_CONTRIB AND ANN_LIB AND ANN_INC)
    message(STATUS "Using system version of ANN")
    list(APPEND EXTERNAL_LIBRARIES ${ANN_LIB})
    list(APPEND EXTERNAL_INCLUDES ${ANN_INC})
    set_config_option(HAVE_ANN "ANN")
  elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/ANN)
    add_subdirectory(contrib/ANN)
    include_directories(contrib/ANN/include)
    set_config_option(HAVE_ANN "ANN[contrib]")
  endif()
endif()

if(ENABLE_ALGLIB)
  find_library(ALGLIB_LIB alglib)
  find_path(ALGLIB_INC "stdafx.h" PATH_SUFFIXES libalglib)
  if(ENABLE_SYSTEM_CONTRIB AND ALGLIB_LIB AND ALGLIB_INC)
    list(APPEND EXTERNAL_LIBRARIES ${ALGLIB_LIB})
    list(APPEND EXTERNAL_INCLUDES ${ALGLIB_INC})
    set_config_option(HAVE_ALGLIB "ALGLIB")
  elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/ALGLIB)
    add_subdirectory(contrib/ALGLIB)
    include_directories(contrib/ALGLIB)
    set_config_option(HAVE_ALGLIB "ALGLIB[contrib]")
  endif()
endif()

if(HAVE_FLTK AND ENABLE_CAIRO)
  find_library(CAIRO_LIB cairo)
  find_path(CAIRO_INC "cairo/cairo.h" PATH_SUFFIXES include)
  if(CAIRO_INC AND CAIRO_LIB)
     set_config_option(HAVE_CAIRO "Cairo")
     list(APPEND EXTERNAL_LIBRARIES ${CAIRO_LIB})
     list(APPEND EXTERNAL_INCLUDES ${CAIRO_INC})
  endif()
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/DiscreteIntegration AND
   ENABLE_DINTEGRATION)
  add_subdirectory(contrib/DiscreteIntegration)
  include_directories(contrib/DiscreteIntegration)
  set_config_option(HAVE_DINTEGRATION "DIntegration")
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/kbipack AND ENABLE_KBIPACK)
  set_config_option(HAVE_KBIPACK "Kbipack")
  add_subdirectory(contrib/kbipack)
  include_directories(contrib/kbipack)
  if(ENABLE_GMP)
    find_library(GMP_LIB gmp)
    find_path(GMP_INC "gmp.h" PATH_SUFFIXES src include)
  endif()
  if(GMP_LIB AND GMP_INC)
    set_config_option(HAVE_GMP "GMP")
    list(APPEND EXTERNAL_LIBRARIES ${GMP_LIB})
    list(APPEND EXTERNAL_INCLUDES ${GMP_INC})
  else()
    message(STATUS "GMP not found: Kbipack uses long int")
  endif()
endif()

if(ENABLE_MATHEX)
  find_library(MATHEX_LIB mathex PATH_SUFFIXES lib)
  find_path(MATHEX_INC "mathex.h" PATH_SUFFIXES src include)
  if(ENABLE_SYSTEM_CONTRIB AND MATHEX_LIB AND MATHEX_INC)
    list(APPEND EXTERNAL_LIBRARIES ${MATHEX_LIB})
    list(APPEND EXTERNAL_INCLUDES ${MATHEX_INC})
    set_config_option(HAVE_MATHEX "MathEx")
  elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/MathEx)
    add_subdirectory(contrib/MathEx)
    include_directories(contrib/MathEx)
    set_config_option(HAVE_MATHEX "MathEx[contrib]")
  endif()
endif()

if(ENABLE_TINYXML2)
  find_library(TINYXML2_LIB mathex PATH_SUFFIXES lib)
  find_path(TINYXML2_INC "tinyxml2.h" PATH_SUFFIXES src include)
  if(ENABLE_SYSTEM_CONTRIB AND TINYXML2_LIB AND TINYXML2_INC)
    list(APPEND EXTERNAL_LIBRARIES ${TINYXML2_LIB})
    list(APPEND EXTERNAL_INCLUDES ${TINYXML2_INC})
    set_config_option(HAVE_TINYXML2 "TinyXML2")
  elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/tinyxml2)
    add_subdirectory(contrib/tinyxml2)
    include_directories(contrib/tinyxml2)
    set_config_option(HAVE_TINYXML2 "TinyXML2[contrib]")
  endif()
endif()

if(ENABLE_MPI)
  find_package(MPI)
  if(MPI_FOUND)
    set_config_option(HAVE_MPI "MPI")
    list(APPEND EXTERNAL_INCLUDES ${MPI_CXX_INCLUDE_PATH})
    list(APPEND EXTERNAL_LIBRARIES ${MPI_CXX_LIBRARIES})
    set(CMAKE_C_COMPILER ${MPI_C_COMPILER})
    set(CMAKE_CXX_COMPILER ${MPI_CXX_COMPILER})
    set(CMAKE_Fortran_COMPILER ${MPI_Fortran_COMPILER})
  endif()
endif()


if(ENABLE_MESQUITE)
  find_library(MESQUITE_LIB mesquite)
  find_path(MESQUITE_INC "Mesquite.hpp" PATH_SUFFIXES src include)
  if(MESQUITE_LIB AND MESQUITE_INC)
    set_config_option(HAVE_MESQUITE "Mesquite")
    list(APPEND EXTERNAL_LIBRARIES ${MESQUITE_LIB})
    list(APPEND EXTERNAL_INCLUDES ${MESQUITE_INC})
  endif()
endif()

if(ENABLE_POPPLER)
  find_library(POPPLER_LIB poppler)
  find_library(POPPLER_CPP_LIB poppler-cpp)
  find_path(POPPLER_INC "poppler/cpp/poppler-document.h" PATH_SUFFIXES src include)
  if(POPPLER_LIB AND POPPLER_INC)
    set_config_option(HAVE_POPPLER "Poppler")
    list(APPEND EXTERNAL_LIBRARIES ${POPPLER_LIB})
    list(APPEND EXTERNAL_LIBRARIES ${POPPLER_CPP_LIB})
    list(APPEND EXTERNAL_INCLUDES ${POPPLER_INC})
  endif()
endif()

if(ENABLE_P4EST)
  find_library(P4EST_LIB p4est)
  find_path(P4EST_INC "p4est.h" PATH_SUFFIXES src)
  find_library(SC_LIB sc)
  if(P4EST_LIB AND P4EST_INC AND SC_LIB)
    set_config_option(HAVE_P4EST "P4est")
    list(APPEND EXTERNAL_LIBRARIES ${P4EST_LIB} ${SC_LIB})
    list(APPEND EXTERNAL_INCLUDES ${P4EST_INC})
  endif()
endif()

if(HAVE_MESH OR HAVE_SOLVER)
  if(ENABLE_METIS)
    find_library(METIS_LIB metis PATH_SUFFIXES lib)
    find_path(METIS_INC "metis.h" PATH_SUFFIXES include)
    if(ENABLE_SYSTEM_CONTRIB AND METIS_LIB AND METIS_INC)
      message(STATUS "Using system version of METIS")
      list(APPEND EXTERNAL_LIBRARIES ${METIS_LIB})
      list(APPEND EXTERNAL_INCLUDES ${METIS_INC})
      set_config_option(HAVE_METIS "Metis")
    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/metis)
      add_definitions(-DUSE_GKREGEX)
      add_subdirectory(contrib/metis)
      include_directories(contrib/metis/include contrib/metis/libmetis
                          contrib/metis/GKlib)
      set_config_option(HAVE_METIS "Metis[contrib]")
    endif()
  endif()
endif()

if(HAVE_MESH)
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/mesh/tetgenBR.cxx)
    set_config_option(HAVE_TETGENBR "TetGen/BR")
  endif()

  if(ENABLE_VOROPP)
    find_library(VOROPP_LIB voro++)
    find_path(VOROPP_INC "voro++.hh" PATH_SUFFIXES voro++)
    if(ENABLE_SYSTEM_CONTRIB AND VOROPP_LIB AND VOROPP_INC)
      message(STATUS "Using system version of voro++")
      list(APPEND EXTERNAL_LIBRARIES ${VOROPP_LIB})
      list(APPEND EXTERNAL_INCLUDES ${VOROPP_INC})
      set_config_option(HAVE_VOROPP "Voro++")
    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/voro++)
      add_subdirectory(contrib/voro++)
      include_directories(contrib/voro++/src)
      set_config_option(HAVE_VOROPP "Voro++[contrib]")
    endif()
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/HighOrderMeshOptimizer AND
     EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/MeshOptimizer AND
     EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/MeshQualityOptimizer AND
     ENABLE_OPTHOM)
    add_subdirectory(contrib/HighOrderMeshOptimizer)
    include_directories(contrib/HighOrderMeshOptimizer)
    add_subdirectory(contrib/MeshOptimizer)
    include_directories(contrib/MeshOptimizer)
    include_directories(${CMAKE_CURRENT_BINARY_DIR}/contrib/MeshOptimizer)
    add_subdirectory(contrib/MeshQualityOptimizer)
    include_directories(contrib/MeshQualityOptimizer)
    set_config_option(HAVE_OPTHOM "OptHom")
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/domhex AND ENABLE_DOMHEX)
    add_subdirectory(contrib/domhex)
    include_directories(contrib/domhex)
    set_config_option(HAVE_DOMHEX "DomHex")
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/QuadTri AND ENABLE_QUADTRI)
    add_subdirectory(contrib/QuadTri)
    include_directories(contrib/QuadTri)
    set_config_option(HAVE_QUADTRI "QuadTri")
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/blossom AND ENABLE_BLOSSOM)
    add_subdirectory(contrib/blossom)
    include_directories(contrib/blossom/MATCH contrib/blossom/concorde97
                        contrib/blossom/concorde97/INCLUDE)
    set_config_option(HAVE_BLOSSOM "Blossom")
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/nii2mesh AND ENABLE_NII2MESH)
    add_subdirectory(contrib/nii2mesh)
    include_directories(contrib/nii2mesh)
    set_config_option(HAVE_NII2MESH "Nii2mesh")
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/untangle AND ENABLE_UNTANGLE)
    add_subdirectory(contrib/untangle)
    include_directories(contrib/untangle)
    set_config_option(HAVE_UNTANGLE "Untangle")
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/Netgen AND ENABLE_NETGEN)
    add_subdirectory(contrib/Netgen)
    include_directories(contrib/Netgen contrib/Netgen/libsrc/include
                        contrib/Netgen/nglib)
    set_config_option(HAVE_NETGEN "Netgen")
    add_definitions(-DNO_PARALLEL_THREADS -DNOTCL)
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/bamg AND ENABLE_BAMG)
    add_subdirectory(contrib/bamg)
    include_directories(contrib/bamg contrib/bamg/bamglib)
    set_config_option(HAVE_BAMG "Bamg")
  endif()

  if(ENABLE_MMG)
    find_library(MMG_LIB NAMES Mmg mmg)
    find_path(MMG_INC "libmmg.h" PATH_SUFFIXES mmg)
    if(MMG_LIB AND MMG_INC)
      list(APPEND EXTERNAL_LIBRARIES ${MMG_LIB})
      list(APPEND EXTERNAL_INCLUDES ${MMG_INC})
      set_config_option(HAVE_MMG "Mmg")
    endif()
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/hxt AND ENABLE_HXT)
    add_subdirectory(contrib/hxt)
    include_directories(BEFORE ${HXT_INC_DIRS})
    set_config_option(HAVE_HXT "Hxt")
    # do not use arithmetic contraction in predicates.c
    if(MSVC OR (CMAKE_C_COMPILER_ID STREQUAL "Intel" AND WIN32))
      set_source_files_properties(
          "${CMAKE_CURRENT_SOURCE_DIR}/contrib/hxt/predicates/src/predicates.c"
          PROPERTIES COMPILE_FLAGS "/fp:strict")
    elseif(CMAKE_C_COMPILER_ID STREQUAL "Intel")
      set_source_files_properties(
          "${CMAKE_CURRENT_SOURCE_DIR}/contrib/hxt/predicates/src/predicates.c"
          PROPERTIES COMPILE_FLAGS "-fp-model strict")
    elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
      set_source_files_properties(
          "${CMAKE_CURRENT_SOURCE_DIR}/contrib/hxt/predicates/src/predicates.c"
          PROPERTIES COMPILE_FLAGS  "-fno-unsafe-math-optimizations -ffp-contract=off")
    else()
      message(WARNING "Unknown compiler: make sure compiled functions from "
              "predicates.c do not use extended double precision and follow "
              "the IEEE754 standard. It is crucial for the robustness of "
              "geometric predicates.")
    endif()
    if(MSVC)
      add_definitions(/bigobj)
    endif()
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/QuadMeshingTools
     AND ENABLE_QUADMESHINGTOOLS)
    set_config_option(HAVE_QUADMESHINGTOOLS "QuadMeshingTools")
    add_subdirectory(contrib/QuadMeshingTools)
    include_directories(BEFORE contrib/QuadMeshingTools)
  endif()

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/WinslowUntangler
     AND ENABLE_WINSLOWUNTANGLER)
    set_config_option(HAVE_WINSLOWUNTANGLER "WinslowUntangler")
    add_subdirectory(contrib/WinslowUntangler)
    include_directories(BEFORE contrib/WinslowUntangler)
  endif()
endif()

if(ENABLE_MED OR ENABLE_CGNS)
  find_package(HDF5)
  if(HDF5_FOUND)
    set(HDF5_LIB "${HDF5_C_LIBRARIES}")
    list(APPEND EXTERNAL_INCLUDES ${HDF5_INCLUDE_DIRS})
    if(ENABLE_MED)
      find_library(MED_LIB medC HINTS ENV MED3HOME PATH_SUFFIXES lib)
      find_path(MED_INC "med.h" HINTS ENV MED3HOME PATH_SUFFIXES include)
      if(MED_LIB AND MED_INC)
        set_config_option(HAVE_MED "Med")
        list(APPEND EXTERNAL_LIBRARIES ${MED_LIB})
        list(APPEND EXTERNAL_INCLUDES ${MED_INC})
      endif()
    endif()
    if(ENABLE_CGNS)
      find_library(CGNS_LIB cgns HINTS ENV CGNS_ROOT PATH_SUFFIXES lib)
      find_path(CGNS_INC "cgnslib.h" HINTS ENV CGNS_ROOT PATH_SUFFIXES include)
      if(CGNS_LIB AND CGNS_INC)
        set_config_option(HAVE_LIBCGNS "Cgns")
        list(APPEND EXTERNAL_LIBRARIES ${CGNS_LIB})
        list(APPEND EXTERNAL_INCLUDES ${CGNS_INC})
        if(ENABLE_CGNS_CPEX0045)
          set_config_option(HAVE_LIBCGNS_CPEX0045 "Cgns_CPEX0045")
        endif()
      endif()
    endif()
    if(MED_LIB OR CGNS_LIB)
      list(APPEND EXTERNAL_LIBRARIES ${HDF5_LIB})
      find_library(SZ_LIB NAMES szlib sz)
      if(SZ_LIB)
        list(APPEND EXTERNAL_LIBRARIES ${SZ_LIB})
      endif()
      if(NOT HAVE_LIBZ) # necessary for non-GUI builds
        find_package(ZLIB)
        if(ZLIB_FOUND)
          set_config_option(HAVE_LIBZ "Zlib")
          list(APPEND EXTERNAL_LIBRARIES ${ZLIB_LIBRARIES})
        endif()
      endif()
    endif()
  else()
    message(STATUS "HDF5 not found")
  endif()
endif()

if(HAVE_SOLVER)
  if(ENABLE_GMM)
    find_path(GMM_INC "gmm.h" PATH_SUFFIXES src include include/gmm)
    if(ENABLE_SYSTEM_CONTRIB AND GMM_INC)
      message(STATUS "Using system version of GMM")
      list(APPEND EXTERNAL_INCLUDES ${GMM_INC})
      set_config_option(HAVE_GMM "Gmm")
    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/gmm)
      include_directories(contrib/gmm)
      set_config_option(HAVE_GMM "Gmm[contrib]")
    endif()
  endif()

  if(ENABLE_PETSC)
    if(PETSC_DIR)
      set(ENV_PETSC_DIR ${PETSC_DIR})
    else()
      set(ENV_PETSC_DIR $ENV{PETSC_DIR})
    endif()
    if(PETSC_ARCH)
      set(ENV_PETSC_ARCH ${PETSC_ARCH})
    else()
      set(ENV_PETSC_ARCH $ENV{PETSC_ARCH})
    endif()
    set(PETSC_POSSIBLE_CONF_FILES
        ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/conf/petscvariables
        ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib/petsc-conf/petscvariables
        ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib/petsc/conf/petscvariables)
    foreach(FILE ${PETSC_POSSIBLE_CONF_FILES})
      if(EXISTS ${FILE})
        # old-style PETSc installations (using PETSC_DIR and PETSC_ARCH)
        message(STATUS "Using PETSc dir: ${ENV_PETSC_DIR}")
        message(STATUS "Using PETSc arch: ${ENV_PETSC_ARCH}")
        # find includes by parsing the petscvariables file
        file(STRINGS ${FILE} PETSC_VARIABLES NEWLINE_CONSUME)
      endif()
    endforeach()
    if(PETSC_VARIABLES)
      # try to find PETSC_CC_INCLUDES for PETSc >= 3.4
      string(REGEX MATCH "PETSC_CC_INCLUDES = [^\n\r]*" PETSC_PACKAGES_INCLUDES
             ${PETSC_VARIABLES})
      if(PETSC_PACKAGES_INCLUDES)
        string(REPLACE "PETSC_CC_INCLUDES = " "" PETSC_PACKAGES_INCLUDES
               ${PETSC_PACKAGES_INCLUDES})
      else()
        # try to find PETSC_PACKAGES_INCLUDES in older versions
        list(APPEND EXTERNAL_INCLUDES ${ENV_PETSC_DIR}/include)
        list(APPEND EXTERNAL_INCLUDES ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/include)
        string(REGEX MATCH "PACKAGES_INCLUDES = [^\n\r]*" PETSC_PACKAGES_INCLUDES
               ${PETSC_VARIABLES})
        string(REPLACE "PACKAGES_INCLUDES = " "" PETSC_PACKAGES_INCLUDES
               ${PETSC_PACKAGES_INCLUDES})
      endif()
      if(PETSC_PACKAGES_INCLUDES)
        if(PETSC_PACKAGES_INCLUDES)
          string(REPLACE "-I" "" PETSC_PACKAGES_INCLUDES ${PETSC_PACKAGES_INCLUDES})
          string(REPLACE " " ";" PETSC_PACKAGES_INCLUDES ${PETSC_PACKAGES_INCLUDES})
          foreach(VAR ${PETSC_PACKAGES_INCLUDES})
            # seem to include unexisting directories (/usr/include/lib64)
            # check to avoid warnings
            if(EXISTS ${VAR})
              list(APPEND EXTERNAL_INCLUDES ${VAR})
            endif()
          endforeach()
        endif()
      endif()
      # find libraries (<= 3.0)
      set(PETSC_LIBS_REQUIRED petscksp petscdm petscmat petscvec petsc)
      find_all_libraries(PETSC_LIBS PETSC_LIBS_REQUIRED
                         ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib "")
      # petsc 3.1 creates only one library (libpetsc)
      if(NOT PETSC_LIBS)
        find_library(PETSC_LIBS petsc PATHS ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib
                     NO_DEFAULT_PATH)
      endif()
      if(PETSC_LIBS)
        set_config_option(HAVE_PETSC "PETSc")
        if(NOT HAVE_BLAS)
          set_config_option(HAVE_BLAS "Blas[petsc]")
        endif()
        if(NOT HAVE_LAPACK)
          set_config_option(HAVE_LAPACK "Lapack[petsc]")
        endif()
      endif()
      # find slepc (needs to be linked in before petsc)
      if(ENABLE_SLEPC)
        if(SLEPC_DIR)
          set(ENV_SLEPC_DIR ${SLEPC_DIR})
         else()
          set(ENV_SLEPC_DIR $ENV{SLEPC_DIR})
        endif()
        find_library(SLEPC_LIB slepc PATHS ${ENV_SLEPC_DIR}/${ENV_PETSC_ARCH}/lib
                     NO_DEFAULT_PATH)
        if(SLEPC_LIB)
          find_path(SLEPC_INC "slepc.h" PATHS ${ENV_SLEPC_DIR} PATH_SUFFIXES include
                    ${ENV_PETSC_ARCH}/include include/slepc NO_DEFAULT_PATH)
          if(SLEPC_INC)
            message(STATUS "Using SLEPc dir: ${ENV_SLEPC_DIR}")
            set_config_option(HAVE_SLEPC "SLEPc")
            list(APPEND EXTERNAL_LIBRARIES ${SLEPC_LIB})
            list(APPEND EXTERNAL_INCLUDES ${SLEPC_INC})
            find_path(SLEPC_INC2 "slepcconf.h" PATHS ${ENV_SLEPC_DIR}
                      PATH_SUFFIXES ${ENV_PETSC_ARCH}/include NO_DEFAULT_PATH)
            if(SLEPC_INC2)
              list(APPEND EXTERNAL_INCLUDES ${SLEPC_INC2})
            endif()
          endif()
        endif()
      endif()
      list(APPEND EXTERNAL_LIBRARIES ${PETSC_LIBS})
      # find additional libraries to link with
      string(REGEX MATCH "PACKAGES_LIBS = [^\n\r]*" PLIBS ${PETSC_VARIABLES})
      if(PLIBS)
        string(REPLACE "PACKAGES_LIBS = " "" PLIBS ${PLIBS})
        string(STRIP ${PLIBS} PLIBS)
        list(APPEND EXTERNAL_LIBRARIES "${PLIBS}")
      endif()
      string(REGEX MATCH "PETSC_EXTERNAL_LIB_BASIC = [^\n\r]*" PLIBS_BASIC ${PETSC_VARIABLES})
      if(PLIBS_BASIC)
        string(REPLACE "PETSC_EXTERNAL_LIB_BASIC = " "" PLIBS_BASIC ${PLIBS_BASIC})
        string(STRIP ${PLIBS_BASIC} PLIBS_BASIC)
        separate_arguments(PLIBS_BASIC)
        list(APPEND EXTERNAL_LIBRARIES "${PLIBS_BASIC}")
      endif()
      string(REGEX MATCH "PCC_LINKER_LIBS = [^\n\r]*" LLIBS ${PETSC_VARIABLES})
      if(LLIBS)
        string(REPLACE "PCC_LINKER_LIBS = " "" LLIBS ${LLIBS})
        string(STRIP ${LLIBS} LLIBS)
        list(APPEND EXTERNAL_LIBRARIES "${LLIBS}")
      endif()
    else()
      # new-style PETSc installations (in standard system directories)
      find_library(PETSC_LIBS petsc)
      find_path(PETSC_INC "petsc.h" PATH_SUFFIXES include/petsc)
      if(PETSC_LIBS AND PETSC_INC)
        set_config_option(HAVE_PETSC "PETSc")
        if(ENABLE_SLEPC)
          find_library(SLEPC_LIB slepc)
          find_path(SLEPC_INC "slepc.h" PATH_SUFFIXES include/slepc)
          if(SLEPC_LIB AND SLEPC_INC)
            set_config_option(HAVE_SLEPC "SLEPc")
            list(APPEND EXTERNAL_LIBRARIES ${SLEPC_LIB})
            list(APPEND EXTERNAL_INCLUDES ${SLEPC_INC})
          endif()
        endif()
        list(APPEND EXTERNAL_LIBRARIES ${PETSC_LIBS})
        list(APPEND EXTERNAL_INCLUDES ${PETSC_INC})
      endif()
    endif()
  endif()

  if(ENABLE_MUMPS AND HAVE_BLAS AND HAVE_LAPACK)
    set(MUMPS_LIBS_REQUIRED smumps dmumps cmumps zmumps mumps_common pord)
    if(NOT ENABLE_MPI)
      list(APPEND MUMPS_LIBS_REQUIRED mpiseq)
    endif()
    find_all_libraries(MUMPS_LIBRARIES MUMPS_LIBS_REQUIRED "" "lib")
    find_path(SMUMPS_INC "smumps_c.h" PATH_SUFFIXES src include)
    find_path(DMUMPS_INC "dmumps_c.h" PATH_SUFFIXES src include)
    find_path(CMUMPS_INC "cmumps_c.h" PATH_SUFFIXES src include)
    find_path(ZMUMPS_INC "zmumps_c.h" PATH_SUFFIXES src include)
    if(MUMPS_LIBRARIES AND SMUMPS_INC AND DMUMPS_INC AND CMUMPS_INC AND ZMUMPS_INC)
      set_config_option(HAVE_MUMPS "MUMPS")
      list(APPEND EXTERNAL_LIBRARIES ${MUMPS_LIBRARIES})
      list(APPEND EXTERNAL_INCLUDES ${SMUMPS_INC})
      list(APPEND EXTERNAL_INCLUDES ${DMUMPS_INC})
      list(APPEND EXTERNAL_INCLUDES ${CMUMPS_INC})
      list(APPEND EXTERNAL_INCLUDES ${ZMUMPS_INC})
      find_library(GFORTRAN_LIB gfortran)
      if(GFORTRAN_LIB)
        list(APPEND EXTERNAL_LIBRARIES ${GFORTRAN_LIB})
      endif()
      if(ENABLE_GMM) # use GMM/MUMPS interface
        add_definitions(-DGMM_USES_MUMPS)
      endif()
    endif()
  endif()

  if(ENABLE_GETDP)
    find_library(GETDP_LIB GetDP)
    find_path(GETDP_INC "GetDP.h" PATH_SUFFIXES getdp)
    if(GETDP_LIB AND GETDP_INC)
      set_config_option(HAVE_GETDP "GetDP")
      list(APPEND EXTERNAL_LIBRARIES ${GETDP_LIB})
      list(APPEND EXTERNAL_INCLUDES ${GETDP_INC})
    endif()
  endif()
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/pro AND ENABLE_PRO)
  add_subdirectory(pro)
endif()

if(ENABLE_OCC)
  set(OCC_MINIMAL_VERSION "6.9.1")
  if(WIN32)
    if(HAVE_64BIT_SIZE_T)
      set(OCC_SYS_NAME win64)
    else()
      set(OCC_SYS_NAME win32)
    endif()
  else()
    set(OCC_SYS_NAME ${CMAKE_SYSTEM_NAME})
  endif()
  find_path(OCC_INC "Standard_Version.hxx" HINTS ENV CASROOT PATH_SUFFIXES
            inc include include/oce opencascade include/opencascade
            occt include/occt)
  if(OCC_INC)
    file(STRINGS ${OCC_INC}/Standard_Version.hxx
         OCC_MAJOR REGEX "#define OCC_VERSION_MAJOR.*")
    file(STRINGS ${OCC_INC}/Standard_Version.hxx
         OCC_MINOR REGEX "#define OCC_VERSION_MINOR.*")
    file(STRINGS ${OCC_INC}/Standard_Version.hxx
         OCC_MAINT REGEX "#define OCC_VERSION_MAINTENANCE.*")
    if(OCC_MAJOR AND OCC_MINOR AND OCC_MAINT)
      string(REGEX MATCH "[0-9]+" OCC_MAJOR "${OCC_MAJOR}")
      string(REGEX MATCH "[0-9]+" OCC_MINOR "${OCC_MINOR}")
      string(REGEX MATCH "[0-9]+" OCC_MAINT "${OCC_MAINT}")
      set(OCC_VERSION "${OCC_MAJOR}.${OCC_MINOR}.${OCC_MAINT}")
      message(STATUS "Found OpenCASCADE version ${OCC_VERSION} in ${OCC_INC}")
    endif()
  endif()
  if(OCC_VERSION AND OCC_VERSION VERSION_LESS ${OCC_MINIMAL_VERSION})
    message(WARNING "Gmsh requires OpenCASCADE >= ${OCC_MINIMAL_VERSION}. "
        "Use CMAKE_PREFIX_PATH or the CASROOT environment variable "
        "to explicitly specify the installation path of OpenCASCADE")
  elseif(OCC_INC)
    if(OCC_VERSION AND OCC_VERSION VERSION_GREATER_EQUAL "7.8.0")
      set(OCC_LIBS_REQUIRED
          # subset of DataExchange
          TKDESTEP TKDEIGES TKXSBase
          # ModelingAlgorithms
          TKOffset TKFeat TKFillet TKBool TKMesh TKHLR TKBO TKPrim TKShHealing
          TKTopAlgo TKGeomAlgo
          # ModelingData
          TKBRep TKGeomBase TKG3d TKG2d
          # FoundationClasses
          TKMath TKernel)
    else()
      set(OCC_LIBS_REQUIRED
          # subset of DataExchange
          TKSTEP TKSTEP209 TKSTEPAttr TKSTEPBase TKIGES TKXSBase
          # ModelingAlgorithms
          TKOffset TKFeat TKFillet TKBool TKMesh TKHLR TKBO TKPrim TKShHealing
          TKTopAlgo TKGeomAlgo
          # ModelingData
          TKBRep TKGeomBase TKG3d TKG2d
          # FoundationClasses
          TKMath TKernel)
    endif()
    if(ENABLE_OCC_TBB)
      list(APPEND OCC_LIBS_REQUIRED tbb tbbmalloc)
    endif()
    list(LENGTH OCC_LIBS_REQUIRED NUM_OCC_LIBS_REQUIRED)
    if(OCC_LIBS)
      message(STATUS "OCC libraries specified explicitly: " ${OCC_LIBS})
      list(LENGTH OCC_LIBS_REQUIRED NUM_OCC_LIBS)
    else()
      set(OCC_LIBS)
      foreach(OCC ${OCC_LIBS_REQUIRED})
        find_library(OCC_LIB ${OCC} HINTS ENV CASROOT PATH_SUFFIXES
                     lib ${OCC_SYS_NAME}/vc8/lib  ${OCC_SYS_NAME}/vc9/lib
                         ${OCC_SYS_NAME}/vc10/lib ${OCC_SYS_NAME}/vc11/lib
                         ${OCC_SYS_NAME}/vc12/lib ${OCC_SYS_NAME}/vc14/lib
                         ${OCC_SYS_NAME}/gcc/lib  ${OCC_SYS_NAME}/gcc/bin
                         ${OCC_SYS_NAME}/lib)
        if(OCC_LIB)
          list(APPEND OCC_LIBS ${OCC_LIB})
        else()
          message(STATUS "OCC lib " ${OCC} " not Found")
        endif()
        unset(OCC_LIB CACHE)
      endforeach()
      list(LENGTH OCC_LIBS NUM_OCC_LIBS)
    endif()
  endif()

  # additional OCC libraries to handle reading of STEP/IGES attributes. Oh my...
  if(ENABLE_OCC_CAF)
    find_package(Freetype)
    if(FREETYPE_FOUND)
      if(OCC_VERSION AND OCC_VERSION VERSION_GREATER_EQUAL "7.8.0")
        set(OCC_CAF_LIBS_REQUIRED
            TKXCAF TKLCAF TKVCAF TKCAF TKV3d TKService TKCDF)
      else()
        set(OCC_CAF_LIBS_REQUIRED
            TKXDESTEP TKXDEIGES TKXCAF TKLCAF TKVCAF TKCAF TKV3d TKService TKCDF)
      endif()
      list(LENGTH OCC_CAF_LIBS_REQUIRED NUM_OCC_CAF_LIBS_REQUIRED)
      set(OCC_CAF_LIBS)
      foreach(OCC ${OCC_CAF_LIBS_REQUIRED})
        find_library(OCC_CAF_LIB ${OCC} HINTS ENV CASROOT PATH_SUFFIXES
                     lib ${OCC_SYS_NAME}/vc8/lib  ${OCC_SYS_NAME}/vc9/lib
                         ${OCC_SYS_NAME}/vc10/lib ${OCC_SYS_NAME}/vc11/lib
                         ${OCC_SYS_NAME}/vc12/lib ${OCC_SYS_NAME}/vc14/lib
                         ${OCC_SYS_NAME}/gcc/lib  ${OCC_SYS_NAME}/gcc/bin
                         ${OCC_SYS_NAME}/lib)
        if(OCC_CAF_LIB)
          list(APPEND OCC_CAF_LIBS ${OCC_CAF_LIB})
        else()
          message(STATUS "OCC CAF lib " ${OCC} " not Found")
        endif()
        unset(OCC_CAF_LIB CACHE)
      endforeach()
      list(LENGTH OCC_CAF_LIBS NUM_OCC_CAF_LIBS)
    endif()
  endif()

  if(NUM_OCC_LIBS EQUAL NUM_OCC_LIBS_REQUIRED)
    # append OCC CAF libraries first...
    if(NUM_OCC_CAF_LIBS EQUAL NUM_OCC_CAF_LIBS_REQUIRED)
      set_config_option(HAVE_OCC_CAF "OpenCASCADE-CAF")
      list(APPEND EXTERNAL_LIBRARIES ${OCC_CAF_LIBS} ${FREETYPE_LIBRARIES})
      list(APPEND EXTERNAL_INCLUDES ${FREETYPE_INCLUDE_DIRS})
      if(WIN32)
        list(APPEND EXTERNAL_LIBRARIES "windowscodecs")
        list(APPEND EXTERNAL_LIBRARIES "ole32")
      endif()
    endif()
    # then append OCC libraries
    set_config_option(HAVE_OCC "OpenCASCADE")
    list(APPEND EXTERNAL_LIBRARIES ${OCC_LIBS})
    list(APPEND EXTERNAL_INCLUDES ${OCC_INC})
    if(WIN32 AND NOT MSVC)
      add_definitions(-DOCC_CONVERT_SIGNALS)
    endif()
  endif()
endif()

if(ENABLE_ZIPPER)
  if(ENABLE_BUILD_IOS)
    set_config_option(HAVE_LIBZ "Zlib")
  endif()
  if(NOT HAVE_LIBZ) # necessary for non-GUI builds
    find_package(ZLIB)
    if(ZLIB_FOUND)
      set_config_option(HAVE_LIBZ "Zlib")
      list(APPEND EXTERNAL_LIBRARIES ${ZLIB_LIBRARIES})
      list(APPEND EXTERNAL_INCLUDES ${ZLIB_INCLUDE_DIR})
    endif()
  endif()
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/zipper AND HAVE_LIBZ)
    add_subdirectory(contrib/zipper)
    include_directories(contrib/zipper)
    set_config_option(HAVE_ZIPPER "Zipper")
  endif()
endif()

if(ENABLE_PRIVATE_API AND ENABLE_WRAP_PYTHON)
  find_package(SWIG REQUIRED)
  include(${SWIG_USE_FILE})
  find_package(PythonLibs)
  if(SWIG_FOUND AND PYTHONLIBS_FOUND)
    message(STATUS "Found SWIG version " ${SWIG_VERSION})
    find_package(PythonInterp)
    string(SUBSTRING ${SWIG_VERSION} 0 1 SWIG_MAJOR_VERSION)
    if(SWIG_MAJOR_VERSION EQUAL 1)
      message(WARNING "Python bindings require SWIG >= 2: disabling Python")
    else()
      set_config_option(HAVE_PYTHON "Python")
      mark_as_advanced(CLEAR PYTHON_LIBRARY PYTHON_INCLUDE_DIR)
      if(ENABLE_NUMPY)
        if (NOT NUMPY_INC)
          EXEC_PROGRAM (${PYTHON_EXECUTABLE}
            ARGS "-c \"import numpy; print(numpy.get_include())\""
            OUTPUT_VARIABLE NUMPY_INC
            RETURN_VALUE NUMPY_NOT_FOUND)
        endif()
        if(NUMPY_INC)
          list(APPEND EXTERNAL_INCLUDES ${NUMPY_INC})
          set_config_option(HAVE_NUMPY "Numpy")
        endif()
      endif()
      if(HAVE_PETSC)
        if(ENABLE_PETSC4PY)
          EXECUTE_PROCESS(
            COMMAND ${PYTHON_EXECUTABLE} -c "import petsc4py; print(petsc4py.get_include())"
            OUTPUT_VARIABLE PETSC4PY_INC
            RESULT_VARIABLE PETSC4PY_NOT_FOUND
            ERROR_QUIET
            OUTPUT_STRIP_TRAILING_WHITESPACE)
          if(PETSC4PY_INC)
            list(APPEND EXTERNAL_INCLUDES ${PETSC4PY_INC})
            set_config_option(HAVE_PETSC4PY "PETSc4py")
          endif()
        endif()
      endif()
    endif()
  endif()
endif()

check_symbol_exists(vsnprintf "stdio.h" HAVE_VSNPRINTF)
if(NOT HAVE_VSNPRINTF AND NOT ENABLE_BUILD_IOS AND NOT ENABLE_BUILD_ANDROID)
  set_config_option(HAVE_NO_VSNPRINTF "NoVsnprintf")
endif()

check_include_file(sys/socket.h HAVE_SYS_SOCKET_H)
if(HAVE_SYS_SOCKET_H)
  set(CMAKE_EXTRA_INCLUDE_FILES sys/socket.h)
endif()
check_type_size(socklen_t SOCKLEN_T_SIZE)
set(CMAKE_EXTRA_INCLUDE_FILES)
if(NOT SOCKLEN_T_SIZE AND NOT ENABLE_BUILD_IOS AND NOT ENABLE_BUILD_ANDROID)
  set_config_option(HAVE_NO_SOCKLEN_T "NoSocklenT")
endif()

check_include_file(stdint.h HAVE_STDINT_H)
if(HAVE_STDINT_H)
  set(CMAKE_EXTRA_INCLUDE_FILES stdint.h)
else()
  set_config_option(HAVE_NO_STDINT_H "NoStdintH")
endif()
check_type_size(intptr_t INTPTR_T_SIZE)
set(CMAKE_EXTRA_INCLUDE_FILES)
if(NOT INTPTR_T_SIZE AND NOT ENABLE_BUILD_IOS AND NOT ENABLE_BUILD_ANDROID)
  set_config_option(HAVE_NO_INTPTR_T "NoIntptrT")
endif()

check_include_file(dlfcn.h DLFCN_H)
if(DLFCN_H)
  set_config_option(HAVE_DLOPEN "Dlopen")
  list(APPEND EXTERNAL_LIBRARIES ${CMAKE_DL_LIBS})
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  check_include_file(linux/joystick.h LINUX_JOYSTICK_H)
  if(LINUX_JOYSTICK_H)
    set_config_option(HAVE_LINUX_JOYSTICK "LinuxJoystick")
  endif()
endif()

if(WIN32)
  add_definitions(-D_USE_MATH_DEFINES)
  list(APPEND EXTERNAL_LIBRARIES winmm wsock32 ws2_32 psapi)
endif()

if(MSVC)
  add_definitions(-DNOMINMAX -D_CRT_SECURE_NO_DEPRECATE -D_CRT_SECURE_NO_WARNINGS
                  -D_SCL_SECURE_NO_DEPRECATE)
endif()

# add C functions API
set(GMSH_SRC ${GMSH_SRC};api/gmshc.cpp)

# force full warnings to encourage everybody to write clean(er) code
check_cxx_compiler_flag("-Wall" WALL)
if(WALL AND NOT MSVC)
  file(GLOB_RECURSE WALL_SRC src/common/*.cpp src/fltk/*.cpp FunctionSpace/*.cpp
       src/geo/*.cpp src/graphics/*.cpp src/mesh/*.cpp src/numeric/*.cpp src/parser/*.cpp
       src/plugin/*.cpp src/post/*.cpp src/solver/*.cpp)
  set(WF "-Wall")
  check_cxx_compiler_flag("-Wint-to-void-pointer-cast" WCAST)
  if(WCAST)
    set(WF "${WF} -Wno-int-to-void-pointer-cast")
  endif()
  check_cxx_compiler_flag("-Wdeprecated-declarations" WDEPREC)
  if(WDEPREC)
    # FIXME: remove this when we have fixed the deprecated GLU code for OpenGL3
    set(WF "${WF} -Wno-deprecated-declarations")
  endif()
  check_cxx_compiler_flag("-Wmisleading-indentation" WIND)
  if(WIND)
    set(WF "${WF} -Wno-misleading-indentation")
  endif()
  check_cxx_compiler_flag("-Wno-attributes" WATTR)
  if(WATTR)
    # FIXME: remove this when GCC behaves more intelligently
    set(WF "${WF} -Wno-attributes")
  endif()
  check_cxx_compiler_flag("-Wno-unused-but-set-variable" WUNUSED)
  if(WUNUSED)
    set(WF "${WF} -Wno-unused-but-set-variable")
  endif()
  if(WIN32 OR NOT HAVE_64BIT_SIZE_T)
    # FIXME: remove printf family warnings on 32 bit systems and windows
    check_cxx_compiler_flag("-Wno-format" WFORMAT)
    if(WFORMAT)
      set(WF "${WF} -Wno-format")
    endif()
  endif()
  set_compile_flags(WALL_SRC ${WF})
endif()

# don't issue warnings for contributed libraries and for autogenerated files
check_cxx_compiler_flag("-w" NOWARN)
if(NOWARN)
  file(GLOB_RECURSE NOWARN_SRC contrib/*.cpp contrib/*.cc contrib/*.cxx
       contrib/*.c src/parser/Gmsh.*.cpp)
  set_compile_flags(NOWARN_SRC "-w")
endif()

# fine-tune optimization flags for particular files
check_cxx_compiler_flag("-O0" NOOPT)
if(NOOPT OR ENABLE_BUILD_IOS)
  if(ENABLE_BUILD_IOS)
    # optimized builds on iOS 10 64 bits fail spectacularly
    file(GLOB_RECURSE NOOPT_SRC src/geo/G*.cpp src/mesh/BDS.cpp
         src/parser/Gmsh.tab.cpp contrib/blossom/* contrib/bamg/*
         src/mesh/Background*)
  else()
    # bamg fails even with -O1
    file(GLOB_RECURSE NOOPT_SRC contrib/bamg/*)
  endif()
  set_compile_flags(NOOPT_SRC "-O0")
endif()
if(MSVC OR (CMAKE_C_COMPILER_ID STREQUAL "Intel" AND WIN32))
  set_source_files_properties(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/numeric/robustPredicates.cpp"
    PROPERTIES COMPILE_FLAGS "/fp:strict")
elseif(CMAKE_C_COMPILER_ID STREQUAL "Intel")
  set_source_files_properties(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/numeric/robustPredicates.cpp"
    PROPERTIES COMPILE_FLAGS "-fp-model strict")
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  set_source_files_properties(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/numeric/robustPredicates.cpp"
    PROPERTIES COMPILE_FLAGS "-fno-unsafe-math-optimizations -ffp-contract=off")
else()
  message(WARNING "Unknown compiler: make sure compiled functions from "
          "src/numeric/robustPredicates.cpp do not use extended double precision "
          "and follow the IEEE754 standard. It is crucial for the robustness of "
          "geometric predicates.")
endif()

# enable Revoropt and set compile flags for the corresponding plugin
if(ENABLE_REVOROPT)
  if(HAVE_EIGEN AND HAVE_MESH AND HAVE_PLUGINS AND HAVE_ANN AND HAVE_ALGLIB)
    list(APPEND EXTERNAL_INCLUDES contrib/Revoropt/include)
    set_config_option(HAVE_REVOROPT "Revoropt")
    add_definitions(-DUSE_ANN)
  else()
    message(WARNING "Revoropt requires Eigen, Mesh, Plugins, ANN and ALGLIB")
  endif()
endif()

if(HAVE_MESH AND NOT HAVE_EIGEN AND NOT HAVE_LAPACK)
  message(WARNING "Most meshing algorithms will not be functional without "
          "Eigen or Lapack")
endif()

list(SORT CONFIG_OPTIONS)
set(GMSH_CONFIG_OPTIONS "")
foreach(OPT ${CONFIG_OPTIONS})
  set(GMSH_CONFIG_OPTIONS "${GMSH_CONFIG_OPTIONS} ${OPT}")
endforeach()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/common/GmshConfig.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/src/common/GmshConfig.h)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/common/GmshVersion.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/src/common/GmshVersion.h)

# the texi version file is modified in the source directory (not
# ideal for version.texi, but since git tracks the contents of the file this is
# acceptable as it will only change when the actual version is changed - not for
# each git hash)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc/texinfo/version.texi.in
               ${CMAKE_CURRENT_SOURCE_DIR}/doc/texinfo/version.texi)

if(ENABLE_BUILD_LIB OR ENABLE_BUILD_SHARED OR ENABLE_BUILD_DYNAMIC)
  if (GMSH_RELEASE)
    set(GMSH_PYTHON_VERSION ${GMSH_SHORT_VERSION})
    file(READ ${CMAKE_CURRENT_SOURCE_DIR}/utils/pypi/README.gmsh.rst GMSH_LONG_DESCRIPTION)
  else()
    if ("${GMSH_EXTRA_VERSION}" MATCHES "-nox")
      set(GMSH_PYTHON_VERSION "${GMSH_SHORT_VERSION}.dev1+nox")
      file(READ ${CMAKE_CURRENT_SOURCE_DIR}/utils/pypi/README.gmsh-nox-dev.rst GMSH_LONG_DESCRIPTION)
    else ()
      set(GMSH_PYTHON_VERSION "${GMSH_SHORT_VERSION}.dev1")
      file(READ ${CMAKE_CURRENT_SOURCE_DIR}/utils/pypi/README.gmsh-dev.rst GMSH_LONG_DESCRIPTION)
    endif()
  endif()
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/utils/pypi/METADATA.in ${CMAKE_CURRENT_BINARY_DIR}/METADATA)
endif()

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/version.txt ${GMSH_SHORT_VERSION})

# process cmake environment variables so we can append them to the -I include
# commands. This is not recommended (we should only use the cache variables) but
# it is very convenient: otherwise we have to remember providing the
# -D... options to cmake for each new build.
set(ENV_CMAKE_PREFIX_PATH $ENV{CMAKE_PREFIX_PATH})
set(ENV_CMAKE_INCLUDE_PATH $ENV{CMAKE_INCLUDE_PATH})
if(UNIX)
  if(ENV_CMAKE_PREFIX_PATH)
    string(REPLACE ":" ";" ENV_CMAKE_PREFIX_PATH ${ENV_CMAKE_PREFIX_PATH})
  endif()
  if(ENV_CMAKE_INCLUDE_PATH)
    string(REPLACE ":" ";" ENV_CMAKE_INCLUDE_PATH ${ENV_CMAKE_INCLUDE_PATH})
  endif()
endif()
list(APPEND EXTERNAL_INCLUDES ${CMAKE_INCLUDE_PATH} ${ENV_CMAKE_INCLUDE_PATH})
list(APPEND EXTERNAL_INCLUDES ${CMAKE_PREFIX_PATH} ${ENV_CMAKE_PREFIX_PATH})
foreach(DIR ${CMAKE_PREFIX_PATH} ${ENV_CMAKE_PREFIX_PATH})
  list(APPEND EXTERNAL_INCLUDES ${DIR}/include)
endforeach()

if(EXTERNAL_INCLUDES)
  list(REMOVE_DUPLICATES EXTERNAL_INCLUDES)
endif()

if(HAVE_FLTK)
  set(LINK_LIBRARIES ${FLTK_LIBRARIES} ${EXTERNAL_LIBRARIES}
                     ${OPENGL_LIBRARIES} ${LAPACK_LIBRARIES})
elseif(HAVE_OPENGL)
  set(LINK_LIBRARIES ${EXTERNAL_LIBRARIES} ${OPENGL_LIBRARIES}
                     ${LAPACK_LIBRARIES})
else()
  set(LINK_LIBRARIES ${EXTERNAL_LIBRARIES} ${LAPACK_LIBRARIES})
endif()

# try to use static gfortran on static builds (cannot do this on dynamic builds
# as e.g. Debian compiles libgfortran.a without -fPIC: sigh...)
if(NOT ENABLE_BUILD_DYNAMIC AND NOT ENABLE_BUILD_SHARED)
  find_library(GFORTRAN_STATIC libgfortran.a)
  if(GFORTRAN_STATIC)
    set(CMAKE_Fortran_IMPLICIT_LINK_LIBRARIES)
    message(STATUS "Using static libgfortran")
    foreach(STR ${LINK_LIBRARIES})
      string(REPLACE "-lgfortran" ${GFORTRAN_STATIC} STR2 ${STR})
      list(APPEND LINK_LIBRARIES2 ${STR2})
    endforeach()
    set(LINK_LIBRARIES ${LINK_LIBRARIES2})
  endif()
endif()

# Linux-specific linker options
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  if(HAVE_OCC)
    find_library(RT_LIB rt)
    if(RT_LIB)
      list(APPEND LINK_LIBRARIES ${RT_LIB})
    endif()
  endif()
  if(CMAKE_C_COMPILER_ID MATCHES "GNU" OR CMAKE_C_COMPILER_ID MATCHES "Intel")
    add_definitions(-fPIC)
  endif()
endif()

# we could specify include dirs more selectively, but this is simpler
include_directories(src/common src/fltk src/geo src/graphics src/mesh src/solver
                    src/numeric src/parser src/plugin src/post api
                    ${EXTERNAL_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR}/src/common)

# set this for external codes that might include this CMakeList file
set(GMSH_EXTERNAL_INCLUDE_DIRS ${EXTERNAL_INCLUDES} CACHE
    STRING "External include directories" FORCE)
set(GMSH_EXTERNAL_LIBRARIES ${LINK_LIBRARIES} CACHE
    STRING "External libraries" FORCE)

# group sources for easier navigation in IDEs
foreach(DIR ${GMSH_DIRS})
  string(REGEX REPLACE "\\+" "\\\\+" DIR ${DIR})
  source_group(${DIR} REGULAR_EXPRESSION ${DIR}/.*)
endforeach()

# static library target
if(ENABLE_BUILD_LIB)
  add_library(lib STATIC ${GMSH_SRC})
  set_target_properties(lib PROPERTIES OUTPUT_NAME gmsh)
  if(MSVC)
    set_target_properties(lib PROPERTIES DEBUG_POSTFIX d)
    if(ENABLE_MSVC_STATIC_RUNTIME)
      set_target_properties(lib PROPERTIES LINK_FLAGS_RELEASE "/nodefaultlib:LIBCMT")
    endif()
  endif()
endif()

# shared library target
if(ENABLE_BUILD_SHARED OR ENABLE_BUILD_DYNAMIC)
  add_library(shared SHARED ${GMSH_SRC})
  set_target_properties(shared PROPERTIES OUTPUT_NAME gmsh
     VERSION ${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION}.${GMSH_PATCH_VERSION}
     SOVERSION ${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION})
  if(WIN32)
    set_target_properties(shared PROPERTIES PREFIX "" IMPORT_PREFIX ""
      IMPORT_SUFFIX ".lib" COMPILE_FLAGS "-DGMSH_DLL -DGMSH_DLL_EXPORT")
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    if(NOT ENABLE_PRIVATE_API)
      # hide all symbols by default (if not exporting the private API); symbols to
      # export should be marked with __attribute__ ((visibility("default")))
      set_target_properties(shared PROPERTIES COMPILE_FLAGS "-fvisibility=hidden")
    endif()
    # hide all symbols from static libs linked into the shared Gmsh lib (this is
    # easier than recompiling all the dependencies with -fvisibility=hidden)
    if(CMAKE_SYSTEM_NAME MATCHES "Linux")
      # TODO would be nice to have the equivalent on macOS
      message(STATUS "Excluding symbols from bundled static libraries")
      list(APPEND LINK_LIBRARIES "-Wl,--exclude-libs,ALL")
    endif()
  endif()
  target_link_libraries(shared ${LINK_LIBRARIES})
  # don't define LC_RPATH in dylib for development, to not get endless warnings
  # about code signing
  if(APPLE AND NOT GMSH_RELEASE)
    set_target_properties(shared PROPERTIES INSTALL_RPATH "")
  endif()
  if(MSVC AND ENABLE_MSVC_STATIC_RUNTIME)
    message(STATUS "Note: By enabling ENABLE_MSVC_STATIC_RUNTIME, shared library "
            "won't link. In MSVC change /MT to /MD in the shared project properties")
  endif()
endif()

# binary targets
if(HAVE_FLTK)
  if(ENABLE_BUILD_DYNAMIC)
    add_executable(gmsh WIN32 src/common/Main.cpp)
    target_link_libraries(gmsh shared)
  else()
    add_executable(gmsh WIN32 src/common/Main.cpp ${GMSH_SRC})
  endif()
  # we could add this to create a minimal app bundle even without install
  # if(APPLE AND NOT ENABLE_OS_SPECIFIC_INSTALL)
  #  set_target_properties(gmsh PROPERTIES MACOSX_BUNDLE ON
  #    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/utils/misc/gmsh_dev.plist)
  # endif()
else()
  if(ENABLE_BUILD_DYNAMIC)
    add_executable(gmsh src/common/Main.cpp)
    target_link_libraries(gmsh shared)
  else()
    add_executable(gmsh src/common/Main.cpp ${GMSH_SRC})
  endif()
endif()
target_link_libraries(gmsh ${LINK_LIBRARIES})

# OS specific linker options
if(WIN32 AND NOT MSVC)
  set(FLAGS "-Wl,--stack,16777216 -Wl,--image-base -Wl,0x10000000 -static")
  if(HAVE_FLTK)
    set(APPFLAGS "${FLAGS} -municode -mwindows")
    if(HAVE_64BIT_SIZE_T)
      set(APPFLAGS "${APPFLAGS} \"${CMAKE_CURRENT_SOURCE_DIR}/src/fltk/Win64Icon.res\"")
    else()
      set(APPFLAGS "${APPFLAGS} \"${CMAKE_CURRENT_SOURCE_DIR}/src/fltk/Win32Icon.res\"")
    endif()
  else()
    set(APPFLAGS "${FLAGS} -municode -mconsole")
  endif()
  set_target_properties(gmsh PROPERTIES LINK_FLAGS "${APPFLAGS}")
  if(ENABLE_BUILD_DYNAMIC OR ENABLE_BUILD_SHARED)
    set_target_properties(shared PROPERTIES LINK_FLAGS "${FLAGS}")
  endif()
  # remove -Wl,-Bdynamic flags
  set(CMAKE_EXE_LINK_DYNAMIC_C_FLAGS)
  set(CMAKE_EXE_LINK_DYNAMIC_CXX_FLAGS)
elseif(MSVC)
  set_target_properties(gmsh PROPERTIES LINK_FLAGS "/STACK:16777216 /SAFESEH:NO")
elseif(APPLE)
  # this remove ld warnings with PETSc+MUMPS on recent macOS versions; but
  # breaks exception handling
  # set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-no_compact_unwind")
  # set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-no_compact_unwind")
endif()

# android target
if(ENABLE_BUILD_ANDROID)
  find_file(CMAKE_TOOLCHAIN_FILE "android.toolchain.cmake")
  if(NOT CMAKE_TOOLCHAIN_FILE)
    message(FATAL_ERROR "Cannot compile Gmsh for android without android-cmake")
  endif()
  add_definitions(-D_GLIBCXX_USE_C99_MATH=1)
  set(CMAKE_BUILD_TYPE Release)
  set(LIBRARY_OUTPUT_PATH_ROOT ${CMAKE_CURRENT_BINARY_DIR})
  set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/libs/)
  add_definitions(-DBUILD_ANDROID)
  add_definitions(-DPICOJSON_USE_LOCALE=0)
  add_library(androidGmsh SHARED ${GMSH_SRC})
  set_target_properties(androidGmsh PROPERTIES OUTPUT_NAME gmsh)
  target_link_libraries(androidGmsh ${EXTERNAL_LIBRARIES} ${LAPACK_LIBRARIES})
  add_custom_command(TARGET androidGmsh POST_BUILD COMMAND
                     ${CMAKE_STRIP} ${LIBRARY_OUTPUT_PATH}/libgmsh.so)
endif()

# parser target
find_program(BISON bison)
find_program(FLEX flex)
if(BISON AND FLEX)
  add_custom_target(parser
                    COMMAND ${BISON} -p gmsh_yy --output Gmsh.tab.cpp -d Gmsh.y
                    COMMAND ${FLEX} -P gmsh_yy -o Gmsh.yy.cpp Gmsh.l
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/parser)
endif()

if(UNIX)
  # cannot use cmake's file search functions here (they would only find files
  # existing at configuration time)
  add_custom_target(purge
                    COMMAND rm -f `find . -name *~ -o -name *~~`
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  add_custom_target(etags
                    COMMAND etags `find . -name *.cpp -o -name *.h -o -name *.y`
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR
   CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                  OUTPUT_VARIABLE CXX_COMPILER_VERSION
                  OUTPUT_STRIP_TRAILING_WHITESPACE)
else()
  set(CXX_COMPILER_VERSION "Unknown")
endif()

set(WELCOME_FILE ${CMAKE_CURRENT_SOURCE_DIR}/doc/WELCOME.txt)
set(SDK_FILE ${CMAKE_CURRENT_SOURCE_DIR}/doc/SDK.txt)
set(LICENSE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt)
set(CREDITS_FILE ${CMAKE_CURRENT_SOURCE_DIR}/CREDITS.txt)
set(CHANGELOG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/CHANGELOG.txt)
file(GLOB TUTORIALS_GEO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tutorials/?*.*)
file(GLOB TUTORIALS_CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tutorials/c++/?*.*)
file(GLOB TUTORIALS_C_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tutorials/c/?*.*)
file(GLOB TUTORIALS_PY_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tutorials/python/?*.*)
file(GLOB TUTORIALS_JL_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tutorials/julia/?*.*)
file(GLOB TUTORIALS_F90_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tutorials/fortran/?*.*)
file(GLOB EXAMPLES ${CMAKE_CURRENT_SOURCE_DIR}/examples/*)
foreach(SUBDIR ${EXAMPLES})
  if(IS_DIRECTORY ${SUBDIR})
    list(APPEND EXAMPLES_DIRS ${SUBDIR})
  endif()
endforeach()
set(TEX_DIR ${CMAKE_CURRENT_SOURCE_DIR}/doc/texinfo)
file(GLOB TEX_SRC ${TEX_DIR}/*.texi)
file(GLOB TEX_IMG ${TEX_DIR}/images/*.png)
set(TEX_OBJ ${TEX_DIR}/gmsh.aux ${TEX_DIR}/gmsh.cp ${TEX_DIR}/gmsh.cps
    ${TEX_DIR}/gmsh.fn ${TEX_DIR}/gmsh.html ${TEX_DIR}/gmsh.info ${TEX_DIR}/gmsh.ky
    ${TEX_DIR}/gmsh.log ${TEX_DIR}/gmsh.pdf ${TEX_DIR}/gmsh.pg ${TEX_DIR}/gmsh.toc
    ${TEX_DIR}/gmsh.tp ${TEX_DIR}/gmsh.tps ${TEX_DIR}/gmsh.txt ${TEX_DIR}/gmsh.vr)

macro(unix2dos VARNAME UNIQUEPATH)
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/unix2dos/${UNIQUEPATH})
  set(UNIX2DOS_FILES)
  foreach(FILE ${${VARNAME}})
    file(READ ${FILE} F0)
    get_filename_component(N ${FILE} NAME)
    if(CYGWIN)
      string(REGEX REPLACE "\n" "\r\n" F1 "${F0}")
      file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/unix2dos/${UNIQUEPATH}/${N} "${F1}")
    else() # if not in Cygwin, cmake adds '\r's automatically
      file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/unix2dos/${UNIQUEPATH}/${N} "${F0}")
    endif()
    list(APPEND UNIX2DOS_FILES ${CMAKE_CURRENT_BINARY_DIR}/unix2dos/${UNIQUEPATH}/${N})
  endforeach()
  set(${VARNAME} ${UNIX2DOS_FILES})
endmacro()

if(WIN32)
  if(ENABLE_OS_SPECIFIC_INSTALL)
    set(GMSH_BIN .)
    set(GMSH_LIB .)
    set(GMSH_DOC .)
    set(GMSH_MAN .)
    set(GMSH_INC .)
  else()
    include(GNUInstallDirs)
    set(GMSH_BIN ${CMAKE_INSTALL_BINDIR})
    set(GMSH_LIB ${CMAKE_INSTALL_LIBDIR})
    set(GMSH_DOC ${CMAKE_INSTALL_DOCDIR})
    set(GMSH_MAN ${CMAKE_INSTALL_MANDIR}/man1)
    set(GMSH_INC ${CMAKE_INSTALL_INCLUDEDIR})
  endif()
  if(CYGWIN)
    unix2dos(GMSH_API "api")
    if(ENABLE_PRIVATE_API)
      unix2dos(GMSH_PRIVATE_API "private_api")
    endif()
    unix2dos(WELCOME_FILE "welcome")
    unix2dos(SDK_FILE "sdk")
    unix2dos(LICENSE_FILE "license")
    unix2dos(CREDITS_FILE "credits")
    unix2dos(CHANGELOG_FILE "changelog")
    unix2dos(TUTORIALS_GEO_FILES "geo")
    unix2dos(TUTORIALS_CPP_FILES "cpp")
    unix2dos(TUTORIALS_C_FILES "c")
    unix2dos(TUTORIALS_PY_FILES "python")
    unix2dos(TUTORIALS_JL_FILES "julia")
    unix2dos(TUTORIALS_F90_FILES "fortran")
    foreach(DIR ${EXAMPLES_DIRS})
      file(GLOB EXAMPLES_FILES ${DIR}/?*.*)
      unix2dos(EXAMPLES_FILES "examples")
    endforeach()
  endif()
elseif(APPLE AND ENABLE_OS_SPECIFIC_INSTALL)
  # set these so that the files get installed nicely in the macOS .app bundle
  set(GMSH_BIN ../MacOS)
  set(GMSH_LIB ../MacOS)
  set(GMSH_DOC ../../..)
  set(GMSH_MAN ../../..)
  set(GMSH_INC ../MacOS)
else()
  include(GNUInstallDirs)
  set(GMSH_BIN ${CMAKE_INSTALL_BINDIR})
  set(GMSH_LIB ${CMAKE_INSTALL_LIBDIR})
  set(GMSH_DOC ${CMAKE_INSTALL_DOCDIR})
  set(GMSH_MAN ${CMAKE_INSTALL_MANDIR}/man1)
  set(GMSH_INC ${CMAKE_INSTALL_INCLUDEDIR})
endif()

# mark targets as optional so we can install them separately if needed
# (e.g. "make lib" or "make shared" followed by "make install/fast")
install(TARGETS gmsh DESTINATION ${GMSH_BIN} OPTIONAL)
if(ENABLE_BUILD_LIB)
  install(TARGETS lib DESTINATION ${GMSH_LIB} OPTIONAL)
endif()
if(ENABLE_BUILD_SHARED OR ENABLE_BUILD_DYNAMIC)
  install(TARGETS shared DESTINATION ${GMSH_LIB} OPTIONAL)
endif()

if(ENABLE_ONELAB AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/onelab)
  install(FILES ${ONELAB_PY} DESTINATION ${GMSH_BIN})
endif()
if(ENABLE_BUILD_LIB OR ENABLE_BUILD_SHARED OR ENABLE_BUILD_DYNAMIC)
  install(FILES ${GMSH_API} DESTINATION ${GMSH_INC})
  install(FILES ${GMSH_PY} DESTINATION ${GMSH_LIB})
  install(FILES ${GMSH_JL} DESTINATION ${GMSH_LIB})
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/METADATA DESTINATION
                ${GMSH_LIB}/gmsh-${GMSH_PYTHON_VERSION}.dist-info)
  if(ENABLE_PRIVATE_API)
    install(FILES ${GMSH_PRIVATE_API} DESTINATION ${GMSH_INC}/gmsh)
    if(HAVE_CONTRIB_EIGEN) # the private API depends on Eigen
      install(DIRECTORY contrib/eigen/Eigen DESTINATION ${GMSH_INC}/gmsh)
    endif()
  endif()
endif()
if(INSTALL_SDK_README)
  configure_file(${SDK_FILE} ${CMAKE_CURRENT_BINARY_DIR}/README.txt)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/README.txt DESTINATION .)
endif()
install(FILES ${WELCOME_FILE} DESTINATION ${GMSH_DOC} RENAME README.txt)
install(FILES ${LICENSE_FILE} DESTINATION ${GMSH_DOC})
install(FILES ${CREDITS_FILE} DESTINATION ${GMSH_DOC})
install(FILES ${CHANGELOG_FILE} DESTINATION ${GMSH_DOC})
install(FILES ${TUTORIALS_GEO_FILES} DESTINATION ${GMSH_DOC}/tutorials)
install(FILES ${TUTORIALS_CPP_FILES} DESTINATION ${GMSH_DOC}/tutorials/c++)
install(FILES ${TUTORIALS_C_FILES} DESTINATION ${GMSH_DOC}/tutorials/c)
install(FILES ${TUTORIALS_PY_FILES} DESTINATION ${GMSH_DOC}/tutorials/python)
install(FILES ${TUTORIALS_JL_FILES} DESTINATION ${GMSH_DOC}/tutorials/julia)
install(FILES ${TUTORIALS_F90_FILES} DESTINATION ${GMSH_DOC}/tutorials/fortran)
foreach(DIR ${EXAMPLES_DIRS})
  get_filename_component(EXAMPLES_DIR_NAME ${DIR} NAME)
  file(GLOB EXAMPLES_FILES ${DIR}/?*.*)
  install(FILES ${EXAMPLES_FILES} DESTINATION ${GMSH_DOC}/examples/${EXAMPLES_DIR_NAME})
endforeach()
if(UNIX AND NOT CYGWIN)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/gmsh.1 DESTINATION ${GMSH_MAN})
endif()

add_custom_target(get_headers
  COMMAND ${CMAKE_COMMAND} -E make_directory Headers/gmsh
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
foreach(FILE ${GMSH_API})
  add_custom_command(TARGET get_headers POST_BUILD COMMAND ${CMAKE_COMMAND}
    -E copy_if_different ${FILE} ${CMAKE_CURRENT_BINARY_DIR}/Headers/
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endforeach()
if(ENABLE_PRIVATE_API)
  foreach(FILE ${GMSH_PRIVATE_API})
    add_custom_command(TARGET get_headers POST_BUILD COMMAND ${CMAKE_COMMAND}
      -E copy_if_different ${FILE} ${CMAKE_CURRENT_BINARY_DIR}/Headers/gmsh/
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  endforeach()
  if(HAVE_CONTRIB_EIGEN) # the private API depends on Eigen
    add_custom_command(TARGET get_headers POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory contrib/eigen/Eigen
        ${CMAKE_CURRENT_BINARY_DIR}/Headers/gmsh/Eigen
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  endif()
endif()

find_program(MAKEINFO makeinfo)
if(MAKEINFO)
  add_custom_command(OUTPUT ${TEX_DIR}/gmsh.info DEPENDS ${TEX_SRC}
                     COMMAND ${MAKEINFO} --split-size 1000000
                     ARGS ${TEX_DIR}/gmsh.texi WORKING_DIRECTORY ${TEX_DIR})
  add_custom_target(info DEPENDS ${TEX_DIR}/gmsh.info)
  add_custom_command(OUTPUT ${TEX_DIR}/gmsh.txt DEPENDS ${TEX_SRC}
                     COMMAND ${MAKEINFO} --plaintext -o gmsh.txt
                     ARGS ${TEX_DIR}/gmsh.texi WORKING_DIRECTORY ${TEX_DIR})
  add_custom_target(txt DEPENDS ${TEX_DIR}/gmsh.txt)
  add_custom_command(OUTPUT ${TEX_DIR}/gmsh.html DEPENDS ${TEX_SRC}
    COMMAND ${MAKEINFO} --html --css-ref=/gmsh.css --no-split
    --set-customization-variable EXTRA_HEAD='<meta name="viewport" content="width=device-width,initial-scale=1.0"><style type="text/css"><!-- img {  width:66%\; max-width:768px } --></style>'
    ARGS ${TEX_DIR}/gmsh.texi WORKING_DIRECTORY ${TEX_DIR})
  add_custom_target(html DEPENDS ${TEX_DIR}/gmsh.html)
  install(FILES ${TEX_DIR}/gmsh.html DESTINATION ${GMSH_DOC} OPTIONAL)
  install(FILES ${TEX_IMG} DESTINATION ${GMSH_DOC}/images OPTIONAL)
else()
  add_custom_target(html COMMAND ${CMAKE_COMMAND} -E touch ${TEX_DIR}/gmsh.html)
endif()

find_program(TEXI2PDF texi2pdf)
if(TEXI2PDF)
  add_custom_command(OUTPUT ${TEX_DIR}/gmsh.pdf DEPENDS ${TEX_SRC}
                     COMMAND ${TEXI2PDF} ARGS gmsh.texi
                     WORKING_DIRECTORY ${TEX_DIR})
  add_custom_target(pdf DEPENDS ${TEX_DIR}/gmsh.pdf)
  install(FILES ${TEX_DIR}/gmsh.pdf DESTINATION ${GMSH_DOC} OPTIONAL)
endif()

execute_process(COMMAND ${CMAKE_COMMAND} -E echo
  "@c This file was generated by cmake: do not edit manually!\n${OPT_TEXI}"
  OUTPUT_FILE cmake_options.texi)

if(MAKEINFO AND TEXI2PDF)
  add_custom_target(doc COMMAND ${CMAKE_COMMAND} -E tar zcf
                    ${CMAKE_CURRENT_BINARY_DIR}/gmsh-${GMSH_VERSION}-doc.tgz
                    CREDITS.txt LICENSE.txt CHANGELOG.txt doc/gmsh.1
                    doc/texinfo/gmsh.html doc/texinfo/images doc/texinfo/gmsh.info
                    doc/texinfo/gmsh.pdf doc/texinfo/gmsh.txt
                    COMMAND ${CMAKE_COMMAND} -E remove ${TEX_OBJ}
                    DEPENDS info txt html pdf
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()

if(MAKEINFO OR TEXI2PDF)
  add_custom_target(clean_doc COMMAND ${CMAKE_COMMAND} -E remove ${TEX_OBJ})
endif()

if(APPLE AND ENABLE_BUILD_LIB)
  file(READ ${CMAKE_CURRENT_SOURCE_DIR}/utils/misc/gmsh_framework.plist F0)
  string(REPLACE GMSH_VERSION "${GMSH_VERSION}" F1 "${F0}")
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/Info_framework.plist "${F1}")
  set(LIBNAME $<TARGET_FILE:lib>)
  add_custom_target(framework DEPENDS lib
    COMMAND ${CMAKE_COMMAND} -E remove_directory gmsh.framework
    COMMAND ${CMAKE_COMMAND} -E make_directory gmsh.framework/Headers
    COMMAND ${CMAKE_COMMAND} -E make_directory gmsh.framework/Resources
    COMMAND ${CMAKE_COMMAND} -E copy ${LIBNAME} gmsh.framework/gmsh
    COMMAND ${CMAKE_COMMAND} -E copy Info_framework.plist
                                     gmsh.framework/Resources/Info.plist
    COMMAND ${CMAKE_COMMAND} -E create_symlink . gmsh.framework/Headers/gmsh
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  foreach(FILE ${GMSH_API})
    add_custom_command(TARGET framework POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        ${FILE} ${CMAKE_CURRENT_BINARY_DIR}/gmsh.framework/Headers/
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  endforeach()
  if(ENABLE_PRIVATE_API)
    foreach(FILE ${GMSH_PRIVATE_API})
      add_custom_command(TARGET framework POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
          ${FILE} ${CMAKE_CURRENT_BINARY_DIR}/gmsh.framework/Headers/
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    endforeach()
    if(HAVE_CONTRIB_EIGEN) # the private API depends on Eigen
      add_custom_command(TARGET framework POST_BUILD COMMAND ${CMAKE_COMMAND}
          -E copy_directory contrib/eigen/Eigen
          ${CMAKE_CURRENT_BINARY_DIR}/gmsh.framework/Headers/Eigen
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    endif()
  endif()
endif()

set(CPACK_PACKAGE_VENDOR "Christophe Geuzaine and Jean-Francois Remacle")
set(CPACK_PACKAGE_VERSION_MAJOR ${GMSH_MAJOR_VERSION})
set(CPACK_PACKAGE_VERSION_MINOR ${GMSH_MINOR_VERSION})
set(CPACK_PACKAGE_VERSION_PATCH ${GMSH_PATCH_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_FILE ${WELCOME_FILE})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "3D finite element mesh generator with built-in CAD engine and post-processor")
if(GMSH_EXTRA_VERSION MATCHES "-git.*") # so that we'll overwrite the archives
  set(CPACK_PACKAGE_FILE_NAME gmsh${GMSH_EXTRA_VERSION_ORIG}-git-${GMSH_OS})
  set(CPACK_SOURCE_PACKAGE_FILE_NAME gmsh${GMSH_EXTRA_VERSION_ORIG}-git-source)
else()
  set(CPACK_PACKAGE_FILE_NAME gmsh-${GMSH_VERSION}-${GMSH_OS})
  set(CPACK_SOURCE_PACKAGE_FILE_NAME gmsh-${GMSH_VERSION}-source)
endif()
set(CPACK_PACKAGE_INSTALL_DIRECTORY "gmsh")
set(CPACK_RESOURCE_FILE_LICENSE ${LICENSE_FILE})
set(CPACK_RESOURCE_FILE_README ${WELCOME_FILE})
set(CPACK_RESOURCE_FILE_WELCOME ${WELCOME_FILE})
set(CPACK_PACKAGE_EXECUTABLE "gmsh")
if(ENABLE_PACKAGE_STRIP)
  set(CPACK_STRIP_FILES TRUE)
else()
  set(CPACK_STRIP_FILES FALSE)
endif()
set(CPACK_SOURCE_GENERATOR TGZ)
set(CPACK_SOURCE_IGNORE_FILES "${CMAKE_CURRENT_BINARY_DIR}" "/CVS/" "/.svn" "/.git"
    "~$" "DS_Store$" "GmshConfig.h$" "GmshVersion.h$" "/benchmarks/" "/tmp/"
    "/bin/" "/lib/" "/nightly/" "GPATH" "GRTAGS" "GSYMS" "GTAGS" "/HTML/"
    "/contrib/3M/" "/contrib/Parasolid/")

if(UNIX)
  # make sure we remove previous installs before doing the next one (on Mac for
  # example "make package; make package_source" would lead to huge file lists
  # getting generated due to the 'Applications' symlink in the bundle)
  set(CPACK_INSTALL_COMMANDS "rm -rf ${CMAKE_CURRENT_BINARY_DIR}/_CPack_Packages")
endif()

if(APPLE AND ENABLE_OS_SPECIFIC_INSTALL AND HAVE_FLTK)
  set(CPACK_GENERATOR Bundle)
  set(CPACK_BUNDLE_NAME Gmsh)
  file(READ ${CMAKE_CURRENT_SOURCE_DIR}/utils/misc/gmsh_app.plist F0)
  string(REPLACE GMSH_VERSION "${GMSH_VERSION}" F1 "${F0}")
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/Info.plist "${F1}")
  set(CPACK_BUNDLE_PLIST ${CMAKE_CURRENT_BINARY_DIR}/Info.plist)
  set(CPACK_BUNDLE_ICON ${CMAKE_CURRENT_SOURCE_DIR}/src/fltk/MacIcons.icns)
  if(PACKAGER STREQUAL "geuzaine")
    # automatic codesigning of the .app
    set(CPACK_BUNDLE_APPLE_CERT_APP "Developer ID Application: Christophe Geuzaine")
    # enable hardened runtime (necessary for notarization and app store)
    set(CPACK_BUNDLE_APPLE_CODESIGN_PARAMETER "--deep --force --options runtime")
  endif()
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/fltk/MacIconsGeo.icns DESTINATION .
          RENAME GmshGeo.icns)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/fltk/MacIconsMsh.icns DESTINATION .
          RENAME GmshMsh.icns)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/fltk/MacIconsSol.icns DESTINATION .
          RENAME GmshSol.icns)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/fltk/MacIconsPos.icns DESTINATION .
          RENAME GmshPos.icns)
  set(CPACK_PACKAGE_ICON ${CMAKE_CURRENT_SOURCE_DIR}/src/fltk/MacIcons.icns)
elseif(WIN32)
  set(CPACK_GENERATOR ZIP)
else()
  set(CPACK_GENERATOR TGZ)
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/utils/wrappers/gmshpy AND
   ENABLE_PRIVATE_API AND ENABLE_WRAP_PYTHON AND HAVE_PYTHON)
  add_subdirectory(utils/wrappers/gmshpy)
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/utils/wrappers/java AND
   ENABLE_PRIVATE_API AND ENABLE_WRAP_JAVA)
  add_subdirectory(utils/wrappers/java)
endif()

include(CPack)

macro(filter_tests IN OUT)
  unset(${OUT})
  foreach(FILE ${IN})
    unset(BAD1)
    unset(BAD2)
    unset(BAD3)
    # OpenCASCADE
    if(NOT HAVE_OCC AND NOT BAD1 AND NOT BAD2 AND NOT BAD3)
      file(STRINGS ${FILE} BAD1 REGEX "^SetFactory.*OpenCASCADE.*")
      file(STRINGS ${FILE} BAD2 REGEX ".*occ\\.synchronize.*")
      file(STRINGS ${FILE} BAD3 REGEX ".*occ::synchronize.*")
    endif()
    # Metis
    if(NOT HAVE_METIS AND NOT BAD1 AND NOT BAD2 AND NOT BAD3)
      file(STRINGS ${FILE} BAD1 REGEX ".*PartitionMesh.*")
      file(STRINGS ${FILE} BAD2 REGEX ".*mesh\\.partition.*")
      file(STRINGS ${FILE} BAD3 REGEX ".*mesh::partition.*")
    endif()
    if(BAD1 OR BAD2 OR BAD3)
      message("Skipping test " ${FILE})
    else()
      list(APPEND ${OUT} ${FILE})
    endif()
  endforeach()
endmacro()

if(ENABLE_TESTS AND NOT DISABLE_GMSH_TESTS)
  # disabling tests is useful when including this CMakeLists in an external project
  include(CTest)
  file(GLOB_RECURSE ALLFILES
       tutorials/*.geo examples/*.geo benchmarks/?d/*.geo benchmarks/extrude/*.geo
       benchmarks/occ/*.geo)
  filter_tests("${ALLFILES}" TESTFILES)
  foreach(TESTFILE ${TESTFILES})
    # use relative path for Cygwin/MinGW (the pure win exe built with the MinGW
    # compilers does not understand a full Cygwin-style path)
    FILE(RELATIVE_PATH TEST ${CMAKE_CURRENT_BINARY_DIR} ${TESTFILE})
    add_test(${TEST} ./gmsh ${TEST} -3 -nopopup -o ./tmp.msh)
  endforeach()
  # test c++ api tutorials with dynamic builds
  if(ENABLE_BUILD_DYNAMIC)
    file(GLOB_RECURSE ALLFILES tutorials/c++/*.cpp tutorials/c/*.c)
    filter_tests("${ALLFILES}" TESTFILES)
    foreach(TESTFILE ${TESTFILES})
      get_filename_component(TEST ${TESTFILE} NAME)
      string(REPLACE "\." "_" TEST ${TEST})
      add_executable(${TEST} WIN32 ${TESTFILE})
      target_link_libraries(${TEST} shared)
      if(WIN32 AND NOT MSVC)
        set(FLAGS "-static")
        if(HAVE_FLTK)
          set(FLAGS "${FLAGS} -mwindows")
        else()
          set(FLAGS "${FLAGS} -mconsole")
        endif()
        set_target_properties(${TEST} PROPERTIES LINK_FLAGS "${FLAGS}")
      endif()
      add_test(${TEST} ${TEST} -nopopup)
    endforeach()
  endif()
  # enable this once we have worked out the path issues on the build machines
  if(0 AND ENABLE_BUILD_DYNAMIC)
    find_package(PythonInterp)
    if(PYTHONINTERP_FOUND)
      file(GLOB_RECURSE ALLFILES tutorials/python/*.py examples/api/*.py)
      filter_tests("${ALLFILES}" TESTFILES)
      foreach(TESTFILE ${TESTFILES})
        get_filename_component(TEST ${TESTFILE} NAME)
        string(REPLACE "\." "_" TEST ${TEST})
        add_test(NAME ${TEST} COMMAND ${PYTHON_EXECUTABLE} ${TESTFILE} -nopopup)
        set_property(TEST ${TEST} APPEND PROPERTY ENVIRONMENT
                     "PYTHONPATH=${CMAKE_SOURCE_DIR}/api")
        set_property(TEST ${TEST} APPEND PROPERTY ENVIRONMENT
                     "LD_LIBRARY_PATH=${CMAKE_CURRENT_BINARY_DIR}")
        endforeach()
    endif()
  endif()
endif()

message(STATUS "")
message(STATUS "Gmsh ${GMSH_VERSION} has been configured for ${GMSH_OS}")
message(STATUS "")
message(STATUS " * Build options:" ${GMSH_CONFIG_OPTIONS})
message(STATUS " * Build type: " ${CMAKE_BUILD_TYPE})
message(STATUS " * C compiler: " ${CMAKE_C_COMPILER})
message(STATUS " * C++ compiler: " ${CMAKE_CXX_COMPILER})
message(STATUS " * Install prefix: " ${CMAKE_INSTALL_PREFIX})
message(STATUS "")

mark_as_advanced(ANN_INC ANN_LIB CAIRO_LIB CAIRO_INC CGNS_INC GMM_INC
                 GMP_INC GMP_LIB MMG_INC MMG_LIB HDF5_LIB
                 MED_LIB OCC_INC SZ_LIB
                 PETSC_LIBS SLEPC_INC SLEPC_INC2 SLEPC_LIB
                 BISON FLEX MAKEINFO TEXI2PDF FLTK_CONFIG_SCRIPT
                 GMSH_EXTERNAL_INCLUDE_DIRS GMSH_EXTERNAL_LIBRARIES)
