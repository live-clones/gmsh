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

# And the part that comes with GLFW rather than with a widget: the text engine
# that takes its glyphs from the Dear ImGui font atlas. It wants a Dear ImGui
# context to exist, which is why it is not the scene itself -- an interface
# built without it still has one.
if(HAVE_GLFW)
  list(APPEND SRC
    drawContextGL.cpp
  )
endif()

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/scene "${SRC};${HDR}")
