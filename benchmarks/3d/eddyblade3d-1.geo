// 
//  eddyblade3d-1.geo
//
//  Copyright 2002 by Alfred P. Steffens, Jr. <alfred.p.steffens-jr@boeing.com>
//

//
//  define scales
//

/*
tiny_scale = 0.04;
small_scale = 0.1;
norm_scale = 0.5;
blade_scale = 0.05;
shield_scale = 0.7;
large_scale = 1.5;
*/

Mesh.Algorithm = 3;
Mesh.Smoothing = 3;
a=0.2;
tiny_scale = a/3.;
small_scale = a;
norm_scale = a;
blade_scale = a/3.;
shield_scale = a;
large_scale2 = a;
large_scale = 5*a;

//
//  points for the spline curve
//  disk top,  left, rear
//
Point(1) = {-5, -3.306, -5, large_scale};
Point(2) = {-3.769, -3.0156, -5, large_scale};
Point(3) = {-2.522, -2.807, -5, large_scale};
Point(4) = {-1.2638, -2.6819, -5, large_scale};
Point(5) = {-0.127, -2.64, -5, large_scale};

//
//  points for the spline curve
//  disk top,  right, rear
//
Point(6) = {5, -3.306, -5, large_scale};
Point(7) = {3.769, -3.0156, -5, large_scale};
Point(8) = {2.522, -2.807, -5, large_scale};
Point(9) = {1.2638, -2.6819, -5, large_scale};
Point(10) = {0.127, -2.64, -5, large_scale};

//
//  points for the spline curve
//  disk top,  left, front
//
Point(11) = {-5, -3.306, 5, large_scale};
Point(12) = {-3.769, -3.0156, 5, large_scale};
Point(13) = {-2.522, -2.807, 5, large_scale};
Point(14) = {-1.2638, -2.6819, 5, large_scale};
Point(15) = {-0.127, -2.64, 5, large_scale};

//
//  points for the spline curve
//  disk top,  right, front
//
Point(16) = {5, -3.306, 5, large_scale};
Point(17) = {3.769, -3.0156, 5, large_scale};
Point(18) = {2.522, -2.807, 5, large_scale};
Point(19) = {1.2638, -2.6819, 5, large_scale};
Point(20) = {0.127, -2.64, 5, large_scale};

//
//  points for closing the blade face -- rear
//  points are closest to the shield plate
//
Point(21) = {-0.127, -0.102, -5, blade_scale};
Point(22) = {0.127, -0.102, -5, blade_scale};
//
//  points for closing the blade face -- front
//  points are closest to the shield plate
//
Point(23) = {-0.127, -0.102, 5, blade_scale};
Point(24) = {0.127, -0.102, 5, blade_scale};

//
//  points that define the top surface of the shield plate
//
Point(25) = {-5, 0.0762, -5, shield_scale};
Point(26) = {-5, 0.0762, 5, shield_scale};
Point(27) = {5, 0.0762, 5, shield_scale};
Point(28) = {5, 0.0762, -5, shield_scale};

//
//  points that define the bottom surface of the shield plate
//
Point(29) = {-5, -0.0762, -5, shield_scale};
Point(30) = {-5, -0.0762, 5, shield_scale};
Point(31) = {5, -0.0762, 5, shield_scale};
Point(32) = {5, -0.0762, -5, shield_scale};

//
//  points that define the top, inner disk for the solenoid
//  the first 90-degree sector
//
Point(33) = {0.159, 2.67, 0, small_scale};   // right-hand point
Point(34) = {0, 2.67, 0, small_scale};        //  center (on y-axis)
Point(35) = {0, 2.67, -0.159, small_scale};  // rear point

//
//  additional point for top, inner disk of the solenoid
//  defines the second sector
//
Point(36) = {-0.159, 2.67, 0, small_scale};

//
//  additional point for top, inner disk of the solenoid
//  defines the third sector (and fourth)
//
Point(37) = {0, 2.67, 0.159, small_scale};

//
//  points that define the top, outer disk for the solenoid
//
Point(38) = {0.185, 2.67, 0, small_scale};   // beginning of 1st sector
Point(39) = {0, 2.67, -0.185, small_scale};  //  beginning od 2nd sector
Point(40) = {-0.185, 2.67, 0, small_scale};  //  beginning of third sector
Point(41) = {0, 2.67, 0.185, small_scale};   //  beginning of 4th sector

//
//  points that define the bottom, inner disk of the solenoid
//
//  1st sector points
//
Point(42) = {0.159, 0.127, 0, small_scale};
Point(43) = {0, 0.127, 0, small_scale};
Point(44) = {0, 0.127, -0.159, small_scale};
//
//
Point(45) = {-0.159, 0.127, 0, small_scale};    //  starts 3rd sector
Point(46) = {0, 0.127, 0.159, small_scale};     //  starts 4th sector

//
//  points that define the bottom, outer disk for the solenoid
//
Point(47) = {0.185, 0.127, 0, small_scale};     // starts 1st sector
Point(48) = {0, 0.127, -0.185, small_scale};    // starts 2nd sector
Point(49) = {-0.185, 0.127, 0, small_scale};    // starts 3rd sector
Point(50) = {0, 0.127, 0.185, small_scale};     // starts 4th sector

