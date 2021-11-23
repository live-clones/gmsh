SetFactory("OpenCASCADE");

a() = ShapeFromFile("PeriodicFaceWithLargeTolerance.brep");

Mesh.Algorithm = 6;
Mesh.MeshSizeFromCurvature = 10;

Mesh 2;

nbtriangles = Mesh.NbTriangles;
If(nbtriangles == 0)
  Error("No triangular elements created!");
EndIf
