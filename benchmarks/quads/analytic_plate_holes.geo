// analytic_plate_holes: quad surface mesh of a plane plate with three circular
// holes and a slot.
// Run: gmsh analytic_plate_holes.geo -2   (PACK, Blossom, cavity optimizer)

SetFactory("OpenCASCADE");
Rectangle(1) = {0, 0, 0, 60, 40};
Disk(2) = {12, 12, 0, 5};
Disk(3) = {30, 28, 0, 7};
Disk(4) = {48, 12, 0, 4};
Rectangle(5) = {40, 26, 0, 12, 4, 1.5}; // slot with rounded corners
BooleanDifference{ Surface{1}; Delete; }{ Surface{2:5}; Delete; }

// Target edge length in model units (equal bounds give uniform sizing).
DefineConstant[
  h = {2, Min 0.5, Max 10, Step 0.5, Name "Parameters/Target edge length"}
];

Mesh.MeshSizeMin = h;
Mesh.MeshSizeMax = h;
Mesh.RandomSeed = 1;
Mesh.SaveAll = 1;
Mesh.SaveParametric = 1;

Mesh.Algorithm = 9; // PACK
Mesh.PackSizemapMethod = 3;
Mesh.PackPatterns = 0;
Mesh.AlgorithmSwitchOnFailure = 0;
Mesh.RecombineAll = 1;
Mesh.RecombinationAlgorithm = 1; // Blossom
Mesh.RecombineMinimumQuality = 0;
Mesh.PackCleanupMethod = 1;

// The automatic tests only look at the exit status: mesh here and check the
// result. (audit.py only reads the CAD: it strips the Mesh options, which
// skips this block.)
If(Mesh.RecombineAll)
  Mesh 2;
  Printf("analytic_plate_holes: %g quadrangles, %g triangles, minimum quality %g",
         Mesh.NbQuadrangles, Mesh.NbTriangles, Mesh.MinQuality);
  If(Mesh.NbQuadrangles == 0)
    Error("analytic_plate_holes: no quadrangle");
  EndIf
  If(Mesh.NbTriangles > 0.05 * Mesh.NbQuadrangles)
    Error("analytic_plate_holes: %g triangles for %g quadrangles", Mesh.NbTriangles, Mesh.NbQuadrangles);
  EndIf
  If(Mesh.MinQuality <= 0)
    Error("analytic_plate_holes: invalid element (minimum quality %g)", Mesh.MinQuality);
  EndIf
EndIf
