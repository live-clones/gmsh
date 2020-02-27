///////////////////
/// Maillage 3D ///
///////////////////


//Précision maillage:
N = 0.1;


//Paramètres éprouvette :

//longueur éprouvette
L = 58;
//largeur éprouvette
l = 9;
//épaisseur éprouvette
e = 10;
//Largeur de contact bloc/éprouvette
Lc = 5;

// Paramètres bloc froid :

//largeur du bloc
Bf = 35;
//hauteur totale du bloc
Af = 27.8;
//profondeur des blocs
C = 30;
//largeur de la surface de contact
D = 10;
//diamètre sonde :
ds = 3.3;
//diamètre thermocouple
dt = 1.1;

// Paramètres bloc chaud :

Bc = 35;
Ac = 25;

//diamètre bobine chauffante
dbc = 10.2;


////////////////////////////////////

// Définition de la géométrie :

//points définissant le bloc froid :
Point(1) = {0,0.0,0.0,20*N};
Point(2) = {Bf,0.0,0.0,20*N};
Point(3) = {0,(Af-1.5),0.0,20*N};
Point(4) = {Bf,(Af-1.5),0,20*N};
Point(5) = {(Bf/2)-(D/2),Af,0,5*N};
Point(46) = {(Bf/2)+(D/2),Af,0,5*N};

Point(48) = {0,0.0,-C,20*N};
Point(49) = {Bf,0.0,-C,20*N};
Point(50) = {0,(Af-1.5),-C,20*N};
Point(51) = {Bf,(Af-1.5),-C,20*N};
Point(52) = {(Bf/2)-(D/2),Af,-C,5*N};
Point(53) = {(Bf/2)+(D/2),Af,-C,5*N};

//centre sonde froide :
Point(7) = {Bf/2,11.8,0,10*N};
//points définissant cercle de la sonde :
Point(8) = {Bf/2+(ds/2),11.8,0,10*N};
Point(9) = {Bf/2,11.8+(ds/2),0,10*N};
Point(10) = {Bf/2-(ds/2),11.8,0,10*N};
Point(11) = {Bf/2,11.8-(ds/2),0,10*N};

Point(60) = {Bf/2,11.8,-C,10*N};
Point(61) = {Bf/2+(ds/2),11.8,-C,10*N};
Point(62) = {Bf/2,11.8+(ds/2),-C,10*N};
Point(63) = {Bf/2-(ds/2),11.8,-C,10*N};
Point(64) = {Bf/2,11.8-(ds/2),-C,10*N};

//thermocouple froid :
Point(12) = {Bf/2,Af-2,-12,5*N};
Physical Point(127) = {12};

//points définissant l'éprouvette 
Point(6) = {(Bf/2)+(D/2),Af,(l-C)/2,3*N};
Point(17) = {Bf/2+D/2-Lc,Af,(l-C)/2,3*N};
Point(18) = {Bf/2+D/2-Lc,Af+e,(l-C)/2,10*N};
Point(19) = {Bf/2+D/2-Lc+L,Af+e,(l-C)/2,10*N};
Point(20) = {Bf/2+D/2-Lc+L,Af,(l-C)/2,3*N};
Point(21) = {Bf/2+D/2-2*Lc+L,Af,(l-C)/2,3*N};
Point(42) = {(Bf/2)+(D/2)+5,Af,(l-C)/2,10*N};
Point(43) = {(Bf/2)+(D/2)+5,Af+e,(l-C)/2,10*N};
Point(44) = {Bf/2+D/2-2*Lc+L-5,Af,(l-C)/2,10*N};
Point(45) = {Bf/2+D/2-2*Lc+L-5,Af+e,(l-C)/2,10*N};

Point(75) = {(Bf/2)+(D/2),Af,-(l+C)/2,3*N};
Point(76) = {Bf/2+D/2-Lc,Af,-(l+C)/2,3*N};
Point(77) = {Bf/2+D/2-Lc,Af+e,-(l+C)/2,10*N};
Point(78) = {Bf/2+D/2-Lc+L,Af+e,-(l+C)/2,10*N};
Point(79) = {Bf/2+D/2-Lc+L,Af,-(l+C)/2,3*N};
Point(80) = {Bf/2+D/2-2*Lc+L,Af,-(l+C)/2,3*N};
Point(81) = {(Bf/2)+(D/2)+5,Af,-(l+C)/2,10*N};
Point(82) = {(Bf/2)+(D/2)+5,Af+e,-(l+C)/2,10*N};
Point(83) = {Bf/2+D/2-2*Lc+L-5,Af,-(l+C)/2,10*N};
Point(84) = {Bf/2+D/2-2*Lc+L-5,Af+e,-(l+C)/2,10*N};

