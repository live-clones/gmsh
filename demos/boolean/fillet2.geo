SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMin = 1;
Mesh.CharacteristicLengthMax = 1;

a() = ShapeFromFile("component8.step");

f() = Boundary{ Volume{a()}; };
e() = Unique( Boundary{ Surface{f()}; } );

Fillet{a()}{e()}{1}

Delete{ Volume{a()}; Surface{f()}; Line{e()}; }
