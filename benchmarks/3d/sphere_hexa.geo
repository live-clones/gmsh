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
Transfinite Line{1:4} = n;
Line Loop(5) = {4,1,2,3};
Plane Surface(6) = {5};
Transfinite Surface{6} = {2,3,4,5};
Recombine Surface{6};
Extrude Surface {6, {0.0,0.0,2*r1}};

// force transfinite grid in interior cube
Transfinite Line {3,22,11,13,8,4,14,9,1,18,10,2} = n;
Transfinite Surface {6} = {4,5,2,3};
Transfinite Surface {15} = {5,6,7,2};
Transfinite Surface {19} = {11,7,2,3};
Transfinite Surface {23} = {4,15,11,3};
Transfinite Surface {27} = {15,6,5,4};
Transfinite Surface {28} = {15,6,7,11};
Recombine Surface{6,15,19,23,27,28};
Transfinite Volume{1} = {4,5,2,3,15,6,7,11};

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

// force transfinite grid in exterior shell
Transfinite Line{29:59} = n;
Transfinite Surface {34} = {102,103,104,105};
Transfinite Surface {35} = {106,108,102,103};
Transfinite Surface {40} = {109,111,108,106};
Transfinite Surface {45} = {104,105,111,109};
Transfinite Surface {50} = {104,109,106,103};
Transfinite Surface {51} = {105,111,108,102};
Recombine Surface{34,35,40,45,50,51};
Transfinite Surface {61} = {3,2,102,103};
Transfinite Surface {63} = {2,7,108,102};
Transfinite Surface {65} = {11,7,108,106};
Transfinite Surface {67} = {3,11,106,103};
Transfinite Surface {69} = {104,4,3,103};
Transfinite Surface {71} = {109,15,11,106};
Transfinite Surface {73} = {6,111,108,7};
Transfinite Surface {75} = {5,105,102,2};
Transfinite Surface {77} = {104,105,5,4};
Transfinite Surface {79} = {104,109,15,4};
Transfinite Surface {81} = {109,111,6,15};
Transfinite Surface {83} = {6,111,105,5};
Recombine Surface{61:83:2};
Transfinite Volume{85} = {105,111,108,102, 5,6,7,2}; // x+
Transfinite Volume{87} = {15,11,3,4,109,106,103,104}; // x-
Transfinite Volume{89} = {11,7,2,3,106,108,102,103}; // y+
Transfinite Volume{91} = {15,4,5,6,109,104,105,111}; // y-
Transfinite Volume{93} = {15,6,7,11,109,111,108,106}; // z+
Transfinite Volume{95} = {4,3,2,5,104,103,102,105}; // z-

// group all hexas in a single volume
Physical Volume(1) = {1, 85:95:2};