//points définissant le bloc chaud :
Point(22) = {(Bf-Bc)/2+L-2*Lc+D,Af-Ac,0,20*N};
Point(23) = {(Bf-Bc)/2+L-2*Lc+D,Af-Ac+(Ac-1.5),0,20*N};
Point(24) = {(Bf+Bc)/2+L-2*Lc+D,Af-Ac+(Ac-1.5),0,20*N};
Point(25) = {(Bf+Bc)/2+L-2*Lc+D,Af-Ac,0,20*N};
Point(26) = {Bf/2+(3/2)*D-2*Lc+L,Af,0,5*N};
Point(47) = {Bf/2+D/2-2*Lc+L,Af,0,5*N};

Point(54) = {(Bf-Bc)/2+L-2*Lc+D,Af-Ac,-C,20*N};
Point(55) = {(Bf-Bc)/2+L-2*Lc+D,Af-Ac+(Ac-1.5),-C,20*N};
Point(56) = {(Bf+Bc)/2+L-2*Lc+D,Af-Ac+(Ac-1.5),-C,20*N};
Point(57) = {(Bf+Bc)/2+L-2*Lc+D,Af-Ac,-C,20*N};
Point(58) = {Bf/2+(3/2)*D-2*Lc+L,Af,-C,5*N};
Point(59) = {Bf/2+D/2-2*Lc+L,Af,-C,5*N};

//centre de la bobine chauffante :
Point(27) = {Bf/2+L-2*Lc+D,Af-Ac+9,0,10*N};
//points définissant la bobine chauffante :
Point(28) = {Bf/2+L-2*Lc+D+dbc/2,Af-Ac+9,0,10*N};
Point(29) = {Bf/2+L-2*Lc+D,Af-Ac+9+dbc/2,0,10*N};
Point(30) = {Bf/2+L-2*Lc+D-dbc/2,Af-Ac+9,0,10*N};
Point(31) = {Bf/2+L-2*Lc+D,Af-Ac+9-dbc/2,0,10*N};

Point(65) = {Bf/2+L-2*Lc+D,Af-Ac+9,-C,10*N};
Point(66) = {Bf/2+L-2*Lc+D+dbc/2,Af-Ac+9,-C,10*N};
Point(67) = {Bf/2+L-2*Lc+D,Af-Ac+9+dbc/2,-C,10*N};
Point(68) = {Bf/2+L-2*Lc+D-dbc/2,Af-Ac+9,-C,10*N};
Point(69) = {Bf/2+L-2*Lc+D,Af-Ac+9-dbc/2,-C,10*N};

//centre de la sonde chaude :
Point(32) = {(Bf-Bc)/2+L-2*Lc+D+8,Af-Ac+9,0,10*N};
//points définissant le cercle de la sonde :
Point(33) = {(Bf-Bc)/2+L-2*Lc+D+8+ds/2,Af-Ac+9,0,10*N};
Point(34) = {(Bf-Bc)/2+L-2*Lc+D+8,Af-Ac+9+ds/2,0,10*N};
Point(35) = {(Bf-Bc)/2+L-2*Lc+D+8-ds/2,Af-Ac+9,0,10*N};
Point(36) = {(Bf-Bc)/2+L-2*Lc+D+8,Af-Ac+9-ds/2,0,10*N};

Point(70) = {(Bf-Bc)/2+L-2*Lc+D+8,Af-Ac+9,-C,10*N};
Point(71) = {(Bf-Bc)/2+L-2*Lc+D+8+ds/2,Af-Ac+9,-C,10*N};
Point(72) = {(Bf-Bc)/2+L-2*Lc+D+8,Af-Ac+9+ds/2,-C,10*N};
Point(73) = {(Bf-Bc)/2+L-2*Lc+D+8-ds/2,Af-Ac+9,-C,10*N};
Point(74) = {(Bf-Bc)/2+L-2*Lc+D+8,Af-Ac+9-ds/2,-C,10*N};

