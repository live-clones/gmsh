# Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.


# HXT (reparametrization)
set(SRC
  hxt_context.c
  hxt_curvature.c
  hxt_edge.c
  hxt_laplace.c
  hxt_linear_system.c
  hxt_linear_system_lu.c
  hxt_linear_system_petsc.c
  hxt_mean_values.c
  hxt_mesh.c
  hxt_message.c
  hxt_parametrization.c
  hxt_tools.c
 )

# HXT3D (3D meshing)
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/hxt_tetDelaunay.c)
set(SRC ${SRC}
  hxt_bbox.c
  hxt_boundary_recovery.cxx
  hxt_edgeRemoval.c
  hxt_mesh.c
  hxt_smoothing.c
  hxt_sort.c
  hxt_tetColor.c
  hxt_tetDelaunay.c
  hxt_tetFlag.c
  hxt_tetMesh.c
  hxt_tetNodalSize.c
  hxt_tetOpti.c
  hxt_tetPostpro.c
  hxt_tetQuality.c
  hxt_tetRefine.c
  hxt_tetRepair.c
  hxt_tetSync.c
  hxt_tetUtils.c
  hxt_vertices.c
  hxt_octree.cpp
  HXTSPR.c
  predicates.c
)
endif()


# HXT (remesh)
set(SRC ${SRC}
  remesh/hxt_gmsh_point_gen_main.c
  remesh/hxt_point_gen_numerics.c
  remesh/hxt_point_gen_io.c
  remesh/hxt_point_gen_1d.c
  remesh/hxt_point_gen_2d.c
  remesh/hxt_point_gen_3d.c

  remesh/hxt_collapse_edge.c
  remesh/hxt_eigenvectors.cpp
  remesh/hxt_gmsh_point_gen_main.c
  remesh/hxt_orientation3d_tools.c
  remesh/hxt_point_gen.c
  remesh/hxt_point_gen_optim.c
  remesh/hxt_point_gen_orientation.c
  remesh/hxt_point_gen_realloc.c
  remesh/hxt_point_gen_utils.c
  remesh/hxt_rtree_wrapper.cpp
  remesh/hxt_split_edge.c
  remesh/hxt_split_triangle.c
  remesh/hxt_surface_mesh.c
  remesh/hxt_surface_mesh_collapse.c
  remesh/hxt_swap_edge.c
  remesh/hxt_triangle_quality.c
  )
# HXT (multiblock)
set(SRC ${SRC}
  multiblock/hxt_quadMultiBlock.cpp
  multiblock/hxt_qmbSingularity.cpp
  multiblock/hxt_qmbCorner.cpp
  multiblock/hxt_qmbBoundaryLine.cpp
  multiblock/hxt_qmbBoundary.cpp
  multiblock/hxt_qmbSeparatrice.cpp
  multiblock/hxt_qmbSepGroup.cpp
  multiblock/hxt_qmbMultiBlock.cpp
  multiblock/hxt_qmbQuadGenerator.cpp
  )

# do not use arithmetic contraction in predicates.c
if("x${CMAKE_C_COMPILER_ID}" STREQUAL "xMSVC" )
  set_source_files_properties(predicates.c PROPERTIES COMPILE_FLAGS
                              "/fp:strict")
endif()
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  set_source_files_properties(predicates.c PROPERTIES COMPILE_FLAGS
                              "-fno-unsafe-math-optimizations -ffp-contract=off")
endif()
if(CMAKE_C_COMPILER_ID STREQUAL "Intel")
 set_source_files_properties(predicates.c PROPERTIES COMPILE_FLAGS
                             "-fp-model strict")
endif()

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/hxt "${SRC};${HDR}")
