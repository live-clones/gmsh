This directory contains FTXUI 7.0.3 (https://github.com/ArthurSonzogni/FTXUI),
used by the terminal interface of Gmsh (ENABLE_TUI).

Only the library is vendored: include/ and src/, without the tests, fuzzers
and benchmarks of src/, nor the meson files; src/ftxui/component/loop.cpp,
which the upstream build does not compile (Loop is defined in app.cpp), is left
out too. The upstream CMakeLists.txt, which also builds the examples, the
documentation and the C++20 modules, is replaced by the CMakeLists.txt here,
which compiles the same sources as its screen, dom and component libraries,
into one static library named ftxui.

FTXUI is distributed under the MIT license (see LICENSE).
