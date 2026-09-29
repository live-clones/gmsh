# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  Gui.cpp
  GuiDialog.cpp
  GuiScene.cpp
  GuiModules.cpp
  GuiActions.cpp
  GuiActionsGeo.cpp
  GuiMenus.cpp
  GuiElementary.cpp
  GuiPhysical.cpp
  GuiTransform.cpp
  GuiMeshContext.cpp
  GuiPartition.cpp
  GuiHighOrder.cpp
  GuiManipulator.cpp
  GuiStatistics.cpp
  GuiClipping.cpp
  GuiGamepad.cpp
  GuiOptions.cpp
  GuiVisibility.cpp
  GuiPlugins.cpp
  GuiFields.cpp
  GuiHelp.cpp
  GuiClassify.cpp
  GuiOnelab.cpp
  GuiPrompts.cpp
  GuiStatus.cpp
  GuiFiles.cpp
  GuiExport.cpp
  VisibilityList.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/gui "${SRC};${HDR}")
