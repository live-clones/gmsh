SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMin = 0.1;
Mesh.CharacteristicLengthMax = 0.1;

Box(1) = {0,0,0,1,1,1};

Chamfer{1}{1,2}{1,1}{0.2,0.05}
