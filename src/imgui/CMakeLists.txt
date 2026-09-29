# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  BackendImGui.cpp
  SceneImGui.cpp
  dialogImGui.cpp
  fieldImGui.cpp
  menuImGui.cpp
  treeImGui.cpp
  fontsImGui.cpp
  fileChooserImGui.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/imgui "${SRC};${HDR}")
