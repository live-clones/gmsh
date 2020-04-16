This directory contains the Gmsh Python tutorials, written using the Gmsh Python
API.

To run the Python tutorials, you need the Gmsh dynamic library and the Python
module (`gmsh.py'). These can be either obtained

- using `pip install --upgrade gmsh', which will download the binary SDK
  automatically, and install the files in the appropriate system directories.

- from the binary Software Development Kit (SDK) available on the Gmsh website
  http://gmsh.info/bin/, for Windows, Linux and macOS. Download and uncompress
  the relevant gmsh*-sdk.* archive for your operating system and add the "lib"
  directory from the SDK to PYTHONPATH, e.g., if you are currently in the root
  directory of the SDK:

    export PYTHONPATH=${PYTHONPATH}:${PWD}/lib

- by compiling the Gmsh source code. Follow these steps in the top-level
  directory of the Gmsh source code:

    mkdir build
    cd build
    cmake -DENABLE_BUILD_DYNAMIC=1 ..
    make
    make install
    cd ..

  Add the installation directory (by default /usr/local/lib) to PYTHONPATH, e.g.

    export PYTHONPATH=${PYTHONPATH}:/usr/local/lib

You can then run e.g. "python t1.py"

For other Python API examples, see the `demos/api' directory.
