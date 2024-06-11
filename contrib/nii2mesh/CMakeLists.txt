# Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  src/MarchingCubes.c
  src/nii2mesh.c
  src/isolevel.c
  src/meshify.c
  src/quadric.c
  src/base64.c
  src/bwlabel.c
  src/radixsort.c
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/nii2mesh "${SRC};${HDR}")
