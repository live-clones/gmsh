// The surface mesher splits some of the curves of this face to recover them.
// Meshing the surface a second time starts from the split curves, whose nodes
// have to be listed in order along them: the renumbering done after the first
// pass used to move the nodes added by the splits to the end of the lists.

SetFactory("OpenCASCADE");

a() = ShapeFromFile("PeriodicFaceWithLargeTolerance.brep");

Mesh.Algorithm = 6;
Mesh.MeshSizeFromCurvature = 10;

Mesh 2;
first = Mesh.NbTriangles;
Mesh 2;

nbtriangles = Mesh.NbTriangles;
If(nbtriangles == 0)
  Error("No triangular elements created!");
EndIf
If(nbtriangles < 0.8 * first || nbtriangles > 1.2 * first)
  Error("%g triangles in the second pass, %g in the first", nbtriangles, first);
EndIf
