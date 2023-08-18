Point(1)={-2,-1.5+0.5,0};
Point(2)={1,-1.5+0.5,0};
Point(3)={1,1.5-0.5,0};
Point(4)={-2,1.5-0.5,0};

d=0.1;
d=0.2;
Point(5)={-1,-d,0};
Point(6)={-1,+d,0};
Point(7)={0,0,0};
l=1;
L=(d*d + l*l)/l;
Point(8)={-L,0,0};
Point(9)={-L-Sqrt(L*L-l*l-d*d),0,0};

Line(1)={1,2};
Line(2)={2,3};
Line(3)={3,4};
Line(4)={4,1};

Circle(5)={5,8,9};
Circle(8)={9,8,6};

Line(6)={6,7};
Line(7)={7,5};

Line Loop(11) = {1,2,3,4};
Line Loop(12) = {5,8,6,7};

Plane Surface(1) = {11,12};

h=0.5;
MeshSize {:} =h;
Mesh.MeshSizeMin = h;
Mesh.MeshSizeMax = h;
Mesh.MeshSizeFromPoints = 1;
Mesh.MeshSizeFromCurvature = 0;
Mesh.MeshSizeExtendFromBoundary = 1;
Mesh.Algorithm = 5;

Transfinite Curve{1,3}=5;
Transfinite Curve{2,4}=4;

Transfinite Curve{5,8}=9;
Transfinite Curve{6,7}=17;

Field[1] = BoundaryLayer;
Field[1].CurvesList = {5,8,6,7};
Field[1].FanPointsList={7};
Field[1].FanPointsSizesList={-3};     //tail
//Field[1].FanPointsSizesList={-4};   // skip
Field[1].Thickness = 0.411;
Field[1].Size = 0.015;
Field[1].Ratio = 1.4;
Field[1].Quads = 1;
BoundaryLayer Field = 1;

