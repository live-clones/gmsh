// 0 shape geometry
dL = 5;
dl = 3;
p = .3;

Point(1) = {0., dL, 0, p};
Point(2) = {0., -dL, 0, p};
Point(3) = {0., -dl, 0, p};
Point(4) = {0., dl, 0, p};

Point(5) = {0., 0, 0, p};

Circle(1) = {1, 5, 2};
Circle(2) = {2, 5, 1};
Circle(3) = {3, 5, 4};
Circle(4) = {4, 5, 3};

Curve Loop(1) = {1, 2};
Curve Loop(2) = {3, 4};
Plane Surface(1) = {1, 2};

/*
Physical Point("vertices_outer") = {1,2};
Physical Point("vertices_inner") = {3,4};
*/

Physical Point("vertices") = {1,2,3,4};
Physical Curve("edges") = {1,2,3,4};
Physical Surface("surface") = {1};
