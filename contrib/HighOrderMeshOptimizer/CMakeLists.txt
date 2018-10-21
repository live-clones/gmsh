# Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues

set(SRC
  OptHomMesh.cpp 
  OptHOM.cpp 
  OptHomRun.cpp 
  OptHomIntegralBoundaryDist.cpp
  OptHomCADDist.cpp
  ParamCoord.cpp 
  MetaEl.cpp 
  OptHomElastic.cpp
  OptHomFastCurving.cpp
  OptHomPeriodicity.cpp
  CADDistances.cpp
  BoundaryLayerCurver2D.cpp
  BoundaryLayerCurver3D.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/HighOrderMeshOptimizer "${SRC};${HDR}")
