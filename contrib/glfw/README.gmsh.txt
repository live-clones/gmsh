This directory contains GLFW 3.4 (https://www.glfw.org), used by the Dear ImGui
frontend of Gmsh (ENABLE_IMGUI).

Unlike most other contribs, GLFW is built through its own upstream CMakeLists.txt
(added with add_subdirectory from the top-level Gmsh CMakeLists.txt): it selects
the platform backends (X11, Wayland, Cocoa, Win32) and the corresponding
_GLFW_* compile definitions, which would be impractical to reproduce by hand.

The docs/, examples/ and tests/ directories of the upstream release have been
removed, as well as the parts of deps/ that are only used by them; deps/wayland
(the Wayland protocol descriptions compiled by wayland-scanner) and deps/mingw
are kept, as the library itself needs them.

GLFW is distributed under the zlib/libpng license (see LICENSE.md).

Local modifications:

* CMakeLists.txt: the cmake_minimum_required() lower bound was raised from 3.4
  to 3.10 (the same value Gmsh itself requires), because CMake >= 4.0 refuses
  compatibility with CMake < 3.5.
