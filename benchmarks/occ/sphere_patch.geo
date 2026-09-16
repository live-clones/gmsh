SetFactory("OpenCASCADE");

r1 = 1;

cp = newp; Point(cp) = {0,0,0};
cp_coords[] = Point{cp};
p1 = newp; Point(p1) = {cp_coords[0] + r1, cp_coords[1] + r1, cp_coords[2] + r1};
p2 = newp; Point(p2) = {cp_coords[0] - r1, cp_coords[1] + r1, cp_coords[2] + r1};
p3 = newp; Point(p3) = {cp_coords[0] - r1, cp_coords[1] - r1, cp_coords[2] + r1};
p4 = newp; Point(p4) = {cp_coords[0] + r1, cp_coords[1] - r1, cp_coords[2] + r1};

l1 = newl; Circle(l1) = {p1,cp,p2};
l2 = newl; Circle(l2) = {p2,cp,p3};
l3 = newl; Circle(l3) = {p3,cp,p4};
l4 = newl; Circle(l4) = {p4,cp,p1};

Sphere(100) = {0,0,0, Sqrt(3)};
Rotate{{1,0,0}, {0,0,0}, Pi/2}{ Volume{100}; }
Delete { Volume{100}; }

BooleanFragments{ Curve{l1, l2, l3, l4}; Delete; } { Surface{1}; Delete; }
Recursive Delete { Surface{1}; }

Transfinite Curve{l1, l2, l3, l4} = 10;
Transfinite Surface{2};
Recombine Surface{2};
