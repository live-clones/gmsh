lc = 0.2;
Point(1) = {-1, -1, 0, lc};
Point(2) = {-0.3, -1, 0, lc};
Point(3) = {-0.3, -0.4, 0, lc};
Point(4) = {-1, -0.4, 0, lc};
Point(5) = {-0.5, -0.7, -0, lc};
Point(6) = {-0.6, -0.7, -0, lc};
Point(7) = {-0.7, -0.7, 0, lc};
Point(8) = {-0.6, -0.6, -0, lc};
Point(9) = {-0.6, -0.8, -0, lc};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Circle(5) = {5, 6, 8};
Circle(6) = {8, 6, 7};
Circle(7) = {7, 6, 9};
Circle(8) = {9, 6, 5};
Line Loop(9) = {4, 1, 2, 3};
Line Loop(10) = {6, 7, 8, 5};
Plane Surface(11) = {9, 10};
Recombine Surface{11};
Extrude {0, 0, 1} {
  Surface{11}; Layers{2}; Recombine;
}

Point(50) = {0.5, -1, 0, lc};
Point(51) = {0.5, -1, 1, lc};
Line(54) = {15, 51};
Line(55) = {51, 50};
Line(56) = {50, 2};
Point(52) = {0.1, -1, 0.4, 1.0};
Point(53) = {0.1, -1, 0.5, 1.0};
Point(54) = {0, -1, 0.5, 1.0};
Point(55) = {0.1, -1, 0.6, 1.0};
Point(56) = {0.2, -1, 0.5, 1.0};
Circle(57) = {56, 53, 52};
Circle(58) = {52, 53, 54};
Circle(59) = {54, 53, 55};
Circle(60) = {55, 53, 56};
Line Loop(61) = {27, 54, 55, 56};
Line Loop(62) = {60, 57, 58, 59};
Plane Surface(63) = {61, 62};
Recombine Surface{63};
Extrude {0, 0.6, 0} { // Warning: 4 layers here depends on lc !
  Surface{63}; Layers{4}; Recombine;
}
