// analytic_cylinder_holes: quad surface mesh of the skin of a cylinder drilled
// through by a smaller one: a periodic surface trimmed by two holes, the bore
// and the two plane ends.
// Run: gmsh analytic_cylinder_holes.geo -2   (PACK, Blossom, cavity optimizer)

SetFactory("OpenCASCADE");
Cylinder(1) = {0, 0, 0, 0, 0, 60, 15};
Cylinder(2) = {-30, 0, 30, 60, 0, 0, 6};
BooleanDifference{ Volume{1}; Delete; }{ Volume{2}; Delete; }
Delete { Volume{:}; } // the surfaces only

// Target edge length in model units (equal bounds give uniform sizing).
DefineConstant[
  h = {3, Min 0.5, Max 10, Step 0.5, Name "Parameters/Target edge length"}
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
  Printf("analytic_cylinder_holes: %g quadrangles, %g triangles, minimum quality %g",
         Mesh.NbQuadrangles, Mesh.NbTriangles, Mesh.MinQuality);
  If(Mesh.NbQuadrangles == 0)
    Error("analytic_cylinder_holes: no quadrangle");
  EndIf
  If(Mesh.NbTriangles > 0.05 * Mesh.NbQuadrangles)
    Error("analytic_cylinder_holes: %g triangles for %g quadrangles", Mesh.NbTriangles, Mesh.NbQuadrangles);
  EndIf
  If(Mesh.MinQuality <= 0)
    Error("analytic_cylinder_holes: invalid element (minimum quality %g)", Mesh.MinQuality);
  EndIf
EndIf
