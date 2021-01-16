# Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  directions3D.cpp
  simple3D.cpp
  pointInsertion.cpp
  pointInsertionRTreeTools.cpp
  yamakawa.cpp
  ThinLayer.cpp
  surfaceFiller.cpp
  BGMBase.cpp
  BackgroundMesh2D.cpp
  BackgroundMesh3D.cpp
  BackgroundMeshManager.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/domhex "${SRC};${HDR}")
