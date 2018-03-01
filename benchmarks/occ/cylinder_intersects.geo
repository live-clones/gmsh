SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMin = 0.02;
Mesh.CharacteristicLengthMax = 0.4;

Circle(1) = {0,0,0, 2, Pi};
Circle(2) = {0,0,0, 2, Pi, 2*Pi};
Extrude{0,0,10}{ Line{1,2}; }
Cylinder(2) = {0, 0, 5, 0, 10, 0, 1, 2*Pi};
BooleanDifference{ Surface{1,2}; Delete; }{ Volume{2}; Delete; }

Rectangle(9) = {0, 0, 4, 4, 1, 0};
Rotate {{1, 0, 0}, {0, 0, 4}, Pi/2} {Surface{9};}
Rotate {{0, 0, 1}, {0, 0, 4}, Pi/6} {Surface{9};}

BooleanFragments{ Surface{1,9}; Delete; }{}
Recursive Delete{ Surface{3,4}; }
Characteristic Length{7, 8} = 0.02;
