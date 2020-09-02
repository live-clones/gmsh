HXT
===


HXT is a collection of libraries for mesh generation, developed by the Hextreme
project group:

https://www.hextreme.eu/project/


## Compiling HXT modules

Each part of HXT can be compiled independently. For example, to compile the
tetrahedral mesh generation module (*tetMesh*):

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_C_FLAGS="-march=native" \
      -DCMAKE_CXX_FLAGS="-march=native" \
      -DHXT_TETMESH_OBJECT_ONLY=OFF \ # to produce an actual library archive
      ../tetMesh
make -j
```

Note that if you intend to build multiple modules, you better choose a
different name for your *build* directory, like *tetMeshBuild*, or create it in
the modules folder: *tetMesh/build*. The rest is classical CMake, except
for a few parameters:

 * We added the `-march=native` flag, so the compiled program is optimized to
   work only on the current (native) machine. Some parts of the tetMesh library
   will be automatically vectorized only when the underlying hardware is known.
 * To produce an actual library archive, each module *Module* has an associated
   option `HXT_MODULE_OBJECT_ONLY` that must be set to `OFF`. If you let it
   `ON`, the library is a CMake [object
   library](https://cmake.org/cmake/help/v3.9/command/add_library.html#object-libraries)
   that can only be used as a CMake target.


A few other remarks concerning the compilation of HXT:

 * modules depends on each other, so if you need the tetMesh module, you
   **cannot** simply keep the tetMesh folder and throw the others away.
 * HXT itself is not a module, **the top-level CMakeLists.txt file is only
   meant to be used by Gmsh**. If you want to create a library that contains
   all HXT, just create your own CMakeLists.txt file with a library target that
   depends on every module.


## The tetMesh module

In addition to a library for tetrahedral mesh generation, the tetMesh module
contains multiple programs:

 * **tetMesh_CLI**: A very efficient tetrahedral mesh generator that takes MSH2
   *.msh* surfaces meshes (containing only triangles, lines and points) as
   input and outputs a quality tetrahedral mesh.
 * **Delaunay_CLI**: A simple 3D Delaunay triangulator. It either generates
   random points from a uniform distribution (`-g` option), or takes a MSH2
   *.msh* file as input. In the later case, it will only take the nodes into
   account, ignoring all types of elements and other information. For example,
   `./Delaunay_CLI -sv2 -G10000000` will show you logs that are very similar to
   what is found in Table 2 of [our paper: "One machine, one minute, 3 billion
   tetrahedra"](https://doi.org/10.1002/nme.5987).
 * **tetOpti_CLI**: Optimize an existing tetrahedral mesh contain in a MSH2
   *.msh* file. This executable is not stable.


## Other modules

 * the **core** module contains the definition of the mesh structure `HXTMesh`,
   the definition of return status, functions to read and write MSH2 files,
   function for allocations, logging, command-line argument handling and more
   small utilities. It also provide a small bounding box object, as well as
   sorting functions, primarily based on radix sort.
 * the **predicates** module is a simple wrapper around [Shewchuk's geometric
   predicates](https://www.cs.cmu.edu/~quake/robust.html)
 * the **reparam** module contains functions to compute the curvature of a
   surface mesh and solvers for the computation of crossfields.
 * the **sizeField** folder is not really a module at the moment. It is a work
   in progress for generating an isotropic size field suitable for volume
   meshing.
 * the **tetBR** module is a wrapper around TetGen's boundary recovery code.
   See *CREDITS.txt* for licence agreements.


## Linking an HXT module to your CMake target

By default, HXT's library targets are [object libraries
](https://cmake.org/cmake/help/v3.9/command/add_library.html#object-libraries),
unless the associated option `HXT_XXX_OBJECT_ONLY` is set to `OFF`. The
difference with a standard library target is that it doesn't create any actual
library archive. If you link the target to yours properly, the object files
created after compiling each source file will simply be added to yours. That
allows you to perform whole-program optimizations and other cool stuffs.

The downside of object libraries in CMake is that they do not propagate
dependencies. This means that if you want to link your target named `my_target`
with the *tetMesh* object library, you will also have to link with all
dependencies of the hxt_tetMesh target. Actually, it is not difficult

```CMake
add_subdirectory(hxt/tetMesh) # assume hxt is in your top-level directory
target_link_libraries(my_target hxt_core hxt_predicates hxt_tetBR hxt_tetMesh)
```

If you want to add link-time optimization (LTO) to your program, you can do:

```CMake
set_target_properties(my_target hxt_core hxt_predicates hxt_tetBR hxt_tetMesh
                      PROPERTIES INTERPROCEDURAL_OPTIMIZATION True)
```

If you don't want to compile the programs provided within the tetMesh module:
```CMake
set(HXT_TETMESH_BUILD_CLI OFF CACHE BOOL "no tetMesh programs, only library")
```


In summary, your *CMakeLists.txt* file may resemble this one:
```CMake
cmake_minimum_required(VERSION 3.9)
project(my_test C CXX)

add_executable(my_target "my_meshing_program.c")

set(HXT_TETMESH_BUILD_CLI OFF CACHE BOOL "no tetMesh programs, only library")
add_subdirectory(hxt/tetMesh)
target_link_libraries(my_target hxt_core
                                hxt_predicates
                                hxt_tetBR
                                hxt_tetMesh)


set_target_properties(my_target hxt_core hxt_predicates hxt_tetBR hxt_tetMesh
                      PROPERTIES INTERPROCEDURAL_OPTIMIZATION True)
```

### TODO/future work

core + others:

 - extend HXT to 40+ bits nodes, 32 bits colors

tetMesh:

 - compute Moore indices on the fly, only when few point to insert or few tetrahedra to optimize
 - try a mesh improvement parallelization based on Geogram point-associated locks
 - add edge-collapse and point insertion
 - modify surface mesh up to a certain distance allowed
 - add a pass of smoothing aimed solely at mesh size control
 - track the order of allocated blocks in reproducible Delaunay
 - simplify the check between Hxt colors and Gmsh colors
 - code the boundary recovery, to replace the tetBR module

## References

A full list of publication linked to the Hextreme project is available at:

https://www.hextreme.eu/publications/


More specifically, to reference the *tetMesh* HXT module, please cite it as: 

- Marot, C, Pellerin, J, Remacle, J‐F. One machine, one minute, three billion
 tetrahedra. Int J Numer Methods Eng. 2019; 117: 967– 990.
 https://doi.org/10.1002/nme.5987