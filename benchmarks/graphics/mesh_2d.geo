// 2D mesh of a plate with holes, with physical groups
SetFactory("OpenCASCADE");
DefineConstant[ N = 1 ];
Rectangle(1) = {0, 0, 0, 2, 1};
Disk(2) = {0.5, 0.5, 0, 0.2};
Disk(3) = {1.5, 0.5, 0, 0.25, 0.15};
BooleanDifference{ Surface{1}; Delete; }{ Surface{2, 3}; Delete; }
Rectangle(10) = {2.2, 0, 0, 1, 1};
Physical Surface("plate") = {1};
Physical Curve("holes") = {5, 6};
Mesh.MeshSizeMax = 0.1 / N;
Mesh 2;
