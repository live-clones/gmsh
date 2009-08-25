#!/bin/bash
date >> statreport.dat
../../gmsh Block.geo Block.opt -clscale .1 -v 0 -2 -append_statreport statreport.dat
../../gmsh linkrods.geo linkrods.opt -clscale 1 -v 0 -2 -append_statreport statreport.dat
../../gmsh Zylkopf.geo -clscale 1 -v 0 -2 -append_statreport statreport.dat
../../gmsh Top.geo -clscale 1 -v 0 -2 -append_statreport statreport.dat
../../gmsh ocean.geo -clscale 1 -v 0 -2 -append_statreport statreport.dat -epslc1d 1.e-2 -algo del2d
../../gmsh 15_cylinder_head.brep -v 0 -2 -clscale .1 -append_statreport statreport.dat
../../gmsh sphere_Rhino3D_default.geo -clscale 1 -v 0 -2 -append_statreport statreport.dat
../../gmsh Cone_1.brep -clscale 1 -v 0 -2 -append_statreport statreport.dat
../../gmsh Cylinder_1.brep -clscale 1 -v 0 -2 -append_statreport statreport.dat
../../gmsh Torus_1.brep -clscale 300 -v 0 -2 -append_statreport statreport.dat
../../gmsh A319.geo -clscale 3 -v 0 -2 -append_statreport statreport.dat
