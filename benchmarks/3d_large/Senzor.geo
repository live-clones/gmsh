/* geosni.geo - aj s dotykom lana na vzduchovy obal
geometria magnetoelastickeho snimaca pre riesenie Diplomovej Prace */

/* Definovanie konstant */

mm = 1.e-3;
chd1 = 0.05;
chd2 = 0.02;
rl = 35*mm; /* polomer lana */
lpol = 600*mm; /* polovicna dlzka lana */
l = 1200*mm; /* dlzka lana */
lvn = 270*mm; /* dlzka vnutra (krytu) */
lvo = 300*mm; /* dlzka vonkajska (krytu) */
lcvh1 = 120*mm; /* z-tova suradnica hornej plochy prvej cievky od stredu */
lcvd1 = 70*mm; /* z-tova suradnica dolnej plochy prvej cievky od stredu */
lcvh2 = 60*mm; /* analogicky ako lcvh a lcvd */
lcvd2 = 10*mm; 
rovo = 150*mm; /* polomer vonkajska krytu */
rovn = 135*mm; /* polomer vnutra krytu */
rcip = 62*mm; /* polomer cipu */
rcvn = 90*mm; /* polomer vnutornej strany cievky */
rcvo = 105*mm; /* polomer vonkajsej strany cievky */
ohrz = -1200*mm; /* zaporna hodnota suradnice ohranicenia */
ohrk = 1200*mm; /* kladna hodnota suradnice ohranicenia */
angle = 3.14159;
vvzd = 1200*mm; /* vyska vzduchoveho obalu */
pvvzd = 600*mm; /* polovica vysky vzduchoveho obalu */
rvzd = 450*mm; /* polomer vzduchoveho obalu */
posx = 0*mm; /* posunutie lana v smere osi x-ovej */
posy = 0*mm; /* posunutie lana v smere osi y-ovej */

/* Definicia bodov, kruznic, ploch a objemov */


/* Obal vzduchu a kovovy kryt sondy,lano,cievky - zakladna geometria */


// Horna plocha vzduchoveho obalu

Point(1) = { 0, 0, pvvzd, chd1 }; 
Point(2) = { 0, rvzd, pvvzd, chd2 };
Point(3) = { -rvzd, 0, pvvzd, chd2 };
Point(4) = { 0, -rvzd, pvvzd, chd2 };
Point(5) = { rvzd, 0, pvvzd, chd2 };

Circle(1) = { 2, 1, 3 };
Circle(2) = { 3, 1, 4 };
Circle(3) = { 4, 1, 5 };
Circle(4) = { 5, 1, 2 };

// Horna plocha lana pri okraj vzduchu

Point(143) = { 0+posx, 0+posy, lpol, chd1};
Point(6) = { 0+posx, rl+posy, lpol, chd2 };
Point(7) = { -rl+posx, 0+posy, lpol, chd2 };
Point(8) = { 0+posx,-rl+posy, lpol, chd2 };
Point(9) = { rl+posx, 0+posy, lpol, chd2 };

Circle(5) = { 6, 143, 7 };
Circle(6) = { 7, 143, 8 };
Circle(7) = { 8, 143, 9 };
Circle(8) = { 9, 143, 6 };


// Horna plocha krytu vonkajska

Point(10) = { 0, 0, lvo/2, chd1 };
Point(11) = { 0, rovo, lvo/2, chd2 };
Point(12) = { -rovo, 0, lvo/2, chd2 };
Point(13) = { 0, -rovo, lvo/2, chd2 };
Point(14) = { rovo, 0, lvo/2, chd2 };

Circle(9) = { 11, 10, 12 };
Circle(10) = { 12, 10, 13 };
Circle(11) = { 13, 10, 14 };
Circle(12) = { 14, 10, 11 };

// Horna plocha otvoru na kryte

Point(15) = { 0, rcip, lvo/2, chd2 };
Point(16) = { -rcip, 0, lvo/2, chd2 };
Point(17) = { 0, -rcip, lvo/2, chd2 };
Point(18) = { rcip, 0, lvo/2, chd2 };

Circle(13) = { 15, 10, 16 };
Circle(14) = { 16, 10, 17 };
Circle(15) = { 17, 10, 18 };
Circle(16) = { 18, 10, 15 };

// Plocha (diera) lana na urovni vonkajsku podstavy horneho krytu a otvoru na kryte

Point(146) = { 0+posx, 0+posy, lvo/2, chd1 };
Point(19) = { 0+posx, rl+posy, lvo/2, chd2 };
Point(20) = { -rl+posx, 0+posy, lvo/2, chd2 };
Point(21) = { 0+posx, -rl+posy, lvo/2, chd2 };
Point(22) = { rl+posx, 0+posy, lvo/2, chd2 };

