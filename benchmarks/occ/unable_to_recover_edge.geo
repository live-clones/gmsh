SetFactory("OpenCASCADE");

a() = ShapeFromFile("unable_to_recover_edge_2d.brep");

Mesh.Algorithm = 1;
lc = 500;
Mesh.CharacteristicLengthMin = lc;
Mesh.CharacteristicLengthMax = lc;
Mesh 2;

nbtriangles = Mesh.NbTriangles;
If(nbtriangles == 0)
  Error("No triangle elements created!");
EndIf
