// ce programme resoud le probleme de haut-parleur en 3d
// en fixant une vitesse sur le tweeter constante U0
// et en prennant comme  frequence de source (tweeter) 
// Freq. 

r = 0.175 ; x0 = 0.31 ; y1 = 0.16; 
y0 = 0.16; x1 = 0.315 ; z0 = 0.12; 
m = 2 ;
Freq = m*100 ; 
lambda = 342 / Freq ;
dx = lambda;
x = 1.04; 
y = 1.0; 

e = lambda ;
p0 = e/8; 
p1 = p0/4; 

// p0=.0085 la frequence d'echontillonnage spatiale, on le	 
// prend toujours au moins 2 fois plus grande que la frequence 
// de la source.


Point(1) = {r,0.0,0.0, p1};
Point(2) = {r+x0,0.0,0.0, p0};
Point(3) = {r+x0,0.0,y0, p0};
Point(4) = {r+x0+x1,r+x0+x1,y0, p0};
Point(6) = {0.0,0.0,0.0,p0};
Point(8) = {r+x0+x1,0.0,y0,p0};
Point(9) = {r+x0+x1,r+x0+x1,0.0, p0};
Point(11) = {r+x0+x1,0.0,0.0,p0};
Point(12) = {y,y,0.0,p0}; 
Point(14) = {y,y,x,p0}; 
Point(16) = {y+dx,y+dx,y+dx,p0}; 
Point(17) = {y+dx,0.0,y+dx, p0};
Point(18) = {0.0,r,0.0, p1};
Point(20) = {0.0,0.0,-0.125, p0};
Point(22) = {0.0,r+x0,y0, p0};
Point(26) = {0.0,0.0,0.09, p1};
Point(27) = {0.0,0.0,0.16,p0};
Point(28) = {0.0,0.485,0.0,p0};
Point(29) = {0.0,0.8,0.0,p0};
Point(30) = {0.0,0.8,0.16,p0};
Point(31) = {0.0,1.0,1.0,p0};
Point(32) = {0.0,1.0,0.0,p0};
Point(33) = {1.0,0.0,0.0,p0};
Point(34) = {1.0,0.0,1.0,p0};
Point(35) = {0.0,1.0+lambda,1.0,p0};
Point(36) = {0.0,1.0+lambda,0.0,p0};
Point(37) = {1.0+lambda,1.0+lambda,0.0,p0};
Point(38) = {1.0+lambda,1.0+lambda,1.04,p0};
Point(39) = {1+lambda,0.0,0.0,p0};
Point(40) = {1+lambda,0.0,1.0,p0};
Point(41) = {0.0,0.0,1.0,p0};
Point(43) = {0.0,1+lambda,1+lambda,p0};
Point(44) = {0.0,0.0,1+lambda,p0};
Circle(19) = {1,6,18};
Circle(20) = {1,20,26};
Circle(21) = {18,20,26};
Circle(23) = {3,27,22};


Line(2) = {6,18};
Line(6) = {3,1};
Line(7) = {6,1};
Line(8) = {1,2};
Line(9) = {3,8};
Line(10) = {8,11};
Line(11) = {11,2};
Line(12) = {9,11};
Line(14) = {9,4};
Line(15) = {8,4};
Line(25) = {2,3};
Line(26) = {22,18};
Line(28) = {28,22};
Line(31) = {18,28};
Circle(32) = {28,6,2};
Line(48) = {6,26};
Line(55) = {30,22};
Line(56) = {28,29};
Line(57) = {30,29};
Line(58) = {30,4};
Line(59) = {29,9};
Line(72) = {9,12};
Line(73) = {14,12};
Line(74) = {29,32};
Line(75) = {31,32};
Line(76) = {31,14};
Line(77) = {32,12};
Line(78) = {33,12};
Line(79) = {34,33};
Line(80) = {14,34};
Line(81) = {33,11};
Line(82) = {35,31};
Line(83) = {32,36};
Line(84) = {36,35};
Line(85) = {35,38};
Line(86) = {36,37};
Line(87) = {38,37};
Line(88) = {12,37};
Line(89) = {14,38};
Line(90) = {39,40};
Line(91) = {39,37};
Line(92) = {40,38};
Line(93) = {33,39};
Line(94) = {34,40};
Line(125) = {44,17};
Line(126) = {17,16};
Line(127) = {43,16};
Line(128) = {44,43};
Line(129) = {44,41};
Line(130) = {35,43};
Line(131) = {17,40};
Line(132) = {38,16};
Line(133) = {34,41};
Line(134) = {31,41};
Line(153) = {27,41};
Line(154) = {26,27};


