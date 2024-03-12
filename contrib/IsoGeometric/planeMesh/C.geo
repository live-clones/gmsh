// C shape geometry
dL = 20;
dl = 8;
p = 1;

Point(1) = {0., -dL, 0, p};
Point(2) = {0., -dl, 0, p};
Point(3) = {0., +dl, 0, p};
Point(4) = {0., +dL, 0, p};

Point(5) = {0., 0, 0, p};

Line(1) = {1, 2};
Circle(2) = {3, 5, 2};
Line(3) = {3, 4};
Circle(4) = {4, 5, 1};


Curve Loop(1) = {1, -2, 3, 4};
Plane Surface(1) = {1};


Physical Point("vertices") = {1,2,3,4};
Physical Curve("edges") = {1,2,3,4};
Physical Surface("surface") = {1};

