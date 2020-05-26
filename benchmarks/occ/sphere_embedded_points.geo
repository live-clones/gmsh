SetFactory("OpenCASCADE");

Point(newp) = {8.000000, 6.000000, 0.000000};
Point(newp) = {8.000000, 0.000000, 6.000000}; // **
Point(newp) = {8.000000, 0.000000, -6.000000}; // **
Point(newp) = {6.000000, -8.000000, 0.000000};
Point(newp) = {0.000000, 10.000000, 0.000000};
Point(newp) = {0.000000, 0.000000, 10.000000};
np = newp-1;
Sphere(1) = { 0, 0, 0, 10 };
//Point {1:np} In Surface{1}; // cannot work for ** on seam -> fragment!
BooleanFragments{ Point{1:np}; Delete; }{ Surface{1}; Delete; }
Mesh.CharacteristicLengthMax = 1.0;
