Point(1)={0,0,0};
Point(2)={5,0,0};
Point(3)={5,3,0};
Point(4)={0,3,0};

d=0.25;
Point(5)={1,1,0};
Point(6)={1+d*2/3,2,0};
Point(7)={4-d,2,0};
Point(8)={4,1,0};


Line(1)={1,2};
Line(2)={2,3};
Line(3)={3,4};
Line(4)={4,1};

Line(5)={5,8};
Line(6)={8,7};
Line(7)={7,6};
Line(8)={6,5};

Line Loop(11) = {1,2,3,4};
Line Loop(12) = {5,6,7,8};

Plane Surface(1) = {11,12};

h=0.25;
MeshSize {:} =h;
Mesh.MeshSizeMin = h;
Mesh.MeshSizeMax = h;
Mesh.MeshSizeFromPoints = 1;
Mesh.MeshSizeFromCurvature = 0;
Mesh.MeshSizeExtendFromBoundary = 1;
Mesh.Algorithm = 6;

Transfinite Curve{5,7}=17;
Transfinite Curve{6,8}=11;

Field[1] = BoundaryLayer;
Field[1].CurvesList = {5,6,7,8};
Field[1].FanPointsList={7,8,5,6};
Field[1].FanPointsSizesList={-1,-1,-2,-2};
Field[1].Thickness = 0.401;
Field[1].Size = 0.05;
Field[1].Ratio = 1.1;
Field[1].Quads = 1;
BoundaryLayer Field = 1;

