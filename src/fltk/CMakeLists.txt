# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  FlGui.cpp
  GuiFltk.cpp
  BackendFltk.cpp
  CreateFileFltk.cpp
    graphicWindow.cpp menuFltk.cpp dialogFltk.cpp
    graphicsFonts.cpp
      openglWindow.cpp
      colorbarWindow.cpp
    drawContextFltkCairo.cpp
    drawContextFltkStringTexture.cpp

    onelabGroup.cpp
    fileDialogs.cpp
    extraDialogs.cpp

    inputValue.cpp
    viewButton.cpp solverButton.cpp
    Navigator.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/fltk "${SRC};${HDR}")