//
//  points that define the top disk of the left magnet
//
//  1st sector points
//
Point(51) = {-0.21, 2.67, 0, small_scale};              // 1st pt
Point(52) = {-0.369, 2.67, 0, small_scale};             // center
Point(53) = {-0.369, 2.67, -0.159, small_scale};        // rear pt
//
//  remaining points for top disk of left magnet
//
Point(54) = {-0.528, 2.67, 0, small_scale};             // starts 3rd sector
Point(55) = {-0.369, 2.67, 0.159, small_scale}; // starts 4th sector

//
//  points defining the bottom disk for the left magnet
//
Point(56) = {-0.21, 0.127, 0, small_scale};             // starts 1st sector
Point(57) = {-0.369, 0.127, 0, small_scale};            // center
Point(58) = {-0.369, 0.127, -0.159, small_scale};       // ends 1st sector
Point(59) = {-0.528, 0.127, 0, small_scale};            // starts 3rd sector
Point(60) = {-0.369, 0.127, 0.159, small_scale};        // starts 4th sector

//  -------

//
//  points that define the top disk of the right magnet
//
//  1st sector points
//
Point(61) = {0.21, 2.67, 0, small_scale};               // 1st pt
Point(62) = {0.369, 2.67, 0, small_scale};              // center
Point(63) = {0.369, 2.67, -0.159, small_scale}; // rear pt
//
//  remaining points for top disk of left magnet
//
Point(64) = {0.528, 2.67, 0, small_scale};              // starts 3rd sector
Point(65) = {0.369, 2.67, 0.159, small_scale};  // starts 4th sector

//
//  points defining the bottom disk for the right magnet
//
Point(66) = {0.21, 0.127, 0, small_scale};              // starts 1st sector
Point(67) = {0.369, 0.127, 0, small_scale};             // center
Point(68) = {0.369, 0.127, -0.159, small_scale};        // ends 1st sector
Point(69) = {0.528, 0.127, 0, small_scale};             // starts 3rd sector
Point(70) = {0.369, 0.127, 0.159, small_scale}; // starts 4th sector

//
//  top 4 points that define the "glass case", the inner surface of
//  the model space
//
Point(71) = {5, 3.306, 5, large_scale};
Point(72) = {5, 3.306, -5, large_scale};
Point(73) = {-5, 3.306, -5, large_scale};
Point(74) = {-5, 3.306, 5, large_scale};

//
//  4 points at top boundary
//
Point(75) = {-5.5, 4, 5.5, large_scale};
Point(76) = {5.5, 4, 5.5, large_scale};
Point(77) = {5.5, 4, -5.5, large_scale};
Point(78) = {-5.5, 4, -5.5, large_scale};

//
//  4 points at bottom boundary
//
Point(79) = {-5.5, -4, 5.5, large_scale};
Point(80) = {5.5, -4, 5.5, large_scale};
Point(81) = {5.5, -4, -5.5, large_scale};
Point(82) = {-5.5, -4, -5.5, large_scale};

//
//  8 points at the boundary that project from the shield plate
//
Point(83) = {-5.5, 0.0762, 5.5, large_scale2};
Point(84) = {5.5, 0.0762, 5.5, large_scale2};
Point(85) = {5.5, 0.0762, -5.5, large_scale2};
Point(86) = {-5.5, 0.0762, -5.5, large_scale2};
Point(87) = {-5.5, -0.0762, 5.5, large_scale2};
Point(88) = {5.5, -0.0762, 5.5, large_scale2};
Point(89) = {5.5, -0.0762, -5.5, large_scale2};
Point(90) = {-5.5, -0.0762, -5.5, large_scale2};

//
//  spline curve for disk top
//  left, rear
//
CatmullRom (1) = {1, 2, 3, 4, 5};
//
//  spline curve for disk top
//  right, rear
//
CatmullRom (2) = {10, 9, 8, 7, 6};
//
//  spline curve for disk top
//  left, front
//
CatmullRom (3) = {11, 12, 13, 14, 15};
//
//  spline curve for disk top
//  right, front
//
CatmullRom (4) = {20, 19, 18, 17, 16};

//
//  lines closing the spline curve for the disk top
//

//
//  left surface, left side
//
Line (5) = {11, 1};
//
//  left surface, right side (near center)
//
Line (6) = {15, 5};
//
//  right surface, right side
//
Line (7) = {16, 6};
//
//  right surface, left side (near center)
//
Line (8) = {20, 10};

//
//  lines that make the blade face at the rear
//
Line (9) = {5, 21};
Line (10) = {21, 22};
Line (11) = {22, 10};
Line (12) = {10, 5};

//
//  lines that make the blade face at the front
//
Line (13) = {15, 23};
Line (14) = {23, 24};
Line (15) = {24, 20};
Line (16) = {20, 15};

//
//  lines that close the blade top
//
Line (17) = {23, 21};
Line (18) = {24, 22};

//
//  line that closes the bottom of the disk chord -- rear
//
Line (19) = {1, 6};
//
//  line that closes the bottom of the disk chord -- front
//
Line (20) = {11, 16};

//
//  lines that bound the top surface of the shield plate
//
Line (21) = {25, 26};
Line (22) = {26, 27};
Line (23) = {27, 28};
Line (24) = {28, 25};

//
//  lines that bound the bottom surface of the shield plate
//
Line (25) = {29, 30};
Line (26) = {30, 31};
Line (27) = {31, 32};
Line (28) = {32, 29};

//
//  lines at the corners of the shield plate
//
Line (29) = {25, 29};
Line (30) = {26, 30};
Line (31) = {28, 32};
Line (32) = {27, 31};

