a = .1;
b = 1;
radius = 0.5;
radiusBoundaryLayer = 0.7;
Point(1) = {0, 0, 0, a};
Point(2) = {radius, 0, 0, a};
Point(3) = {-radius, 0, 0, a};
Point(4) = {0, radius, 0, a};
Point(5) = {0, -radius, 0, a};
Point(12) = {radiusBoundaryLayer, 0, 0, a};
Point(13) = {-radiusBoundaryLayer, 0, 0, a};
Point(14) = {0, radiusBoundaryLayer, 0, a};
Point(15) = {0, -radiusBoundaryLayer, 0, a};
Point(6) = {-5, -5, 0, b};
Point(7) = {-5, 5, 0, b};
Point(8) = {15, 5, 0, b};
Point(9) = {15, -5, 0, b};
Circle(1) = {4, 1, 2};
Circle(2) = {2, 1, 5};
Circle(3) = {5, 1, 3};
Circle(4) = {3, 1, 4};
Circle(11) = {14, 1, 12};
Circle(12) = {12, 1, 15};
Circle(13) = {15, 1, 13};
Circle(14) = {13, 1, 14};

Line(5) = {7, 8};
Line(6) = {8, 9};
Line(7) = {9, 6};
Line(8) = {6, 7};
Line(22) ={2,12};
Line(23) ={3,13};
Line(24) ={4,14};
Line(25) ={5,15};

Line Loop(1) = {1, 22, -11, -24};
Plane Surface(1)={1};
Line Loop(2) = {2, 25, -12, -22};
Plane Surface(2)={2};
Line Loop(3) = {3, 23, -13, -25};
Plane Surface(3)={3};
Line Loop(4) = {4, 24, -14, -23};
Plane Surface(4)={4};

np=6;
np2=4;
Transfinite Line(1) = np;
Transfinite Line(2) = np;
Transfinite Line(3) = np;
Transfinite Line(4) = np;
Transfinite Line(11) = np;
Transfinite Line(12) = np;
Transfinite Line(13) = np;
Transfinite Line(14) = np;

Transfinite Line(22) = np2;
Transfinite Line(23) = np2;
Transfinite Line(24) = np2;
Transfinite Line(25) = np2;

Transfinite Surface(1) = {2,12,14,4};
Transfinite Surface(2) = {5,15,12,2};
Transfinite Surface(3) = {3,13,15,5};
Transfinite Surface(4) = {4,14,13,3};
Recombine Surface {1,2,3,4};

Line Loop(9) = {6, 7, 8, 5};
Line Loop(10) = {11,12,13,14};
Plane Surface(100) = {9, 10};

Physical Surface("Air") = {1,2,3,4};
Physical Surface("BoundaryLayer") = {100};
Physical Line("Cylinder") = {4, 1, 2, 3};
Physical Line("Box") = {5, 6, 7, 8};
Mesh.CharacteristicLengthExtendFromBoundary=1;
