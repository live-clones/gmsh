SetFactory("OpenCASCADE");

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthMin = 0.4;
Mesh.CharacteristicLengthMax = 0.4;

R = 1.4;
s = .7;
t = 1.25;

Block(1) = {-R,-R,-R, R,R,R};

Sphere(2) = {0,0,0,R*t};

BooleanIntersection(3) = { Volume{1}; Delete; }{ Volume{2}; Delete; };

Cylinder(4) = {-2*R,0,0, 2*R,0,0, R*s};
Cylinder(5) = {0,-2*R,0, 0,2*R,0, R*s};
Cylinder(6) = {0,0,-2*R, 0,0,2*R, R*s};

BooleanUnion(7) = { Volume{4}; Delete; }{ Volume{5}; Delete; };
BooleanUnion(8) = { Volume{6}; Delete; }{ Volume{7}; Delete; };
BooleanSubtraction(9) = { Volume{3}; Delete; }{ Volume{8}; Delete; };
