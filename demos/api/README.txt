This directory contains examples on how to use the Gmsh API.

The files t1.{cpp,py}, t2.{cpp,py}, ... are reimplementations in C++ and Python
of the corresponding .geo tutorials. The other files show how to use various
other Gmsh API functions.

To run the examples, you need the Gmsh dynamic library and the associated header
files (for C++ and C) or module (for Python). This library and the associated
files can be either obtained from the binary Software Development Kit (SDK), or
can be rebuilt using the Gmsh source code.

Using the Gmsh binary Software Development Kit (SDK)
----------------------------------------------------

The binary SDKs are available for Windows, Linux and MacOS: browse
http://gmsh.info/bin/ to download the relevant gmsh*-sdk.* archive for your
operating system.

To run the Python examples, add the lib/ directory from the SDK to PYTHONPATH,
e.g.

   export PYTHONPATH=lib

then run

   python share/doc/gmsh/demos/api/t1.py
   python share/doc/gmsh/demos/api/gui.py
   ...

To run the C++ examples, compile them e.g. with

   g++ -o t1 -Iinclude share/doc/gmsh/demos/api/t1.cpp -Llib -lgmsh
   g++ -o gui -Iinclude share/doc/gmsh/demos/api/gui.cpp -Llib -lgmsh
   ...

then run

   ./t1
   ./gui
   ...

Using the Gmsh source code
--------------------------

In order to build and install the Gmsh library and the associated header and
module files, follow these steps in the top-level directory of the Gmsh source
code:

  mkdir build
  cd build
  cmake -DENABLE_BUILD_DYNAMIC=1 ..
  make
  make install
  cd ..

To run the Python examples, add the api/ directory to PYTHONPATH, e.g.

   export PYTHONPATH=api

then run

   python demos/api/t1.py
   python demos/api/gui.py
   ...

To run the C++ examples, compile them e.g. with

  cd demos/api
  mkdir build
  cd build
  cmake ..
  make

then run

  ./t1
  ./gui
  ...
