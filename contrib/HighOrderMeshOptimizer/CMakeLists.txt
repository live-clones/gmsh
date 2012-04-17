# Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  OptHomMesh.cpp 
  OptHOM.cpp 
  OptHomRun.cpp 
  ParamCoord.cpp 
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
append_gmsh_src(contrib/HighOrderMeshOptimizer "${SRC};${HDR}")