Circle(17) = { 19, 146, 20 };
Circle(18) = { 20, 146, 21 };
Circle(19) = { 21, 146, 22 };
Circle(20) = { 22, 146, 19 };

// Horna plocha tela krytu

Point(23) = { 0, 0, lvn/2, chd1 };
Point(24) = { 0, rovo, lvn/2, chd2 };
Point(25) = { -rovo, 0, lvn/2, chd2 };
Point(26) = { 0, -rovo, lvn/2, chd2 };
Point(27) = { rovo, 0, lvn/2, chd2 };

Circle(21) = { 24, 23, 25 };
Circle(22) = { 25, 23, 26 };
Circle(23) = { 26, 23, 27 };
Circle(24) = { 27, 23, 24 };

Point(28) = { 0, rovn, lvn/2, chd2 };
Point(29) = { -rovn, 0, lvn/2, chd2 };
Point(30) = { 0, -rovn, lvn/2, chd2 };
Point(31) = { rovn, 0, lvn/2, chd2 };

Circle(25) = { 28, 23, 29 };
Circle(26) = { 29, 23, 30 };
Circle(27) = { 30, 23, 31 };
Circle(28) = { 31, 23, 28 }; 

// Plocha otvoru krytu zvnutra hornej podstavy

Point(32) = { 0, rcip, lvn/2, chd2 };
Point(33) = { -rcip, 0, lvn/2, chd2 };
Point(34) = { 0, -rcip, lvn/2, chd2 };
Point(35) = { rcip, 0, lvn/2, chd2 };

Circle(29) = { 32, 23, 33 };
Circle(30) = { 33, 23, 34 };
Circle(31) = { 34, 23, 35 };
Circle(32) = { 35, 23, 32 };

// Cievka 1

Point(36) = { 0, 0, lcvh1, chd1 };
Point(37) = { 0, rcvo, lcvh1, chd2 };
Point(38) = { -rcvo, 0, lcvh1, chd2 };
Point(39) = { 0, -rcvo, lcvh1, chd2 };
Point(40) = { rcvo, 0, lcvh1, chd2 };

Circle(33) = { 37, 36, 38 };
Circle(34) = { 38, 36, 39 };
Circle(35) = { 39, 36, 40 };
Circle(36) = { 40, 36, 37 };

Point(41) = { 0, rcvn, lcvh1, chd2 };
Point(42) = { -rcvn, 0, lcvh1, chd2 };
Point(43) = { 0, -rcvn, lcvh1, chd2 };
Point(44) = { rcvn, 0, lcvh1, chd2 };

Circle(37) = { 41, 36, 42 };
Circle(38) = { 42, 36, 43 };
Circle(39) = { 43, 36, 44 };
Circle(40) = { 44, 36, 41 };

Point(45) = { 0, 0, lcvd1, chd1 };
Point(46) = { 0, rcvo, lcvd1, chd2 };
Point(47) = { -rcvo, 0, lcvd1, chd2 };
Point(48) = { 0, -rcvo, lcvd1, chd2 };
Point(49) = { rcvo, 0, lcvd1, chd2 };

Circle(41) = { 46, 45, 47 };
Circle(42) = { 47, 45, 48 };
Circle(43) = { 48, 45, 49 };
Circle(44) = { 49, 45, 46 };

Point(50) = { 0, rcvn, lcvd1, chd2 };
Point(51) = { -rcvn, 0, lcvd1, chd2 };
Point(52) = { 0, -rcvn, lcvd1, chd2 };
Point(53) = { rcvn, 0, lcvd1, chd2 };

Circle(45) = { 50, 45, 51 };
Circle(46) = { 51, 45, 52 };
Circle(47) = { 52, 45, 53 };
Circle(48) = { 53, 45, 50 };

// Cievka 2

Point(54) = { 0, 0, lcvh2, chd1 };
Point(55) = { 0, rcvo, lcvh2, chd2 };
Point(56) = { -rcvo, 0, lcvh2, chd2 };
Point(57) = { 0, -rcvo, lcvh2, chd2 };
Point(58) = { rcvo, 0, lcvh2, chd2 };

Circle(49) = { 55, 54, 56 };
Circle(50) = { 56, 54, 57 };
Circle(51) = { 57, 54, 58 };
Circle(52) = { 58, 54, 55 };

Point(59) = { 0, rcvn, lcvh2, chd2 };
Point(60) = { -rcvn, 0, lcvh2, chd2 };
Point(61) = { 0, -rcvn, lcvh2, chd2 };
Point(62) = { rcvn, 0, lcvh2, chd2 };

