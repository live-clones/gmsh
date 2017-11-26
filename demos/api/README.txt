This directory contains examples on how to use the Gmsh API in C++ and in
Python. The full API is available in Common/gmsh.h.

The files t1.{cpp,py}, t2.{cpp,py}, ... are reimplementations in C++ and Python
of the corresponding tutorials in gmsh/tutorials.

1) Build and install the Gmsh library (this is done automatically when building
   the dynamically-linked Gmsh app):

  cd gmsh
  mkdir build
  cd build
  cmake -DENABLE_BUILD_DYNAMIC=1 ..
  make
  make install
  cd ..

2a) To build the C++ examples:

  cd demos/api
  mkdir build
  cd build
  cmake ..
  make
  ./t1

2b) To run the Python examples:

  export PYTHON_PATH=/path/to/gmsh/build
  python demos/api/t1.py
