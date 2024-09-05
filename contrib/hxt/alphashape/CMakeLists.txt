cmake_minimum_required(VERSION 3.9)
project(hxt_alphashape C CXX)

# include guard for CMake:
# if you plan to include multiple directory that depend on this one,
# you need to include this directory first
if(TARGET hxt_alphashape)
  return()
endif()


#################################################################################
# Options
#################################################################################
option(HXT_ALPHASHAPE_OBJECT_ONLY "Do not create hxt_alphashape library" ON)
option(HXT_TETMESH_BUILD_CLI "build hxt_tetMesh CLI tools" ON)


#################################################################################
# Library definition
#################################################################################
set(HXT_ALPHASHAPE_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_alphaUtils.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_alphaUtils.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_alphashape.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_alphashape.h"
   )

if(HXT_ALPHASHAPE_OBJECT_ONLY)
    add_library(hxt_alphashape OBJECT ${HXT_ALPHASHAPE_SRC})
else()
    add_library(hxt_alphashape ${HXT_ALPHASHAPE_SRC})
endif()

add_subdirectory(../core "${CMAKE_CURRENT_BINARY_DIR}/core")
add_subdirectory(../predicates "${CMAKE_CURRENT_BINARY_DIR}/predicates")
add_subdirectory(../tetBR "${CMAKE_CURRENT_BINARY_DIR}/tetBR")

target_include_directories(hxt_alphashape
                           PUBLIC include
                           PRIVATE src)
target_link_libraries(hxt_alphashape
                      PUBLIC hxt_core
                      PRIVATE hxt_predicates hxt_tetBR m)
target_compile_features(hxt_alphashape PRIVATE c_std_99)

#################################################################################
# Executable definition
#################################################################################
# if(HXT_TETMESH_BUILD_CLI)
#     # tetMesh_CLI
#     add_executable(tetMesh_CLI "${CMAKE_CURRENT_SOURCE_DIR}/exe/tetMesh_CLI.c")
#     target_link_libraries(tetMesh_CLI hxt_core hxt_predicates hxt_tetBR hxt_tetMesh)

#     # Delaunay_CLI
#     add_executable(Delaunay_CLI "${CMAKE_CURRENT_SOURCE_DIR}/exe/Delaunay_CLI.c")
#     target_link_libraries(Delaunay_CLI hxt_core hxt_predicates hxt_tetBR hxt_tetMesh)

#     # tetOpti_CLI
#     add_executable(tetOpti_CLI "${CMAKE_CURRENT_SOURCE_DIR}/exe/tetOpti_CLI.c")
#     target_link_libraries(tetOpti_CLI hxt_core hxt_predicates hxt_tetBR hxt_tetMesh)
# endif()