Circle(53) = { 59, 54, 60 };
Circle(54) = { 60, 54, 61 };
Circle(55) = { 61, 54, 62 };
Circle(56) = { 62, 54, 59 };

Point(63) = { 0, 0, lcvd2, chd1 };
Point(64) = { 0, rcvo, lcvd2, chd2 };
Point(65) = { -rcvo, 0, lcvd2, chd2 };
Point(66) = { 0, -rcvo, lcvd2, chd2 };
Point(67) = { rcvo, 0, lcvd2, chd2 };

Circle(57) = { 64, 63, 65 };
Circle(58) = { 65, 63, 66 };
Circle(59) = { 66, 63, 67 };
Circle(60) = { 67, 63, 64 };

Point(68) = { 0, rcvn, lcvd2, chd2 };
Point(69) = { -rcvn, 0, lcvd2, chd2 };
Point(70) = { 0, -rcvn, lcvd2, chd2 };
Point(71) = { rcvn, 0, lcvd2, chd2 };

Circle(61) = { 68, 63, 69 };
Circle(62) = { 69, 63, 70 };
Circle(63) = { 70, 63, 71 };
Circle(64) = { 71, 63, 68 };

// Cievka 3

Point(72) = { 0, 0, -lcvd2, chd1 };
Point(73) = { 0, rcvo, -lcvd2, chd2 };
Point(74) = { -rcvo, 0, -lcvd2, chd2 };
Point(75) = { 0, -rcvo, -lcvd2, chd2 };
Point(76) = { rcvo, 0, -lcvd2, chd2 };

Circle(65) = { 73, 72, 74 };
Circle(66) = { 74, 72, 75 };
Circle(67) = { 75, 72, 76 };
Circle(68) = { 76, 72, 73 };

Point(77) = { 0, rcvn, -lcvd2, chd2 };
Point(78) = { -rcvn, 0, -lcvd2, chd2 };
Point(79) = { 0, -rcvn, -lcvd2, chd2 };
Point(80) = { rcvn, 0, -lcvd2, chd2 };

Circle(69) = { 77, 72, 78 };
Circle(70) = { 78, 72, 79 };
Circle(71) = { 79, 72, 80 };
Circle(72) = { 80, 72, 77 };

Point(81) = { 0, 0, -lcvh2, chd1 };
Point(82) = { 0, rcvo, -lcvh2, chd2 };
Point(83) = { -rcvo, 0, -lcvh2, chd2 };
Point(84) = { 0, -rcvo, -lcvh2, chd2 };
Point(85) = { rcvo, 0, -lcvh2, chd2 };

Circle(73) = { 82, 81, 83 };
Circle(74) = { 83, 81, 84 };
Circle(75) = { 84, 81, 85 };
Circle(76) = { 85, 81, 82 };

Point(86) = { 0, rcvn, -lcvh2, chd2 };
Point(87) = { -rcvn, 0, -lcvh2, chd2 };
Point(88) = { 0, -rcvn, -lcvh2, chd2 };
Point(89) = { rcvn, 0, -lcvh2, chd2 };

Circle(77) = { 86, 81, 87 };
Circle(78) = { 87, 81, 88 };
Circle(79) = { 88, 81, 89 };
Circle(80) = { 89, 81, 86 };

// Cievka 4

Point(90) = { 0, 0, -lcvd1, chd1 };
Point(91) = { 0, rcvo, -lcvd1, chd2 };
Point(92) = { -rcvo, 0, -lcvd1, chd2 };
Point(93) = { 0, -rcvo, -lcvd1, chd2 };
Point(94) = { rcvo, 0, -lcvd1, chd2 };

Circle(81) = { 91, 90, 92 };
Circle(82) = { 92, 90, 93 };
Circle(83) = { 93, 90, 94 };
Circle(84) = { 94, 90, 91 };

Point(95) = { 0, rcvn, -lcvd1, chd2 };
Point(96) = { -rcvn, 0, -lcvd1, chd2 };
Point(97) = { 0, -rcvn, -lcvd1, chd2 };
Point(98) = { rcvn, 0, -lcvd1, chd2 };

Circle(85) = { 95, 90, 96 };
Circle(86) = { 96, 90, 97 };
Circle(87) = { 97, 90, 98 };
Circle(88) = { 98, 90, 95 };

Point(99) = { 0, 0, -lcvh1, chd1 };
Point(100) = { 0, rcvo, -lcvh1, chd2 };
Point(101) = { -rcvo, 0, -lcvh1, chd2 };
Point(102) = { 0, -rcvo, -lcvh1, chd2 };
Point(103) = { rcvo, 0, -lcvh1, chd2 };

