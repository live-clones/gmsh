SetFactory("OpenCASCADE");
Merge "rod.brep";

Rectangle(100) = {-0.0095, 0, 0, 0.0095-0.005*Sqrt(2)/2, 0.1162};
s1() = Rotate{{1,0,0}, {-0.0095,0,0}, Pi/2}{ Surface{100}; };
s2() = Rotate{{0,0,1}, {0,0,0}, Pi/2}{ Duplicata{ Surface{s1()}; } };
s3() = Symmetry{1,0,0,0}{ Duplicata{ Surface{s1()}; } };
s4() = Symmetry{0,1,0,0}{ Duplicata{ Surface{s2()}; } };

Rectangle(200) = {-0.0095, -0.0095, 0.02, 0.0190, 0.0190};
Rectangle(201) = {-0.0095, -0.0095, 0.0327, 0.0190, 0.0190};
Rectangle(202) = {-0.0095, -0.0095, 0.0835, 0.0190, 0.0190};
Rectangle(203) = {-0.0095, -0.0095, 0.0962, 0.0190, 0.0190};

Box(2) = {-0.0025, -0.0025, 0, 0.005, 0.005, 0.1162};
Rotate{{0,0,1}, {0,0,0}, Pi/4}{ Volume{2}; }

Geometry.ToleranceBoolean = 0;
BooleanFragments{ Surface{s1(), s2(), s3(), s4(), 200:203}; Delete; }{ Volume{1,2}; Delete; }

// remove all surfaces not on boundary of a volume
Recursive Delete { Surface{:}; }

Transfinite Curve{:} = 10;
Transfinite Surface{:};
Recombine Surface{:};
Transfinite Volume{:};
