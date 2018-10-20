# Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

set(SRC
  hxt_bbox.c
  hxt_context.c
  hxt_curvature.c
  hxt_edge.c
  hxt_laplace.c
  hxt_linear_system.c
  hxt_linear_system_lu.c
  hxt_linear_system_petsc.c
  hxt_mesh.c
  hxt_message.c
  hxt_non_linear_solver.c
  hxt_option.c
  hxt_opt.c
  hxt_sort.c
  hxt_tools.c
  predicates.c
  hxt_mesh3d.c
  hxt_mesh3d_main.c
  hxt_mesh_size.c
  hxt_tetOpti.c
  hxt_tetRepair.c
  hxt_tetUtils.c
  hxt_tetColor.c
  hxt_tetFlag.c
  hxt_tetPostpro.c
  hxt_tet_aspect_ratio.c
  hxt_tetDelaunay.c
  hxt_vertices.c
  hxt_parametrization.c
  hxt_mean_values.c 
  hxt_boundary_recovery.cxx
)

# do not use arithmetic contraction in predicates.c
if ("x${CMAKE_C_COMPILER_ID}" STREQUAL "xMSVC" )
  set_source_files_properties(predicates.c PROPERTIES COMPILE_FLAGS "/fp:strict")
endif()
if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  set_source_files_properties(predicates.c PROPERTIES COMPILE_FLAGS "-fno-unsafe-math-optimizations -ffp-contract=off")
endif()
if (CMAKE_C_COMPILER_ID STREQUAL "Intel")
  set_source_files_properties(predicates.c PROPERTIES COMPILE_FLAGS "-fp-model strict")
endif()



file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/hxt "${SRC};${HDR}")
