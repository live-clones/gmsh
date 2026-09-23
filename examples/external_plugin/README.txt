This directory contains a Gmsh plugin built as a shared library:

  - ElementAverage.cpp: Plugin(ElementAverage), a class derived from
    GMSH_PostPlugin, defined for Gmsh by GMSH_PLUGIN() (see Plugin.h)
  - CMakeLists.txt: builds it against an installed Gmsh
  - element_average.py: loads it with gmsh.plugin.load() and runs it

A plugin uses the private API, and is loaded into the shared Gmsh library:
Gmsh must be built with ENABLE_BUILD_DYNAMIC (or ENABLE_BUILD_SHARED) and
ENABLE_PRIVATE_API, on a system with dlopen (Linux, macOS), and installed.
Then:

  mkdir build && cd build && cmake .. && make
  python ../element_average.py ./libElementAverage.so

Gmsh also loads, when it starts, the plugins (.so, .dylib, .dll) in the
directories listed in the GMSHPLUGINSHOME environment variable (separated like
in PATH), so that e.g. `Plugin(ElementAverage).Run;' can be used in a .geo file:

  GMSHPLUGINSHOME=$PWD gmsh file.geo

A plugin must be built with the headers of the Gmsh it is loaded into: Gmsh
refuses a plugin built for another version of the plugin interface
(GMSH_PLUGIN_API_VERSION in Plugin.h).
