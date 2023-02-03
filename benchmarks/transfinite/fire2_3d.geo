Geometry.Tolerance = 1.e-12;

// FireII Mesh 3D Case with centerline O-Grid
// Created by Pedro Santos in 12/06/2014

// The current values are for the 2nd Geomtry,
// but the file is general enough to be adapted for the others


// General descritpion of the axial layers
//
// ____________________________________________________________________________
// | Number | Name             |  Positioning   | Nn Poinsts  | Geometric     |
// |        |                  |                |             |  progression  |
// |________|__________________|________________|_____________|_______________|
// | 1.     | Boundary layer   |  [0   -> bl1]  | nBl         |  pBl          |
// | 2.     | Inner Layer      |  [bl1 -> bl2]  | nIn         |  pIn          |
// | 3.     | Transition layer |  [bl2 -> sh1]  | nTr         |  pTr          |
// | 4.     | Shock layer      |  [sh1 -> sh2]  | nSh         |  pSh          |
// | 5.     | Exit layer       |  [sh2 -> t  ]  | nEx         |  pEx          |
// |________|__________________|________________|_____________|_______________|
//
//

// General descritpion of the radial layers
//
// ___________________________________________________________________________________
// | Number | Name             |     Positioning       | Nn Poinsts  | Geometric     |
// |        |                  |                       |             |  progression  |
// |________|__________________|_______________________|_____________|_______________|
// | 1.     | Center Layer     |  [0       -> clAng ]  | nCl         |  pCl          |
// | 2.     | Inner Layer      |  [clAng   -> shldAng] | nIn_r       |  pIn_r        |
// | 3.     | Shouder layer    |  [shldAng -> extAng ] | nShld       |  pShld        |
// |________|__________________|_______________________|_____________|_______________|
//
//


// Units in meters
// Angles in radians

///////////////////////////////
//      Axial  Positions     //
///////////////////////////////
bl1 = 0.0033578 ;
bl2 = 0.03      ;
sh1 = 0.038     ;
sh2 = 0.044     ;
t   = 0.06      ;

//////////////////////////////
// Axial Number of Points   //
//////////////////////////////
nBl = 20 ;
nIn = 18 ;
nTr = 10 ;
nSh = 18 ;
nEx = 12 ;

//////////////////////////////////////
// Axial Geometric progression rate //
//////////////////////////////////////
pBl = 1.4405062; //1.2726587;
pIn = 1.;
pTr = 1.1;
pSh = 1. ;
pEx = 1.2;


///////////////////////////////
//     Radial  Positions     //
///////////////////////////////
clAng   = .1;
shldAng = .372988;
extAng = 0; //defined later


//////////////////////////////
// Radial Number of Points  //
//////////////////////////////
nCl   = 10 ;
nIn_r = 20 ;
nShld = 10;

///////////////////////////////////////
// Radial Geometric progression rate //
///////////////////////////////////////
pCl   = 1. ;
pIn_r = 1. ;
pShld = 1. ;

// dummy mesh parameter
dr    = .005;

Geometry.CopyMeshingMethod = 1;


// GEOMETRIC PARAMETERS

//Radius of curvature of the Capsule
r = .805;
rn = .036;


Point(100) = {r, 0. ,0., dr};

//First row of points
Point(1) = {-0.  , 0. , 0. , dr };
Point(2) = {-bl1 , 0. , 0. , dr };
Point(3) = {-bl2 , 0. , 0. , dr };
Point(4) = {-sh1 , 0. , 0. , dr };
Point(5) = {-sh2 , 0. , 0. , dr };
Point(6) = {-t   , 0. , 0. , dr };

//second row of points
Point(7 ) = { -(r + 0  ) * Cos(clAng) + r, (r + 0  ) * Sin(clAng) ,0., dr };
Point(8 ) = { -(r + bl1) * Cos(clAng) + r, (r + bl1) * Sin(clAng) ,0., dr };
Point(9 ) = { -(r + bl2) * Cos(clAng) + r, (r + bl2) * Sin(clAng) ,0., dr };
Point(10) = { -(r + sh1) * Cos(clAng) + r, (r + sh1) * Sin(clAng) ,0., dr };
Point(11) = { -(r + sh2) * Cos(clAng) + r, (r + sh2) * Sin(clAng) ,0., dr };
Point(12) = { -(r + t  ) * Cos(clAng) + r, (r + t  ) * Sin(clAng) ,0., dr };