//
//  Top, Inner Disk for the solenoid
//
//  1st sector arc --  defining the top, inner disk for solenoid
//
Circle (33) = {33, 34, 35} Plane{0, 0, 1};
//
//  2nd sector arc --  defining the top, inner disk for solenoid
//
Circle (34) = {35, 34, 36} Plane{0, 0, 1};
//
//  3rd sector arc --  defining the top, inner disk for solenoid
//
Circle (35) = {36, 34, 37} Plane{0, 0, 1};
//
//  4th sector arc --  defining the top, inner disk for solenoid
//
Circle (36) = {37, 34, 33} Plane{0, 0, 1};

//
//  sectors defining the top, outer disk for the solenoid
//
Circle (37) = {38, 34, 39} Plane{0, 0, 1};      // 1st sector
Circle (38) = {39, 34, 40} Plane{0, 0, 1};      // 2nd sector
Circle (39) = {40, 34, 41} Plane{0, 0, 1};      // 3rd sector
Circle (40) = {41, 34, 38} Plane{0, 0, 1};      // 4th sector

//
//  sectors that define the bottom, inner disk for the solenoid
//
Circle (41) = {42, 43, 44} Plane{0, 0, 1};      // 1st sector
Circle (42) = {44, 43, 45} Plane{0, 0, 1};      // 2nd sector
Circle (43) = {45, 43, 46} Plane{0, 0, 1};      // 3rd sector
Circle (44) = {46, 43, 42} Plane{0, 0, 1};      // 4th sector

//
//  sectors that define the bottom, outer disk for the solenoid
//
Circle (45) = {47, 43, 48} Plane{0, 0, 1};      // 1st sector
Circle (46) = {48, 43, 49} Plane{0, 0, 1};      // 2nd sector
Circle (47) = {49, 43, 50} Plane{0, 0, 1};      // 3rd sector
Circle (48) = {50, 43, 47} Plane{0, 0, 1};      // 4th sector

//
//  sectors that define the top disk for the left magnet
//
Circle (49) = {51, 52, 53} Plane{0, 0, 1};
Circle (50) = {53, 52, 54} Plane{0, 0, 1};
Circle (51) = {54, 52, 55} Plane{0, 0, 1};
Circle (52) = {55, 52, 51} Plane{0, 0, 1};

//
//  sectors defining the bottom disk for the left magnet
//
Circle (53) = {56, 57, 58} Plane{0, 0, 1};
Circle (54) = {58, 57, 59} Plane{0, 0, 1};
Circle (55) = {59, 57, 60} Plane{0, 0, 1};
Circle (56) = {60, 57, 56} Plane{0, 0, 1};

//
//  sectors that define the top disk for the right magnet
//
Circle (57) = {64, 62, 63} Plane{0, 0, 1};
Circle (58) = {63, 62, 61} Plane{0, 0, 1};
Circle (59) = {61, 62, 65} Plane{0, 0, 1};
Circle (60) = {65, 62, 64} Plane{0, 0, 1};

//
//  sectors that define the bottom disk for the right magnet
//
Circle (61) = {69, 67, 68} Plane{0, 0, 1};
Circle (62) = {68, 67, 66} Plane{0, 0, 1};
Circle (63) = {66, 67, 70} Plane{0, 0, 1};
Circle (64) = {70, 67, 69} Plane{0, 0, 1};

//
//  lines that close the "glass case"
//
Line (65) = {1, 29};
Line (66) = {25, 73};
Line (67) = {11, 30};
Line (68) = {26, 74};
Line (69) = {6, 32};
Line (70) = {28, 72};
Line (71) = {16, 31};
Line (72) = {27, 71};
Line (73) = {73, 74};
Line (74) = {74, 71};
Line (75) = {71, 72};
Line (76) = {72, 73};

//
//  lines that extend out from the glass case to the boundary
//  "porquipine lines"
//
Line (77) = {74, 75};
Line (78) = {73, 78};
Line (79) = {72, 77};
Line (80) = {71, 76};
Line (81) = {1, 82};
Line (82) = {11, 79};
Line (83) = {6, 81};
Line (84) = {16, 80};
Line (85) = {26, 83};
Line (86) = {30, 87};
Line (87) = {27, 84};
Line (88) = {31, 88};
Line (89) = {28, 85};
Line (90) = {32, 89};
Line (91) = {25, 86};
Line (92) = {29, 90};

//
//  lines that join all the outer points that form the boundary
//
Line (93) = {78, 77};
Line (94) = {77, 76};
Line (95) = {76, 75};
Line (96) = {75, 78};
Line (97) = {83, 86};
Line (98) = {86, 85};
Line (99) = {85, 84};
Line (100) = {84, 83};
Line (101) = {87, 90};
Line (102) = {90, 89};
Line (103) = {89, 88};
Line (104) = {88, 87};
Line (105) = {82, 81};
Line (106) = {81, 80};
Line (107) = {80, 79};
Line (108) = {79, 82};
Line (109) = {82, 90};
Line (110) = {90, 86};
Line (111) = {86, 78};
Line (112) = {79, 87};
Line (113) = {87, 83};
Line (114) = {83, 75};
Line (115) = {81, 89};
Line (116) = {89, 85};
Line (117) = {85, 77};
Line (118) = {80, 88};
Line (119) = {88, 84};
Line (120) = {84, 76};

