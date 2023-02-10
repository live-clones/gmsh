

//**** Definition of points

p1 = newp;
Point(p1+1) ={   0.0000,  -2.0940,   1.4490,   0.500};
Point(p1+2) ={   1.1080,  -2.0940,   1.4490,   0.500};
Point(p1+3) ={   0.5540,  -2.0940,   2.4086,   0.500};
Point(p1+4) ={  -0.5540,  -2.0940,   2.4086,   0.500};
Point(p1+5) ={  -1.1080,  -2.0940,   1.4490,   0.500};
Point(p1+6) ={  -0.5540,  -2.0940,   0.4894,   0.500};
Point(p1+7) ={   0.5540,  -2.0940,   0.4894,   0.500};
Point(p1+8) ={   0.0000, -10.4040,   1.4490,   0.500};
Point(p1+9) ={   1.1080, -10.4040,   1.4490,   0.500};
Point(p1+10) ={   0.5540, -10.4040,   2.4086,   0.500};
Point(p1+11) ={  -0.5540, -10.4040,   2.4086,   0.500};
Point(p1+12) ={  -1.1080, -10.4040,   1.4490,   0.500};
Point(p1+13) ={  -0.5540, -10.4040,   0.4894,   0.500};
Point(p1+14) ={   0.5540, -10.4040,   0.4894,   0.500};

lref =  0.2015;

//**** Definition of lines

line1 = 100;

Line(line1+14) ={p1+  2,p1+  9};
Line(line1+17) ={p1+  5,p1+ 12};

p1 = newp;

Point (p1+  1)={  2.8559,  0.9391,  0.6751, 0.10};
Point (p1+  2)={  1.6943,  0.4638,  0.4542, 0.10};
Point (p1+  3)={  2.1772, -0.7156,  0.4523, 0.10};
Point (p1+  4)={  3.3386, -0.2404,  0.6750, 0.10};
Point (p1+  5)={  2.5166,  0.1118,  0.5637, 0.10};
Point (p1+  6)={  2.8578,  0.9398,  0.6636, 0.10};
Point (p1+  7)={  1.6962,  0.4645,  0.4426, 0.10};
Point (p1+  8)={  2.1791, -0.7148,  0.4408, 0.10};
Point (p1+  9)={  3.3404, -0.2396,  0.6635, 0.10};
Point (p1+ 10)={  2.5185,  0.1125,  0.5522, 0.10};
//+

p1 = newp;

Point (p1+  1)={ -4.0600,  0.0040,  0.8471, 0.10};
Point (p1+  2)={ -2.8859, -1.1884,  0.6386, 0.10};
Point (p1+  3)={ -1.7126,  0.0040,  0.4260, 0.10};
Point (p1+  4)={ -2.8859,  1.1964,  0.6386, 0.10};
Point (p1+  5)={ -2.8863,  0.0040,  0.6366, 0.10};
Point (p1+  6)={ -4.0650,  0.0040,  0.8186, 0.10};
Point (p1+  7)={ -2.8910, -1.1884,  0.6101, 0.10};
Point (p1+  8)={ -1.7177,  0.0040,  0.3976, 0.10};
Point (p1+  9)={ -2.8910,  1.1964,  0.6101, 0.10};
Point (p1+ 10)={ -2.8914,  0.0040,  0.6081, 0.10};

p1 = newp;

Point (p1+  1)={ 1, 0.928,2.775, 0.50};
Point (p1+  2)={ 1,-0.928,2.775, 0.50};
Point (p1+  3)={-1,-0.928,2.775, 0.50};
Point (p1+  4)={-1, 0.928,2.775, 0.50};
Point (p1+  5)={ 1, 0.928,0.317, 0.50};
Point (p1+  6)={ 1,-0.928,0.317, 0.50};
Point (p1+  7)={-1,-0.928,0.317, 0.50};
Point (p1+  8)={-1, 0.928,0.317, 0.50};

p1 = newp;



//// FAR FIELD
Point (p1+  1)={ 4.5,  2.44,  4, 0.50};
Point (p1+  2)={ 4.5,-11.80,  4, 0.50};
Point (p1+  3)={-4.86,-11.8,  4, 0.50};
Point (p1+  4)={-4.86, 2.44,  4, 0.50};

Point (p1+  5)={ 4.5,  2.44,-0.91, 0.50};
Point (p1+  6)={ 4.5,-11.80,-0.91, 0.50};
Point (p1+  7)={-4.86,-11.8,-0.91, 0.50};
Point (p1+  8)={-4.86, 2.44,-0.91, 0.50};//+
Coherence;

//Merge "punti_motore.geo";


/////////////////////////////////////////////////////
p1 = newp;

