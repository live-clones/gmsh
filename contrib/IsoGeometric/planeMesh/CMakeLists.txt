cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(example CXX)

# The following commands can be included in the CMakeLists.txt of each tutorial:
# they fill the EXTRA_INCS and EXTRA_LIBS variables.

# Detect if we use the MinGW compilers on Cygwin - if we do, handle the build as
# a pure Windows build
if(CYGWIN OR MSYS)
  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR
     CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpmachine
                    OUTPUT_VARIABLE CXX_COMPILER_MACHINE
                    OUTPUT_STRIP_TRAILING_WHITESPACE)
    if(CXX_COMPILER_MACHINE MATCHES "mingw")
      set(WIN32 1)
      add_definitions(-DWIN32)
      set(CMAKE_FIND_LIBRARY_PREFIXES "lib" "")
      set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" ".so" ".lib" ".LIB" ".dll" ".DLL")
    endif()
  endif()
endif()

# Make sure we have C++14 support
set(CMAKE_CXX_STANDARD 17)

# Enable all warnings
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-Wall" HAVE_WALL)
if(HAVE_WALL)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()

# Find Gmsh
find_library(GMSH_LIB gmsh)
if(NOT GMSH_LIB)
  message(FATAL_ERROR "Could not find Gmsh library")
endif(NOT GMSH_LIB)
find_path(GMSH_INC gmsh.h)
if(NOT GMSH_INC)
  message(FATAL_ERROR "Could not find Gmsh header 'gmsh.h'")
endif(NOT GMSH_INC)
list(APPEND EXTRA_INCS ${GMSH_INC})
list(APPEND EXTRA_LIBS ${GMSH_LIB})

# Find GmshFEM
find_library(GMSHFEM_LIB gmshfem)
if(NOT GMSHFEM_LIB)
  message(FATAL_ERROR "Could not find GmshFEM library")
endif(NOT GMSHFEM_LIB)
find_path(GMSHFEM_INC gmshfem/GmshFem.h)
if(NOT GMSHFEM_INC)
  message(FATAL_ERROR "Could not find GmshFEM header 'gmshfem/GmshFem.h'")
endif(NOT GMSHFEM_INC)
list(APPEND EXTRA_LIBS ${GMSHFEM_LIB})
list(APPEND EXTRA_INCS ${GMSHFEM_INC} ${GMSHFEM_INC}/gmshfem)

# Find Eigen if GmshFEM was not compiled with contrib Eigen
if(NOT EXISTS ${GMSHFEM_INC}/gmshfem/Eigen)
  find_path(EIGEN_INC "Eigen/Dense" PATH_SUFFIXES eigen3)
  if(EIGEN_INC)
    list(APPEND EXTRA_INCS ${EIGEN_INC})
  endif()
endif()

# OpenMP
find_package(OpenMP)
if(OPENMP_FOUND)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()
if(APPLE AND EXISTS "/usr/local/opt/libomp")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp -I/usr/local/opt/libomp/include")
  list(APPEND EXTRA_LIBS "-L/usr/local/opt/libomp/lib -lomp")
  message(STATUS "Found OpenMP[Homebrew]")
elseif(APPLE AND EXISTS "/opt/local/lib/libomp")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp -I/opt/local/include/libomp")
  list(APPEND EXTRA_LIBS "-L/opt/local/lib/libomp -lomp")
  message(STATUS "Found OpenMP[MacPorts]")
elseif(APPLE AND EXISTS "/opt/homebrew/opt/libomp")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include")
  list(APPEND EXTRA_LIBS "-L/opt/homebrew/opt/libomp/lib -lomp")
  message(STATUS "Found OpenMP[Homebrew]")
endif()

