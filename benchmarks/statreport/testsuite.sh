#!/bin/bash

if [ $# = 0 ] ; then
  echo "Usage: $0 path/to/gmsh [options]"
  exit 1
fi

if [ ! -e statreport.dat ] ; then
  $@ -statreport statreport.dat -v 1 -2
fi

GMSH="$@ -append_statreport statreport.dat"

# use "> /dev/null" to filter out annoying occ chatter
# use "-v 1" to keep seeing actual error messages

date >> statreport.dat
${GMSH} Block.geo Block.opt -clscale .1 -2 -v 1 > /dev/null
${GMSH} linkrods.geo linkrods.opt -clscale 1 -2 -v 1 > /dev/null
${GMSH} Zylkopf.geo -clscale 1 -2 -v 1 > /dev/null
${GMSH} Top.geo -clscale 1 -2 -v 1 > /dev/null
${GMSH} ocean.geo -clscale 1 -2 -epslc1d 1.e-2 -algo del2d -v 1 > /dev/null
${GMSH} 15_cylinder_head.brep -2 -clscale .1 -v 1 > /dev/null
${GMSH} sphere_Rhino3D_default.geo -clscale 1 -2 -v 1 > /dev/null
${GMSH} Cone_1.brep -clscale 1 -2 -v 1 > /dev/null
${GMSH} Cylinder_1.brep -clscale 1 -2 -v 1 > /dev/null
${GMSH} Torus_1.brep -clscale 300 -2 -v 1 > /dev/null
${GMSH} A319.geo -clscale 3 -2 -v 1 > /dev/null
${GMSH} capot.geo -clscale .2 -2 -saveall -v 1 > /dev/null
${GMSH} bouda_.geo -clscale .2 -2 -saveall -v 1 > /dev/null