Point (p1+  1)={  1.1904, -0.9327,  1.4885, 0.10};
Point (p1+  2)={  1.1484, -0.9720,  1.5460, 0.10};
Point (p1+  3)={  1.1063, -1.0111,  1.4885, 0.10};
Point (p1+  4)={  1.1484, -0.9720,  1.4310, 0.10};
Point (p1+  5)={  1.1484, -0.9719,  1.4885, 0.10};

Point (p1+  6)={  1.1221, -0.8596,  1.4885, 0.10};
Point (p1+  7)={  1.0801, -0.8989,  1.5460, 0.10};
Point (p1+  8)={  1.0380, -0.9380,  1.4885, 0.10};
Point (p1+  9)={  1.0801, -0.8989,  1.4310, 0.10};
Point (p1+ 10)={  1.0801, -0.8988,  1.4885, 0.10};

Point (p1+ 11)={  1.1688, -0.9528,  1.4885, 0.10};
Point (p1+ 12)={  1.1484, -0.9719,  1.5165, 0.10};
Point (p1+ 13)={  1.1279, -0.9910,  1.4885, 0.10};
Point (p1+ 14)={  1.1484, -0.9719,  1.4605, 0.10};

Point (p1+ 15)={  1.1849, -0.9378,  1.4885, 0.10};
Point (p1+ 16)={  1.1484, -0.9720,  1.5385, 0.10};
Point (p1+ 17)={  1.1118, -1.0060,  1.4885, 0.10};
Point (p1+ 18)={  1.1484, -0.9720,  1.4385, 0.10};

/////////////////////////////////////////////////////


Coherence;

//+
Circle(118) = {18, 21, 17};
//+
Circle(119) = {17, 21, 20};
//+
Circle(120) = {20, 21, 19};
//+
Circle(121) = {19, 21, 18};
//+
Circle(122) = {23, 26, 22};
//+
Circle(123) = {22, 26, 25};
//+
Circle(124) = {25, 26, 24};
//+
Circle(125) = {24, 26, 23};
//+
Circle(126) = {58, 61, 57};
//+
Circle(127) = {57, 61, 60};
//+
Circle(128) = {60, 61, 59};
//+
Circle(129) = {59, 61, 58};
//+
Circle(130) = {72, 61, 71};
//+
Circle(131) = {71, 61, 74};
//+
Circle(132) = {74, 61, 73};
//+
Circle(133) = {73, 61, 72};
//+
Circle(134) = {68, 61, 67};
//+
Circle(135) = {67, 61, 70};
//+
Circle(136) = {70, 61, 69};
//+
Circle(137) = {69, 61, 68};
//+
Circle(138) = {63, 66, 62};
//+
Circle(139) = {62, 66, 65};
//+
Circle(140) = {65, 66, 64};
//+
Circle(141) = {64, 66, 63};
//+
Line(142) = {63, 58};
//+
Line(143) = {62, 57};
//+
Line(144) = {65, 60};
//+
Line(145) = {64, 59};
//+
Line(146) = {49, 50};
//+
Line(147) = {50, 51};
//+
Line(148) = {51, 48};
//+
Line(149) = {48, 49};
//+
Line(150) = {55, 54};
//+
Line(151) = {54, 53};
//+
Line(152) = {53, 52};
//+
Line(153) = {52, 55};
//+
Line(154) = {51, 55};
//+
Line(155) = {50, 54};
//+
Line(156) = {49, 53};
//+
Line(157) = {48, 52};
//+
Line(158) = {13, 10};
//+
Line(159) = {6, 3};
//+
Delete {
  Point{4, 2, 5, 7, 8, 12, 11, 9, 14, 15};
}
//+
Circle(161) = {31, 32, 30};
//+
Circle(162) = {30, 32, 29};
//+
Circle(163) = {29, 32, 28};
//+
Circle(164) = {28, 32, 31};
//+
Circle(165) = {36, 37, 35};
//+
Circle(166) = {35, 37, 34};
//+
Circle(167) = {34, 37, 33};
//+
Circle(168) = {33, 37, 36};
//+
Line(169) = {36, 31};
//+
Line(170) = {35, 30};
//+
Line(171) = {34, 29};
//+
Line(172) = {33, 28};
//+
Line(173) = {17, 22};
//+
Line(174) = {20, 25};
//+
Line(175) = {19, 24};
//+
Line(176) = {18, 23};
//+

//+

Coherence;




