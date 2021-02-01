# Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  FlGui.cpp
    graphicWindow.cpp
      openglWindow.cpp
    optionWindow.cpp
      colorbarWindow.cpp
    drawContextFltkCairo.cpp
    drawContextFltkStringTexture.cpp
    gamepadWindow.cpp
    fieldWindow.cpp
    pluginWindow.cpp
    statisticsWindow.cpp
    visibilityWindow.cpp
    highOrderToolsWindow.cpp
    clippingWindow.cpp
    manipWindow.cpp
    contextWindow.cpp
    onelabContextWindow.cpp
    onelabGroup.cpp
    helpWindow.cpp
    fileDialogs.cpp
    extraDialogs.cpp
    classificationEditor.cpp
    partitionDialog.cpp
    inputValue.cpp
    viewButton.cpp solverButton.cpp
    Navigator.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(Fltk "${SRC};${HDR}")
