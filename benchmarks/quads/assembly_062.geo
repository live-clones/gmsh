// assembly_062: PACK quad surface mesh of a generated thin-walled part (sheet metal assembly).
// Run: gmsh assembly_062.geo -2 -nt 2 -o assembly_062.msh

SetFactory("OpenCASCADE");
v() = ShapeFromFile("../step/matgmsh/assembly_062.stp");

// Target edge length in model units (equal bounds give uniform sizing).
DefineConstant[
  h = {10, Min 1, Max 40, Step 1, Name "Parameters/Target edge length"}
];

Mesh.Algorithm = 9;               // PACK
Mesh.MeshSizeMin = h;
Mesh.MeshSizeMax = h;
Mesh.PackSizemapMethod = 3;
Mesh.PackPatterns = 0;
Mesh.AlgorithmSwitchOnFailure = 0;
Mesh.RandomSeed = 1;
Mesh.RecombineAll = 1;
Mesh.RecombinationAlgorithm = 1;  // Blossom
Mesh.RecombineMinimumQuality = 0;
Mesh.PackCleanupMethod = 1;
Mesh.SaveAll = 1;
Mesh.SaveParametric = 1;
