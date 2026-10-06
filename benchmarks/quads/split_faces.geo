// split_faces: PACK quad surface mesh of a generated thin-walled part (faces split by imprinted edges).
// Run: gmsh split_faces.geo -2 -nt 2 -o split_faces.msh

SetFactory("OpenCASCADE");
v() = ShapeFromFile("../step/matgmsh/split_faces.stp");

// Target edge length in model units (equal bounds give uniform sizing).
DefineConstant[
  h = {4, Min 1, Max 40, Step 1, Name "Parameters/Target edge length"}
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
