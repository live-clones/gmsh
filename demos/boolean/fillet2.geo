SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMin = 1e-3;
Mesh.CharacteristicLengthMax = 1e-3;

a() = ShapeFromFile("component8.step");

f() = Abs(Boundary{ Volume{a()}; });
e() = Unique(Abs(Boundary{ Surface{f()}; }));

Fillet{a()}{e()}{1}
