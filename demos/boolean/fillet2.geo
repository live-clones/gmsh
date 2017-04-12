SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMin = 1;
Mesh.CharacteristicLengthMax = 1;

a() = ShapeFromFile("component8.step");

f() = Abs(Boundary{ Volume{a()}; });
e() = Unique(Abs(Boundary{ Surface{f()}; }));

Fillet{a()}{e()}{1}
