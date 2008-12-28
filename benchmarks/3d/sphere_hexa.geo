l = 1;
r1 = 0.5;
r2 = 1;
n = 10;

// interior cube
Point(1) = {0,0,0,l};
Point(2) = {r1,r1,-r1,l};
Point(3) = {-r1,r1,-r1,l};
Point(4) = {-r1,-r1,-r1,l};
Point(5) = {r1,-r1,-r1,l};
Line(1) = {2,3};
Line(2) = {3,4};
Line(3) = {4,5};
Line(4) = {5,2};
Line Loop(5) = {4,1,2,3};
Plane Surface(6) = {5};
Extrude Surface {6, {0.0,0.0,2*r1}};

// exterior shell
Point(102) = {r2,r2,-r2,l};
Point(103) = {-r2,r2,-r2,l};
Point(104) = {-r2,-r2,-r2,l};
Point(105) = {r2,-r2,-r2,l};
Circle(29) = {103,1,102};
Circle(30) = {102,1,105};
Circle(31) = {105,1,104};
Circle(32) = {104,1,103};
Line Loop(33) = {29,30,31,32};
Ruled Surface(34) = {33};
Rotate { {1,0,0},{0,0,0}, Pi/2 } { Duplicata{ Surface{34}; } }
Rotate { {1,0,0},{0,0,0}, Pi } { Duplicata{ Surface{34}; } }
Rotate { {1,0,0},{0,0,0}, 3*Pi/2 } { Duplicata{ Surface{34}; } }
Rotate { {0,1,0},{0,0,0}, Pi/2 } { Duplicata { Surface{34}; } }
Rotate { {0,1,0},{0,0,0}, -Pi/2 } { Duplicata { Surface{34}; } }
Line(52) = {11,106};
Line(53) = {3,103};
Line(54) = {2,102};
Line(55) = {7,108};
Line(56) = {5,105};
Line(57) = {6,111};
Line(58) = {15,109};
Line(59) = {4,104};
Line Loop(60) = {54,-29,-53,-1}; Plane Surface(61) = {60};
Line Loop(62) = {54,-37,-55,-14}; Plane Surface(63) = {62};
Line Loop(64) = {55,-36,-52,-9}; Plane Surface(65) = {64};
Line Loop(66) = {39,-52,-18,53}; Plane Surface(67) = {66};
Line Loop(68) = {53,-32,-59,-2}; Plane Surface(69) = {68};
Line Loop(70) = {44,-58,-10,52}; Plane Surface(71) = {70};
Line Loop(72) = {8,55,-42,-57}; Plane Surface(73) = {72};
Line Loop(74) = {54,30,-56,4}; Plane Surface(75) = {74};
Line Loop(76) = {59,-31,-56,-3}; Plane Surface(77) = {76};
Line Loop(78) = {22,58,49,-59}; Plane Surface(79) = {78};
Line Loop(80) = {58,41,-57,-11}; Plane Surface(81) = {80};
Line Loop(82) = {13,57,-47,-56}; Plane Surface(83) = {82};
Surface Loop(84) = {51,-63,75,-83,-15,-73};Volume(85) = {84};
Surface Loop(86) = {23,69,-67,-50,-79,-71};Volume(87) = {86};
Surface Loop(88) = {35,65,63,-61,-67,-19};Volume(89) = {88};
Surface Loop(90) = {45,-77,-79,-27,83,81};Volume(91) = {90};
Surface Loop(92) = {40,-81,-71,-28,73,-65};Volume(93) = {92};
Surface Loop(94) = {34,61,-75,77,69,6};Volume(95) = {94};

Transfinite Line "*" = n;
Transfinite Surface "*";
Recombine Surface "*";
Transfinite Volume "*";

// group all hexas in a single volume
Physical Volume(1) = {1, 85:95:2};
