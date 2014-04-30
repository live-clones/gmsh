# Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@geuz.org>.

set(SRC
  OptHomMesh.cpp 
  OptHOM.cpp 
  OptHomRun.cpp 
  OptHomIntegralBoundaryDist.cpp
  ParamCoord.cpp 
  SuperEl.cpp 
  OptHomElastic.cpp
  OptHomFastCurving.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
append_gmsh_src(contrib/HighOrderMeshOptimizer "${SRC};${HDR}")
