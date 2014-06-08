//gasdis.geo
//

//gas distribution ring

//parameters

mm=1e-3;
lc1=0.25*mm;

bigrad=100*mm;
bigang=Pi/9;
tuberad=4*mm;
holerad=1*mm;
seglength=3*mm;

Point(1) = {0.0,0.0,0.0,lc1};
Point(2) = {tuberad,0.0,0.0,lc1};
Point(3) = {-tuberad,0.0,0.0,lc1};
Point(4) = {0,tuberad,0.0,lc1};
Point(5) = {0,-tuberad,0.0,lc1};


Rotate { {0,1,0},{0.0,0.0,0.0},Pi/6 } {Duplicata { Point{3}; }}
Rotate { {0,1,0},{0.0,0.0,0.0},-Pi/6 } {Duplicata { Point{3}; }}
Rotate { {0,0,1},{0.0,0.0,0.0},Pi/6 } {Duplicata { Point{3}; }}
Rotate { {0,0,1},{0.0,0.0,0.0},-Pi/6 } {Duplicata { Point{3}; }}

Point(10)={-tuberad*Cos(Pi/6), 0, 0, lc1};

Circle(1) = {9,10,6};
Circle(2) = {6,10,8};
Circle(3) = {8,10,7};
Circle(4) = {7,10,9};

Point(12) = {tuberad,0.0,seglength,lc1};
Point(13) = {-tuberad,0.0,seglength,lc1};
Point(14) = {0,tuberad,seglength,lc1};
Point(15) = {0,-tuberad,seglength,lc1};
Point(16) = {0,0,seglength,lc1};

Point(17) = {tuberad,0.0,-seglength,lc1};
Point(18) = {-tuberad,0.0,-seglength,lc1};
Point(19) = {0,tuberad,-seglength,lc1};
Point(20) = {0,-tuberad,-seglength,lc1};
Point(21) = {0,0,-seglength,lc1};


Circle(6) = {13,16,14};
Circle(7) = {14,16,12};
Circle(8) = {12,16,15};
Circle(9) = {15,16,13};
Circle(10) = {18,21,19};
Circle(11) = {19,21,17};
Circle(12) = {17,21,20};
Circle(13) = {20,21,18};
Circle(14) = {9,1,4};
Circle(15) = {4,1,2};
Circle(16) = {2,1,5};
Circle(17) = {5,1,8};

Point(22)={0,tuberad,-tuberad*Sin(Pi/6),  lc1};
Point(23)={0,-tuberad,-tuberad*Sin(Pi/6),  lc1};
Point(24)={tuberad,0,-tuberad*Sin(Pi/6),  lc1};
Point(25)={0,0,-tuberad*Sin(Pi/6),  lc1};

Point(26)={0,tuberad,tuberad*Sin(Pi/6),  lc1};
Point(27)={0,-tuberad,tuberad*Sin(Pi/6),  lc1};
Point(28)={tuberad,0,tuberad*Sin(Pi/6),  lc1};

Point(29)={0,0,tuberad*Sin(Pi/6),  lc1};

Point(30)={-bigrad,tuberad,0,  lc1};
Point(31)={-bigrad,-tuberad,0,  lc1};
Point(32)={-bigrad,0,0,  lc1};