//+
Delete {
  Line{148, 153, 157, 149, 152, 156, 146, 151, 155, 147, 150, 154};
}
//+
Delete {
  Point{48, 51, 55, 54, 50, 53, 49, 52};
}
//+
Line(177) = {39, 40};
//+
Line(178) = {40, 41};
//+
Line(179) = {41, 42};
//+
Line(180) = {42, 39};
//+
Line(181) = {39, 43};
//+
Line(182) = {43, 44};
//+
Line(183) = {44, 45};
//+
Line(184) = {45, 46};
//+
Line(185) = {46, 43};
//+
Line(186) = {41, 45};
//+
Line(187) = {40, 44};
//+
Line(188) = {42, 46};
//+
Translate {0, 0, -0.015} {
  Duplicata { Line{159, 114, 117, 158}; }
}
//+
Line(193) = {76, 3};
//+
Line(194) = {10, 80};
//+
Line(195) = {84, 13};
//+
Line(196) = {6, 75};
//+
Line Loop(197) = {187, 183, -186, -178};
//+
Plane Surface(198) = {197};
//+
Line Loop(199) = {186, 184, -188, -179};
//+
Plane Surface(200) = {199};
//+
Line Loop(201) = {180, 181, -185, -188};
//+
Plane Surface(202) = {201};
//+
Line Loop(203) = {181, 182, -187, -177};
//+
Plane Surface(204) = {203};
//+
Line Loop(205) = {182, 183, 184, 185};
//+
Plane Surface(206) = {205};
//+
Line Loop(207) = {179, 180, 177, 178};
//+
Plane Surface(208) = {207};
//+
Line Loop(209) = {134, 135, 136, 137};
//+
Plane Surface(210) = {209};
//+
Line Loop(211) = {130, 131, 132, 133};
//+
Line(212) = {68, 72};
//+
Line(213) = {71, 67};
//+
Line(214) = {69, 73};
//+
Line(215) = {70, 74};
//+
Line Loop(216) = {130, 213, -134, 212};
//+
Plane Surface(217) = {216};
//+
Line Loop(218) = {213, 135, 215, -131};
//+
Plane Surface(219) = {218};
//+
Line Loop(220) = {215, 132, -214, -136};
//+
Plane Surface(221) = {220};
//+
Line Loop(222) = {214, 133, -212, -137};
//+
Plane Surface(223) = {222};
//+
Line Loop(224) = {129, 126, 127, 128};
//+
Plane Surface(225) = {211, 224};
//+
Line Loop(226) = {138, 139, 140, 141};
//+
Plane Surface(227) = {226};
//+
Line Loop(228) = {142, 126, -143, -138};
//+
Surface(229) = {228};
//+
Line Loop(230) = {143, 127, -144, -139};
//+
Surface(231) = {230};
//+
Line Loop(232) = {144, 128, -145, -140};
//+
Surface(233) = {232};
//+
Line Loop(234) = {141, 142, -129, -145};
//+
Surface(235) = {234};
//+
Line Loop(236) = {118, 119, 120, 121};
//+
Plane Surface(237) = {236};
//+
Line Loop(238) = {125, 122, 123, 124};
//+
Plane Surface(239) = {238};
//+
Line Loop(240) = {119, 174, -123, -173};
//+
Surface(241) = {240};
//+
Line Loop(242) = {120, 175, -124, -174};
//+
Surface(243) = {242};
//+
Line Loop(244) = {121, 176, -125, -175};
//+
Surface(245) = {244};
//+
Line Loop(246) = {118, 173, -122, -176};
//+
Surface(247) = {246};
//+
Line Loop(248) = {171, 163, -172, -167};
//+
Surface(249) = {248};
//+
Line Loop(250) = {164, -169, -168, 172};
//+
Surface(251) = {250};
//+
Line Loop(252) = {161, -170, -165, 169};
//+
Surface(253) = {252};
//+
Line Loop(254) = {162, -171, -166, 170};
//+
Surface(255) = {254};
//+
Line Loop(256) = {163, 164, 161, 162};
//+
Plane Surface(257) = {256};
//+
Line Loop(258) = {166, 167, 168, 165};
//+
Plane Surface(259) = {258};
//+
Line Loop(260) = {159, 114, -158, -117};
//+
Plane Surface(261) = {260};
//+
Line Loop(262) = {189, 190, -192, -191};
//+
Plane Surface(263) = {262};
//+
Line Loop(264) = {117, -195, -191, -196};
//+
Plane Surface(265) = {264};
//+
Line Loop(266) = {159, -193, -189, -196};
//+
Plane Surface(267) = {266};
//+
Line Loop(268) = {114, 194, -190, 193};
//+
Plane Surface(269) = {268};
//+
Line Loop(270) = {158, 194, -192, 195};
//+
Plane Surface(271) = {270};
//+
Physical Surface(300) = {257, 259, 253, 251, 249, 255};
//+
Physical Surface(301) = {204, 208, 202, 200, 206, 198};
//+
Physical Surface(302) = {261};
//+
Physical Surface(303) = {263, 269, 267, 265, 271};
//+
Physical Surface(304) = {225, 210, 229, 235, 233, 231, 227};
//+
Physical Surface("Source", 305) = {217, 223, 221, 219};
//+
Transfinite Line {213, 212, 214, 215} = 3 Using Progression 1;
//+
Transfinite Line {134, 135, 137, 136} = 5 Using Progression 1;
//+
Transfinite Line {130, 131, 127, 126, 129, 133, 132, 128} = 7 Using Progression 1;
//+
Transfinite Line {142, 143, 144, 145} = 4 Using Progression 1;
//+
Transfinite Line {140, 141, 139, 138} = 5 Using Progression 1;
//+
Transfinite Line {178, 177, 180, 179, 181, 182, 185, 186, 187, 183, 184, 188} = 13 Using Progression 1;
Transfinite Line {180, 179, 185, 184, 188} = 10 Using Progression 1;

