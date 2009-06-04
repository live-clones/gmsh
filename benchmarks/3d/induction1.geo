//Fichier test

mm    = 1e-3;
s     = 1.;
prec4 = 15 * mm * s;
prec1 = 7 * mm * s;
prec2 = 10 * mm * s;
prec3 = 4 * mm * s;

//Donnees geometriques 

d       = 20 * mm;
largt   = 50 * mm;
longt   = 60 * mm;
h       = 40 * mm;
c       = 25 * mm;
k       = 1.5;
bl      = 10 * mm;
bk      = k * bl;
long_ei = largt + 2 * c;
long_ii = long_ei - 2 * bk;
larg_ei = 2 * bk;
larg_ii = larg_ei - 2 * bl;
ep_i    = 10 * mm;
htot    = 200 * mm;
mult    = 1.5;

// pts ind 1

Point(1)  = { larg_ii/2.   , 0                       , h/2.        , prec1 };
Point(2)  = { larg_ii/2.   , long_ii/2. - larg_ii/2. , h/2.        , prec1 };
Point(3)  = { 0            , long_ii/2.              , h/2.        , prec1 };
Point(4)  = { -larg_ii/2.  , long_ii/2. - larg_ii/2. , h/2.        , prec1 };
Point(5)  = { -larg_ii/2.  , 0                       , h/2.        , prec1 };
Point(6)  = { larg_ii/2.   , 0                       , h/2. + ep_i , prec1 };
Point(7)  = { larg_ii/2.   , long_ii/2. - larg_ii/2. , h/2. + ep_i , prec1 };
Point(8)  = { 0            , long_ii/2.              , h/2. + ep_i , prec1 };
Point(9)  = { -larg_ii/2.  , long_ii/2. - larg_ii/2. , h/2. + ep_i , prec1 };
Point(10) = { -larg_ii/2.  , 0                       , h/2. + ep_i , prec1 };
Point(11)  = { 0           , long_ii/2. - larg_ii/2  , h/2.        , prec1 };
Point(12)  = { 0           , long_ii/2. - larg_ii/2  , h/2.+ ep_i  , prec1 };
Point(13) = { larg_ei/2.   , 0                       , h/2.        , prec1 };
Point(14) = { larg_ei/2.   , long_ei/2. - larg_ei/2. , h/2.        , prec1 };
Point(15) = { 0            , long_ei/2.              , h/2.        , prec1 };
Point(16) = { -larg_ei/2.  , long_ei/2. - larg_ei/2. , h/2.        , prec1 };
Point(17) = { -larg_ei/2.  , 0                       , h/2.        , prec1 };
Point(18) = { larg_ei/2.   , 0                       , h/2. + ep_i , prec1 };
Point(19) = { larg_ei/2.   , long_ei/2. - larg_ei/2. , h/2. + ep_i , prec1 };
Point(20) = { 0            , long_ei/2.              , h/2. + ep_i , prec1 };
Point(21) = { -larg_ei/2.  , long_ei/2. - larg_ei/2. , h/2. + ep_i , prec1 };
Point(22) = { -larg_ei/2.  , 0                       , h/2. + ep_i , prec1 };

h2        =h+3*ep_i;

//Pts ind 2