//third row of points
Point(13) = { -(r + 0  ) * Cos(shldAng) + r, (r + 0  ) * Sin(shldAng) ,0., dr };
Point(14) = { -(r + bl1) * Cos(shldAng) + r, (r + bl1) * Sin(shldAng) ,0., dr };
Point(15) = { -(r + bl2) * Cos(shldAng) + r, (r + bl2) * Sin(shldAng) ,0., dr };
Point(16) = { -(r + sh1) * Cos(shldAng) + r, (r + sh1) * Sin(shldAng) ,0., dr };
Point(17) = { -(r + sh2) * Cos(shldAng) + r, (r + sh2) * Sin(shldAng) ,0., dr };
Point(18) = { -(r + t  ) * Cos(shldAng) + r, (r + t  ) * Sin(shldAng) ,0., dr };


//forth row of points
//center of curvature of the sholder bool
Point(101) ={ -(r-rn) * Cos(shldAng) + r + 0, (r-rn)*Sin(shldAng) +0. + 0.   ,0. ,dr  };
Point(19) = { -(r-rn) * Cos(shldAng) + r + 0, (r-rn)*Sin(shldAng) +rn + 0.   ,0. ,dr  };
Point(20) = { -(r-rn) * Cos(shldAng) + r + 0, (r-rn)*Sin(shldAng) +rn + bl1  ,0. ,dr  };

//extra parameters for controling the shock layer
sh22 = .414;
sh12 = sh22-(sh2-sh1)*1.5;
bl22 = sh22-(sh2-bl2)*1.6;
t22  = sh22 + (t-bl2);

Point(21) = {  -( (r - rn ) * Cos(shldAng) - r ), bl22, 0. ,dr  };
Point(22) = {  -( (r - rn ) * Cos(shldAng) - r ), sh12, 0. ,dr  };
Point(23) = {  -( (r - rn ) * Cos(shldAng) - r ), sh22, 0. ,dr  };
Point(24) = {  -( (r - rn ) * Cos(shldAng) - r ), t22 , 0. ,dr  };

//Add a B-spline between the inner points and its known derivatives
//In the case of a B-spline that means adding a control point that
//is the intersection of the lines defined by the points and its
// derivatives

x01  = -(r + t) * Cos(shldAng) + r;
y01  =  (r + t) * Sin(shldAng);
d21  = Cos(-132.15*Pi/180.);
d22  = Sin(-132.14*Pi/180.);
d11= Sin(shldAng);
d12= Cos(shldAng);
xpos = (r - rn ) * Cos(shldAng) - r ;

x01= -(r + bl2) * Cos(shldAng) + r ;
y01=  (r + bl2) * Sin(shldAng) ;
x02= -xpos;
y02= bl22;
t1 = (d21*(y01 - y02))/(d11*d22 - d12*d21) - (d22*(x01 - x02))/(d11*d22 - d12*d21);
t2 = (d11*(y01 - y02))/(d11*d22 - d12*d21) - (d12*(x01 - x02))/(d11*d22 - d12*d21);
x_intersection = x01 + d11*t1;
y_intersection = y01 + d12*t1;
Point(102) = {x_intersection, y_intersection, 0, dr};

x01= -(r + sh1) * Cos(shldAng) + r ;
y01=  (r + sh1) * Sin(shldAng) ;
x02= -xpos;
y02= sh12;
t1 = (d21*(y01 - y02))/(d11*d22 - d12*d21) - (d22*(x01 - x02))/(d11*d22 - d12*d21);
t2 = (d11*(y01 - y02))/(d11*d22 - d12*d21) - (d12*(x01 - x02))/(d11*d22 - d12*d21);
x_intersection = x01 + d11*t1;
y_intersection = y01 + d12*t1;
Point(103) = {x_intersection, y_intersection, 0, dr};

