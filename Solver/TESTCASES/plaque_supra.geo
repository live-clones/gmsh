lc=0.25;
a=5;
b=0.5;

Point(1) = {-a, -b, 0, lc};
Point(2) = {-a, b, 0, lc};
Point(3) = {a, b, 0, lc};
Point(4) = {a, -b, 0, lc};
Line(1) = {4, 3};
Line(2) = {3, 2};
Line(3) = {2, 1};
Line(4) = {1, 4};
Line Loop(5) = {2, 3, 4, 1};
Plane Surface(6) = {5};

Physical Line("Right")={1};
Physical Line("Top")={2};
Physical Line("Left")={3};
Physical Line("Bottom")={4};
Physical Surface("Inside") = {6};
//Mesh.CharacteristicLengthExtendFromBoundary=1;
//Transfinite Line {1, 2, 4, 3} = 2 Using Progression 1;
//Transfinite Surface {6};