//
//  lines that join the top disk to the bottom disk on solenoid
//  inner cylinder  (need for defining the surface)
//
Line (2000144) = {33, 42};
Line (2000145) = {35, 44};
Line (2000146) = {36, 45};
Line (2000147) = {37, 46};

//
//  lines that join the top disk to the bottom disk on solenoid
//  outer cylinder (need for defining the surface)
//
Line (2000148) = {38, 47};
Line (2000149) = {39, 48};
Line (2000150) = {40, 49};
Line (2000151) = {41, 50};

//
//  lines that join the top disk and bottom disk of the left magnet
//
Line (2000152) = {51, 56};
Line (2000153) = {53, 58};
Line (2000154) = {54, 59};
Line (2000155) = {55, 60};

//
//  lines that join the top disk and bottom disk of the right magnet
//
Line (2000156) = {64, 69};
Line (2000157) = {63, 68};
Line (2000158) = {61, 66};
Line (2000159) = {65, 70};

//
//  lines that partition the sectors of the top, inner disk
//  of the solenoid
//
Line (2000160) = {33, 34};
Line (2000161) = {35, 34};
Line (2000162) = {36, 34};
Line (2000163) = {37, 34};

//
//  lines that partition the sectors of the bottom, inner disk
//  of the solenoid
//
Line (2000164) = {42, 43};
Line (2000165) = {44, 43};
Line (2000166) = {45, 43};
Line (2000167) = {46, 43};

//
//  lines that partition the sectors of the top, outer disk
//  of the solenoid
//
Line (2000168) = {38, 33};
Line (2000169) = {39, 35};
Line (2000170) = {40, 36};
Line (2000171) = {41, 37};

//
//  lines that partition the sectors of the bottom, outer disk
//  of the solenoid
//
Line (2000172) = {47, 42};
Line (2000173) = {48, 44};
Line (2000174) = {49, 45};
Line (2000175) = {50, 46};

//
//  lines that partition the sectors on the top disk of left magnet
//
Line (2000176) = {51, 52};
Line (2000177) = {53, 52};
Line (2000178) = {54, 52};
Line (2000179) = {55, 52};

//
//  lines that partition the sectors on the bottom disk of left magnet
//
Line (2000180) = {56, 57};
Line (2000181) = {58, 57};
Line (2000182) = {59, 57};
Line (2000183) = {60, 57};

//
//  lines that partition the sectors of the top disk of the right magnet
//
Line (2000184) = {64, 62};
Line (2000185) = {63, 62};
Line (2000186) = {61, 62};
Line (2000187) = {65, 62};

//
//  lines that partition the sectors of the bottom disk of the right magnet
//
Line (2000188) = {69, 67};
Line (2000189) = {68, 67};
Line (2000190) = {66, 67};
Line (2000191) = {70, 67};

//
//  plane surfaces (6 of them) for the blade
//
Line Loop (1000122) = {14, 15, 16, 13};
Plane Surface (122) = {1000122};
Line Loop (1000124) = {10, 11, 12, 9};
Plane Surface (124) = {1000124};
Line Loop (1000126) = {-12, -8, 16, 6};
Plane Surface (126) = {1000126};
Line Loop (1000128) = {10, -18, -14, 17};
Plane Surface (128) = {1000128};
Line Loop (1000130) = {11, -8, -15, 18};
Plane Surface (130) = {1000130};
Line Loop (1000132) = {-9, -6, 13, 17};
Plane Surface (132) = {1000132};

//
//  plane surfaces for the disk chord (disk below blade)
//
Line Loop (2000134) = {-16, 4, -20, 3};
Plane Surface (1000134) = {2000134};
Line Loop (2000136) = {-12, 2, -19, 1};
Plane Surface (1000136) = {2000136};
Line Loop (2000138) = {7, -2, -8, 4};
Ruled Surface (1000138) = {2000138};
Line Loop (2000140) = {-6, -3, 5, 1};
Ruled Surface (1000140) = {2000140};
Line Loop (2000141) = {-12, -8, 16, 6};
Plane Surface (1000141) = {2000141};
Line Loop (2000143) = {19, -7, -20, 5};
Plane Surface (1000143) = {2000143};

//
// plane surface for the top, inner disk of solenoid
//
Line Loop (3000193) = {-2000161, -33, 2000160};
Plane Surface (2000193) = {3000193};
Line Loop (3000195) = {-2000162, -34, 2000161};
Plane Surface (2000195) = {3000195};
Line Loop (3000197) = {-2000163, -35, 2000162};
Plane Surface (2000197) = {3000197};
Line Loop (3000199) = {-2000160, -36, 2000163};
Plane Surface (2000199) = {3000199};

//
// plane surface for the bottom, inner disk of solenoid
//
Line Loop (4000201) = {-2000165, -41, 2000164};
Plane Surface (3000201) = {4000201};
Line Loop (4000203) = {-2000166, -42, 2000165};
Plane Surface (3000203) = {4000203};
Line Loop (4000205) = {-2000167, -43, 2000166};
Plane Surface (3000205) = {4000205};
Line Loop (4000207) = {-2000164, -44, 2000167};
Plane Surface (3000207) = {4000207};

//
//  plane surface for the inner shell of the solenoid
//
Line Loop (5000209) = {41, -2000145, -33, 2000144};
Ruled Surface (4000209) = {5000209};
Line Loop (5000211) = {42, -2000146, -34, 2000145};
Ruled Surface (4000211) = {5000211};
Line Loop (5000213) = {-43, -2000146, 35, 2000147};
Ruled Surface (4000213) = {5000213};
Line Loop (5000215) = {44, -2000144, -36, 2000147};
Ruled Surface (4000215) = {5000215};


