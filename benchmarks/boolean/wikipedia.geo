SetFactory("OpenCASCADE");

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthMin = 0.4;
Mesh.CharacteristicLengthMax = 0.4;

R = DefineNumber[ 1.4 , Name "Parameters/Dimension of the Block" ];
s = DefineNumber[  .7 , Name "Parameters/Cylinder of radius s *R" ];
t = DefineNumber[ 1.25, Name "Parameters/Sphere   of radius t *R" ];

Block(1) = {-R,-R,-R, R,R,R};

Sphere(2) = {0,0,0,R*t};

BooleanIntersection(3) = { Volume{1}; Delete; }{ Volume{2}; Delete; };

Cylinder(4) = {-2*R,0,0, 2*R,0,0, R*s};
Cylinder(5) = {0,-2*R,0, 0,2*R,0, R*s};
Cylinder(6) = {0,0,-2*R, 0,0,2*R, R*s};

BooleanUnion(7) = { Volume{4}; Delete; }{ Volume{5,6}; Delete; };
BooleanDifference(8) = { Volume{3}; Delete; }{ Volume{7}; Delete; };
