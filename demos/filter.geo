// Original author: Benoit Meys

ech = 0.001 ;
a = 8.0 ;
b = 20.45 ;
c = 45.55 ;
d = 58.0 ;
e = 66.0 ;
f = 23.0 ;
g = 20.0 ;
h = 2.8 ;
i = 8.0 ;
k = 5.0 ;
in = 1.0 ;
did = 4.0 ;
ded = 11.7 ;
dame = 1.25 ;
dtef = 4.0 ;

sizereson = 1.5 ;
sizeresoni = 1. ;
sizebig = 4.0 ;
sizeame = 1.0 ;
sizetef = 1.0 ;

a = a* ech ;
b = b* ech ;
c = c* ech ;
d = d* ech ;
e = e* ech ;
f = f* ech ;
g = g* ech ;
h = h* ech ;
i = i* ech ;
k = k* ech ;
j = f/2 ;
in = in * ech ;
did = did* ech ;
ded = ded* ech ;
dame = dame* ech ;
dtef = dtef* ech ;

rid = did/2.0 ;
red = ded/2.0 ;
rame=dame/2 ;
rtef=dtef/2 ;


sizereson = sizereson * ech ;
sizeresoni = sizeresoni * ech ;
sizebig = sizebig * ech ;
sizeame = sizeame * ech ;
sizetef = sizetef * ech ;

/* box */

Point(1) = {0,0,0,sizebig} ;
Point(2) = {e,0,0,sizebig} ;
Point(3) = {e,f,0,sizebig} ;
Point(4) = {0,f,0,sizebig} ;
Point(5) = {0,0,i,sizebig} ;
Point(6) = {e,0,i,sizebig} ;
Point(7) = {e,f,i,sizebig} ;
Point(8) = {0,f,i,sizebig} ;
Point(81) = {e/2,0,0,sizebig};

/* left reson */

Point(9) = {b,j,0,sizeresoni} ;
Point(10) = {b+rid,j,0,sizeresoni} ;
Point(11) = {b,j+rid,0,sizeresoni} ;
Point(12) = {b-rid,j,0,sizeresoni} ;
Point(13) = {b,j-rid,0,sizeresoni} ;
Point(14) = {b+red,j,0,sizereson} ;
Point(15) = {b,j+red,0,sizereson} ;
Point(16) = {b-red,j,0,sizereson} ;
Point(17) = {b,j-red,0,sizereson} ;

Point(18) = {b,j,h,sizeresoni} ;
Point(19) = {b+rid,j,h,sizeresoni} ;
Point(20) = {b,j+rid,h,sizeresoni} ;
Point(21) = {b-rid,j,h,sizeresoni} ;
Point(22) = {b,j-rid,h,sizeresoni} ;
Point(23) = {b+red,j,h,sizereson} ;
Point(24) = {b,j+red,h,sizereson} ;
Point(25) = {b-red,j,h,sizereson} ;
Point(26) = {b,j-red,h,sizereson} ;

/* right reson */

Point(27) = {c,j,0,sizeresoni} ;
Point(28) = {c+rid,j,0,sizeresoni} ;
Point(29) = {c,j+rid,0,sizeresoni} ;
Point(30) = {c-rid,j,0,sizeresoni} ;
Point(31) = {c,j-rid,0,sizeresoni} ;
Point(32) = {c+red,j,0,sizereson} ;
Point(33) = {c,j+red,0,sizereson} ;
Point(34) = {c-red,j,0,sizereson} ;
Point(35) = {c,j-red,0,sizereson} ;

Point(36) = {c,j,h,sizeresoni} ;
Point(37) = {c+rid,j,h,sizeresoni} ;
Point(38) = {c,j+rid,h,sizeresoni} ;
Point(39) = {c-rid,j,h,sizeresoni} ;
Point(40) = {c,j-rid,h,sizeresoni} ;
Point(41) = {c+red,j,h,sizereson} ;
Point(42) = {c,j+red,h,sizereson} ;
Point(43) = {c-red,j,h,sizereson} ;
Point(44) = {c,j-red,h,sizereson} ;

/* left cab */

Point(45) = {a,0,0,sizeame} ;
Point(46) = {a,0,rame,sizeame} ;
Point(47) = {a-rame,0,0,sizeame} ;
Point(48) = {a+rame,0,0,sizeame} ;

Point(49) = {a,-k,0,sizeame} ;
Point(50) = {a,-k,rame,sizeame} ;
Point(51) = {a-rame,-k,0,sizeame} ;
Point(52) = {a+rame,-k,0,sizeame} ;

