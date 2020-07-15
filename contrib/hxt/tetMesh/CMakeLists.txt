cmake_minimum_required(VERSION 3.9)
project(hxt_tetMesh C CXX)

# include guard for CMake:
# if you plan to include multiple directory that depend on this one,
# you need to include this directory first
if(TARGET hxt_tetMesh)
  return()
endif()


#################################################################################
# Options
#################################################################################
option(HXT_TETMESH_OBJECT_ONLY "Do not create hxt_tetMesh library" ON)
option(HXT_TETMESH_BUILD_CLI "build hxt_tetMesh CLI tools" ON)


#################################################################################
# Library definition
#################################################################################
set(HXT_TETMESH_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/HXTSPR.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetFlag.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetMesh.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetOpti.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetSync.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetColor.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetUtils.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_vertices.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_smoothing.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetRefine.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetRepair.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetQuality.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_edgeRemoval.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetDelaunay.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetNodalSize.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/HXTSPR.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetSync.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetColor.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetUtils.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_smoothing.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetRefine.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetQuality.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_edgeRemoval.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetOptiUtils.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_tetPartition.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_tetDelaunay.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_tetFlag.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_tetMesh.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_tetNodalSize.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_tetOpti.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_tetRepair.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_vertices.h"
   )

if(HXT_TETMESH_OBJECT_ONLY)
    add_library(hxt_tetMesh OBJECT ${HXT_TETMESH_SRC})
else()
    add_library(hxt_tetMesh ${HXT_TETMESH_SRC})
endif()

add_subdirectory(../core "${CMAKE_CURRENT_BINARY_DIR}/core")
add_subdirectory(../predicates "${CMAKE_CURRENT_BINARY_DIR}/predicates")
add_subdirectory(../tetBR "${CMAKE_CURRENT_BINARY_DIR}/tetBR")

target_include_directories(hxt_tetMesh
                           PUBLIC include
                           PRIVATE src)
target_link_libraries(hxt_tetMesh
                      PUBLIC hxt_core
                      PRIVATE hxt_predicates hxt_tetBR m)
target_compile_features(hxt_tetMesh PRIVATE c_std_99)


#################################################################################
# Executable definition
#################################################################################
if(HXT_TETMESH_BUILD_CLI)
    # tetMesh_CLI
    add_executable(tetMesh_CLI "${CMAKE_CURRENT_SOURCE_DIR}/exe/tetMesh_CLI.c")
    target_link_libraries(tetMesh_CLI hxt_core hxt_predicates hxt_tetBR hxt_tetMesh)

    # Delaunay_CLI
    add_executable(Delaunay_CLI "${CMAKE_CURRENT_SOURCE_DIR}/exe/Delaunay_CLI.c")
    target_link_libraries(Delaunay_CLI hxt_core hxt_predicates hxt_tetBR hxt_tetMesh)

    # tetOpti_CLI
    add_executable(tetOpti_CLI "${CMAKE_CURRENT_SOURCE_DIR}/exe/tetOpti_CLI.c")
    target_link_libraries(tetOpti_CLI hxt_core hxt_predicates hxt_tetBR hxt_tetMesh)
endif()