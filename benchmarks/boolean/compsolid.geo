SetFactory("OpenCASCADE");

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthMin = 0.1;
Mesh.CharacteristicLengthMax = 0.1;

Block(1) = {0,0,0, 2,2,2};
Sphere(2) = {2.2, 1, 1, 0.5};
Block(3) = {2,0,0, 4,2,2};

BooleanFragments { Volume{1}; Delete; }{ Volume{2,3}; Delete; }