//
//  plane surface for top, outer ring of solenoid
//
Line Loop (6000217) = {33, -2000169, -37, 2000168};
Plane Surface (5000217) = {6000217};
Line Loop (6000219) = {34, -2000170, -38, 2000169};
Plane Surface (5000219) = {6000219};
Line Loop (6000221) = {35, -2000171, -39, 2000170};
Plane Surface (5000221) = {6000221};
Line Loop (6000223) = {36, -2000168, -40, 2000171};
Plane Surface (5000223) = {6000223};

//
//  plane surface for bottom, outer ring of solenoid
//
Line Loop (7000225) = {41, -2000173, -45, 2000172};
Plane Surface (6000225) = {7000225};
Line Loop (7000227) = {42, -2000174, -46, 2000173};
Plane Surface (6000227) = {7000227};
Line Loop (7000229) = {43, -2000175, -47, 2000174};
Plane Surface (6000229) = {7000229};
Line Loop (7000231) = {44, -2000172, -48, 2000175};
Plane Surface (6000231) = {7000231};

//
//  plane surface for the outer shell of the solenoid
//
Line Loop (8000233) = {45, -2000149, -37, 2000148};
Ruled Surface (7000233) = {8000233};
Line Loop (8000235) = {46, -2000150, -38, 2000149};
Ruled Surface (7000235) = {8000235};
Line Loop (8000237) = {47, -2000151, -39, 2000150};
Ruled Surface (7000237) = {8000237};
Line Loop (8000239) = {48, -2000148, -40, 2000151};
Ruled Surface (7000239) = {8000239};

//
//  plane surface for top disk on left magnet
//
Line Loop (9000241) = {-2000177, -49, 2000176};
Plane Surface (8000241) = {9000241};
Line Loop (9000243) = {-2000178, -50, 2000177};
Plane Surface (8000243) = {9000243};
Line Loop (9000245) = {-2000179, -51, 2000178};
Plane Surface (8000245) = {9000245};
Line Loop (9000247) = {-2000176, -52, 2000179};
Plane Surface (8000247) = {9000247};

//
//  plane surface for bottom disk on left magnet
//
Line Loop (10000249) = {-2000181, -53, 2000180};
Plane Surface (9000249) = {10000249};
Line Loop (10000251) = {-2000182, -54, 2000181};
Plane Surface (9000251) = {10000251};
Line Loop (10000253) = {-2000183, -55, 2000182};
Plane Surface (9000253) = {10000253};
Line Loop (10000255) = {-2000180, -56, 2000183};
Plane Surface (9000255) = {10000255};

//
//  plane surface for the shell of the left magnet
//
Line Loop (11000257) = {53, -2000153, -49, 2000152};
Ruled Surface (10000257) = {11000257};
Line Loop (11000259) = {54, -2000154, -50, 2000153};
Ruled Surface (10000259) = {11000259};
Line Loop (11000261) = {-55, -2000154, 51, 2000155};
Ruled Surface (10000261) = {11000261};
Line Loop (11000263) = {56, -2000152, -52, 2000155};
Ruled Surface (10000263) = {11000263};

//
//  plane surface for the top disk of the right magnet
//
Line Loop (12000265) = {-2000185, -57, 2000184};
Plane Surface (11000265) = {12000265};
Line Loop (12000267) = {-2000186, -58, 2000185};
Plane Surface (11000267) = {12000267};
Line Loop (12000269) = {-2000187, -59, 2000186};
Plane Surface (11000269) = {12000269};
Line Loop (12000271) = {-2000184, -60, 2000187};
Plane Surface (11000271) = {12000271};

//
//  plane surface for the bottom disk of the right magnet
//
Line Loop (13000273) = {-2000189, -61, 2000188};
Plane Surface (12000273) = {13000273};
Line Loop (13000275) = {-2000190, -62, 2000189};
Plane Surface (12000275) = {13000275};
Line Loop (13000277) = {-2000191, -63, 2000190};
Plane Surface (12000277) = {13000277};
Line Loop (13000279) = {-2000188, -64, 2000191};
Plane Surface (12000279) = {13000279};

//
//  plane surface for the shell of the right magnet
//
Line Loop (14000281) = {61, -2000157, -57, 2000156};
Ruled Surface (13000281) = {14000281};
Line Loop (14000283) = {62, -2000158, -58, 2000157};
Ruled Surface (13000283) = {14000283};
Line Loop (14000285) = {63, -2000159, -59, 2000158};
Ruled Surface (13000285) = {14000285};
Line Loop (14000287) = {64, -2000156, -60, 2000159};
Ruled Surface (13000287) = {14000287};

//
//  plane surfaces for the shield plate
//
Line Loop (15000289) = {22, 23, 24, 21};
Plane Surface (14000289) = {15000289};
Line Loop (15000291) = {26, 27, 28, 25};
Plane Surface (14000291) = {15000291};
Line Loop (15000293) = {-26, -30, 22, 32};
Plane Surface (14000293) = {15000293};
Line Loop (15000295) = {-27, -32, 23, 31};
Plane Surface (14000295) = {15000295};
Line Loop (15000297) = {-28, -31, 24, 29};
Plane Surface (14000297) = {15000297};
Line Loop (15000299) = {25, -30, -21, 29};
Plane Surface (14000299) = {15000299};

