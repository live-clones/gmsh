// c3 shape geometry
R = 2;
r = 1;
dy = 3;
p = .1;

SetFactory("OpenCASCADE");

Circle(1) = {0, 0, 0, R};
Circle(2) = {0, 0, 0, r};
Circle(3) = {0, dy, 0, R};
Circle(4) = {0, dy, 0, r};
Circle(5) = {-0.866*dy, dy/2, 0, R};
Circle(6) = {-0.866*dy, dy/2, 0, r};

Curve Loop(1) = {1};
Curve Loop(2) = {3};
Curve Loop(3) = {5};

Plane Surface(1) = {1};
Plane Surface(2) = {2};
Plane Surface(3) = {3};

BooleanUnion{ Surface{1}; Delete; }{ Surface{2}; Delete; }
BooleanUnion{ Surface{1}; Delete; }{ Surface{3}; Delete; }
Delete {Surface{1};}

Curve Loop(1) = {7, 8, 9};
Curve Loop(2) = {2};
Curve Loop(3) = {4};
Curve Loop(4) = {6};

Plane Surface(1) = {1, 2, 3, 4};


Physical Point("vertices_outer") = {7,8,9};
Physical Point("vertices_inner1") = {2};
Physical Point("vertices_inner2") = {4};
Physical Point("vertices_inner3") = {6};
Physical Surface("surface") = {1};


MeshSize {:} = p;