Ellipse(18) = {6,29,26,26};
Ellipse(19) = {7,25,22,22};
Ellipse(20) = {6,29,27,27};
Ellipse(21) = {7,25,23,23};
Circle(22) = {26,29,28};
Circle(23) = {28,29,27};
Circle(24) = {22,25,24};
Circle(25) = {24,25,23};
Line(26) = {22,4};
Line(27) = {4,26};
Line(28) = {24,2};
Line(29) = {2,28};
Line(30) = {23,5};
Line(31) = {5,27};
Line(32) = {19,22};
Line(33) = {20,23};
Line(34) = {27,15};
Line(35) = {28,12};
Line(36) = {26,14};
Line(37) = {18,7};
Line(38) = {17,24};
Line(39) = {6,13};
Line Loop(40) = {17,-2,20,-31};			Ruled Surface(41) = {40};
Line Loop(42) = {3,21,30,17};			Ruled Surface(43) = {42};
Line Loop(44) = {37,21,-33,13};			Ruled Surface(45) = {44};
Line Loop(46) = {19,-32,-10,37};		Ruled Surface(47) = {46};
Line Loop(48) = {19,26,-14,-4};			Ruled Surface(49) = {48};
Line Loop(50) = {14,27,-18,-1};			Ruled Surface(51) = {50};
Line Loop(52) = {30,-16,-28,25};		Ruled Surface(53) = {52};
Line Loop(54) = {31,-23,-29,16};		Ruled Surface(55) = {54};
Line Loop(56) = {28,-15,-26,24};		Ruled Surface(57) = {56};
Line Loop(58) = {32,24,-38,-11};		Ruled Surface(59) = {58};
Line Loop(60) = {25,-33,-12,38};		Ruled Surface(61) = {60};
Line Loop(62) = {27,22,-29,-15};		Ruled Surface(63) = {62};
Line Loop(64) = {39,-9,-34,-20};		Ruled Surface(65) = {64};
Line Loop(66) = {18,36,-6,-39};			Ruled Surface(67) = {66};
Line Loop(68) = {36,7,-35,-22};			Ruled Surface(69) = {68};
Line Loop(70) = {8,-34,-23,35};			Ruled Surface(71) = {70};
Rotate { {0.0,1.0,0.0},{-bigrad,0.0,0.0},bigang } {Duplicata { Surface{41,43, 45,47,49,51,53,55,57, 59,61,63, 65, 67,69, 71}; }}
Rotate { {0.0,1.0,0.0},{-bigrad,0.0,0.0},2*bigang } {Duplicata { Surface{41,43,45,47,49,51,53,55,57, 59,61,63, 65, 67,69, 71}; }}
Rotate { {0.0,1.0,0.0},{-bigrad,0.0,0.0},3*bigang } {Duplicata { Surface{41,43,45,47,49,51,53,55,57, 59,61,63, 65, 67,69, 71}; }}
Rotate { {0.0,1.0,0.0},{-bigrad,0.0,0.0},4*bigang } {Duplicata { Surface{41,43,45,47,49,51,53,55,57, 59,61,63, 65, 67,69, 71}; }}
Rotate { {0.0,1.0,0.0},{-bigrad,0.0,0.0},5*bigang } {Duplicata { Surface{41,43,45,47,49,51,53,55,57, 59,61,63, 65, 67,69, 71}; }}
Rotate { {0.0,1.0,0.0},{-bigrad,0.0,0.0},6*bigang } {Duplicata { Surface{41,43,45,47,49,51,53,55,57, 59,61,63, 65, 67,69, 71}; }}Circle(534) = {1620,31,1168};

