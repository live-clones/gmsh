# Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

# if CMAKE_BUILD_TYPE is specified use it; otherwise set the default
# build type to "RelWithDebInfo" ("-O2 -g" with gcc) prior to calling
# project()
if(DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose build type")
else(DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose build type")
endif(DEFINED CMAKE_BUILD_TYPE)

project(gmsh CXX C)

option(ENABLE_ACIS "Enable ACIS geometrical models" ON)
option(ENABLE_ANN "Enable ANN to compute Approximate Nearest Neighbors" ON)
option(ENABLE_APP_BUNDLE "Create .app bundle on Mac when installing" ON)
option(ENABLE_BAMG "Enable Bamg mesh generator" ON)
option(ENABLE_BFGS "Enable BFGS" ON)
option(ENABLE_BLAS_LAPACK "Use BLAS and Lapack for linear algebra" ON)
option(ENABLE_BLOSSOM "Enable Blossom algo (based on MATCH and concorde97)" ON)
option(ENABLE_CGNS "Enable CGNS mesh export" OFF)
option(ENABLE_CHACO "Enable Chaco mesh partitioner" ON)
option(ENABLE_DINTEGRATION "Enable discrete integration and levelsets" ON)
option(ENABLE_FLTK "Build FLTK GUI" ON)
option(ENABLE_FL_TREE "Enable FLTK tree browser widget" ON)
option(ENABLE_FOURIER_MODEL "Enable Fourier geometrical models" OFF)
option(ENABLE_GMM "Enable GMM linear algebra solvers" ON)
option(ENABLE_GRAPHICS "Compile-in OpenGL graphics even if there is no GUI" OFF)
option(ENABLE_KBIPACK "Enable Kbipack for homology solver" ON)
option(ENABLE_MATHEX "Enable MathEx expression parser" ON)
option(ENABLE_MED "Enable MED mesh and post-processing file formats" ON)
option(ENABLE_MESH "Build the mesh module" ON)
option(ENABLE_METIS "Enable Metis mesh partitioner" ON)
option(ENABLE_MMG3D "Enable 3D Mobile Mesh Generation" ON)
option(ENABLE_MPEG_ENCODE "Enable built-in MPEG encoder" ON)
option(ENABLE_MPI "Enable MPI parallelization" OFF)
option(ENABLE_MSVC_STATIC_RUNTIME "Use static Visual C++ runtime" OFF)
option(ENABLE_NATIVE_FILE_CHOOSER "Enable native file chooser in GUI" ON)
option(ENABLE_NETGEN "Enable Netgen mesh generator" ON)
option(ENABLE_OCC "Enable Open CASCADE geometrical models" ON)
option(ENABLE_OSMESA "Use OSMesa for offscreen rendering" OFF)
option(ENABLE_PARSER "Build the GEO file parser" ON)
option(ENABLE_PETSC "Enable PETSc linear algebra solvers" ON)
option(ENABLE_PLUGINS "Build the post-processing plugins" ON)
option(ENABLE_POST "Build the post-processing module" ON)
option(ENABLE_QT "Build proof-of-concept QT GUI" OFF)
option(ENABLE_RBF "Enable RBF project" OFF)
option(ENABLE_SALOME "Enable Salome routines for CAD healing" ON)
option(ENABLE_SLEPC "Enable SLEPc eigensolvers" ON)
option(ENABLE_SOLVER "Enable solver components" ON)
option(ENABLE_SWIG "Build Swig wrappers" ON)
option(ENABLE_TAUCS "Enable Taucs linear algebra solver" ON)
option(ENABLE_TETGEN "Enable Tetgen mesh generator" ON)
option(ENABLE_TETGEN_NEW "Enable experimental version of Tetgen" OFF)

set(GMSH_MAJOR_VERSION 2)
set(GMSH_MINOR_VERSION 5)
set(GMSH_PATCH_VERSION 1)
set(GMSH_EXTRA_VERSION "" CACHE STRING "Gmsh extra version string")

set(GMSH_VERSION "${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION}")
set(GMSH_VERSION "${GMSH_VERSION}.${GMSH_PATCH_VERSION}${GMSH_EXTRA_VERSION}")
set(GMSH_SHORT_LICENSE "GNU General Public License")

set(GMSH_API
  ${CMAKE_CURRENT_BINARY_DIR}/Common/GmshConfig.h 
  ${CMAKE_CURRENT_BINARY_DIR}/Common/GmshVersion.h
  Common/Gmsh.h Common/Context.h Common/GmshDefines.h Common/GmshMessage.h
    Common/VertexArray.h Common/Octree.h Common/OctreeInternals.h
  Numeric/Numeric.h Numeric/GaussIntegration.h Numeric/polynomialBasis.h
    Numeric/JacobianBasis.h Numeric/fullMatrix.h
    Numeric/simpleFunction.h Numeric/cartesian.h
  Geo/GModel.h Geo/GEntity.h Geo/GPoint.h Geo/GVertex.h Geo/GEdge.h 
    Geo/GFace.h Geo/GRegion.h Geo/GEdgeLoop.h Geo/GEdgeCompound.h 
    Geo/GFaceCompound.h Geo/GRegionCompound.h Geo/GRbf.h Geo/MVertex.h
    Geo/MVertexBoundaryLayerData.h Geo/MEdge.h 
    Geo/MFace.h Geo/MElement.h Geo/MPoint.h Geo/MLine.h Geo/MTriangle.h 
    Geo/MQuadrangle.h Geo/MTetrahedron.h Geo/MHexahedron.h Geo/MPrism.h 
    Geo/MPyramid.h Geo/MElementCut.h Geo/discreteVertex.h Geo/discreteEdge.h
    Geo/discreteFace.h Geo/discreteRegion.h Geo/SPoint2.h Geo/SPoint3.h
    Geo/SVector3.h Geo/STensor3.h Geo/SBoundingBox3d.h Geo/Pair.h Geo/Range.h 
    Geo/SOrientedBoundingBox.h Geo/CellComplex.h Geo/ChainComplex.h Geo/Cell.h
    Geo/Homology.h Geo/partitionEdge.h Geo/CGNSOptions.h Geo/gmshLevelset.h
  Mesh/meshGEdge.h Mesh/meshGFace.h Mesh/meshGFaceOptimize.h Mesh/meshPartition.h
    Mesh/meshGFaceDelaunayInsertion.h Mesh/Levy3D.h Mesh/meshPartitionOptions.h
  Numeric/mathEvaluator.h
  Solver/dofManager.h Solver/femTerm.h Solver/laplaceTerm.h Solver/elasticityTerm.h
    Solver/crossConfTerm.h Solver/orthogonalTerm.h
    Solver/linearSystem.h Solver/linearSystemGMM.h Solver/linearSystemCSR.h 
    Solver/linearSystemFull.h Solver/elasticitySolver.h
  Post/PView.h Post/PViewData.h Plugin/PluginManager.h Post/OctreePost.h
  Graphics/drawContext.h
  contrib/kbipack/gmp_normal_form.h contrib/kbipack/gmp_matrix.h 
    contrib/kbipack/gmp_blas.h contrib/kbipack/mpz.h
  contrib/DiscreteIntegration/Integration3D.h
  contrib/MathEx/mathex.h)

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

if(MSVC)
  # remove annoying warning about bool/int cast performance
  set(GMSH_CONFIG_PRAGMAS "#pragma warning(disable:4800)")
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
endif(MSVC)

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
    find_library(FOUND_LIB ${LIB} PATHS ${PATH} PATH_SUFFIXES ${SUFFIX})
    if(FOUND_LIB)
      list(APPEND ${VARNAME} ${FOUND_LIB})
    endif(FOUND_LIB)
    set(FOUND_LIB FOUND_LIB-NOTFOUND CACHE INTERNAL "")
    # unset(FOUND_LIB CACHE) # cleaner, but only available in cmake >= 2.6.4
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

# check if the machine is 64 bits (this is more reliable than using
# CMAKE_SIZEOF_VOID_P, which does not seem to work e.g. on some Suse
# machines)
check_type_size("void*" SIZEOF_VOID_P)
if(SIZEOF_VOID_P EQUAL 8)
  set_config_option(HAVE_64BIT_SIZE_T "Have64BitSizeT")
endif(SIZEOF_VOID_P EQUAL 8)

if(ENABLE_BLAS_LAPACK)
  if(MSVC)
    # on Windows with Visual C++ try really hard to find blas/lapack
    # *without* requiring a Fortran compiler: 1) try to find the Intel
    # MKL libs using the standard search path; if not found 2) try to
    # get the reference blas/lapack libs (useful for users with no
    # Fortran compiler and no MKL license, who can just download our
    # precompiled "gmsh-dep" package)
    if(HAVE_64BIT_SIZE_T)
      set(MKL_PATH em64t/lib)
    else(HAVE_64BIT_SIZE_T)
      set(MKL_PATH ia32/lib)
    endif(HAVE_64BIT_SIZE_T)
    set(MKL_LIBS_REQUIRED libguide40 mkl_intel_c mkl_intel_thread mkl_core)
    find_all_libraries(LAPACK_LIBRARIES MKL_LIBS_REQUIRED "" ${MKL_PATH})
    if(LAPACK_LIBRARIES)
      set_config_option(HAVE_BLAS "Blas(IntelMKL)")
      set_config_option(HAVE_LAPACK "Lapack(IntelMKL)")
    else(LAPACK_LIBRARIES)
      set(REFLAPACK_LIBS_REQUIRED lapack blas g2c gcc)
      find_all_libraries(LAPACK_LIBRARIES REFLAPACK_LIBS_REQUIRED "" "")
      if(LAPACK_LIBRARIES)
        set_config_option(HAVE_BLAS "Blas(Ref)")
        set_config_option(HAVE_LAPACK "Lapack(Ref)")
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
      #match lapack 9.0 on 64bit
      set(MKL_LIBS_REQUIRED mkl_lapack mkl_em64t guide)
      find_all_libraries(LAPACK_LIBRARIES MKL_LIBS_REQUIRED "" ${MKL_PATH})
    endif(NOT LAPACK_LIBRARIES)
    if(LAPACK_LIBRARIES)
      set_config_option(HAVE_BLAS "Blas(IntelMKL)")
      set_config_option(HAVE_LAPACK "Lapack(IntelMKL)")
    else(LAPACK_LIBRARIES)
      # on Linux also try to find ATLAS without a Fortran compiler,
      # because cmake ships with a buggy FindBLAS e.g. on Ubuntu Lucid
      # Lynx
      set(ATLAS_LIBS_REQUIRED lapack f77blas cblas atlas)
      find_all_libraries(LAPACK_LIBRARIES ATLAS_LIBS_REQUIRED "" "")
      if(LAPACK_LIBRARIES)
        set_config_option(HAVE_BLAS "Blas(ATLAS)")
        set_config_option(HAVE_LAPACK "Lapack(ATLAS)")
      endif(LAPACK_LIBRARIES)
    endif(LAPACK_LIBRARIES)
  elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
    # on SunOS we know blas and lapack are available in sunperf
    set(LAPACK_FLAGS -library=sunperf)
    set_config_option(HAVE_BLAS "Blas(SubPerf)")
    set_config_option(HAVE_LAPACK "Lapack(SunPerf)")
  elseif(APPLE)
    # on Mac we also know that blas and lapack are available
    set(LAPACK_LIBRARIES "-framework vecLib")
    set_config_option(HAVE_BLAS "Blas(VecLib)")
    set_config_option(HAVE_LAPACK "Lapack(VecLib)")
  endif(MSVC)
  if(NOT HAVE_BLAS OR NOT HAVE_LAPACK)
    # if we haven't found blas and lapack without using the standard
    # cmake tests, do it (this requires a working Fortran compiler)
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
    message("WARNING: Could not find Blas or Lapack: most meshing algorithms "
            "will not be functional")
  endif(NOT HAVE_BLAS OR NOT HAVE_LAPACK)
endif(ENABLE_BLAS_LAPACK)

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
  # first, try to use fltk-config for fltk >= 1.3 (FindFLTK is buggy
  # on Unix, where e.g. xft and xinerama options are not dealt with)
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
      list(APPEND EXTERNAL_INCLUDES ${FLTK_INCLUDE_DIR} ${FLTK_INCLUDE_DIR}/FL/images
           ${FLTK_INCLUDE_DIR}/jpeg ${FLTK_INCLUDE_DIR}/zlib ${FLTK_INCLUDE_DIR}/png)
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
  if(HAVE_FLTK)
    if(ENABLE_NATIVE_FILE_CHOOSER)
      if(NOT FLTK_VERSION OR FLTK_VERSION EQUAL 1.1)
        add_subdirectory(contrib/NativeFileChooser)
        include_directories(contrib/NativeFileChooser)
        add_definitions(-DFLTK1)
      endif(NOT FLTK_VERSION OR FLTK_VERSION EQUAL 1.1)
      set_config_option(HAVE_NATIVE_FILE_CHOOSER "NativeFileChooser")
    endif(ENABLE_NATIVE_FILE_CHOOSER)
    if(ENABLE_FL_TREE)
      if(NOT FLTK_VERSION OR FLTK_VERSION EQUAL 1.1)
        add_subdirectory(contrib/Fl_Tree)
        include_directories(contrib/Fl_Tree)
      endif(NOT FLTK_VERSION OR FLTK_VERSION EQUAL 1.1)
      set_config_option(HAVE_FL_TREE "FlTree")
    endif(ENABLE_FL_TREE)
  endif(HAVE_FLTK)
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

if(HAVE_FLTK OR HAVE_QT OR ENABLE_GRAPHICS)
  if(NOT HAVE_MESH OR NOT HAVE_POST OR NOT HAVE_PLUGINS)
    message(SEND_ERROR "Cannot compile GUI without Mesh, Post or Plugin modules")
  endif(NOT HAVE_MESH OR NOT HAVE_POST OR NOT HAVE_PLUGINS)
  # get jpeg lib
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
  # get zlib
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
  # get png lib
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
  find_package(OpenGL REQUIRED)
  if(OPENGL_GLU_FOUND)
    add_subdirectory(Graphics)
    set_config_option(HAVE_OPENGL "OpenGL")
  else(OPENGL_GLU_FOUND)
    message(SEND_ERROR "Could not find GLU: disabling OpenGL support")
  endif(OPENGL_GLU_FOUND)
endif(HAVE_FLTK OR HAVE_QT OR ENABLE_GRAPHICS)

if(ENABLE_ANN)
  add_subdirectory(contrib/ANN)
  include_directories(contrib/ANN/include)
  set_config_option(HAVE_ANN "Ann")
endif(ENABLE_ANN)

if(ENABLE_BLOSSOM)
  add_subdirectory(contrib/blossom)
  include_directories(contrib/blossom/MATCH contrib/blossom/concorde97
                      contrib/blossom/concorde97/INCLUDE)
  set_config_option(HAVE_BLOSSOM "Blossom")
endif(ENABLE_BLOSSOM)

if(ENABLE_CHACO)
  add_subdirectory(contrib/Chaco)
  include_directories(contrib/Chaco/main)
  set_config_option(HAVE_CHACO "Chaco")
endif(ENABLE_CHACO)

if(ENABLE_BFGS)
  add_subdirectory(contrib/lbfgs)
  include_directories(contrib/lbfgs)
  set_config_option(HAVE_BFGS "Bfgs")
endif(ENABLE_BFGS)

if(ENABLE_DINTEGRATION)
  add_subdirectory(contrib/DiscreteIntegration)
  include_directories(contrib/DiscreteIntegration)
  set_config_option(HAVE_DINTEGRATION "DIntegration")
endif(ENABLE_DINTEGRATION)

if(ENABLE_GMM)
  include_directories(contrib/gmm)
  set_config_option(HAVE_GMM "Gmm")
endif(ENABLE_GMM)

if(ENABLE_KBIPACK)
  find_library(GMP_LIB gmp)
  if(GMP_LIB)
    find_path(GMP_INC "gmp.h" PATH_SUFFIXES src include)
    if(GMP_INC)
      set_config_option(HAVE_GMP "GMP")
      list(APPEND EXTERNAL_LIBRARIES ${GMP_LIB})
      list(APPEND EXTERNAL_INCLUDES ${GMP_INC})
      add_subdirectory(contrib/kbipack)
      include_directories(contrib/kbipack)
      set_config_option(HAVE_KBIPACK "Kbipack")
    endif(GMP_INC)
  endif(GMP_LIB)
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
     cmake_force_cxx_compiler(${MPI_COMPILER} "MPI C++ Compiler")
   endif(MPI_FOUND)
endif(ENABLE_MPI)

if(ENABLE_MPEG_ENCODE)
  add_subdirectory(contrib/mpeg_encode)
  include_directories(contrib/mpeg_encode/headers)
  set_config_option(HAVE_MPEG_ENCODE "Mpeg")
endif(ENABLE_MPEG_ENCODE)

if(ENABLE_METIS)
  add_subdirectory(contrib/Metis)
  include_directories(contrib/Metis)
  set_config_option(HAVE_METIS "Metis")
  message("WARNING: By including Metis you have to comply with Metis' special "
          "licensing requirements stated in contrib/Metis/README.txt.")
endif(ENABLE_METIS)

if(HAVE_MESH)
  if(ENABLE_NETGEN)
    add_subdirectory(contrib/Netgen)
    include_directories(contrib/Netgen contrib/Netgen/libsrc/include 
                        contrib/Netgen/libsrc/interface)
    set_config_option(HAVE_NETGEN "Netgen")
    add_definitions(-DNO_PARALLEL_THREADS)
  endif(ENABLE_NETGEN)

  if(ENABLE_BAMG)
    add_subdirectory(contrib/bamg)
    include_directories(contrib/bamg contrib/bamg/bamglib)
    set_config_option(HAVE_BAMG "Bamg")
  endif(ENABLE_BAMG)

  if(ENABLE_MMG3D)
    add_subdirectory(contrib/mmg3d)
    include_directories(contrib/mmg3d/build/sources)
    set_config_option(HAVE_MMG3D "Mmg3d")
  endif(ENABLE_MMG3D)

  if(ENABLE_TETGEN_NEW AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/TetgenNew/tetgen.h)
    add_subdirectory(contrib/TetgenNew)
    include_directories(contrib/TetgenNew)
    set_config_option(HAVE_TETGEN "Tetgen(New)")
    add_definitions(-DTETLIBRARY)
    message("WARNING: You are including an experimental version of Tetgen "
            "that is KNOWN TO BE BUGGY on 64 bits archs and on WIN32/MSVC.")
  elseif(ENABLE_TETGEN AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/Tetgen/tetgen.h)
    add_subdirectory(contrib/Tetgen)
    include_directories(contrib/Tetgen)
    set_config_option(HAVE_TETGEN "Tetgen")
    add_definitions(-DTETLIBRARY)
    message("WARNING: By including Tetgen you have to comply with Tetgen's "
            "special licensing requirements stated in contrib/Tetgen/LICENSE.")
  endif(ENABLE_TETGEN_NEW AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/TetgenNew/tetgen.h)
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
      find_library(CGNS_LIB cgns)
      if(CGNS_LIB)
        set_config_option(HAVE_LIBCGNS "Cgns")
        list(APPEND EXTERNAL_LIBRARIES ${CGNS_LIB})
      endif(CGNS_LIB)
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
  endif(HDF5_LIB)
endif(ENABLE_MED OR ENABLE_CGNS)

if(ENABLE_TAUCS)
  if(NOT HAVE_METIS)
    message(SEND_ERROR "You have to enable METIS in order to use TAUCS")
  endif(NOT HAVE_METIS)
  find_library(TAUCS_LIB taucs PATH_SUFFIXES lib)
  if(TAUCS_LIB)
    find_path(TAUCS_INC "taucs.h" PATH_SUFFIXES src include taucs)
    if(TAUCS_INC)
      set_config_option(HAVE_TAUCS "Taucs")
      add_definitions(-DTAUCS_CILK)
      list(APPEND EXTERNAL_LIBRARIES ${TAUCS_LIB})
      list(APPEND EXTERNAL_INCLUDES ${TAUCS_INC})
    endif(TAUCS_INC)
  endif(TAUCS_LIB)
endif(ENABLE_TAUCS)

if(ENABLE_PETSC)
  set(ENV_PETSC_DIR $ENV{PETSC_DIR})
  set(ENV_PETSC_ARCH $ENV{PETSC_ARCH})
  if(EXISTS ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/conf/petscvariables)
    # old-style PETSc installations (using PETSC_DIR and PETSC_ARCH)
    set_config_option(HAVE_PETSC "PETSc")
    file(STRINGS ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/conf/petscvariables 
         PETSC_VARIABLES NEWLINE_CONSUME)
    # find include directories
    list(APPEND EXTERNAL_INCLUDES ${ENV_PETSC_DIR}/include)
    list(APPEND EXTERNAL_INCLUDES ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/include)
    string(REGEX MATCH "PACKAGES_INCLUDES = [^\n\r]*" PETSC_PACKAGES_INCLUDES
           ${PETSC_VARIABLES})
    if(PETSC_PACKAGES_INCLUDES)
      string(REPLACE "PACKAGES_INCLUDES = " "" PETSC_PACKAGES_INCLUDES
             ${PETSC_PACKAGES_INCLUDES})
      if(PETSC_PACKAGES_INCLUDES)
        string(REPLACE "-I" "" PETSC_PACKAGES_INCLUDES ${PETSC_PACKAGES_INCLUDES})
        string(REPLACE " " ";" PETSC_PACKAGES_INCLUDES ${PETSC_PACKAGES_INCLUDES})
        foreach(VAR ${PETSC_PACKAGES_INCLUDES})
          list(APPEND EXTERNAL_INCLUDES ${VAR})
        endforeach(VAR)
      endif(PETSC_PACKAGES_INCLUDES)
    endif(PETSC_PACKAGES_INCLUDES)
    # find libraries (<= 3.0)
    set(PETSC_LIBS_REQUIRED petscksp petscdm petscmat petscvec petsc)
    find_all_libraries(PETSC_LIBS PETSC_LIBS_REQUIRED 
                       ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib "")
    # petsc 3.1 creates only one library (libpetsc)
    if(NOT PETSC_LIBS)
      find_library(PETSC_LIBS petsc PATHS ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib)
    endif(NOT PETSC_LIBS)
    # find slepc (needs to be linked in before petsc)
    if(ENABLE_SLEPC)
      set(ENV_SLEPC_DIR $ENV{SLEPC_DIR})
      find_library(SLEPC_LIB slepc PATHS ${ENV_SLEPC_DIR}/${ENV_PETSC_ARCH}/lib)
      if(SLEPC_LIB)
        find_path(SLEPC_INC "slepc.h" PATHS ${ENV_SLEPC_DIR} PATH_SUFFIXES include 
                  ${ENV_PETSC_ARCH}/include include/slepc)
        if(SLEPC_INC)
          set_config_option(HAVE_SLEPC "SLEPc")
          list(APPEND EXTERNAL_LIBRARIES ${SLEPC_LIB})
          list(APPEND EXTERNAL_INCLUDES ${SLEPC_INC}) 
        endif(SLEPC_INC)
      endif(SLEPC_LIB)
      if(NOT HAVE_SLEPC AND NOT ENV_SLEPC_DIR)
         message("WARNING: Export SLEPC_DIR before calling cmake")
      endif(NOT HAVE_SLEPC AND NOT ENV_SLEPC_DIR)
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
      list(APPEND EXTERNAL_LIBRARIES "${PLIBS_BASIC}")
    endif(PLIBS_BASIC)
    string(REGEX MATCH "PCC_LINKER_LIBS = [^\n\r]*" LLIBS ${PETSC_VARIABLES})
    if(LLIBS)
      string(REPLACE "PCC_LINKER_LIBS = " "" LLIBS ${LLIBS})
      string(STRIP ${LLIBS} LLIBS)
      list(APPEND EXTERNAL_LIBRARIES "${LLIBS}")
    endif(LLIBS)
  else(EXISTS ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/conf/petscvariables)
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
  endif(EXISTS ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/conf/petscvariables)
  if(NOT HAVE_PETSC AND NOT ENV_PETSC_DIR)
     message("WARNING: Export PETSC_DIR before calling cmake")
  endif(NOT HAVE_PETSC AND NOT ENV_PETSC_DIR)
  if(NOT HAVE_PETSC AND NOT ENV_PETSC_ARCH)
     message("WARNING: Export PETSC_ARCH before calling cmake")
  endif(NOT HAVE_PETSC AND NOT ENV_PETSC_ARCH)
endif(ENABLE_PETSC)

if(ENABLE_OCC)
  if(WIN32 OR CYGWIN)
    set(OCC_SYS_NAME win32)
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
      TKAdvTools TKMath TKernel)
  list(LENGTH OCC_LIBS_REQUIRED NUM_OCC_LIBS_REQUIRED)
  set(OCC_LIBS)
  foreach(OCC ${OCC_LIBS_REQUIRED})
    find_library(OCC_LIB ${OCC} PATHS ENV CASROOT PATH_SUFFIXES lib 
                 ${OCC_SYS_NAME}/lib ${OCC_SYS_NAME}/vc8/lib)
    if(OCC_LIB)
      list(APPEND OCC_LIBS ${OCC_LIB})
    else(OCC_LIB)
      message(STATUS "OCC lib " ${OCC} " not Found")
    endif(OCC_LIB)
    set(OCC_LIB OCC_LIB-NOTFOUND CACHE INTERNAL "")
    # unset(OCC_LIB CACHE) # cleaner, but only available in cmake >= 2.6.4
  endforeach(OCC)
  list(LENGTH OCC_LIBS NUM_OCC_LIBS)
  if(NUM_OCC_LIBS EQUAL NUM_OCC_LIBS_REQUIRED)
    find_path(OCC_INC "BRep_Tool.hxx" PATHS ENV CASROOT PATH_SUFFIXES inc 
              include opencascade)
    if(OCC_INC)
      set_config_option(HAVE_OCC "OpenCascade")
      list(APPEND EXTERNAL_LIBRARIES ${OCC_LIBS})
      list(APPEND EXTERNAL_INCLUDES ${OCC_INC})
      if(HAVE_64BIT_SIZE_T)
        add_definitions(-D_OCC64)
      endif(HAVE_64BIT_SIZE_T)
      if(CYGWIN)
        list(APPEND EXTERNAL_LIBRARIES "winspool")
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
  if(HAVE_OCC AND ENABLE_SALOME)
    add_subdirectory(contrib/Salome)
    include_directories(contrib/Salome)
    add_definitions(-DOCCGEOMETRY)
    set_config_option(HAVE_SALOME "Salome")
  endif(HAVE_OCC AND ENABLE_SALOME)
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

if(ENABLE_OSMESA)
  find_library(OSMESA_LIB OSMesa)
  if(OSMESA_LIB)
    set_config_option(HAVE_OSMESA "OSMesa")
    list(APPEND EXTERNAL_LIBRARIES ${OSMESA_LIB})
  endif(OSMESA_LIB)
endif(ENABLE_OSMESA)

if(ENABLE_SWIG)
  find_package(SWIG)
  find_package(PythonLibs)
  if(SWIG_FOUND AND PYTHONLIBS_FOUND)
    message(STATUS "Found SWIG version " ${SWIG_VERSION})
    string(SUBSTRING ${SWIG_VERSION} 0 1 SWIG_MAJOR_VERSION)
    if(SWIG_MAJOR_VERSION EQUAL 1)
      message("WARNING: Python bindings require SWIG >= 2: disabling Python")
    else(SWIG_MAJOR_VERSION EQUAL 1)
      set_config_option(HAVE_SWIG "Swig")
    endif(SWIG_MAJOR_VERSION EQUAL 1)
  endif(SWIG_FOUND AND PYTHONLIBS_FOUND)
endif(ENABLE_SWIG)

check_function_exists(vsnprintf HAVE_VSNPRINTF)
if(NOT HAVE_VSNPRINTF)
  set_config_option(HAVE_NO_VSNPRINTF "NoVsnprintf")
endif(NOT HAVE_VSNPRINTF)

check_include_file(sys/socket.h HAVE_SYS_SOCKET_H)
if(HAVE_SYS_SOCKET_H)
  set(CMAKE_EXTRA_INCLUDE_FILES sys/socket.h)
endif(HAVE_SYS_SOCKET_H)

check_type_size(socklen_t SOCKLEN_T_SIZE)
if(NOT SOCKLEN_T_SIZE)
  set_config_option(HAVE_NO_SOCKLEN_T "NoSocklenT")
endif(NOT SOCKLEN_T_SIZE)
set(CMAKE_EXTRA_INCLUDE_FILES)

check_include_file(dlfcn.h DLFCN_H)
if(DLFCN_H)
  set_config_option(HAVE_DLOPEN "Dlopen")
  list(APPEND EXTERNAL_LIBRARIES ${CMAKE_DL_LIBS})
endif(DLFCN_H)

if(UNIX)
  # do not optimize some files on Unix
  file(GLOB_RECURSE NON_OPTIMIZED_SRC Common/GmshPredicates.cpp Mesh/BDS.cpp
       Parser/Gmsh.tab.cpp contrib/Tetgen*/*.cxx)
  set_source_files_properties(${NON_OPTIMIZED_SRC} COMPILE_FLAGS "-O0")
endif(UNIX)

if(MSVC)
  add_definitions(-D_USE_MATH_DEFINES -DNOMINMAX 
                  -D_CRT_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_DEPRECATE)
  set(GMSH_SRC ${GMSH_SRC};Fltk/Win32Icon.rc)
endif(MSVC)

if(WIN32 OR CYGWIN)
  list(APPEND EXTERNAL_LIBRARIES wsock32 ws2_32)
endif(WIN32 OR CYGWIN)

list(SORT CONFIG_OPTIONS)
set(GMSH_CONFIG_OPTIONS "")
foreach(OPT ${CONFIG_OPTIONS})
  set(GMSH_CONFIG_OPTIONS "${GMSH_CONFIG_OPTIONS} ${OPT}")
endforeach(OPT)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Common/GmshConfig.h.in 
               ${CMAKE_CURRENT_BINARY_DIR}/Common/GmshConfig.h)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Common/GmshVersion.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/Common/GmshVersion.h)

# process cmake environment variables so we can append them to the -I
# include commands. This is not recommended (we should only use the
# cache variables) but it is very convenient: otherwise we have to
# remember providing the -D... options to cmake for each new build.
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

# we could specify include dirs more selectively, but this is simpler
include_directories(Common Fltk Geo Graphics Mesh Solver Numeric Parser
  Plugin Post Qt ${EXTERNAL_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR}/Common)

# set this for external codes that might include this CMakeList file
set(GMSH_EXTERNAL_INCLUDE_DIRS ${EXTERNAL_INCLUDES} CACHE 
    STRING "External include directories" FORCE)
set(GMSH_EXTERNAL_LIBRARIES ${EXTERNAL_LIBRARIES} CACHE 
    STRING "External libraries" FORCE)

# group sources for easier navigation in IDEs
foreach(DIR ${GMSH_DIRS})
  source_group(${DIR} REGULAR_EXPRESSION ${DIR}/.*)
endforeach(DIR)

# static library target: we don't build it by default (we could then
# create the gmsh target by linking with it) because doing so slows
# down the compile/link development a lot: running ranlib+ar on a
# large static lib every time we recompile is frustratingly
# slow. Instead, we build the gmsh target directly from the object
# files. This is much faster but has one side effect: when we actually
# want to build the lib we need to recompile everything (the first
# time--it's a separate target)
add_library(lib STATIC EXCLUDE_FROM_ALL ${GMSH_SRC})
set_target_properties(lib PROPERTIES OUTPUT_NAME Gmsh)
if(MSVC)
  set_target_properties(lib PROPERTIES DEBUG_POSTFIX d) 
  if(ENABLE_MSVC_STATIC_RUNTIME)
    set_target_properties(lib PROPERTIES LINK_FLAGS_RELEASE "/nodefaultlib:LIBCMT")
  endif(ENABLE_MSVC_STATIC_RUNTIME)
endif(MSVC)

# shared library target: we don't build it by default either
add_library(shared SHARED EXCLUDE_FROM_ALL ${GMSH_SRC})
set_target_properties(shared PROPERTIES OUTPUT_NAME Gmsh)
if(HAVE_LAPACK AND LAPACK_FLAGS)
  set_target_properties(shared PROPERTIES LINK_FLAGS ${LAPACK_FLAGS})
endif(HAVE_LAPACK AND LAPACK_FLAGS)
if(MSVC AND ENABLE_MSVC_STATIC_RUNTIME)
  message("WARNING: By enabling ENABLE_MSVC_STATIC_RUNTIME, shared library wont link. "
          "Change in msvc /MT flag to /MD in the shared project properties")
endif(MSVC AND ENABLE_MSVC_STATIC_RUNTIME)		  
target_link_libraries(shared ${LINK_LIBRARIES})

# binary targets
if(HAVE_FLTK)
  add_executable(gmsh WIN32 Fltk/Main.cpp ${GMSH_SRC})
  add_executable(gmsh_dynamic EXCLUDE_FROM_ALL Fltk/Main.cpp)
  target_link_libraries(gmsh_dynamic shared)
elseif(HAVE_QT)
  qt4_wrap_cpp(GMSH_MOC_SRC ${GMSH_MOC_HDR})
  add_executable(gmsh WIN32 Qt/Main.cpp ${GMSH_SRC} ${GMSH_MOC_SRC})
else(HAVE_FLTK)
  add_executable(gmsh Common/Main.cpp ${GMSH_SRC})
  add_executable(gmsh_dynamic EXCLUDE_FROM_ALL Common/Main.cpp)
  target_link_libraries(gmsh_dynamic shared)
endif(HAVE_FLTK)
target_link_libraries(gmsh ${LINK_LIBRARIES})

# increase stack to 16Mb on Windows to avoid overflows in recursive
# tet classification for large 3D Delaunay grids + force static
# linking of system libraries with cygwin/mingw (to ease distribution 
# andspeed up app startup time)
if(WIN32 AND NOT MSVC OR CYGWIN)
  if(HAVE_64BIT_SIZE_T)
    set_target_properties(gmsh PROPERTIES LINK_FLAGS 
      "-Wl,--stack,16777216 -mwindows -static")
  else(HAVE_64BIT_SIZE_T)
    set_target_properties(gmsh PROPERTIES LINK_FLAGS 
      "-Wl,--stack,16777216 ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/Win32Icon.res -mwindows -static")
  endif(HAVE_64BIT_SIZE_T)
  # remove stupid -Wl,-Bdynamic flags
  set(CMAKE_EXE_LINK_DYNAMIC_C_FLAGS)
  set(CMAKE_EXE_LINK_DYNAMIC_CXX_FLAGS)
elseif(MSVC)
  set_target_properties(gmsh PROPERTIES LINK_FLAGS "/STACK:16777216")
endif(WIN32 AND NOT MSVC OR CYGWIN)

add_subdirectory(gmshpy)

find_program(BISON bison)
find_program(FLEX flex)
if(BISON AND FLEX)
  add_custom_target(parser 
                    COMMAND ${BISON} -p gmsh_yy --output Gmsh.tab.cpp -d Gmsh.y
                    COMMAND ${FLEX} -P gmsh_yy -o Gmsh.yy.cpp Gmsh.l
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Parser)
endif(BISON AND FLEX)

if(UNIX)
  # cannot use cmake's file search functions here (they would only
  # find files existing at configuration time)
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
file(GLOB TUTORIAL_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tutorial/?*.*)
file(GLOB DEMO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/demos/?*.*)
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
  set(GMSH_BIN .)
  set(GMSH_DOC .)
  set(GMSH_MAN .)
  if(CYGWIN)
    unix2dos(GMSH_API)
    unix2dos(WELCOME_FILE)
    unix2dos(LICENSE_FILE)
    unix2dos(CREDITS_FILE)
    unix2dos(TUTORIAL_FILES)
    unix2dos(DEMO_FILES)
  endif(CYGWIN)
elseif(APPLE AND ENABLE_APP_BUNDLE)
  # set these so that the files get installed nicely in the MacOSX
  # .app bundle
  set(GMSH_BIN ../MacOS)
  set(GMSH_DOC ../../..)
  set(GMSH_MAN ../../..)
else(WIN32 OR CYGWIN)
  set(GMSH_BIN bin)
  set(GMSH_DOC share/doc/gmsh)
  set(GMSH_MAN share/man/man1)
endif(WIN32 OR CYGWIN)

# mark targets as optional so we can install them separately if needed
# (e.g. "make lib" or "make shared" followed by "make install/fast")
install(TARGETS gmsh DESTINATION ${GMSH_BIN} OPTIONAL)
install(TARGETS lib shared DESTINATION lib OPTIONAL)
install(FILES ${GMSH_API} DESTINATION include/gmsh)
install(FILES ${WELCOME_FILE} DESTINATION ${GMSH_DOC} RENAME README.txt)
install(FILES ${LICENSE_FILE} DESTINATION ${GMSH_DOC})
install(FILES ${CREDITS_FILE} DESTINATION ${GMSH_DOC})
install(FILES ${TUTORIAL_FILES} DESTINATION ${GMSH_DOC}/tutorial)
install(FILES ${DEMO_FILES} DESTINATION ${GMSH_DOC}/demos)
if(UNIX AND NOT CYGWIN)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/gmsh.1 DESTINATION ${GMSH_MAN})
endif(UNIX AND NOT CYGWIN)

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
                     COMMAND ${MAKEINFO} --html --no-split
                     ARGS ${TEX_DIR}/gmsh.texi WORKING_DIRECTORY ${TEX_DIR})
  add_custom_target(html DEPENDS ${TEX_DIR}/gmsh.html)
  install(FILES ${TEX_DIR}/gmsh.html DESTINATION ${GMSH_DOC} OPTIONAL)
endif(MAKEINFO)

find_program(TEXI2PDF texi2pdf)
if(TEXI2PDF)
  add_custom_command(OUTPUT ${TEX_DIR}/gmsh.pdf DEPENDS ${TEX_SRC} 
                     COMMAND ${TEXI2PDF} ARGS ${TEX_DIR}/gmsh.texi 
                     WORKING_DIRECTORY ${TEX_DIR})
  add_custom_target(pdf DEPENDS ${TEX_DIR}/gmsh.pdf)
  install(FILES ${TEX_DIR}/gmsh.pdf DESTINATION ${GMSH_DOC} OPTIONAL)
endif(TEXI2PDF)

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

if(APPLE)
  file(READ ${CMAKE_CURRENT_SOURCE_DIR}/utils/misc/gmsh_framework.plist F0)
  string(REPLACE GMSH_VERSION "${GMSH_VERSION}" F1 "${F0}")
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/Info_framework.plist "${F1}")
  get_target_property(LIBNAME lib LOCATION)
  add_custom_target(framework DEPENDS lib
    COMMAND ${CMAKE_COMMAND} -E remove_directory Gmsh.framework
    COMMAND ${CMAKE_COMMAND} -E make_directory Gmsh.framework/Versions/A/Headers
    COMMAND ${CMAKE_COMMAND} -E make_directory Gmsh.framework/Versions/A/Resources
    COMMAND ${CMAKE_COMMAND} -E copy ${LIBNAME} Gmsh.framework/Versions/A/Gmsh
    COMMAND ${CMAKE_COMMAND} -E copy Info_framework.plist 
                                     Gmsh.framework/Versions/A/Resources/Info.plist
    COMMAND ${CMAKE_COMMAND} -E create_symlink A Gmsh.framework/Versions/Current
    COMMAND ${CMAKE_COMMAND} -E create_symlink Versions/Current/Gmsh 
                                               Gmsh.framework/Gmsh
    COMMAND ${CMAKE_COMMAND} -E create_symlink Versions/Current/Headers
                                               Gmsh.framework/Headers
    COMMAND ${CMAKE_COMMAND} -E create_symlink Versions/Current/Resources
                                               Gmsh.framework/Resources 
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  foreach(FILE ${GMSH_API})
    add_custom_command(TARGET framework POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        ${FILE} ${CMAKE_CURRENT_BINARY_DIR}/Gmsh.framework/Versions/A/Headers/
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  endforeach(FILE)
endif(APPLE)

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
    "/projects/" "/TetgenNew/") #"/Tetgen.*/.*(cxx|h)")

if(UNIX)
  # make sure we remove previous installs before doing the next one
  # (on Mac for example "make package; make package_source" would lead
  # to huge file lists getting generated due to the 'Applications'
  # symlink in the bundle)
  set(CPACK_INSTALL_COMMANDS "rm -rf ${CMAKE_CURRENT_BINARY_DIR}/_CPack_Packages")
endif(UNIX)

if(APPLE AND ENABLE_APP_BUNDLE)
  set(CPACK_GENERATOR Bundle)
  set(CPACK_BUNDLE_NAME Gmsh)
  file(READ ${CMAKE_CURRENT_SOURCE_DIR}/utils/misc/gmsh_app.plist F0)
  string(REPLACE GMSH_VERSION "${GMSH_VERSION}" F1 "${F0}")
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/Info.plist "${F1}")
  set(CPACK_BUNDLE_PLIST ${CMAKE_CURRENT_BINARY_DIR}/Info.plist)
  set(CPACK_BUNDLE_ICON ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/MacIcons.icns)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/MacIconsGeo.icns DESTINATION .
          RENAME GmshGeo.icns)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/MacIconsMsh.icns DESTINATION .
          RENAME GmshMsh.icns)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/MacIconsPos.icns DESTINATION .
          RENAME GmshPos.icns)
  set(CPACK_PACKAGE_ICON ${CMAKE_CURRENT_SOURCE_DIR}/Fltk/MacIcons.icns)
