// Gmsh

m=0.3;

Point(1) = {0, 0, 0, m};
Point(2) = {10, 0, 0, m};
Point(3) = {10, 10, 0, m};
Point(4) = {0, 10, 0, m};
Point(5) = {4, 4, 0, m};
Point(6) = {6, 4, 0, m};
Point(7) = {6, 6, 0, m};
Point(8) = {4, 6, 0, m};
Point(newp) = {0, 0, 1, m};
Point(newp) = {10, 0, 1, m};
Point(newp) = {10, 10, 1, m};
Point(newp) = {0, 10, 1, m};
Point(newp) = {4, 4, 1, m};
Point(newp) = {6, 4, 1, m};
Point(newp) = {6, 6, 1, m};
Point(newp) = {4, 6, 1, m};

Point(newp) = {0, 1, 0, m};
Point(newp) = {7, 1, 0, m};
Point(newp) = {7, 0, 0, m};

Line(5) = {17, 4};
Line(6) = {4, 12};
Line(7) = {9, 12};

Point(newp) = {9, 10, 1, m};
Point(newp) = {10, 3, 1, m};
Point(newp) = {9, 3, 1, m};
Point(newp) = {9, 4, 1, m};


Point(newp) = {5, 4, 1, m};
Point(newp) = {5, 4, 1, m};
Point(newp) = {4, 3, 1, m};

Line(8) = {20, 11};
Line(9) = {11, 3};
Line(10) = {20, 12};
Line(11) = {4, 3};
Line(12) = {9, 1};
Line(13) = {20, 23};
Line(14) = {11, 21};
Line(15) = {22, 21};
Line(16) = {23, 22};
Line(17) = {14, 23};
Line(18) = {14, 24};

Line(19) = {24, 13};
Line(20) = {13, 26};
Line(21) = {26, 22};

Point(newp) = {6, 5, 1, m};
Point(newp) = {6, 5, 0, m};
Point(newp) = {5, 4, 0, m};


Line(22) = {8, 7};
Line(23) = {7, 15};
Line(24) = {15, 16};
Line(25) = {16, 8};
Line(26) = {13, 16};
Line(27) = {5, 8};
Line(28) = {5, 13};
Line(29) = {28, 27};
Line(30) = {28, 7};
Line(31) = {15, 27};
Line(32) = {5, 29};
Line(33) = {29, 24};

Point(newp) = {6, 1, 0, m};
Line(34) = {17, 1};
Line(35) = {1, 19};
Line(36) = {19, 18};
Line(37) = {18, 30};
Line(38) = {30, 17};
Line(39) = {28, 6};

Point(newp) = {7, 6, 0, m};
Line(40) = {7, 31};
Line(41) = {31, 18};
Line(42) = {6, 30};



Line Loop(45) = {35, 36, 37, 38, 34};
Plane Surface(46) = {45};
Line Loop(47) = {41, 37, -42, -39, 30, 40};
Plane Surface(48) = {47};
Line Loop(49) = {34, -12, 7, -6, -5};
Plane Surface(50) = {49};
Line Loop(51) = {11, -9, -8, 10, -6};
Plane Surface(52) = {51};
Line Loop(53) = {13, 16, 15, -14, -8};
Plane Surface(54) = {53};
Line Loop(55) = {21, -16, -17, 18, 19, 20};
Plane Surface(56) = {55};
Line Loop(57) = {33, 19, -28, 32};
Plane Surface(58) = {57};
Line Loop(59) = {26, 25, -27, 28};
Plane Surface(60) = {59};
Line Loop(61) = {24, 25, 22, 23};
Plane Surface(62) = {61};
Line Loop(63) = {30, 23, 31, -29};
Plane Surface(64) = {63};
Line(65) = {2, 10};
Line(66) = {2, 3};
Line(67) = {21, 10};
Line(68) = {2, 19};
Line(69) = {10, 9};
Line(70) = {27, 14};
Line(71) = {14, 6};
Line(72) = {6, 29};
Line Loop(73) = {66, -9, 14, 67, -65};
Plane Surface(74) = {73};
Line Loop(75) = {69, 12, 35, -68, 65};
Plane Surface(76) = {75};
Line Loop(77) = {67, 69, 7, -10, 13, -17, -70, -31, 24, -26, 20, 21, 15};
Plane Surface(78) = {77};
Line Loop(79) = {68, 36, -41, -40, -22, -27, 32, -72, 42, 38, 5, 11, -66};
Plane Surface(80) = {79};
Line Loop(81) = {72, 33, -18, 71};
Plane Surface(82) = {81};
Line Loop(83) = {29, 70, 71, -39};
Plane Surface(84) = {83};
Surface Loop(85) = {76, 78, 74, 80, 46, 48, 84, 64, 62, 60, 58, 82, 56, 54, 52, 50};
Volume(86) = {85};
Physical Volume(87) = {86};
Physical Surface(88) = {46, 48, 64, 62, 60, 58, 56, 54, 52, 50};

Mesh 3;

HomGen("torsion.msh") = {{87},{88}};