Point(53) = {a,g,0,sizeame} ;
Point(54) = {a,g,rame,sizeame} ;
Point(55) = {a-rame,g,0,sizeame} ;
Point(56) = {a+rame,g,0,sizeame} ;

/* right cab */

Point(57) = {d,0,0,sizeame} ;
Point(58) = {d,0,rame,sizeame} ;
Point(59) = {d-rame,0,0,sizeame} ;
Point(60) = {d+rame,0,0,sizeame} ;

Point(61) = {d,-k,0,sizeame} ;
Point(62) = {d,-k,rame,sizeame} ;
Point(63) = {d-rame,-k,0,sizeame} ;
Point(64) = {d+rame,-k,0,sizeame} ;

Point(65) = {d,g,0,sizeame} ;
Point(66) = {d,g,rame,sizeame} ;
Point(67) = {d-rame,g,0,sizeame} ;
Point(68) = {d+rame,g,0,sizeame} ;

/* left teflon */

Point(69) = {a,0,rtef,sizetef} ;
Point(70) = {a-rtef,0,0,sizetef} ;
Point(71) = {a+rtef,0,0,sizetef} ;

Point(72) = {a,-k,rtef,sizetef} ;
Point(73) = {a-rtef,-k,0,sizetef} ;
Point(74) = {a+rtef,-k,0,sizetef} ;


/* right teflon */

Point(75) = {d,0,rtef,sizetef} ;
Point(76) = {d-rtef,0,0,sizetef} ;
Point(77) = {d+rtef,0,0,sizetef} ;

Point(78) = {d,-k,rtef,sizetef} ;
Point(79) = {d-rtef,-k,0,sizetef} ;
Point(80) = {d+rtef,-k,0,sizetef} ;

/* in */


Point(82) = {d,-k-in,rtef,sizetef} ;
Point(83) = {d-rtef,-k-in,0,sizetef} ;
Point(84) = {d+rtef,-k-in,0,sizetef} ;


Point(85) = {d,-k-in,0,sizeame} ;
Point(86) = {d,-k-in,rame,sizeame} ;
Point(87) = {d-rame,-k-in,0,sizeame} ;
Point(88) = {d+rame,-k-in,0,sizeame} ;


/* eps teflon = 2.03
   eps res = 38 */

Circle(1) = {20,18,21};
Circle(2) = {21,18,22};
Circle(3) = {22,18,19};
Circle(4) = {19,18,20};
Circle(5) = {11,9,12};
Circle(6) = {12,9,13};
Circle(7) = {13,9,10};
Circle(8) = {10,9,11};
Circle(9) = {24,18,25};
Circle(10) = {25,18,26};
Circle(11) = {26,18,23};
Circle(12) = {23,18,24};
Circle(13) = {15,9,16};
Circle(14) = {16,9,17};
Circle(15) = {17,9,14};
Circle(16) = {14,9,15};
Circle(17) = {38,36,39};
Circle(18) = {39,36,40};
Circle(19) = {40,36,37};
Circle(20) = {37,36,38};
Circle(21) = {42,36,43};
Circle(22) = {43,36,44};
Circle(23) = {44,36,41};
Circle(24) = {41,36,42};
Circle(25) = {29,27,30};
Circle(26) = {30,27,31};
Circle(27) = {31,27,28};
Circle(28) = {28,27,29};
Circle(29) = {33,27,34};
Circle(30) = {34,27,35};
Circle(31) = {35,27,32};
Circle(32) = {32,27,33};
Line(33) = {8,7};
Line(34) = {7,3};
Line(35) = {8,4};
Line(36) = {5,1};
Line(37) = {6,2};
Line(38) = {6,7};
Line(39) = {5,8};
Line(40) = {2,3};
Line(41) = {1,4};
Line(42) = {3,4};
Line(43) = {6,5};
Circle(44) = {66,65,67};
Circle(45) = {68,65,66};
Circle(46) = {54,53,55};
Circle(47) = {56,53,54};
Circle(48) = {50,49,51};
Circle(49) = {52,49,50};
Circle(50) = {72,49,73};
Circle(51) = {74,49,72};
Circle(52) = {48,45,46};
Circle(53) = {46,45,47};
Circle(54) = {69,45,70};
Circle(55) = {71,45,69};
Circle(56) = {62,61,63};
Circle(57) = {64,61,62};
Circle(58) = {80,61,78};
Circle(59) = {78,61,79};
Circle(60) = {60,57,58};
Circle(61) = {58,57,59};
Circle(62) = {77,57,75};
Circle(63) = {75,57,76};
Line(64) = {2,77};
Line(65) = {77,60};
Line(66) = {60,57};
Line(67) = {57,59};
Line(68) = {59,76};
Line(70) = {71,48};
Line(71) = {48,45};
Line(72) = {45,47};
Line(73) = {47,70};
Line(74) = {70,1};
Line(75) = {70,73};
Line(76) = {47,51};
Line(77) = {48,52};
Line(78) = {71,74};
Line(79) = {74,52};
Line(80) = {52,49};
Line(81) = {49,51};
Line(82) = {51,73};
Line(83) = {76,79};
Line(84) = {59,63};
Line(85) = {60,64};
Line(86) = {77,80};
Line(87) = {79,63};
Line(88) = {63,61};
Line(89) = {61,64};
Line(90) = {64,80};
Line(91) = {59,67};
Line(92) = {60,68};
Line(93) = {67,65};
Line(94) = {65,68};
Line(95) = {48,56};
Line(96) = {47,55};
Line(97) = {55,53};
Line(98) = {53,56};
Line Loop(99) = {11,12,9,10};
Line Loop(100) = {4,1,2,3};
Plane Surface(101) = {99,100};
Line Loop(102) = {15,16,13,14};
Line Loop(103) = {7,8,5,6};
Plane Surface(104) = {102,103};
Plane Surface(105) = {103};
Plane Surface(106) = {100};
Line Loop(107) = {31,32,29,30};
Line Loop(108) = {27,28,25,26};
Plane Surface(109) = {107,108};
Line Loop(110) = {23,24,21,22};
Line Loop(111) = {19,20,17,18};
Plane Surface(112) = {110,111};
Plane Surface(113) = {111};
Plane Surface(114) = {108};
Line(115) = {16,25};
Line(116) = {15,24};
Line(117) = {14,23};
Line(118) = {17,26};
Line(119) = {12,21};
Line(120) = {11,20};
Line(121) = {19,10};
Line(122) = {22,13};
Line(123) = {44,35};
Line(124) = {41,32};
Line(125) = {43,34};
Line(126) = {42,33};
Line(127) = {40,31};
Line(128) = {37,28};
Line(129) = {38,29};
Line(130) = {39,30};

