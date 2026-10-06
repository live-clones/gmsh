// tray_two_ribs_hole: quad surface mesh of a generated thin-walled part (tray with two ribs and a hole).
// Run: see the Flow parameter below.

SetFactory("OpenCASCADE");
v() = ShapeFromFile("../step/matgmsh/tray_two_ribs_hole.stp");

// Target edge length in model units (equal bounds give uniform sizing).
DefineConstant[
  h = {4, Min 1, Max 40, Step 1, Name "Parameters/Target edge length"}
];

Mesh.MeshSizeMin = h;
Mesh.MeshSizeMax = h;
Mesh.RandomSeed = 1;
Mesh.SaveAll = 1;
Mesh.SaveParametric = 1;

// Flow: 0 = PACK, Blossom, cavity optimizer      run with   gmsh tray_two_ribs_hole.geo -2
//       1 = Frontal-Delaunay, Q-Morph            run with   gmsh tray_two_ribs_hole.geo -
//       2 = PACK, Q-Morph, cavity optimizer      run with   gmsh tray_two_ribs_hole.geo -2
// (flow 1 meshes inside the script: with -2, Gmsh would mesh again afterwards
// and discard Q-Morph.)
DefineConstant[
  flow = {0, Choices {0 = "PACK + Blossom", 1 = "Frontal-Delaunay + Q-Morph",
                      2 = "PACK + Q-Morph"},
          Name "Parameters/Flow"}
];
If(flow == 1)
  Mesh.Algorithm = 6; // Frontal-Delaunay
  Mesh 2;
  OptimizeMesh "QMorph";
  Save "tray_two_ribs_hole.msh";
Else
  Mesh.Algorithm = 9; // PACK
  Mesh.PackSizemapMethod = 3;
  Mesh.PackPatterns = 0;
  Mesh.AlgorithmSwitchOnFailure = 0;
  Mesh.RecombineAll = 1;
  Mesh.RecombinationAlgorithm = 1; // Blossom
  Mesh.RecombineMinimumQuality = 0;
  Mesh.PackCleanupMethod = 1;
  Mesh.PackRecombination = (flow == 2); // 0: Blossom, 1: Q-Morph
EndIf
