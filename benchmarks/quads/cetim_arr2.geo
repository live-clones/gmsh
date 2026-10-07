// cetim_arr2: quad surface mesh of a rear automotive structure part (CETIM), surfaces only (179 faces, external CAD, model units as given).
// Known failure (2026-10-07): PACK stops with "no internal edges" (cross field on one surface), Frontal-Delaunay + Q-Morph exceeds 420 s.
// Run: see the Flow parameter below.

SetFactory("OpenCASCADE");
v() = ShapeFromFile("../step/industrial/cetim_arr2.stp");

// Target edge length in model units (equal bounds give uniform sizing).
DefineConstant[
  h = {24, Min 0.1, Max 192, Step 1, Name "Parameters/Target edge length"}
];

Mesh.MeshSizeMin = h;
Mesh.MeshSizeMax = h;
Mesh.RandomSeed = 1;
Mesh.SaveAll = 1;
Mesh.SaveParametric = 1;

// Flow: 0 = PACK, Blossom, cavity optimizer      run with   gmsh cetim_arr2.geo -2
//       1 = Frontal-Delaunay, Q-Morph            run with   gmsh cetim_arr2.geo -
//       2 = PACK, Q-Morph, cavity optimizer      run with   gmsh cetim_arr2.geo -2
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
  Save "cetim_arr2.msh";
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
