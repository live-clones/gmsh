This directory contains the Gmsh Fortran tutorials, written using the Gmsh Fortran API.

To compile and run the Fortran tutorials, you need the Gmsh dynamic library and the
associated Fortran module (`gmsh.f90'). These can be either obtained

- from the binary Software Development Kit (SDK) available on the Gmsh website
  https://gmsh.info/bin/, for Windows, Linux and macOS. Download and uncompress
  the relevant gmsh*-sdk.* archive for your operating system. To compile the
  first tutorial, assuming that you are currently in the root directory of the
  SDK and that you are using the gfortran compiler:

    gfortran -o t1 include/gmsh.f90 share/doc/gmsh/tutorials/fortran/t1.f90 -Llib -lgmsh

  Then run

    ./t1

- by compiling the Gmsh source code. Follow these steps in the top-level
  directory of the Gmsh source code:

    mkdir build
    cd build
    cmake -DENABLE_BUILD_DYNAMIC=1 ..
    make
    make install
    cd ..

  Then, assuming that you are using the gcc compiler:

    gfortran -o t1 /usr/local/include/gmsh.f90 t1.f90 -L/usr/local/lib -lgmsh
    ./t1

For other Fortran API examples, see the `examples/api' directory.
