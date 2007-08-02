hsubstrat = 1;
wsubstrat = 6;
lsubstrat = 3*hsubstrat;

hboite = hsubstrat;

wstrip = hsubstrat;
estrip = hsubstrat/50;

R = hsubstrat/2;
r = hsubstrat/100;

maboite = 0.99*hsubstrat/3;
mafil = Pi*r/6;
mastrip = hsubstrat/10;

Point(1) = {0,-wstrip/2,0,mastrip};
Point(2) = {0,wstrip/2,0,mastrip};
Point(3) = {R+r,0,0,mafil};

Extrude Point {1, {lsubstrat,0,0}};
Extrude Point {2, {lsubstrat,0,0}};

Line(3) = {1,2};
Line(4) = {5,4};

Extrude Point {3, {0,0,1}, {R,0,0}, Pi/4};
Extrude Point {6, {0,0,1}, {R,0,0}, Pi/4};
Extrude Point {8, {0,0,1}, {R,0,0}, Pi/4};
Extrude Point {9, {0,0,1}, {R,0,0}, Pi/4};
Extrude Point {10, {0,0,1}, {R,0,0}, Pi/4};
Extrude Point {11, {0,0,1}, {R,0,0}, Pi/4};
Extrude Point {12, {0,0,1}, {R,0,0}, Pi/4};
Extrude Point {13, {0,0,1}, {R,0,0}, Pi/4};

Line Loop(13) = {-4,-2,-3,1};
Line Loop(14) = {5,6,7,8,9,10,11,12};
Plane Surface(15) = {13,14};

Extrude Line {8, {0,-1,0}, {0,0,0}, Pi/2}{
  Layers {{R*Pi/2/mafil},{1.0}};
};
Extrude Line {9, {0,-1,0}, {0,0,0}, Pi/2}{
  Layers {{R*Pi/2/mafil},{1.0}};
};
Extrude Line {10, {0,-1,0}, {0,0,0}, Pi/2}{
  Layers {{R*Pi/2/mafil},{1.0}};
};
Extrude Line {7, {0,-1,0}, {0,0,0}, Pi/2}{
  Layers {{R*Pi/2/mafil},{1.0}};
};
Extrude Line {6, {0,-1,0}, {0,0,0}, Pi/2}{
  Layers {{R*Pi/2/mafil},{1.0}};
};
Extrude Line {5, {0,-1,0}, {0,0,0}, Pi/2}{
  Layers {{R*Pi/2/mafil},{1.0}};
};
Extrude Line {12, {0,-1,0}, {0,0,0}, Pi/2}{
  Layers {{R*Pi/2/mafil},{1.0}};
};
Extrude Line {11, {0,-1,0}, {0,0,0}, Pi/2}{
  Layers {{R*Pi/2/mafil},{1.0}};
};

Point(51) = {0,-wsubstrat/2,0,maboite};
Point(52) = {0,-wsubstrat/2,-hsubstrat,maboite};
Point(53) = {0,wsubstrat/2,-hsubstrat,maboite};
Point(54) = {0,wsubstrat/2,0,maboite};
Point(55) = {0,-wstrip/2,-estrip,mastrip};
Point(56) = {0,wstrip/2,-estrip,mastrip};
Line(48) = {1,55};
Line(49) = {1,51};
Line(50) = {51,52};
Line(51) = {52,53};
Line(52) = {53,54};
Line(53) = {54,2};
Line(54) = {55,56};
Line(55) = {56,2};
Line Loop(56) = {-53,-52,-51,-50,-49,48,54,55};
Plane Surface(57) = {56};
aa[] = Extrude Surface {57, {lsubstrat,0,0}};  ;
Delete { Volume { aa[1] }; }

Extrude Line {81, {0,0,hboite}};
Extrude Line {69, {0,0,hboite}};
Line(108) = {83,85};
Line(109) = {86,84};
Line Loop(110) = {108,-105,53,-3,49,101};
Line Loop(111) = {40,36,32,28,16,20,24,44};
Plane Surface(112) = {110,111};
Line Loop(113) = {-109,-104,-108,100};
Plane Surface(114) = {113};
Line Loop(115) = {-109,-106,-59,4,-63,102};
Plane Surface(116) = {115};

Physical Surface(117) = {78};
Physical Surface(118) = {94};
Physical Surface(119) = {15};
Physical Surface(120) = {86,70};
Physical Surface(121) = {114};
Physical Surface(122) = {82,103};
Physical Surface(123) = {90};
Physical Surface(124) = {98};
Physical Surface(125) = {107,74};
Physical Surface(126) = {112,57};
Physical Surface(127) = {99,116};
Physical Surface(128) = {39,35,43,31,47,19,27,23};

Surface Loop(129) = {70,57,74,78,82,86,90,94,98,99};
Volume(130) = {129};
Surface Loop(131) = {70,112,114,116,107,15,86,103,39,35,31,19,23,27,47,43};
Volume(132) = {131};

Physical Volume(133) = {130};
Physical Volume(134) = {132};
