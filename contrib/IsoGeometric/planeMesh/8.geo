// 8 shape geometry
R = 2;
r = 1;
dy = 3;
p = .1;

SetFactory("OpenCASCADE");

Point(1) = {0, -R, 0, p};
Point(2) = {0, +r+dy, 0, p};

Circle(1) = {0, 0, 0, R};
Circle(2) = {0, 0, 0, r};
Circle(3) = {0, dy, 0, R};
Circle(4) = {0, dy, 0, r};

Curve Loop(1) = {1};
Curve Loop(2) = {2};
Curve Loop(3) = {3};
Curve Loop(4) = {4};

Plane Surface(1) = {1, 2};
Plane Surface(2) = {3, 4};

BooleanUnion{ Surface{1}; Delete; }{ Surface{2}; Delete; }
Delete {Surface{1};}
/*
Delete {CurveLoop{1};}
Delete {CurveLoop{2};}
Delete {CurveLoop{3};}
Delete {CurveLoop{4};}
*/

BooleanFragments{ Curve{1};}{ Point{1};}
Delete {Curve{1};}
BooleanFragments{ Curve{4};}{ Point{2}; }
Delete {Curve{4};}

Curve Loop(1) = {2, 6, 5};
Curve Loop(2) = {7, 8};
Curve Loop(3) = {3};

Plane Surface(1) = {1, 2, 3};


Physical Point("vertices_outer") = {3,4};
Physical Point("vertices_inner1") = {1,5};
Physical Point("vertices_inner2") = {2,6};

Physical Surface("surface") = {1};


MeshSize {:} = p;