Circle(89) = { 100, 99, 101 };
Circle(90) = { 101, 99, 102 };
Circle(91) = { 102, 99, 103 };
Circle(92) = { 103, 99, 100 };

Point(104) = { 0, rcvn, -lcvh1, chd2 };
Point(105) = { -rcvn, 0, -lcvh1, chd2 };
Point(106) = { 0, -rcvn, -lcvh1, chd2 };
Point(107) = { rcvn, 0, -lcvh1, chd2 };

Circle(93) = { 104, 99, 105 };
Circle(94) = { 105, 99, 106 };
Circle(95) = { 106, 99, 107 };
Circle(96) = { 107, 99, 104 };

// Plocha otvoru krytu zvnutra dolnej podstavy

Point(108) = { 0, 0, -lvn/2, chd1 };
Point(109) = { 0, rcip, -lvn/2, chd2 };
Point(110) = { -rcip, 0, -lvn/2, chd2 };
Point(111) = { 0, -rcip, -lvn/2, chd2 };
Point(112) = { rcip, 0, -lvn/2, chd2 };

Circle(97) = { 109, 108, 110 };
Circle(98) = { 110, 108, 111 };
Circle(99) = { 111, 108, 112 };
Circle(100) = { 112, 108, 109 };

// Dolna plocha tela krytu

Point(113) = { 0, rovo, -lvn/2, chd2 };
Point(114) = { -rovo, 0, -lvn/2, chd2 };
Point(115) = { 0, -rovo, -lvn/2, chd2 };
Point(116) = { rovo, 0, -lvn/2, chd2 };

Circle(101) = { 113, 108, 114 };
Circle(102) = { 114, 108, 115 };
Circle(103) = { 115, 108, 116 };
Circle(104) = { 116, 108, 113 };

Point(117) = { 0, rovn, -lvn/2, chd2 };
Point(118) = { -rovn, 0, -lvn/2, chd2 };
Point(119) = { 0, -rovn, -lvn/2, chd2 };
Point(120) = { rovn, 0, -lvn/2, chd2 };

Circle(105) = { 117, 108, 118 };
Circle(106) = { 118, 108, 119 };
Circle(107) = { 119, 108, 120 };
Circle(108) = { 120, 108, 117 }; 

// Plocha (diera) lana na urovni vonkajska dolnej podstavy krytu a otvoru na kryte

Point(145) = { 0+posx, 0+posy, -lvo/2, chd1 };
Point(122) = { 0+posx, rl+posy, -lvo/2, chd2 };
Point(123) = { -rl+posx, 0+posy, -lvo/2, chd2 };
Point(124) = { 0+posx, -rl+posy, -lvo/2, chd2 };
Point(125) = { rl+posx, 0+posy, -lvo/2, chd2 };

Circle(109) = { 122, 145, 123 };
Circle(110) = { 123, 145, 124 };
Circle(111) = { 124, 145, 125 };
Circle(112) = { 125, 145, 122 };

// Dolna plocha otvoru na kryte

Point(121) = { 0, 0, -lvo/2, chd1 };
Point(126) = { 0, rcip, -lvo/2, chd2 };
Point(127) = { -rcip, 0, -lvo/2, chd2 };
Point(128) = { 0, -rcip, -lvo/2, chd2 };
Point(129) = { rcip, 0, -lvo/2, chd2 };

Circle(113) = { 126, 121, 127 };
Circle(114) = { 127, 121, 128 };
Circle(115) = { 128, 121, 129 };
Circle(116) = { 129, 121, 126 };

// Dolna plocha krytu vonkajska

Point(130) = { 0, rovo, -lvo/2, chd2 };
Point(131) = { -rovo, 0, -lvo/2, chd2 };
Point(132) = { 0, -rovo, -lvo/2, chd2 };
Point(133) = { rovo, 0, -lvo/2, chd2 };

Circle(117) = { 130, 121, 131 };
Circle(118) = { 131, 121, 132 };
Circle(119) = { 132, 121, 133 };
Circle(120) = { 133, 121, 130 };

// Dolna plocha lana pri okraji vzduchu

Point(144) = { 0+posx, 0+posy, -lpol, chd1 };
Point(135) = { 0+posx, rl+posy, -lpol, chd2 };
Point(136) = { -rl+posx, 0+posy, -lpol, chd2 };
Point(137) = { 0+posx,-rl+posy, -lpol, chd2 };
Point(138) = { rl+posx, 0+posy, -lpol, chd2 };

Circle(121) = { 135, 144, 136 };
Circle(122) = { 136, 144, 137 };
Circle(123) = { 137, 144, 138 };
Circle(124) = { 138, 144, 135 };

// Dolna plocha vzduchoveho obalu

