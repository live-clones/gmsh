SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMin = 0.1;
Mesh.CharacteristicLengthMax = 0.1;

Box(1) = {0,0,0,1,1,1};

Fillet{1}{1, 3}{0.2, 0.05, 0.2, 0.05}