Point(401)  = { larg_ii/2.   , 0                       , h2/2.        , prec1 };
Point(402)  = { larg_ii/2.   , long_ii/2. - larg_ii/2. , h2/2.        , prec1 };
Point(403)  = { 0            , long_ii/2.              , h2/2.        , prec1 };
Point(404)  = { -larg_ii/2.  , long_ii/2. - larg_ii/2. , h2/2.        , prec1 };
Point(405)  = { -larg_ii/2.  , 0                       , h2/2.        , prec1 };
Point(406)  = { larg_ii/2.   , 0                       , h2/2. + ep_i , prec1 };
Point(407)  = { larg_ii/2.   , long_ii/2. - larg_ii/2. , h2/2. + ep_i , prec1 };
Point(408)  = { 0            , long_ii/2.              , h2/2. + ep_i , prec1 };
Point(409)  = { -larg_ii/2.  , long_ii/2. - larg_ii/2. , h2/2. + ep_i , prec1 };
Point(410) = { -larg_ii/2.  , 0                       , h2/2. + ep_i , prec1 };
Point(411)  = { 0           , long_ii/2. - larg_ii/2  , h2/2.        , prec1 };
Point(412)  = { 0           , long_ii/2. - larg_ii/2  , h2/2.+ ep_i  , prec1 };
Point(413) = { larg_ei/2.   , 0                       , h2/2.        , prec1 };
Point(414) = { larg_ei/2.   , long_ei/2. - larg_ei/2. , h2/2.        , prec1 };
Point(415) = { 0            , long_ei/2.              , h2/2.        , prec1 };
Point(416) = { -larg_ei/2.  , long_ei/2. - larg_ei/2. , h2/2.        , prec1 };
Point(417) = { -larg_ei/2.  , 0                       , h2/2.        , prec1 };
Point(418) = { larg_ei/2.   , 0                       , h2/2. + ep_i , prec1 };
Point(419) = { larg_ei/2.   , long_ei/2. - larg_ei/2. , h2/2. + ep_i , prec1 };
Point(420) = { 0            , long_ei/2.              , h2/2. + ep_i , prec1 };
Point(421) = { -larg_ei/2.  , long_ei/2. - larg_ei/2. , h2/2. + ep_i , prec1 };
Point(422) = { -larg_ei/2.  , 0                       , h2/2. + ep_i , prec1 };

// points volume air et points tole

largeur  = 100 * mm;
longueur = 100 * mm;
hauteur  = 2./3.*100 * mm;
ept      = 1 * mm;


Point(23) = { -largeur/2. , 0        , 0       , prec3 };
Point(25) = { largeur/2.  , 0        , 0       , prec3 }; 
Point(26) = { largeur/2.  , longueur , 0       , prec3 };
Point(27) = { -largeur/2. , longueur , 0       , prec3 };

Point(28) = { -largeur/2. , 0        , ept     , prec3 };
Point(29) = { largeur/2.  , 0        , ept     , prec3 }; 
Point(30) = { largeur/2.  , longueur , ept     , prec3 };
Point(31) = { -largeur/2. , longueur , ept     , prec3 };

Point(32) = { -largeur/2. , 0        , hauteur , prec4 };
Point(33) = { largeur/2.  , 0        , hauteur , prec4 }; 
Point(34) = { largeur/2.  , longueur , hauteur , prec4 };
Point(35) = { -largeur/2. , longueur , hauteur , prec4 };



Line(1) = {1,13};
Line(2) = {13,18};
Line(3) = {18,6};
Line(4) = {6,1};
Line(5) = {5,10};
Line(6) = {10,22};
Line(7) = {22,17};
Line(8) = {17,5};
Line(9) = {6,7};
Circle(10) = {7,12,8};
Circle(11) = {8,12,9};
Line(12) = {9,9,10};
Line(13) = {1,2};
Circle(14) = {2,11,3};
Circle(15) = {3,11,4};
Line(16) = {4,5};
Line(17) = {13,14};
Circle(18) = {14,3,15};
Circle(19) = {15,3,16};
Line(20) = {16,17};
Line(21) = {18,19};
Circle(22) = {19,8,20};
Circle(23) = {20,8,21};
Line(24) = {21,22};


