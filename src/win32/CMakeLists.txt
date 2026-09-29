# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# gmsh.rc goes into the executable alone: see the top-level CMakeLists.txt
set(SRC
  BackendWin32.cpp
  win32Common.cpp
  SceneWin32.cpp
  dialogWin32.cpp
  fieldWin32.cpp
  treeWin32.cpp
  menuWin32.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/win32 "${SRC};${HDR}")
