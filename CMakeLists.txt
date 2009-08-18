# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
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

option(ENABLE_ANN "Enable ANN to compute Approximate Nearest Neighbors" ON)
option(ENABLE_BLAS_LAPACK "Use BLAS/Lapack for basic linear algebra" ON)
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
option(ENABLE_METIS "Enable Metis mesh partitioner" ON)
option(ENABLE_NATIVE_FILE_CHOOSER "Enable native file chooser in GUI" ON)
option(ENABLE_NETGEN "Enable Netgen mesh generator" ON)
option(ENABLE_OCC "Enable OpenCASCADE geometrical models" ON)
option(ENABLE_OOFELIE "Set compiler options to match oofelie settings" OFF)
option(ENABLE_OSMESA "Use OSMesa for offscreen rendering" OFF)
option(ENABLE_PARSER "Build the GEO file parser" ON)
option(ENABLE_POST "Build the post-processing module" ON)
option(ENABLE_QT "Build QT GUI" OFF)
option(ENABLE_TAUCS "Enable Taucs linear algebra solver" ON)
option(ENABLE_TETGEN "Enable Tetgen mesh generator" ON)
option(ENABLE_TETGEN_NEW "Enable experimental version of Tetgen" OFF)

set(GMSH_MAJOR_VERSION 2)
set(GMSH_MINOR_VERSION 4)
set(GMSH_PATCH_VERSION 0)
set(GMSH_EXTRA_VERSION "" CACHE STRING "Gmsh extra version string")

set(GMSH_VERSION "${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION}")
set(GMSH_VERSION "${GMSH_VERSION}.${GMSH_PATCH_VERSION}${GMSH_EXTRA_VERSION}")
set(GMSH_SHORT_LICENSE "GNU General Public License")

set(GMSH_API
  ${CMAKE_BINARY_DIR}/Common/GmshConfig.h 
  ${CMAKE_BINARY_DIR}/Common/GmshVersion.h
  Common/Gmsh.h Common/GmshDefines.h Common/GmshMessage.h Common/VertexArray.h
  Numeric/Gauss.h Numeric/FunctionSpace.h Numeric/GmshMatrix.h
    Numeric/gmshAssembler.h Numeric/gmshTermOfFormulation.h 
    Numeric/gmshLaplace.h Numeric/gmshElasticity.h Numeric/gmshLinearSystem.h
    Numeric/gmshLinearSystemGmm.h Numeric/gmshLinearSystemFull.h 
    Numeric/gmshFunction.h
  Geo/GModel.h Geo/GEntity.h Geo/GPoint.h Geo/GVertex.h Geo/GEdge.h 
    Geo/GFace.h Geo/GRegion.h Geo/GEdgeLoop.h Geo/GEdgeCompound.h 
    Geo/GFaceCompound.h Geo/GRegionCompound.h Geo/MVertex.h Geo/MEdge.h 
    Geo/MFace.h Geo/MElement.h Geo/MPoint.h Geo/MLine.h Geo/MTriangle.h 
    Geo/MQuadrangle.h Geo/MTetrahedron.h Geo/MHexahedron.h Geo/MPrism.h 
    Geo/MPyramid.h Geo/MElementCut.h Geo/discreteVertex.h Geo/discreteEdge.h
    Geo/discreteFace.h Geo/discreteRegion.h Geo/SPoint2.h Geo/SPoint3.h
    Geo/SVector3.h Geo/SBoundingBox3d.h Geo/Pair.h Geo/Range.h 
    Geo/SOrientedBoundingBox.h Geo/CellComplex.h Geo/ChainComplex.h
  Post/PView.h Post/PViewData.h Plugin/PluginManager.h
  Graphics/drawContext.h
  contrib/kbipack/gmp_normal_form.h contrib/kbipack/gmp_matrix.h 
    contrib/kbipack/gmp_blas.h
  contrib/DiscreteIntegration/DILevelset.h)

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

if(MSVC)
  # remove really annoying (and stupid, and wrong) warning about
  # bool/int cast performance in Visual C++
  set(GMSH_CONFIG_PRAGMAS "#pragma warning(disable:4800)")
endif(MSVC)

macro(append_gmsh_src DIRECTORY_NAME SRC_FILES)
  foreach(FILE ${SRC_FILES})
    list(APPEND LIST ${DIRECTORY_NAME}/${FILE})
  endforeach(FILE)
  set(GMSH_SRC ${GMSH_SRC};${LIST} PARENT_SCOPE)
endmacro(append_gmsh_src)

