lc = 0.02;

r = 0.1;
d = 2*r;

h = 2*d;
assym = 0.1*d;

depth = 0.5;

l1 = 2*d;
l2 = 20*d;

n = 1;
nl1 = n*8;
nl2 = n*88;
nc = n*8;

nz = 16;
//nz = 1;

Point(1) = {0,0,0,lc};
Point(2) = {0,r,0,lc};
Point(3) = {r,0,0,lc};
Point(4) = {-r,0,0,lc};
Point(5) = {-l1,0,0,lc};
Point(6) = {l2,0,0,lc};
Point(7) = {-l1,h,0,lc};
Point(8) = {l2,h,0,lc};
Point(9) = {2*r,0.0,0,lc};
Point(10) = {-2*r,0.0,0,lc};
Point(11) = {0.0,0.2,0,lc};
Point(12) = {0.0,h,0,lc};
Point(13) = {r*Sin(Pi/4),r*Sin(Pi/4),0,lc};
Point(14) = {-r*Sin(Pi/4),r*Sin(Pi/4),0,lc};
Point(15) = {2*r*Sin(Pi/4),2*r*Sin(Pi/4),0,lc};
Point(16) = {-2*r*Sin(Pi/4),2*r*Sin(Pi/4),0,lc};
Point(17) = {l2,2*r*Sin(Pi/4),0,lc};
Point(18) = {-l1,2*r*Sin(Pi/4),0,lc};
Point(19) = {2*r*Sin(Pi/4),h,0,lc};
Point(20) = {-2*r*Sin(Pi/4),h,0,lc};

Circle(1) = {15,1,11};
Circle(2) = {13,1,2};
Circle(3) = {2,1,14};
Circle(4) = {11,1,16};
Circle(5) = {16,1,10};
Circle(6) = {14,1,4};
Circle(7) = {13,1,3};
Circle(8) = {15,1,9};
Line(9) = {9,3};
Line(10) = {15,13};
Line(11) = {11,2};
Line(12) = {16,14};
Line(13) = {10,4};
Line(14) = {12,11};
Line(15) = {19,15};
Line(16) = {12,19};
Line(17) = {19,8};
Line(18) = {8,17};
Line(19) = {17,15};
Line(20) = {6,9};
Line(21) = {6,17};
Line(22) = {16,20};
Line(23) = {20,12};
Line(24) = {10,5};
Line(25) = {5,18};
Line(26) = {18,16};
Line(27) = {7,18};
Line(28) = {20,7};

Line Loop(29) = {17,18,19,-15};
Plane Surface(30) = {29};
Line Loop(31) = {21,19,8,-20};
Plane Surface(32) = {31};
Line Loop(33) = {10,7,-9,-8};
Plane Surface(34) = {33};
Line Loop(35) = {1,11,-2,-10};
Plane Surface(36) = {35};
Line Loop(37) = {16,15,1,-14};
Plane Surface(38) = {37};
Line Loop(39) = {4,22,23,14};
Plane Surface(40) = {39};
Line Loop(41) = {11,3,-12,-4};
Plane Surface(42) = {41};
Line Loop(43) = {6,-13,-5,12};
Plane Surface(44) = {43};
Line Loop(45) = {26,5,24,25};
Plane Surface(46) = {45};
Line Loop(47) = {28,27,26,22};
Plane Surface(48) = {47};

Symmetry { 0.0,1.0,0.0,0.0 } {
  Duplicata { Surface{32}; }
}

Symmetry { 0.0,1.0,0.0,0.0 } {
  Duplicata { Surface{34}; }
}

Symmetry { 0.0,1.0,0.0,0.0 } {
  Duplicata { Surface{36}; }
}

Symmetry { 0.0,1.0,0.0,0.0 } {
  Duplicata { Surface{42}; }
}

Symmetry { 0.0,1.0,0.0,0.0 } {
  Duplicata { Surface{44}; }
}

Symmetry { 0.0,1.0,0.0,0.0 } {
  Duplicata { Surface{46}; }
}

Symmetry { 0.0,1.0,0.0,0.0 } {
  Duplicata { Surface{48}; }
}

Symmetry { 0.0,1.0,0.0,0.0 } {
  Duplicata { Surface{40}; }
}

Symmetry { 0.0,1.0,0.0,0.0 } {
  Duplicata { Surface{38}; }
}

Symmetry { 0.0,1.0,0.0,0.0 } {
  Duplicata { Surface{30}; }
}

Translate {0.0,assym,0.0} {
  Point{7};
}

Translate {0.0,assym,0.0} {
  Point{20};
}

Translate {0.0,assym,0.0} {
  Point{12};
}

Translate {0.0,assym,0.0} {
  Point{19};
}

Translate {0.0,assym,0.0} {
  Point{8};
}

Transfinite Line {28,26,24,70,75} = nl1+1 Using Progression 1.0;

Transfinite Line {17} = nl2+1 Using Progression 1.0/0.99;
Transfinite Line {19} = nl2+1 Using Progression 0.99;
Transfinite Line {20} = nl2+1 Using Progression 0.99;
Transfinite Line {51} = nl2+1 Using Progression 0.99;
Transfinite Line {88} = nl2+1 Using Progression 1.0/0.99;

Transfinite Line {18,21,8,15,14,22,27,25,5,6,7,4,3,13,12,11,10,2,9,1,16,23} = nc+1 Using Progression 1.0;
Transfinite Line {50,89,52,86,55,54,59,57,85,83,58,62,64,82,63,78,68,73,76,66} = nc+1 Using Progression 1.0;

Transfinite Line {15,14,18,27} = nc+1 Using Progression 1.0;
Transfinite Line {76,78,86,89} = nc+1 Using Progression 1.0;


Transfinite Surface {30} = {17,8,19,15};
Transfinite Surface {32} = {17,15,9,6};
Transfinite Surface {34} = {15,13,3,9};
Transfinite Surface {36} = {13,15,11,2};
Transfinite Surface {38} = {11,15,19,12};
Transfinite Surface {40} = {11,12,20,16};
Transfinite Surface {42} = {2,11,16,14};
Transfinite Surface {44} = {4,14,16,10};
Transfinite Surface {46} = {10,16,18,5};
Transfinite Surface {48} = {18,16,20,7};

Transfinite Surface {49} = {6,22,26,9};
Transfinite Surface {53} = {3,9,26,28};
Transfinite Surface {56} = {28,26,31,35};
Transfinite Surface {60} = {42,35,31,46};
Transfinite Surface {65} = {10,4,42,46};
Transfinite Surface {69} = {5,10,46,47};
Transfinite Surface {74} = {47,46,48,49};
Transfinite Surface {79} = {46,31,60,48};
Transfinite Surface {84} = {31,26,62,60};
Transfinite Surface {87} = {22,64,62,26};


allsurf[] = {30,32,34,36,38,40,42,44,46,48,
	     49,53,56,60,65,69,74,79,84,87};

Recombine Surface{allsurf[]};

Extrude {0,0,depth} {
  Surface{allsurf[]}; Layers{nz}; Recombine;
}

// Walls
Physical Surface(600) = {98,186,216,296,516,494,480,450,146,344,370,388,406,252,234,172};

// Inlet
Physical Surface(601) = {300,286,440,454};

// Outlet
Physical Surface(602) = {102,120,318,520};

//Physical Volume(603) = {9000};


