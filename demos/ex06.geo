/* 
   Gmsh demo file (C) 2000 C. Geuzaine, J.-F. Remacle

   2D and 3D transfinite meshes

   All important comments are marked with "README"
*/

r_int  = 0.05 ;
r_ext  = 0.051 ;
r_far  = 0.125 ;
r_inf  = 0.4 ;
phi1   = 30. * (Pi/180.) ;
angl   = 45. * (Pi/180.) ;


nbpt_phi   = 5 ; nbpt_int   = 20 ;
nbpt_arc1  = 10 ; nbpt_arc2  = 10 ;
nbpt_shell = 10 ; nbpt_far   = 25 ; nbpt_inf = 15 ;

lc0 = 0.1 ; lc1 = 0.1 ; lc2 = 0.3 ;

Point(1) = {0,     0, 0, lc0} ;
Point(2) = {r_int, 0, 0, lc0} ;
Point(3) = {r_ext, 0, 0, lc1} ;
Point(4) = {r_far, 0, 0, lc2} ;
Point(5) = {r_inf, 0, 0, lc2} ;
Point(6) = {0, 0,  r_int, lc0} ;
Point(7) = {0, 0,  r_ext, lc1} ;
Point(8) = {0, 0,  r_far, lc2} ;
Point(9) = {0, 0,  r_inf, lc2} ;

Point(10) = {r_int*Cos(phi1), r_int*Sin(phi1), 0, lc0} ;
Point(11) = {r_ext*Cos(phi1), r_ext*Sin(phi1), 0, lc1} ;
Point(12) = {r_far*Cos(phi1), r_far*Sin(phi1), 0, lc2} ;
Point(13) = {r_inf*Cos(phi1), r_inf*Sin(phi1), 0, lc2} ;

Point(14) = {r_int/2,           0,   0,               lc2} ;
Point(15) = {r_int/2*Cos(phi1), r_int/2*Sin(phi1), 0, lc2} ;
Point(16) = {r_int/2,           0,                 r_int/2, lc2} ;
Point(17) = {r_int/2*Cos(phi1), r_int/2*Sin(phi1), r_int/2, lc2} ;
Point(18) = {0, 0,  r_int/2, lc2} ;
Point(19) = {r_int*Cos(angl),           0,                          r_int*Sin(angl), lc2} ;
Point(20) = {r_int*Cos(angl)*Cos(phi1), r_int*Cos(angl)*Sin(phi1),  r_int*Sin(angl), lc2} ;
Point(21) = {r_ext*Cos(angl),           0,                          r_ext*Sin(angl), lc2} ;
Point(22) = {r_ext*Cos(angl)*Cos(phi1), r_ext*Cos(angl)*Sin(phi1),  r_ext*Sin(angl), lc2} ;
Point(23) = {r_far*Cos(angl),           0,                          r_far*Sin(angl), lc2} ;
Point(24) = {r_far*Cos(angl)*Cos(phi1), r_far*Cos(angl)*Sin(phi1),  r_far*Sin(angl), lc2} ;
Point(25) = {r_inf,           0,                r_inf, lc2} ;
Point(26) = {r_inf*Cos(phi1), r_inf*Sin(phi1),  r_inf, lc2} ;

Circle(1) = {2,1,19};   Circle(2) = {19,1,6};   Circle(3) = {3,1,21};   Circle(4) = {21,1,7};
Circle(5) = {4,1,23};   Circle(6) = {23,1,8};   Line(7) = {5,25};   Line(8) = {25,9};
Circle(9) = {10,1,20};  Circle(10) = {20,1,6};  Circle(11) = {11,1,22}; Circle(12) = {22,1,7};
Circle(13) = {12,1,24}; Circle(14) = {24,1,8};  Line(15) = {13,26}; Line(16) = {26,9};
Circle(17) = {19,1,20}; Circle(18) = {21,1,22}; Circle(19) = {23,1,24}; Circle(20) = {25,1,26};
Circle(21) = {2,1,10};  Circle(22) = {3,1,11};  Circle(23) = {4,1,12};  Circle(24) = {5,1,13};