Line Loop(131) = {31,-124,-23,123};
Ruled Surface(132) = {131};
Line Loop(133) = {30,-123,-22,125};
Ruled Surface(134) = {133};
Line Loop(135) = {29,-125,-21,126};
Ruled Surface(136) = {135};
Line Loop(137) = {32,-126,-24,124};
Ruled Surface(138) = {137};
Line Loop(139) = {11,-117,-15,118};
Ruled Surface(140) = {139};
Line Loop(141) = {10,-118,-14,115};
Ruled Surface(142) = {141};
Line Loop(143) = {9,-115,-13,116};
Ruled Surface(144) = {143};
Line Loop(145) = {-116,-16,117,12};
Ruled Surface(146) = {145};
Line Loop(147) = {-1,-120,5,119};
Ruled Surface(148) = {147};
Line Loop(149) = {-6,119,2,122};
Ruled Surface(150) = {149};
Line Loop(151) = {-7,-122,3,121};
Ruled Surface(152) = {151};
Line Loop(153) = {120,-4,121,8};
Ruled Surface(154) = {153};
Line Loop(155) = {27,-128,-19,127};
Ruled Surface(156) = {155};
Line Loop(157) = {-127,-18,130,26};
Ruled Surface(158) = {157};
Line Loop(159) = {130,-25,-129,17};
Ruled Surface(160) = {159};
Line Loop(161) = {28,-129,-20,128};
Ruled Surface(162) = {161};
Line(167) = {78,75};
Line(168) = {62,58};
Line(169) = {75,66};
Line(170) = {58,66};
Line Loop(171) = {-167,-58,-86,62};
Ruled Surface(172) = {171};
Line Loop(173) = {63,83,-59,167};
Ruled Surface(174) = {173};
Line Loop(175) = {84,-56,168,61};
Ruled Surface(176) = {175};
Line Loop(177) = {-168,-57,-85,60};
Ruled Surface(178) = {177};
Line Loop(179) = {-91,-61,170,44};
Ruled Surface(180) = {179};
Line Loop(181) = {170,-45,-92,60};
Ruled Surface(182) = {181};
Line Loop(183) = {-87,-59,-58,-90,57,56};
Plane Surface(184) = {183};
Line Loop(185) = {68,-63,-62,65,60,61};
Plane Surface(186) = {185};
Line Loop(187) = {93,94,45,44};
Plane Surface(188) = {187};
Line Loop(189) = {-87,-83,-68,84};
Plane Surface(190) = {189};
Line Loop(191) = {-90,-85,-65,86};
Plane Surface(192) = {191};
Line(195) = {72,69};
Line(196) = {50,46};
Line(197) = {46,54};
Line Loop(198) = {96,-46,-197,53};
Ruled Surface(199) = {198};
Line Loop(200) = {197,-47,-95,52};
Ruled Surface(201) = {200};
Line Loop(202) = {75,-50,195,54};
Ruled Surface(203) = {202};
Line Loop(204) = {-195,-51,-78,55};
Ruled Surface(205) = {204};
Line Loop(206) = {49,196,-52,77};
Ruled Surface(207) = {206};
Line Loop(208) = {76,-48,196,53};
Ruled Surface(209) = {208};
Line Loop(210) = {48,82,-50,-51,79,49};
Plane Surface(211) = {210};
Line Loop(212) = {73,-54,-55,70,52,53};
Plane Surface(213) = {212};
Line Loop(214) = {-79,-78,70,77};
Plane Surface(215) = {214};
Line Loop(216) = {82,-75,-73,76};
Plane Surface(217) = {216};
Line Loop(218) = {97,98,47,46};
Plane Surface(219) = {218};
Line Loop(226) = {39,33,-38,43};
Plane Surface(227) = {226};
Line Loop(228) = {-35,33,34,42};
Plane Surface(229) = {228};
Line Loop(230) = {41,-35,-39,36};
Plane Surface(231) = {230};
Line Loop(232) = {-34,-38,37,40};
Plane Surface(233) = {232};
Line(234) = {76,81};
Line(235) = {81,71};
Line Loop(236) = {234,235,55,54,74,-36,-43,37,64,62,63};
Plane Surface(237) = {236};
Line Loop(238) = {92,-94,-93,-91,68,234,235,70,95,-98,-97,-96,73,74,41,-42,-40,64,65};
Plane Surface(239) = {238,107,102};