if(ENABLE_BLAS_LAPACK)
  if(MSVC)
    # on Windows with Visual C++ try really hard to find blas/lapack
    # in CMAKE_PREFIX_PATH *without* requiring a Fortran compiler: 1)
    # try to find the Intel MKL; if not found 2) try to get the
    # reference blas/lapack libs (useful for users with no Fortan
    # compiler and no MKL license, who can just download our
    # precompiled "gmsh-dep" package)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
      set(MKL_PATH em64t/lib)
    else(CMAKE_SIZEOF_VOID_P EQUAL 8)
      set(MKL_PATH ia32/lib)
    endif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    find_library(LIBGUIDE libguide PATHS ${CMAKE_PREFIX_PATH} 
                 PATH_SUFFIXES ${MKL_PATH})
    find_library(MKL_C mkl_c PATHS ${CMAKE_PREFIX_PATH} 
                 PATH_SUFFIXES ${MKL_PATH})
    find_library(MKL_INTEL_C mkl_intel_c PATHS ${CMAKE_PREFIX_PATH} 
                 PATH_SUFFIXES ${MKL_PATH})
    find_library(MKL_INTEL_THREAD mkl_intel_thread PATHS ${CMAKE_PREFIX_PATH} 
                 PATH_SUFFIXES ${MKL_PATH})
    find_library(MKL_CORE mkl_core PATHS ${CMAKE_PREFIX_PATH} 
                 PATH_SUFFIXES ${MKL_PATH})
    if(LIBGUIDE AND MKL_C AND MKL_INTEL_C AND MKL_INTEL_THREAD AND MKL_CORE)
      set(LAPACK_LIBRARIES ${LIBGUIDE} ${MKL_C} ${MKL_INTEL_C} 
          ${MKL_INTEL_THREAD} ${MKL_CORE})
      set(HAVE_BLAS TRUE)
      set(HAVE_LAPACK TRUE)
      list(APPEND CONFIG_OPTIONS "IntelBlas" "IntelLapack")
    endif(LIBGUIDE AND MKL_C AND MKL_INTEL_C AND MKL_INTEL_THREAD AND MKL_CORE)
    if(NOT HAVE_BLAS OR NOT HAVE_LAPACK)
      find_library(REF_LAPACK lapack PATHS ${CMAKE_PREFIX_PATH}
                   PATH_SUFFIXES lib NO_DEFAULT_PATH)
      find_library(REF_BLAS blas PATHS ${CMAKE_PREFIX_PATH}
                   PATH_SUFFIXES lib NO_DEFAULT_PATH)
      find_library(REF_G2C g2c PATHS ${CMAKE_PREFIX_PATH}
                   PATH_SUFFIXES lib NO_DEFAULT_PATH)
      find_library(REF_GCC gcc PATHS ${CMAKE_PREFIX_PATH}
                   PATH_SUFFIXES lib NO_DEFAULT_PATH)
      if(REF_LAPACK AND REF_BLAS AND REF_G2C AND REF_GCC)
        set(LAPACK_LIBRARIES ${REF_LAPACK} ${REF_BLAS} ${REF_G2C} ${REF_GCC})
        set(HAVE_BLAS TRUE)
        set(HAVE_LAPACK TRUE)
        list(APPEND CONFIG_OPTIONS "RefBlas" "RefLapack")
      endif(REF_LAPACK AND REF_BLAS AND REF_G2C AND REF_GCC)
    endif(NOT HAVE_BLAS OR NOT HAVE_LAPACK)
  elseif(APPLE)
    # on Mac we know blas and lapack are available, so don't force users
    # to install a Fortran compiler
    set(LAPACK_LIBRARIES "-llapack -lblas")
    set(HAVE_BLAS TRUE)
    set(HAVE_LAPACK TRUE)
    list(APPEND CONFIG_OPTIONS "Blas" "Lapack")
  endif(MSVC)
  if(NOT HAVE_BLAS OR NOT HAVE_LAPACK)
    enable_language(Fortran)
    find_package(BLAS)
    if(BLAS_FOUND)
      set(HAVE_BLAS TRUE)
      list(APPEND CONFIG_OPTIONS "Blas")
      find_package(LAPACK)
      if(LAPACK_FOUND)
        set(HAVE_LAPACK TRUE)
        list(APPEND CONFIG_OPTIONS "Lapack")
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
endif(ENABLE_BLAS_LAPACK)

add_subdirectory(Common)
add_subdirectory(Numeric)
add_subdirectory(Geo)
add_subdirectory(Mesh)

if(ENABLE_POST)
  add_subdirectory(Post)
  add_subdirectory(Plugin)
else(ENABLE_POST)
  set(HAVE_NO_POST TRUE)
  list(APPEND CONFIG_OPTIONS "NoPost")
endif(ENABLE_POST)

if(ENABLE_PARSER)
  add_subdirectory(Parser)
else(ENABLE_PARSER)
  set(HAVE_NO_PARSER TRUE)
  list(APPEND CONFIG_OPTIONS "NoParser")
