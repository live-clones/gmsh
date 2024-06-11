# Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  HighOrderMeshOptimizer.cpp
  HighOrderMeshElasticAnalogy.cpp
  HighOrderMeshFastCurving.cpp
  HighOrderMeshPeriodicity.cpp
  MetaEl.cpp
  BoundaryLayerCurver2D.cpp
  BoundaryLayerCurver3D.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/HighOrderMeshOptimizer "${SRC};${HDR}")