# PETSc
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
  string(REGEX MATCH "PETSC_CC_INCLUDES = [^\n\r]*" PETSC_PACKAGES_INCLUDES ${PETSC_VARIABLES})
  if(PETSC_PACKAGES_INCLUDES)
    string(REPLACE "PETSC_CC_INCLUDES = " "" PETSC_PACKAGES_INCLUDES ${PETSC_PACKAGES_INCLUDES})
  else()
    # try to find PETSC_PACKAGES_INCLUDES in older versions
    list(APPEND EXTRA_INCS ${ENV_PETSC_DIR}/include)
    list(APPEND EXTRA_INCS ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/include)
    string(REGEX MATCH "PACKAGES_INCLUDES = [^\n\r]*" PETSC_PACKAGES_INCLUDES ${PETSC_VARIABLES})
    string(REPLACE "PACKAGES_INCLUDES = " "" PETSC_PACKAGES_INCLUDES ${PETSC_PACKAGES_INCLUDES})
  endif()

  if(PETSC_PACKAGES_INCLUDES)
    if(PETSC_PACKAGES_INCLUDES)
      string(REPLACE "-I" "" PETSC_PACKAGES_INCLUDES ${PETSC_PACKAGES_INCLUDES})
      string(REPLACE " " ";" PETSC_PACKAGES_INCLUDES ${PETSC_PACKAGES_INCLUDES})
      foreach(VAR ${PETSC_PACKAGES_INCLUDES})
        list(APPEND EXTRA_INCS ${VAR})
      endforeach()
    endif()
  endif()

  find_library(PETSC_LIBS petsc PATHS ${ENV_PETSC_DIR}/${ENV_PETSC_ARCH}/lib NO_DEFAULT_PATH)

  if(SLEPC_DIR)
    set(ENV_SLEPC_DIR ${SLEPC_DIR})
  else()
    set(ENV_SLEPC_DIR $ENV{SLEPC_DIR})
  endif()
  find_library(SLEPC_LIB slepc PATHS ${ENV_SLEPC_DIR}/${ENV_PETSC_ARCH}/lib NO_DEFAULT_PATH)
  if(SLEPC_LIB)
    find_path(SLEPC_INC "slepc.h" PATHS ${ENV_SLEPC_DIR} PATH_SUFFIXES include ${ENV_PETSC_ARCH}/include include/slepc NO_DEFAULT_PATH)
    if(SLEPC_INC)
      message(STATUS "Using SLEPc dir: ${ENV_SLEPC_DIR}")
      list(APPEND EXTRA_LIBS ${SLEPC_LIB})
      list(APPEND EXTRA_INCS ${SLEPC_INC})
      find_path(SLEPC_INC2 "slepcconf.h" PATHS ${ENV_SLEPC_DIR} PATH_SUFFIXES ${ENV_PETSC_ARCH}/include NO_DEFAULT_PATH)
      if(SLEPC_INC2)
        list(APPEND EXTRA_INCS ${SLEPC_INC2})
      endif()
    endif()
  endif()

  list(APPEND EXTRA_LIBS ${PETSC_LIBS})

  string(REGEX MATCH "PACKAGES_LIBS = [^\n\r]*" PLIBS ${PETSC_VARIABLES})
  if(PLIBS)
    string(REPLACE "PACKAGES_LIBS = " "" PLIBS ${PLIBS})
    string(STRIP ${PLIBS} PLIBS)
    list(APPEND EXTRA_LIBS "${PLIBS}")
  endif()

  string(REGEX MATCH "PETSC_EXTERNAL_LIB_BASIC = [^\n\r]*" PLIBS_BASIC ${PETSC_VARIABLES})
  if(PLIBS_BASIC)
    string(REPLACE "PETSC_EXTERNAL_LIB_BASIC = " "" PLIBS_BASIC ${PLIBS_BASIC})
    string(STRIP ${PLIBS_BASIC} PLIBS_BASIC)
    list(APPEND EXTRA_LIBS "${PLIBS_BASIC}")
  endif()

  string(REGEX MATCH "PCC_LINKER_LIBS = [^\n\r]*" LLIBS ${PETSC_VARIABLES})
  if(LLIBS)
    string(REPLACE "PCC_LINKER_LIBS = " "" LLIBS ${LLIBS})
    string(STRIP ${LLIBS} LLIBS)
    list(APPEND EXTRA_LIBS "${LLIBS}")
  endif()

  list(APPEND EXTRA_LIBS ${PETSC_LIBS})
else()
  find_library(PETSC_LIBS petsc)
  find_path(PETSC_INC "petsc.h" PATH_SUFFIXES include/petsc)
  if(PETSC_LIBS AND PETSC_INC)
    list(APPEND EXTRA_LIBS ${PETSC_LIBS})
    list(APPEND EXTRA_INCS ${PETSC_INC})
  endif()
  find_library(SLEPC_LIBS slepc)
  find_path(SLEPC_INC "slepc.h" PATH_SUFFIXES include/slepc)
  if(SLEPC_LIBS AND SLEPC_INC)
    list(APPEND EXTRA_LIBS ${SLEPC_LIBS})
    list(APPEND EXTRA_INCS ${SLEPC_INC})
  endif()
endif()

include_directories(${EXTRA_INCS})

# Surface deformation
add_executable(expansion mainExpansion.cpp laplacianSmoothing.h ${EXTRA_INCS})
add_executable(metric mainMetric.cpp laplacianSmoothing.h ${EXTRA_INCS})
add_executable(deformation mainDeformation.cpp ${EXTRA_INCS})
add_executable(construct mainConstruct.cpp meshMacro.h ${EXTRA_INCS})

target_link_libraries(expansion ${EXTRA_LIBS})
target_link_libraries(metric ${EXTRA_LIBS})
target_link_libraries(deformation ${EXTRA_LIBS})
target_link_libraries(construct ${EXTRA_LIBS})

# Solver
add_executable(poisson mainPoisson.cpp ${EXTRA_INCS})
add_executable(elasticity mainElasticity.cpp ${EXTRA_INCS})

target_link_libraries(poisson ${EXTRA_LIBS})
target_link_libraries(elasticity ${EXTRA_LIBS})
