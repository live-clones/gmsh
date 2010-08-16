Mesh.CharacteristicLengthFactor=0.5;

R = 0.3;
H = 1.5;

Point (1) = {0, 0, 0};
Point (2) = {0, R, 0};
Point (3) = {0, -R, 0};
Point (4) = {0, 0, R};
Point (5) = {0, 0, -R};

Circle (1) = {2, 1, 4};
Circle (2) = {4, 1, 3};
Circle (3) = {3, 1, 5};
Circle (4) = {5, 1, 2};

Line Loop(5) = {4,1,2,3};
Plane Surface(6) = {5};

//here we create a volume by extruding
Extrude {H,0,0} {
  Surface{6};
}

//Compound Surface(100)={15,19,23,27};

//Surface Loop(200)={100,6,28};
//Volume(201)={200};

Physical Surface(100)={6};
Physical Surface(200)={28};
Physical Surface(300)={15,19,23,27};
Physical Volume(1)={1};
