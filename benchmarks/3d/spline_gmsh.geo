DefineConstant[ lc = { 0.5, Name "Gmsh/Parameters/lc"}];
DefineConstant[ r1 = { 2, Name "Gmsh/Parameters/r1"}];
DefineConstant[ r2 = { 3, Name "Gmsh/Parameters/r2"}];
DefineConstant[ hole1x = { -2-r1, Name "Gmsh/Parameters/hole1 x"}];
DefineConstant[ hole2x = { 10+r2, Name "Gmsh/Parameters/hole2 x"}];
Point(1) = {hole1x, 0, 0, lc};
Point(2) = {hole2x, 0, 0, lc};
Point(3) = {hole1x-r1, 0, 0, lc};
Point(4) = {hole1x, r1, 0, lc};
Point(5) = {hole1x+r1, 0, 0, lc};
Point(6) = {hole2x+r2, 0, 0, lc};
Point(7) = {hole2x, r2, 0, lc};
Point(8) = {hole2x-r2, 0, 0, lc};
Point(9) = {0, 0, 0, lc};
Point(10) = {0, 1, 0, lc};
Point(11) = {1, 2.5 , 0, lc};
Point(12) = {4, 3, 0, lc};
Point(13) = {7, 3.5, 0, lc};
Point(14) = {8, 1, 0, lc};
Point(15) = {8, 0, 0, lc};
Point(16) = {hole1x-1.5*r1, 0, 0, lc};
Point(17) = {hole1x-1.5*r1, 1.5*r1, 0, lc};
Point(18) = {2, 1.8*r2, 0, lc};
Point(19) = {5, 2*r2, 0, lc};
Point(20) = {8, 2.2*r2, 0, lc};
Point(21) = {hole2x+1.5*r2, 1.5*r2, 0, lc};
Point(22) = {hole2x+1.5*r2, 0, 0, lc};
Circle(1) = {3, 1, 4};
Circle(2) = {4, 1, 5};
Line(3) = {8, 7};
Line(4) = {7, 6};
Spline(5) = {9, 10, 11, 12};
Spline(6) = {12, 13, 14, 15};
Spline(7) = {16, 17, 18, 19};
Spline(8) = {19, 20, 21, 22};
Symmetry {0, 1, 0, 0} {
  Duplicata { Line{7, 8, 4, 3, 6, 5, 2, 1}; }
}
Line Loop(17) = {7, 8, -10, -9};
Line Loop(18) = {1, 2, -15, -16};
Line Loop(19) = {5, 6, -13, -14};
Line Loop(20) = {3, 4, -11, -12};
Plane Surface(21) = {17, 18, 19, 20};
Extrude {0, 0, 3} {
  Surface{21};
}