Point(134) = { 0, 0, -pvvzd, chd1 };
Point(139) = { 0, rvzd, -pvvzd, chd2 };
Point(140) = { -rvzd, 0, -pvvzd, chd2 };
Point(141) = { 0, -rvzd, -pvvzd, chd2 };
Point(142) = { rvzd, 0, -pvvzd, chd2 };

Circle(125) = { 139, 134, 140 };
Circle(126) = { 140, 134, 141 };
Circle(127) = { 141, 134, 142 };
Circle(128) = { 142, 134, 139 };

// Ciary tvoriace zakladnu geometriu snimaca - t.j. vzd.obal,kryt,cievky a lano

// Obal vzduchu prepojenie hornej a spodnej plochy (vytvorenie valca)

Line(129) = { 2, 139 };
Line(130) = { 3, 140 };
Line(131) = { 4, 141 };
Line(132) = { 5, 142 };

// Vytvorenie krytu 

// vrchna podstava

Line(133) = { 11, 24 };
Line(134) = { 12, 25 };
Line(135) = { 13, 26 };
Line(136) = { 14, 27 };

Line(137) = { 15, 32 };
Line(138) = { 16, 33 };
Line(139) = { 17, 34 };
Line(140) = { 18, 35 };

// spodna podstava

Line(141) = { 113, 130 };
Line(142) = { 114, 131 };
Line(143) = { 115, 132 };
Line(144) = { 116, 133 };

Line(145) = { 109, 126 };
Line(146) = { 110, 127 };
Line(147) = { 111, 128 };
Line(148) = { 112, 129 };

// prepojenie spodku s vrchom - vytvorenie tela krytu

Line(149) = { 24, 113 };
Line(150) = { 25, 114 };
Line(151) = { 26, 115 };
Line(152) = { 27, 116 };

Line(153) = { 117, 28 };
Line(154) = { 118, 29 };
Line(155) = { 119, 30 };
Line(156) = { 120, 31 };

// cievka1 - vytvorenie valca

// vnutro

Line(157) = { 41, 50 };
Line(158) = { 42, 51 };
Line(159) = { 43, 52 };
Line(160) = { 44, 53 };

// vonkajsok

Line(161) = { 38, 47 };
Line(162) = { 39, 48 };
Line(163) = { 40, 49 };
Line(164) = { 37, 46 };

// cievka2 - vytvorenie valca

// vnutro

Line(165) = { 59, 68 };
Line(166) = { 60, 69 };
Line(167) = { 61, 70 };
Line(168) = { 62, 71 };

// vonkajsok

Line(169) = { 55, 64 };
Line(170) = { 56, 65 };
Line(171) = { 57, 66 };
Line(172) = { 58, 67 };

// cievka3 - vytvorenie valca

// vnutro

Line(173) = { 77, 86 };
Line(174) = { 78, 87 };
Line(175) = { 79, 88 };
Line(176) = { 80, 89 };

// vonkajsok

Line(177) = { 73, 82 };
Line(178) = { 74, 83 };
Line(179) = { 75, 84 };
Line(180) = { 76, 85 };

// cievka4 - vytvorenie valca

// vnutro

Line(181) = { 95, 104 };
Line(182) = { 96, 105 };
Line(183) = { 97, 106 };
Line(184) = { 98, 107 };

// vonkajsok

Line(185) = { 91, 100 };
Line(186) = { 92, 101 };
Line(187) = { 93, 102 };
Line(188) = { 94, 103 };

// lano - vytvorenie valca 

Line(189) = { 6, 19 };
Line(190) = { 19, 122 };
Line(191) = { 122, 135 };

Line(192) = { 7, 20 };
Line(193) = { 20, 123 };
Line(194) = { 123, 136 };

Line(195) = { 8, 21 };
Line(196) = { 21, 124 };
Line(197) = { 124, 137 };

Line(198) = { 9, 22 };
Line(199) = { 22, 125 };
Line(200) = { 125, 138 };


/* Vytvorenie orientovanych ploch v celom snimaci a prostredi (definovanie dier) */


// Vzduchovy obal ( + lano mimo sondy )

// Horna podstava ( + horna podstava lana mimo sondy )

Line Loop(1) = { 5, 6, 7, 8 };		Plane Surface(2) = {1};
Line Loop(3) = { 1, 2, 3, 4 };		Plane Surface(4) = {3,1};

// obal Vzduchov. valca

Line Loop(5) = { -1, 129, 125, -130 };	Ruled Surface(6) = {5};
Line Loop(7) = { -2, 130, 126, -131 };	Ruled Surface(8) = {7};
Line Loop(9) = { -3, 131, 127, -132 };	Ruled Surface(10) = {9};
Line Loop(11) = { -4, 132, 128, -129 };	Ruled Surface(12) = {11};

