
dT1 = 10.e-3 ;
dT2 = 10.e-3 ;
dT3 = 10.e-3 ;

lT1 = 10.e-3 ;
lT2 = 10.e-3 ;
lT3 = 10.e-3 ;

e = 0.65e-3/2. ;


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

/* selon e */

Transfinite Line {-46,-48,-53,-54,-47,-49,-52,-55,-50,-51}
  = 8 Using Power 1.2 ;

/* vers les angles */

Transfinite Line {-3,-24,1,22, 11,34,-13,-36,  8,40,-10,-42}
  = 11 Using Power 1.4 ;

/* selon y pour f1 et f2 */

Transfinite Line {-2,-23,4,25,-6,-29,12,35}
  = 11 Using Bump -1.4 ;

/* selon x pour f3 */

Transfinite Line {9,41,7,30,5,28}
  = 11 Using Bump -1.4 ;


Transfinite Surface {15} = {1,2,3,4} ;
Transfinite Surface {27} = {11,12,14,16} ;

Transfinite Surface {17} = {9,10,7,8} ;
Transfinite Surface {39} = {24,18,20,22} ;

Transfinite Surface {19} = {7,4,5,6} ;
Transfinite Surface {45} = {20,16,26,28} ;

Transfinite Surface {21} = {10,1,4,7} ;
Transfinite Surface {33} = {18,11,16,20} ;

Transfinite Surface {57} = {2,12,14,3} ;
Transfinite Surface {63} = {1,11,16,4} ;
Transfinite Surface {75} = {10,18,20,7} ;
Transfinite Surface {81} = {9,24,22,8} ;
Transfinite Surface {65} = {4,16,26,5} ;
Transfinite Surface {69} = {7,20,28,6} ;

Transfinite Surface {59} = {12,11,1,2} ;
Transfinite Surface {61} = {14,16,4,3} ;

Transfinite Surface {73} = {11,18,10,1} ;
Transfinite Surface {71} = {16,20,7,4} ;
Transfinite Surface {67} = {26,28,6,5} ;

Transfinite Surface {79} = {18,24,9,10} ;
Transfinite Surface {77} = {20,22,8,7} ;


Recombine Surface {15,27,17,39,19,45,21,33,57,63,75,81,59,61,73,71,67,79,77,65,69} ;


Transfinite Volume {83} = {1,2,12,11,4,3,14,16} ;
Transfinite Volume {85} = {9,10,18,24,8,7,20,22} ;
Transfinite Volume {87} = {7,4,16,20,6,5,26,28} ;
Transfinite Volume {89} = {10,1,11,18,7,4,16,20} ;


Physical Volume(101) = {83,85,87,89} ;  /* Tooth */

Physical Line(2001) = { 2,47,23,46} ; /* LineFlux1 */
Physical Line(2002) = {55,12,54,35} ; /* LineFlux2 */
Physical Line(2003) = { 9,51,41,50} ; /* LineFlux3 */

Physical Surface(1001) = {57} ;  /* Flux1 */
Physical Surface(1002) = {81} ;  /* Flux2 */
Physical Surface(1003) = {67} ;  /* Flux3 */

Physical Surface(1100) = {27,33,39, 59,73,79, 61,65,45,69,77} ;  /* SkinTooth */
