SetFactory("OpenCASCADE");

a() = ShapeFromFile("full_sphere.brep");

Mesh.Algorithm = 2;
Mesh.Algorithm3D = 2;
Mesh.ElementOrder = 2;

lc = 5;
Mesh.CharacteristicLengthMin = lc;
Mesh.CharacteristicLengthMax = lc;
Mesh 3;

nbtets = Mesh.NbTetrahedra;
If(nbtets == 0)
  Error("No tetrahedral elements created!");
EndIf