// Dolna podstava ( + dolna podstava lana mimo sondy )

Line Loop(13) = { -124, -123, -122, -121 };		Plane Surface(14) = {13};
Line Loop(15) = { -128, -127, -126, -125 };		Plane Surface(16) = {15,13};

// Lano mimo sondy (hore)

Line Loop(17) = { -5, 189, 17, -192 };	Ruled Surface(18) = {17};
Line Loop(19) = { -6, 192, 18, -195 };	Ruled Surface(20) = {19};
Line Loop(21) = { -7, 195, 19, -198 };	Ruled Surface(22) = {21};
Line Loop(23) = { -8, 198, 20, -189 };	Ruled Surface(24) = {23};

// Lano mimo sondy (dole)

Line Loop(25) = { -109, 191, 121, -194 };	Ruled Surface(26) = {25};
Line Loop(27) = { -110, 194, 122, -197 };	Ruled Surface(28) = {27};
Line Loop(29) = { -111, 197, 123, -200 };	Ruled Surface(30) = {29};
Line Loop(31) = { -112, 200, 124, -191 };	Ruled Surface(32) = {31};

// Kovovy kryt - sluzi na odtienenie feromagnetickych okolitych vplyvov

// Definicia vonkajsich ploch krytu

// Horna podstava krytu - horna (vonkajsia) plocha ( rozhranie so vzduchovym obalom )

Line Loop(33) = { 17, 18, 19, 20 }; 	/* Plane Surface(34) = {33}; */
Line Loop(35) = { 13, 14, 15, 16 };	Plane Surface(36) = {35,33};
Line Loop(37) = { 9, 10, 11, 12 };	Plane Surface(38) = {37,35};

// Horna podstava krytu - valcovy (vonkajsi) plast hornej podstavy

Line Loop(39) = { -9, 133, 21, -134 };	Ruled Surface(40) = {39};
Line Loop(41) = { -10, 134, 22, -135 };	Ruled Surface(42) = {41};
Line Loop(43) = { -11, 135, 23, -136 };	Ruled Surface(44) = {43};
Line Loop(45) = { -12, 136, 24, -133 };	Ruled Surface(46) = {45};

// Valcovy plast vonkajsku tela krytu ( rozhranie so vzduchovym obalom )

Line Loop(47) = { -21, 149, 101, -150 }; 	Ruled Surface(48) = {47};
Line Loop(49) = { -22, 150, 102, -151 }; 	Ruled Surface(50) = {49};
Line Loop(51) = { -23, 151, 103, -152 };	Ruled Surface(52) = {51};
Line Loop(53) = { -24, 152, 104, -149 }; 	Ruled Surface(54) = {53};

// Dolna podstava krytu - valcovy (vonkajsi) plast dolnej podstavy

Line Loop(55) = { -101, 141, 117, -142 };	Ruled Surface(56) = {55};
Line Loop(57) = { -102, 142, 118, -143 };	Ruled Surface(58) = {57};
Line Loop(59) = { -103, 143, 119, -144 };	Ruled Surface(60) = {59};
Line Loop(61) = { -104, 144, 120, -141 };	Ruled Surface(62) = {61};

// Dolna podstava krytu - dolna (vonkajsia) plocha ( rozhranie so vzduchovym obalom )

Line Loop(63) = { -112, -111, -110, -109 }; 	/* Plane Surface(64) = {63}; */
Line Loop(65) = { -116, -115, -114, -113 }; 	Plane Surface(66) = {65,63};
Line Loop(67) = { -120, -119, -118, -117 };	Plane Surface(68) = {67,65}; 

// Definica ploch vo vnutri krytu ( vo vnutri sondy - lano, cievky, vnutro, lano )

// Lano v sonde - plast valca

Line Loop(69) = { -193, -17, 190, 109 };	Ruled Surface(70) = {69};
Line Loop(71) = { -196, -18, 193, 110 };	Ruled Surface(72) = {71};
Line Loop(73) = { -199, -19, 196, 111 };	Ruled Surface(74) = {73};
Line Loop(75) = { -190, -20, 199, 112 };	Ruled Surface(76) = {75};

// Cievka 1

// Horna plocha - cievky

Line Loop(77) = { 37, 38, 39, 40 };
Line Loop(79) = { 33, 34, 35, 36 };	Plane Surface(80) = {79,77};

// Plast valca cievky

// vnutorny

Line Loop(81) = { -158, -37, 157, 45 };	Ruled Surface(82) = {81};
Line Loop(83) = { -159, -38, 158, 46 };	Ruled Surface(84) = {83};
Line Loop(85) = { -160, -39, 159, 47 };	Ruled Surface(86) = {85};
Line Loop(87) = { -157, -40, 160, 48 };	Ruled Surface(88) = {87};

