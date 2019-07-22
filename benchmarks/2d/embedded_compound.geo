lc = 0.1;

Point(1) = {0, 0, 0, lc};      Point(2) = {1, 0, 0.05, lc};
Point(3) = {1, 1, 0, lc};      Point(4) = {0, 1, 0, lc};
Point(5) = {0.3, 0.2, 0, lc};  Point(6) = {0, 0.01, 0., lc};
Point(7) = {0, 0.02, 0.0, lc}; Point(8) = {1, 0.05, 0.0, lc};
Point(9) = {1, 0.32, 0.0, lc};

Line(1) = {1, 2}; Line(2) = {2, 8}; Line(3) = {8, 9};
Line(4) = {9, 3}; Line(5) = {3, 4}; Line(6) = {4, 7};
Line(7) = {7, 6}; Line(8) = {6, 1}; Spline(9) = {7, 5, 9};
Line(10) = {6, 8};

Curve Loop(11) = {5, 6, 9, 4};     Surface(1) = {11};
Curve Loop(13) = {-9, 3, 10, 7}; Surface(5) = {13};
Curve Loop(15) = {-10, 2, 1, 8}; Surface(10) = {15};

// Treat curves 2, 3 and 4 as a single curve when meshing (i.e. mesh across
// points 6 and 7)
Compound Curve{2, 3, 4};
// Idem with curves 6, 7 and 8
Compound Curve{6, 7, 8};

// Treat surfaces 1, 5 and 10 as a single surface when meshing (i.e. mesh across
// curves 9 and 10)
Compound Surface{1, 5, 10};
Point(10) = {0.2, 0.6, 0, lc/2};
Point(11) = {0.7, 0.2, 0, lc/20};
Line(11) = {10, 11};

// test embedding of a curve across the internal boundary
Curve{11} In Surface{1}; // any surface (1, 5 or 10) would do