Circle(535) = {1615,32,1157};
Circle(536) = {1658,32,1299};
Circle(537) = {1640,30,1183};
Circle(538) = {1349,31,897};
Circle(539) = {1344,32,886};
Circle(540) = {1369,30,912};
Circle(541) = {1387,32,1028};
Circle(542) = {1073,32,615};
Circle(543) = {1116,32,757};
Circle(544) = {1078,31,626};
Circle(545) = {1098,30,641};
Circle(546) = {802,32,344};
Circle(547) = {807,31,355};
Circle(548) = {827,30,370};
Circle(549) = {845,32,486};
Circle(550) = {531,32,73};
Circle(551) = {215,32,574};
Circle(552) = {99,30,556};
Circle(553) = {536,31,84};
Circle(554) = {260,32,18};
Circle(555) = {17,32,303};
Circle(556) = {20,31,265};
Circle(557) = {285,30,19};
Line Loop(558) = {534,433,-536,533};
Ruled Surface(559) = {558};
Line Loop(560) = {536,429,-537,529};
Ruled Surface(561) = {560};
Line Loop(562) = {534,394,-535,519};
Ruled Surface(563) = {562};
Line Loop(564) = {535,-398,-537,525};
Ruled Surface(565) = {564};
Line Loop(566) = {442,538,317,-539};
Ruled Surface(567) = {566};
Line Loop(568) = {539,-321,-540,448};
Ruled Surface(569) = {568};
Line Loop(570) = {540,-352,-541,-452};
Ruled Surface(571) = {570};
Line Loop(572) = {541,-356,-538,-456};
Ruled Surface(573) = {572};
Line Loop(574) = {542,-244,-545,371};
Ruled Surface(575) = {574};
Line Loop(576) = {545,-275,-543,-375};
Ruled Surface(577) = {576};
Line Loop(578) = {542,-240,-544,-365};
Ruled Surface(579) = {578};
Line Loop(580) = {544,279,-543,379};
Ruled Surface(581) = {580};
Ruled Surface(582) = {576};
Line Loop(583) = {546,-163,-547,-288};
Ruled Surface(584) = {583};
Line Loop(585) = {202,-549,302,547};
Ruled Surface(586) = {585};
Line Loop(587) = {549,198,-548,298};
Ruled Surface(588) = {587};
Line Loop(589) = {167,-546,-294,548};
Ruled Surface(590) = {589};
Line Loop(591) = {217,550,-90,552};
Ruled Surface(592) = {591};
Line Loop(593) = {550,-86,-553,-211};
Ruled Surface(594) = {593};
Line Loop(595) = {225,553,125,551};
Ruled Surface(596) = {595};
Line Loop(597) = {221,-551,121,552};
Ruled Surface(598) = {597};
Line Loop(599) = {554,-13,556,-134};
Ruled Surface(600) = {599};
Line Loop(601) = {556,-148,-555,12};
Ruled Surface(602) = {601};
Line Loop(603) = {10,-557,140,554};
Ruled Surface(604) = {603};
Line Loop(605) = {557,11,555,-144};
Ruled Surface(606) = {605};
Line Loop(607) = {7,8,9,6};
Plane Surface(608) = {607};
Physical Surface(609) = {67,608,69,63,608,51,65,71,55,41,49,57,59,53,43,47,604,45,61,606,602,600,137,142,127,97,132,147,112,92,92,72,107,117,87,77,102,598,122,82,592,594,596,214,219,224,209,174,204,184,149,154,179,189,169,159,199,586,194,164,590,584,588,286,301,296,291,226,261,281,251,256,231,246,266,276,236,241,271,582,582,582,581,575,579,582,378,363,368,373,338,303,328,358,333,343,323,308,313,318,348,353,573,571,567,569,450,567,445,440,455,435,405,415,380,420,400,410,385,425,395,390,430,561,559,563,565,522,517,527,532,512,457,482,492,497,462,477,487,502,472,467,507};
Line Loop(610) = {4,1,2,3};
Plane Surface(611) = {610};
Line Loop(612) = {101,96,-78,74};
Plane Surface(613) = {612};
Line Loop(614) = {178,173,-155,151};
Plane Surface(615) = {614};
Line Loop(616) = {255,250,-232,228};
Plane Surface(617) = {616};
Line Loop(618) = {327,-309,305,332};
Plane Surface(619) = {618};
Line Loop(620) = {404,-386,382,409};
Plane Surface(621) = {620};
Line Loop(622) = {481,-463,459,486};
Plane Surface(623) = {622};
Line Loop(624) = {506,475,-471,510};
Plane Surface(625) = {624};
Physical Surface(626) = {611,613,615,617,619,621,623};
Physical Surface(627)={625};

Surface Loop(628) = {571,569,567,-440,-445,-405,-400,395,425,-420,-410,385,621,-380,-415,455,573,353,-333,308,619,-323,318,348,-343,358,-328,-368,373,582,575,-579,-236,241,-246,-266,-256,231,617,-251,281,296,-291,-590,164,-169,-189,-179,154,615,-174,204,219,-214,592,-594,-82,87,-92,-112,-102,77,613,-97,127,142,-137,604,47,-49,-57,-53,43,-611,-51,63,69,-67,-608,71,-65,-41,-55,-45,61,602,-600,-132,147,-107,-72,606,59,122,-596,224,-209,-149,-184,-598,117,-159,199,-586,-588,194,301,-286,-584,-226,-261,276,-581,378,-363,-303,-338,271,-313,450,435,-390,430,-559,563,565,-561,527,-522,-482,-477,472,502,-497,-487,462,623,-457,-517,532,-492,512,-467,507,-625};
Volume(629) = {628};
