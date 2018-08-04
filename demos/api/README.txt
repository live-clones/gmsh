This directory contains examples on how to use the Gmsh API.

The files t1.*, t2.*, ... are reimplementations in C++ (.cpp), C (.c), Python
(.py) and Julia (.jl) of the corresponding .geo tutorials. The other files show
how to use various other Gmsh API functions.

To run the examples, you need the Gmsh dynamic library and the associated header
files (for C++ and C) or modules (for Python and Julia). This library and the
associated files can be either obtained from the binary Software Development Kit
(SDK), or can be rebuilt from the Gmsh source code.

Using the Gmsh binary Software Development Kit (SDK)
----------------------------------------------------

The binary SDKs are available for Windows, Linux and MacOS: browse
http://gmsh.info/bin/ to download the relevant gmsh*-sdk.* archive for your
operating system.

To run the Python examples, add the "lib" directory from the SDK to PYTHONPATH,
e.g., if you are currently in the root directory of the SDK:

   export PYTHONPATH=${PYTHONPATH}:${PWD}/lib

then run e.g.

   python share/doc/gmsh/demos/api/t1.py

To run the Julia examples, add the "lib" directory from the SDK to
JULIA_LOAD_PATH, e.g.

   export JULIA_LOAD_PATH=${JULIA_LOAD_PATH}:${PWD}/lib

then run e.g.

   julia share/doc/gmsh/demos/api/t1.jl

To run the C++ examples, compile them (here with GCC) as follows:

   g++ -o t1 -Iinclude share/doc/gmsh/demos/api/t1.cpp -Llib -lgmsh

then run

   ./t1

If your compiler has a different ABI than the compiler used to generate the
binary SDK (see the top-level README.txt file in the SDK for additional
information), you should use the "gmsh.h_cwrap" header instead of "gmsh.h".  For
example, to compile a C++ example with Microsoft Visual Studio 2017 in the
Visual Studio shell:

C:\gmsh-git-Windows64-sdk> ren include\gmsh.h_cwrap gmsh.h
C:\gmsh-git-Windows64-sdk> cl /Iinclude share\doc\gmsh\demos\api\simple.cpp lib\gmsh.lib
C:\gmsh-git-Windows64-sdk> cd lib
C:\gmsh-git-Windows64-sdk\lib> ..\simple.exe

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

To run the Python examples, add the "api" directory to PYTHONPATH, e.g.

   export PYTHONPATH=${PYTHONPATH}:${PWD}/api

then run

   python demos/api/t1.py

To run the Julia examples, add the "api" directory to JULIA_LOAD_PATH, e.g.

   export JULIA_LOAD_PATH=${JULIA_LOAD_PATH}:${PWD}/lib

then run e.g.

   julia demos/api/t1.jl

To run the C++ examples, compile them e.g. with

  cd demos/api
  mkdir build
  cd build
  cmake ..
  make

then run

  ./t1
