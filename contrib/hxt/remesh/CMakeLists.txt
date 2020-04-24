cmake_minimum_required(VERSION 3.9)
project(hxt_remesh C CXX)

# include guard for CMake:
# if you plan to include multiple directory that depend on this one,
# you need to include this directory first
if(TARGET hxt_tetMesh)
  return()
endif()


#################################################################################
# Options
#################################################################################
option(HXT_ENABLE_EIGEN "use the Eigen for computing eigenvalues" ON)
option(HXT_REMESH_OBJECT_ONLY "Do not create hxt_remesh library" OFF)


#################################################################################
# Library definition
#################################################################################
set(HXT_REMESH_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_collapse_edge.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_collapse_edge.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_eigenvectors.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_eigenvectors.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_gmsh_point_gen_main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_orientation3d_tools.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_orientation3d_tools.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_1d.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_1d.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_2d.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_2d.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_3d.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_3d.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_io.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_io.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_numerics.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_numerics.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_optim.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_optim.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_orientation.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_orientation.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_realloc.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_realloc.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_utils.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_point_gen_utils.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_post_debugging.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_remesh_tools.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_remesh_tools.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_rtree_wrapper.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_rtree_wrapper.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_split_edge.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_split_edge.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_split_triangle.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_split_triangle.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_surface_mesh.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_surface_mesh.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_surface_mesh_collapse.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_surface_mesh_collapse.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_swap_edge.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_swap_edge.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_triangle_quality.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_triangle_quality.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/rtree.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_gmsh_point_gen_main.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_point_gen_options.h"
   )

if(HXT_REMESH_OBJECT_ONLY)
	add_library(hxt_remesh OBJECT ${HXT_REMESH_SRC})
else()
	add_library(hxt_remesh ${HXT_REMESH_SRC})
endif()

add_subdirectory(../core "${CMAKE_CURRENT_BINARY_DIR}/core")
add_subdirectory(../predicates "${CMAKE_CURRENT_BINARY_DIR}/predicates")
add_subdirectory(../reparam "${CMAKE_CURRENT_BINARY_DIR}/reparam")

set(HXT_TETMESH_BUILD_CLI OFF CACHE BOOL "do not build tetMesh CLI" FORCE)
add_subdirectory(../tetMesh "${CMAKE_CURRENT_BINARY_DIR}/tetMesh")

target_link_libraries(hxt_remesh PUBLIC hxt_core PRIVATE hxt_predicates hxt_reparam hxt_tetMesh m)
target_include_directories(hxt_remesh PUBLIC include)

if(HXT_ENABLE_EIGEN)
	find_package(Eigen3 REQUIRED NO_MODULE)
	target_link_libraries (hxt_remesh PRIVATE Eigen3::Eigen)
	target_compile_definitions(hxt_remesh PRIVATE HXT_HAVE_EIGEN)
endif()

