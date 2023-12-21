SetFactory("OpenCASCADE");

a() = ShapeFromFile("CylindricalSurface.brep");

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthExtendFromBoundary = 1;
Mesh.CharacteristicLengthFactor = 1.0;

Mesh 2;

nbtriangles = Mesh.NbTriangles;
If(nbtriangles == 0)
  Error("No triangular elements created!");
EndIf
