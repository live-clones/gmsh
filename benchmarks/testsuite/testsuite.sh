#!/bin/bash

if [ $# = 0 ] ; then
  echo "Usage: $0 path_to_gmsh"
  exit 1
fi

if [ ! -e statreport.dat ] ; then
  $1 -statreport statreport.dat -2
fi

GMSH="$1 -append_statreport statreport.dat"

date >> statreport.dat
${GMSH} Block.geo Block.opt -clscale .1 -v 0 -2 
${GMSH} linkrods.geo linkrods.opt -clscale 1 -v 0 -2
${GMSH} Zylkopf.geo -clscale 1 -v 0 -2
${GMSH} Top.geo -clscale 1 -v 0 -2
${GMSH} ocean.geo -clscale 1 -v 0 -2 -epslc1d 1.e-2 -algo del2d
${GMSH} 15_cylinder_head.brep -v 0 -2 -clscale .1 
${GMSH} sphere_Rhino3D_default.geo -clscale 1 -v 0 -2
${GMSH} Cone_1.brep -clscale 1 -v 0 -2
${GMSH} Cylinder_1.brep -clscale 1 -v 0 -2
${GMSH} Torus_1.brep -clscale 300 -v 0 -2
${GMSH} A319.geo -clscale 3 -v 0 -2
