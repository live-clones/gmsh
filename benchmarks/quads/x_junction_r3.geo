// x_junction_r3: quad surface mesh of a generated thin-walled part (X junction with fillets).
// Run: see the Flow parameter below.

SetFactory("OpenCASCADE");
v() = ShapeFromFile("../step/matgmsh/x_junction_r3.stp");

// Target edge length in model units (equal bounds give uniform sizing).
DefineConstant[
  h = {4, Min 1, Max 40, Step 1, Name "Parameters/Target edge length"}
];

Mesh.MeshSizeMin = h;
Mesh.MeshSizeMax = h;
Mesh.RandomSeed = 1;
Mesh.SaveAll = 1;
Mesh.SaveParametric = 1;

// Flow: 0 = PACK + QuadOpt, run with   gmsh x_junction_r3.geo -2
//       1 = Frontal-Delaunay + Q-Morph, run with   gmsh x_junction_r3.geo -
// (with -2, Gmsh would mesh again after the script and discard Q-Morph).
DefineConstant[
  flow = {0, Choices {0 = "PACK + QuadOpt", 1 = "Frontal-Delaunay + Q-Morph"},
          Name "Parameters/Flow"}
];
If(flow == 0)
  Mesh.Algorithm = 9; // PACK
  Mesh.PackSizemapMethod = 3;
  Mesh.PackPatterns = 0;
  Mesh.AlgorithmSwitchOnFailure = 0;
  Mesh.RecombineAll = 1;
  Mesh.RecombinationAlgorithm = 1; // Blossom
  Mesh.RecombineMinimumQuality = 0;
  Mesh.PackCleanupMethod = 1;
Else
  Mesh.Algorithm = 6; // Frontal-Delaunay
  Mesh 2;
  OptimizeMesh "QMorph";
  Save "x_junction_r3.msh";
EndIf
