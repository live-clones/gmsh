# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# The scene proper: OpenGL and Gmsh, and no toolkit at all. Whichever
# interface is up holds it through Scene::Host.
set(SRC
  sceneHost.cpp
  sceneView.cpp
  sceneGamepad.cpp
  Navigator.cpp
)

# And the part that is held by GLFW rather than by a widget: the window of its
# own that a chrome drawing no scene pairs with, and the text engine that
# takes its glyphs from the Dear ImGui font atlas. Both want a Dear ImGui
# context to exist, even one holding no window, which is why they are not the
# scene itself -- an interface built without them still has one.
if(HAVE_GLFW)
  list(APPEND SRC
    drawContextGL.cpp
    sceneWindow.cpp
  )
endif()

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/scene "${SRC};${HDR}")
