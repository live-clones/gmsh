# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# no Q_OBJECT anywhere: nothing goes through moc
set(SRC
  BackendQt.cpp
  SceneQt.cpp
  dialogQt.cpp
  fieldQt.cpp
  treeQt.cpp
  menuQt.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/qt "${SRC};${HDR}")