//
//  plane surfaces of infinite abuttment on shield
//
//
//  front
//  (rear surface already defined)
//
Line Loop (16000301) = {100, -113, -104, 119};
Plane Surface (15000301) = {16000301};
Line Loop (16000303) = {119, -87, 32, 88};
Plane Surface (15000303) = {16000303};
Line Loop (16000305) = {86, 113, -85, 30};
Plane Surface (15000305) = {16000305};
//
//  left
//  (outer surface of boundary only)
//
Line Loop (17000307) = {-97, -113, 101, 110};
Plane Surface (16000307) = {17000307};
//
//  right
//  (outer surface of boundary only)
//
Line Loop (18000309) = {99, -119, -103, 116};
Plane Surface (17000309) = {18000309};
//
//  rear
//  (outer surface of boundary and the rear sides
//
//
Line Loop (19000311) = {-98, -110, 102, 116};
Plane Surface (18000311) = {19000311};
Line Loop (19000313) = {92, 110, -91, 29};
Plane Surface (18000313) = {19000313};
Line Loop (19000315) = {116, -89, 31, 90};
Plane Surface (18000315) = {19000315};

//
//  plane surfaces for the infinite wedges above the shield plate
//
//
//  front (top) prism
//  (bottom surface coplanar with the infinite shield prism)
//
Line Loop (20000317) = {87, 100, -85, 22};
Plane Surface (19000317) = {20000317};          // bottom
Line Loop (20000319) = {-77, 74, 80, 95};
Plane Surface (19000319) = {20000319};          // top
Line Loop (20000321) = {77, -114, -85, 68};
Plane Surface (19000321) = {20000321};          // left
Line Loop (20000323) = {-80, -72, 87, 120};
Plane Surface (19000323) = {20000323};          // right
Line Loop (20000325) = {-72, -22, 68, 74};
Plane Surface (19000325) = {20000325};          // back
Line Loop (20000327) = {-114, -100, 120, 95};
Plane Surface (19000327) = {20000327};          // front
//
//  rear (top) prism
//  (bottom surface coplanar with the infinite shield prism)
//
Line Loop (21000329) = {-98, -91, -24, 89};
Plane Surface (20000329) = {21000329};          // bottom
Line Loop (21000331) = {-93, -78, -76, 79};
Plane Surface (20000331) = {21000331};          // top
Line Loop (21000333) = {78, -111, -91, 66};
Plane Surface (20000333) = {21000333};          // left
Line Loop (21000335) = {-79, -70, 89, 117};
Plane Surface (20000335) = {21000335};          // right
Line Loop (21000337) = {76, -66, -24, 70};
Plane Surface (20000337) = {21000337};          // inner
Line Loop (21000339) = {-93, -111, 98, 117};
Plane Surface (20000339) = {21000339};          // far rear
//
//  left (top) prism
//  (side surfaces already defined in first two prisms above
//
Line Loop (22000341) = {-96, -77, -73, 78};
Plane Surface (21000341) = {22000341};          // top
Line Loop (22000343) = {-97, -85, -21, 91};
Plane Surface (21000343) = {22000343};          // bottom
Line Loop (22000345) = {73, -68, -21, 66};
Plane Surface (21000345) = {22000345};          // inner
Line Loop (22000347) = {-96, -114, 97, 111};
Plane Surface (21000347) = {22000347};          //  far left
//
//  right (top) prism
//  (side surfaces already defined in first two prisms above
//
Line Loop (23000349) = {94, -80, 75, 79};
Plane Surface (22000349) = {23000349};          // top
Line Loop (23000351) = {-99, -89, -23, 87};
Plane Surface (22000351) = {23000351};          // bottom
Line Loop (23000353) = {-75, -72, 23, 70};
Plane Surface (22000353) = {23000353};          // inner
Line Loop (23000355) = {94, -120, -99, 117};
Plane Surface (22000355) = {23000355};          // far right
//
//  top (top) prism
//  (side surfaces on all 4 sides already defined)
//
Line Loop (24000357) = {73, 74, 75, 76};
Plane Surface (23000357) = {24000357};
Line Loop (24000359) = {94, 95, 96, 93};
Plane Surface (23000359) = {24000359};

