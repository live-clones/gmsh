// quadqs_fallback_options: an L-shaped plate meshed by a script that sets the
// options of the former quasi-structured quad algorithm (Mesh.Algorithm = 11
// and Mesh.Quadqs*). The options are deprecated: they are still accepted, so
// that such a script runs, but they are not documented anymore and change
// nothing. The case checks that they are read back as set and that the mesh is
// the one of PACK without them.
// Run: gmsh quadqs_fallback_options.geo -2

SetFactory("OpenCASCADE");
Rectangle(1) = {0, 0, 0, 40, 40};
Rectangle(2) = {20, 20, 0, 21, 21};
BooleanDifference{ Surface{1}; Delete; }{ Surface{2}; Delete; }

// Target edge length in model units (equal bounds give uniform sizing).
DefineConstant[
  h = {2, Min 0.5, Max 10, Step 0.5, Name "Parameters/Target edge length"}
];

Mesh.MeshSizeMin = h;
Mesh.MeshSizeMax = h;
Mesh.RandomSeed = 1;
Mesh.SaveAll = 1;
Mesh.SaveParametric = 1;

Mesh.Algorithm = 11; // former quasi-structured quad: falls back to PACK
Mesh.QuadqsSizemapMethod = 1;
Mesh.QuadqsTopologyOptimizationMethods = 101;
Mesh.QuadqsRemeshingBoldness = 0.3;
Mesh.QuadqsScalingOnTriangulation = 0.5;
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
  If(Mesh.Algorithm != 9)
    Error("quadqs_fallback_options: Mesh.Algorithm = 11 gave %g instead of 9",
          Mesh.Algorithm);
  EndIf
  If(Mesh.QuadqsSizemapMethod != 1 ||
     Mesh.QuadqsTopologyOptimizationMethods != 101 ||
     Mesh.QuadqsRemeshingBoldness != 0.3 ||
     Mesh.QuadqsScalingOnTriangulation != 0.5)
    Error("quadqs_fallback_options: a Mesh.Quadqs option is not read back as set");
  EndIf
  Mesh 2;
  nn = Mesh.NbNodes; nq = Mesh.NbQuadrangles; nt = Mesh.NbTriangles;
  Printf("quadqs_fallback_options: %g quadrangles, %g triangles, minimum quality %g",
         nq, nt, Mesh.MinQuality);
  If(nq == 0)
    Error("quadqs_fallback_options: no quadrangle");
  EndIf
  If(nt > 0.05 * nq)
    Error("quadqs_fallback_options: %g triangles for %g quadrangles", nt, nq);
  EndIf
  If(Mesh.MinQuality <= 0)
    Error("quadqs_fallback_options: invalid element (minimum quality %g)", Mesh.MinQuality);
  EndIf
  // the same with PACK selected explicitly and the default Mesh.Quadqs options
  Mesh.Algorithm = 9;
  Mesh.QuadqsSizemapMethod = 3;
  Mesh.QuadqsTopologyOptimizationMethods = 0;
  Mesh.QuadqsRemeshingBoldness = 0.66;
  Mesh.QuadqsScalingOnTriangulation = 0.75;
  Mesh 2;
  If(Mesh.NbNodes != nn || Mesh.NbQuadrangles != nq || Mesh.NbTriangles != nt)
    Error("quadqs_fallback_options: %g nodes, %g quadrangles, %g triangles with the Mesh.Quadqs options but %g, %g, %g without",
          nn, nq, nt, Mesh.NbNodes, Mesh.NbQuadrangles, Mesh.NbTriangles);
  EndIf
EndIf