Surface Loop(601) = {152,104,140,-101,146,144,142,-154,-148,150};
Complex Volume(602) = {601};
Surface Loop(603) = {160,-158,-156,109,-132,-138,-136,-134,-112,-162};
Complex Volume(604) = {603};
Surface Loop(605) = {213,217,-211,-209,207,-215,205,203};
Complex Volume(606) = {605};
Surface Loop(607) = {186,190,-184,174,172,192,-178,-176};
Complex Volume(608) = {607};


Surface Loop(6001) = {213,-239,-182,180,186,237,231,-229,227,-233,-188,
  -201,-199,-219,132,138,136,134,112,156,-114,162,-160,158,-140,101,
  -146,-144,-142,154,148,-105,-152,-150};
Complex Volume(6002) = {6001};

Delete { Line{169} ; }

Line(6003) = {83,87};
Line(6004) = {87,85};
Line(6005) = {85,88};
Line(6006) = {88,84};
Circle(6007) = {84,85,82};
Circle(6008) = {82,85,83};
Circle(6009) = {88,85,86};
Circle(6010) = {86,85,87};
Line(6011) = {83,79};
Line(6012) = {87,63};
Line(6013) = {88,64};
Line(6014) = {84,80};
Line(6015) = {82,78};
Line(6016) = {86,62};
Line Loop(6017) = {90,-6014,-6006,6013};
Plane Surface(6018) = {6017};
Line Loop(6019) = {87,-6012,-6003,6011};
Plane Surface(6020) = {6019};
Line Loop(6021) = {6010,-6003,-6008,-6007,-6006,6009};
Plane Surface(6022) = {6021};
Line Loop(6023) = {-58,-6014,6007,6015};
Ruled Surface(6024) = {6023};
Line Loop(6025) = {6011,-59,-6015,6008};
Ruled Surface(6026) = {6025};
//Line Loop(6027) = {-57,-6013,6009,6016};
//Ruled Surface(6028) = {6027};
Line Loop(6029) = {-56,-6016,6010,6012};
Ruled Surface(6030) = {6029};
Surface Loop(6031) = {184,6020,6030,6028,6018,-6024,-6022,-6026};
//Complex Volume(6032) = {6031};


AIR = 10000 ;
R1 = 20000 ;
R2 = 30000 ;
TT1 = 40000 ;
TT2 = 50000 ;
CLD0 = 60000 ;
SOU  = 70000 ;
CLTEM  = 80000 ;

Physical Volume  (AIR)     = 6002;

Physical Volume  (TT1)      = 606;
Physical Volume  (TT2)      = 608;
Physical Volume  (R1)      = 602;
Physical Volume  (R2)      = 604;
//Physical Volume  (SOU)     = 6032;

Physical Surface (CLD0) = {231,229,223,237,227,
                           199,201,219,209,207,203,205,
                           180,182,188,176,178,174,172,
                           6026,6024,6028,6030};
Physical Surface (CLTEM) = {211,6022};