endif(ENABLE_PARSER)

if(ENABLE_FLTK)
  set(FLTK_SKIP_FORMS TRUE)
  set(FLTK_SKIP_FLUID TRUE)
  find_package(FLTK)
  if(FLTK_FOUND)
    set(HAVE_FLTK TRUE)
    list(APPEND CONFIG_OPTIONS "Fltk")
    list(APPEND EXTERNAL_INCLUDES ${FLTK_INCLUDE_DIR})
    add_subdirectory(Fltk)
    if(ENABLE_NATIVE_FILE_CHOOSER)
      add_subdirectory(contrib/NativeFileChooser)
      set(HAVE_NATIVE_FILE_CHOOSER TRUE)
      list(APPEND CONFIG_OPTIONS "NativeFileChooser")
      add_definitions(-DFLTK1)
    endif(ENABLE_NATIVE_FILE_CHOOSER)
    if(ENABLE_FL_TREE)
      add_subdirectory(contrib/Fl_Tree)
      set(HAVE_FL_TREE TRUE)
      list(APPEND CONFIG_OPTIONS "FlTree")
    endif(ENABLE_FL_TREE)
  endif(FLTK_FOUND)
elseif(ENABLE_QT)
  find_package(Qt4)
  set(QT_USE_QTOPENGL TRUE)
  include(${QT_USE_FILE})
  if(QT_FOUND)
    set(HAVE_QT TRUE)
    list(APPEND CONFIG_OPTIONS "Qt")
    list(APPEND EXTERNAL_INCLUDES ${QT_INCLUDE_DIR})
    add_subdirectory(Qt)
  endif(QT_FOUND)
endif(ENABLE_FLTK)

if(HAVE_FLTK OR HAVE_QT OR ENABLE_GRAPHICS)
  # get jpeg lib (if we have fltk first try to get the local jpeg lib)
  if(HAVE_FLTK)
    find_library(FLTK_JPEG fltk_jpeg)
    if(NOT FLTK_JPEG)
      find_library(FLTK_JPEG fltkjpeg)
    endif(NOT FLTK_JPEG)
    if(FLTK_JPEG)
      set(HAVE_LIBJPEG TRUE) 
      list(APPEND CONFIG_OPTIONS "FltkJpeg")
      list(APPEND EXTERNAL_LIBRARIES ${FLTK_JPEG})
      foreach(DIR ${FLTK_INCLUDE_DIR})
        list(APPEND EXTERNAL_INCLUDES ${DIR}/FL/images ${DIR}/jpeg)
      endforeach(DIR)
    endif(FLTK_JPEG)
  endif(HAVE_FLTK)
  if(NOT FLTK_JPEG)
    find_package(JPEG)
    if(JPEG_FOUND)
      set(HAVE_LIBJPEG TRUE) 
      list(APPEND CONFIG_OPTIONS "Jpeg")
      list(APPEND EXTERNAL_LIBRARIES ${JPEG_LIBRARIES})
      list(APPEND EXTERNAL_INCLUDES ${JPEG_INCLUDE_DIR})
    endif(JPEG_FOUND)
  endif(NOT FLTK_JPEG)
  # get zlib (if we have fltk first try to get the local zlib)
  if(HAVE_FLTK)
    find_library(FLTK_Z fltk_z)
    if(NOT FLTK_Z)
      find_library(FLTK_Z fltkz)
    endif(NOT FLTK_Z)
    if(FLTK_Z)
      set(HAVE_LIBZ TRUE) 
      list(APPEND CONFIG_OPTIONS "FltkZlib")
      list(APPEND EXTERNAL_LIBRARIES ${FLTK_Z})
      foreach(DIR ${FLTK_INCLUDE_DIR})
        list(APPEND EXTERNAL_INCLUDES ${DIR}/FL/images ${DIR}/zlib)
      endforeach(DIR)
    endif(FLTK_Z)
  endif(HAVE_FLTK)
  if(NOT FLTK_Z)
    find_package(ZLIB)
    if(ZLIB_FOUND)
      set(HAVE_LIBZ TRUE) 
      list(APPEND CONFIG_OPTIONS "Zlib")
      list(APPEND EXTERNAL_LIBRARIES ${ZLIB_LIBRARIES})
      list(APPEND EXTERNAL_INCLUDES ${ZLIB_INCLUDE_DIR})
    endif(ZLIB_FOUND)
  endif(NOT FLTK_Z)
  # get png lib (if we have fltk first try to get the local png lib)
  if(HAVE_LIBZ)
    if(HAVE_FLTK)
      find_library(FLTK_PNG fltk_png)
      if(NOT FLTK_PNG)
        find_library(FLTK_PNG fltkpng)
      endif(NOT FLTK_PNG)
      if(FLTK_PNG)
        set(HAVE_LIBPNG TRUE) 
        list(APPEND CONFIG_OPTIONS "FltkPng")
        list(APPEND EXTERNAL_LIBRARIES ${FLTK_PNG})
        foreach(DIR ${FLTK_INCLUDE_DIR})
          list(APPEND EXTERNAL_INCLUDES ${DIR}/FL/images ${DIR}/png)
        endforeach(DIR)
      endif(FLTK_PNG)
    endif(HAVE_FLTK)
    if(NOT FLTK_PNG)
      find_package(PNG)
      if(PNG_FOUND)
        set(HAVE_LIBPNG TRUE)
        list(APPEND CONFIG_OPTIONS "Png")
        list(APPEND EXTERNAL_LIBRARIES ${PNG_LIBRARIES})
        list(APPEND EXTERNAL_INCLUDES ${PNG_INCLUDE_DIR})
      endif(PNG_FOUND)
    endif(NOT FLTK_PNG)
  endif(HAVE_LIBZ)
  find_package(OpenGL REQUIRED)
  add_subdirectory(Graphics)
