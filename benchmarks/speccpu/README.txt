Mahesh Madhav
August 2023

This directory contains geo scripts for SPEC CPUv8 (www.spec.org/cpuv8),
where gmsh is a candidate benchmark under the name of 737.gmsh_r. We are
trying to craft cmdlines that are representative of gmsh meshing use, where
the "work completed" can be verified as "equal work" within some tolerance.
This enables multiple architecture/compiler combinations to run the cmdline
and output almost the same result, allowing comparisons of CPU performance.
The guidance is to NOT be i/o bound, so we would suggest skip saving the mesh
file to disk especially when it is very large. We don't verify that way anyway.

We verify using directives in the .geo script. Inside each script the final
step is to check how many tetrahedrons were used for meshing, and whether or
not that conforms to the specified request. This is an important verification
step, as meshing is by nature a non-linear process, and very sensitive to
floating point math, compiler optimizations, and hardware implementations.
The check is to ensure the resulting mesh falls within a strict bound, even
though it is not exactly matching the reference. This aligns with the user
behavior and flow of 3D-meshing in general; since the resulting mesh model is
used downstream in 3D workspaces and only needs to be sufficiently dense for
CAD work, and not necessarily exact.


Here are the current cmdlines used for reference benchmarks (July 2023).
spec.geo was the first proof-of-concept to use the verification scheme, as
it is a simple rectangular prism. sphere-discrete.geo is more complex and
doesn't yet have a verification formula. spec.geo's verification is robust
enough to work for a range of clscale levels and different meshing
algorithms, so it is a great example to learn from.
------------------------------------------------------------------------------
refrate (single threaded, within 1.8GB memory footprint)
  -option gmsh.opts        -smooth 2 -clscale 0.11 -nt 1 -algo meshadapt spec.geo
  -option gmsh.opts -check -smooth 2 -clscale 0.16 -nt 1 -algo hxt       spec.geo
  -option gmsh.opts -check -smooth 2 -clscale 0.05 -nt 1 -algo del3d     sphere-discrete.geo
  -option gmsh.opts -check -smooth 3 -clscale 0.06 -nt 1 -algo hxt       sphere-discrete.geo

refspeed (multi threaded, within 64GB memory footprint)
  -option gmsh.opts -smooth 3 -clscale 0.06 -nt 0 -algo meshadapt spec.geo
  -option gmsh.opts -smooth 3 -clscale 0.08 -nt 0 -algo hxt       spec.geo
  -option gmsh.opts -smooth 4 -clscale 0.07 -nt 0 -algo del3d     spec.geo
------------------------------------------------------------------------------


Here are cmdlines we would like to enable and investigate for benchmarking,
to offer more coverage and variety of behavior. They do not yet have
verification formulas. I've tested them to check for the runlenghts and
memory requirements needed for SPEC CPU. There are more listed below than
what can be used in the final benchmark suite, because we would like
a deep roster to choose from. This is especially important when test esoteric
hardware that has trouble verifying a particular cmdline, but is ok on a
different one. The final cmdlines may add a different -clscale value to
adjust for runtime requirements. We are not beholden to the switches listed;
if others allow for more realistic usage and coverage, please suggest those!
------------------------------------------------------------------------------
refrate (single threaded, within 1.8GB memory footprint)
  sphere-discrete.geo -algo hxt -nt 1 -clscale 0.06
  projection.geo -2 -algo del2d -nt 1 -clscale 0.1
  Torus.geo -3 -nt 1 -clscale 0.4
  geom8du.geo -3 -nt 1 -clscale 0.4
  p19.geo -3 -nt 1 -clscale 0.2 -bin
  stator1920.geo -clscale 0.14 -algo hxt -3 -cpu -order 4
  gasdis.geo -3 --smooth 0 
  mediterranean.geo -2

refspeed (multi threaded, within 64GB memory footprint)
  choi.geo -3 -algo hxt -algo del2d -nt 60 -clscale 0.3
  many_holes.geo -2 -algo hxt -algo del2d -nt 40 -clscale 0.5
------------------------------------------------------------------------------

