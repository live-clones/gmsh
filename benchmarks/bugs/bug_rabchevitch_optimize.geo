// Gmsh project created on Thu Nov 01 10:31:41 2007

//indenter which has a little blunt radius

Z1 = 0.15; //Z of the sphere tip


D = 1.7; //contact radius

beta = 90 / 2 * Pi / 180; //half the angle of the cone

d = D * Cos(beta); //diameter of the touch of cone and contact sphere 

//alpha is the distance from sphere tip to some point on the sphere
//alpha = 0.5 * (D - (D ^ 2 - d ^ 2) ^ 0.5), where d is a diameter at alpha

alpha = 0.5 * (D - (D ^ 2 - d ^ 2) ^ 0.5);

D2 =  4; //pivot diameter

L1 = 0.5 * (D2 - d) / Tan(beta); //length of the cone

L2 = 20; //pivot length

Di = 0.85 * D; //inner sphere diameter for better meshing


//characteristic lengths
l0 = 0.2 * (D - Di);  //sphere tip
l1 = 2.0 * l0; //outer sphere
l2 = 0.5 * Di; //inner sphere can be coarse
l3 = 0.5 * D2;




//points

//outer sphere
Point(100) = {0, 0, Z1+0.5*D, l0}; //virtual point - sphere center - for setting sphere surfaces
Point(101) = {0, 0, Z1, l0}; //sphere tip
r = 0.5 * d;
l = l1;
h = alpha;
Point(102) = {0,0,Z1+h,l};
Point(103) = {r,0,Z1+h,l};
tmp104[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/4} { Duplicata{ Point{103}; } } ;
tmp105[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/2} { Duplicata{ Point{103}; } } ;




//cone
h = alpha + L1;
a = 0.5 * D2;
a1 = 0.5 * a;
l = 0.5 * a;
Point(122) = {0,0,Z1+h,l};
Point(123) = {a,0,Z1+h,l};
tmp124[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/4} { Duplicata{ Point{123}; } } ;
tmp125[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/2} { Duplicata{ Point{123}; } } ;



//thick cylinder
H = alpha + L1;
h = L2 * 0.2;
l = 0.5 * D2;
a1 = 0.5 * 0.5 * D2;
Point(142) = {0,0,H+h,l};
Point(143) = {0.5 * D2,0,H+h,l};
tmp144[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/4} { Duplicata{ Point{143}; } } ;
tmp145[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/2} { Duplicata{ Point{143}; } } ;




Point(152) = {0,0,H+2*h,l};
Point(153) = {0.5 * D2,0,H+2*h,l};
tmp154[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/4} { Duplicata{ Point{153}; } } ;
tmp155[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/2} { Duplicata{ Point{153}; } } ;




Point(162) = {0,0,H+3*h,l};
Point(163) = {0.5 * D2,0,H+3*h,l};
tmp164[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/4} { Duplicata{ Point{163}; } } ;
tmp165[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/2} { Duplicata{ Point{163}; } } ;




Point(172) = {0,0,H+4*h,l};
Point(173) = {0.5 * D2,0,H+4*h,l};
tmp174[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/4} { Duplicata{ Point{173}; } } ;
tmp175[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/2} { Duplicata{ Point{173}; } } ;




Point(182) = {0,0,H+5*h,l};
Point(183) = {0.5 * D2,0,H+5*h,l};
tmp184[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/4} { Duplicata{ Point{183}; } } ;
tmp185[] = Rotate {{0, 0, 1}, {0,0,0}, Pi/2} { Duplicata{ Point{183}; } } ;




