SetFactory("OpenCASCADE");
Rectangle(1) = {-0.7, -0.2, 0, 1, 0.5, 0.1};

Point(9) = {-0.39, 0.21, 0, 1.0};
Point(10) = {-0.25, 0.14, 0, 1.0};
Point(11) = {-0.12, -0.05, 0, 1.0};
Point(12) = {-0.03, 0.12, 0, 1.0};
Point(13) = {0.14, 0.12, 0, 1.0};
Spline(9) = {9, 10, 11, 12, 13};

BooleanFragments{ Surface{1}; Delete; }{ Curve{9}; Delete; }

Field[1] = Distance;
Field[1].NNodesByEdge = 200;
Field[1].EdgesList = {9};

Field[2] = Threshold;
Field[2].IField = 1;
Field[2].LcMin = 0.005;
Field[2].LcMax = 0.05;
Field[2].DistMin = 0.01;
Field[2].DistMax = 0.1;

Background Field = 2;

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthExtendFromBoundary = 0;
