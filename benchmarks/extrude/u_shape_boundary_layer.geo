Point(1) = {0, 0.5, 0, 0.1};
Point(2) = {0.1, 0.7, 0, 0.1};
Point(3) = {0.3, 0.8, 0, 0.1};
Point(4) = {1, 0.8, 0, 0.1};
Point(5) = {2.1, 0.5, 0, 0.1};
Point(6) = {3, 0.5, 0, 0.1};
Point(7) = {1, 0.4, 0, 0.1};
Point(8) = {0.3, 0.4, 0, 0.1};
Point(9) = {0.1, 0.4, 0, 0.1};
BSpline(1) = {5, 4, 3, 2, 1};
BSpline(2) = {1, 9, 8, 7, 5};
Line(3) = {5, 6};

Extrude { Line{1,-3}; Layers{5,0.04}; Using Index[0]; }
Extrude { Line{2,3}; Layers{5,0.04}; Using Index[1]; }

// fix leading edge by hand
Coherence Point {25, 16};

Point(31) = {-0.5, 1.5, 0, 0.2};
Point(32) = {-0.5, -0.5, 0, 0.2};
Point(33) = {3.5, -0.5, 0, 0.2};
Point(34) = {3.5, 1.5, 0, 0.2};
Line(20) = {32, 33};
Line(21) = {33, 34};
Line(22) = {34, 31};
Line(23) = {31, 32};
Line Loop(24) = {22, 23, 20, 21};
Line Loop(25) = {4, 12, 16, -18, 9, 8};
//Plane Surface(26) = {24, 25};
