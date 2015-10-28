Merge "Submarine.stp";

//Mesh.CharacteristicLengthExtendFromBoundary=0;
Mesh.Algorithm=9;
Mesh.Algorithm3D=9;
Mesh.Smoothing=0;
Mesh.Recombine3DAll=1;
Mesh.SaveParametric = 1;
MeshAlgorithm Surface {12}  6;

MeshAlgorithm Surface {10}  5;
MeshAlgorithm Surface {11}  5; 

//Mesh.Algorithm=5;
//Mesh.Algorithm3D=5;

Mesh.Optimize = 1;

//Mesh.CharacteristicLengthMax = 25;

Characteristic Length {14, 13, 15, 16, 10, 9, 11, 12, 6, 5, 19, 8, 4, 3, 7, 2, 1} = 100;
Characteristic Length {21} = 200;
Characteristic Length {17, 18} = 100;
Characteristic Length {20} = 200;

Compound Line(34) = {22, 24, 25};
Compound Surface(13) = {10};
Compound Surface(14) = {11};

submarineLine[] = {15, 21, 17, 26, 11, 20, 13, 27, 29, 8, 19, 10, 34};
Physical Line(1) = submarineLine[];
submarineSurf[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 13};
Physical Surface(2) = submarineSurf[];
Physical Surface(3) = {12,14};
Physical Volume(4) = {1};
Physical Line(5) = {30, 31};