elseif(WIN32 OR CYGWIN)
  set(CPACK_GENERATOR ZIP)
else(APPLE AND ENABLE_APP_BUNDLE)
  set(CPACK_GENERATOR TGZ)
endif(APPLE AND ENABLE_APP_BUNDLE)

include(CPack)

message("")
message("Gmsh ${GMSH_VERSION} has been configured for ${GMSH_OS} with the "
        "following options:" ${GMSH_CONFIG_OPTIONS})
message("")
message("C compiler: " ${CMAKE_C_COMPILER})
message("C++ compiler: " ${CMAKE_CXX_COMPILER})
if(NOT CMAKE_BUILD_TYPE)
  message("C compiler flags: " ${CMAKE_C_FLAGS})
  message("C++ compiler flags: " ${CMAKE_CXX_FLAGS})
else(NOT CMAKE_BUILD_TYPE)
  message("Build type: " ${CMAKE_BUILD_TYPE})
endif(NOT CMAKE_BUILD_TYPE)
message("Install prefix: " ${CMAKE_INSTALL_PREFIX})
message("")
message("Run 'ccmake ${CMAKE_CURRENT_SOURCE_DIR}' to fine-tune the configuration.")
message("")

mark_as_advanced(BISON FLEX GMP_LIB GMSH_EXTRA_VERSION HDF5_LIB MAKEINFO 
                 MED_LIB OCC_INC SZ_LIB TAUCS_LIB ACIS_LIB TEXI2PDF)