Line(25) = {23,25};
Line(26) = {25,26};
Line(27) = {26,27};
Line(28) = {27,23};
Line(29) = {28,29};
Line(30) = {29,30};
Line(31) = {30,31};
Line(32) = {31,28};
Line(33) = {33,34};
Line(34) = {34,35};
Line(35) = {35,32};
Line(36) = {32,33};
Line(37) = {25,29};
Line(38) = {29,33};
Line(39) = {26,30};
Line(40) = {30,34};
Line(41) = {27,31};
Line(42) = {31,35};
Line(43) = {23,28};
Line(44) = {28,32};
Line(45) = {14,19};
Line(46) = {2,7};
Line(47) = {4,9};
Line(48) = {16,21};
Line(49) = {15,20};
Line(50) = {3,8};
Line(51) = {5,1};
Line(52) = {10,6};
Line(1002) = {401,413};
Line(1003) = {413,418};
Line(1004) = {418,406};
Line(1005) = {406,401};
Line(1006) = {405,410};
Line(1007) = {410,422};
Line(1008) = {422,417};
Line(1009) = {417,405};
Line(1010) = {418,419};
Line(1012) = {414,413};
Line(1013) = {422,421};
Line(1014) = {417,416};
Line(1015) = {406,407};
Line(1016) = {401,402};
Line(1017) = {405,404};
Line(1018) = {410,409};
Circle(1019) = {404,411,403};
Circle(1020) = {403,411,402};
Circle(1023) = {416,403,415};
Circle(1024) = {415,403,414};
Circle(1025) = {409,412,408};
Circle(1026) = {408,412,407};
Circle(1027) = {421,408,420};
Circle(1028) = {420,408,419};
Line(1029) = {415,415,420};
Line(1030) = {408,403};
Line(1037) = {410,406};
Line(1038) = {405,401};
Line(1041) = {407,402};
Line(1042) = {414,419};
Line(1043) = {404,409};
Line(1044) = {416,421};

Line Loop(53) = {25,26,27,28};
Plane Surface(54) = {53};
Line Loop(55) = {30,-39,-26,37};
Plane Surface(56) = {55};
Line Loop(57) = {-31,-39,27,41};
Plane Surface(58) = {57};
Line Loop(59) = {43,-32,-41,28};
Plane Surface(60) = {59};
Line Loop(61) = {-37,-25,43,29};
Plane Surface(62) = {61};
Line Loop(63) = {33,-40,-30,38};
Plane Surface(64) = {63};
Line Loop(65) = {-34,-40,31,42};
Plane Surface(66) = {65};
Line Loop(67) = {44,-35,-42,32};
Plane Surface(68) = {67};
Line Loop(69) = {36,-38,-29,44};
//Line Loop(70) = {1,2,3,-52,6,7,8,51};
//Plane Surface(71) = {69,70};
Line Loop(72) = {29,30,31,32};
Plane Surface(73) = {72};
Line Loop(74) = {1,2,3,4};
Plane Surface(75) = {74};
Line Loop(76) = {52,4,-51,5};
Plane Surface(77) = {76};
Line Loop(78) = {7,8,5,6};
Plane Surface(79) = {78};
Line Loop(80) = {21,-45,-17,2};
Plane Surface(81) = {80};
Line Loop(82) = {-49,-18,45,22};
Ruled Surface(83) = {82};
Line Loop(84) = {-23,-49,19,48};
Ruled Surface(85) = {84};
Line Loop(86) = {-20,48,24,7};
Ruled Surface(87) = {86};
Line Loop(88) = {-10,-46,14,50};
Ruled Surface(89) = {88};
Line Loop(90) = {-11,-50,15,47};
Ruled Surface(91) = {90};
Line Loop(92) = {13,46,-9,4};
Plane Surface(93) = {92};
Line Loop(94) = {5,-12,-47,16};
Plane Surface(95) = {94};
Line Loop(96) = {8,-16,-15,-14,-13,1,17,18,19,20};
Plane Surface(97) = {96};
Line Loop(98) = {51,13,14,15,16};
Plane Surface(99) = {98};
Line Loop(100) = {52,9,10,11,12};
Plane Surface(101) = {100};
Line Loop(102) = {10,11,12,6,-24,-23,-22,-21,3,9};
Plane Surface(103) = {102};
Line Loop(104) = {36,33,34,35};
Plane Surface(105) = {104};
Line Loop(1031) = {1006,1007,1008,1009};
Plane Surface(1032) = {1031};
Line Loop(1033) = {1002,1003,1004,1005};
Plane Surface(1034) = {1033};
Line Loop(1035) = {-1004,1010,-1028,-1027,-1013,-1007,1018,1025,1026,-1015};
Plane Surface(1036) = {1035};
Line Loop(1039) = {1020,-1016,1002,-1012,-1024,-1023,-1014,1009,1017,1019};
Plane Surface(1040) = {1039};
Line Loop(1045) = {1028,-1042,-1024,1029};
Ruled Surface(1046) = {1045};
Line Loop(1047) = {1029,-1027,-1044,1023};
Ruled Surface(1048) = {1047};
Line Loop(1049) = {1030,-1019,1043,1025};
Ruled Surface(1050) = {1049};
Line Loop(1051) = {-1020,-1030,1026,1041};
Ruled Surface(1052) = {1051};
Line Loop(1053) = {1010,-1042,1012,1003};
Plane Surface(1054) = {1053};
Line Loop(1055) = {1016,-1041,-1015,1005};
Plane Surface(1056) = {1055};
Line Loop(1057) = {-1013,1008,1014,1044};
Plane Surface(1058) = {1057};
Line Loop(1059) = {-1018,-1006,1017,1043};
Plane Surface(1060) = {1059};
Line Loop(1061) = {1037,1005,-1038,1006};
Plane Surface(1062) = {1061};
Line Loop(1063) = {1019,1020,-1016,-1038,1017};
Plane Surface(1064) = {1063};
Line Loop(1065) = {1026,-1015,-1037,1018,1025};
Plane Surface(1066) = {1065};
Line Loop(1079) = {8,51,1,2,3,-52,6,7};
Line Loop(1080) = {1038,1002,1003,1004,-1037,1007,1008,1009};
Plane Surface(1081) = {69,1079,1080};