//+
Transfinite Line {162, 166, 167, 163, 161, 165, 164, 168} = 11 Using Progression 1;
//+
Transfinite Line {159, 189} = 15 Using Progression 1;
//+
Transfinite Line {114, 190, 117, 191} = 31 Using Progression 1.04;


////////////////////////////////////////////////////////////

p1 = newp;

Point (p1+  1)={  0.0000,  0.0000,  0.0000, 0.10};
Point (p1+  2)={ -5.0000,  0.0000,  0.0000, 0.10};
Point (p1+  3)={ -1.7101,  0.0000,  0.0000, 0.10};
Point (p1+  4)={ -1.7101,  0.0000,  4.6985, 0.10};
Point (p1+  5)={ -1.7101, -4.6985, -0.0000, 0.10};
Point (p1+  6)={ -1.7101,  0.0000, -4.6985, 0.10};
Point (p1+  7)={ -1.7101,  4.6985, -0.0000, 0.10};

Point (p1+  8)={  5.8530,  0.0000,  0.0000, 0.10};
Point (p1+  9)={ 12.8548,  0.0000,  0.0000, 0.10};
Point (p1+ 10)={  3.4582,  0.0000,  0.0000, 0.10};
Point (p1+ 11)={  3.4582,  0.0000,  6.5796, 0.10};
Point (p1+ 12)={  3.4582, -6.5796, -0.0000, 0.10};
Point (p1+ 13)={  3.4582,  0.0000, -6.5796, 0.10};
Point (p1+ 14)={  3.4582,  6.5796, -0.0000, 0.10};

 //////////////////////////

  //////////////////////////

 Rotate {{    0.0000,    0.0000,    1.0000},
         {    0.0000,    0.0000,    0.0000},   -1.0472 } {
 Point{p1+2, p1+3, p1+1, p1+7,p1+ 4,
 p1+5, p1+6, p1+11,p1+ 14,p1+13,
 p1+ 12,p1+ 10, p1+8, p1+9};}

  //////////////////////////

 Translate {    0.1484,    0.0281,    1.4885} {
 Point{p1+1, p1+3, p1+2, p1+4, p1+5,
 p1+6, p1+7, p1+10, p1+8, p1+9,
p1+11, p1+12, p1+14, p1+13};}


l1 = newreg;
Circle(l1+1) = {p1+2, p1+1, p1+4};
Circle(l1+2) = {p1+2, p1+1, p1+6};
Circle(l1+3) = {p1+11, p1+8, p1+9};
Circle(l1+4) = {p1+9, p1+8, p1+13};
Line(l1+5) = {p1+4, p1+11};
Line(l1+6) = {p1+6, p1+13};
Line(l1+7) = {p1+5, p1+12};
Line(l1+8) = {p1+7, p1+14};
Circle(l1+9) = {p1+2, p1+1, p1+7};
Circle(l1+10) = {p1+2, p1+1, p1+5};
Circle(l1+11) = {p1+14, p1+8, p1+9};
Circle(l1+12) = {p1+9, p1+8, p1+12};
Circle(l1+13) = {p1+4, p1+3, p1+7};
Circle(l1+14) = {p1+7, p1+3, p1+6};
Circle(l1+15) = {p1+6, p1+3, p1+5};
Circle(l1+16) = {p1+5, p1+3,p1+ 4};
Circle(l1+17) = {p1+11,p1+10,p1+ 14};
Circle(l1+18) = {p1+14,p1+ 10, p1+13};
Circle(l1+19) = {p1+13,p1+ 10,p1+ 12};
Circle(l1+20) = {p1+12, p1+10,p1+ 11};
//+
Line Loop(327) = {322, -307, 316};
//+
Surface(328) = {327};
//+
Line Loop(329) = {319, -315, 307};
//+
Surface(330) = {329};
//+
Line Loop(331) = {320, -308, 315};
//+
Surface(332) = {331};
//+
Line Loop(333) = {321, -316, 308};
//+
Surface(334) = {333};
//+
Line Loop(335) = {309, -317, -323};
//+
Surface(336) = {335};
//+
Line Loop(337) = {317, 310, -324};
//+
Surface(338) = {337};
//+
Line Loop(339) = {325, -318, 310};
//+
Surface(340) = {339};
//+
Line Loop(341) = {326, 309, 318};
//+
Surface(342) = {341};
//+
Line Loop(343) = {314, -323, -311, 319};
//+
Surface(344) = {343};
//+
Line Loop(345) = {320, 312, -324, -314};
//+
Surface(346) = {345};
//+
Line Loop(347) = {321, 313, -325, -312};
//+
Surface(348) = {347};
//+
Line Loop(349) = {326, -311, -322, 313};
//+
Surface(350) = {349};
//+
Transfinite Line {311, 314, 308, 313, 312} = 21 Using Progression 1.0;
Transfinite Line {310, 318} = 19 Using Progression 0.90;
Transfinite Line {317, 309} = 19 Using Progression 1.111;
//+
Transfinite Line {322, 319, 320, 321} = 21 Using Progression 1.0;
Transfinite Line {325, 326, 323, 324} = 25 Using Progression 1.0;
//+
Transfinite Line {316, 308, 307, 315} = 13 Using Progression 0.90;
//+
Surface Loop(351) = {336, 342, 350, 344, 346, 332, 334, 348, 340, 338, 328, 330};
//+
Surface Loop(352) = {261, 267, 269, 271, 263, 265};
//+
Surface Loop(353) = {257, 249, 255, 259, 251, 253};
//+
Surface Loop(354) = {208, 200, 198, 204, 202, 206};
//+
Surface Loop(355) = {239, 245, 237, 247, 241, 243};
//+
Surface Loop(356) = {235, 227, 229, 225, 217, 219, 210, 221, 223, 233, 231};
//+