endif(HAVE_FLTK OR HAVE_QT OR ENABLE_GRAPHICS)

if(ENABLE_ANN)
  add_subdirectory(contrib/ANN)
  set(HAVE_ANN TRUE)
  list(APPEND CONFIG_OPTIONS "Ann")
endif(ENABLE_ANN)

if(ENABLE_CHACO)
  add_subdirectory(contrib/Chaco)
  set(HAVE_CHACO TRUE)
  list(APPEND CONFIG_OPTIONS "Chaco")
endif(ENABLE_CHACO)

if(ENABLE_DINTEGRATION)
  add_subdirectory(contrib/DiscreteIntegration)
  set(HAVE_DINTEGRATION TRUE)
  list(APPEND CONFIG_OPTIONS "DIntegration")
endif(ENABLE_DINTEGRATION)

if(ENABLE_GMM)
  set(HAVE_GMM TRUE)
  list(APPEND CONFIG_OPTIONS "Gmm")
endif(ENABLE_GMM)

if(ENABLE_KBIPACK)
  find_library(GMP_LIB gmp)
  if(GMP_LIB)
    add_subdirectory(contrib/kbipack)
    set(HAVE_KBIPACK TRUE)
    list(APPEND CONFIG_OPTIONS "Kbipack")
    list(APPEND EXTERNAL_LIBRARIES ${GMP_LIB})
  endif(GMP_LIB)
endif(ENABLE_KBIPACK)

if(ENABLE_MATHEX)
  add_subdirectory(contrib/MathEx)
  set(HAVE_MATHEX TRUE)
  list(APPEND CONFIG_OPTIONS "MathEx")
endif(ENABLE_MATHEX)

if(ENABLE_METIS)
  add_subdirectory(contrib/Metis)
  set(HAVE_METIS TRUE)
  list(APPEND CONFIG_OPTIONS "Metis")
  message("WARNING: By including Metis you have to comply with Metis' "
          "special licensing requirements stated in contrib/Metis/README.")
endif(ENABLE_METIS)

if(ENABLE_NETGEN)
  add_subdirectory(contrib/Netgen)
  set(HAVE_NETGEN TRUE)
  list(APPEND CONFIG_OPTIONS "Netgen")
  add_definitions(-DNO_PARALLEL_THREADS)
endif(ENABLE_NETGEN)

if(ENABLE_TETGEN_NEW AND EXISTS ${CMAKE_SOURCE_DIR}/contrib/TetgenNew/tetgen.h)
  add_subdirectory(contrib/TetgenNew)
  set(HAVE_TETGEN TRUE)
  list(APPEND CONFIG_OPTIONS "TetgenNew")
  add_definitions(-DTETLIBRARY)
  message("WARNING: You are including an experimental version of Tetgen "
          "that is KNOWN TO BE BUGGY on 64 bits archs and on WIN32/MSVC.")
elseif(ENABLE_TETGEN AND EXISTS ${CMAKE_SOURCE_DIR}/contrib/Tetgen/tetgen.h)
  add_subdirectory(contrib/Tetgen)
  set(HAVE_TETGEN TRUE)
  list(APPEND CONFIG_OPTIONS "Tetgen")
  add_definitions(-DTETLIBRARY)
  message("WARNING: By including Tetgen you have to comply with Tetgen's "
          "special licensing requirements stated in contrib/Tetgen/LICENSE.")
endif(ENABLE_TETGEN_NEW AND EXISTS ${CMAKE_SOURCE_DIR}/contrib/TetgenNew/tetgen.h)

