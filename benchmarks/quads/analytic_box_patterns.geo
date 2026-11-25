// analytic_box_patterns: quad surface mesh of the skin of a notched box: six
// rectangles and two L-shaped faces, all plane. Unlike the other cases of this
// directory, the simple faces are remeshed with quad patterns after the
// packing (Mesh.PackPatterns = 1, the default).
// Run: gmsh analytic_box_patterns.geo -2   (PACK, patterns, Blossom, cavity optimizer)

SetFactory("OpenCASCADE");
Box(1) = {0, 0, 0, 40, 30, 20};
Box(2) = {20, -1, 10, 21, 32, 11}; // the notch
BooleanDifference{ Volume{1}; Delete; }{ Volume{2}; Delete; }
Delete { Volume{:}; } // the surfaces only

// Target edge length in model units (equal bounds give uniform sizing).
DefineConstant[
  h = {2.5, Min 0.5, Max 10, Step 0.5, Name "Parameters/Target edge length"}
];

Mesh.MeshSizeMin = h;
Mesh.MeshSizeMax = h;
Mesh.RandomSeed = 1;
Mesh.SaveAll = 1;
Mesh.SaveParametric = 1;

Mesh.Algorithm = 9; // PACK
Mesh.PackSizemapMethod = 3;
Mesh.PackPatterns = 1;
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
  Printf("analytic_box_patterns: %g quadrangles, %g triangles, minimum quality %g",
         Mesh.NbQuadrangles, Mesh.NbTriangles, Mesh.MinQuality);
  If(Mesh.NbQuadrangles == 0)
    Error("analytic_box_patterns: no quadrangle");
  EndIf
  If(Mesh.NbTriangles > 0.05 * Mesh.NbQuadrangles)
    Error("analytic_box_patterns: %g triangles for %g quadrangles", Mesh.NbTriangles, Mesh.NbQuadrangles);
  EndIf
  If(Mesh.MinQuality <= 0)
    Error("analytic_box_patterns: invalid element (minimum quality %g)", Mesh.MinQuality);
  EndIf
EndIf
