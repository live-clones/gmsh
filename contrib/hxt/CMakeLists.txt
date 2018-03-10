# Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

set(SRC
  hxt_bbox.c
  hxt_context.c
  hxt_curvature.c
  hxt_edge.c
  hxt_linear_system.c
  hxt_linear_system_lu.c
  hxt_message.c
  hxt_option.c
  hxt_parametrization.c
  hxt_mean_values.c
  hxt_tools.c
  hxt_mesh.c
  hxt_vertices.c
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/hxt "${SRC};${HDR}")
