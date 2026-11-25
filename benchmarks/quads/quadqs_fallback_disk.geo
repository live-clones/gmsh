// quadqs_fallback_disk: a disk meshed by a script that asks for the former
// quasi-structured quad algorithm (Mesh.Algorithm = 11). The algorithm cannot
// be selected anymore: Gmsh warns and uses the packing of parallelograms (9).
// The case checks that the option falls back to 9 and that the mesh is the one
// of PACK selected explicitly.
// Run: gmsh quadqs_fallback_disk.geo -2

SetFactory("OpenCASCADE");
Disk(1) = {0, 0, 0, 20};

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
    Error("quadqs_fallback_disk: Mesh.Algorithm = 11 gave %g instead of 9",
          Mesh.Algorithm);
  EndIf
  Mesh 2;
  nn = Mesh.NbNodes; nq = Mesh.NbQuadrangles; nt = Mesh.NbTriangles;
  Printf("quadqs_fallback_disk: %g quadrangles, %g triangles, minimum quality %g",
         nq, nt, Mesh.MinQuality);
  If(nq == 0)
    Error("quadqs_fallback_disk: no quadrangle");
  EndIf
  If(nt > 0.05 * nq)
    Error("quadqs_fallback_disk: %g triangles for %g quadrangles", nt, nq);
  EndIf
  If(Mesh.MinQuality <= 0)
    Error("quadqs_fallback_disk: invalid element (minimum quality %g)", Mesh.MinQuality);
  EndIf
  // the same with PACK selected explicitly
  Mesh.Algorithm = 9;
  Mesh 2;
  If(Mesh.NbNodes != nn || Mesh.NbQuadrangles != nq || Mesh.NbTriangles != nt)
    Error("quadqs_fallback_disk: %g nodes, %g quadrangles, %g triangles with Mesh.Algorithm = 11 but %g, %g, %g with 9",
          nn, nq, nt, Mesh.NbNodes, Mesh.NbQuadrangles, Mesh.NbTriangles);
  EndIf
EndIf
