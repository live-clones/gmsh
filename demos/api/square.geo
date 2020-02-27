SetFactory("OpenCASCADE");
Rectangle(1) = {0,0,0, 1,1};
Mesh.CharacteristicLengthMin = 1;
Mesh.CharacteristicLengthMax = 1;
Transfinite Surface{1};
