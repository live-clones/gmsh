mm    = 1e-3;
s     = 0.6;
prec1 = 20 * mm * s;
prec2 = 35 * mm * s;
prec3 = 60 * mm * s;

/* Donnees geometriques */

d       = 10 * mm;
largt   = 500 * mm;
longt   = 600 * mm;
h       = 50 * mm;
c       = 30 * mm;
k       = 1.5;
bl      = 100 * mm;
bk      = k * bl;
long_ei = largt + 2 * c;
long_ii = long_ei - 2 * bk;
larg_ei = 2 * bk;
larg_ii = larg_ei - 2 * bl;
ep_i    = 10 * mm;
htot    = 200 * mm;
mult    = 1.5;
/* pts ind */
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

/* pts tole */

Point(23) = { - longt/2.   , 0                       , 0           , prec1 };
Point(24) = { longt/2.     , 0                       , 0           , prec1 };
Point(25) = { longt/2.     , largt/2.                , 0           , prec1 };
Point(26) = { - longt/2.   , largt/2.                , 0           , prec1 };
Point(27) = { - longt/2.   , 0                       , d/2.        , prec1 };
Point(28) = { longt/2.     , 0                       , d/2.        , prec1 };
Point(29) = { longt/2.     , largt/2.                , d/2.        , prec1 };
Point(30) = { - longt/2.   , largt/2.                , d/2.        , prec1 };

/* pts supp contour air */

Point(31) = { longt/2.     , mult * largt/2.         , 0           , prec2 };
Point(32) = { - longt/2.   , mult * largt/2.         , 0           , prec2 };
Point(33) = { longt/2.     , mult * largt/2.         , htot        , prec3 };
Point(34) = { - longt/2.   , mult * largt/2.         , htot        , prec3 };
Point(35) = { longt/2.     , 0                       , htot        , prec3 };
Point(36) = { - longt/2.   , 0                       , htot        , prec3 };


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
Line(25) = {23,27};
Line(26) = {27,36};
Line(27) = {26,30};
Line(28) = {23,26};
Line(29) = {26,32};
Line(30) = {32,34};
Line(31) = {34,36};
Line(32) = {30,27};
Line(33) = {32,31};
Line(34) = {31,33};
Line(35) = {33,34};
Line(36) = {33,35};
Line(37) = {35,36};
Line(38) = {31,25};
Line(39) = {25,24};
Line(40) = {24,28};
Line(41) = {28,35};
Line(42) = {25,29};
Line(43) = {29,28};
Line(44) = {28,27};
Line(45) = {24,23};
Line(46) = {29,30};
Line(47) = {25,26};
Line(62) = {9,4};
Line(63) = {8,3};
Line(64) = {7,2};
Line(65) = {21,16};
Line(66) = {20,15};
Line(67) = {19,14};
Line(68) = {5,1};
Line(69) = {6,10};

/* tole */
Line Loop(70) = {-25,28,27,32};
Plane Surface(71) = {70};
Line Loop(72) = {-25,-45,40,44};
Plane Surface(73) = {72};
Line Loop(74) = {40,-43,-42,39};
Plane Surface(75) = {74};
Line Loop(76) = {27,-46,-42,47};
Plane Surface(77) = {76};
Line Loop(78) = {-32,-46,43,44};
Plane Surface(79) = {78};
Line Loop(80) = {-47,39,45,28};
Plane Surface(81) = {80};
Surface Loop(82) = {79,71,-73,-81,-77,75};
Complex Volume(83) = {82};

/* boite air */

Line Loop(84) = {-13,-4,9,64};
Plane Surface(85) = {84};
Line Loop(86) = {-69,4,-68,5};
Plane Surface(87) = {86};
Line Loop(88) = {5,-12,62,16};
Plane Surface(89) = {88};
Line Loop(90) = {-63,-10,64,14};
Ruled Surface(91) = {90};
Line Loop(92) = {-62,-11,63,15};
Ruled Surface(93) = {92};
Line Loop(94) = {-69,9,10,11,12};
Plane Surface(95) = {94};
Line Loop(96) = {16,68,13,14,15};
Plane Surface(97) = {96};
Surface Loop(98) = {95,-87,-85,-97,89,93,91};
Complex Volume(99) = {98};

/* inducteur */

Line Loop(100) = {-67,-21,-2,17};
Plane Surface(101) = {100};
Line Loop(102) = {-66,-22,67,18};
Ruled Surface(103) = {102};
Line Loop(104) = {-65,-23,66,19};
Ruled Surface(105) = {104};
Line Loop(106) = {-20,-65,24,7};
Plane Surface(107) = {106};
Line Loop(108) = {7,8,5,6};
Plane Surface(109) = {108};
Line Loop(110) = {1,2,3,4};
Plane Surface(111) = {110};
Line Loop(112) = {14,15,16,-8,-20,-19,-18,-17,-1,13};
Plane Surface(113) = {112};
Line Loop(114) = {11,12,6,-24,-23,-22,-21,3,9,10};
Plane Surface(115) = {114};
Surface Loop(116) = {91,93,89,-109,107,-113,-105,115,-103,-101,-111,-85};
Complex Volume(117) = {116};

/* air */
Line Loop(118) = {-35,-34,-33,30};
Plane Surface(119) = {118};
Line Loop(120) = {-41,-43,-42,-38,34,36};
Plane Surface(121) = {120};
Line Loop(122) = {33,38,47,29};
Plane Surface(123) = {122};
Line Loop(124) = {32,26,-31,-30,-29,27};
Plane Surface(125) = {124};
Line Loop(126) = {31,-37,-36,35};
Plane Surface(127) = {126};
Line Loop(128) = {-37,-41,44,26};
Line Loop(129) = {8,68,1,2,3,69,6,7};
Plane Surface(130) = {128,129};
Surface Loop(131) = {97,-113,-130,127,125,79,-77,121,123,119,-101,-103,-105,107,115,-95};
Complex Volume(132) = {131};

Physical Volume(500) = { 99 , 131 }; /* boite air + air */
Physical Volume(501) = { 83 }; /* tole */
Physical Volume(501) = { 117 }; /* ind */

Physical Surface(1000) = { 87 , 109 , 111 , 119 , 121 , 123 , 125 , 127 , 130 };
Physical Surface(700) = { 109 };
Physical Surface(701) = { 111 };