x01= -(r + sh2) * Cos(shldAng) + r;
y01=  (r + sh2) * Sin(shldAng);
x02= -xpos;
y02= sh22;
t1 = (d21*(y01 - y02))/(d11*d22 - d12*d21) - (d22*(x01 - x02))/(d11*d22 - d12*d21);
t2 = (d11*(y01 - y02))/(d11*d22 - d12*d21) - (d12*(x01 - x02))/(d11*d22 - d12*d21);
x_intersection = x01 + d11*t1;
y_intersection = y01 + d12*t1;
Point(104) = {x_intersection, y_intersection, 0, dr};

x01= -(r + t) * Cos(shldAng) + r;
y01=  (r + t) * Sin(shldAng);
x02= -xpos;
y02= t22;
t1 = (d21*(y01 - y02))/(d11*d22 - d12*d21) - (d22*(x01 - x02))/(d11*d22 - d12*d21);
t2 = (d11*(y01 - y02))/(d11*d22 - d12*d21) - (d12*(x01 - x02))/(d11*d22 - d12*d21);
x_intersection = x01 + d11*t1;
y_intersection = y01 + d12*t1;
Point(105) = {x_intersection, y_intersection, 0, dr};

/////////////////////////////////////
//first section geometric entities
/////////////////////////////////////
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 6};
Line(6) = {7, 8};
Line(7) = {8, 9};
Line(8) = {9, 10};
Line(9) = {10, 11};
Line(10) = {11, 12};
Circle(11) = {1, 100, 7 };
Circle(12) = {2, 100, 8 };
Circle(13) = {3, 100, 9 };
Circle(14) = {4, 100, 10};
Circle(15) = {5, 100, 11};
Circle(16) = {6, 100, 12};

Line Loop(1) = {11, 6, -12, -1};
Plane Surface(1) = {1};
Line Loop(2) = {12, 7, -13, -2};
Plane Surface(2) = {2};
Line Loop(3) = {13, 8, -14, -3};
Plane Surface(3) = {3};
Line Loop(4) = {14, 9, -15, -4};
Plane Surface(4) = {4};
Line Loop(5) = {15, 10, -16, -5};
Plane Surface(5) = {5};

/////////////////////////////////////
// second section geometric entities
/////////////////////////////////////
Circle(17) = {7 , 100, 13};
Circle(18) = {8 , 100, 14};
Circle(19) = {9 , 100, 15};
Circle(20) = {10, 100, 16};
Circle(21) = {11, 100, 17};
Circle(22) = {12, 100, 18};
Line(23) = {13, 14};
Line(24) = {14, 15};
Line(25) = {15, 16};
Line(26) = {16, 17};
Line(27) = {17, 18};

Line Loop(6) = {17, 23, -18, -6};
Plane Surface(6) = {6};
Line Loop(7) = {18, 24, -19, -7};
Plane Surface(7) = {7};
Line Loop(8) = {19, 25, -20, -8};
Plane Surface(8) = {8};
Line Loop(9) = {20, 26, -21, -9};
Plane Surface(9) = {9};
Line Loop(10) = {21, 27, -22, -10};
Plane Surface(10) = {10};

/////////////////////////////////////
// third section geometric entities
/////////////////////////////////////
Circle(28) = {13, 101, 19};
Circle(29) = {14, 101, 20};
BSpline(30) = {15, 102, 21};
BSpline(31) = {16, 103, 22};
BSpline(32) = {17, 104, 23};
BSpline(33) = {18, 105, 24};
Line(34) = {19, 20};
Line(35) = {20, 21};
Line(36) = {21, 22};
Line(37) = {22, 23};
Line(38) = {23, 24};

Line Loop(11) = {28, 34, -29, -23};
Plane Surface(11) = {11};
Line Loop(12) = {29, 35, -30, -24};
Plane Surface(12) = {12};
Line Loop(13) = {30, 36, -31, -25};
Plane Surface(13) = {13};
Line Loop(14) = {31, 37, -32, -26};
Plane Surface(14) = {14};
Line Loop(15) = {32, 38, -33, -27};
Plane Surface(15) = {15};

//////////////////////////////////////
// Transfinite Definitions
//////////////////////////////////////

//Radial Transfinites
Transfinite Line{11,12,13,14,15,16} = nCl Using Progression pCl;
Transfinite Line{17,18,19,20,21,22} = nIn_r Using Progression pIn_r;
Transfinite Line{28,29,30,31,32,33} = nShld Using Progression pShld;

