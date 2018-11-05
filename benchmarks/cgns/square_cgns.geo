lc=1000;
Point(1) = {0, 0, 0,lc*.1};
Point(2) = {0, 10, 0,lc};
Point(3) = {10, 10, 0,lc};
Point(4) = {10, 0, 0,lc};
Line(1) = {2, 3};
Line(2) = {3, 4};
Line(3) = {4, 1};
Line(4) = {1, 2};

Line Loop(5) = {1, 2, 3, 4};
Plane Surface(10) = {5};

Transfinite Curve {3, 2, 1, 4} = 11 Using Progression 1;
Transfinite Surface {10} = {1, 4, 3, 2};
Recombine Surface {10};

Physical Curve("TOP") = {1};
Physical Curve("BOTTOM") = {3};
Physical Curve("LEFT") = {4};
Physical Curve("RIGHT") = {2};

Mesh 2;
Mesh.RecombineAll = 1;
Mesh.Format = 32;		//CGNS  - User has to choose "Write Structured mesh" option from GUI to write "Recombined mesh" - command prompt version will not do