Line(25) = {1,14};  Line(26) = {14,2};  Line(27) = {2,3};   Line(28) = {3,4};
Line(29) = {4,5};   Line(30) = {1,15};  Line(31) = {15,10}; Line(32) = {10,11};
Line(33) = {11,12}; Line(34) = {12,13}; Line(35) = {14,15}; Line(36) = {14,16};
Line(37) = {15,17}; Line(38) = {16,17}; Line(39) = {18,16}; Line(40) = {18,17};
Line(41) = {1,18};  Line(42) = {18,6};  Line(43) = {6,7};   Line(44) = {16,19};
Line(45) = {19,21}; Line(46) = {21,23}; Line(47) = {23,25}; Line(48) = {17,20};
Line(49) = {20,22}; Line(50) = {22,24}; Line(51) = {24,26}; Line(52) = {7,8};
Line(53) = {8,9};

Line Loop(54) = {39,-36,-25,41}; Ruled Surface(55) = {54};
Line Loop(56) = {44,-1,-26,36};  Ruled Surface(57) = {56};
Line Loop(58) = {3,-45,-1,27};   Ruled Surface(59) = {58};
Line Loop(60) = {5,-46,-3,28};   Ruled Surface(61) = {60};
Line Loop(62) = {7,-47,-5,29};   Ruled Surface(63) = {62};
Line Loop(64) = {-2,-44,-39,42}; Ruled Surface(65) = {64};
Line Loop(66) = {-4,-45,2,43};   Ruled Surface(67) = {66};
Line Loop(68) = {-6,-46,4,52};   Ruled Surface(69) = {68};
Line Loop(70) = {-8,-47,6,53};   Ruled Surface(71) = {70};
Line Loop(72) = {-40,-41,30,37}; Ruled Surface(73) = {72};
Line Loop(74) = {48,-9,-31,37};  Ruled Surface(75) = {74};
Line Loop(76) = {49,-11,-32,9};  Ruled Surface(77) = {76};
Line Loop(78) = {-50,-11,33,13}; Ruled Surface(79) = {78};
Line Loop(80) = {-51,-13,34,15}; Ruled Surface(81) = {80};
Line Loop(82) = {10,-42,40,48};  Ruled Surface(83) = {82};
Line Loop(84) = {12,-43,-10,49}; Ruled Surface(85) = {84};
Line Loop(86) = {14,-52,-12,50}; Ruled Surface(87) = {86};
Line Loop(88) = {16,-53,-14,51}; Ruled Surface(89) = {88};
Line Loop(90) = {-30,25,35};     Ruled Surface(91) = {90};
Line Loop(92) = {-40,39,38};     Ruled Surface(93) = {92};
Line Loop(94) = {37,-38,-36,35}; Ruled Surface(95) = {94};
Line Loop(96) = {-48,-38,44,17}; Ruled Surface(97) = {96};
Line Loop(98) = {18,-49,-17,45}; Ruled Surface(99) = {98};
Line Loop(100) = {19,-50,-18,46};Ruled Surface(101) = {100};
Line Loop(102) = {20,-51,-19,47};Ruled Surface(103) = {102};
Line Loop(104) = {-2,17,10};     Ruled Surface(105) = {104};
Line Loop(106) = {-9,-21,1,17};  Ruled Surface(107) = {106};
Line Loop(108) = {-4,18,12};     Ruled Surface(109) = {108};
Line Loop(110) = {-11,-22,3,18}; Ruled Surface(111) = {110};
Line Loop(112) = {-13,-23,5,19}; Ruled Surface(113) = {112};
Line Loop(114) = {-6,19,14};     Ruled Surface(115) = {114};
Line Loop(116) = {-15,-24,7,20}; Ruled Surface(117) = {116};
Line Loop(118) = {-8,20,16};     Ruled Surface(119) = {118};
Line Loop(120) = {-31,-35,26,21};Ruled Surface(121) = {120};
Line Loop(122) = {32,-22,-27,21};Ruled Surface(123) = {122};
Line Loop(124) = {33,-23,-28,22};Ruled Surface(125) = {124};
Line Loop(126) = {34,-24,-29,23};Ruled Surface(127) = {126};

