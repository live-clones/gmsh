# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# What GLFW holds of the scene: the window of its own that an interface
# drawing no scene pairs with (a canvas of the page, compiled to
# WebAssembly), and the screen as GLFW sees it, for the Dear ImGui interface
# too
set(SRC
  sceneWindow.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/glfw "${SRC};${HDR}")