Line Loop(38) = {31,28,26};
Plane Surface(39) = {38};
Line Loop(42) = {21,-20,19};
Ruled Surface(43) = {42};
Line Loop(46) = {-26,-23,6,19};
Ruled Surface(47) = {46};
Line Loop(49) = {20,-48,7};
Plane Surface(50) = {49};
Line Loop(51) = {-48,2,21};
Plane Surface(52) = {51};
Line Loop(53) = {6,8,25};
Plane Surface(54) = {53};
Line Loop(60) = {-15,10,-12,14};
Plane Surface(61) = {60};
Line Loop(62) = {59,14,-58,57};
Plane Surface(63) = {62};
Line Loop(64) = {-55,57,-56,28};
Plane Surface(65) = {64};
Line Loop(66) = {-58,55,-23,9,15};
Plane Surface(67) = {66};
Line Loop(68) = {12,11,-32,56,59};
Plane Surface(69) = {68};
Line Loop(70) = {9,10,11,25};
Plane Surface(71) = {70};
Line Loop(95) = {-89,80,94,92};
Plane Surface(96) = {95};
Line Loop(97) = {92,87,-91,90};
Plane Surface(98) = {97};
Line Loop(99) = {85,87,-86,84};
Plane Surface(100) = {99};
Line Loop(101) = {84,82,75,83};
Plane Surface(102) = {101};
Line Loop(103) = {88,-86,-83,77};
Plane Surface(104) = {103};
Line Loop(105) = {88,-91,-93,78};
Plane Surface(106) = {105};
Line Loop(107) = {-88,-73,89,87};
Plane Surface(108) = {107};
Line Loop(109) = {93,90,-94,79};
Plane Surface(110) = {109};
Line Loop(111) = {-73,80,79,78};
Plane Surface(112) = {111};
Line Loop(113) = {-73,-76,75,77};
Plane Surface(114) = {113};
Line Loop(115) = {-85,82,76,89};
Plane Surface(116) = {115};
Line Loop(117) = {-81,78,-72,12};
Plane Surface(118) = {117};
Line Loop(119) = {77,-72,-59,74};
Plane Surface(120) = {119};
Line Loop(135) = {132,-126,131,92};
Plane Surface(136) = {135};
Line Loop(137) = {-94,133,-129,125,131};
Plane Surface(138) = {137};
Line Loop(139) = {133,-134,76,80};
Plane Surface(140) = {139};
Line Loop(141) = {-129,128,-130,82,134};
Plane Surface(142) = {141};
Line Loop(143) = {127,-132,-85,130};
Plane Surface(144) = {143};
Line Loop(145) = {127,-126,-125,128};
Plane Surface(146) = {145};
Line Loop(155) = {-153,-154,-20,-6,9,10,-81,-79,133};
Plane Surface(156) = {155};
Line Loop(157) = {-74,-57,55,26,21,154,153,-134,75};
Plane Surface(158) = {157};


Surface Loop(147) = {116,-144,146,-136,138,96,-140,-142};
Complex Volume(148) = {147};
Surface Loop(149) = {96,108,106,-98,110,-112};
Complex Volume(150) = {149};
Surface Loop(151) = {108,104,-100,-116,102,-114};
Complex Volume(152) = {151} ;
Surface Loop(159) = {112,-114,-140,156,158,120,-118,-61,-67,63,47,-43};
Complex Volume(160) = {159};

Physical Volume(1000) = {160}; // Air

Physical Volume(1301) = {150}; // PML_X1
Physical Volume(1302) = {152}; // PML_Y1
Physical Volume(1303) = {148}; // PML_Z1

Physical Surface(1200) = {43}; // tweeter
// Physical Surface(1400) = {47,67}; // Pavillon

