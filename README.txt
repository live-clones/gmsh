This is Gmsh, an automatic three-dimensional finite element mesh generator with
built-in pre- and post-processing facilities.

Gmsh is copyright (C) 1997-2024 C. Geuzaine and J.-F. Remacle, and is
distributed under the terms of the GNU General Public License, Version 2 or
later, with an exception to allow for easier linking with external
libraries. See LICENSE.txt and CREDITS.txt for more information.

See the doc/ and tutorials/ directories for documentation and tutorials. The
reference manual is located in doc/texinfo/. See the examples/ directory and the
web site https://gmsh.info for additional examples.

Building Gmsh from source code requires a C++ compiler and CMake
(http://cmake.org). Building the graphical user interface requires FLTK 1.3.3 or
higher (FLTK-dev 1.4 is required on macOS; http://fltk.org), configured with
OpenGL support. Support for boolean operations, constructive solid geometry
features and STEP file import requires OpenCASCADE 6.9 or higher (version 7.2 or
higher is highly recommended; http://www.opencascade.com). Step-by-step
compilation instructions are available on the Gmsh wiki:
https://gitlab.onelab.info/gmsh/gmsh/-/wikis/Gmsh-compilation.


Build Gmsh from the command line
--------------------------------

* Create a build directory, for example as a subdirectory of Gmsh's source
  directory:

    mkdir build

* To build the monolithic Gmsh app with the default build options, run cmake
  from within the build directory, pointing to Gmsh's source directory, then run
  "make"

    cd build
    cmake ..
    make

  Optionally running

    make install

  will install the Gmsh app in the standard system location (controlled by
  CMAKE_INSTALL_PREFIX - see below).

* To build the Gmsh app dynamically linked to the shared Gmsh library, which can
  then also be used by external codes through the C++, C, Python, Julia and
  Fortran Gmsh API, run

    cd build
    cmake -DENABLE_BUILD_DYNAMIC=1 ..
    make
    make install

  This will install the Gmsh app and the shared Gmsh library, as well as the C++
  and C include files, and the Python, Julia and Fortran modules.

* To change build options you can use "ccmake" instead of "cmake", e.g.:

    ccmake ..

  or you can specify options directly on the command line. For example, you can
  use

    cmake -DCMAKE_PREFIX_PATH=/opt/local ..

  to specify the location of external packages installed in non-standard
  directories. You can use

    cmake -DCMAKE_INSTALL_PREFIX=/opt

  to change the installation directory. Or you could use

    cmake -DENABLE_FLTK=0 ..

  to build a version of Gmsh without the FLTK graphical interface. The list of
  all available configuration options is given in the reference manual.

* To see a detailed compilation log use

    make VERBOSE=1


Build Gmsh using CMake's graphical user interface
-------------------------------------------------

* Launch CMake and fill-in the two top input fields (telling where the Gmsh
  source directory is located and where you want the Gmsh binary to be created).

* Click on "Add entry" and define the variable CMAKE_PREFIX_PATH, of type
  "PATH", pointing to the location(s) of any external package(s) (FLTK,
  BLAS/LAPACK, etc.) installed in non-standard directories.

* Click on "Configure" and choose your compiler.

* Optionally change some configuration options (re-run "Configure" every time
  you change some options).

* Once you are happy with all the configuration options, click on "Generate".

* Go to the build directory and build Gmsh using your chosen compiler.
