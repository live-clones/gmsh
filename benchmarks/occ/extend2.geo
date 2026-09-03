SetFactory("OpenCASCADE");

Rectangle(1) = {-0.1,-0.1,0, 1.2,1.2};
N = 100;
For i In {2:N}
  Disk(i) = {Rand(1), Rand(1), 0, 0.01};
EndFor
BooleanDifference{ Surface{1}; Delete; }{ Surface{2:N}; Delete; }

Mesh.MeshSizeFromCurvature = 20;
Mesh.MeshSizeMax = 0.1;
Mesh.MeshSizeExtendFromBoundary = 0;

Field[1] = Extend;
Field[1].SurfacesList = {1};
Field[1].Ratio = 1.4;
Background Field = 1;
