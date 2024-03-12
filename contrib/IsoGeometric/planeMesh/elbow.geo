// Elbow
dX = 20.;
dx = 15;
p = 1;

Point(1) = {0, 0, 0, p};
Point(2) = {dX, 0, 0, p};
Point(3) = {dX, dX, 0, p};
Point(4) = {0, dX, 0, p};
Point(5) = {dx, 0, 0, p};
Point(6) = {dx, dx, 0, p};
Point(7) = {0, dx, 0, p};

BSpline(1) = {5, 7, 6, 5, 2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,7};
BSpline(5) = {7, 1, 5};


Curve Loop(1) = {1, 2, 3, 4, 5};
Plane Surface(1) = {1};

Physical Point("vertices") = {7, 2, 3, 4};
Physical Curve("edges") = {1,2,3,4,5};
Physical Surface("surface") = {1};

Mesh.MinimumCurveNodes = 2;
