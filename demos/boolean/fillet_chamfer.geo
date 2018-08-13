SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMin = 0.1;
Mesh.CharacteristicLengthMax = 0.1;

Box(1) = {0,0,0,1,1,1};

Chamfer{1}{1,10,5}{3,3,3}{0.2}
Fillet{1}{1}{0.2}
