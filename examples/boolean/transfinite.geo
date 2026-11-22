SetFactory("OpenCASCADE");
// boundary entities keep their tags through boolean operations
Geometry.OCCBooleanPreserveNumbering = 2;

Mesh.Algorithm = 6;
Mesh.MeshSizeMin = 1;
Mesh.MeshSizeMax = 1;

Box(1) = {0,0,0, 1,1,1};
Cylinder(2) = {0.5,0,0, 0,1,0, 0.7};
BooleanDifference(3) = { Volume{1}; Delete; }{ Volume{2}; Delete; };

s() = Boundary{ Volume{3}; };
l() = Unique(Boundary{ Surface{s()}; });

N = DefineNumber[ 10, Name "Parameters/N" ];

// simple transfinite mesh
Transfinite Curve{l()} = N;
Transfinite Surface{7};

// transfinite mesh with explicit corners
Transfinite Curve{12} = 2*N-1;
Transfinite Surface{4} = {3, 12, 7, 14};
