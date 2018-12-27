
//Tailles maillage :
//------------------
tailleMaillageGuide = 0.10;
tailleMaillageAxe = 0.03;
tailleMaillageGlissement = 0.05;

//Parametres geometriques :
//-------------------------
epaisseurGuide = 0.60;
largeurGuide = 3.86;
pasGuide = 1.10;
diametreGlissement = 0.70;
hauteurGuide = 1.10;
rayonCourbureInterieur = 0.5 * ( pasGuide - epaisseurGuide);
rayonCourbureExterieur = 0.5 * ( pasGuide + epaisseurGuide);
rayonGlissement = 0.5 * diametreGlissement;
rayonFaisceau = 0.5 * rayonGlissement;
axialSwitch = -0.5 * pasGuide;
b = epaisseurGuide;
a = largeurGuide;
p = pasGuide;
d = diametreGlissement;
h = hauteurGuide;
rIn = rayonCourbureInterieur;
rEx = rayonCourbureExterieur;
rG = 0.5 * diametreGlissement;
rB = 0.5 * rG;
sw = axialSwitch;

//Construction de la geometrie :
//------------------------------
Point(1) = { 0.5 * a, 0.5 * h, rIn + sw, tailleMaillageGuide};
Point(2) = {-0.5 * a, 0.5 * h, rIn + sw, tailleMaillageGuide};
Point(3) = { 0.5 * a, 0.5 * h, rEx + sw, tailleMaillageGuide};
Point(4) = {-0.5 * a, 0.5 * h, rEx + sw, tailleMaillageGuide};
Point(5) = {rG, 0, 0 + sw, tailleMaillageGlissement};
Point(6) = {rB, 0, 0 + sw, tailleMaillageAxe};
Point(7) = {0, 0, rIn + sw, tailleMaillageAxe};
Extrude {{1, 0, 0}, {0, 0.5 * hauteurGuide, 0 + sw}, -0.5 * Pi} {
Point{1, 2, 3, 4};
}
Extrude {0, -0.5 * hauteurGuide, 0} {
Point{1, 2, 3, 4};
}
Extrude {{0, 0, 1}, {0, 0, 0}, 0.5 * Pi} {
Point{6, 5};
}
Symmetry {-1, 0, 0, 0} {
Duplicata {
Line{10, 9};
}
}
Extrude {0, 0, rIn} {
Point{5, 20, 21};
}
Circle(16) = {28, 7, 29};
Circle(17) = {28, 7, 27};
Extrude {0, 0, p} {
Point{6, 18, 19, 26};
}
Symmetry {0, 0, -1, 0.5 * p + sw} {
Duplicata {
Line{13, 9, 14, 12, 15, 16, 17};
}
}
Line(29) = {15, 29};
Line(30) = {15, 17};
Line(31) = {17, 53};
Line(32) = {52, 33};
Line(33) = {33, 32};
Line(34) = {32, 30};
Line(35) = {30, 34};
Line(36) = {35, 16};
Line(37) = {16, 14};
Line(38) = {14, 27};
Line(39) = {5, 6};
Line(40) = {6, 19};
Line(41) = {19, 26};
Line(42) = {26, 21};
Line(43) = {8, 10};
Line(44) = {10, 13};
Line(45) = {13, 12};
Line(46) = {12, 8};
Line(47) = {2, 1};
Line(48) = {1, 3};
Line(49) = {3, 4};
Line(50) = {4, 2};
Circle(51) = {43, 32, 52};
Circle(52) = {43, 32, 34};
Delete {
Line{20};
}
Line Loop(53) = {45, 46, 43, 44};
Plane Surface(54) = {53};
Line Loop(55) = {4, -44, -2, -50};
Plane Surface(56) = {55};
Line Loop(57) = {46, -1, 48, 3};
Plane Surface(58) = {57};
Line Loop(59) = {5, -37, -7, -48};
Plane Surface(60) = {59};
Line Loop(61) = {50, 6, 30, -8};
Plane Surface(62) = {61};
Line Loop(63) = {31, -27, 28, 36, -7, 49, 8};
Plane Surface(64) = {63};
Line Loop(65) = {38, -17, 16, -29, -6, 47, 5};
Plane Surface(66) = {65};
Line Loop(67) = {51, 32, 25, -23, 35, -52};
Plane Surface(68) = {67};
Line Loop(69) = {10, -11, -42, 12, -9, -39};
Plane Surface(70) = {69};
Line Loop(71) = {34, 23, -25, 33};
Plane Surface(72) = {71};
Line Loop(73) = {41, 12, -9, 40};
Plane Surface(74) = {73};
Line Loop(75) = {4, 45, -3, 49};
Surface(76) = {75};
Line Loop(77) = {43, -2, 47, 1};
Surface(78) = {77};
Line Loop(79) = {16, -15, 11, 14};
Surface(80) = {79};
Line Loop(81) = {14, 17, -13, 10};
Surface(82) = {81};
Line Loop(83) = {51, 26, -27, -24};
Surface(84) = {83};
Line Loop(85) = {24, 28, -22, -52};
Surface(86) = {85};
Line Loop(87) = {18, 23, -19, -9};
Surface(88) = {87};
Line Loop(89) = {19, -25, -21, 12};
Surface(90) = {89};
Rotate {{1, 0, 0}, {0, 0, 0.5 * p + sw}, Pi} {
Duplicata {
Surface{58, 60, 86, 72, 68, 84, 82, 88, 90, 74, 70, 80, 76, 64, 54, 78, 56, 66, 62};
}
}
Surface Loop(192) = {90, 88, 128, 133, 72, 138, 74, 106};
Volume(193) = {192};
Surface Loop(194) = {76, 56, 54, 58, 78, 66, 160, 118, 80, 82, 101, 111, 70, 96, 183, 64, 84, 150, 123, 86, 68, 143, 60, 62, 191, 178, 155, 168, 91, 173, 90, 88, 128, 133};
Volume(195) = {194};

//Conditions maitre-esclave : ici en utilisant une transformation affine explicite
//---------------------------
Periodic Surface {168} = {54} Affine {1,0,0,0, 0,-1,0,0, 0,0,-1,0, 0,0,0,1};

Characteristic Length{13} = 0.02;
