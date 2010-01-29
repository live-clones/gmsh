Point(1) = {-0.5, -0.5, 0, .03};
Point(2) = {0, -0.5, 0, .03};
Point(3) = {0, 0.5, 0, .03};
Point(4) = {-0.5, 0.5, 0, .03};

Point(5) = {0.5, -0.5, 0, .03};
Point(6) = {0.5, 0.5, 0, .03};

Line(1) = {4, 3};
Line(2) = {3, 2};
Line(3) = {2, 1};
Line(4) = {1, 4};

Line(7) = {3, 6};
Line(8) = {6, 5};
Line(9) = {5, 2};

Line Loop(5) = {2, 3, 4, 1};
Line Loop(6) = {8, 9, -2, 7};
Plane Surface(7) = {5};
Plane Surface(8) = {6};
Transfinite Line {4,8} = 20 ;
Transfinite Line{2}=20;
Transfinite Surface {7};
Recombine Surface {7};
Transfinite Line {3,1,7,9} = 10;
Transfinite Surface{8};

Physical Line("Border") = {1, 3, 4, 7, 8, 9};
Physical Surface("Inside1") = {7};
Physical Surface("Inside2") = {8};
