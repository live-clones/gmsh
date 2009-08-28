#!/bin/bash

if [ $# = 0 ] ; then
  echo "Usage: $0 path_to_gmsh"
  exit 1
fi

GMSH=$1

date >> statreport3d.dat
${GMSH} ./Kurbelwelle.geo -3 -clcurv -epslc1d 1.e-2 -clmin .05 -optimize
${GMSH} ./Angled.step -clcurv  -epslc1d 1.e-2 -clmin 1 -3 -optimize
${GMSH} ./917_fusee.stp -clcurv  -epslc1d 1.e-2 -clmin .025 -3 -optimize 
${GMSH} ./918_pump_carter_sup_21_03_2006.stp -clcurv  -epslc1d 1.e-2 -clmin .0125 -3 -optimize 
