#!/bin/bash

# refrate (single threaded, within 1.8GB memory footprint):

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

# stator1910.geo:
# 1D, 2D and 3D unstructured mesh, many volumes, high-order
gmsh stator1910.geo -option gmsh.opts -nt 1 -cpu -

# geom8du.geo:
# 1D, 2D and 3D unstructured mesh, multiscale geometry
gmsh geom8du.geo -option gmsh.opts -nt 1 -cpu -

# projection.geo:
# 1D and 2D structured and unstructured mesh, twisted surface
gmsh projection.geo -option gmsh.opts -nt 1 -cpu -

# mediterranean.geo:
# 1D and 2D unstructured mesh, multiscale curved surface
gmsh mediterranean.geo -option gmsh.opts -nt 1 -cpu -

# refspeed (multi threaded, within 64GB memory footprint)

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