//+
Delete {
  Surface{225, 223, 221, 219, 217, 210};
}
//+
Delete {
  Line{133, 130, 212, 134, 137, 214, 136, 215, 135, 131, 132, 213};
}
//+
Delete {
  Point{74, 70, 61, 68, 72, 71, 67, 69, 73};
}
//+
Delete {
  Surface{235, 229, 231, 233};
}
//+
Delete {
  Line{129, 126, 127, 128};
}
//+
Delete {
  Line{142, 143, 144, 145};
}
//+
Delete {
  Point{58, 57, 60, 59};
}
//+
Delete {
  Point{61};
}

SyncModel;

//Merge "thruster.geo";


///////////////////////////////////////////////////////////////////////////////////////////
//**** Definition of points

p1 = newp;

lref= 0.070;
Point(p1+1) ={   1.1484,  -0.9719,   1.4885, lref};
Point(p1+2) ={   1.1689,  -0.9528,   1.4885, lref};
Point(p1+3) ={   1.1484,  -0.9719,   1.5165, lref};
Point(p1+4) ={   1.1279,  -0.9910,   1.4885, lref};
Point(p1+5) ={   1.1484,  -0.9719,   1.4605, lref};
Point(p1+6) ={   1.1850,  -0.9378,   1.4885, lref};
Point(p1+7) ={   1.1484,  -0.9719,   1.5385, lref};
Point(p1+8) ={   1.1118,  -1.0060,   1.4885, lref};
Point(p1+9) ={   1.1484,  -0.9719,   1.4385, lref};
Point(p1+10) ={   1.1996,  -0.9242,   1.4885, lref};
Point(p1+11) ={   1.1484,  -0.9719,   1.5585, lref};
Point(p1+12) ={   1.0972,  -1.0196,   1.4885, lref};
Point(p1+13) ={   1.1484,  -0.9719,   1.4185, lref};

lref= 0.022;
Point(p1+14) ={   1.6429,  -1.5022,   1.4885, lref};
Point(p1+17) ={   1.8901,  -1.2716,   1.4885, lref};
Point(p1+18) ={   1.6429,  -1.5022,   1.8266, lref};
Point(p1+19) ={   1.3956,  -1.7328,   1.4885, lref};
Point(p1+20) ={   1.6429,  -1.5022,   1.1504, lref};
Point(p1+29) ={   1.6940,  -1.5570,   1.4885, lref};

Point(p1+15) ={   1.5342,  -1.3856,   1.4885, lref};
Point(p1+21) ={   1.9479,  -0.9998,   1.4885, lref};
Point(p1+22) ={   1.5342,  -1.3856,   2.0542, lref};
Point(p1+23) ={   1.1205,  -1.7714,   1.4885, lref};
Point(p1+24) ={   1.5342,  -1.3856,   0.9228, lref};
Point(p1+16) ={   1.4212,  -1.2644,   1.4885, lref};
Point(p1+25) ={   1.9279,  -0.7920,   1.4885, lref};
Point(p1+26) ={   1.4212,  -1.2644,   2.1813, lref};
Point(p1+27) ={   0.9145,  -1.7369,   1.4885, lref};
Point(p1+28) ={   1.4212,  -1.2644,   0.7957, lref};
//**** Definition of lines

