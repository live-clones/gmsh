SetFactory("OpenCASCADE");

Rectangle(1) = {0,0,0, 1,1};
Point(5) = {0.6, 0.7, 0};
Point(6) = {0.5, 0.75, 0};
Point(7) = {0.4, 0.7, 0};
Point(8) = {0.35, 0.5, 0};
Point(9) = {0.4, 0.3, 0};
Point(10) = {0.5, 0.25, 0};
Point(11) = {0.6, 0.3, 0};
Spline(5) = {5:11};

// add this to make the 2D mesh conformal to the 1D mesh of the spline
// Curve{5} In Surface{1};

Field[1] = Distance;
Field[1].CurvesList = {5};
Field[1].NumPointsPerCurve = 100;

Field[2] = Threshold;
Field[2].InField = 1;
Field[2].SizeMin = 0.0025;
Field[2].SizeMax = 0.05;
Field[2].DistMin = 0.015;
Field[2].DistMax = 0.1;

Background Field = 2;

Mesh.Algorithm = 5;
Mesh.MeshSizeExtendFromBoundary = 0;
