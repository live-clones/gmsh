# Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# do not warn about non-definition of WIN32 on cygwin
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

# if CMAKE_BUILD_TYPE is specified use it; otherwise set the default
# build type to "RelWithDebInfo" ("-O2 -g" with gcc) prior to calling
# project()
if(DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose build type")
else(DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose build type")
endif(DEFINED CMAKE_BUILD_TYPE)

project(gmsh CXX C)

# this variable controls the default value of the options which are normally set
# to ON (useful if you want to configure a minimal version of Gmsh: e.g. "cmake
# -DDEFAULT=0 -DENABLE_POST=1 -DENABLE_PARSER=1")
set(DEFAULT ON CACHE INTERNAL "Default value for enabled-by-default options")

macro(opt OPTION HELP VALUE)
  option(ENABLE_${OPTION} ${HELP} ${VALUE})
  set(OPT_TEXI "${OPT_TEXI}\n@item ENABLE_${OPTION}\n${HELP} (default: ${VALUE})")
endmacro(opt)

opt(3M "Enable proprietary 3M extension" OFF)
opt(ACIS "Enable ACIS geometrical models (experimental)" ${DEFAULT})
opt(ANN "Enable ANN (used for fast point search in mesh/post)" ${DEFAULT})
opt(BAMG "Enable Bamg 2D anisotropic mesh generator" ${DEFAULT})
opt(BFGS "Enable BFGS (used by some mesh optimizers)" ${DEFAULT})
opt(BLAS_LAPACK "Enable BLAS/Lapack for linear algebra (required for meshing)" ON)
opt(BLOSSOM "Enable Blossom algorithm (needed for full quad meshing)" ${DEFAULT})
opt(BUILD_LIB "Enable 'lib' target for building static Gmsh library" OFF)
opt(BUILD_SHARED "Enable 'shared' target for building shared Gmsh library" OFF)
opt(BUILD_DYNAMIC "Enable dynamic Gmsh executable (linked with shared lib)" OFF)
opt(BUILD_ANDROID "Enable Android NDK library target (experimental)" OFF)
opt(BUILD_IOS "Enable iOS (ARM) library target (experimental)" OFF)
opt(CGNS "Enable CGNS mesh export (experimental)" OFF)
opt(CAIRO "Enable Cairo to render fonts (experimental)" ${DEFAULT})
opt(CHACO "Enable Chaco mesh partitioner (alternative to Metis)" ${DEFAULT})
opt(COMPRESSED_IO "Enable compressed (gzip) input/output using zlib" OFF)
opt(CXX11 "Compile with -std=c++11" OFF)
opt(DINTEGRATION "Enable discrete integration (needed for levelsets)" ${DEFAULT})
opt(FLTK "Enable FLTK graphical user interface (requires mesh/post)" ${DEFAULT})
opt(FOURIER_MODEL "Enable Fourier geometrical models (experimental)" OFF)
opt(GETDP "Enable GetDP solver (as a directly linked library)" ${DEFAULT})
opt(GMM "Enable GMM linear solvers (simple alternative to PETSc)" ${DEFAULT})
opt(GMP "Enable GMP for Kbipack (advanced)" ON)
opt(GRAPHICS "Enable building graphics lib even without GUI (advanced)" OFF)
opt(KBIPACK "Enable Kbipack (neeeded by homology solver)" ${DEFAULT})
opt(MATHEX "Enable math expression parser (used by plugins and options)" ${DEFAULT})
opt(MED "Enable MED mesh and post file formats" ${DEFAULT})
opt(MESH "Enable mesh module (required by GUI)" ${DEFAULT})
opt(METIS "Enable Metis mesh partitioner" ${DEFAULT})
opt(MMG3D "Enable MMG3D 3D anisotropic mesh refinement" ${DEFAULT})
opt(MPEG_ENCODE "Enable built-in MPEG movie encoder" ${DEFAULT})
opt(MPI "Enable MPI (mostly for parser and solver - mesh generation is sequential)" OFF)
opt(MSVC_STATIC_RUNTIME "Enable static Visual C++ runtime" OFF)
opt(MUMPS "Enable MUMPS sparse direct linear solver" OFF)
opt(NATIVE_FILE_CHOOSER "Enable native file chooser in GUI" ${DEFAULT})
opt(NETGEN "Enable Netgen 3D frontal mesh generator" ${DEFAULT})
opt(NUMPY "Enable conversion between fullMatrix and numpy array (requires SWIG)" OFF)
opt(PETSC4PY "Enable petsc4py wrappers for petsc matrices" ON)
opt(OCC "Enable Open CASCADE geometrical models" ${DEFAULT})
opt(ONELAB "Enable ONELAB solver interface" ${DEFAULT})
opt(ONELAB_METAMODEL "Enable ONELAB metamodels (experimental)" ${DEFAULT})
opt(OPENMP "Enable OpenMP (experimental)" OFF)
opt(OPTHOM "Enable high-order mesh optimization tools" ${DEFAULT})
opt(OS_SPECIFIC_INSTALL "Enable OS-specific (e.g. app bundle) installation" ${DEFAULT})
opt(OSMESA "Enable OSMesa for offscreen rendering (experimental)" OFF)
opt(PARSER "Enable GEO file parser (required for .geo/.pos files)" ${DEFAULT})
opt(PETSC "Enable PETSc linear solvers (required for SLEPc)" ${DEFAULT})
opt(PLUGINS "Enable post-processing plugins" ${DEFAULT})
opt(POST "Enable post-processing module (required by GUI)" ${DEFAULT})
opt(POPPLER "Enable Poppler for displaying PDF documents (experimental)" OFF)
opt(QT "Enable dummy QT graphical interface proof-of-concept (experimental)" OFF)
opt(REVOROPT "Enable Revoropt (used for CVT remeshing)" OFF)
opt(SLEPC "Enable SLEPc eigensolvers (required for conformal compounds)" ${DEFAULT})
opt(SOLVER "Enable built-in finite element solvers (required for compounds)" ${DEFAULT})
opt(TAUCS "Enable Taucs linear solver" ${DEFAULT})
opt(TCMALLOC "Enable libtcmalloc, a fast malloc implementation but that does not release memory" OFF)
opt(TETGEN "Enable Tetgen 3D initial mesh generator" ${DEFAULT})
opt(VORO3D "Enable Voro3D (for hex meshing, experimental)" ${DEFAULT})
opt(WRAP_JAVA "Enable generation of Java wrappers (experimental)" OFF)
opt(WRAP_PYTHON "Enable generation of Python wrappers" OFF)
opt(ZIPPER "Enable Zip file compression/decompression" OFF)

set(GMSH_MAJOR_VERSION 2)
set(GMSH_MINOR_VERSION 16)
set(GMSH_PATCH_VERSION 0)
set(GMSH_EXTRA_VERSION "" CACHE STRING "Gmsh extra version string")

set(GMSH_VERSION "${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION}")
set(GMSH_VERSION "${GMSH_VERSION}.${GMSH_PATCH_VERSION}${GMSH_EXTRA_VERSION}")
set(GMSH_SHORT_LICENSE "GNU General Public License")

set(GMSH_API
  ${CMAKE_CURRENT_BINARY_DIR}/Common/GmshConfig.h
  ${CMAKE_CURRENT_BINARY_DIR}/Common/GmshVersion.h
  Common/Gmsh.h Common/Context.h Common/GmshDefines.h Common/GmshMessage.h
    Common/VertexArray.h Common/Octree.h Common/OctreeInternals.h
    Common/OS.h Common/StringUtils.h Common/OpenFile.h
    Common/onelab.h Common/GmshSocket.h Common/onelabUtils.h Common/Options.h
  Numeric/Numeric.h Numeric/GaussIntegration.h Numeric/polynomialBasis.h
    Numeric/JacobianBasis.h Numeric/bezierBasis.h Numeric/fullMatrix.h
    Numeric/FuncSpaceData.h Numeric/pointsGenerators.h
    Numeric/simpleFunction.h Numeric/cartesian.h Numeric/ElementType.h
    Numeric/BasisFactory.h Numeric/CondNumBasis.h
  Geo/GModel.h Geo/GEntity.h Geo/GPoint.h Geo/GVertex.h Geo/GEdge.h
    Geo/GFace.h Geo/GRegion.h Geo/GEdgeLoop.h Geo/GEdgeCompound.h
    Geo/GFaceCompound.h Geo/GRegionCompound.h Geo/GRbf.h Geo/MVertex.h
    Geo/MVertexBoundaryLayerData.h Geo/MEdge.h
    Geo/MFace.h Geo/MElement.h Geo/MElementOctree.h Geo/MPoint.h Geo/MLine.h
    Geo/MTriangle.h Geo/MQuadrangle.h Geo/MTetrahedron.h Geo/MHexahedron.h
    Geo/MPrism.h Geo/MPyramid.h Geo/MTrihedron.h Geo/MElementCut.h Geo/MElementOctree.h
    Geo/discreteVertex.h Geo/discreteEdge.h Geo/discreteFace.h Geo/discreteRegion.h
    Geo/SPoint2.h Geo/SPoint3.h Geo/SVector3.h Geo/STensor3.h Geo/SBoundingBox3d.h
    Geo/Pair.h Geo/Range.h Geo/SOrientedBoundingBox.h
    Geo/CellComplex.h Geo/ChainComplex.h Geo/Cell.h Geo/Homology.h Geo/Chain.h
    Geo/GenericVertex.h Geo/GenericEdge.h Geo/GenericFace.h Geo/GenericRegion.h
    Geo/partitionEdge.h Geo/CGNSOptions.h Geo/gmshLevelset.h Geo/boundaryLayersData.h
  Mesh/meshGEdge.h Mesh/meshGFace.h Mesh/meshGFaceOptimize.h
    Mesh/meshGFaceElliptic.h Mesh/meshPartition.h Mesh/meshGFaceDelaunayInsertion.h
    Mesh/simple3D.h Mesh/meshPartitionOptions.h Mesh/directions3D.h Mesh/yamakawa.h
    Mesh/Voronoi3D.h Mesh/Levy3D.h Mesh/periodical.h Mesh/meshMetric.h Mesh/ThinLayer.h
  Numeric/mathEvaluator.h
  Solver/dofManager.h Solver/femTerm.h Solver/laplaceTerm.h Solver/elasticityTerm.h
    Solver/crossConfTerm.h Solver/orthogonalTerm.h
    Solver/linearSystem.h Solver/linearSystemGMM.h Solver/linearSystemCSR.h
    Solver/linearSystemFull.h Solver/elasticitySolver.h Solver/sparsityPattern.h
    Solver/groupOfElements.h Solver/linearSystemPETSc.h Solver/linearSystemMUMPS.h
    Solver/thermicSolver.h
  Post/PView.h Post/PViewData.h Plugin/PluginManager.h Post/OctreePost.h
  Post/PViewDataList.h Post/PViewDataGModel.h Post/PViewOptions.h Post/ColorTable.h
   Numeric/nodalBasis.h Post/adaptiveData.h
  Graphics/drawContext.h
  contrib/kbipack/gmp_normal_form.h contrib/kbipack/gmp_matrix.h
    contrib/kbipack/gmp_blas.h contrib/kbipack/mpz.h
  contrib/DiscreteIntegration/Integration3D.h
  contrib/HighOrderMeshOptimizer/OptHOM.h contrib/HighOrderMeshOptimizer/OptHomMesh.h
  contrib/HighOrderMeshOptimizer/OptHomRun.h contrib/HighOrderMeshOptimizer/ParamCoord.h
  contrib/HighOrderMeshOptimizer/OptHomFastCurving.h contrib/HighOrderMeshOptimizer/SuperEl.h
  contrib/HighOrderMeshOptimizer/OptHomIntegralBoundaryDist.h
  contrib/HighOrderMeshOptimizer/CADDistances.h
  contrib/HighOrderMeshOptimizer/OptHomObjContribScaledJac.h
  contrib/HighOrderMeshOptimizer/OptHomObjContribMetricMin.h
  contrib/HighOrderMeshOptimizer/OptHomObjContribCADDist.h
  contrib/MeshOptimizer/MeshOptPatch.h contrib/MeshOptimizer/MeshOpt.h
  contrib/MeshOptimizer/MeshOptCommon.h contrib/MeshOptimizer/MeshOptimizer.h
  contrib/MeshOptimizer/MeshOptObjContribFunc.h contrib/MeshOptimizer/MeshOptObjContrib.h
  contrib/MeshOptimizer/MeshOptObjContribScaledNodeDispSq.h
  contrib/MeshOptimizer/MeshOptObjectiveFunction.h contrib/MeshOptimizer/MeshOptVertexCoord.h
  contrib/MeshQualityOptimizer/MeshQualityObjContribIdealJac.h
  contrib/MeshQualityOptimizer/MeshQualityObjContribInvCond.h
  contrib/MeshQualityOptimizer/MeshQualityOptimizer.h
  contrib/MathEx/mathex.h)

get_property(IAMCHILD DIRECTORY  PROPERTY PARENT_DIRECTORY)
if(IAMCHILD)
  set(GMSH_API ${GMSH_API} PARENT_SCOPE)
endif(IAMCHILD)

execute_process(COMMAND date "+%Y%m%d" OUTPUT_VARIABLE DATE
                OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND hostname OUTPUT_VARIABLE HOSTNAME
                OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND whoami OUTPUT_VARIABLE PACKAGER
                OUTPUT_STRIP_TRAILING_WHITESPACE)

if(NOT DATE)
  set(DATE "unknown")
endif(NOT DATE)
set(GMSH_DATE "${DATE}")

if(NOT HOSTNAME)
  set(HOSTNAME "unknown")
endif(NOT HOSTNAME)
set(GMSH_HOST "${HOSTNAME}")

if(NOT PACKAGER)
  set(PACKAGER "unknown")
endif(NOT PACKAGER)
set(GMSH_PACKAGER "${PACKAGER}")

if(APPLE)
  set(GMSH_OS "MacOSX")
elseif(CYGWIN)
  set(GMSH_OS "Windows")
else(APPLE)
  set(GMSH_OS "${CMAKE_SYSTEM_NAME}")
endif(APPLE)

include(CheckTypeSize)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckCXXCompilerFlag)

if(ENABLE_WRAP_PYTHON AND NOT ENABLE_BUILD_SHARED)
  set(ENABLE_BUILD_DYNAMIC ON)
endif(ENABLE_WRAP_PYTHON AND NOT ENABLE_BUILD_SHARED)

if(MSVC)
  # remove annoying warning about bool/int cast performance
  set(GMSH_CONFIG_PRAGMAS "#pragma warning(disable:4800 4244 4267)")
  if(ENABLE_MSVC_STATIC_RUNTIME)
    foreach(VAR
            CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
            CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
            CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
      if(${VAR} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${VAR} "${${VAR}}")
      endif(${VAR} MATCHES "/MD")
    endforeach(VAR)
  endif(ENABLE_MSVC_STATIC_RUNTIME)
  if(ENABLE_BUILD_DYNAMIC OR ENABLE_BUILD_SHARED)
    # automatically export .def file with all symbols (requires CMake 3.4);
    # depending on the compiling options this might lead to more than 64k export
    # symbols; just trim the .def file to keep the ones you need
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
  endif(ENABLE_BUILD_DYNAMIC OR ENABLE_BUILD_SHARED)
endif(MSVC)

if(ENABLE_OPENMP)
  find_package(OpenMP)
  if(OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  endif(OPENMP_FOUND)
endif(ENABLE_OPENMP)

if(ENABLE_CXX11)
  # in recent cmake versions we could do e.g. set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif(ENABLE_CXX11)

macro(append_gmsh_src DIRNAME FILES)
  foreach(FILE ${FILES})
    list(APPEND LIST ${DIRNAME}/${FILE})
  endforeach(FILE)
  set(GMSH_SRC ${GMSH_SRC};${LIST} PARENT_SCOPE)
  set(GMSH_DIRS ${GMSH_DIRS};${DIRNAME} PARENT_SCOPE)
endmacro(append_gmsh_src)

macro(find_all_libraries VARNAME LISTNAME PATH SUFFIX)
  set(${VARNAME})
  list(LENGTH ${LISTNAME} NUM_LIST)
  foreach(LIB ${${LISTNAME}})
    if("${PATH}" STREQUAL "")
      find_library(FOUND_LIB ${LIB} PATH_SUFFIXES ${SUFFIX})
    else("${PATH}" STREQUAL "")
      find_library(FOUND_LIB ${LIB} PATHS ${PATH} NO_DEFAULT_PATH)
    endif("${PATH}" STREQUAL "")
    if(FOUND_LIB)
      list(APPEND ${VARNAME} ${FOUND_LIB})
    endif(FOUND_LIB)
    unset(FOUND_LIB CACHE)
  endforeach(LIB)
  list(LENGTH ${VARNAME} NUM_FOUND_LIBRARIES)
  if(NUM_FOUND_LIBRARIES LESS NUM_LIST)
    set(${VARNAME})
  endif(NUM_FOUND_LIBRARIES LESS NUM_LIST)
endmacro(find_all_libraries)

macro(set_config_option VARNAME STRING)
  set(${VARNAME} TRUE)
  list(APPEND CONFIG_OPTIONS ${STRING})
  message(STATUS "Found " ${STRING})
endmacro(set_config_option)

macro(set_compile_flags LISTNAME FLAGS)
  foreach(FILE ${${LISTNAME}})
    get_source_file_property(PROP ${FILE} COMPILE_FLAGS)
    if(PROP)
      set_source_files_properties(${FILE} PROPERTIES COMPILE_FLAGS "${PROP} ${FLAGS}")
    else(PROP)
      set_source_files_properties(${FILE} PROPERTIES COMPILE_FLAGS "${FLAGS}")
    endif(PROP)
  endforeach(FILE)
endmacro(set_compile_flags)

# check if the machine is 64 bits (this is more reliable than using
# CMAKE_SIZEOF_VOID_P, which does not seem to work e.g. on some Suse
# machines)
check_type_size("void*" SIZEOF_VOID_P)
if(SIZEOF_VOID_P EQUAL 8)
  set(HAVE_64BIT_SIZE_T TRUE)
endif(SIZEOF_VOID_P EQUAL 8)

if(ENABLE_BLAS_LAPACK)
  if(BLAS_LAPACK_LIBRARIES)
    # use libs as specified in the BLAS_LAPACK_LIBRARIES variable
    set_config_option(HAVE_BLAS "Blas(Custom)")
    set_config_option(HAVE_LAPACK "Lapack(Custom)")
    set(LAPACK_LIBRARIES ${BLAS_LAPACK_LIBRARIES})
  else(BLAS_LAPACK_LIBRARIES)
    if(MSVC)
      # on Windows with Visual C++ try really hard to find blas/lapack *without*
      # requiring a Fortran compiler: 1) try to find the Intel MKL libs using
      # the standard search path; if not found 2) try to get the reference
      # blas/lapack libs (useful for users with no Fortran compiler and no MKL
      # license, who can just download our precompiled "gmsh-dep" package)
      if(HAVE_64BIT_SIZE_T)
        set(MKL_PATH em64t/lib)
        set(MKL_LIBS_REQUIRED libguide40 mkl_intel_lp64 mkl_intel_thread mkl_core)
      else(HAVE_64BIT_SIZE_T)
        set(MKL_PATH ia32/lib)
        set(MKL_LIBS_REQUIRED libguide40 mkl_intel_c mkl_intel_thread mkl_core)
      endif(HAVE_64BIT_SIZE_T)
      find_all_libraries(LAPACK_LIBRARIES MKL_LIBS_REQUIRED "" ${MKL_PATH})
      if(LAPACK_LIBRARIES)
        set_config_option(HAVE_BLAS "Blas(IntelMKL)")
        set_config_option(HAVE_LAPACK "Lapack(IntelMKL)")
      else(LAPACK_LIBRARIES)
        set(REFLAPACK_LIBS_REQUIRED lapack blas g2c gcc)
        find_all_libraries(LAPACK_LIBRARIES REFLAPACK_LIBS_REQUIRED "" "")
        if(LAPACK_LIBRARIES)
          set_config_option(HAVE_BLAS "Blas(Reference)")
          set_config_option(HAVE_LAPACK "Lapack(Reference)")
        endif(LAPACK_LIBRARIES)
      endif(LAPACK_LIBRARIES)
    elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
      # on Linux try to find the Intel MKL without a Fortran compiler
      if(HAVE_64BIT_SIZE_T)
        set(MKL_PATH lib/em64t)
      else(HAVE_64BIT_SIZE_T)
        set(MKL_PATH lib/32)
      endif(HAVE_64BIT_SIZE_T)
      set(MKL_LIBS_REQUIRED mkl_gf_lp64 iomp5 mkl_gnu_thread mkl_core guide pthread)
      find_all_libraries(LAPACK_LIBRARIES MKL_LIBS_REQUIRED "" ${MKL_PATH})
      if(NOT LAPACK_LIBRARIES)
        # match lapack 9.0 on 64bit
        set(MKL_LIBS_REQUIRED mkl_lapack mkl_em64t guide)
        find_all_libraries(LAPACK_LIBRARIES MKL_LIBS_REQUIRED "" ${MKL_PATH})
      endif(NOT LAPACK_LIBRARIES)
      if(LAPACK_LIBRARIES)
        set_config_option(HAVE_BLAS "Blas(IntelMKL)")
        set_config_option(HAVE_LAPACK "Lapack(IntelMKL)")
      else(LAPACK_LIBRARIES)
        # on Linux also try to find ATLAS without a Fortran compiler, because
        # cmake ships with a buggy FindBLAS e.g. on Ubuntu Lucid Lynx
        set(ATLAS_LIBS_REQUIRED lapack f77blas cblas atlas)
        find_all_libraries(LAPACK_LIBRARIES ATLAS_LIBS_REQUIRED "" "")
        if(LAPACK_LIBRARIES)
          set_config_option(HAVE_BLAS "Blas(ATLAS)")
          set_config_option(HAVE_LAPACK "Lapack(ATLAS)")
        else(LAPACK_LIBRARIES)
          # try with generic names
          set(GENERIC_LIBS_REQUIRED lapack blas pthread)
          find_all_libraries(LAPACK_LIBRARIES GENERIC_LIBS_REQUIRED "" "")
          if(LAPACK_LIBRARIES)
            set_config_option(HAVE_BLAS "Blas(Generic)")
            set_config_option(HAVE_LAPACK "Lapack(Generic)")
            find_library(GFORTRAN_LIB gfortran)
            if(GFORTRAN_LIB)
              list(APPEND LAPACK_LIBRARIES ${GFORTRAN_LIB})
            endif(GFORTRAN_LIB)
          endif(LAPACK_LIBRARIES)
        endif(LAPACK_LIBRARIES)
      endif(LAPACK_LIBRARIES)
    elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
      # on SunOS we know blas and lapack are available in sunperf
      set(LAPACK_FLAGS -library=sunperf)
      set_config_option(HAVE_BLAS "Blas(SunPerf)")
      set_config_option(HAVE_LAPACK "Lapack(SunPerf)")
    elseif(APPLE)
      # on Mac we also know that blas and lapack are available
      set(LAPACK_LIBRARIES "-llapack -lblas")
      set_config_option(HAVE_BLAS "Blas(VecLib)")
      set_config_option(HAVE_LAPACK "Lapack(VecLib)")
    endif(MSVC)

    if(ENABLE_BUILD_ANDROID)
      find_library(BLAS_LIB f2cblas PATH_SUFFIXES lib)
      find_library(LAPACK_LIB f2clapack PATH_SUFFIXES lib)
      if(BLAS_LIB)
        list(APPEND EXTERNAL_LIBRARIES ${BLAS_LIB})
        set_config_option(HAVE_BLAS "Blas")
      endif(BLAS_LIB)
      if(LAPACK_LIB)
        list(APPEND EXTERNAL_LIBRARIES ${LAPACK_LIB})
        set_config_option(HAVE_LAPACK "Lapack")
      endif(LAPACK_LIB)
      # for isnan/isinf
      add_definitions(-D_GLIBCXX_USE_C99_MATH=1)
    endif(ENABLE_BUILD_ANDROID)

    if(NOT HAVE_BLAS OR NOT HAVE_LAPACK)
      # if we haven't found blas and lapack check for OpenBlas
      set(OPENBLAS_LIBS_REQUIRED openblas)
      find_all_libraries(LAPACK_LIBRARIES OPENBLAS_LIBS_REQUIRED "" "")
      if(LAPACK_LIBRARIES)
        set_config_option(HAVE_BLAS "Blas(OpenBlas)")
        set_config_option(HAVE_LAPACK "Lapack(OpenBlas)")
        find_library(GFORTRAN_LIB gfortran)
        if(GFORTRAN_LIB)
          list(APPEND LAPACK_LIBRARIES ${GFORTRAN_LIB})
        endif(GFORTRAN_LIB)
      endif(LAPACK_LIBRARIES)
    endif(NOT HAVE_BLAS OR NOT HAVE_LAPACK)

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
        else(LAPACK_FOUND)
          set(LAPACK_LIBRARIES ${BLAS_LIBRARIES})
        endif(LAPACK_FOUND)
        if(CMAKE_Fortran_COMPILER_ID MATCHES "GNU")
          if(CMAKE_Fortran_COMPILER MATCHES "gfortran")
            list(APPEND LAPACK_LIBRARIES gfortran)
          elseif(CMAKE_Fortran_COMPILER MATCHES "f95")
            list(APPEND LAPACK_LIBRARIES gfortran)
          elseif(CMAKE_Fortran_COMPILER MATCHES "g77")
            list(APPEND LAPACK_LIBRARIES g2c)
          endif(CMAKE_Fortran_COMPILER MATCHES "gfortran")
        endif(CMAKE_Fortran_COMPILER_ID MATCHES "GNU")
      endif(BLAS_FOUND)
    endif(NOT HAVE_BLAS OR NOT HAVE_LAPACK)

    if(NOT HAVE_BLAS OR NOT HAVE_LAPACK)
      message(STATUS "Warning: Could not find Blas or Lapack: most meshing algorithms "
              "will not be functional")
    endif(NOT HAVE_BLAS OR NOT HAVE_LAPACK)

  endif(BLAS_LAPACK_LIBRARIES)
endif(ENABLE_BLAS_LAPACK)

if(ENABLE_TCMALLOC)
  find_library(TCMALLOC tcmalloc)
  if(TCMALLOC)
    set_config_option(HAVE_TCMALLOC "TCMalloc")
    list(APPEND EXTERNAL_LIBRARIES ${TCMALLOC})
  endif(TCMALLOC)
endif(ENABLE_TCMALLOC)

add_subdirectory(Common)
add_subdirectory(Numeric)
add_subdirectory(Geo)

if(ENABLE_MESH)
  add_subdirectory(Mesh)
  set_config_option(HAVE_MESH "Mesh")
endif(ENABLE_MESH)

if(ENABLE_SOLVER)
  add_subdirectory(Solver)
  set_config_option(HAVE_SOLVER "Solver")
endif(ENABLE_SOLVER)

if(ENABLE_POST)
  add_subdirectory(Post)
  set_config_option(HAVE_POST "Post")
  if(ENABLE_PLUGINS)
    add_subdirectory(Plugin)
    set_config_option(HAVE_PLUGINS "Plugins")
  endif(ENABLE_PLUGINS)
endif(ENABLE_POST)

if(ENABLE_PARSER)
  add_subdirectory(Parser)
  set_config_option(HAVE_PARSER "Parser")
endif(ENABLE_PARSER)

if(ENABLE_FLTK)
  # first, try to use fltk-config for fltk >= 1.3 (FindFLTK is buggy on Unix,
  # where e.g. xft and xinerama options are not dealt with)
  find_program(FLTK_CONFIG_SCRIPT fltk-config)
  if(FLTK_CONFIG_SCRIPT)
    execute_process(COMMAND ${FLTK_CONFIG_SCRIPT} --api-version
                    OUTPUT_VARIABLE FLTK_VERSION)
    string(STRIP ${FLTK_VERSION} FLTK_VERSION)
    if(FLTK_VERSION GREATER 1.1)
      add_subdirectory(Fltk)
      set_config_option(HAVE_FLTK "Fltk")
      message(STATUS "Using fltk-config script for Fltk " ${FLTK_VERSION})
      execute_process(COMMAND ${FLTK_CONFIG_SCRIPT} --use-gl --use-images --includedir
                      OUTPUT_VARIABLE FLTK_INCLUDE_DIR)
      string(STRIP ${FLTK_INCLUDE_DIR} FLTK_INCLUDE_DIR)
      list(APPEND EXTERNAL_INCLUDES ${FLTK_INCLUDE_DIR})
      # On linux (at least OpenSuSE) the following directories are
      # not existing (everything is in /usr/include). To avoid warnings
      # check existance of these directories before adding them
      if(EXISTS ${FLTK_INCLUDE_DIR}/FL/images)
        list(APPEND EXTERNAL_INCLUDES ${FLTK_INCLUDE_DIR}/FL/images)
      endif(EXISTS ${FLTK_INCLUDE_DIR}/FL/images)
      if(EXISTS ${FLTK_INCLUDE_DIR}/jpeg)
        list(APPEND EXTERNAL_INCLUDES ${FLTK_INCLUDE_DIR}/jpeg)
      endif(EXISTS ${FLTK_INCLUDE_DIR}/jpeg)
      if(EXISTS ${FLTK_INCLUDE_DIR}/zlib)
        list(APPEND EXTERNAL_INCLUDES ${FLTK_INCLUDE_DIR}/zlib)
      endif(EXISTS ${FLTK_INCLUDE_DIR}/zlib)
      if(EXISTS ${FLTK_INCLUDE_DIR}/png)
        list(APPEND EXTERNAL_INCLUDES ${FLTK_INCLUDE_DIR}/png)
      endif(EXISTS ${FLTK_INCLUDE_DIR}/png)
      execute_process(COMMAND ${FLTK_CONFIG_SCRIPT} --use-gl --use-images --ldflags
                      OUTPUT_VARIABLE FLTK_LIBRARIES)
      string(STRIP ${FLTK_LIBRARIES} FLTK_LIBRARIES)
      string(REGEX MATCH "fltk[_ ]jpeg" FLTK_JPEG ${FLTK_LIBRARIES})
      string(REGEX MATCH "fltk[_ ]z" FLTK_Z ${FLTK_LIBRARIES})
      string(REGEX MATCH "fltk[_ ]png" FLTK_PNG ${FLTK_LIBRARIES})
    endif(FLTK_VERSION GREATER 1.1)
  endif(FLTK_CONFIG_SCRIPT)
  # then try the built-in FindFLTK module
  if(NOT HAVE_FLTK)
    set(FLTK_SKIP_FORMS TRUE)
    set(FLTK_SKIP_FLUID TRUE)
    find_package(FLTK)
    if(FLTK_FOUND)
      add_subdirectory(Fltk)
      set_config_option(HAVE_FLTK "Fltk")
      list(APPEND EXTERNAL_INCLUDES ${FLTK_INCLUDE_DIR})
      # find fltk jpeg
      find_library(FLTK_JPEG NAMES fltk_jpeg fltkjpeg)
      if(FLTK_JPEG)
        list(APPEND EXTERNAL_LIBRARIES ${FLTK_JPEG})
        foreach(DIR ${FLTK_INCLUDE_DIR})
          list(APPEND EXTERNAL_INCLUDES ${DIR}/FL/images ${DIR}/jpeg)
        endforeach(DIR)
      endif(FLTK_JPEG)
      # find fltk zlib
      find_library(FLTK_Z NAMES fltk_z fltkz)
      if(FLTK_Z)
        list(APPEND EXTERNAL_LIBRARIES ${FLTK_Z})
        foreach(DIR ${FLTK_INCLUDE_DIR})
          list(APPEND EXTERNAL_INCLUDES ${DIR}/FL/images ${DIR}/zlib)
        endforeach(DIR)
      endif(FLTK_Z)
      # find fltk png
      find_library(FLTK_PNG NAMES fltk_png fltkpng)
      if(FLTK_PNG)
        list(APPEND EXTERNAL_LIBRARIES ${FLTK_PNG})
        foreach(DIR ${FLTK_INCLUDE_DIR})
          list(APPEND EXTERNAL_INCLUDES ${DIR}/FL/images ${DIR}/png)
        endforeach(DIR)
      endif(FLTK_PNG)
    endif(FLTK_FOUND)
  endif(NOT HAVE_FLTK)
elseif(ENABLE_QT)
  find_package(Qt4)
  set(QT_USE_QTOPENGL TRUE)
  include(${QT_USE_FILE})
  if(QT_FOUND)
    add_subdirectory(Qt)
    set_config_option(HAVE_QT "Qt")
    list(APPEND EXTERNAL_INCLUDES ${QT_INCLUDE_DIR})
  endif(QT_FOUND)
endif(ENABLE_FLTK)

if(ENABLE_NATIVE_FILE_CHOOSER)
  set_config_option(HAVE_NATIVE_FILE_CHOOSER "NativeFileChooser")
endif(ENABLE_NATIVE_FILE_CHOOSER)

if(ENABLE_ONELAB)
  set_config_option(HAVE_ONELAB "ONELAB")
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/onelab)
    if(ENABLE_ONELAB_METAMODEL)
      add_subdirectory(contrib/onelab)
      include_directories(contrib/onelab)
      set_config_option(HAVE_ONELAB_METAMODEL "ONELABMetamodel")
    endif(ENABLE_ONELAB_METAMODEL)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/contrib/onelab/python/onelab.py
              DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/onelab)
endif(ENABLE_ONELAB)

if(ENABLE_BUILD_IOS)
  find_file(CMAKE_TOOLCHAIN_FILE "ios.cmake")
  if(NOT CMAKE_TOOLCHAIN_FILE)
    message(FATAL_ERROR "Cannot compile Gmsh for iOS without a toolchain")
  endif(NOT CMAKE_TOOLCHAIN_FILE)
endif(ENABLE_BUILD_IOS)

if(HAVE_FLTK OR HAVE_QT OR ENABLE_GRAPHICS)
  if(NOT HAVE_MESH OR NOT HAVE_POST OR NOT HAVE_PLUGINS OR NOT HAVE_ONELAB)
    message(SEND_ERROR "Cannot compile GUI without Mesh, Post, Plugin and ONELAB")
  endif(NOT HAVE_MESH OR NOT HAVE_POST OR NOT HAVE_PLUGINS OR NOT HAVE_ONELAB)

  if(FLTK_JPEG)
    set_config_option(HAVE_LIBJPEG "Jpeg(Fltk)")
  else(FLTK_JPEG)
    find_package(JPEG)
    if(JPEG_FOUND)
      set_config_option(HAVE_LIBJPEG "Jpeg")
      list(APPEND EXTERNAL_LIBRARIES ${JPEG_LIBRARIES})
      list(APPEND EXTERNAL_INCLUDES ${JPEG_INCLUDE_DIR})
    endif(JPEG_FOUND)
  endif(FLTK_JPEG)

  if(FLTK_Z)
    set_config_option(HAVE_LIBZ "Zlib(Fltk)")
  else(FLTK_Z)
    find_package(ZLIB)
    if(ZLIB_FOUND)
      set_config_option(HAVE_LIBZ "Zlib")
      list(APPEND EXTERNAL_LIBRARIES ${ZLIB_LIBRARIES})
      list(APPEND EXTERNAL_INCLUDES ${ZLIB_INCLUDE_DIR})
    endif(ZLIB_FOUND)
  endif(FLTK_Z)

  if(HAVE_LIBZ)
    if(FLTK_PNG)
      set_config_option(HAVE_LIBPNG "Png(Fltk)")
    else(FLTK_PNG)
      find_package(PNG)
      if(PNG_FOUND)
        set_config_option(HAVE_LIBPNG "Png")
        list(APPEND EXTERNAL_LIBRARIES ${PNG_LIBRARIES})
        list(APPEND EXTERNAL_INCLUDES ${PNG_INCLUDE_DIR})
      endif(PNG_FOUND)
    endif(FLTK_PNG)
  endif(HAVE_LIBZ)

  if(ENABLE_MPEG_ENCODE)
    add_subdirectory(contrib/mpeg_encode)
    include_directories(contrib/mpeg_encode/headers)
    set_config_option(HAVE_MPEG_ENCODE "Mpeg")
  endif(ENABLE_MPEG_ENCODE)

  if(ENABLE_3M AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/3M)
    add_subdirectory(contrib/3M)
    include_directories(contrib/3M)
    set_config_option(HAVE_3M "3M")
  endif(ENABLE_3M AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/3M)

  if(ENABLE_OSMESA)
    find_library(OSMESA_LIB OSMesa)
    if(OSMESA_LIB)
      set_config_option(HAVE_OSMESA "OSMesa")
      list(APPEND EXTERNAL_LIBRARIES ${OSMESA_LIB})
    endif(OSMESA_LIB)
  endif(ENABLE_OSMESA)

  find_package(OpenGL REQUIRED)
  if(OPENGL_GLU_FOUND AND OPENGL_FOUND)
    add_subdirectory(Graphics)
    set_config_option(HAVE_OPENGL "OpenGL")
  else(OPENGL_GLU_FOUND AND  OPENGL_FOUND)
    message(SEND_ERROR "Could not find GLU: disabling OpenGL support")
  endif(OPENGL_GLU_FOUND AND  OPENGL_FOUND)
endif(HAVE_FLTK OR HAVE_QT OR ENABLE_GRAPHICS)

if(HAVE_MESH OR HAVE_PLUGINS)
  if(ENABLE_ANN)
    find_library(ANN_LIB ann PATH_SUFFIXES lib)
    find_path(ANN_INC "ANN.h" PATH_SUFFIXES src include ANN)
    if(ANN_LIB AND ANN_INC)
      list(APPEND EXTERNAL_LIBRARIES ${ANN_LIB})
      list(APPEND EXTERNAL_INCLUDES ${ANN_INC})
    else(ANN_LIB AND ANN_INC)
      message(STATUS "System ANN not found: using contrib/ANN instead")
      add_subdirectory(contrib/ANN)
      include_directories(contrib/ANN/include)
    endif(ANN_LIB AND ANN_INC)
    set_config_option(HAVE_ANN "Ann")
  endif(ENABLE_ANN)
endif(HAVE_MESH OR HAVE_PLUGINS)

if(ENABLE_BFGS)
  add_subdirectory(contrib/lbfgs)
  include_directories(contrib/lbfgs)
  set_config_option(HAVE_BFGS "Bfgs")
endif(ENABLE_BFGS)

if(HAVE_FLTK AND ENABLE_CAIRO)
  find_library(CAIRO_LIB cairo)
  find_path(CAIRO_INC "cairo/cairo.h" PATH_SUFFIXES include)
  if(CAIRO_INC AND CAIRO_LIB)
     set_config_option(HAVE_CAIRO "Cairo")
     list(APPEND EXTERNAL_LIBRARIES ${CAIRO_LIB})
     list(APPEND EXTERNAL_INCLUDES ${CAIRO_INC})
  endif(CAIRO_INC AND CAIRO_LIB)
endif(HAVE_FLTK AND ENABLE_CAIRO)

if(ENABLE_DINTEGRATION)
  add_subdirectory(contrib/DiscreteIntegration)
  include_directories(contrib/DiscreteIntegration)
  set_config_option(HAVE_DINTEGRATION "DIntegration")
endif(ENABLE_DINTEGRATION)

if(ENABLE_OPTHOM)
  add_subdirectory(contrib/HighOrderMeshOptimizer)
  include_directories(contrib/HighOrderMeshOptimizer)
  add_subdirectory(contrib/MeshOptimizer)
  include_directories(contrib/MeshOptimizer)
  include_directories(${CMAKE_CURRENT_BINARY_DIR}/contrib/MeshOptimizer)
  add_subdirectory(contrib/MeshQualityOptimizer)
  include_directories(contrib/MeshQualityOptimizer)
  set_config_option(HAVE_OPTHOM "OptHom")
endif(ENABLE_OPTHOM)

if(ENABLE_KBIPACK)
  set_config_option(HAVE_KBIPACK "Kbipack")
  add_subdirectory(contrib/kbipack)
  include_directories(contrib/kbipack)
  if(ENABLE_GMP)
    find_library(GMP_LIB gmp)
    find_path(GMP_INC "gmp.h" PATH_SUFFIXES src include)
  endif(ENABLE_GMP)
  if(GMP_LIB AND GMP_INC)
    set_config_option(HAVE_GMP "GMP")
    list(APPEND EXTERNAL_LIBRARIES ${GMP_LIB})
    list(APPEND EXTERNAL_INCLUDES ${GMP_INC})
  else(GMP_LIB AND GMP_INC)
    message(STATUS "GMP not found: Kbipack uses long int")
  endif(GMP_LIB AND GMP_INC)
endif(ENABLE_KBIPACK)

if(ENABLE_MATHEX)
  add_subdirectory(contrib/MathEx)
  include_directories(contrib/MathEx)
  set_config_option(HAVE_MATHEX "MathEx")
endif(ENABLE_MATHEX)

if(ENABLE_MPI)
  find_package(MPI)
  if(MPI_FOUND)
    set_config_option(HAVE_MPI "MPI")
    list(APPEND EXTERNAL_INCLUDES ${MPI_INCLUDE_DIR})
    list(APPEND EXTERNAL_LIBRARIES ${MPI_LIBRARIES})
    include(CMakeForceCompiler)
    # Warning: this actually requires cmake >= 2.8.5
    cmake_force_c_compiler(${MPI_C_COMPILER} "MPI C Compiler")
    cmake_force_cxx_compiler(${MPI_CXX_COMPILER} "MPI C++ Compiler")
  endif(MPI_FOUND)
endif(ENABLE_MPI)

if(ENABLE_POPPLER)
  find_library(POPPLER_LIB poppler)
  find_library(POPPLER_CPP_LIB poppler-cpp)
  find_path(POPPLER_INC "poppler/cpp/poppler-document.h" PATH_SUFFIXES src include)
  if(POPPLER_LIB AND POPPLER_INC)
    set_config_option(HAVE_POPPLER "Poppler")
    list(APPEND EXTERNAL_LIBRARIES ${POPPLER_LIB})
    list(APPEND EXTERNAL_LIBRARIES ${POPPLER_CPP_LIB})
    list(APPEND EXTERNAL_INCLUDES ${POPPLER_INC})
  endif(POPPLER_LIB AND POPPLER_INC)
endif(ENABLE_POPPLER)

if(HAVE_MESH OR HAVE_SOLVER)
  if(ENABLE_METIS)
    # Gmsh currently uses Metis 4 - we should switch to Metis 5 and use the
    # system lib if available
    add_subdirectory(contrib/Metis)
    # make sure to include path before any (system) Metis 5 directories
    include_directories(BEFORE contrib/Metis)
    set_config_option(HAVE_METIS "Metis")
    message(STATUS "Note: By including Metis you have to comply with Metis' "
            "special licensing requirements stated in contrib/Metis/README.txt.")
  endif(ENABLE_METIS)

  if(ENABLE_CHACO)
    add_subdirectory(contrib/Chaco)
    include_directories(contrib/Chaco/main)
    set_config_option(HAVE_CHACO "Chaco")
  endif(ENABLE_CHACO)
endif(HAVE_MESH OR HAVE_SOLVER)

if(HAVE_MESH)
  set_config_option(HAVE_TETGENBR "TetGen/BR")

  if(ENABLE_VORO3D)
    add_subdirectory(contrib/voro++)
    include_directories(contrib/voro++/src)
    set_config_option(HAVE_VORO3D "Voro3D")
  endif(ENABLE_VORO3D)

  if(ENABLE_BLOSSOM)
    add_subdirectory(contrib/blossom)
    include_directories(contrib/blossom/MATCH contrib/blossom/concorde97
                        contrib/blossom/concorde97/INCLUDE)
    set_config_option(HAVE_BLOSSOM "Blossom")
  endif(ENABLE_BLOSSOM)

  if(ENABLE_NETGEN)
    add_subdirectory(contrib/Netgen)
    include_directories(contrib/Netgen contrib/Netgen/libsrc/include
                        contrib/Netgen/nglib)
    set_config_option(HAVE_NETGEN "Netgen")
    add_definitions(-DNO_PARALLEL_THREADS -DNOTCL)
  endif(ENABLE_NETGEN)

  if(ENABLE_BAMG)
    add_subdirectory(contrib/bamg)
    include_directories(contrib/bamg contrib/bamg/bamglib)
    set_config_option(HAVE_BAMG "Bamg")
  endif(ENABLE_BAMG)

  if(ENABLE_MMG3D)
    find_library(MMG3D_LIB mmg3dlib4.0 PATH_SUFFIXES lib)
    find_path(MMG3D_INC "libmmg3d.h" PATH_SUFFIXES src include)
    if(MMG3D_LIB AND MMG3D_INC)
       list(APPEND EXTERNAL_LIBRARIES ${MMG3D_LIB})
       list(APPEND EXTERNAL_INCLUDES ${MMG3D_INC})
    else(MMG3D_LIB AND MMG3D_INC)
       message(STATUS "System MMG3D not found: using contrib/mmg3d instead")
       add_subdirectory(contrib/mmg3d)
       include_directories(contrib/mmg3d/build/sources)
    endif(MMG3D_LIB AND MMG3D_INC)
    set_config_option(HAVE_MMG3D "Mmg3d")
  endif(ENABLE_MMG3D)

  if(ENABLE_TETGEN AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/Tetgen1.5/tetgen.h)
    add_subdirectory(contrib/Tetgen1.5)
    include_directories(contrib/Tetgen1.5)
    set_config_option(HAVE_TETGEN "Tetgen1.5")
    add_definitions(-DTETLIBRARY)
  elseif(ENABLE_TETGEN)
    find_library(TETGEN_LIB tet PATH_SUFFIXES lib)
    find_path(TETGEN_INC "tetgen.h" PATH_SUFFIXES src include tetgen)
    if(TETGEN_LIB AND TETGEN_INC)
      list(APPEND EXTERNAL_LIBRARIES ${TETGEN_LIB})
      list(APPEND EXTERNAL_INCLUDES ${TETGEN_INC})
      set_config_option(HAVE_TETGEN "Tetgen")
    endif(TETGEN_LIB AND TETGEN_INC)
  endif(ENABLE_TETGEN AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/Tetgen1.5/tetgen.h)
  if(HAVE_TETGEN)
    message(STATUS "Note: By including Tetgen you have to comply with Tetgen's "
            "special licensing requirements stated in contrib/Tetgen1.5/LICENSE.")
  endif(HAVE_TETGEN)
endif(HAVE_MESH)

if(ENABLE_FOURIER_MODEL)
  set(FM_REQUIRED FourierModel fftw3 gsl gslcblas)
  find_all_libraries(FM_LIBS FM_REQUIRED "" lib)
  if(FM_LIBS)
    set_config_option(HAVE_FOURIER_MODEL "FourierModel")
    list(APPEND EXTERNAL_LIBRARIES ${FM_LIBS})
  endif(FM_LIBS)
endif(ENABLE_FOURIER_MODEL)

if(ENABLE_MED OR ENABLE_CGNS)
  find_library(HDF5_LIB hdf5)
  if(HDF5_LIB)
    if(ENABLE_MED)
      find_library(MED_LIB med)
      if(MED_LIB)
        set_config_option(HAVE_MED "Med")
        list(APPEND EXTERNAL_LIBRARIES ${MED_LIB})
      endif(MED_LIB)
    endif(ENABLE_MED)
    if(ENABLE_CGNS)
      find_library(CGNS_LIB cgns PATHS ENV CGNS_ROOT PATH_SUFFIXES lib)
      find_path(CGNS_INC "cgnslib.h" PATHS ENV CGNS_ROOT PATH_SUFFIXES include)
      if(CGNS_LIB AND CGNS_INC)
        set_config_option(HAVE_LIBCGNS "Cgns")
        list(APPEND EXTERNAL_LIBRARIES ${CGNS_LIB})
        list(APPEND EXTERNAL_INCLUDES ${CGNS_INC})
      endif(CGNS_LIB AND CGNS_INC)
    endif(ENABLE_CGNS)
    if(MED_LIB OR CGNS_LIB)
      list(APPEND EXTERNAL_LIBRARIES ${HDF5_LIB})
      find_library(SZ_LIB NAMES szlib sz)
      if(SZ_LIB)
        list(APPEND EXTERNAL_LIBRARIES ${SZ_LIB})
      endif(SZ_LIB)
      if(NOT HAVE_LIBZ) # necessary for non-GUI builds
        find_package(ZLIB)
        if(ZLIB_FOUND)
          set_config_option(HAVE_LIBZ "Zlib")
          list(APPEND EXTERNAL_LIBRARIES ${ZLIB_LIBRARIES})
        endif(ZLIB_FOUND)
      endif(NOT HAVE_LIBZ)
    endif(MED_LIB OR CGNS_LIB)
  else(HDF5_LIB)
    message(STATUS "HDF5 not found")
  endif(HDF5_LIB)
endif(ENABLE_MED OR ENABLE_CGNS)

if(HAVE_SOLVER)
  if(ENABLE_GMM)
    find_path(GMM_INC "gmm.h" PATH_SUFFIXES src include include/gmm)
    if(GMM_INC)
      list(APPEND EXTERNAL_INCLUDES ${GMM_INC})
    else(GMM_INC)
      message(STATUS "System GMM not found: using contrib/gmm instead")
      include_directories(contrib/gmm)
    endif(GMM_INC)
    set_config_option(HAVE_GMM "Gmm")
  endif(ENABLE_GMM)

  if(ENABLE_TAUCS)
    if(HAVE_METIS)
      add_subdirectory(contrib/taucs)
      include_directories(contrib/taucs/src contrib/taucs/config)
      if(WIN32 OR CYGWIN)
        add_definitions(-DOSTYPE_win32)
      elseif(APPLE)
        add_definitions(-DOSTYPE_darwin)
      else(WIN32)
        add_definitions(-DOSTYPE_linux)
      endif(WIN32 OR CYGWIN)
      file(GLOB_RECURSE TAUCS_D ${CMAKE_CURRENT_BINARY_DIR}/contrib/taucs/D/*.c)
      file(GLOB_RECURSE TAUCS_S ${CMAKE_CURRENT_BINARY_DIR}/contrib/taucs/S/*.c)
      file(GLOB_RECURSE TAUCS_Z ${CMAKE_CURRENT_BINARY_DIR}/contrib/taucs/Z/*.c)
      file(GLOB_RECURSE TAUCS_C ${CMAKE_CURRENT_BINARY_DIR}/contrib/taucs/C/*.c)
      file(GLOB_RECURSE TAUCS_G ${CMAKE_CURRENT_BINARY_DIR}/contrib/taucs/G/*.c)
      list(APPEND GMSH_SRC ${TAUCS_D};${TAUCS_S};${TAUCS_Z};${TAUCS_C};${TAUCS_G})
      set_source_files_properties(${TAUCS_D} PROPERTIES COMPILE_FLAGS -DTAUCS_CORE_DOUBLE)
      set_source_files_properties(${TAUCS_S} PROPERTIES COMPILE_FLAGS -DTAUCS_CORE_SINGLE)
      set_source_files_properties(${TAUCS_Z} PROPERTIES COMPILE_FLAGS -DTAUCS_CORE_DCOMPLEX)
      set_source_files_properties(${TAUCS_C} PROPERTIES COMPILE_FLAGS -DTAUCS_CORE_SCOMPLEX)
      set_source_files_properties(${TAUCS_G} PROPERTIES COMPILE_FLAGS -DTAUCS_CORE_GENERAL)
      set_config_option(HAVE_TAUCS "Taucs")
    else(HAVE_METIS)
      message(STATUS "Warning: Disabling Taucs (requires METIS)")
    endif(HAVE_METIS)
  endif(ENABLE_TAUCS)

  if(ENABLE_MUMPS)
    set(MUMPS_LIBS_REQUIRED smumps dmumps cmumps zmumps mumps_common pord)
    if(NOT ENABLE_MPI)
      list(APPEND MUMPS_LIBS_REQUIRED mpiseq)
    endif(NOT ENABLE_MPI)
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
      endif(GFORTRAN_LIB)
      if(ENABLE_GMM) # use GMM/MUMPS interface
        add_definitions(-DGMM_USES_MUMPS)
      endif(ENABLE_GMM)
    endif(MUMPS_LIBRARIES AND SMUMPS_INC AND DMUMPS_INC AND CMUMPS_INC AND ZMUMPS_INC)
  endif(ENABLE_MUMPS)

  if(ENABLE_PETSC)
    if(PETSC_DIR)
      set(ENV_PETSC_DIR ${PETSC_DIR})
    else(PETSC_DIR)
      set(ENV_PETSC_DIR $ENV{PETSC_DIR})
    endif(PETSC_DIR)
    if(PETSC_ARCH)
      set(ENV_PETSC_ARCH ${PETSC_ARCH})
    else(PETSC_ARCH)
      set(ENV_PETSC_ARCH $ENV{PETSC_ARCH})
    endif(PETSC_ARCH)
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
      endif(EXISTS ${FILE})
    endforeach(FILE)
    if(PETSC_VARIABLES)
      # try to find PETSC_CC_INCLUDES for PETSc >= 3.4
      string(REGEX MATCH "PETSC_CC_INCLUDES = [^\n\r]*" PETSC_PACKAGES_INCLUDES
             ${PETSC_VARIABLES})
      if(PETSC_PACKAGES_INCLUDES)
        string(REPLACE "PETSC_CC_INCLUDES = " "" PETSC_PACKAGES_INCLUDES
               ${PETSC_PACKAGES_INCLUDES})
      else(PETSC_PACKAGES_INCLUDES)
        # try to find PETSC_PACKAGES_INCLUDES in older versions
        list(APPEND EXTERNAL_INCLUDES ${ENV_PETSC_DIR}/include)
        list(APPEND EXTERNAL_INCLUDES ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/include)
        string(REGEX MATCH "PACKAGES_INCLUDES = [^\n\r]*" PETSC_PACKAGES_INCLUDES
               ${PETSC_VARIABLES})
        string(REPLACE "PACKAGES_INCLUDES = " "" PETSC_PACKAGES_INCLUDES
               ${PETSC_PACKAGES_INCLUDES})
      endif(PETSC_PACKAGES_INCLUDES)
      if(PETSC_PACKAGES_INCLUDES)
        if(PETSC_PACKAGES_INCLUDES)
          string(REPLACE "-I" "" PETSC_PACKAGES_INCLUDES ${PETSC_PACKAGES_INCLUDES})
          string(REPLACE " " ";" PETSC_PACKAGES_INCLUDES ${PETSC_PACKAGES_INCLUDES})
          foreach(VAR ${PETSC_PACKAGES_INCLUDES})
            # seem to include unexisting directories (/usr/include/lib64)
	    # check to avoid warnings
	    if(EXISTS ${VAR})
	      list(APPEND EXTERNAL_INCLUDES ${VAR})
            endif(EXISTS ${VAR})
          endforeach(VAR)
        endif(PETSC_PACKAGES_INCLUDES)
      endif(PETSC_PACKAGES_INCLUDES)
      # find libraries (<= 3.0)
      set(PETSC_LIBS_REQUIRED petscksp petscdm petscmat petscvec petsc)
      find_all_libraries(PETSC_LIBS PETSC_LIBS_REQUIRED
                         ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib "")
      # petsc 3.1 creates only one library (libpetsc)
      if(NOT PETSC_LIBS)
        find_library(PETSC_LIBS petsc PATHS ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib
                     NO_DEFAULT_PATH)
      endif(NOT PETSC_LIBS)
      if(PETSC_LIBS)
        set_config_option(HAVE_PETSC "PETSc")
	if(NOT HAVE_BLAS)
          set_config_option(HAVE_BLAS "Blas(PETSc)")
        endif(NOT HAVE_BLAS)
	if(NOT HAVE_LAPACK)
          set_config_option(HAVE_LAPACK "Lapack(PETSc)")
        endif(NOT HAVE_LAPACK)
      endif(PETSC_LIBS)
      # find slepc (needs to be linked in before petsc)
      if(ENABLE_SLEPC)
        if(SLEPC_DIR)
          set(ENV_SLEPC_DIR ${SLEPC_DIR})
         else(SLEPC_DIR)
          set(ENV_SLEPC_DIR $ENV{SLEPC_DIR})
        endif(SLEPC_DIR)
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
            endif(SLEPC_INC2)
          endif(SLEPC_INC)
        endif(SLEPC_LIB)
      endif(ENABLE_SLEPC)
      list(APPEND EXTERNAL_LIBRARIES ${PETSC_LIBS})
      # find additional libraries to link with
      string(REGEX MATCH "PACKAGES_LIBS = [^\n\r]*" PLIBS ${PETSC_VARIABLES})
      if(PLIBS)
        string(REPLACE "PACKAGES_LIBS = " "" PLIBS ${PLIBS})
        string(STRIP ${PLIBS} PLIBS)
        list(APPEND EXTERNAL_LIBRARIES "${PLIBS}")
      endif(PLIBS)
      string(REGEX MATCH "PETSC_EXTERNAL_LIB_BASIC = [^\n\r]*" PLIBS_BASIC ${PETSC_VARIABLES})
      if(PLIBS_BASIC)
        string(REPLACE "PETSC_EXTERNAL_LIB_BASIC = " "" PLIBS_BASIC ${PLIBS_BASIC})
        string(STRIP ${PLIBS_BASIC} PLIBS_BASIC)
        separate_arguments(PLIBS_BASIC)
        list(APPEND EXTERNAL_LIBRARIES "${PLIBS_BASIC}")
      endif(PLIBS_BASIC)
      string(REGEX MATCH "PCC_LINKER_LIBS = [^\n\r]*" LLIBS ${PETSC_VARIABLES})
      if(LLIBS)
        string(REPLACE "PCC_LINKER_LIBS = " "" LLIBS ${LLIBS})
        string(STRIP ${LLIBS} LLIBS)
        list(APPEND EXTERNAL_LIBRARIES "${LLIBS}")
      endif(LLIBS)
    else(PETSC_VARIABLES)
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
          endif(SLEPC_LIB AND SLEPC_INC)
        endif(ENABLE_SLEPC)
        list(APPEND EXTERNAL_LIBRARIES ${PETSC_LIBS})
        list(APPEND EXTERNAL_INCLUDES ${PETSC_INC})
      endif(PETSC_LIBS AND PETSC_INC)
    endif(PETSC_VARIABLES)
  endif(ENABLE_PETSC)

  if(ENABLE_GETDP)
    find_library(GETDP_LIB GetDP)
    find_path(GETDP_INC "GetDP.h" PATH_SUFFIXES getdp)
    if(GETDP_LIB AND GETDP_INC)
      set_config_option(HAVE_GETDP "GetDP")
      list(APPEND EXTERNAL_LIBRARIES ${GETDP_LIB})
      list(APPEND EXTERNAL_INCLUDES ${GETDP_INC})
    endif(GETDP_LIB AND GETDP_INC)
  endif(ENABLE_GETDP)
endif(HAVE_SOLVER)

if(ENABLE_OCC)
  if(WIN32 OR CYGWIN)
    if(HAVE_64BIT_SIZE_T)
      set(OCC_SYS_NAME win64)
    else(HAVE_64BIT_SIZE_T)
      set(OCC_SYS_NAME win32)
    endif(HAVE_64BIT_SIZE_T)
  else(WIN32 OR CYGWIN)
    set(OCC_SYS_NAME ${CMAKE_SYSTEM_NAME})
  endif(WIN32 OR CYGWIN)
  set(OCC_LIBS_REQUIRED
      # subset of DataExchange
      TKSTEP TKSTEP209 TKSTEPAttr TKSTEPBase TKIGES TKXSBase
      # ModelingAlgorithms
      TKOffset TKFeat TKFillet TKBool TKShHealing TKMesh TKHLR TKBO TKPrim
      TKTopAlgo TKGeomAlgo
      # ModelingData
      TKBRep TKGeomBase TKG3d TKG2d
      # FoundationClasses
      # TKAdvTools -- not necessary? (and removed from OCC 6.8)
      TKMath TKernel)
  list(LENGTH OCC_LIBS_REQUIRED NUM_OCC_LIBS_REQUIRED)
  set(OCC_LIBS)
  foreach(OCC ${OCC_LIBS_REQUIRED})
    find_library(OCC_LIB ${OCC} HINTS ENV CASROOT PATH_SUFFIXES lib
                 ${OCC_SYS_NAME}/lib ${OCC_SYS_NAME}/vc8/lib)
    if(OCC_LIB)
      list(APPEND OCC_LIBS ${OCC_LIB})
    else(OCC_LIB)
      message(STATUS "OCC lib " ${OCC} " not Found")
    endif(OCC_LIB)
    unset(OCC_LIB CACHE)
  endforeach(OCC)
  list(LENGTH OCC_LIBS NUM_OCC_LIBS)
  if(NUM_OCC_LIBS EQUAL NUM_OCC_LIBS_REQUIRED)
    find_path(OCC_INC "BRep_Tool.hxx" PATHS ENV CASROOT PATH_SUFFIXES inc
              include include/oce opencascade)
    if(OCC_INC)
      set_config_option(HAVE_OCC "OpenCascade")
      list(APPEND EXTERNAL_LIBRARIES ${OCC_LIBS})
      list(APPEND EXTERNAL_INCLUDES ${OCC_INC})
      if(HAVE_64BIT_SIZE_T)
        add_definitions(-D_OCC64)
      endif(HAVE_64BIT_SIZE_T)
      if(CYGWIN)
        list(APPEND EXTERNAL_LIBRARIES "winspool")
        add_definitions(-DOCC_CONVERT_SIGNALS)
      elseif(MSVC)
        add_definitions(-DWNT)
      endif(CYGWIN)
      find_path(OCC_CONFIG_H "config.h" PATHS ${OCC_INC} ${OCC_CONFIG_H_PATH}
                NO_DEFAULT_PATH)
      if(NOT OCC_CONFIG_H)
        add_definitions(-DHAVE_NO_OCC_CONFIG_H)
      endif(NOT OCC_CONFIG_H)
    endif(OCC_INC)
  endif(NUM_OCC_LIBS EQUAL NUM_OCC_LIBS_REQUIRED)
endif(ENABLE_OCC)

if(ENABLE_ACIS)
  find_library(ACIS_LIB SpaACIS PATH_SUFFIXES bin/maci386)
  if(ACIS_LIB)
    find_path(ACIS_INC "kernapi.hxx" PATH_SUFFIXES include)
    if(ACIS_INC)
      set_config_option(HAVE_ACIS "Acis")
      list(APPEND EXTERNAL_LIBRARIES ${ACIS_LIB})
      list(APPEND EXTERNAL_INCLUDES ${ACIS_INC})
    endif(ACIS_INC)
  endif(ACIS_LIB)
endif(ENABLE_ACIS)

if(HAVE_LIBZ AND ENABLE_COMPRESSED_IO)
  set_config_option(HAVE_COMPRESSED_IO "CompressedIO")
endif(HAVE_LIBZ AND ENABLE_COMPRESSED_IO)

if(ENABLE_ZIPPER)
  if(ENABLE_BUILD_IOS)
    set_config_option(HAVE_LIBZ "Zlib")
  endif(ENABLE_BUILD_IOS)
  if(NOT HAVE_LIBZ) # necessary for non-GUI builds
    find_package(ZLIB)
    if(ZLIB_FOUND)
      set_config_option(HAVE_LIBZ "Zlib")
      list(APPEND EXTERNAL_LIBRARIES ${ZLIB_LIBRARIES})
      list(APPEND EXTERNAL_INCLUDES ${ZLIB_INCLUDE_DIR})
    endif(ZLIB_FOUND)
  endif(NOT HAVE_LIBZ)
  if(HAVE_LIBZ)
    add_subdirectory(contrib/zipper)
    include_directories(contrib/zipper)
    set_config_option(HAVE_ZIPPER "Zipper")
  endif(HAVE_LIBZ)
endif(ENABLE_ZIPPER)

if(ENABLE_WRAP_PYTHON)
  find_package(SWIG)
  find_package(PythonLibs)
  find_package(PythonInterp)# ${PYTHONLIBS_VERSION_STRING} EXACT)
  if(SWIG_FOUND AND PYTHONLIBS_FOUND)
    message(STATUS "Found SWIG version " ${SWIG_VERSION})
    string(SUBSTRING ${SWIG_VERSION} 0 1 SWIG_MAJOR_VERSION)
    if(SWIG_MAJOR_VERSION EQUAL 1)
      message(WARNING "Python bindings require SWIG >= 2: disabling Python")
    else(SWIG_MAJOR_VERSION EQUAL 1)
      set_config_option(HAVE_PYTHON "Python")
      mark_as_advanced(CLEAR PYTHON_LIBRARY PYTHON_INCLUDE_DIR)
    endif(SWIG_MAJOR_VERSION EQUAL 1)
  endif(SWIG_FOUND AND PYTHONLIBS_FOUND)
endif(ENABLE_WRAP_PYTHON)

if(HAVE_PYTHON)
  if(ENABLE_NUMPY)
    if (NOT NUMPY_INC)
      EXEC_PROGRAM (${PYTHON_EXECUTABLE}
        ARGS "-c \"import numpy; print(numpy.get_include())\""
        OUTPUT_VARIABLE NUMPY_INC
        RETURN_VALUE NUMPY_NOT_FOUND)
    endif(NOT NUMPY_INC)
    if(NUMPY_INC)
      list(APPEND EXTERNAL_INCLUDES ${NUMPY_INC})
      set_config_option(HAVE_NUMPY "Numpy")
    endif(NUMPY_INC)
  endif(ENABLE_NUMPY)
  if(HAVE_PETSC)
    if(ENABLE_PETSC4PY)
      EXECUTE_PROCESS(
        COMMAND ${PYTHON_EXECUTABLE} -c "import petsc4py; print(petsc4py.get_include())"
        OUTPUT_VARIABLE PETSC4PY_INC
        RESULT_VARIABLE PETSC4PY_NOT_FOUND
        ERROR_QUIET
        OUTPUT_STRIP_TRAILING_WHITESPACE
      )
      if(PETSC4PY_INC)
        list(APPEND EXTERNAL_INCLUDES ${PETSC4PY_INC})
        set_config_option(HAVE_PETSC4PY "PETSc4py")
      endif(PETSC4PY_INC)
    endif(ENABLE_PETSC4PY)
  endif(HAVE_PETSC)
endif(HAVE_PYTHON)

check_function_exists(vsnprintf HAVE_VSNPRINTF)
if(NOT HAVE_VSNPRINTF AND NOT ENABLE_BUILD_IOS AND NOT ENABLE_BUILD_ANDROID)
  set_config_option(HAVE_NO_VSNPRINTF "NoVsnprintf")
endif(NOT HAVE_VSNPRINTF AND NOT ENABLE_BUILD_IOS AND NOT ENABLE_BUILD_ANDROID)

check_include_file(sys/socket.h HAVE_SYS_SOCKET_H)
if(HAVE_SYS_SOCKET_H)
  set(CMAKE_EXTRA_INCLUDE_FILES sys/socket.h)
endif(HAVE_SYS_SOCKET_H)
check_type_size(socklen_t SOCKLEN_T_SIZE)
set(CMAKE_EXTRA_INCLUDE_FILES)
if(NOT SOCKLEN_T_SIZE AND NOT ENABLE_BUILD_IOS AND NOT ENABLE_BUILD_ANDROID)
  set_config_option(HAVE_NO_SOCKLEN_T "NoSocklenT")
endif(NOT SOCKLEN_T_SIZE AND NOT ENABLE_BUILD_IOS AND NOT ENABLE_BUILD_ANDROID)

check_include_file(stdint.h HAVE_STDINT_H)
if(HAVE_STDINT_H)
  set(CMAKE_EXTRA_INCLUDE_FILES stdint.h)
else(HAVE_STDINT_H)
  set_config_option(HAVE_NO_STDINT_H "NoStdintH")
endif(HAVE_STDINT_H)
check_type_size(intptr_t INTPTR_T_SIZE)
set(CMAKE_EXTRA_INCLUDE_FILES)
if(NOT INTPTR_T_SIZE AND NOT ENABLE_BUILD_IOS AND NOT ENABLE_BUILD_ANDROID)
  set_config_option(HAVE_NO_INTPTR_T "NoIntptrT")
endif(NOT INTPTR_T_SIZE AND NOT ENABLE_BUILD_IOS AND NOT ENABLE_BUILD_ANDROID)

check_include_file(dlfcn.h DLFCN_H)
if(DLFCN_H)
  set_config_option(HAVE_DLOPEN "Dlopen")
  list(APPEND EXTERNAL_LIBRARIES ${CMAKE_DL_LIBS})
endif(DLFCN_H)

check_include_file(linux/joystick.h LINUX_JOYSTICK_H)
if(LINUX_JOYSTICK_H)
  set_config_option(HAVE_LINUX_JOYSTICK "LinuxJoystick")
endif(LINUX_JOYSTICK_H)

if(MSVC)
  add_definitions(-D_USE_MATH_DEFINES -DNOMINMAX
                  -D_CRT_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_DEPRECATE)
  if(HAVE_FLTK)
    set(GMSH_SRC ${GMSH_SRC};Fltk/Win32Icon.rc)
  endif(HAVE_FLTK)
endif(MSVC)

if(WIN32 OR CYGWIN)
  list(APPEND EXTERNAL_LIBRARIES winmm wsock32 ws2_32 psapi)
endif(WIN32 OR CYGWIN)

# force full warnings to encourage everybody to write clean(er) code
check_cxx_compiler_flag("-Wall" WALL)
if(WALL AND NOT MSVC)
  file(GLOB_RECURSE WALL_SRC Common/*.cpp Fltk/*.cpp FunctionSpace/*.cpp
       Geo/*.cpp Graphics/*.cpp Mesh/*.cpp Numeric/*.cpp Parser/*.cpp
       Plugin/*.cpp Post/*.cpp Qt/*.cpp Solver/*.cpp)
  set(WF "-Wall")
  check_cxx_compiler_flag("-Wint-to-void-pointer-cast" WCAST)
  if(WCAST)
    set(WF "${WF} -Wno-int-to-void-pointer-cast")
  endif(WCAST)
  check_cxx_compiler_flag("-Wdeprecated-declarations" WDEPREC)
  if(WDEPREC)
    # FIXME: remove this when we have fixed the deprecated GLU code for OpenGL3
    set(WF "${WF} -Wno-deprecated-declarations")
  endif(WDEPREC)
  check_cxx_compiler_flag("-Wmisleading-indentation" WIND)
  if(WIND)
    set(WF "${WF} -Wno-misleading-indentation")
  endif(WIND)
  set_compile_flags(WALL_SRC ${WF})
endif(WALL AND NOT MSVC)

# don't issue warnings for contributed libraries
check_cxx_compiler_flag("-w" NOWARN)
if(NOWARN)
  file(GLOB_RECURSE NOWARN_SRC contrib/*.cpp contrib/*.cc contrib/*.cxx contrib/*.c
      ${CMAKE_CURRENT_BINARY_DIR}/contrib/taucs/*.c)
  set_compile_flags(NOWARN_SRC "-w")
endif(NOWARN)

# disable compile optimization on some known problematic files
check_cxx_compiler_flag("-O0" NOOPT)
if(NOOPT OR ENABLE_BUILD_IOS)
  if(ENABLE_BUILD_IOS) # optimized iOS 10 64 bits screws somewhere in Geo
    file(GLOB_RECURSE NOOPT_SRC Geo/G*.cpp Mesh/BDS.cpp Parser/Gmsh.tab.cpp
         contrib/Tetgen1.5/predicates.cxx)
  else(ENABLE_BUILD_IOS)
    file(GLOB_RECURSE NOOPT_SRC Mesh/BDS.cpp Parser/Gmsh.tab.cpp
         contrib/Tetgen1.5/predicates.cxx)
  endif(ENABLE_BUILD_IOS)
  set_compile_flags(NOOPT_SRC "-O0")
endif(NOOPT OR ENABLE_BUILD_IOS)

#enable Revoropt and set compile flags for the corresponding plugin
if(ENABLE_REVOROPT)
  find_path(EIGEN3_INC "eigen3/Eigen/Dense")
  if(EIGEN3_INC AND HAVE_MESH AND HAVE_PLUGINS AND HAVE_ANN AND HAVE_BFGS)
    list(APPEND EXTERNAL_INCLUDES ${EIGEN3_INC} contrib/Revoropt/include)
    message(STATUS "using contrib/Revoropt")
    set_config_option(HAVE_REVOROPT "Revoropt")
    add_definitions(-DUSE_ANN)
    get_source_file_property(PROP Plugin/CVTRemesh.cpp COMPILE_FLAGS)
    if(PROP)
      set_source_files_properties(Plugin/CVTRemesh.cpp PROPERTIES
                                  COMPILE_FLAGS "${PROP} -std=c++11")
    else(PROP)
      set_source_files_properties(Plugin/CVTRemesh.cpp PROPERTIES
                                  COMPILE_FLAGS "-std=c++11")
    endif(PROP)
  else(EIGEN3_INC AND HAVE_MESH AND HAVE_PLUGINS AND HAVE_ANN AND HAVE_BFGS)
    message(WARNING "Revoropt requires Eigen3, Mesh, Plugins, Ann and BFGS")
  endif(EIGEN3_INC AND HAVE_MESH AND HAVE_PLUGINS AND HAVE_ANN AND HAVE_BFGS)
endif(ENABLE_REVOROPT)

list(SORT CONFIG_OPTIONS)
set(GMSH_CONFIG_OPTIONS "")
foreach(OPT ${CONFIG_OPTIONS})
  set(GMSH_CONFIG_OPTIONS "${GMSH_CONFIG_OPTIONS} ${OPT}")
endforeach(OPT)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Common/GmshConfig.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/Common/GmshConfig.h)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Common/GmshVersion.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/Common/GmshVersion.h)

# process cmake environment variables so we can append them to the -I include
# commands. This is not recommended (we should only use the cache variables) but
# it is very convenient: otherwise we have to remember providing the
# -D... options to cmake for each new build.
set(ENV_CMAKE_PREFIX_PATH $ENV{CMAKE_PREFIX_PATH})
set(ENV_CMAKE_INCLUDE_PATH $ENV{CMAKE_INCLUDE_PATH})
if(UNIX)
  if(ENV_CMAKE_PREFIX_PATH)
    string(REPLACE ":" ";" ENV_CMAKE_PREFIX_PATH ${ENV_CMAKE_PREFIX_PATH})
  endif(ENV_CMAKE_PREFIX_PATH)
  if(ENV_CMAKE_INCLUDE_PATH)
    string(REPLACE ":" ";" ENV_CMAKE_INCLUDE_PATH ${ENV_CMAKE_INCLUDE_PATH})
  endif(ENV_CMAKE_INCLUDE_PATH)
endif(UNIX)
list(APPEND EXTERNAL_INCLUDES ${CMAKE_INCLUDE_PATH} ${ENV_CMAKE_INCLUDE_PATH})
list(APPEND EXTERNAL_INCLUDES ${CMAKE_PREFIX_PATH} ${ENV_CMAKE_PREFIX_PATH})
foreach(DIR ${CMAKE_PREFIX_PATH} ${ENV_CMAKE_PREFIX_PATH})
  list(APPEND EXTERNAL_INCLUDES ${DIR}/include)
endforeach(DIR)

if(EXTERNAL_INCLUDES)
  list(REMOVE_DUPLICATES EXTERNAL_INCLUDES)
endif(EXTERNAL_INCLUDES)

if(HAVE_FLTK)
  set(LINK_LIBRARIES ${FLTK_LIBRARIES} ${EXTERNAL_LIBRARIES}
                     ${OPENGL_LIBRARIES} ${LAPACK_LIBRARIES})
elseif(HAVE_QT)
  set(LINK_LIBRARIES ${QT_LIBRARIES} ${EXTERNAL_LIBRARIES}
                     ${OPENGL_LIBRARIES} ${LAPACK_LIBRARIES})
elseif(HAVE_OPENGL)
  set(LINK_LIBRARIES ${EXTERNAL_LIBRARIES} ${OPENGL_LIBRARIES}
                     ${LAPACK_LIBRARIES})
else(HAVE_FLTK)
  set(LINK_LIBRARIES ${EXTERNAL_LIBRARIES} ${LAPACK_LIBRARIES})
endif(HAVE_FLTK)

# Linux-specific linking
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  # try to use static gfortran on static Linux builds
  if(NOT ENABLE_BUILD_DYNAMIC AND NOT ENABLE_BUILD_SHARED)
    find_library(GFORTRAN_STATIC libgfortran.a)
    if(GFORTRAN_STATIC)
      message(STATUS "Using static libgfortran")
      foreach(STR ${LINK_LIBRARIES})
        string(REPLACE "-lgfortran" ${GFORTRAN_STATIC} STR2 ${STR})
        list(APPEND LINK_LIBRARIES2 ${STR2})
      endforeach(STR)
      set(LINK_LIBRARIES ${LINK_LIBRARIES2})
    endif(GFORTRAN_STATIC)
  endif(NOT ENABLE_BUILD_DYNAMIC AND NOT ENABLE_BUILD_SHARED)
  if(HAVE_OCC)
    find_library(RT_LIB rt)
    if(RT_LIB)
      list(APPEND LINK_LIBRARIES ${RT_LIB})
    endif(RT_LIB)
  endif(HAVE_OCC)
  if(CMAKE_C_COMPILER_ID MATCHES "GNU")
    add_definitions(-fPIC)
  endif(CMAKE_C_COMPILER_ID MATCHES "GNU")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

# we could specify include dirs more selectively, but this is simpler
include_directories(Common Fltk Geo Graphics Mesh Solver Numeric Parser
  Plugin Post Qt ${EXTERNAL_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR}/Common)

# set this for external codes that might include this CMakeList file
set(GMSH_EXTERNAL_INCLUDE_DIRS ${EXTERNAL_INCLUDES} CACHE
    STRING "External include directories" FORCE)
set(GMSH_EXTERNAL_LIBRARIES ${LINK_LIBRARIES} CACHE
    STRING "External libraries" FORCE)

# group sources for easier navigation in IDEs
foreach(DIR ${GMSH_DIRS})
  string(REGEX REPLACE "\\+" "\\\\+" DIR ${DIR})
  source_group(${DIR} REGULAR_EXPRESSION ${DIR}/.*)
endforeach(DIR)

# static library target
if(ENABLE_BUILD_LIB)
  add_library(lib STATIC ${GMSH_SRC})
  set_target_properties(lib PROPERTIES OUTPUT_NAME Gmsh)
  if(MSVC)
    set_target_properties(lib PROPERTIES DEBUG_POSTFIX d)
    if(ENABLE_MSVC_STATIC_RUNTIME)
      set_target_properties(lib PROPERTIES LINK_FLAGS_RELEASE "/nodefaultlib:LIBCMT")
    endif(ENABLE_MSVC_STATIC_RUNTIME)
  endif(MSVC)
endif(ENABLE_BUILD_LIB)

if(ENABLE_BUILD_ANDROID)
  find_file(CMAKE_TOOLCHAIN_FILE "android.toolchain.cmake")
  if(NOT CMAKE_TOOLCHAIN_FILE)
    message(FATAL_ERROR "Cannot compile Gmsh for android without android-cmake")
  endif(NOT CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_BUILD_TYPE Release)
  set(LIBRARY_OUTPUT_PATH_ROOT ${CMAKE_CURRENT_BINARY_DIR})
  set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/libs/)
  add_definitions(-DBUILD_ANDROID)
  add_library(androidGmsh SHARED ${GMSH_SRC})
  set_target_properties(androidGmsh PROPERTIES OUTPUT_NAME Gmsh)
  target_link_libraries(androidGmsh ${EXTERNAL_LIBRARIES})
endif(ENABLE_BUILD_ANDROID)

# shared library target
if(ENABLE_BUILD_SHARED OR ENABLE_BUILD_DYNAMIC OR
   ENABLE_WRAP_PYTHON OR ENABLE_WRAP_JAVA)
  add_library(shared SHARED ${GMSH_SRC})
  set_target_properties(shared PROPERTIES OUTPUT_NAME Gmsh)
  set_target_properties(shared PROPERTIES
    VERSION ${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION}.${GMSH_PATCH_VERSION}
    SOVERSION ${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION})
  if(HAVE_LAPACK AND LAPACK_FLAGS)
    set_target_properties(shared PROPERTIES LINK_FLAGS ${LAPACK_FLAGS})
  endif(HAVE_LAPACK AND LAPACK_FLAGS)
  if(MSVC AND ENABLE_MSVC_STATIC_RUNTIME)
    message(STATUS "Note: By enabling ENABLE_MSVC_STATIC_RUNTIME, shared library "
            "won't link. In MSVC change /MT to /MD in the shared project properties")
  endif(MSVC AND ENABLE_MSVC_STATIC_RUNTIME)
  target_link_libraries(shared ${LINK_LIBRARIES})
endif(ENABLE_BUILD_SHARED OR ENABLE_BUILD_DYNAMIC OR
      ENABLE_WRAP_PYTHON OR ENABLE_WRAP_JAVA)

# binary targets
if(HAVE_FLTK)
  if(ENABLE_BUILD_DYNAMIC)
    add_executable(gmsh WIN32 Fltk/Main.cpp)
    target_link_libraries(gmsh shared)
  else(ENABLE_BUILD_DYNAMIC)
    add_executable(gmsh WIN32 Fltk/Main.cpp ${GMSH_SRC})
  endif(ENABLE_BUILD_DYNAMIC)
elseif(HAVE_QT)
  qt4_wrap_cpp(GMSH_MOC_SRC ${GMSH_MOC_HDR})
  add_executable(gmsh WIN32 Qt/Main.cpp ${GMSH_SRC} ${GMSH_MOC_SRC})
else(HAVE_FLTK)
  if(ENABLE_BUILD_DYNAMIC)
    add_executable(gmsh Common/Main.cpp)
    target_link_libraries(gmsh shared)
  else(ENABLE_BUILD_DYNAMIC)
    add_executable(gmsh Common/Main.cpp ${GMSH_SRC})
  endif(ENABLE_BUILD_DYNAMIC)
endif(HAVE_FLTK)
target_link_libraries(gmsh ${LINK_LIBRARIES})

# Windows specific linker options
if(WIN32 AND NOT MSVC OR CYGWIN)
  set(FLAGS "-Wl,--stack,16777216 -mwindows")
  if(HAVE_64BIT_SIZE_T)
    set(FLAGS "${FLAGS} ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/Win64Icon.res")
  else(HAVE_64BIT_SIZE_T)
    set(FLAGS "${FLAGS} ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/Win32Icon.res")
  endif(HAVE_64BIT_SIZE_T)
  if(ENABLE_BUILD_DYNAMIC OR ENABLE_BUILD_SHARED)
    set(FLAGS "${FLAGS} -Wl,-Bstatic -lgfortran")
    set_target_properties(gmsh PROPERTIES
      LINK_FLAGS "${FLAGS} -Wl,--enable-auto-import")
    set(LIBGMSH_DEF "libGmsh-${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION}.def")
    # automatically export .def file with all symbols
    set_target_properties(shared PROPERTIES PREFIX "lib"
      LINK_FLAGS "${FLAGS} -Wl,--export-all-symbols,--output-def,${LIBGMSH_DEF}")
  else(ENABLE_BUILD_DYNAMIC OR ENABLE_BUILD_SHARED)
    set_target_properties(gmsh PROPERTIES
      LINK_FLAGS "${FLAGS} -static")
    # remove -Wl,-Bdynamic flags
    set(CMAKE_EXE_LINK_DYNAMIC_C_FLAGS)
    set(CMAKE_EXE_LINK_DYNAMIC_CXX_FLAGS)
  endif(ENABLE_BUILD_DYNAMIC OR ENABLE_BUILD_SHARED)
elseif(MSVC)
  set_target_properties(gmsh PROPERTIES LINK_FLAGS
    "/STACK:16777216 /SAFESEH:NO")
endif(WIN32 AND NOT MSVC OR CYGWIN)

# parser target
find_program(BISON bison)
find_program(FLEX flex)
if(BISON AND FLEX)
  add_custom_target(parser
                    COMMAND ${BISON} -p gmsh_yy --output Gmsh.tab.cpp -d Gmsh.y
                    COMMAND ${FLEX} -P gmsh_yy -o Gmsh.yy.cpp Gmsh.l
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Parser)
endif(BISON AND FLEX)

if(UNIX)
  # cannot use cmake's file search functions here (they would only find files
  # existing at configuration time)
  add_custom_target(purge
                    COMMAND rm -f `find . -name *~ -o -name *~~`
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  add_custom_target(etags
                    COMMAND etags `find . -name *.cpp -o -name *.h -o -name *.y`
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif(UNIX)

set(WELCOME_FILE ${CMAKE_CURRENT_SOURCE_DIR}/doc/WELCOME.txt)
set(LICENSE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/doc/LICENSE.txt)
set(CREDITS_FILE ${CMAKE_CURRENT_SOURCE_DIR}/doc/CREDITS.txt)
set(ONELAB_PY ${CMAKE_CURRENT_SOURCE_DIR}/contrib/onelab/python/onelab.py)
file(GLOB TUTORIAL_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tutorial/?*.*)
file(GLOB DEMOS ${CMAKE_CURRENT_SOURCE_DIR}/demos/*)
foreach(SUBDIR ${DEMOS})
  if(IS_DIRECTORY ${SUBDIR})
    list(APPEND DEMOS_DIRS ${SUBDIR})
  endif()
endforeach()
set(TEX_DIR ${CMAKE_CURRENT_SOURCE_DIR}/doc/texinfo)
file(GLOB TEX_SRC ${TEX_DIR}/*.texi)
set(TEX_OBJ ${TEX_DIR}/gmsh.aux ${TEX_DIR}/gmsh.cp ${TEX_DIR}/gmsh.cps
    ${TEX_DIR}/gmsh.fn ${TEX_DIR}/gmsh.html ${TEX_DIR}/gmsh.info ${TEX_DIR}/gmsh.ky
    ${TEX_DIR}/gmsh.log ${TEX_DIR}/gmsh.pdf ${TEX_DIR}/gmsh.pg ${TEX_DIR}/gmsh.toc
    ${TEX_DIR}/gmsh.tp ${TEX_DIR}/gmsh.tps ${TEX_DIR}/gmsh.txt ${TEX_DIR}/gmsh.vr)

macro(unix2dos VARNAME)
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/unix2dos)
  set(UNIX2DOS_FILES)
  foreach(FILE ${${VARNAME}})
    file(READ ${FILE} F0)
    get_filename_component(N ${FILE} NAME)
    if(CYGWIN)
      string(REGEX REPLACE "\n" "\r\n" F1 "${F0}")
      file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/unix2dos/${N} "${F1}")
    else(CYGWIN) # if not in cygwin, cmake adds '\r's automatically
      file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/unix2dos/${N} "${F0}")
    endif(CYGWIN)
    list(APPEND UNIX2DOS_FILES ${CMAKE_CURRENT_BINARY_DIR}/unix2dos/${N})
  endforeach(FILE)
  set(${VARNAME} ${UNIX2DOS_FILES})
endmacro(unix2dos)

if(WIN32 OR CYGWIN)
  if(ENABLE_OS_SPECIFIC_INSTALL)
    set(GMSH_BIN .)
    set(GMSH_LIB .)
    set(GMSH_DOC .)
    set(GMSH_MAN .)
  else(ENABLE_OS_SPECIFIC_INSTALL)
    set(GMSH_BIN bin)
    set(GMSH_LIB lib)
    set(GMSH_DOC share/doc/gmsh)
    set(GMSH_MAN share/man/man1)
  endif(ENABLE_OS_SPECIFIC_INSTALL)
  if(CYGWIN)
    unix2dos(GMSH_API)
    unix2dos(WELCOME_FILE)
    unix2dos(LICENSE_FILE)
    unix2dos(CREDITS_FILE)
    unix2dos(TUTORIAL_FILES)
    foreach(DIR ${DEMOS_DIRS})
      file(GLOB DEMO_FILES ${DIR}/?*.*)
      unix2dos(DEMO_FILES)
    endforeach()
  endif(CYGWIN)
elseif(APPLE AND ENABLE_OS_SPECIFIC_INSTALL)
  # set these so that the files get installed nicely in the MacOSX
  # .app bundle
  set(GMSH_BIN ../MacOS)
  set(GMSH_LIB ../MacOS)
  set(GMSH_DOC ../../..)
  set(GMSH_MAN ../../..)
else(WIN32 OR CYGWIN)
  set(GMSH_BIN bin)
  set(GMSH_LIB lib)
  set(GMSH_DOC share/doc/gmsh)
  set(GMSH_MAN share/man/man1)
endif(WIN32 OR CYGWIN)

# mark targets as optional so we can install them separately if needed
# (e.g. "make lib" or "make shared" followed by "make install/fast")
install(TARGETS gmsh DESTINATION ${GMSH_BIN} OPTIONAL)
if(ENABLE_BUILD_LIB)
  install(TARGETS lib DESTINATION ${GMSH_LIB} OPTIONAL)
endif(ENABLE_BUILD_LIB)
if(ENABLE_BUILD_SHARED OR ENABLE_BUILD_DYNAMIC)
  if(WIN32 AND NOT MSVC OR CYGWIN)
    # install only the runtime (DLL); the .dll.a generated by gcc is not usable
    # by MSVC
    install(TARGETS shared RUNTIME DESTINATION ${GMSH_LIB} OPTIONAL)
    # install .def file
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${LIBGMSH_DEF}
            DESTINATION ${GMSH_LIB})
    # install these DLLs until we figure out how to link them in statically
    # (libstc++ and libgcc should be linkable statically with -static-libstdc++
    # and -static-libgcc but with current mingw64 toolchain it does not
    # work). Also, when cross-compilating find_program does not work -> ask the
    # compiler instead
    find_program(GCC_DLL libgcc_s_sjlj-1.dll)
    find_program(STDC_DLL libstdc++-6.dll)
    if(NOT GCC_DLL)
      execute_process(COMMAND ${CMAKE_CXX_COMPILER} -print-file-name=libgcc_s_seh-1.dll
                      OUTPUT_VARIABLE GCC_DLL OUTPUT_STRIP_TRAILING_WHITESPACE)
      if (NOT EXISTS "${GCC_DLL}")
        execute_process(COMMAND ${CMAKE_CXX_COMPILER} -print-file-name=libgcc_s_sjlj-1.dll
                        OUTPUT_VARIABLE GCC_DLL OUTPUT_STRIP_TRAILING_WHITESPACE)
      endif(NOT EXISTS "${GCC_DLL}")
      get_filename_component(GCC_DLL ${GCC_DLL} ABSOLUTE)
    endif(NOT GCC_DLL)
    if(NOT STDC_DLL)
      execute_process(COMMAND ${CMAKE_CXX_COMPILER} -print-file-name=libstdc++-6.dll
                      OUTPUT_VARIABLE STDC_DLL OUTPUT_STRIP_TRAILING_WHITESPACE)
      get_filename_component(STD_DLL ${STDC_DLL} ABSOLUTE)
    endif(NOT STDC_DLL)
    if(GCC_DLL AND STDC_DLL)
      message(STATUS "Will install extra DLLs for Windows")
      install(FILES ${GCC_DLL} ${STDC_DLL} DESTINATION ${GMSH_LIB})
    endif(GCC_DLL AND STDC_DLL)
  else(WIN32 AND NOT MSVC OR CYGWIN)
    install(TARGETS shared DESTINATION ${GMSH_LIB} OPTIONAL)
  endif(WIN32 AND NOT MSVC OR CYGWIN)
endif(ENABLE_BUILD_SHARED OR ENABLE_BUILD_DYNAMIC)

if(ENABLE_ONELAB)
  install(FILES ${ONELAB_PY} DESTINATION ${GMSH_BIN})
endif(ENABLE_ONELAB)
if(ENABLE_BUILD_LIB OR ENABLE_BUILD_SHARED OR ENABLE_BUILD_DYNAMIC)
  install(FILES ${GMSH_API} DESTINATION include/gmsh)
endif(ENABLE_BUILD_LIB OR ENABLE_BUILD_SHARED OR ENABLE_BUILD_DYNAMIC)
install(FILES ${WELCOME_FILE} DESTINATION ${GMSH_DOC} RENAME README.txt)
install(FILES ${LICENSE_FILE} DESTINATION ${GMSH_DOC})
install(FILES ${CREDITS_FILE} DESTINATION ${GMSH_DOC})
install(FILES ${TUTORIAL_FILES} DESTINATION ${GMSH_DOC}/tutorial)
foreach(DIR ${DEMOS_DIRS})
  get_filename_component(DEMOS_DIR_NAME ${DIR} NAME)
  file(GLOB DEMO_FILES ${DIR}/?*.*)
  install(FILES ${DEMO_FILES} DESTINATION ${GMSH_DOC}/demos/${DEMOS_DIR_NAME})
endforeach()
if(UNIX AND NOT CYGWIN)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/gmsh.1 DESTINATION ${GMSH_MAN})
endif(UNIX AND NOT CYGWIN)

add_custom_target(get_headers
  COMMAND ${CMAKE_COMMAND} -E make_directory Headers/gmsh
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
foreach(FILE ${GMSH_API})
  add_custom_command(TARGET get_headers POST_BUILD COMMAND ${CMAKE_COMMAND}
    -E copy_if_different ${FILE} ${CMAKE_CURRENT_BINARY_DIR}/Headers/gmsh/
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endforeach(FILE)

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
    COMMAND ${MAKEINFO} --html --css-ref=http://gmsh.info/gmsh.css
    --no-split --set-customization-variable
    EXTRA_HEAD='<meta name="viewport" content="width=device-width,initial-scale=1.0">'
    ARGS ${TEX_DIR}/gmsh.texi WORKING_DIRECTORY ${TEX_DIR})
  add_custom_target(html DEPENDS ${TEX_DIR}/gmsh.html)
  install(FILES ${TEX_DIR}/gmsh.html DESTINATION ${GMSH_DOC} OPTIONAL)
else(MAKEINFO)
  add_custom_target(html COMMAND ${CMAKE_COMMAND} -E touch ${TEX_DIR}/gmsh.html)
endif(MAKEINFO)

find_program(TEXI2PDF texi2pdf)
if(TEXI2PDF)
  add_custom_command(OUTPUT ${TEX_DIR}/gmsh.pdf DEPENDS ${TEX_SRC}
                     COMMAND ${TEXI2PDF} ARGS gmsh.texi
                     WORKING_DIRECTORY ${TEX_DIR})
  add_custom_target(pdf DEPENDS ${TEX_DIR}/gmsh.pdf)
  install(FILES ${TEX_DIR}/gmsh.pdf DESTINATION ${GMSH_DOC} OPTIONAL)
endif(TEXI2PDF)

execute_process(COMMAND ${CMAKE_COMMAND} -E echo "${OPT_TEXI}"
                OUTPUT_FILE cmake_options.texi)

if(MAKEINFO AND TEXI2PDF)
  add_custom_target(doc COMMAND ${CMAKE_COMMAND} -E tar zcf
                    ${CMAKE_CURRENT_BINARY_DIR}/gmsh-${GMSH_VERSION}-doc.tgz
                    doc/CREDITS.txt doc/LICENSE.txt doc/VERSIONS.txt
                    doc/gmsh.1 doc/texinfo/gmsh.html doc/texinfo/gmsh.info
                    doc/texinfo/gmsh.pdf doc/texinfo/gmsh.txt
                    COMMAND ${CMAKE_COMMAND} -E remove ${TEX_OBJ}
                    DEPENDS ${TEX_DIR}/gmsh.info ${TEX_DIR}/gmsh.txt
                    ${TEX_DIR}/gmsh.html ${TEX_DIR}/gmsh.pdf
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif(MAKEINFO AND TEXI2PDF)

if(MAKEINFO OR TEXI2PDF)
  add_custom_target(clean_doc COMMAND ${CMAKE_COMMAND} -E remove ${TEX_OBJ})
endif(MAKEINFO OR TEXI2PDF)

if(APPLE AND ENABLE_BUILD_LIB)
  file(READ ${CMAKE_CURRENT_SOURCE_DIR}/utils/misc/gmsh_framework.plist F0)
  string(REPLACE GMSH_VERSION "${GMSH_VERSION}" F1 "${F0}")
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/Info_framework.plist "${F1}")
  get_target_property(LIBNAME lib LOCATION) # depracated
  #set(LIBNAME $<TARGET_FILE:lib>) # FIXME: use this in the future
  add_custom_target(framework DEPENDS lib
    COMMAND ${CMAKE_COMMAND} -E remove_directory Gmsh.framework
    COMMAND ${CMAKE_COMMAND} -E make_directory Gmsh.framework/Headers
    COMMAND ${CMAKE_COMMAND} -E make_directory Gmsh.framework/Resources
    COMMAND ${CMAKE_COMMAND} -E copy ${LIBNAME} Gmsh.framework/Gmsh
    COMMAND ${CMAKE_COMMAND} -E copy Info_framework.plist
                                     Gmsh.framework/Resources/Info.plist
    COMMAND ${CMAKE_COMMAND} -E create_symlink . Gmsh.framework/Headers/gmsh
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  foreach(FILE ${GMSH_API})
    add_custom_command(TARGET framework POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        ${FILE} ${CMAKE_CURRENT_BINARY_DIR}/Gmsh.framework/Headers/
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  endforeach(FILE)
endif(APPLE AND ENABLE_BUILD_LIB)

set(CPACK_PACKAGE_VENDOR "Christophe Geuzaine and Jean-Francois Remacle")
set(CPACK_PACKAGE_VERSION_MAJOR ${GMSH_MAJOR_VERSION})
set(CPACK_PACKAGE_VERSION_MINOR ${GMSH_MINOR_VERSION})
set(CPACK_PACKAGE_VERSION_PATCH ${GMSH_PATCH_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_FILE ${WELCOME_FILE})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "3D finite element mesh generator with built-in CAD engine and post-processor")
set(CPACK_PACKAGE_FILE_NAME gmsh-${GMSH_VERSION}-${GMSH_OS})
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Gmsh")
set(CPACK_RESOURCE_FILE_LICENSE ${LICENSE_FILE})
set(CPACK_RESOURCE_FILE_README ${WELCOME_FILE})
set(CPACK_RESOURCE_FILE_WELCOME ${WELCOME_FILE})
set(CPACK_PACKAGE_EXECUTABLE "gmsh;Gmsh")
set(CPACK_STRIP_FILES TRUE)
set(CPACK_SOURCE_PACKAGE_FILE_NAME gmsh-${GMSH_VERSION}-source)
set(CPACK_SOURCE_GENERATOR TGZ)
set(CPACK_SOURCE_IGNORE_FILES "${CMAKE_CURRENT_BINARY_DIR}" "/CVS/" "/.svn" "~$"
    "DS_Store$" "GmshConfig.h$" "GmshVersion.h$" "/benchmarks/" "/tmp/"
    "/bin/" "/lib/" "/nightly/" "GPATH" "GRTAGS" "GSYMS" "GTAGS" "/HTML/"
    "/projects/"
    "/FunctionSpace/" "/Mesh/meshRecombine*" "/utils/solvers/legacy/"
    "/contrib/3M/" "/contrib/Parasolid/")

if(UNIX)
  # make sure we remove previous installs before doing the next one (on Mac for
  # example "make package; make package_source" would lead to huge file lists
  # getting generated due to the 'Applications' symlink in the bundle)
  set(CPACK_INSTALL_COMMANDS "rm -rf ${CMAKE_CURRENT_BINARY_DIR}/_CPack_Packages")
endif(UNIX)

if(APPLE AND ENABLE_OS_SPECIFIC_INSTALL)
  set(CPACK_GENERATOR Bundle)
  set(CPACK_BUNDLE_NAME Gmsh)
  file(READ ${CMAKE_CURRENT_SOURCE_DIR}/utils/misc/gmsh_app.plist F0)
  string(REPLACE GMSH_VERSION "${GMSH_VERSION}" F1 "${F0}")
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/Info.plist "${F1}")
  set(CPACK_BUNDLE_PLIST ${CMAKE_CURRENT_BINARY_DIR}/Info.plist)
  set(CPACK_BUNDLE_ICON ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/MacIcons.icns)
  if(PACKAGER STREQUAL "geuzaine")
    # codesigning requires CMake >= 3.2
    set(CPACK_BUNDLE_APPLE_CERT_APP "Developer ID Application: Christophe Geuzaine")
  endif(PACKAGER STREQUAL "geuzaine")
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/MacIconsGeo.icns DESTINATION .
          RENAME GmshGeo.icns)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/MacIconsMsh.icns DESTINATION .
          RENAME GmshMsh.icns)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/MacIconsSol.icns DESTINATION .
          RENAME GmshSol.icns)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/MacIconsPos.icns DESTINATION .
          RENAME GmshPos.icns)
  set(CPACK_PACKAGE_ICON ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/MacIcons.icns)
elseif(WIN32 OR CYGWIN)
  set(CPACK_GENERATOR ZIP)
else(APPLE AND ENABLE_OS_SPECIFIC_INSTALL)
  set(CPACK_GENERATOR TGZ)
endif(APPLE AND ENABLE_OS_SPECIFIC_INSTALL)

if(HAVE_PYTHON)
  add_subdirectory(wrappers/gmshpy)
endif(HAVE_PYTHON)

if(ENABLE_WRAP_JAVA)
  if(NOT HAVE_BLAS OR NOT HAVE_LAPACK)
    message(WARNING "Java wrapping samples will not work without BLAS and LAPACK")
  endif(NOT HAVE_BLAS OR NOT HAVE_LAPACK)
  add_subdirectory(wrappers/java)
endif(ENABLE_WRAP_JAVA)

include(CPack)

if(NOT DISABLE_GMSH_TESTS)
  # disabling tests is useful when including this CMakeLists in an external project
  include(CTest)
  file(GLOB_RECURSE TESTFILES
       tutorial/*.geo demos/*.geo benchmarks/?d/*.geo benchmarks/extrude/*.geo)
  foreach(TESTFILE ${TESTFILES})
    # use relative path for cygwin/mingw (the pure win exe built with the mingw
    # compilers does not understand a full cygwin-style path)
    FILE(RELATIVE_PATH TEST ${CMAKE_CURRENT_BINARY_DIR} ${TESTFILE})
    add_test(${TEST} ./gmsh ${TEST} -3 -nopopup -o ./tmp.msh)
  endforeach()
  # if(HAVE_PYTHON)
  #   file(GLOB_RECURSE TESTFILES tutorial/*.py)
  #   foreach(TESTFILE ${TESTFILES})
  #     add_test(NAME ${TESTFILE}
  #              COMMAND ${PYTHON_EXECUTABLE}
  #                      ${TESTFILE} $<CONFIGURATION>)
  #     # sys.path.insert(0, "path/to/your/package")
  #   endforeach()
  # endif(HAVE_PYTHON)
endif(NOT DISABLE_GMSH_TESTS)

message(STATUS "")
message(STATUS "Gmsh ${GMSH_VERSION} has been configured for ${GMSH_OS}")
message(STATUS "")
message(STATUS " * Build options:" ${GMSH_CONFIG_OPTIONS})
message(STATUS " * Build type: " ${CMAKE_BUILD_TYPE})
message(STATUS " * C compiler: " ${CMAKE_C_COMPILER})
message(STATUS " * C++ compiler: " ${CMAKE_CXX_COMPILER})
message(STATUS " * Install prefix: " ${CMAKE_INSTALL_PREFIX})
message(STATUS "")

mark_as_advanced(GMSH_EXTRA_VERSION
                 ACIS_LIB ANN_INC ANN_LIB CAIRO_LIB CAIRO_INC CGNS_INC GMM_INC
                 GMP_INC GMP_LIB MMG3D_INC MMG3D_LIB HDF5_LIB
                 MED_LIB OCC_INC OCC_CONFIG_H SZ_LIB
                 PETSC_LIBS SLEPC_INC SLEPC_INC2 SLEPC_LIB
                 BISON FLEX MAKEINFO TEXI2PDF FLTK_CONFIG_SCRIPT
                 GMSH_EXTERNAL_INCLUDE_DIRS GMSH_EXTERNAL_LIBRARIES)
