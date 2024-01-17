# Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  Mesh2d.cpp 
  bamg-gmsh.cpp 
  bamglib/Mesh2.cpp
  bamglib/MeshGeom.cpp	
  bamglib/MeshRead.cpp	
  bamglib/Metric.cpp	
  bamglib/R2.cpp
  bamglib/MeshDraw.cpp
  bamglib/MeshQuad.cpp	
  bamglib/MeshWrite.cpp	
  bamglib/Meshio.cpp	
  bamglib/QuadTree.cpp	
  bamglib/SetOfE4.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
append_gmsh_src(contrib/bamg "${SRC};${HDR}")
