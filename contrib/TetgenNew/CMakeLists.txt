# Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  behavior.cxx
  constrain.cxx
  delaunay.cxx
  flip.cxx
  geom.cxx
  io.cxx
  main.cxx
  memorypool.cxx
  meshio.cxx
  meshstat.cxx
  predicates.cxx
  refine.cxx
  surface.cxx
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/TetgenNew "${SRC};${HDR}")
