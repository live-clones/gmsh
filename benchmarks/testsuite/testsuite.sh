#!/bin/bash
date >> statreport.dat
../../bin/gmsh Block.geo Block.opt -clscale .1 -v 0 -2 -append_statreport statreport.dat
../../bin/gmsh linkrods.geo linkrods.opt -clscale 1 -v 0 -2 -append_statreport statreport.dat
../../bin/gmsh Zylkopf.geo -clscale 1 -v 0 -2 -append_statreport statreport.dat
../../bin/gmsh Top.geo -clscale 1 -v 0 -2 -append_statreport statreport.dat
../../bin/gmsh ocean.geo -clscale 1 -v 0 -2 -append_statreport statreport.dat -epslc1d 1.e-2 -algo del2d
../../bin/gmsh 15_cylinder_head.brep -2 -clscale .1 -append_statreport statreport.dat
../../bin/gmsh sphere_Rhino3D_default.igs -clscale 1 -v 0 -2 -append_statreport statreport.dat
../../bin/gmsh Cone_1.brep -clscale 1 -v 0 -2 -append_statreport statreport.dat
../../bin/gmsh Cylinder_1.brep -clscale 1 -v 0 -2 -append_statreport statreport.dat
../../bin/gmsh A319.geo -clscale 3 -v 0 -2 -append_statreport statreport.dat

