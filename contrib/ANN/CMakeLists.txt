# Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  src/ANN.cpp
  src/bd_fix_rad_search.cpp
  src/bd_pr_search.cpp
  src/bd_search.cpp
  src/bd_tree.cpp
  src/brute.cpp
  src/kd_dump.cpp
  src/kd_fix_rad_search.cpp
  src/kd_pr_search.cpp
  src/kd_search.cpp
  src/kd_split.cpp
  src/kd_tree.cpp
  src/kd_util.cpp
  src/perf.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/ANN "${SRC};${HDR}")
