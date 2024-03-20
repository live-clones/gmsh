# Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  untangle3d.cpp
  pointset.cpp 
  polyline.cpp
  vec.cpp
  volume.cpp
  surface.cpp
  HLBFGS_wrapper.cpp
  LineSearch.cpp
  HLBFGS.cpp
  HLBFGS_BLAS.cpp
  Lite_Sparse_Matrix.cpp
  ICFS.cpp
) 

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/untangle "${SRC};${HDR}")