if(ENABLE_FOURIER_MODEL)
  find_library(FFTW3_LIB fftw3)
  if(FFTW3_LIB)
    find_library(FOURIER_MODEL_LIB FourierModel)
    if(FOURIER_MODEL_LIB)
      set(HAVE_FOURIER_MODEL TRUE)
      list(APPEND CONFIG_OPTIONS "FourierModel")
      list(APPEND EXTERNAL_LIBRARIES ${FOURIER_MODEL_LIB} ${FFTW3_LIB})
    endif(FOURIER_MODEL_LIB)
  endif(FFTW3_LIB)
endif(ENABLE_FOURIER_MODEL)

if(ENABLE_MED OR ENABLE_CGNS)
  find_library(HDF5_LIB hdf5)
  if(HDF5_LIB)
    if(ENABLE_MED)
      find_library(MED_LIB med)
      if(MED_LIB)
        set(HAVE_MED TRUE)
        list(APPEND CONFIG_OPTIONS "Med")
        list(APPEND EXTERNAL_LIBRARIES ${MED_LIB})
      endif(MED_LIB)
    endif(ENABLE_MED)    
    if(ENABLE_CGNS)
      find_library(CGNS_LIB cgns)
      if(CGNS_LIB)
        set(HAVE_LIBCGNS TRUE)
        list(APPEND CONFIG_OPTIONS "Cgns")
        list(APPEND EXTERNAL_LIBRARIES ${CGNS_LIB})
      endif(CGNS_LIB)
    endif(ENABLE_CGNS)    
    if(MED_LIB OR CGNS_LIB)
      list(APPEND EXTERNAL_LIBRARIES ${HDF5_LIB})
      find_library(SZ_LIB szlib)
      if(SZ_LIB)
        list(APPEND EXTERNAL_LIBRARIES ${SZ_LIB})
      endif(SZ_LIB)
      if(NOT HAVE_LIBZ) # necessary for non-GUI builds
        find_package(ZLIB)
        if(ZLIB_FOUND)
          set(HAVE_LIBZ TRUE) 
          list(APPEND CONFIG_OPTIONS "Zlib")
          list(APPEND EXTERNAL_LIBRARIES ${ZLIB_LIBRARIES})
        endif(ZLIB_FOUND)
      endif(NOT HAVE_LIBZ)
    endif(MED_LIB OR CGNS_LIB)
  endif(HDF5_LIB)
endif(ENABLE_MED OR ENABLE_CGNS)

if(ENABLE_TAUCS)
  find_library(TAUCS_LIB taucs)
  if(TAUCS_LIB)
    set(HAVE_TAUCS TRUE)
    list(APPEND CONFIG_OPTIONS "Taucs")
    list(APPEND EXTERNAL_LIBRARIES ${TAUCS_LIB})
  endif(TAUCS_LIB)
endif(ENABLE_TAUCS)

if(ENABLE_OCC)
  if(WIN32)
    set(OCC_SYS_NAME win32)
  else(WIN32)
    set(OCC_SYS_NAME ${CMAKE_SYSTEM_NAME})
  endif(WIN32)
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
                 ${OCC_SYS_NAME}/lib)
    if(OCC_LIB)
      list(APPEND OCC_LIBS ${OCC_LIB})
    endif(OCC_LIB)
    set(OCC_LIB OCC_LIB-NOTFOUND CACHE INTERNAL "")
    # unset(OCC_LIB CACHE) # cleaner, but only available in cmake >= 2.6.4
  endforeach(OCC)
  list(LENGTH OCC_LIBS NUM_OCC_LIBS)
  if(NUM_OCC_LIBS EQUAL NUM_OCC_LIBS_REQUIRED)
    find_path(OCC_INC "BRep_Tool.hxx" PATHS ENV CASROOT PATH_SUFFIXES inc 
              include opencascade)
    if(OCC_INC)
      set(HAVE_OCC TRUE)
      list(APPEND CONFIG_OPTIONS "OpenCascade")
      list(APPEND EXTERNAL_LIBRARIES ${OCC_LIBS})
      list(APPEND EXTERNAL_INCLUDES ${OCC_INC})
      if(CYGWIN)
        list(APPEND EXTERNAL_LIBRARIES "winspool")
      elseif(MSVC)
        add_definitions(-DHAVE_NO_OCC_CONFIG_H -DWNT)
      endif(CYGWIN)
    endif(OCC_INC)
  endif(NUM_OCC_LIBS EQUAL NUM_OCC_LIBS_REQUIRED)
endif(ENABLE_OCC)

if(ENABLE_OSMESA)
  find_library(OSMESA_LIB OSMesa)
  if(OSMESA_LIB)
    set(HAVE_OSMESA TRUE)
    list(APPEND CONFIG_OPTIONS "OSMesa")
    list(APPEND EXTERNAL_LIBRARIES ${OSMESA_LIB})
  endif(OSMESA_LIB)