line1 = newl;
SyncModel;

// archi thruster box

Circle(line1+1) ={p1+  2,p1+  1,p1+  3};
Circle(line1+5) ={p1+  6,p1+  1,p1+  7};
Circle(line1+9) ={p1+ 10,p1+  1,p1+ 11};
Circle(line1+2) ={p1+  3,p1+  1,p1+  4};
Circle(line1+6) ={p1+  7,p1+  1,p1+  8};
Circle(line1+10) ={p1+ 11,p1+  1,p1+ 12};
Circle(line1+3) ={p1+  4,p1+  1,p1+  5};
Circle(line1+7) ={p1+  8,p1+  1,p1+  9};
Circle(line1+11) ={p1+ 12,p1+  1,p1+ 13};
Circle(line1+4) ={p1+  5,p1+  1,p1+  2};
Circle(line1+8) ={p1+  9,p1+  1,p1+  6};
Circle(line1+12) ={p1+ 13,p1+  1,p1+ 10};

Circle(line1+13) ={p1+ 17,p1+ 14,p1+ 18};
Circle(line1+14) ={p1+ 18,p1+ 14,p1+ 19};
Circle(line1+15) ={p1+ 19,p1+ 14,p1+ 20};
Circle(line1+16) ={p1+ 20,p1+ 14,p1+ 17};

// radial lines thruster exit plane

Line(line1+25) ={p1+  2,p1+  6};
Line(line1+26) ={p1+  6,p1+ 10};
Line(line1+27) ={p1+  3,p1+  7};
Line(line1+28) ={p1+  7,p1+ 11};
Line(line1+29) ={p1+  4,p1+  8};
Line(line1+30) ={p1+  8,p1+ 12};
Line(line1+31) ={p1+  5,p1+  9};
Line(line1+32) ={p1+  9,p1+ 13};

//arcs  auxiliary

Circle(line1+35) ={p1+ 20,p1+  1,p1+ 29};
Circle(line1+36) ={p1+ 29,p1+  1,p1+ 18};
Circle(line1+41) ={p1+ 19,p1+  1,p1+ 29};
Circle(line1+42) ={p1+ 29,p1+  1,p1+ 17};

// longitudinal lines

Line(line1+48) ={p1+  1,p1+ 29};
Line(line1+55) ={p1+  2,p1+ 17};
Line(line1+49) ={p1+  3,p1+ 18};
Line(line1+54) ={p1+  4,p1+ 19};
Line(line1+47) ={p1+  5,p1+ 20};

// radial lines thruster

Line(line1+58) ={p1+  1,p1+  2};
Line(line1+59) ={p1+  1,p1+  3};
Line(line1+60) ={p1+  1,p1+  4};
Line(line1+61) ={p1+  1,p1+  5};

// Surfaces

s1 = news;

// thruster inner and outer faces

Line Loop(s1+1) = {line1+1, -line1-59, line1+58};
Plane Surface(s1+2) = {s1+1};
Line Loop(s1+3) = {line1+2, -line1-60, line1+59};
Plane Surface(s1+4) = {s1+3};
Line Loop(s1+5) = {line1+3, -line1-61, line1+60};
Plane Surface(s1+6) = {s1+5};
Line Loop(s1+7) = {line1+4, -line1-58, line1+61};
Plane Surface(s1+8) = {s1+7};
Line Loop(s1+9) = {line1+10, -line1-30,-line1-6,line1+28};
Plane Surface(s1+10) = {s1+9};
Line Loop(s1+11) = {line1+11, -line1-32,-line1-7,line1+30};
Plane Surface(s1+12) = {s1+11};
Line Loop(s1+13) = {line1+12, -line1-26,-line1-8,line1+32};
Plane Surface(s1+14) = {s1+13};
Line Loop(s1+15) = {line1+9, -line1-28,-line1-5,line1+26};
Plane Surface(s1+16) = {s1+15};

// thruster exit plane

Line Loop(s1+17) = {line1+6, -line1-29,-line1-2, line1+27};
Plane Surface(s1+18) = {s1+17};
Line Loop(s1+19) = {line1+29, line1+7,-line1-31, -line1-3};
Plane Surface(s1+20) = {s1+19};
Line Loop(s1+21) = {line1+8, -line1-25,-line1-4, line1+31};
Plane Surface(s1+22) = {s1+21};
Line Loop(s1+23) = {line1+5, -line1-27,-line1-1, line1+25};
Plane Surface(s1+24) = {s1+23};

Transfinite Line {line1+2, line1+1, line1+4, line1+3}     = 9
          Using Progression 1; // thruster inner circle
Transfinite Line {line1+6, line1+5, line1+8, line1+7}     = 11
          Using Progression 1; // thruster outer circle
Transfinite Line {line1+10, line1+9, line1+12, line1+11}  = 11
          Using Progression 1; // thruster box out circle
