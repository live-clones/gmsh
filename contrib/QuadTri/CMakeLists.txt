# Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  QuadTriExtruded2D.cpp
  QuadTriExtruded3D.cpp
  QuadTriTransfinite3D.cpp
  QuadTriUtils.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/QuadTri "${SRC};${HDR}")
