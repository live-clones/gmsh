# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  imgui.cpp
  imgui_draw.cpp
  imgui_tables.cpp
  imgui_widgets.cpp
  imgui_demo.cpp
  misc/cpp/imgui_stdlib.cpp
    backends/imgui_impl_glfw.cpp
    backends/imgui_impl_opengl2.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/imgui "${SRC};${HDR}")
