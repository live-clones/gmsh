# Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  FlGui.cpp
    graphicWindow.cpp
      openglWindow.cpp
    menuWindow.cpp
    optionWindow.cpp
      colorbarWindow.cpp
    fieldWindow.cpp
    pluginWindow.cpp
    statisticsWindow.cpp
    visibilityWindow.cpp
    clippingWindow.cpp
    messageWindow.cpp
    manipWindow.cpp
    contextWindow.cpp
    solverWindow.cpp
    aboutWindow.cpp
    fileDialogs.cpp
    extraDialogs.cpp
    projectionEditor.cpp
    classificationEditor.cpp
    partitionDialog.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_SOURCE_DIR}/Fltk *.h) 
append_gmsh_src(Fltk "${SRC};${HDR}")
