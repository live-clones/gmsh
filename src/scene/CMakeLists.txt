# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# The scene proper: OpenGL and Gmsh, and no toolkit at all. Whichever
# interface is up holds it through Scene::Host.
# drawContextGL.cpp: the drawing functions of a scene asked of its holder,
# and the Embedded font engine, which every interface uses
set(SRC
  sceneHost.cpp
  sceneView.cpp
  sceneGamepad.cpp
  Navigator.cpp
  drawContextGL.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/scene "${SRC};${HDR}")
