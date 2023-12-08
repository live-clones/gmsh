Mahesh Madhav, Christophe Geuzaine
August-September 2023

This directory contains geo scripts for SPEC CPUv8 (www.spec.org/cpuv8), where
gmsh is a candidate benchmark under the name of 737.gmsh_r. We are trying to
craft cmdlines that are representative of gmsh meshing use, where the "work
completed" can be verified as "equal work" within some tolerance.  This enables
multiple architecture/compiler combinations to run the cmdline and output almost
the same result, allowing comparisons of CPU performance.  The guidance is to
NOT be i/o bound, so we skip saving the mesh file to disk.

All the input files are given as .geo scripts so that gmsh can be used as a
single monolithic executable without extra dependencies (e.g. no Python
interpreter is necessary). Morover, the .geo scripts only use the simple built-in
CAD kernel (e.g. not OpenCASCADE) so that the gmsh binary depends on as few
third-party libraries as possible.

We verify the generated mesh by using directives in the .geo script. Inside each
script the final step is to check how many elements were used for meshing, and
whether or not that conforms to the specified request. This is an important
verification step, as meshing is by nature a non-linear process, and very
sensitive to floating point math, compiler optimizations, and hardware
implementations.  The check is to ensure the resulting mesh falls within a
strict bound, even though it is not exactly matching the reference. This aligns
with the user behavior and flow of 2D/3D unstructured meshing in general; since the
resulting mesh is used downstream in simulation workflows that only require sufficiently
dense meshes depending on the underlying physical/mathematical models to solve, but not
on exact element counts.

The current command lines used for reference benchmarks are provided in the

> run_spec.sh

script. The result of each benchmark is appended to a file with the same name as
the .geo script, with the .geo extension changed to ".val".
