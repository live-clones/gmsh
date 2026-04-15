SetFactory("OpenCASCADE");
Rectangle(1) = {0,0,0, 1,1};
Disk(2) = {0.5, 1, 0, 0.35};
Disk(3) = {0.5, 0, 0, 0.35};
BooleanDifference{ Surface{1}; Delete; }{ Surface{2}; Surface{3}; Delete; }
MeshSize{ : } = 0.3;
MeshSize{ 1,2,7} = 0.001;
MeshSize{ 5,6} = 0.006;

Mesh.MeshSizeExtendFromBoundary = 0;

Field[1] = Extend;
Field[1].SurfacesList = {1};
Field[1].Ratio = 1.2;
Field[1].SizeMax = 0.25;
Background Field = 1;
