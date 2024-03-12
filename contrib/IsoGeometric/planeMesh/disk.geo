// Disk shape geometry
dL = 30;
p = 1;

Point(1) = {0., dL, 0, p};
Point(2) = {0., -dL, 0, p};

Point(3) = {0., 0, 0, p};

Circle(1) = {1, 3, 2};
Circle(2) = {2, 3, 1};

Curve Loop(1) = {1, 2};
Plane Surface(1) = {1};


Physical Point("vertices") = {1,2};
Physical Curve("outer") = {1,2};
Physical Surface("surface") = {1};
