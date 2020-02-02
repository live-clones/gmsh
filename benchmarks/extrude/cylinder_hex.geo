Point(1) = {0, 0, 0};
Point(2) = {1, 0, 0};
Point(3) = {0, 1, 0};
Point(4) = {0, -1, 0};
Point(5) = {-1, 0, 0};
Circle(1) = {3, 1, 2};
Circle(2) = {2, 1, 4};
Circle(3) = {4, 1, 5};
Circle(4) = {5, 1, 3};

Point(6) = {0.5, 0, 0};
Point(7) = {0, 0.5, 0};
Point(8) = {0, -0.5, 0};
Point(9) = {-0.5, 0, 0};

Line(5) = {6, 7};
Line(6) = {7, 9};
Line(7) = {9, 8};
Line(8) = {8, 6};
Line(9) = {6, 2};
Line(10) = {7, 3};
Line(11) = {9, 5};
Line(12) = {8, 4};

Curve Loop(1) = {5, 10, 1, -9};
Plane Surface(1) = {1};
Curve Loop(2) = {10, -4, -11, -6};
Plane Surface(2) = {2};
Curve Loop(3) = {11, -3, -12, -7};
Plane Surface(3) = {3};
Curve Loop(4) = {12, -2, -9, -8};
Plane Surface(4) = {4};
Curve Loop(5) = {5, 6, 7, 8};
Plane Surface(5) = {5};

Transfinite Curve{:} = 10;
Transfinite Surface{:};
Recombine Surface{:};

Extrude {0, 0, 1} { Surface{:}; Layers{10}; Recombine; }