Surface Loop(1067) = {1060,1066,-1052,-1064,-1050,-1056,1062};
Volume(1068) = {1067};

Surface Loop(1070) = {1060,1036,1034,-1040,-1052,-1050,-1056,-1054,1046,-1048,-1058,1032};
Volume(1071) = {1070};

Surface Loop(1072) = {89,101,-77,93,-99,91,95};
Volume(1073) = {1072};

Surface Loop(1074) = {95,-79,87,97,91,103,89,93,-75,81,83,-85};
Volume(1075) = {1074};

Surface Loop(1076) = {62,56,-58,54,-60,-73};
Volume(1077) = {1076};

Surface Loop(1082) = {1066,-1036,-1081,105,-64,66,-73,68,97,99,81,103,-101,87,-85,83,-1064,1040,1054,-1046,1048,1058};
Volume(1083) = {1082};

//Physical datas

Physical Volume(502) = { 1075 , 1071 }; //ind inf et sup
Physical Volume(501) = { 1077 }; //tole
Physical Volume(500) = { 1083 }; // Volume air
Physical Volume(550) = { 1073 }; //boite air inf
Physical Volume(551) = { 1068 }; //boite air sup

Physical Surface(600) = {1054,1046,1048,1058,1060,1050,1052,1056,1036,1040,97,87,85,83,81,103,93,95,91,89}; //skinind

Physical Surface(601) = { 99,1064 }; //cutind
Physical Surface(602) = {93,89,91,95,1056,1052,1050,1060}; //skindomainc2_Mag

Physical Surface(603) = { 73 }; //skintole
Physical Surface(1001) = {64,66,68,105,54,58};  //gh0
 
Physical Surface(700) = {75,1034}; //elec0
Physical Surface(701) = {79,1032}; //elec1

Physical Surface(702) = {75,1034,79,1032}; //elec1+2




