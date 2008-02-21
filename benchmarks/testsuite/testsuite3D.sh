#!/bin/bash
date >> statreport3d.dat
../../bin/gmsh ./Kurbelwelle.geo -3 -clcurv -epslc1d 1.e-2 -clmin .05 -optimize
../../bin/gmsh ./Angled.step -clcurv  -epslc1d 1.e-2 -clmin 1 -3 -optimize
../../bin/gmsh ./917_fusee.stp -clcurv  -epslc1d 1.e-2 -clmin .025 -3 -optimize 
../../bin/gmsh ./918_pump_carter_sup_21_03_2006.stp -clcurv  -epslc1d 1.e-2 -clmin .0125 -3 -optimize 