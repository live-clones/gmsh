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

# The drawing functions of a scene held by OpenGL alone, GLFW's or a
# GtkGLArea's; and the part that is held by GLFW rather than by a widget: the
# window of its own that an interface drawing no scene pairs with (a canvas of
# the page, compiled to WebAssembly)
if(HAVE_GLFW OR HAVE_GTK)
  list(APPEND SRC drawContextGL.cpp)
endif()
if(HAVE_GLFW)
  list(APPEND SRC sceneWindow.cpp)
endif()

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/scene "${SRC};${HDR}")
