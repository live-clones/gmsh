This directory contains a subset of Dear ImGui (https://github.com/ocornut/imgui),
release v1.92.9b-docking (the "docking" branch, which adds docking and multi-
viewport support on top of the corresponding stable release).

Only the files needed by Gmsh are vendored:

  imconfig.h imgui.h imgui.cpp imgui_draw.cpp imgui_tables.cpp imgui_widgets.cpp
  imgui_internal.h imgui_demo.cpp imstb_rectpack.h imstb_textedit.h
  imstb_truetype.h backends/imgui_impl_glfw.{h,cpp}
  backends/imgui_impl_opengl2.{h,cpp} misc/cpp/imgui_stdlib.{h,cpp}

Dear ImGui is distributed under the MIT license (see LICENSE.txt).
