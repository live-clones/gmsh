
dT1 = 10.e-3 ;
dT2 = 10.e-3 ;
dT3 = 10.e-3 ;

lT1 = 10.e-3 ;
lT2 = 10.e-3 ;
lT3 = 10.e-3 ;

e = 0.65e-2/2. ;


pp = 4.99e-3 ;

p0 = pp ;
pT1 = pp ;  pT2 = pp ;  pT3 = pp ;
pT13 = pp ; pT23 = pp ;


Point(1) = { -dT3/2.,0,0,p0};

Point(2) = { -dT3/2.-lT1,   0, 0, pT1};
Point(3) = { -dT3/2.-lT1, dT1, 0, pT1};

Point(4) = { -dT3/2., dT1    , 0, pT13};

Point(5) = { -dT3/2., dT1+lT3, 0, pT3};
Point(6) = {  dT3/2., dT1+lT3, 0, pT3};

Point(7) = {  dT3/2., dT2    , 0, pT23};

Point(8) = {  dT3/2.+lT2, dT2, 0, pT2};
Point(9) = {  dT3/2.+lT2,   0, 0, pT2};

Point(10) = { dT3/2.,0,0,p0};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};
Line(5) = {1,10};
Line(6) = {10,7};
Line(7) = {7,4};
Line(8) = {4,5};
Line(9) = {5,6};
Line(10) = {6,7};
Line(11) = {7,8};
Line(12) = {8,9};
Line(13) = {9,10};
Line Loop(14) = {1,2,3,4};
Plane Surface(15) = {14};
Line Loop(16) = {11,12,13,6};
Plane Surface(17) = {16};
Line Loop(18) = {8,9,10,7};
Plane Surface(19) = {18};
Line Loop(20) = {5,6,7,4};
Plane Surface(21) = {20};
Translate({0,0,e}) {
  Duplicata { Surface(15); }
}
Coherence;
Translate({0,0,e}) {
  Duplicata { Surface(21); }
}
Coherence;
Translate({0,0,e}) {
  Duplicata { Surface(17); }
}
Coherence;
Translate({0,0,e}) {
  Duplicata { Surface(19); }
}
Coherence;
Line(46) = {2,12};
Line(47) = {3,14};
Line(48) = {1,11};
Line(49) = {4,16};
Line(50) = {5,26};
Line(51) = {6,28};
Line(52) = {7,20};
Line(53) = {10,18};
Line(54) = {9,24};
Line(55) = {8,22};

Line Loop(56) = {23,-47,-2,46};
Plane Surface(57) = {56};
Line Loop(58) = {22,-46,-1,48};
Plane Surface(59) = {58};
Line Loop(60) = {-49,-3,47,24};
Plane Surface(61) = {60};
Line Loop(62) = {-25,-49,4,48};
Plane Surface(63) = {62};
Line Loop(64) = {40,-50,-8,49};
Plane Surface(65) = {64};
Line Loop(66) = {41,-51,-9,50};
Plane Surface(67) = {66};
Line Loop(68) = {-42,-51,10,52};
Plane Surface(69) = {68};
Line Loop(70) = {-30,-52,7,49};
Plane Surface(71) = {70};
Line Loop(72) = {28,-53,-5,48};
Plane Surface(73) = {72};
Line Loop(74) = {29,-52,-6,53};
Plane Surface(75) = {74};
Line Loop(76) = {34,-55,-11,52};
Plane Surface(77) = {76};
Line Loop(78) = {36,-53,-13,54};
Plane Surface(79) = {78};
Line Loop(80) = {-35,-55,12,54};
Plane Surface(81) = {80};
Surface Loop(82) = {63,27,-59,-57,-61,-15};
Complex Volume(83) = {82};
Surface Loop(84) = {75,-39,77,-81,17,79};
Complex Volume(85) = {84};
Surface Loop(86) = {71,45,-65,-67,69,-19};
Complex Volume(87) = {86};
Surface Loop(88) = {71,33,-73,-75,-21,63};
Complex Volume(89) = {88};

nbpts1 = 1.0;

Transfinite Line{46,47,49,48,53,52,50,51,55,54} = nbpts1 Using Power 1.0;

nbpts2 = 10;
Transfinite Line{9,41,7,30,3,24,11,34,13,36,5,28,1,22} = nbpts2 Using Power 1.0;
nbpts3 = 15;
Transfinite Line{2,23,4,25,8,40,10,42,6,29,12,35} = nbpts3 Using Power 1.0;
Transfinite Surface{27} = {12,11,16,14};
Transfinite Surface{33} = {11,18,20,16};
Transfinite Surface{39} = {18,24,22,20};
Transfinite Surface{15} = {2,1,4,3};
Transfinite Surface{21} = {1,10,7,4};
Transfinite Surface{17} = {10,9,8,7};
Transfinite Surface{45} = {16,20,28,26};
Transfinite Surface{19} = {4,7,6,5};