endif(ENABLE_OSMESA)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(HAVE_64BIT_SIZE_T TRUE)
  list(APPEND CONFIG_OPTIONS "Have64BitSizeT")
  if(HAVE_OCC)
    add_definitions(-D_OCC64)
  endif(HAVE_OCC)
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

set(HAVE_NO_DLL TRUE)
list(APPEND CONFIG_OPTIONS "NoDll")

include(CheckFunctionExists)
check_function_exists(vsnprintf HAVE_VSNPRINTF)
if(NOT HAVE_VSNPRINTF)
  set(HAVE_NO_VSNPRINTF TRUE)
  list(APPEND CONFIG_OPTIONS "NoVsnprintf")
endif(NOT HAVE_VSNPRINTF)

include(CheckIncludeFile)
check_include_file(sys/socket.h HAVE_SYS_SOCKET_H)
if(HAVE_SYS_SOCKET_H)
  set(CMAKE_EXTRA_INCLUDE_FILES sys/socket.h)
endif(HAVE_SYS_SOCKET_H)
include(CheckTypeSize)
check_type_size(socklen_t SOCKLEN_T_SIZE)
if(NOT SOCKLEN_T_SIZE)
  set(HAVE_NO_SOCKLEN_T TRUE)
  list(APPEND CONFIG_OPTIONS "NoSocklenT")
endif(NOT SOCKLEN_T_SIZE)
set(CMAKE_EXTRA_INCLUDE_FILES)