Circle(1) = {103,102,104};
Circle(2) = {104,102,105};
Circle(3) = {103,100,101};
Circle(4) = {104,100,101};
Circle(5) = {105,100,101};
Circle(6) = {123,122,124};
Circle(7) = {124,122,125};
Circle(8) = {143,142,144};
Circle(9) = {144,142,145};
Circle(10) = {153,152,154};
Circle(11) = {154,152,155};
Circle(12) = {163,162,164};
Circle(13) = {164,162,165};
Circle(14) = {173,172,174};
Circle(15) = {174,172,175};
Circle(16) = {183,182,184};
Circle(17) = {184,182,185};
Line(18) = {103,102};
Line(19) = {104,102};
Line(20) = {105,102};
Line(21) = {123,122};
Line(22) = {124,122};
Line(23) = {125,122};
Line(24) = {143,142};
Line(25) = {144,142};
Line(26) = {145,142};
Line(27) = {153,152};
Line(28) = {154,152};
Line(29) = {155,152};
Line(30) = {163,162};
Line(31) = {164,162};
Line(32) = {165,162};
Line(33) = {173,172};
Line(34) = {174,172};
Line(35) = {175,172};
Line(36) = {183,182};
Line(37) = {184,182};
Line(38) = {185,182};
Line(39) = {101,102};
Line(40) = {102,100};
Line(41) = {100,122};
Line(42) = {122,142};
Line(43) = {142,152};
Line(44) = {152,162};
Line(45) = {162,172};
Line(46) = {172,182};
Line(47) = {103,123};
Line(48) = {123,143};
Line(49) = {143,153};
Line(50) = {153,163};
Line(51) = {163,173};
Line(52) = {173,183};
Line(53) = {104,124};
Line(54) = {124,144};
Line(55) = {144,154};
Line(56) = {154,164};
Line(57) = {164,174};
Line(58) = {174,184};
Line(59) = {125,145};
Line(60) = {145,155};
Line(61) = {155,165};
Line(62) = {165,175};
Line(63) = {175,185};
Line(64) = {105,125};
Line Loop(65) = {5,-4,2};
Ruled Surface(66) = {65};
Line Loop(67) = {4,-3,1};
Ruled Surface(68) = {67};
Line Loop(69) = {64,-7,-53,2};
Ruled Surface(70) = {69};
Line Loop(71) = {53,-6,-47,1};
Ruled Surface(72) = {71};
Line Loop(73) = {48,8,-54,-6};
Ruled Surface(74) = {73};
Line Loop(75) = {54,9,-59,-7};
Ruled Surface(76) = {75};
Line Loop(77) = {8,55,-10,-49};
Ruled Surface(78) = {77};
Line Loop(79) = {55,11,-60,-9};
Ruled Surface(80) = {79};
Line Loop(81) = {10,56,-12,-50};
Ruled Surface(82) = {81};
Line Loop(83) = {56,13,-61,-11};
Ruled Surface(84) = {83};
Line Loop(85) = {51,14,-57,-12};
Ruled Surface(86) = {85};
Line Loop(87) = {57,15,-62,-13};
Ruled Surface(88) = {87};
Line Loop(89) = {52,16,-58,-14};
Ruled Surface(90) = {89};
Line Loop(91) = {58,17,-63,-15};
Ruled Surface(92) = {91};
Line Loop(93) = {3,39,-18};
Plane Surface(94) = {93};
Line Loop(95) = {4,39,-19};
Plane Surface(96) = {95};
Line Loop(97) = {5,39,-20};
Plane Surface(98) = {97};
Line Loop(99) = {18,40,41,-21,-47};
Plane Surface(100) = {99};
Line Loop(101) = {19,40,41,-22,-53};
Plane Surface(102) = {101};
Line Loop(103) = {20,40,41,-23,-64};
Plane Surface(104) = {103};
Line Loop(105) = {21,42,-24,-48};
Plane Surface(106) = {105};
Line Loop(107) = {22,42,-25,-54};
Plane Surface(108) = {107};
Line Loop(109) = {23,42,-26,-59};
Plane Surface(110) = {109};
Line Loop(111) = {24,43,-27,-49};
Plane Surface(112) = {111};
Line Loop(113) = {25,43,-28,-55};
Plane Surface(114) = {113};
Line Loop(115) = {26,43,-29,-60};
Plane Surface(116) = {115};
Line Loop(117) = {27,44,-30,-50};
Plane Surface(118) = {117};
Line Loop(119) = {28,44,-31,-56};
Plane Surface(120) = {119};
Line Loop(121) = {29,44,-32,-61};
Plane Surface(122) = {121};
Line Loop(123) = {30,45,-33,-51};
Plane Surface(124) = {123};
Line Loop(125) = {31,45,-34,-57};
Plane Surface(126) = {125};
Line Loop(127) = {32,45,-35,-62};
Plane Surface(128) = {127};
Line Loop(129) = {33,46,-36,-52};
Plane Surface(130) = {129};
Line Loop(131) = {34,46,-37,-58};
Plane Surface(132) = {131};
Line Loop(133) = {35,46,-38,-63};
Plane Surface(134) = {133};
Line Loop(135) = {18,-19,-1};
Plane Surface(136) = {135};
Line Loop(137) = {19,-20,-2};
Plane Surface(138) = {137};
Line Loop(139) = {21,-22,-6};
Plane Surface(140) = {139};
Line Loop(141) = {22,-23,-7};
Plane Surface(142) = {141};
Line Loop(143) = {24,-25,-8};
Plane Surface(144) = {143};
Line Loop(145) = {25,-26,-9};
Plane Surface(146) = {145};
Line Loop(147) = {27,-28,-10};
Plane Surface(148) = {147};
Line Loop(149) = {28,-29,-11};
Plane Surface(150) = {149};
Line Loop(151) = {30,-31,-12};
Plane Surface(152) = {151};
Line Loop(153) = {31,-32,-13};
Plane Surface(154) = {153};
Line Loop(155) = {33,-34,-14};
Plane Surface(156) = {155};
Line Loop(157) = {34,-35,-15};
Plane Surface(158) = {157};
Line Loop(159) = {36,-37,-16};
Plane Surface(160) = {159};
Line Loop(161) = {37,-38,-17};
Plane Surface(162) = {161};
Surface Loop(163) = {94,68,96,136};
Volume(164) = {163};
Surface Loop(165) = {98,66,138,96};
Volume(166) = {165};
Surface Loop(167) = {136,140,72,100,102};
Volume(168) = {167};
Surface Loop(169) = {142,138,104,70,102};
Volume(170) = {169};
Surface Loop(171) = {74,106,108,144,140};
Volume(172) = {171};
Surface Loop(173) = {76,110,146,142,108};
Volume(174) = {173};
Surface Loop(175) = {78,112,148,144,114};
Volume(176) = {175};
Surface Loop(177) = {150,80,116,146,114};
Volume(178) = {177};
Surface Loop(179) = {82,118,152,148,120};
Volume(180) = {179};
Surface Loop(181) = {84,122,154,150,120};
Volume(182) = {181};
Surface Loop(183) = {86,124,156,152,126};
Volume(184) = {183};
Surface Loop(185) = {88,128,158,154,126};
Volume(186) = {185};
Surface Loop(187) = {90,130,160,156,132};
Volume(188) = {187};
Surface Loop(189) = {92,162,134,158,132};
Volume(190) = {189};
Physical Volume(191) = {164,166,168,170,172,174,176,178,180,182,184,186,188,190};
