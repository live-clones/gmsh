SetFactory("OpenCASCADE");
r1 = DefineNumber[0.05, Name "r1"];
r2 = DefineNumber[0.03, Name "r2"];
e1 = DefineNumber[0.01, Name "e1"];
e2 = DefineNumber[0.005, Name "e2"];
Cylinder(1) = {-1,0,0, 2,0,0, r1};
Cylinder(2) = {0,0,0, 0,0.3,0, r2};
BooleanUnion(3) = { Volume{1}; Delete; }{ Volume{2}; Delete; };

Cylinder(4) = {-1,0,0, 2,0,0, r1-e1};
Cylinder(5) = {0,0,0, 0,0.3,0, r2-e2};
BooleanUnion(6) = { Volume{4}; Delete; }{ Volume{5}; Delete; };

BooleanDifference(10) = { Volume{3}; Delete; }{ Volume{6}; Delete; };

Mesh.Algorithm = 6;
Mesh.MeshSizeFromCurvature = 10;