//
//  plane surfaces for the infinite wedges below the shield plate
//
//
//  front (below) prism
//
Line Loop (25000361) = {-104, -88, -26, 86};
Plane Surface (24000361) = {25000361};          // top
Line Loop (25000363) = {84, 107, -82, 20};
Plane Surface (24000363) = {25000363};          // bottom
//Line Loop (25000365) = {-71, -20, 67, 26};
//Plane Surface (24000365) = {25000365};                // inner
Line Loop (25000365) = {15, 4, 71, -26, -67, 3, 13, 14};
Plane Surface (24000365) = {25000365};
Line Loop (25000367) = {-112, -107, 118, 104};
Plane Surface (24000367) = {25000367};          // nearest front
//
//  rear (below) prism
//
Line Loop (26000369) = {-90, 28, 92, 102};
Plane Surface (25000369) = {26000369};          // top
Line Loop (26000371) = {-105, -81, 19, 83};
Plane Surface (25000371) = {26000371};          // bottom
//Line Loop (26000373) = {28, -65, 19, 69};
//Plane Surface (25000373) = {26000373};                // inner
Line Loop (26000373) = {2, 69, 28, -65, 1, 9, 10, 11};
Plane Surface (25000373) = {26000373};
Line Loop (26000375) = {-102, -109, 105, 115};
Plane Surface (25000375) = {26000375};          // far rear
//
//  left (below) prism
//
Line Loop (27000377) = {-101, -86, -25, 92};
Plane Surface (26000377) = {27000377};          // top
Line Loop (27000379) = {-108, -82, 5, 81};
Plane Surface (26000379) = {27000379};          // bottom
Line Loop (27000381) = {109, -92, -65, 81};
Plane Surface (26000381) = {27000381};          // left (rear)
Line Loop (27000383) = {86, -112, -82, 67};
Plane Surface (26000383) = {27000383};          // right (front)
Line Loop (27000385) = {25, -67, 5, 65};
Plane Surface (26000385) = {27000385};          // inner
Line Loop (27000387) = {-101, -112, 108, 109};
Plane Surface (26000387) = {27000387};          // outside left
//
//  right (below) prism
//
Line Loop (28000389) = {-103, -90, -27, 88};
Plane Surface (27000389) = {28000389};          // top
Line Loop (28000391) = {106, -84, 7, 83};
Plane Surface (27000391) = {28000391};          // bottom
Line Loop (28000393) = {-90, -69, 83, 115};
Plane Surface (27000393) = {28000393};          // left (rear)
Line Loop (28000395) = {-88, -71, 84, 118};
Plane Surface (27000395) = {28000395};          // right (front)
Line Loop (28000397) = {-27, -71, 7, 69};
Plane Surface (27000397) = {28000397};          // inner
Line Loop (28000399) = {103, -118, -106, 115};
Plane Surface (27000399) = {28000399};          // ouside right

//
//  plane surface closing the bottom-most prism, under the disk
//
Line Loop (29000401) = {105, 106, 107, 108};
Plane Surface (28000401) = {29000401};

//
//  (rework)
// inner surface for front, lower air prism
//
//Line Loop (47000437) = {15, 4, 71, -26, -67, 3, 13, 14};
//Plane Surface (46000437) = {47000437};

//
//  (rework)
// inner surface for rear, lower air prism
//
//Line Loop (48000439) = {2, 69, 28, -65, 1, 9, 10, 11};
//Plane Surface (47000439) = {48000439};

//
// -----------------------------------------------------------------------
//  Geometric Volumes
// -----------------------------------------------------------------------
//

//
//  Volume for the Disk below the blade
//
Surface Loop (30000403) = {1000141, 1000136, 1000138, 1000143, 1000134,
1000140};
Volume (29000403) = {30000403};

//
//  Volume for the blade
//
Surface Loop (31000405) = {1000141, 124, 128, 130, 122, 132};
Volume (30000405) = {31000405};

//
//  Volume for the shield plate
//
Surface Loop (32000407) = {14000291, 14000293, 14000299, 14000289, 14000295,
14000297};
Volume (31000407) = {32000407};

//
//  Volume for the Solenoid core
//
Surface Loop (33000409) = {2000193, 2000195, 2000197, 2000199, 4000215,
3000207, 3000201, 3000203, 3000205, 4000213, 4000211, 4000209};
Volume (32000409) = {33000409};

//
//  Volume for the Left Magnet core
//
Surface Loop (34000411) = {10000257, 9000249, 9000251, 9000253, 9000255,
10000263, 8000247, 8000241, 8000243, 8000245, 10000261, 10000259};
Volume (33000411) = {34000411};

//
//  Volume for the Right Magnet core
//
Surface Loop (35000413) = {13000281, 12000273, 12000275, 12000277, 12000279,
13000287, 11000271, 11000265, 11000267, 11000269, 13000285, 13000283};
Volume (34000413) = {35000413};

//
//  Volume for the Solenoid windings shell
//
Surface Loop (36000415) = {4000213, 6000229, 6000231, 4000215, 4000209,
6000225, 6000227, 4000211, 5000219, 5000221, 5000223, 5000217, 7000233,
7000235, 7000237, 7000239};
Volume (35000415) = {36000415};

//
//
//  Volume for the shield plate edge prisms
//
//
//  front prism
//
Surface Loop (37000417) = {24000361, 15000301, 19000317, 15000303, 14000293,
15000305};
Volume (36000417) = {37000417};
//
//  rear prism
//
Surface Loop (38000419) = {18000315, 18000311, 20000329, 18000313, 25000369,
14000297};
Volume (37000419) = {38000419};
//
//  left prism
//
Surface Loop (39000421) = {18000313, 26000377, 16000307, 21000343, 15000305,
14000299};
Volume (38000421) = {39000421};
//
//  right prism
//
Surface Loop (40000423) = {18000315, 17000309, 22000351, 14000295, 27000389,
15000303};
Volume (39000423) = {40000423};

//
//
//  Volume for the upper, air prisms
//
//
//
//  left prism
//
Surface Loop (41000425) = {20000333, 21000341, 21000347, 19000321, 21000343,
21000345};
Volume (40000425) = {41000425};
//
//  right prism
//
Surface Loop (42000427) = {20000335, 22000349, 22000355, 19000323, 22000353,
22000351};
Volume (41000427) = {42000427};
//
//  front prism
//
Surface Loop (43000429) = {19000325, 19000323, 19000319, 19000321, 19000327,
19000317};
Volume (42000429) = {43000429};
//
//  rear prism
//
Surface Loop (44000431) = {20000337, 20000331, 20000339, 20000333, 20000329,
20000335};
Volume (43000431) = {44000431};
//
//  top prism
//
Surface Loop (45000433) = {23000357, 21000341, 23000359, 22000349, 19000319,
20000331};
Volume (44000433) = {45000433};

