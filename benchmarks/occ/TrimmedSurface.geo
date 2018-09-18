SetFactory("OpenCASCADE");

a() = ShapeFromFile("TrimmedSurface.brep");

lc = 2.2626725788082012;
Mesh.Algorithm = 6;
Mesh.CharacteristicLengthExtendFromBoundary = 1;
Mesh.CharacteristicLengthFactor = 1.0;
Mesh.CharacteristicLengthMin = lc;
Mesh.CharacteristicLengthMax = lc;
Mesh.QualityType = 0;

Mesh 2;