Transfinite Line {line1+26, line1+28, line1+30,line1+32} = 3
         Using Progression 1; // radial thruster exit plane
Transfinite Line {line1+25, line1+27, line1+29, line1+31} = 4
          Using Progression 1; // radial outer
Transfinite Line {line1+58, line1+59, line1+60, line1+61} = 4
          Using Progression 1; // radial inner

// auxiliary inner layer

Line Loop(s1+25) = {line1+48, line1+36, -line1-49, -line1-59};
Plane Surface(s1+26) = {s1+25};
Line Loop(s1+27) = {line1+48, -line1-41, -line1-54, -line1-60};
Plane Surface(s1+28) = {s1+27};
Line Loop(s1+29) = {line1+48, -line1-35, -line1-47, -line1-61};
Plane Surface(s1+30) = {s1+29};
Line Loop(s1+31) = {line1+48, line1+42, -line1-55, -line1-58};
Plane Surface(s1+32) = {s1+31};
Line Loop(s1+33) = {line1+14, -line1-54, -line1-2, line1+49};
Surface(s1+34) = {s1+33};
Line Loop(s1+35) = {line1+15, -line1-47, -line1-3, line1+54};
Surface(s1+36) = {s1+35};
Line Loop(s1+37) = {line1+16, -line1-55, -line1-4, line1+47};
Surface(s1+38) = {s1+37};
Line Loop(s1+39) = {line1+13, -line1-49, -line1-1, line1+55};
Surface(s1+40) = {s1+39};

Transfinite Line {line1+48,line1+49,line1+47,line1+54,line1+55} = 25
            Using Progression 1.1;
Transfinite Line {line1+36, line1+41, line1+42, line1+35} = 8
            Using Progression 1.0;
Transfinite Line {line1+14, line1+13, line1+15, line1+16} = 12
            Using Progression 1.0;

// EMBED SURFACES //
//Surface {s1+26,s1+28,s1+30,s1+32,s1+34,s1+36,s1+38,s1+40} In Volume {};


// auxiliary intermediate layer

Circle(line1+17) ={p1+ 21,p1+ 15,p1+ 22};
Circle(line1+18) ={p1+ 22,p1+ 15,p1+ 23};
Circle(line1+19) ={p1+ 23,p1+ 15,p1+ 24};
Circle(line1+20) ={p1+ 24,p1+ 15,p1+ 21};

Circle(line1+34) ={p1+ 24,p1+  1,p1+ 20};
Circle(line1+37) ={p1+ 18,p1+  1,p1+ 22};
Circle(line1+40) ={p1+ 23,p1+  1,p1+ 19};
Circle(line1+43) ={p1+ 17,p1+  1,p1+ 21};

Line(line1+56) ={p1+  6,p1+ 21};
Line(line1+50) ={p1+  7,p1+ 22};
Line(line1+53) ={p1+  8,p1+ 23};
Line(line1+46) ={p1+  9,p1+ 24};

Line Loop(s1+41) = {line1+37, -line1-50, -line1-27, line1+49};
Plane Surface(s1+42) = {s1+41};
Line Loop(s1+43) = {line1+40, -line1-54, line1+29, line1+53};
Plane Surface(s1+44) = {s1+43};
Line Loop(s1+45) = {line1+34, -line1-47, line1+31, line1+46};
Plane Surface(s1+46) = {s1+45};
Line Loop(s1+47) = {line1+43, -line1-56, -line1-25, line1+55};
Plane Surface(s1+48) = {s1+47};
Line Loop(s1+49) = {line1+18, -line1-53, -line1-6, line1+50};
Surface(s1+50) = {s1+49};
Line Loop(s1+51) = {line1+19, -line1-46, -line1-7, line1+53};
Surface(s1+52) = {s1+51};
Line Loop(s1+53) = {line1+20, -line1-56, -line1-8, line1+46};
Surface(s1+54) = {s1+53};
Line Loop(s1+55) = {line1+17, -line1-50, -line1-5, line1+56};
Surface(s1+56) = {s1+55};

Transfinite Line {line1+53, line1+50, line1+56, line1+46} = 25
            Using Progression 1.1;
Transfinite Line {line1+37, line1+40, line1+34, line1+43} = 6
            Using Progression 1.0;
Transfinite Line {line1+18, line1+19, line1+20, line1+17} = 19
            Using Progression 1.1;

// EMBED SURFACES //
//Surface {s1+42,s1+44,s1+46,s1+48,s1+50,s1+52,s1+54,s1+56} In Volume {};

// auxiliary external layer

Circle(line1+21) ={p1+ 25,p1+ 16,p1+ 26};
Circle(line1+22) ={p1+ 26,p1+ 16,p1+ 27};
Circle(line1+23) ={p1+ 27,p1+ 16,p1+ 28};
Circle(line1+24) ={p1+ 28,p1+ 16,p1+ 25};