//Axial Transfinites
Transfinite Line{1,6 ,23,34} = nBl Using Progression pBl;
Transfinite Line{2,7 ,24,35} = nIn Using Progression pIn;
Transfinite Line{3,8 ,25,36} = nTr Using Progression pTr;
Transfinite Line{4,9 ,26,37} = nSh Using Progression pSh;
Transfinite Line{5,10,27,38} = nEx Using Progression pEx;


//////////////////////////////////////////////////////////////////////////////
//  3D CONSTRUCTION
//////////////////////////////////////////////////////////////////////////////

Point(106) = { -(r + 0  ) * Cos(shldAng) + r, 0. ,0., dr };
Point(107) = { -(r + bl1) * Cos(shldAng) + r, 0. ,0., dr };
Point(108) = { -(r + bl2) * Cos(shldAng) + r, 0. ,0., dr };
Point(109) = { -(r + sh1) * Cos(shldAng) + r, 0. ,0., dr };
Point(110) = { -(r + sh2) * Cos(shldAng) + r, 0. ,0., dr };
Point(111) = { -(r + t  ) * Cos(shldAng) + r, 0. ,0., dr };
Point(112) = { -(r - rn ) * Cos(shldAng) + r, 0. ,0., dr};


Rotate {{1, 0, 0}, {0, 0, 0}, Pi/4} {
  Duplicata { Surface{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; }
}

Rotate {{1, 0, 0}, {0, 0, 0}, Pi/2} {
  Duplicata { Surface{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; }
}

Delete {
  Surface{39, 44, 49, 54, 59};
}
Delete {
  Line{40, 42, 47, 52, 57, 62};
}
Delete {
  Surface{84, 74, 79, 69, 64};
}
Delete {
  Line{87, 82, 77, 72, 67, 65};
}
thetaRot = Atan2( 2^.5 * r * Sin(clAng), r );

Rotate {{0, 1, -1}, {r, 0, 0}, thetaRot-clAng} {
  Point{115, 119, 137, 155, 173, 191};
}


Circle(187) = {115, 100, 205};
Circle(188) = {119, 100, 209};
Circle(189) = {137, 100, 227};
Circle(190) = {155, 100, 245};
Circle(191) = {173, 100, 263};
Circle(192) = {191, 100, 281};
Line Loop(193) = {187, 66, -188, -41};
Plane Surface(194) = {193};
Line Loop(195) = {188, 71, -189, -46};
Plane Surface(196) = {195};
Line Loop(197) = {189, 76, -190, -51};
Plane Surface(198) = {197};
Line Loop(199) = {190, 81, -191, -56};
Plane Surface(200) = {199};
Line Loop(201) = {191, 86, -192, -61};
Plane Surface(202) = {201};
Circle(203) = {7, 100, 115};
Circle(204) = {8, 100, 119};
Circle(205) = {9, 100, 137};
Circle(206) = {10, 100, 155};
Circle(207) = {11, 100, 173};
Circle(208) = {12, 100, 191};
Circle(209) = {115, 100, 378};
Circle(210) = {119, 100, 382};
Circle(211) = {137, 100, 400};
Circle(212) = {155, 100, 418};
Circle(213) = {173, 100, 436};
Circle(214) = {191, 100, 454};
Line Loop(215) = {203, 41, -204, -6};
Plane Surface(216) = {215};
Line Loop(217) = {204, 46, -205, -7};
Plane Surface(218) = {217};
Line Loop(219) = {205, 51, -206, -8};
Plane Surface(220) = {219};
Line Loop(221) = {206, 56, -207, -9};
Plane Surface(222) = {221};
Line Loop(223) = {207, 61, -208, -10};
Plane Surface(224) = {223};
Line Loop(225) = {209, 115, -210, -41};
Plane Surface(226) = {225};
Line Loop(227) = {210, 120, -211, -46};
Plane Surface(228) = {227};
Line Loop(229) = {211, 125, -212, -51};
Plane Surface(230) = {229};
Line Loop(231) = {212, 130, -213, -56};
Plane Surface(232) = {231};
Line Loop(233) = {213, 135, -214, -61};
Plane Surface(234) = {233};
Line Loop(235) = {209, -114, 11, 203};
Plane Surface(236) = {235};
Line Loop(237) = {116, 12, 204, 210};
Plane Surface(238) = {237};
Line Loop(239) = {121, 13, 205, 211};
Plane Surface(240) = {239};
Line Loop(241) = {14, 206, 212, 126};
Plane Surface(242) = {241};
Line Loop(243) = {15, 207, 213, 131};
Plane Surface(244) = {243};
Line Loop(245) = {136, 16, 208, 214};
Plane Surface(246) = {245};
Circle(247) = {19, 112, 295};
Circle(248) = {20, 112, 299};
Circle(249) = {21, 112, 317};
Circle(250) = {22, 112, 335};
Circle(251) = {23, 112, 353};
Circle(252) = {24, 112, 371};
Circle(253) = {13, 106, 205};
Circle(254) = {14, 107, 209};
Circle(255) = {15, 108, 227};
Circle(256) = {16, 109, 245};
Circle(257) = {17, 110, 263};
Circle(258) = {18, 111, 281};
Circle(259) = {295, 112, 558};
Circle(260) = {299, 112, 562};
Circle(261) = {317, 112, 580};
Circle(262) = {335, 112, 598};
Circle(263) = {353, 112, 616};
Circle(264) = {371, 112, 634};
Circle(265) = {205, 106, 468};
Circle(266) = {209, 107, 472};
Circle(267) = {227, 108, 490};
Circle(268) = {245, 109, 508};
Circle(269) = {263, 110, 526};
Circle(270) = {281, 111, 544};
Line Loop(271) = {252, -111, -251, 38};
Surface(272) = {271};
Line Loop(273) = {251, -106, -250, 37};
Surface(274) = {273};
Line Loop(275) = {250, -101, -249, 36};
Surface(276) = {275};
Line Loop(277) = {249, -96, -248, 35};
Surface(278) = {277};
Line Loop(279) = {248, -91, -247, 34};
Surface(280) = {279};
Line Loop(281) = {28, 247, -90, -253};
Surface(282) = {281};
Line Loop(283) = {29, 248, 92, -254};
Surface(284) = {283};
Line Loop(285) = {30, 249, 97, -255};
Surface(286) = {285};
Line Loop(287) = {32, 251, 107, -257};
Surface(288) = {287};
Line Loop(289) = {260, -165, -259, 91};
Surface(290) = {289};
Line Loop(291) = {96, 261, -170, -260};
Surface(292) = {291};
Line Loop(293) = {-261, -175, 262, 101};
Surface(294) = {293};
Line Loop(295) = {-262, -180, 263, 106};
Surface(296) = {295};
Line Loop(297) = {-263, -185, 264, 111};
Surface(298) = {297};
Line Loop(299) = {259, -164, -265, 90};
Surface(300) = {299};
Line Loop(301) = {-266, 166, 260, -92};
Surface(302) = {301};
Line Loop(303) = {-97, -267, 171, 261};
Surface(304) = {303};
Line Loop(305) = {-268, 176, 262, -102};
Surface(306) = {305};
Line Loop(307) = {-269, 181, 263, -107};
Surface(308) = {307};
Line Loop(309) = {-270, 186, 264, -112};
Surface(310) = {309};
Line Loop(313) = {253, 66, -254, -23};
Surface(314) = {313};
Line Loop(315) = {254, 71, -255, -24};
Surface(316) = {315};
Line Loop(317) = {255, 76, -256, -25};
Surface(318) = {317};
Line Loop(319) = {256, 81, -257, -26};
Surface(320) = {319};
Line Loop(321) = {257, 86, -258, -27};
Surface(322) = {321};
Line Loop(323) = {265, 140, -266, -66};
Surface(324) = {323};
Line Loop(325) = {266, 145, -267, -71};
Surface(326) = {325};
Line Loop(327) = {267, 150, -268, -76};
Surface(328) = {327};
Line Loop(329) = {268, 155, -269, -81};
Surface(330) = {329};
Line Loop(331) = {269, 160, -270, -86};
Surface(332) = {331};
Line Loop(333) = {17, 253, -187, -203};
Surface(334) = {333};
Line Loop(335) = {-204, -188, 254, 18};
Surface(336) = {335};
Line Loop(337) = {19, 255, -189, -205};
Surface(339) = {337};
Line Loop(340) = {20, 256, -190, -206};
Surface(341) = {340};
Line Loop(342) = {21, 257, -191, -207};
Surface(343) = {342};
Line Loop(344) = {22, 258, -192, -208};
Surface(345) = {344};
Line Loop(346) = {187, 265, -139, -209};
Surface(347) = {346};
Line Loop(348) = {188, 266, 141, -210};
Surface(349) = {348};
Line Loop(350) = {189, 267, 146, -211};
Surface(351) = {350};
Line Loop(352) = {191, 269, 156, -213};
Surface(353) = {352};
Line Loop(354) = {192, 270, 161, -214};
Surface(355) = {354};

Transfinite Line {254, 251, 252, 249, 250, 264, 263, 262, 261, 247, 248, 260, 259, 265, 265, 266, 267, 269, 268, 270, 209, 210, 211, 212, 204, 203, 205, 213, 214, 206, 207, 208, 116, 114, 121, 126, 131, 136, 11, 12, 13, 14, 15, 16, 253, 255, 256, 257, 258} = nCl Using Progression pCl;

Transfinite Line {61} = nEx Using Progression pEx;
Transfinite Line {46} = nIn Using Progression pIn;
Transfinite Line {187, 188, 189, 190, 191, 192} = nIn_r Using Progression pIn_r;

Surface Loop(356) = {1, 236, 113, 216, 226, 238};
Volume(357) = {356};
Surface Loop(358) = {238, 240, 2, 118, 218, 228};
Volume(359) = {358};
Surface Loop(360) = {123, 3, 220, 230, 240, 242};
Volume(361) = {360};
Surface Loop(362) = {242, 244, 128, 4, 232, 222};
Volume(363) = {362};
Surface Loop(364) = {224, 5, 246, 133, 234, 244};
Volume(365) = {364};
Surface Loop(366) = {334, 6, 314, 336, 216, 194};
Volume(367) = {366};
Surface Loop(368) = {336, 339, 196, 7, 316, 218};
Volume(369) = {368};
Surface Loop(370) = {339, 341, 198, 8, 318, 220};
Volume(371) = {370};
Surface Loop(372) = {343, 341, 9, 200, 320, 222};
Volume(373) = {372};
Surface Loop(374) = {343, 10, 345, 322, 202, 224};
Volume(375) = {374};
Surface Loop(376) = {282, 11, 280, 284, 314, 89};
Volume(377) = {376};
Surface Loop(378) = {286, 278, 12, 284, 316, 94};
Volume(379) = {378};
Line Loop(380) = {250, 102, -256, 31};
Surface(381) = {380};
Line Loop(382) = {112, -258, 33, 252};
Surface(383) = {382};
Surface Loop(384) = {286, 381, 276, 13, 99, 318};
Volume(385) = {384};
Surface Loop(386) = {274, 14, 104, 320, 381, 288};
Volume(387) = {386};
Surface Loop(388) = {288, 383, 15, 272, 109, 322};
Volume(389) = {388};
Surface Loop(390) = {300, 290, 163, 302, 324, 89};
Volume(391) = {390};
Surface Loop(392) = {292, 168, 304, 302, 94, 326};
Volume(393) = {392};
Surface Loop(394) = {294, 173, 306, 304, 328, 99};
Volume(395) = {394};
Surface Loop(396) = {104, 296, 178, 306, 308, 330};
Volume(397) = {396};
Surface Loop(398) = {298, 310, 183, 109, 308, 332};
Volume(399) = {398};
Surface Loop(400) = {138, 347, 349, 194, 324, 226};
Volume(401) = {400};
Surface Loop(402) = {143, 228, 351, 349, 196, 326};
Volume(403) = {402};
Line Loop(404) = {151, -212, 190, 268};
Surface(405) = {404};
Surface Loop(406) = {351, 405, 148, 328, 198, 230};
Volume(407) = {406};
Surface Loop(408) = {405, 353, 200, 153, 232, 330};
Volume(409) = {408};
Surface Loop(410) = {158, 355, 353, 332, 234, 202};
Volume(411) = {410};


Recombine Surface {:};
Transfinite Surface {:};
Transfinite Volume {:};