//thermocouple chaud :
Point(37) = {Bf/2+L-2*Lc+D,Af-2,-12,5*N};
Physical Point(128) = {37};

//définition des lignes :
Line(1) = {1,2};
Line(2) = {2,4};
Line(3) = {5,3};
Line(4) = {3,1};
Line(5) = {17,18};
Line(6) = {19,20};
Line(7) = {22,25};
Line(8) = {25,24};
Line(9) = {24,26};
Line(10) = {23,22};
Circle(19) = {9,7,8};
Circle(20) = {8,7,11};
Circle(21) = {11,7,10};
Circle(22) = {10,7,9};
Circle(27) = {34,32,33};
Circle(28) = {33,32,36};
Circle(29) = {36,32,35};
Circle(30) = {35,32,34};
Circle(31) = {29,27,28};
Circle(32) = {28,27,31};
Circle(33) = {31,27,30};
Circle(34) = {30,27,29};
Line(49) = {18,43};
Line(50) = {43,45};
Line(51) = {45,19};
Line(52) = {21,44};
Line(53) = {44,42};
Line(54) = {42,6};
Line(55) = {5,46};
Line(56) = {46,4};
Line(57) = {23,47};
Line(58) = {47,26};
Line(59) = {17,6};
Line(60) = {21,20};
Circle(61) = {62,60,61};
Circle(62) = {61,60,64};
Circle(63) = {64,60,63};
Circle(64) = {63,60,62};
Circle(65) = {72,70,71};
Circle(66) = {71,70,74};
Circle(67) = {74,70,73};
Circle(68) = {73,70,72};
Circle(69) = {69,65,66};
Circle(70) = {66,65,67};
Circle(71) = {67,65,68};
Circle(72) = {68,65,69};
Line(73) = {1,48};
Line(74) = {48,49};
Line(75) = {49,2};
Line(76) = {50,3};
Line(77) = {50,48};
Line(78) = {50,52};
Line(79) = {52,53};
Line(80) = {53,51};
Line(81) = {51,4};
Line(82) = {5,52};
Line(83) = {22,54};
Line(84) = {49,51};
Line(85) = {55,54};
Line(86) = {55,59};
Line(87) = {59,58};
Line(88) = {58,56};
Line(89) = {56,24};
Line(90) = {58,26};
Line(91) = {23,55};
Line(92) = {57,25};
Line(93) = {57,56};
Line(94) = {57,54};
Line(95) = {9,62};
Line(96) = {61,8};
Line(97) = {11,64};
Line(98) = {63,10};
Line(99) = {34,72};
Line(100) = {71,33};
Line(101) = {36,74};
Line(102) = {73,35};
Line(103) = {67,29};
Line(104) = {28,66};
Line(105) = {69,31};
Line(106) = {30,68};
Line(107) = {17,76};
Line(108) = {76,75};
Line(109) = {75,81};
Line(110) = {81,83};
Line(111) = {83,80};
Line(112) = {80,79};
Line(113) = {79,20};
Line(114) = {79,78};
Line(115) = {78,19};
Line(116) = {78,84};
Line(117) = {84,82};
Line(118) = {82,77};
Line(119) = {77,18};
Line(120) = {77,76};
Line(121) = {46,6};
Line(122) = {6,75};
Line(123) = {75,53};
Line(124) = {47,21};
Line(125) = {21,80};
Line(126) = {80,59};

