SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMin = 0.1;
Mesh.CharacteristicLengthMax = 0.1;

Block(1) = {0,0,0,1,1,1};
f() = Abs(Boundary{ Volume{1}; });
e() = Unique(Abs(Boundary{ Surface{f()}; }));

Fillet{1}{e()}{0.2}

tmp() = Fillet{1}{1,2,4}{0.05};
Translate{2,0,0} { Volume{tmp(0)}; }

Delete{ Volume{1}; Surface{f()}; Line{e()}; }
