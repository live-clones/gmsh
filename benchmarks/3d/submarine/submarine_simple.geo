lc = 25;
Mesh.CharacteristicLengthMin = lc;
Mesh.CharacteristicLengthMax = lc;
Mesh.Smoothing = 0;

Merge "submarine.brep";


Compound Surface(1034) = {12};

Physical Surface(1) = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
Physical Surface(2) = {1034};
Physical Surface(3) = {11};

MeshAlgorithm Surface {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,1034}  9;
MeshAlgorithm Surface {12}  5;
Mesh.Recombine3DAll = 1;
Mesh.Algorithm3D = 9;
Delete {Volume {1};}
//Compound Volume(1035) = {1};

Surface Loop(1000) = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1034};
Volume(1001) = {1000};
Physical Volume(1) = {1001};