//
//
//  Volume for the bottom (beneath Disk) prism
//
//
Surface Loop (46000435) = {1000143, 25000371, 28000401, 27000391, 24000363,
26000379};
Volume (45000435) = {46000435};

//
//
//  Volumes for the lower, air prisms
//
//
//  The front prism
//
Surface Loop (47000437) = {122, 24000365, 1000134, 24000363, 27000395,
24000361, 24000367, 26000383};
Volume (46000437) = {47000437};
//
//  The rear prism
//
Surface Loop (48000439) = {124, 25000373, 1000136, 25000371, 25000375,
25000369, 27000393, 26000381};
Volume (47000439) = {48000439};
//
//  The left prism
//
Surface Loop (49000441) = {26000387, 26000377, 26000383, 26000379, 26000385,
26000381};
Volume (48000441) = {49000441};
//
//  The right prism
//
Surface Loop (50000443) = {27000397, 27000389, 27000399, 27000395, 27000391,
27000393};
Volume (49000443) = {50000443};

//
//  Volume for Top Air Gap
//
Surface Loop (51000446) = {20000337, 23000357, 21000345, 19000325, 22000353,
14000289, 3000205, 3000207, 3000201, 3000203, 6000227, 6000229, 6000231,
6000225, 7000233, 7000235, 7000237, 7000239, 5000223, 2000199, 2000193,
2000195, 2000197, 5000221, 5000219, 5000217, 13000281, 12000273, 12000275,
12000277, 12000279, 13000287, 11000271, 11000265, 11000267, 11000269,
13000285, 13000283, 10000257, 9000249, 9000251, 9000253, 9000255, 10000263,
8000247, 8000241, 8000243, 8000245, 10000261, 10000259};
Volume (50000446) = {51000446};

//
//  Volume for the Bottom Air Gap
//
Surface Loop (52000448) = {1000140, 132, 25000373, 1000138, 27000397,
14000291, 24000365, 130, 128, 26000385};
Volume (51000448) = {52000448};

//
//  ----------------------------------------------------------------------
//
//  Physical Regions
//
//  ----------------------------------------------------------------------
//

//
//  Region 1  --  The outer, enclosing surface
//
Physical Surface (1) = {19000327, 24000367, 15000301, 22000355, 27000399,
17000309, 25000375, 20000339, 18000311, 21000347, 26000387, 16000307,
23000359, 28000401};
//
// Region 2 -- top surface of left magnet
//
Physical Surface (2) = {8000241, 8000247, 8000245, 8000243};
//
// Region 3 -- bottom surface of left magnet
//
Physical Surface (3) = {9000249, 9000255, 9000253, 9000251};
//
// Region 4 -- top surface of right magnet
//
Physical Surface (4) = {11000265, 11000267, 11000269, 11000271};
//
// Region 5 -- bottom surface of right magnet
//
Physical Surface (5) = {12000273, 12000275, 12000277, 12000279};

//
//  Region 6 -- Solenoid Core Volume
//
Physical Volume (6) = {32000409};
//
//  Region 7 -- Solenoid windings shell Volume
//
Physical Volume (7) = {35000415};
//
//  Region 8 -- Left Magnet Core Volume
//
Physical Volume (8) = {33000411};
//
//  Region 9 -- Right Magnet Core Volume
//
Physical Volume (9) = {34000413};
//
//  Region 10 -- shield plate Volume
//
Physical Volume (10) = {31000407};
//
//  Region 11 -- Blade
//
Physical Volume (11) = {30000405};
//
//  Region 12 -- Disk under Blade
//
Physical Volume (12) = {29000403};

//
//  Regions for the Infinte Prisms
//
//
//  Top Prisms
//
// Region 13 -- top, front air
//
Physical Volume (13) = {42000429};
//
// Region 14 -- top, rear air
//
Physical Volume (14) = {43000431};
//
// Region 15 -- top, left air
//
Physical Volume (15) = {40000425};
//
// Region 16 -- top, right air
//
Physical Volume (16) = {41000427};
//
// Region 17 -- top, top air
//
Physical Volume (17) = {44000433};

//
//  Shield plate Prisms
//
//
//  Region 18 -- shield front
//
Physical Volume (18) = {36000417};
//
//  Region 19 -- shield rear
//
Physical Volume (19) = {37000419};
//
//  Region 20 -- shield left
//
Physical Volume (20) = {38000421};
//
//  Region 21 -- shield right
//
Physical Volume (21) = {39000423};

//
//  Infinite Prisms for the Bottom Air
//
//
//
//  Region 22 -- bottom, front air prism
//
Physical Volume (22) = {46000437};
//
//  Region 23 -- bottom, rear air prism
//
Physical Volume (23) = {47000439};
//
//  Region 24 -- bottom, left air prism
//
Physical Volume (24) = {48000441};
//
//  Region 25 -- bottom, right air prism
//
Physical Volume (25) = {49000443};

//
//  Infinite  Prism  beneath the Disk
//
//
//  Region 26 -- prism under the disk
//
Physical Volume (26) = {45000435};

//
//  Physical Volume for the Top Air Gap
//
//  Region 27
//
Physical Volume (27) = {50000446};

//
//  Physical Volume for the Bottom Air Gap
//
//  Region 28
//
Physical Volume (28) = {51000448};

//  end .geo file

