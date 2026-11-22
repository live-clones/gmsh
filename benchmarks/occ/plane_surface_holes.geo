SetFactory("OpenCASCADE");

// The curve loops of the holes of a plane surface can be oriented either way,
// and the outer one too: a hole oriented like the outer boundary used to add
// its area instead of removing it, and booleans then failed on the surface
// (#3219)

Point(1) = {0, 0, 0}; Point(2) = {1, 0, 0}; Point(3) = {1, 1, 0};
Point(4) = {0, 1, 0};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 1};
Point(5) = {0.1, 0.1, 0}; Point(6) = {0.2, 0.1, 0}; Point(7) = {0.2, 0.2, 0};
Point(8) = {0.1, 0.2, 0};
Line(5) = {5, 6}; Line(6) = {6, 7}; Line(7) = {7, 8}; Line(8) = {8, 5};
Point(9) = {0.3, 0.1, 0}; Point(10) = {0.4, 0.1, 0}; Point(11) = {0.4, 0.2, 0};
Point(12) = {0.3, 0.2, 0};
Line(9) = {9, 10}; Line(10) = {10, 11}; Line(11) = {11, 12}; Line(12) = {12, 9};
Circle(13) = {0.7, 0.7, 0, 0.1};

Curve Loop(1) = {1, 2, 3, 4};
Curve Loop(2) = {5, 6, 7, 8}; // like the outer boundary
Curve Loop(3) = {-12, -11, -10, -9}; // opposite
Curve Loop(4) = {13};
Curve Loop(5) = {-4, -3, -2, -1}; // the outer boundary, the other way

Plane Surface(1) = {1, 2, 3, 4};
Plane Surface(2) = {5, 2, 3, 4};
area = 1 - 0.01 - 0.01 - Pi * 0.01;
For s In {1:2}
  a = Mass Surface{s};
  If(Fabs(a - area) > 1e-6)
    Error("Surface %g has area %g instead of %g", s, a, area);
  EndIf
EndFor

// a plate crossing the surface through a hole splits it
Rectangle(10) = {0.35, -0.1, -0.5, 1, 1};
Rotate{{1, 0, 0}, {0.35, -0.1, -0.5}, Pi/2}{ Surface{10}; }
Rotate{{0, 0, 1}, {0.35, 0, 0}, Pi/2}{ Surface{10}; }
out() = BooleanFragments{ Surface{1}; Delete; }{ Surface{10}; Delete; };
If(#out() < 3)
  Error("Fragments give %g surfaces instead of at least 3", #out());
EndIf
