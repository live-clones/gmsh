l = 1;
r1 = 3;
r2 = 0.5;
n = 10;
n2 = n;
progr = 1.4;

// exterior cube
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
Delete { Volume{1}; }

// force transfinite grid on exterior cube
Transfinite Line {3,22,11,13,8,4,14,9,1,18,10,2} = n;
Transfinite Surface {6} = {4,5,2,3};
Transfinite Surface {15} = {5,6,7,2};
Transfinite Surface {19} = {11,7,2,3};
Transfinite Surface {23} = {4,15,11,3};
Transfinite Surface {27} = {15,6,5,4};
Transfinite Surface {28} = {15,6,7,11};
Recombine Surface{6,15,19,23,27,28};

// interior sphere
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

// force transfinite grid on interior sphere
Transfinite Line{29:59} = n;
Transfinite Surface {34} = {102,103,104,105};
Transfinite Surface {35} = {106,108,102,103};
Transfinite Surface {40} = {109,111,108,106};
Transfinite Surface {45} = {104,105,111,109};
Transfinite Surface {50} = {104,109,106,103};
Transfinite Surface {51} = {105,111,108,102};
Recombine Surface{34,35,40,45,50,51};

// connect sphere and cube
Line(52) = {102,2};
Line(53) = {108,7};
Line(54) = {105,5};
Line(55) = {111,6};
Line(56) = {109,15};
Line(57) = {104,4};
Line(58) = {103,3};
Line(59) = {106,11};
Transfinite Line{52:59} = n2 Using Progression progr;

Line Loop(60) = {58,-1,-52,-29};Plane Surface(61) = {60};
Line Loop(62) = {58,18,-59,-39};Plane Surface(63) = {62};
Line Loop(64) = {59,-9,-53,-36};Plane Surface(65) = {64};
Line Loop(66) = {37,52,14,-53};Plane Surface(67) = {66};
Line Loop(68) = {56,-22,-57,-49};Plane Surface(69) = {68};
Line Loop(70) = {31,57,3,-54};Plane Surface(71) = {70};
Line Loop(72) = {54,13,-55,-47};Plane Surface(73) = {72};
Line Loop(74) = {55,-11,-56,41};Plane Surface(75) = {74};
Line Loop(76) = {59,10,-56,-44};Plane Surface(77) = {76};
Line Loop(78) = {58,2,-57,32};Plane Surface(79) = {78};
Line Loop(80) = {52,-4,-54,-30};Plane Surface(81) = {80};
Line Loop(82) = {42,53,-8,-55};Plane Surface(83) = {82};

// force transfinite grid on connection surfaces
Transfinite Surface {61} = {103,102,2,3};
Transfinite Surface {63} = {106,103,3,11};
Transfinite Surface {65} = {11,7,108,106};
Transfinite Surface {67} = {102,108,7,2};
Transfinite Surface {69} = {4,15,109,104};
Transfinite Surface {71} = {5,4,104,105};
Transfinite Surface {73} = {6,5,105,111};
Transfinite Surface {75} = {15,6,111,109};
Transfinite Surface {77} = {15,109,106,11};
Transfinite Surface {79} = {4,104,103,3};
Transfinite Surface {81} = {105,5,2,102};
Transfinite Surface {83} = {111,6,7,108};
Recombine Surface{61:83:2};

// connection volumes
Surface Loop(84) = {19,61,-63,-65,67,-35}; Volume(85) = {84};
Surface Loop(86) = {34,61,-79,6,81,-71}; Volume(87) = {86};
Surface Loop(88) = {23,-79,63,77,69,-50}; Volume(89) = {88};
Surface Loop(90) = {28,83,-40,75,-77,65}; Volume(91) = {90};
Surface Loop(92) = {15,81,-67,-51,-83,73}; Volume(93) = {92};
Surface Loop(94) = {27,-71,-45,-73,-75,-69}; Volume(95) = {94};

// force transfinite grid on connection volume
Transfinite Volume{85} = {106,108,102,103,11,7,2,3};
Transfinite Volume{87} = {104,105,102,103,4,5,2,3};
Transfinite Volume{89} = {104,109,106,103,4,15,11,3};
Transfinite Volume{91} = {109,111,108,106,15,6,7,11};
Transfinite Volume{93} = {111,105,102,108,6,5,2,7};
Transfinite Volume{95} = {109,104,105,111,15,4,5,6};

Physical Volume(1) = {85:95:2}; // ext volume
Physical Surface(100) = {34,35,40,45,50,51}; // int surf
Physical Surface(101) = {6,15,19,23,27,28}; // ext surf
