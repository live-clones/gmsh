This directory contains examples on how to use the Gmsh API.

The files t1.{cpp,py}, t2.{cpp,py}, ... are reimplementations in C++ and Python
of the corresponding tutorials in gmsh/tutorials.

To run the examples, you first need to build and install the Gmsh library (this
is done automatically when building the dynamically-linked Gmsh app). To do so,
follow these steps, in the top-level directory of the Gmsh source code:

  mkdir build
  cd build
  cmake -DENABLE_BUILD_DYNAMIC=1 ..
  make
  make install

Then, to build and run the C++ examples:

  cd ..
  cd demos/api
  mkdir build
  cd build
  cmake ..
  make
  ./t1
  ./t2

To run the Python examples, add the top-level api directory to your PYTHON_PATH
and simply run the examples with Python:

  export PYTHON_PATH=/path/to/gmsh/api
  python t1.py
  python t2.py