// vonkajsi

Line Loop(89) = { -161, -33, 164, 41 };	Ruled Surface(90) = {89};
Line Loop(91) = { -162, -34, 161, 42 };	Ruled Surface(92) = {91};
Line Loop(93) = { -163, -35, 162, 43 };	Ruled Surface(94) = {93};
Line Loop(95) = { -164, -36, 163, 44 };	Ruled Surface(96) = {95};

// Dolna plocha - cievky

Line Loop(97) = { -45, -46, -47, -48 };
Line Loop(99) = { -41, -42, -43, -44 };	Plane Surface(100) = {99,97};

// Cievka 2

// Horna plocha - cievky

Line Loop(101) = { 53, 54, 55, 56 };
Line Loop(103) = { 49, 50, 51, 52 };	Plane Surface(104) = {103,101};

// Plast valca cievky

// vnutorny

Line Loop(105) = { -166, -53, 165, 61 };	Ruled Surface(106) = {105};
Line Loop(107) = { -167, -54, 166, 62 };	Ruled Surface(108) = {107};
Line Loop(109) = { -168, -55, 167, 63 };	Ruled Surface(110) = {109};
Line Loop(111) = { -165, -56, 168, 64 };	Ruled Surface(112) = {111};

// vonkajsi

Line Loop(113) = { -170, -49, 169, 57 };	Ruled Surface(114) = {113};
Line Loop(115) = { -171, -50, 170, 58 };	Ruled Surface(116) = {115};
Line Loop(117) = { -172, -51, 171, 59 };	Ruled Surface(118) = {117};
Line Loop(119) = { -169, -52, 172, 60 };	Ruled Surface(120) = {119};

// Dolna plocha - cievky

Line Loop(121) = { -61, -62, -63, -64 };
Line Loop(123) = { -57, -58, -59, -60 };	Plane Surface(124) = {123,121};

// Cievka 3

// Horna plocha - cievky

Line Loop(125) = { 69, 70, 71, 72 };
Line Loop(127) = { 65, 66, 67, 68 };	Plane Surface(128) = {127,125};

// Plast valca cievky

// vnutorny

Line Loop(129) = { -174, -69, 173, 77 };	Ruled Surface(130) = {129};
Line Loop(131) = { -175, -70, 174, 78 };	Ruled Surface(132) = {131};
Line Loop(133) = { -176, -71, 175, 79 };	Ruled Surface(134) = {133};
Line Loop(135) = { -173, -72, 176, 80 };	Ruled Surface(136) = {135};

// vonkajsi

Line Loop(137) = { -178, -65, 177, 73 };	Ruled Surface(138) = {137};
Line Loop(139) = { -179, -66, 178, 74 };	Ruled Surface(140) = {139};
Line Loop(141) = { -180, -67, 179, 75 };	Ruled Surface(142) = {141};
Line Loop(143) = { -177, -68, 180, 76 };	Ruled Surface(144) = {143};

// Dolna plocha - cievky

Line Loop(145) = { -77, -78, -79, -80 };
Line Loop(147) = { -73, -74, -75, -76 };	Plane Surface(148) = {147,145};

// Cievka 4

// Horna plocha - cievky

Line Loop(149) = { 85, 86, 87, 88 };
Line Loop(151) = { 81, 82, 83, 84 };	Plane Surface(152) = {151,149};

// Plast valca cievky

// vnutorny

Line Loop(153) = { -182, -85, 181, 93 };	Ruled Surface(154) = {153};
Line Loop(155) = { -183, -86, 182, 94 };	Ruled Surface(156) = {155};
Line Loop(157) = { -184, -87, 183, 95 };	Ruled Surface(158) = {157};
Line Loop(159) = { -181, -88, 184, 96 };	Ruled Surface(160) = {159};

// vonkajsi

Line Loop(161) = { -186, -81, 185, 89 };	Ruled Surface(162) = {161};
Line Loop(163) = { -187, -82, 186, 90 };	Ruled Surface(164) = {163};
Line Loop(165) = { -188, -83, 187, 91 };	Ruled Surface(166) = {165};
Line Loop(167) = { -185, -84, 188, 92 };	Ruled Surface(168) = {167};

// Dolna plocha - cievky

Line Loop(169) = { -93, -94, -95, -96 };
Line Loop(171) = { -89, -90, -91, -92 };	Plane Surface(172) = {171,169};

// Vnutorny plast valca krytu + vnutro krytu

// Plochy v otvore krytu na hornej podstave