Line Loop(129) = {19,-96,-61,-95};
Ruled Surface(130) = {129};
Line Loop(131) = {20,97,-62,96};
Ruled Surface(132) = {131};
Line Loop(133) = {21,-98,-63,-97};
Ruled Surface(134) = {133};
Line Loop(135) = {64,-95,-22,-98};
Ruled Surface(136) = {135};
Line Loop(137) = {99,65,100,-27};
Ruled Surface(138) = {137};
Line Loop(139) = {100,28,101,-66};
Ruled Surface(140) = {139};
Line Loop(141) = {101,67,102,-29};
Ruled Surface(142) = {141};
Line Loop(143) = {102,30,99,-68};
Ruled Surface(144) = {143};
Line Loop(145) = {31,104,70,103};
Ruled Surface(146) = {145};
Line Loop(147) = {32,-105,69,-104};
Ruled Surface(148) = {147};
Line Loop(149) = {33,106,72,105};
Ruled Surface(150) = {149};
Line Loop(151) = {34,-103,71,-106};
Ruled Surface(152) = {151};
Line Loop(153) = {1,-75,-74,-73};
Plane Surface(154) = {153};
Line Loop(155) = {3,-76,78,-82};
Plane Surface(156) = {155};
Line Loop(157) = {55,121,-59,107,108,123,-79,-82};
Plane Surface(158) = {157};
Line Loop(159) = {56,-81,-80,-123,-122,-121};
Plane Surface(160) = {159};
Line Loop(161) = {4,73,-77,76};
Plane Surface(162) = {161};
Line Loop(163) = {2,-81,-84,75};
Plane Surface(164) = {163};
Line Loop(165) = {77,74,84,-80,-79,-78};
Line Loop(166) = {61,62,63,64};
Plane Surface(167) = {165,166};
Line Loop(168) = {4,1,2,-56,-55,3};
Line Loop(169) = {22,19,20,21};
Plane Surface(170) = {168,169};
Line Loop(171) = {108,-122,-59,107};
Plane Surface(172) = {171};
Line Loop(173) = {7,-92,94,-83};
Plane Surface(174) = {173};
Line Loop(175) = {57,124,125,126,-86,-91};
Plane Surface(176) = {175};
Line Loop(177) = {126,87,90,-58,124,60,-113,-112};
Plane Surface(178) = {177};
Line Loop(179) = {88,89,9,-90};
Plane Surface(180) = {179};
Line Loop(181) = {60,-113,-112,-125};
Plane Surface(182) = {181};
Line Loop(183) = {89,-8,-92,93};
Plane Surface(184) = {183};
Line Loop(185) = {10,83,-85,-91};
Plane Surface(186) = {185};
Line Loop(187) = {85,-94,93,-88,-87,-86};
Line Loop(188) = {65,66,67,68};
Line Loop(189) = {71,72,69,70};
Plane Surface(190) = {187,188,189};
Line Loop(191) = {10,7,8,9,-58,-57};
Line Loop(192) = {27,28,29,30};
Line Loop(193) = {34,31,32,33};
Plane Surface(194) = {191,192,193};
Line Loop(195) = {118,120,108,109,110,111,112,114,116,117};
Plane Surface(196) = {195};
Line Loop(197) = {52,53,54,-59,5,49,50,51,6,-60};
Plane Surface(198) = {197};
Line Loop(199) = {5,-119,120,-107};
Plane Surface(200) = {199};
Line Loop(201) = {114,115,6,-113};
Plane Surface(202) = {201};
Line Loop(203) = {119,49,50,51,-115,116,117,118};
Plane Surface(204) = {203};
Line Loop(205) = {122,109,110,111,-125,52,53,54};
Plane Surface(206) = {205};

//refroid :
Physical Surface(207) = {154};

//Cont_froid :
Physical Surface(208) = {172};

//sonde_froide :
Physical Surface(209) = {130,136,134,132};

//chauff :
Physical Surface(210) = {146,152,150,148};

//Cont_chaud :
Physical Surface(211) = {182};

//sonde_chaud :
Physical Surface(212) = {142,140,144,138};

//Conv :
Physical Surface(213) = {162,164,186,184,156,158,160,200,204,196,198,206,176,178,180,202};

//Flux0 :
Physical Surface(214) = {174,167,170,190,194};

Surface Loop(215) = {162,-170,154,164,-160,167,-158,172,156,136,-130,-132,-134};
Surface Loop(217) = {186,-194,174,-184,180,190,178,-176,-182,-144,142,-140,138,146,148,150,152};
Surface Loop(219) = {196,-204,-200,198,-206,-172,182,-202};
Volume(220) = {219};
Volume(216) = {215};
Volume(218) = {217};

//Bloc_froid :
Physical Volume(221) = {216};

//Bloc_chaud :
Physical Volume(222) = {218};

//Eprouvette :
Physical Volume(223) = {220};