Surface Loop(128) = {93,-73,-55,95,-91};        Complex Volume(129) = {128}; /* int */
Surface Loop(130) = {107,-75,-97,95,57,121};    Complex Volume(131) = {130}; /* int b */
Surface Loop(132) = {105,-65,-97,-83,-93};      Complex Volume(133) = {132}; /* int h */
Surface Loop(134) = {99,-111,77,123,59,107};    Complex Volume(135) = {134}; /* shell b */
Surface Loop(136) = {99,-109,67,105,85};        Complex Volume(137) = {136}; /* shell h */
Surface Loop(138) = {113,79,-101,-111,-125,-61};Complex Volume(139) = {138}; /* ext b */
Surface Loop(140) = {115,-69,-101,-87,-109};    Complex Volume(141) = {140}; /* ext h */
Surface Loop(142) = {103,-117,-81,113,127,63};  Complex Volume(143) = {142}; /* inf b */
Surface Loop(144) = {89,-119,71,103,115};       Complex Volume(145) = {144}; /* inf h */

/* README: Tranfinite line commands explicitly specify the number of
   points and their repartition. A minus sign in the argument list of
   the transfinite command will produce the reversed mesh. */

Transfinite Line{35,21,22,23,24,38,17,18,19,20}   = nbpt_phi Using Power 1.0;
Transfinite Line{31,26,48,44,42}                  = nbpt_int Using Progression 0.95;
Transfinite Line{41,37,36,9,11,1,3,13,5,15,7}     = nbpt_arc1 Using Power 1.0;
Transfinite Line{30,25,40,39,10,2,12,4,14,6,16,8} = nbpt_arc2 Using Power 1.0;
Transfinite Line{32,27,49,45,43}                  = nbpt_shell Using Power 1.0;
Transfinite Line{33,28,46,50,52}                  = nbpt_far Using Progression 1.05 ;
Transfinite Line{34,29,51,47,53}                  = nbpt_inf Using Progression 1.2;

/* README: *All* 2D and 3D transfinite entities are defined in respect
   to points. The ordering of the points defines the ordering of the
   mesh elements. */

Transfinite Surface{55} = {1,14,16,18};
Transfinite Surface{57} = {14,2,19,16};
Transfinite Surface{59} = {2,3,21,19};
Transfinite Surface{61} = {3,4,23,21};
Transfinite Surface{63} = {4,5,25,23};
Transfinite Surface{73} = {1,15,17,18};
Transfinite Surface{75} = {15,10,20,17};
Transfinite Surface{77} = {10,11,22,20};
Transfinite Surface{79} = {11,12,24,22};
Transfinite Surface{81} = {12,13,26,24};
Transfinite Surface{65} = {18,16,19,6};
Transfinite Surface{67} = {6,19,21,7};
Transfinite Surface{69} = {7,21,23,8};
Transfinite Surface{71} = {8,23,25,9};
Transfinite Surface{83} = {17,18,6,20};
Transfinite Surface{85} = {20,6,7,22};
Transfinite Surface{87} = {22,7,8,24};
Transfinite Surface{89} = {24,8,9,26};
Transfinite Surface{91} = {1,14,15};
Transfinite Surface{95} = {15,14,16,17};
Transfinite Surface{93} = {18,16,17};
Transfinite Surface{121} = {15,14,2,10};
Transfinite Surface{97} = {17,16,19,20};
Transfinite Surface{123} = {10,2,3,11};
Transfinite Surface{99} = {20,19,21,22};
Transfinite Surface{107} = {10,2,19,20};
Transfinite Surface{105} = {6,20,19};
Transfinite Surface{109} = {7,22,21};
Transfinite Surface{111} = {11,3,21,22};
Transfinite Surface{101} = {22,21,23,24};
Transfinite Surface{125} = {11,3,4,12};
Transfinite Surface{115} = {8,24,23};
Transfinite Surface{113} = {24,12,4,23};
Transfinite Surface{127} = {12,13,5,4};
Transfinite Surface{103} = {24,23,25,26};
Transfinite Surface{119} = {9,26,25};
Transfinite Surface{117} = {13,5,25,26};