Line Loop(173) = { 137, -13, -138, 29 };	Ruled Surface(174) = {173};
Line Loop(175) = { 138, -14, -139, 30 };	Ruled Surface(176) = {175};
Line Loop(177) = { 139, -15, -140, 31 };	Ruled Surface(178) = {177};
Line Loop(179) = { 140, -16, -137, 32 };	Ruled Surface(180) = {179};

// Horna vnutorna podstava krytu

Line Loop(181) = { 29, 30, 31, 32 };
Line Loop(183) = { 25, 26, 27, 28 };	Plane Surface(184) = {183,181};

// Vnutorny plast krytu

Line Loop(185) = { 154, -25, -153, 105 };	Ruled Surface(186) = {185};
Line Loop(187) = { 155, -26, -154, 106 };	Ruled Surface(188) = {187};
Line Loop(189) = { 156, -27, -155, 107 };	Ruled Surface(190) = {189};
Line Loop(191) = { 153, -28, -156, 108 };	Ruled Surface(192) = {191};

// Dolna vnutorna podstava krytu

Line Loop(193) = { -97, -98, -99, -100};	
Line Loop(195) = { -105, -106, -107, -108 };	Plane Surface(196) = {195,193};

// Plochy v otvore krytu na dolnej podstave

Line Loop(197) = { -145, 97, 146, -113 };	Ruled Surface(198) = {197};
Line Loop(199) = { -146, 98, 147, -114 };	Ruled Surface(200) = {199};
Line Loop(201) = { -147, 99, 148, -115 };	Ruled Surface(202) = {201};
Line Loop(203) = { -148, 100, 145, -116 };	Ruled Surface(204) = {203};


/* Definicia objemov jednotlivych priestorov */

// Lano mimo aj vo vnutri sondy (krytu)

Surface Loop(1) = {2,14,18,20,22,24,26,28,30,32,70,72,74,76};
Volume(1) = {1};

// Cievka 1

Surface Loop(2) = {80,82,84,86,88,90,92,94,96,100};
Volume(2) = {2};

// Cievka 2

Surface Loop(3) = {104,106,108,110,112,114,116,118,120,124};
Volume(3) = {3};

// Cievka 3

Surface Loop(4) = {128,130,132,134,136,138,140,142,144,148};
Volume(4) = {4};

// Cievka 4

Surface Loop(5) = {152,154,156,158,160,162,164,166,168,172};
Volume(5) = {5};

// Kryt

// vnutro

Surface Loop(6) = {174,176,178,180,184,186,188,190,192,196,198,200,202,204};

// vonkajsok

Surface Loop(7) = {38,40,42,44,46,48,50,52,54,56,58,60,62,68};

Volume(6) = {7,6};

// Vzduch vo vnutri krytu

// Lano iba vo vnutri

Surface Loop(8) = {70,72,74,76};

// Vsetky cievky

Surface Loop(9) = {80,82,84,86,88,90,92,94,96,100,104,106,108,110,112,114,116,118,120,124,128,130,132,134,136,138,140,142,144,148,152,154,156,158,160,162,164,166,168,172};

// Vnutro krytu

Surface Loop(10) = {36,66,174,176,178,180,184,186,188,190,192,196,198,200,202,204};

// Vnutro krytu - Cievky - Lano = vzduch v sonde

Volume(7) = {10,9,8};

// Objem vzduchoveho obalu okolo krytu 

Surface Loop(11) = {18,20,22,24,26,28,30,32,36,38,40,42,44,46,48,50,52,54,56,58,60,62,66,68};
Surface Loop(12) = {4,6,8,10,12,16};
Volume(8) = {12,11};

// Definicia fyzikalnych ploch a objemov pre program GetDP

// Lano

Physical Surface(999) = {2,14}; /* dotykove plochy lana na vzduchovom obale */
Physical Surface(1000) = {18,20,22,24,26,28,30,32,70,72,74,76};
Physical Volume(1001) = {1};

// Cievky 

Physical Surface(1002) = {80,82,84,86,88,90,92,94,96,100,104,106,108,110,112,114,116,118,120,124,128,130,132,134,136,138,140,142,144,148,152,154,156,158,160,162,164,166,168,172};
Physical Volume(1003) = {2,3,4,5};

// Kryt

Physical Surface(1004) = {174,176,178,180,184,186,188,190,192,196,198,200,202,204,38,40,42,44,46,48,50,52,54,56,58,60,62,68};
Physical Volume(1005) = {6};

// Vzduch v sonde (kryte) v okoli sondy ( vo vzduchovom obale ) a plochy vzduchoveho obalu

Physical Surface(1006) = {4,6,8,10,12,16};
Physical Volume(1007) = {7}; /* vzduch v sonde */
Physical Volume(1008) = {8}; /* okolity vzduch */

