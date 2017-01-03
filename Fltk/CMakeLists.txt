# Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

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
    helpWindow.cpp
    fileDialogs.cpp
    extraDialogs.cpp
    projectionEditor.cpp
    classificationEditor.cpp
    partitionDialog.cpp
    inputValue.cpp inputRegion.cpp
    viewButton.cpp solverButton.cpp
    Navigator.cpp
    onelabGroup.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Fltk "${SRC};${HDR}")
