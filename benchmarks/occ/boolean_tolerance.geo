SetFactory("OpenCASCADE");
Rectangle(1) = {0, -0.4, -0, 0.6, 0.5, 0};

Point(5) = {0.1, -0.2, 0, 1.0};
Point(6) = {0.5, -0.1, 0, 1.0};
Point(7) = {0.1, -0.201, 0, 1.0};
Point(8) = {0.5, -0.12, 0, 1.0};

Line(5) = {7, 8};
Line(6) = {5, 6};

Point(9) = {0.2, -0, 0, 1.0};
Point(10) = {0.4, -0.3, 0, 1.0};
Point(11) = {0.1, -0, 0, 1.0};
Point(12) = {0.5, -0.3, 0, 1.0};
Line(7) = {11, 12};
Line(8) = {10, 9};

Geometry.ToleranceBoolean = 0.1; // to merge curves 5,8 and 10,15
a() = BooleanFragments{ Curve{5}; Curve{6}; Curve{7}; Curve{8}; Delete; }{ };
Curve {a()} In Surface {1};

Field[1] = Distance;
Field[1].CurvesList = {a()};
Field[1].Sampling = 200;
Field[2] = Threshold;
Field[2].DistMax = 0.1;
Field[2].DistMin = 0.01;
Field[2].InField = 1;
Field[2].SizeMax = 0.1;
Field[2].SizeMin = 0.005;

Background Field = 2;
Mesh.MeshSizeExtendFromBoundary = 0;
