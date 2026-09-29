# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# Objective-C++, with ARC: see the CMakeLists.txt at the top, which gives them
# the flag, the source files being the top directory's
set(SRC
  BackendCocoa.mm
  SceneCocoa.mm
  dialogCocoa.mm
  fieldCocoa.mm
  treeCocoa.mm
  menuCocoa.mm
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/cocoa "${SRC};${HDR}")