Circle(line1+33) ={p1+ 28,p1+  1,p1+ 24};
Circle(line1+38) ={p1+ 22,p1+  1,p1+ 26};
Circle(line1+39) ={p1+ 27,p1+  1,p1+ 23};
Circle(line1+44) ={p1+ 21,p1+  1,p1+ 25};

Line(line1+57) ={p1+ 10,p1+ 25};
Line(line1+51) ={p1+ 11,p1+ 26};
Line(line1+52) ={p1+ 12,p1+ 27};
Line(line1+45) ={p1+ 13,p1+ 28};

Line Loop(s1+57) = {line1+38, -line1-51, -line1-28, line1+50};
Plane Surface(s1+58) = {s1+57};
Line Loop(s1+59) = {line1+39, -line1-53, line1+30, line1+52};
Plane Surface(s1+60) = {s1+59};
Line Loop(s1+61) = {line1+33, -line1-46, line1+32, line1+45};
Plane Surface(s1+62) = {s1+61};
Line Loop(s1+63) = {line1+44, -line1-57, -line1-26, line1+56};
Plane Surface(s1+64) = {s1+63};
Line Loop(s1+65) = {line1+22, -line1-52, -line1-10, line1+51};
Surface(s1+66) = {s1+65};
Line Loop(s1+67) = {line1+23, -line1-45, -line1-11, line1+52};
Surface(s1+68) = {s1+67};
Line Loop(s1+69) = {line1+24, -line1-57, -line1-12, line1+45};
Surface(s1+70) = {s1+69};
Line Loop(s1+71) = {line1+21, -line1-51, -line1-9, line1+57};
Surface(s1+72) = {s1+71};

Transfinite Line {line1+51, line1+52, line1+45, line1+57} = 25
            Using Progression 1.1;
Transfinite Line {line1+22, line1+21, line1+24, line1+23} = 23
            Using Progression 1.0;
Transfinite Line {line1+44, line1+38, line1+39, line1+33} = 5
            Using Progression 1.0;

////////////////////////////////////////////////////////////////////////////////////////////

//+
Line(492) = {111, 63};
//+
Line(493) = {112, 64};
//+
Line(494) = {113, 65};
//+
Line(495) = {110, 62};
//+
Line Loop(496) = {367, 493, 141, -492};
//+
Surface(497) = {496};
//+
Line Loop(498) = {368, 494, 140, -493};
//+
Surface(499) = {498};
//+
Line Loop(500) = {369, 495, 139, -494};
//+
Surface(501) = {500};
//+
Line Loop(502) = {366, 492, 138, -495};
//+
Surface(503) = {502};
//+
Transfinite Line {492, 493, 494, 495} = 5 Using Progression 1.0;
//+
Surface Loop(504) = {497, 499, 501, 503, 227, 435, 429, 431, 433, 441, 443, 437, 439, 425, 427, 421, 423};
//+
Volume(505) = {351, 352, 353, 354, 355, 504};

SyncModel;

// EMBED SURFACES //
Surface {s1+26,s1+28,s1+30,s1+32,s1+34,s1+36,s1+38,s1+40} In Volume {505};
Surface {s1+42,s1+44,s1+46,s1+48,s1+50,s1+52,s1+54,s1+56} In Volume {505};
Surface {s1+58,s1+60,s1+62,s1+64,s1+66,s1+68,s1+70,s1+72} In Volume {505};

//Printf ("%f",s1);

//+
Physical Surface(310) = {437, 443, 439, 441};
Physical Surface(304) += {421,423,425,427};
Physical Surface(304) += {429,431,433,435};
Physical Surface(304) += {497,499,501,503};
//+
Physical Volume("310") = {505};
//+
Physical Surface("320") = {328, 332, 334, 330, 344, 350, 348, 346, 338, 340, 342, 336};
//+

If(1)
Rotate {{0, 0, 1}, {1.8775, -3, 1.4885}, -0.5235987} {
  Point{87, 89, 92, 90, 91, 96, 99, 98, 97, 94, 93, 95, 88, 86};
}
Translate {-1.0, 0.0, 0.0} {
  Point{87, 89, 92, 90, 91, 96, 99, 98, 97, 94, 93, 95, 88, 86};
}
EndIf

Surface {477} In Volume {505};

//+
Physical Surface(340) = {237, 239, 247, 245, 241, 243};
//+

//+
Transfinite Line {118, 121, 120, 119} = 12 Using Progression 1;
//+
Transfinite Line {122, 125, 124, 123} = 10 Using Progression 1;
//+
Transfinite Line {375, 374, 377, 376} = 17 Using Progression 1;
//+
Transfinite Line {379, 378, 381, 380} = 20 Using Progression 1;
