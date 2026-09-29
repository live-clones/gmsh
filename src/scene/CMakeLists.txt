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

# The drawing functions of a scene held by OpenGL alone -- GLFW's, a
# GtkGLArea's, a QOpenGLWidget's, an NSOpenGLView's, a WGL window's or a
# framebuffer off screen: wanted by the interfaces that said so in
# GMSH_GL_HOLDERS
if(GMSH_GL_HOLDERS)
  list(APPEND SRC drawContextGL.cpp)
endif()

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/scene "${SRC};${HDR}")
