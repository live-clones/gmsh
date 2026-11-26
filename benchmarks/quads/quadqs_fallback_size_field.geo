// quadqs_fallback_size_field: the plate with rotated rectangular holes and a
// size field that examples/boolean/full_quad.geo used to mesh with the former
// quasi-structured quad algorithm, with the options of that script only
// (Mesh.Algorithm = 11, none of the PACK options). Gmsh warns and meshes with
// the packing of parallelograms and its defaults. The case checks that the
// option falls back to 9 and that the mesh is the one of PACK selected
// explicitly.
// Run: gmsh quadqs_fallback_size_field.geo -2

SetFactory("OpenCASCADE");
Rectangle(1) = {0, 0, 0, 10, 10};
Rectangle(2) = {2, 4, 0, 2, 1};
Rectangle(3) = {5, 5, 0, 1, 2};
Rectangle(4) = {2, 6, 0, 1, 1};
Rectangle(5) = {7, 2, 0, 2, 2};
Rotate {{0, 0, 1}, {5, 5, 0}, Pi/4} { Surface{3}; }
Rotate {{0, 0, 1}, {2, 6, 0}, Pi/3} { Surface{4}; }
MeshSize{ PointsOf{ Surface{1}; } } = 1;
MeshSize{ PointsOf{ Surface{2:5}; } } = 0.1;
BooleanDifference{ Surface{1}; Delete; }{ Surface{2:5}; Delete; }

// sizes decreasing smoothly away from the boundaries
Field[1] = Extend;
Field[1].SurfacesList = {Surface{:}};
Field[1].SizeMax = 1;
Field[1].Ratio = 1.2;
Background Field = 1;

Mesh.MeshSizeExtendFromBoundary = 0;
Mesh.RandomSeed = 1;
Mesh.SaveAll = 1;
Mesh.SaveParametric = 1;

// A curve may be meshed with a single edge: the defaults impose at least two
// edges on a general curve and one per 60 degrees of a circle arc.
Mesh.MinCurveNodes = 2;
Mesh.MinCircleNodes = 2;

Mesh.Algorithm = 11; // former quasi-structured quad: falls back to PACK
Mesh.RecombineAll = 1;

// The automatic tests only look at the exit status: mesh here and check the
// result. (audit.py only reads the CAD: it strips the Mesh options, which
// skips this block.)
If(Mesh.RecombineAll)
  If(Mesh.Algorithm != 9)
    Error("quadqs_fallback_size_field: Mesh.Algorithm = 11 gave %g instead of 9",
          Mesh.Algorithm);
  EndIf
  Mesh 2;
  nn = Mesh.NbNodes; nq = Mesh.NbQuadrangles; nt = Mesh.NbTriangles;
  Printf("quadqs_fallback_size_field: %g quadrangles, %g triangles, minimum quality %g",
         nq, nt, Mesh.MinQuality);
  If(nq == 0)
    Error("quadqs_fallback_size_field: no quadrangle");
  EndIf
  If(nt > 0.05 * nq)
    Error("quadqs_fallback_size_field: %g triangles for %g quadrangles", nt, nq);
  EndIf
  If(Mesh.MinQuality <= 0)
    Error("quadqs_fallback_size_field: invalid element (minimum quality %g)", Mesh.MinQuality);
  EndIf
  // the same with PACK selected explicitly
  Mesh.Algorithm = 9;
  Mesh 2;
  If(Mesh.NbNodes != nn || Mesh.NbQuadrangles != nq || Mesh.NbTriangles != nt)
    Error("quadqs_fallback_size_field: %g nodes, %g quadrangles, %g triangles with Mesh.Algorithm = 11 but %g, %g, %g with 9",
          nn, nq, nt, Mesh.NbNodes, Mesh.NbQuadrangles, Mesh.NbTriangles);
  EndIf
EndIf
