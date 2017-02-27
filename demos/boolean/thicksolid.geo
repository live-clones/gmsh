SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMin = 0.1;
Mesh.CharacteristicLengthMax = 0.1;

Block(1) = {0,0,0,1,1,1};
Boundary{ Volume{1}; }
ThickSolid(100) = {1, 0.05, 6};

Delete{ Surface{6}; Volume{1}; }
