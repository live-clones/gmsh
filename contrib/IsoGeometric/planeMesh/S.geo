// S shape geometry
dL = 5;
dl = 2;
p = .4;

Point(1) = {0., 0, 0, p};
Point(2) = {0., dL-dl, 0, p};
Point(3) = {0., dL+dl, 0, p};
Point(4) = {0., 2*dL, 0, p};
Point(5) = {0., 2*dL+2*dl, 0, p};
Point(6) = {0., 3*dL+dl, 0, p};

Point(7) = {0., dL, 0, p};
Point(8) = {0., 2*dL+dl, 0, p};

Line(1) = {1, 2};
Circle(2) = {2, 7, 3};
Circle(3) = {6, 8, 3};
Line(4) = {6, 5};
Circle(5) = {5, 8, 4};
Circle(6) = {1, 7, 4};

Curve Loop(1) = {1, 2, -3, 4, 5, -6};
Plane Surface(1) = {1};


Physical Point("vertices") = {1, 2, 6, 5};
Physical Surface("surface") = {1};
