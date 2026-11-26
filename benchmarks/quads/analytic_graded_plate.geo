// analytic_graded_plate: quad surface mesh of a plane plate with a circular
// hole, the size graded by a background field from h/4 on the rim of the hole
// to h far from it.
// Run: gmsh analytic_graded_plate.geo -2   (PACK, Blossom, cavity optimizer)

SetFactory("OpenCASCADE");
Rectangle(1) = {0, 0, 0, 80, 50};
Disk(2) = {25, 25, 0, 6};
BooleanDifference{ Surface{1}; Delete; }{ Surface{2}; Delete; }
hole() = Curve In BoundingBox{18, 18, -1, 32, 32, 1};

// Target edge length far from the hole, in model units.
DefineConstant[
  h = {4, Min 1, Max 10, Step 0.5, Name "Parameters/Target edge length"}
];

Field[1] = Distance;
Field[1].CurvesList = {hole()};
Field[1].Sampling = 100;
Field[2] = Threshold;
Field[2].InField = 1;
Field[2].SizeMin = h / 4;
Field[2].SizeMax = h;
Field[2].DistMin = 2;
Field[2].DistMax = 25;
Background Field = 2;

Mesh.MeshSizeMin = h / 4;
Mesh.MeshSizeMax = h;
Mesh.MeshSizeExtendFromBoundary = 0;
Mesh.MeshSizeFromPoints = 0;
Mesh.MeshSizeFromCurvature = 0;
Mesh.RandomSeed = 1;
Mesh.SaveAll = 1;
Mesh.SaveParametric = 1;

// A curve may be meshed with a single edge: the defaults impose at least two
// edges on a general curve and one per 60 degrees of a circle arc.
Mesh.MinCurveNodes = 2;
Mesh.MinCircleNodes = 2;

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
  Printf("analytic_graded_plate: %g quadrangles, %g triangles, minimum quality %g",
         Mesh.NbQuadrangles, Mesh.NbTriangles, Mesh.MinQuality);
  If(Mesh.NbQuadrangles == 0)
    Error("analytic_graded_plate: no quadrangle");
  EndIf
  If(Mesh.NbTriangles > 0.05 * Mesh.NbQuadrangles)
    Error("analytic_graded_plate: %g triangles for %g quadrangles", Mesh.NbTriangles, Mesh.NbQuadrangles);
  EndIf
  If(Mesh.MinQuality <= 0)
    Error("analytic_graded_plate: invalid element (minimum quality %g)", Mesh.MinQuality);
  EndIf
EndIf
