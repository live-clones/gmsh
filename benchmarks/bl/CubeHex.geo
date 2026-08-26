

//+
SetFactory("OpenCASCADE");
Box(1) = {-0.5, -0.5, 0, 1, 1, 1};
//+
Recombine Surface {6, 1, 2, 3, 4, 5};
Mesh.Algorithm = 8;
//Mesh.OptimizePyramids = -3;
//+
MeshSize {3, 7, 4, 8} = 0.1;
//+
MeshSize {1, 5, 2, 6} = 0.1;
