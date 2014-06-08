h1 = 3;
r1 = 5;
h2 = 0.5;
r2 = 1.1;

Point(1) = {0, 0, 0, 1};
Point(2) = {r1, 0, 0, 1};
Point(3) = {0, r1, 0, 1};
Point(4) = {-r1, 0, 0, 1};
Point(5) = {0, -r1, 0, 1};
Circle(1) = {2, 1, 3};
Circle(2) = {3, 1, 4};
Circle(3) = {4, 1, 5};
Circle(4) = {5, 1, 2};
Point(11) = {0, 0, h1, 1};
Point(12) = {r1, 0, h1, 1};
Point(13) = {0, r1, h1, 1};
Point(14) = {-r1, 0, h1, 1};
Point(15) = {0, -r1, h1, 1};
Circle(11) = {12, 11, 13};
Circle(12) = {13, 11, 14};
Circle(13) = {14, 11, 15};
Circle(14) = {15, 11, 12};
Point(22) = {r2, 0, h1, 1};
Point(23) = {0, r2, h1, 1};
Point(24) = {-r2, 0, h1, 1};
Point(25) = {0, -r2, h1, 1};
Circle(21) = {22, 11, 23};
Circle(22) = {23, 11, 24};
Circle(23) = {24, 11, 25};
Circle(24) = {25, 11, 22};
Point(31) = {0, 0, h2+h1, 1};
Point(32) = {r2, 0, h2+h1, 1};
Point(33) = {0, r2, h2+h1, 1};
Point(34) = {-r2, 0, h2+h1, 1};
Point(35) = {0, -r2, h2+h1, 1};
Circle(31) = {32, 31, 33};
Circle(32) = {33, 31, 34};
Circle(33) = {34, 31, 35};
Circle(34) = {35, 31, 32};
Line(55) = {5, 15};
Line(56) = {2, 12};
Line(57) = {3, 13};
Line(58) = {4, 14};
Line(59) = {23, 33};
Line(60) = {22, 32};
Line(61) = {25, 35};
Line(62) = {24, 34};

Line Loop(63) = {3, 4, 1, 2};
Plane Surface(64) = {63};
Line Loop(65) = {13, 14, 11, 12};
Line Loop(66) = {23, 24, 21, 22};
Plane Surface(67) = {65, 66};
Line Loop(69) = {33, 34, 31, 32};
Plane Surface(70) = {69};
Line Loop(71) = {13, -55, -3, 58};
Ruled Surface(72) = {71};
Line Loop(73) = {12, -58, -2, 57};
Ruled Surface(74) = {73};
Line Loop(75) = {1, 57, -11, -56};
Ruled Surface(76) = {75};
Line Loop(77) = {4, 56, -14, -55};
Ruled Surface(78) = {77};
Line Loop(81) = {33, -61, -23, 62};
Ruled Surface(82) = {81};
Line Loop(83) = {32, -62, -22, 59};
Ruled Surface(84) = {83};
Line Loop(85) = {60, 31, -59, -21};
Ruled Surface(86) = {85};
Line Loop(87) = {24, 60, -34, -61};
Ruled Surface(88) = {87};

// THIS DOES NOT WORK (INTERNAL SURF)
//Plane Surface(68) = {66};
//Surface Loop(79) = {78, 64, 72, 67, 76, 74, 68};
//Volume(80) = {79};
//Surface Loop(89) = {70, 82, 88, 86, 84, 68};
//Volume(90) = {89};

// this is OK
Surface Loop(89) = {67, 72, 78, 64, 76, 74, 84, 70, 82, 88, 86};
Volume(90) = {89};


Mesh.Algorithm = 7; //Bamg
Mesh.Algorithm3D= 7; //mmg3d
Mesh.CharacteristicLengthExtendFromBoundary = 0;
// Layer 1 xy
Field[1] = Box;
Field[1].VIn = r1 / 5;
Field[1].VOut = 10;
Field[1].XMax = r1 + 1;
Field[1].XMin = -r1 - 1;
Field[1].YMax = r1 + 1;
Field[1].YMin = -r1 - 1;
Field[1].ZMax = h1;
Field[1].ZMin = 0;
// Layer 1 z
Field[2] = Box;
Field[2].VIn = h1 / 10;
Field[2].VOut = 10;
Field[2].XMax = r1 + 1;
Field[2].XMin = -r1 - 1;
Field[2].YMax = r1 + 1;
Field[2].YMin = -r1 - 1;
Field[2].ZMax = h1;
Field[2].ZMin = 0;
// Layer 2 xy
Field[3] = Box;
Field[3].VIn = r2 / 5;
Field[3].VOut = 10;
Field[3].XMax = r2 + 1;
Field[3].XMin = -r2 - 1;
Field[3].YMax = r2 + 1;
Field[3].YMin = -r2 - 1;
Field[3].ZMax = h2+h1;
Field[3].ZMin = h1;
// Layer 2 z
Field[4] = Box;
Field[4].VIn = h2 / 90;
Field[4].VOut = 10;
Field[4].XMax = r2 + 1;
Field[4].XMin = -r2 - 1;
Field[4].YMax = r2 + 1;
Field[4].YMin = -r2 - 1;
Field[4].ZMax = h2+h1;
Field[4].ZMin = h1;


// xy
Field[7] = Min;
Field[7].FieldsList = {1,3};
// z
Field[8] = Min;
Field[8].FieldsList = {2,4};

Field[10] = MathEvalAniso;
Field[10].m11 = "1 / F7^2";
Field[10].m12 = "0";
Field[10].m13 = "0";
Field[10].m22 = "1 / F7^2";
Field[10].m23 = "0";
Field[10].m33 = "1 / F8^2";

Background Field = 10;

