#!/bin/bash -x

# point to your gmsh binary
GMSH=../../build/gmsh

# clean up from previous run
rm *.val

####################################################################
# test {single threaded and/or multi threaded, dead-or-alive test)
####################################################################

# spec.geo:
# 1D, 2D and 3D unstructured mesh, simple cubes with plane surfaces
${GMSH} spec.geo -option gmsh.opts -smooth 0 -check -clscale .60 -nt 1 -cpu -


####################################################################
# train {short, used for compiler FDO training)
####################################################################

# spec.geo:
# 1D, 2D and 3D unstructured mesh, simple cubes with plane surfaces
${GMSH} spec.geo -option gmsh.opts -smooth 2 -check -clscale .25 -nt 1 -cpu -


####################################################################
# refrate {single threaded, within 1.8GB memory footprint):
####################################################################

# spec.geo:
# 1D, 2D and 3D unstructured mesh, simple cubes with plane surfaces
${GMSH} spec.geo -option gmsh.opts -check -clscale 0.175 -algo del2d -algo hxt -nt 1 -cpu -

# Torus.geo:
# 1D, 2D and 3D unstructured mesh, single volume, few curved surfaces
${GMSH} Torus.geo -option gmsh.opts -smooth 3 -clscale 0.250 -algo del2d -algo hxt -nt 1 -cpu -

# gasdis.geo
# 1D, 2D and 3D unstructured mesh, single volume, many curved surfaces
${GMSH} gasdis.geo -option gmsh.opts -smooth 2 -clscale 0.900 -algo del2d -algo hxt -nt 1 -cpu -

# p19.geo:
# 1D, 2D and 3D unstructured mesh, multiple volumes, curved surfaces
${GMSH} p19.geo -option gmsh.opts -check -smooth 1 -clscale 0.115 -algo del2d -algo hxt -nt 1 -cpu -

# projection.geo:
# 1D and 2D structured and unstructured mesh, twisted surface
${GMSH} projection.geo -option gmsh.opts -smooth 2 -clscale 0.041 -algo del2d -nt 1 -cpu -

# mediterranean.geo:
# 1D and 2D unstructured mesh, multiscale curved surface
${GMSH} mediterranean.geo -option gmsh.opts -clscale 0.500 -algo front2d -nt 1 -cpu -

# sphere-discrete.geo
# reads in a file of nodes...
${GMSH} sphere-discrete.geo -option gmsh.opts -check -smooth 3 -clscale 0.070 -algo hxt -nt 1 -cpu -


####################################################################
# refspeed {multi threaded, within 64GB memory footprint)
####################################################################

# Torus_dense.geo:
# 1D, 2D and 3D unstructured mesh, single volume, few curved surfaces
${GMSH} Torus_dense.geo -option gmsh.opts -smooth 3 -nt 0 -cpu -

# stator1920.geo:
# 1D, 2D and 3D unstructured mesh, many volumes, high-order
${GMSH} stator1920.geo -option gmsh.opts -nt 0 -cpu -

# geom8du.geo:
# 1D, 2D and 3D unstructured mesh, multiscale geometry
${GMSH} geom8du.geo -option gmsh.opts -nt 0 -cpu -

# TieAnchor520.geo
# 1D and 2D unstructured mesh, many surfaces
${GMSH} TieAnchor520.geo -option gmsh.opts -nt 0 -cpu -

echo " - - - - "
grep Error *.val || echo "Zero Errors in .val files!"