/* README: Recombine simplexes into quadrangles when possible */

Recombine Surface {55 ... 127};

/* README: *All* 2D and 3D transfinite entities are defined in respect
   to points. The ordering of the points defines the ordering of the
   mesh elements. */

Transfinite Volume{129} = {1,14,15,18,16,17};
Transfinite Volume{131} = {17,16,14,15,20,19,2,10};
Transfinite Volume{133} = {18,17,16,6,20,19};
Transfinite Volume{135} = {10,2,19,20,11,3,21,22};
Transfinite Volume{137} = {6,20,19,7,22,21};
Transfinite Volume{139} = {11,3,4,12,22,21,23,24};
Transfinite Volume{141} = {7,22,21,8,24,23};
Transfinite Volume{143} = {12,4,5,13,24,23,25,26};
Transfinite Volume{145} = {8,24,23,9,26,25};

VolInt           = 1000 ;
SurfIntPhi0      = 1001 ;
SurfIntPhi1      = 1002 ;
SurfIntZ0        = 1003 ;

VolShell         = 2000 ;
SurfShellInt     = 2001 ;
SurfShellExt     = 2002 ;
SurfShellPhi0    = 2003 ;
SurfShellPhi1    = 2004 ;
SurfShellZ0      = 2005 ;
LineShellIntPhi0 = 2006 ;
LineShellIntPhi1 = 2007 ;
LineShellIntZ0   = 2008 ;
PointShellInt    = 2009 ;

VolExt           = 3000 ;
VolInf           = 3001 ;
SurfInf          = 3002 ;
SurfExtInfPhi0   = 3003 ;
SurfExtInfPhi1   = 3004 ;
SurfExtInfZ0     = 3005 ;
SurfInfRight     = 3006 ;
SurfInfTop       = 3007 ;

Physical Volume  (VolInt)           = {129,131,133} ;
Physical Surface (SurfIntPhi0)      = {55,57,65} ;
Physical Surface (SurfIntPhi1)      = {73,75,83} ;
Physical Surface (SurfIntZ0)        = {91,121} ;

Physical Volume  (VolShell)         = {135,137} ;
Physical Surface (SurfShellInt)     = {105,107} ;
Physical Surface (SurfShellExt)     = {109,111} ;
Physical Surface (SurfShellPhi0)    = {59,67} ;
Physical Surface (SurfShellPhi1)    = {77,85} ;
Physical Surface (SurfShellZ0)      = {123} ;
Physical Line    (LineShellIntPhi0) = {1,2} ;
Physical Line    (LineShellIntPhi1) = {9,10} ;
Physical Line    (LineShellIntZ0)   = 21 ;
Physical Point   (PointShellInt)    = 6 ;

Physical Volume  (VolExt)           = {139,141} ;
Physical Volume  (VolInf)           = {143,145} ;
Physical Surface (SurfExtInfPhi0)   = {61,63,69,71} ;
Physical Surface (SurfExtInfPhi1)   = {79,87,81,89} ;
Physical Surface (SurfExtInfZ0)     = {125,127} ;
Physical Surface (SurfInfRight)     = {117} ;
Physical Surface (SurfInfTop)       = {119} ;
