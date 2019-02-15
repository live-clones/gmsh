SetFactory("OpenCASCADE");

a() = ShapeFromFile("SlenderSurface.brep");

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthExtendFromBoundary = 1;
Mesh.CharacteristicLengthFactor = 10.0;

Mesh 2;

nbtriangles = Mesh.NbTriangles;
If(nbtriangles == 0)
  Error("No triangular elements created!");
EndIf
