epecr  = 4.e-3 ;

c      = 0.0 ; 
lspire = 0.135 ;
pspire = 0.4 ;
lecr   = 0.3 ;
pecr   = 0.5 ;
hecr   = 0.2 - epecr/2. ;

far   = 2. ;
infty = 2.5 ;

lc1 = 0.1; 
lc2 = 0.1; 
lc4 = 0.8;

lc1 = 0.01; 
lc2 = 0.05; 
lc3 = 0.1; 
lc4 = 0.5;



Point(1) = {c,        c,        c, lc2};
Point(2) = {c+lspire, c,        c, lc2};
Point(3) = {c,        c+pspire, c, lc2};
Point(4) = {c+lspire, c+pspire, c, lc2};

Point(5) = {c+lecr,   c,        c, lc2};
Point(6) = {c,        c+pecr,   c, lc2};
Point(7) = {c+lecr,   c+pecr,   c, lc2};

Point(8) = {c,        c,        c+hecr, lc2};
Point(9) = {c+lecr,   c,        c+hecr, lc1};
Point(10)= {c,        c+pecr,   c+hecr, lc1};
Point(11)= {c+lecr,   c+pecr,   c+hecr, lc1};

Point(12)= {c+far,    c,        c,     lc4};
Point(13)= {c,        c+far,    c,     lc4};
Point(14)= {c,        c,        c+far, lc3};
Point(15)= {c,        c,        c-far, lc4};

Point(16)= {c+infty,  c,        c,       lc4};
Point(17)= {c,        c+infty,  c,       lc4};
Point(18)= {c,        c,        c+infty, lc4};
Point(19)= {c,        c,        c-infty, lc4};

Line(1) = {2,4};
Line(2) = {4,3};
Line(3) = {1,2};
Line(4) = {1,3};
Line(5) = {2,5};
Line(6) = {5,7};
Line(7) = {7,6};
Line(8) = {6,13};
Line(9) = {5,12};
Line(10) = {6,10};
Line(11) = {10,11};
Line(12) = {11,7};
Line(13) = {10,8};
Line(14) = {8,9};
Line(15) = {9,11};
Line(16) = {9,5};
Line(17) = {1,8};
Line(18) = {8,14};
Line(19) = {14,18};
Line(20) = {13,17};
Line(21) = {12,16};
Circle(22) = {12,1,13};
Circle(23) = {16,1,17};
Circle(24) = {12,1,14};
Circle(25) = {16,1,18};
Circle(26) = {13,1,14};
Circle(27) = {17,1,18};
Circle(28) = {15,1,13};
Circle(29) = {19,1,17};
Circle(30) = {12,1,15};
Circle(31) = {16,1,19};
Line(32) = {1,15};
Line(33) = {15,19};
Line(34) = {3,6};

Line Loop(35) = {-2,-1,-3,4};
Plane Surface(36) = {35};
Line Loop(37) = {-7,-6,-5,1,2,34};
Plane Surface(38) = {37};
Line Loop(39) = {7,10,11,12};
Plane Surface(40) = {39};
Line Loop(41) = {12,-6,-16,15};
Plane Surface(42) = {41};
Line Loop(43) = {14,15,-11,13};
Plane Surface(44) = {43};
Line Loop(45) = {5,-16,-14,-17,3};
Plane Surface(46) = {45};
Line Loop(47) = {-17,4,34,10,13};
Plane Surface(48) = {47};
Line Loop(49) = {7,8,-22,-9,6};
Plane Surface(50) = {49};
Line Loop(51) = {20,-23,-21,22};
Plane Surface(52) = {51};
Line Loop(53) = {-8,-34,-4,32,28};
Plane Surface(54) = {53};
Line Loop(55) = {-20,-28,33,29};
Plane Surface(56) = {55};
Line Loop(57) = {5,9,30,-32,3};
Plane Surface(58) = {57};
Line Loop(59) = {19,-25,-21,24};
Plane Surface(60) = {59};
Line Loop(61) = {9,24,-18,14,16};
Plane Surface(62) = {61};
Line Loop(63) = {-18,-13,-10,8,26};
Plane Surface(64) = {63};
Line Loop(65) = {19,-27,-20,26};
Plane Surface(66) = {65};
Line Loop(67) = {33,-31,-21,30};
Plane Surface(68) = {67};
Line Loop(69) = {-28,-30,22};
Ruled Surface(70) = {69};
Line Loop(71) = {-29,-31,23};
Ruled Surface(72) = {71};
Line Loop(73) = {-24,22,26};
Ruled Surface(74) = {73};
Line Loop(75) = {-25,23,27};
Ruled Surface(76) = {75};

Surface Loop(77) = {48,-46,-38,-40,-44,42,-36};
Volume(78) = {77};
Surface Loop(79) = {64,-62,-50,40,44,-42,-74};
Volume(80) = {79};
Surface Loop(81) = {36,38,50,54,58,70};
Volume(82) = {81};
Surface Loop(83) = {70,-56,-52,-72,68};
Volume(84) = {83};
Surface Loop(85) = {52,66,-60,76,-74};
Volume(86) = {85};



AirInterieur = 1111 ; 
AirBas       = 1112 ; 
AirHaut      = 1113 ; 
AirInfini    = 1114 ;

Spire  = 2222 ; 
Ecran  = 3333 ; 
dEcran = 3334 ;

CLInf = 1100 ;



Physical Line(dEcran) = {11,12,6, 14,16,13} ;

Physical Surface(Spire) = 36 ;
Physical Surface(Ecran) = {42,44} ;

Physical Surface(CLInf) = {76,72} ;

Physical Volume(AirInterieur) = 78;
Physical Volume(AirBas) = 80;
Physical Volume(AirHaut) = 82;

Physical Volume(AirInfini) = {84,86};



