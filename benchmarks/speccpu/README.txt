Mahesh Madhav, Christophe Geuzaine
August-September 2023

This directory contains geo scripts for SPEC CPUv8 (www.spec.org/cpuv8),
where gmsh is a candidate benchmark under the name of 737.gmsh_r. We are
trying to craft cmdlines that are representative of gmsh meshing use, where
the "work completed" can be verified as "equal work" within some tolerance.
This enables multiple architecture/compiler combinations to run the cmdline
and output almost the same result, allowing comparisons of CPU performance.
The guidance is to NOT be i/o bound, so we skip saving the mesh file to disk.

All the input files are given as .geo scripts so that gmsh can be used as a
single monolithic executable without extra dependencies (e.g. no Python
interpreter is necessary). Morover, the .geo scripts only use the simple
built-in CAD kernel (e.g. not OpenCASCADE) so that the gmsh binary depends on
as few third-party libraries as possible.

We verify the generated mesh by using directives in the .geo script. Inside each
script the final step is to check how many elements were used for meshing,
and whether or not that conforms to the specified request. This is an
important verification step, as meshing is by nature a non-linear process,
and very sensitive to floating point math, compiler optimizations, and
hardware implementations.  The check is to ensure the resulting mesh falls
within a strict bound, even though it is not exactly matching the reference.
This aligns with the user behavior and flow of 2D/3D unstructured meshing in
general; since the resulting mesh is used downstream in simulation workflows
that only require sufficiently dense meshes depending on the underlying
physical/mathematical models to solve, but not on exact element counts.

Here are the current cmdlines used for reference benchmarks. The result of
each benchmark is appended to a file with the same name as the .geo script,
with the .geo extension changed to ".val".

* test (single threaded and/or multi threaded, dead-or-alive test)

  # spec.geo:
  # 1D, 2D and 3D unstructured mesh, simple cubes with plane surfaces
  gmsh spec.geo -option gmsh.opts -smooth 0 -clscale .60 -nt 1 -

* train (short, used for compiler FDO training)

  # spec.geo:
  # 1D, 2D and 3D unstructured mesh, simple cubes with plane surfaces
  gmsh spec.geo -option gmsh.opts -smooth 2 -clscale .25 -nt 1 -

* refrate (single threaded, within 1.8GB memory footprint):

  # spec.geo:
  # 1D, 2D and 3D unstructured mesh, simple cubes with plane surfaces
  gmsh spec.geo -option gmsh.opts -clscale 0.175 -algo del2d -algo hxt -nt 1 -

  # Torus.geo:
  # 1D, 2D and 3D unstructured mesh, single volume, few curved surfaces
  gmsh Torus.geo -option gmsh.opts -nt 1 -

  # gasdis.geo
  # 1D, 2D and 3D unstructured mesh, single volume, many curved surfaces
  gmsh gasdis.geo -option gmsh.opts -nt 1 -

  # p19.geo:
  # 1D, 2D and 3D unstructured mesh, multiple volumes, curved surfaces
  gmsh p19.geo -option gmsh.opts -nt 1 -

  # projection.geo:
  # 1D and 2D structured and unstructured mesh, twisted surface
  gmsh projection.geo -option gmsh.opts -nt 1 -

  # mediterranean.geo:
  # 1D and 2D unstructured mesh, multiscale curved surface
  gmsh mediterranean.geo -option gmsh.opts -nt 1 -

  # sphere-discrete.geo
  # reads in a file of nodes...
  gmsh sphere-discrete.geo -option gmsh.opts -nt 1 -

* refspeed (multi threaded, within 64GB memory footprint)

  # spec.geo:
  # 1D, 2D and 3D unstructured mesh, simple cubes with plane surfaces
  gmsh spec.geo -option gmsh.opts -clscale 0.05 -algo del2d -algo hxt -nt 0 -

  # Torus_dense.geo:
  # 1D, 2D and 3D unstructured mesh, single volume, few curved surfaces
  gmsh Torus_dense.geo -option gmsh.opts -nt 0 -

  # stator1910.geo:
  # 1D, 2D and 3D unstructured mesh, many volumes, high-order
  gmsh stator1910.geo -option gmsh.opts -nt 0 -

  # geom8du.geo:
  # 1D, 2D and 3D unstructured mesh, multiscale geometry
  gmsh geom8du.geo -option gmsh.opts -nt 0 -

  # TieAnchor520.geo
  # 1D and 2D unstructured mesh, many surfaces
  gmsh TieAnchor520.geo -option gmsh.opts -nt 0 -
