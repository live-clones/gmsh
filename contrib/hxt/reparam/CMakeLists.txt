cmake_minimum_required(VERSION 3.9)
project(hxt_reparam C)

# include guard for CMake:
# if you plan to include multiple directory that depend on this one,
# you need to include this directory first
if(TARGET hxt_reparam)
  return()
endif()


#################################################################################
# Options
#################################################################################
option(HXT_ENABLE_PETSC "USE PETSc as linear solver (requires petsc compile without mpi and for real numbers)" ON)
option(HXT_REPARAM_OBJECT_ONLY "Do not create hxt_reparam library" ON)


#################################################################################
# Library definition
#################################################################################
set(HXT_REPARAM_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_edge.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_curvature.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_mean_values.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_linear_system.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_linear_system_lu.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_non_linear_solver.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_linear_system_petsc.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_class_macro.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_linear_system_lu.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_non_linear_solver.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_linear_system_petsc.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_curvature.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_edge.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_linear_system.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_mean_values.h")

if(HXT_REPARAM_OBJECT_ONLY)
	add_library(hxt_reparam OBJECT ${HXT_REPARAM_SRC})
else()
	add_library(hxt_reparam ${HXT_REPARAM_SRC})
endif()

add_subdirectory(../core "${CMAKE_CURRENT_BINARY_DIR}/core")

target_link_libraries(hxt_reparam PUBLIC hxt_core PRIVATE m)
target_compile_features(hxt_reparam PRIVATE c_std_99)
target_include_directories(hxt_reparam PUBLIC include)

if(ENABLE_PETSC)
	list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
	find_package(PETSc REQUIRED)
	target_include_directories(hxt_reparam PRIVATE "${PETSC_INC}")
	target_link_libraries(hxt_reparam PRIVATE "${PETSC_LIBS}")
	target_compile_definitions(hxt_reparam PRIVATE HXT_HAVE_PETSC)
endif()

