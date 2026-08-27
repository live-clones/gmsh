# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  Gui.cpp
  appWindow.cpp
  scenePane.cpp
  drawContextImGui.cpp
  messageConsole.cpp
  statusBar.cpp
  menuBar.cpp
  shortcuts.cpp
  panels.cpp
  visibilityPanel.cpp
  colormapPanel.cpp
  modulesPanel.cpp
  exportDialog.cpp
  toolPanels.cpp
  contextPanels.cpp
  helpPanel.cpp
  fonts.cpp
  meshToolPanels.cpp
  onelabContextPanel.cpp
  fileBrowser.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/imgui "${SRC};${HDR}")
