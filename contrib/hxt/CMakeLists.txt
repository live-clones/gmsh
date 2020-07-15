# Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.


# This CMakeList is only part of Gmsh
# To compile hxt separately, use the CMakeLists in the module you would like to use
# except for sizeField, which can only be compiled with Gmsh

# Fixme: HXT should rather be included using simple target_link_library calls,
# as for external libraries


#################################################################################
# HXT core
#################################################################################
set(SRC
    hxt_bbox.c
    hxt_mesh.c
    hxt_message.c
    hxt_sort.c
   )

set(INC
    hxt_bbox.h
    hxt_mesh.h
    hxt_message.h
    hxt_omp.h
    hxt_sort.h
    hxt_tools.h
   )

append_gmsh_src(contrib/hxt/core/src "${SRC}")
append_gmsh_src(contrib/hxt/core/include "${INC}")
list(APPEND HXT_INC_DIRS
     contrib/hxt/core/src
     contrib/hxt/core/include)


#################################################################################
# HXT reparam
#################################################################################
set(SRC
    hxt_class_macro.h
    hxt_curvature.c
    hxt_edge.c
    hxt_linear_system.c
    hxt_linear_system_lu.c
    hxt_linear_system_lu.h
    hxt_linear_system_petsc.c
    hxt_linear_system_petsc.h
    hxt_mean_values.c
    hxt_non_linear_solver.c
    hxt_non_linear_solver.h
   )

set(INC
    hxt_curvature.h
    hxt_edge.h
    hxt_linear_system.h
    hxt_mean_values.h
   )

append_gmsh_src(contrib/hxt/reparam/src "${SRC}")
append_gmsh_src(contrib/hxt/reparam/include "${INC}")
list(APPEND HXT_INC_DIRS
     contrib/hxt/reparam/src
     contrib/hxt/reparam/include)


#################################################################################
# HXT sizeField
#################################################################################
if(HAVE_P4EST)
  append_gmsh_src(contrib/hxt/sizeField "hxt_octree.cpp;hxt_octree.h" )
  list(APPEND HXT_INC_DIRS contrib/hxt/sizeField)
endif()


#################################################################################
# HXT predicates
#################################################################################
# do not use arithmetic contraction in predicates.c
if(MSVC OR (CMAKE_C_COMPILER_ID STREQUAL "Intel" AND WIN32))
  set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/predicates/src/predicates.c"
                              PROPERTIES COMPILE_FLAGS "/fp:strict")
elseif(CMAKE_C_COMPILER_ID STREQUAL "Intel")
  set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/predicates/src/predicates.c"
                              PROPERTIES COMPILE_FLAGS "-fp-model strict")
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/predicates/src/predicates.c"
                              PROPERTIES COMPILE_FLAGS  "-fno-unsafe-math-optimizations -ffp-contract=off")
else()
  message(WARNING
    "Unsupported compiler !
     Make sure compiled functions from predicates.c
     do NOT use extended double precision and follow IEEE754 standard.
     It is crucial for the robustness of geometric predicates.")
endif()
append_gmsh_src(contrib/hxt/predicates/src predicates.c)
append_gmsh_src(contrib/hxt/predicates/include predicates.h)
list(APPEND HXT_INC_DIRS
     contrib/hxt/predicates/src
     contrib/hxt/predicates/include)


#################################################################################
# HXT tetBR
#################################################################################
append_gmsh_src(contrib/hxt/tetBR/src hxt_boundary_recovery.cxx)
append_gmsh_src(contrib/hxt/tetBR/include hxt_boundary_recovery.h)
list(APPEND HXT_INC_DIRS
     contrib/hxt/tetBR/src
     contrib/hxt/tetBR/include)


#################################################################################
# HXT tetMesh
#################################################################################
set(SRC
    hxt_edgeRemoval.c
    hxt_edgeRemoval.h
    hxt_smoothing.c
    hxt_smoothing.h
    HXTSPR.c
    HXTSPR.h
    hxt_tetColor.c
    hxt_tetColor.h
    hxt_tetDelaunay.c
    hxt_tetFlag.c
    hxt_tetMesh.c
    hxt_tetNodalSize.c
    hxt_tetOpti.c
    hxt_tetOptiUtils.h
    hxt_tetPartition.h
    hxt_tetQuality.c
    hxt_tetQuality.h
    hxt_tetRefine.c
    hxt_tetRefine.h
    hxt_tetRepair.c
    hxt_tetSync.c
    hxt_tetSync.h
    hxt_tetUtils.c
    hxt_tetUtils.h
    hxt_vertices.c
   )

set(INC
    hxt_tetDelaunay.h
    hxt_tetFlag.h
    hxt_tetMesh.h
    hxt_tetNodalSize.h
    hxt_tetOpti.h
    hxt_tetRepair.h
    hxt_vertices.h
   )

append_gmsh_src(contrib/hxt/tetMesh/src "${SRC}")
append_gmsh_src(contrib/hxt/tetMesh/include "${INC}")

list(APPEND HXT_INC_DIRS
     contrib/hxt/tetMesh/src
     contrib/hxt/tetMesh/include)


#################################################################################
# HXT remesh
#################################################################################
set(SRC
    hxt_collapse_edge.c
    hxt_collapse_edge.h
    hxt_eigenvectors.cpp
    hxt_eigenvectors.h
    hxt_gmsh_point_gen_main.c
    hxt_orientation3d_tools.c
    hxt_orientation3d_tools.h
    hxt_point_gen.c
    hxt_point_gen.h
    hxt_point_gen_1d.c
    hxt_point_gen_1d.h
    hxt_point_gen_2d.c
    hxt_point_gen_2d.h
    hxt_point_gen_3d.c
    hxt_point_gen_3d.h
    hxt_point_gen_io.c
    hxt_point_gen_io.h
    hxt_point_gen_numerics.c
    hxt_point_gen_numerics.h
    hxt_point_gen_optim.c
    hxt_point_gen_optim.h
    hxt_point_gen_orientation.c
    hxt_point_gen_orientation.h
    hxt_point_gen_realloc.c
    hxt_point_gen_realloc.h
    hxt_point_gen_utils.c
    hxt_point_gen_utils.h
    hxt_post_debugging.h
    hxt_remesh_tools.c
    hxt_remesh_tools.h
    hxt_rtree_wrapper.cpp
    hxt_rtree_wrapper.h
    hxt_split_edge.c
    hxt_split_edge.h
    hxt_split_triangle.c
    hxt_split_triangle.h
    hxt_surface_mesh.c
    hxt_surface_mesh.h
    hxt_surface_mesh_collapse.c
    hxt_surface_mesh_collapse.h
    hxt_swap_edge.c
    hxt_swap_edge.h
    hxt_triangle_quality.c
    hxt_triangle_quality.h
    rtree.hpp
   )

set(INC
    hxt_gmsh_point_gen_main.h
    hxt_point_gen_options.h
   )

append_gmsh_src(contrib/hxt/remesh/src "${SRC}")
append_gmsh_src(contrib/hxt/remesh/include "${INC}")
list(APPEND HXT_INC_DIRS
     contrib/hxt/remesh/src
     contrib/hxt/remesh/include)


#################################################################################
# propagate HXT_INC_DIRS to parent CMakeLists
#################################################################################
set(HXT_INC_DIRS ${HXT_INC_DIRS} PARENT_SCOPE)