if(UNIX)
  file(GLOB_RECURSE NON_OPTIMIZED_SRC Common/GmshPredicates.cpp Mesh/BDS.cpp
       Parser/Gmsh.tab.cpp contrib/Tetgen*/*.cxx)
  set_source_files_properties(${NON_OPTIMIZED_SRC} COMPILE_FLAGS "-O0")
endif(UNIX)

if(MSVC)
  add_definitions(-D_USE_MATH_DEFINES -DNOMINMAX 
                  -D_CRT_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_DEPRECATE)
  set(GMSH_SRC ${GMSH_SRC};Fltk/Win32Icon.rc)
  list(APPEND EXTERNAL_LIBRARIES "ws2_32")
endif(MSVC)

list(SORT CONFIG_OPTIONS)
set(GMSH_CONFIG_OPTIONS "")
foreach(OPT ${CONFIG_OPTIONS})
  set(GMSH_CONFIG_OPTIONS "${GMSH_CONFIG_OPTIONS} ${OPT}")
endforeach(OPT)

configure_file(${CMAKE_SOURCE_DIR}/Common/GmshConfig.h.in 
               ${CMAKE_BINARY_DIR}/Common/GmshConfig.h)
configure_file(${CMAKE_SOURCE_DIR}/Common/GmshVersion.h.in
               ${CMAKE_BINARY_DIR}/Common/GmshVersion.h)

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

# we could specify include dirs more selectively, but this is simpler
include_directories(Common Fltk Geo Graphics Mesh Numeric Parser Plugin
  Post Qt contrib/ANN/include contrib/Chaco/main contrib/DiscreteIntegration
  contrib/MathEx contrib/Metis contrib/NativeFileChooser contrib/Netgen 
  contrib/Netgen/libsrc/include contrib/Netgen/libsrc/interface
  contrib/Tetgen contrib/Fl_Tree contrib/gmm contrib/kbipack
  ${EXTERNAL_INCLUDES} ${CMAKE_BINARY_DIR}/Common)

# we don't build the lib by default (we could then create the gmsh
# target by linking with it) because doing so slows down the
# compile/link development a lot: running ranlib+ar on a large static
# lib every time we recompile is frustratingly slow. Instead, we build
# the gmsh target directly from the object files. This is much faster
# but has one side effect: when we actually want to build the lib we
# need to recompile everything (the first time--it's a separate
# target)
add_library(lib STATIC EXCLUDE_FROM_ALL ${GMSH_SRC})
set_target_properties(lib PROPERTIES OUTPUT_NAME Gmsh)
if(MSVC)
  SET_TARGET_PROPERTIES(lib PROPERTIES DEBUG_POSTFIX d) 
  if(ENABLE_OOFELIE)
    INCLUDE(${CMAKE_SOURCE_DIR}/utils/misc/withOOFELIE.cmake)
  endif(ENABLE_OOFELIE)
endif(MSVC)

if(HAVE_FLTK)
  add_executable(gmsh WIN32 Fltk/Main.cpp ${GMSH_SRC})
  target_link_libraries(gmsh ${FLTK_LIBRARIES} ${EXTERNAL_LIBRARIES} 
                        ${OPENGL_LIBRARIES} ${LAPACK_LIBRARIES})
elseif(HAVE_QT)
  qt4_wrap_cpp(GMSH_MOC_SRC ${GMSH_MOC_HDR})
  add_executable(gmsh WIN32 Qt/Main.cpp ${GMSH_SRC} ${GMSH_MOC_SRC})
  target_link_libraries(gmsh ${QT_LIBRARIES} ${EXTERNAL_LIBRARIES}
                        ${OPENGL_LIBRARIES} ${LAPACK_LIBRARIES})
else(HAVE_FLTK)
  add_executable(gmsh Common/Main.cpp ${GMSH_SRC})
  target_link_libraries(gmsh ${EXTERNAL_LIBRARIES} ${LAPACK_LIBRARIES})
endif(HAVE_FLTK)

# increase stack to 16Mb on Windows to avoid overflows in recursive
# tet classification for large 3D Delaunay grids
if(CYGWIN)
  set_target_properties(gmsh PROPERTIES LINK_FLAGS 
    "-Wl,--stack,16777216 ${CMAKE_SOURCE_DIR}/Fltk/Win32Icon.res -mwindows")
elseif(MSVC)
  set_target_properties(gmsh PROPERTIES LINK_FLAGS "/STACK:16777216")
endif(CYGWIN)

find_program(BISON bison)
find_program(FLEX flex)
if(BISON AND FLEX)
  add_custom_target(parser 
                    COMMAND ${BISON} -p gmsh_yy --output Gmsh.tab.cpp -d Gmsh.y
                    COMMAND ${FLEX} -P gmsh_yy -o Gmsh.yy.cpp Gmsh.l
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/Parser)
endif(BISON AND FLEX)

if(UNIX)
  add_custom_target(purge COMMAND ${CMAKE_SOURCE_DIR}/utils/misc/purge.sh
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endif(UNIX)

set(WELCOME_FILE ${CMAKE_SOURCE_DIR}/doc/WELCOME.txt)
set(LICENSE_FILE ${CMAKE_SOURCE_DIR}/doc/LICENSE.txt)
set(CREDITS_FILE ${CMAKE_SOURCE_DIR}/doc/CREDITS.txt)
file(GLOB TUTORIAL_FILES ${CMAKE_SOURCE_DIR}/tutorial/*.*)
file(GLOB DEMO_FILES ${CMAKE_SOURCE_DIR}/demos/*.*)
set(TEX_DIR ${CMAKE_SOURCE_DIR}/doc/texinfo)
file(GLOB TEX_SRC ${TEX_DIR}/*.texi)
set(TEX_OBJ ${TEX_DIR}/gmsh.aux ${TEX_DIR}/gmsh.cp ${TEX_DIR}/gmsh.cps
    ${TEX_DIR}/gmsh.fn ${TEX_DIR}/gmsh.html ${TEX_DIR}/gmsh.info ${TEX_DIR}/gmsh.ky 
    ${TEX_DIR}/gmsh.log ${TEX_DIR}/gmsh.pdf ${TEX_DIR}/gmsh.pg ${TEX_DIR}/gmsh.toc 
    ${TEX_DIR}/gmsh.tp ${TEX_DIR}/gmsh.tps ${TEX_DIR}/gmsh.txt ${TEX_DIR}/gmsh.vr)

macro(unix2dos VARNAME)
  file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/unix2dos)
  set(UNIX2DOS_FILES)
  foreach(FILE ${${VARNAME}})
    file(READ ${FILE} F0)
    get_filename_component(N ${FILE} NAME)
    if(CYGWIN)
      string(REGEX REPLACE "\n" "\r\n" F1 "${F0}")
      file(WRITE ${CMAKE_BINARY_DIR}/unix2dos/${N} "${F1}")
    else(CYGWIN) # if not in cygwin, cmake adds '\r's automatically
      file(WRITE ${CMAKE_BINARY_DIR}/unix2dos/${N} "${F0}")
    endif(CYGWIN)
    list(APPEND UNIX2DOS_FILES ${CMAKE_BINARY_DIR}/unix2dos/${N})
  endforeach(FILE)
  set(${VARNAME} ${UNIX2DOS_FILES})
endmacro(unix2dos)

if(WIN32)
  set(GMSH_BIN .)
  set(GMSH_DOC .)
  unix2dos(GMSH_API)
  unix2dos(WELCOME_FILE)
  unix2dos(LICENSE_FILE)
  unix2dos(CREDITS_FILE)
  unix2dos(TUTORIAL_FILES)
  unix2dos(DEMO_FILES)
else(WIN32)
  set(GMSH_BIN bin)
  set(GMSH_DOC share/doc/gmsh)
endif(WIN32)

# mark targets as optional so we can install them separately if needed
# (e.g. "make lib" followed by "make install/fast")
install(TARGETS gmsh RUNTIME DESTINATION ${GMSH_BIN} OPTIONAL)
install(TARGETS lib ARCHIVE DESTINATION lib OPTIONAL)
install(FILES ${GMSH_API} DESTINATION include/gmsh)
install(FILES ${WELCOME_FILE} DESTINATION ${GMSH_DOC} RENAME README.txt)
install(FILES ${LICENSE_FILE} DESTINATION ${GMSH_DOC})
install(FILES ${CREDITS_FILE} DESTINATION ${GMSH_DOC})
install(FILES ${TUTORIAL_FILES} DESTINATION ${GMSH_DOC}/tutorial)
install(FILES ${DEMO_FILES} DESTINATION ${GMSH_DOC}/demos)
if(UNIX AND NOT CYGWIN)
  install(FILES ${CMAKE_SOURCE_DIR}/doc/gmsh.1 DESTINATION share/man/man1)
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
                    ${CMAKE_BINARY_DIR}/gmsh-${GMSH_VERSION}-doc.tgz
                    FAQ.txt CREDITS.txt VERSIONS.txt gmsh.1
                    texinfo/gmsh.info texinfo/gmsh.txt texinfo/gmsh.html 
                    texinfo/gmsh.pdf DEPENDS ${TEX_DIR}/gmsh.info 
                    ${TEX_DIR}/gmsh.txt ${TEX_DIR}/gmsh.html ${TEX_DIR}/gmsh.pdf
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc)
endif(MAKEINFO AND TEXI2PDF)

if(MAKEINFO OR TEXI2PDF)
  add_custom_target(clean_doc COMMAND ${CMAKE_COMMAND} -E remove ${TEX_OBJ})
endif(MAKEINFO OR TEXI2PDF)

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
set(CPACK_SOURCE_IGNORE_FILES "${CMAKE_BINARY_DIR}" "/CVS/" "/.svn" "~$" 
    "DS_Store$" "GmshConfig.h$" "GmshVersion.h$" "/benchmarks/" "/tmp/" 
    "/bin/" "/lib/" "/nightly/" "GPATH" "GRTAGS" "GSYMS" "GTAGS" "/HTML/" 
    "/TetgenNew/") #"/Tetgen.*/.*(cxx|h)")

if(UNIX)
  # make sure we remove previous installs before doing the next one
  # (on Mac for example "make package; make package_source" would lead
  # to huge file lists getting generated due to the 'Applications'
  # symlink in the bundle)
  set(CPACK_INSTALL_COMMANDS 
      "${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/_CPack_Packages")
endif(UNIX)

if(APPLE)
  set(CPACK_GENERATOR Bundle)
  set(CPACK_BUNDLE_NAME Gmsh)
  file(READ ${CMAKE_SOURCE_DIR}/utils/misc/gmsh_app.plist F0)
  string(REPLACE GMSH_VERSION "${GMSH_VERSION}" F1 "${F0}")
  file(WRITE ${CMAKE_BINARY_DIR}/Info.plist "${F1}")
  set(CPACK_BUNDLE_PLIST ${CMAKE_BINARY_DIR}/Info.plist)
  set(CPACK_BUNDLE_ICON ${CMAKE_SOURCE_DIR}/Fltk/MacIcons.icns)
  set(CPACK_BUNDLE_STARTUP_COMMAND ${CMAKE_SOURCE_DIR}/utils/misc/gmsh_app.sh)
  install(FILES ${CMAKE_SOURCE_DIR}/Fltk/MacIconsGeo.icns DESTINATION .
          RENAME GmshGeo.icns)
  install(FILES ${CMAKE_SOURCE_DIR}/Fltk/MacIconsMsh.icns DESTINATION .
          RENAME GmshMsh.icns)
  install(FILES ${CMAKE_SOURCE_DIR}/Fltk/MacIconsPos.icns DESTINATION .
          RENAME GmshPos.icns)
  set(CPACK_PACKAGE_ICON ${CMAKE_SOURCE_DIR}/Fltk/MacIcons.icns)
elseif(WIN32)
  set(CPACK_GENERATOR ZIP)
else(APPLE)
  set(CPACK_GENERATOR TGZ)
endif(APPLE)

include(CPack)

message("")
message("Gmsh has been configured for ${GMSH_OS} with the "
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
message("Run 'ccmake ${CMAKE_SOURCE_DIR}' to fine-tune the configuration.")
message("")

mark_as_advanced(BISON ENABLE_GRAPHICS FLEX GMP_LIB GMSH_EXTRA_VERSION 
                 HDF5_LIB LIBGUIDE MAKEINFO MED_LIB MKL_C MKL_CORE MKL_INTEL_C
                 MKL_INTEL_THREAD OCC_INC REF_BLAS REF_G2C REF_GCC REF_LAPACK 
                 SZ_LIB TAUCS_LIB TEXI2PDF)
