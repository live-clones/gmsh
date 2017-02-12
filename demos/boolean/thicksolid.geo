SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMin = 0.1;
Mesh.CharacteristicLengthMax = 0.1;

Block(1) = {0,0,0,1,1,1};
ThickSolid(11) = {1, 0.05};

Block(2) = {2,0,0,3,1,1};
Boundary{ Volume{2}; }
ThickSolid(12) = {2, 0.05, 1, 2};

Delete{Volume{1,2};}
