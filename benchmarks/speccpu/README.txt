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
intepreter is necessary). Morover, the .geo script only use the simple built-in
CAD kernel (e.g. not OpenCASCADE) so that the gmsh binary depends on as few
third-party libraries as possible.

We verify the generated mesh at using directives in the .geo script. Inside each
script the final step is to check how many elements were used for meshing, and
whether or not that conforms to the specified request. This is an important
verification step, as meshing is by nature a non-linear process, and very
sensitive to floating point math, compiler optimizations, and hardware
implementations.  The check is to ensure the resulting mesh falls within a
strict bound, even though it is not exactly matching the reference. This aligns
with the user behavior and flow of 3D-meshing in general; since the resulting
mesh model is used downstream in 3D workspaces and only needs to be sufficiently
dense for CAD work, and not necessarily exact.

Here are the current cmdlines used for reference benchmarks. The result of the
benchmark is appended to a file with the same name as the .geo script, with the
.geo extension changed to ".val".

* refrate (single threaded, within 1.8GB memory footprint):

  # spec.geo:
  # 1D, 2D and 3D unstructured mesh, simple cubes with plane surfaces
  gmsh spec.geo -option gmsh.opts -clscale 0.2 -nt 1 -algo front2d -algo del3d -cpu -
  gmsh spec.geo -option gmsh.opts -clscale 0.17 -nt 1 -algo del2d -algo hxt -cpu -

  # Torus.geo:
  # 1D, 2D and 3D unstructured mesh, single volume, few curved surfaces
  gmsh Torus.geo -option gmsh.opts -nt 1 -cpu -

  # gasdis.geo
  # 1D, 2D and 3D unstructured mesh, single volume, many curved surfaces
  gmsh gasdis.geo -option gmsh.opts -nt 1 -cpu -

  # p19.geo:
  # 1D, 2D and 3D unstructured mesh, multiple volumes, curved surfaces
  gmsh p19.geo -option gmsh.opts -nt 1 -cpu -

  # stator1920.geo:
  # 1D, 2D and 3D unstructured mesh, many volumes, high-order
  gmsh stator1920.geo -option gmsh.opts -nt 1 -cpu -

  # geom8du.geo:
  # 1D, 2D and 3D unstructured mesh, multiscale geometry
  gmsh geom8du.geo -option gmsh.opts -nt 1 -cpu -

  # projection.geo:
  # 1D and 2D structured and unstructured mesh, twisted surface
  gmsh projection.geo -option gmsh.opts -nt 1 -cpu -

  # mediterranean.geo:
  # 1D and 2D unstructured mesh, multiscale curved surface
  gmsh mediterranean.geo -option gmsh.opts -nt 1 -cpu -

* refspeed (multi threaded, within 64GB memory footprint)

  # spec.geo:
  # 1D, 2D and 3D unstructured mesh, simple cubes with plane surfaces
  gmsh spec.geo -option gmsh.opts -nt 0 -clscale 0.05 -algo front2d -algo hxt -cpu -
  gmsh spec.geo -option gmsh.opts -nt 0 -clscale 0.05 -algo del2d -algo hxt -cpu -

  # choi.geo:
  # 1D, 2D and 3D unstructured mesh, complex model
  gmsh choi.geo -option gmsh.opts -nt 0 -cpu -

  # TieAnchor520.geo
  # 1D and 2D unstructured mesh, many surfaces
  gmsh TieAnchor520.geo -option gmsh.opts -nt 0 -cpu -
