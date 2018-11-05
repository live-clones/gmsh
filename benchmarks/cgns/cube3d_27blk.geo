//++++++++++++++++++++++++++++++++++++++++ Z = 0.0 +++++++++++++++++++++++++++++
//+
Point(1) = {0.0, 0.0, 0.0, 0.1};
//+
Point(2) = {0.1, 0.0, 0.0, 0.1};
//+
Point(3) = {0.3, 0.0, 0.0, 0.1};
//+
Point(4) = {0.6, 0.0, 0.0, 0.1};
//+
Point(5) = {0.0, 0.1, 0.0, 0.1};
//+
Point(6) = {0.1, 0.1, 0.0, 0.1};
//+
Point(7) = {0.3, 0.1, 0.0, 0.1};
//+
Point(8) = {0.6, 0.1, 0.0, 0.1};
//+
Point(9) = {0.0, 0.3, 0.0, 0.1};
//+
Point(10) = {0.1, 0.3, 0.0, 0.1};
//+
Point(11) = {0.3, 0.3, 0.0, 0.1};
//+
Point(12) = {0.6, 0.3, 0.0, 0.1};
//+
Point(13) = {0.0, 0.6, 0.0, 0.1};
//+
Point(14) = {0.1, 0.6, 0.0, 0.1};
//+
Point(15) = {0.3, 0.6, 0.0, 0.1};
//+
Point(16) = {0.6, 0.6, 0.0, 0.1};

//+
Line(1) = {1, 2};
//+
Line(2) = {2, 3};
//+
Line(3) = {3, 4};
//+
Line(4) = {5, 6};
//+
Line(5) = {6, 7};
//+
Line(6) = {7, 8};
//+
Line(7) = {9, 10};
//+
Line(8) = {10, 11};
//+
Line(9) = {11, 12};
//+
Line(10) = {13, 14};
//+
Line(11) = {14, 15};
//+
Line(12) = {15, 16};
//+
Line(13) = {1, 5};
//+
Line(14) = {5, 9};
//+
Line(15) = {9, 13};
//+
Line(16) = {2, 6};
//+
Line(17) = {6, 10};
//+
Line(18) = {10, 14};
//+
Line(19) = {3, 7};
//+
Line(20) = {7, 11};
//+
Line(21) = {11, 15};
//+
Line(22) = {4, 8};
//+
Line(23) = {8, 12};
//+
Line(24) = {12, 16};

//+
Curve Loop(1) = {1, 16, -4, -13};
//+
Surface(1) = {1};
//+
Curve Loop(2) = {2, 19, -5, -16};
//+
Surface(2) = {2};
//+
Curve Loop(3) = {3, 22, -6, -19};
//+
Surface(3) = {3};
//+
Curve Loop(4) = {4, 17, -7, -14};
//+
Surface(4) = {4};
//+
Curve Loop(5) = {5, 20, -8, -17};
//+
Surface(5) = {5};
//+
Curve Loop(6) = {6, 23, -9, -20};
//+
Surface(6) = {6};
//+
Curve Loop(7) = {7, 18, -10, -15};
//+
Surface(7) = {7};
//+
Curve Loop(8) = {8, 21, -11, -18};
//+
Surface(8) = {8};
//+
Curve Loop(9) = {9, 24, -12, -21};
//+
Surface(9) = {9};

//+
Transfinite Curve {1, 4, 7, 10} = 11 Using Progression 1;
//+
Transfinite Curve {13, 16, 19, 22} = 11 Using Progression 1;
//+
Transfinite Curve {2, 5, 8, 11} = 21 Using Progression 1;
//+
Transfinite Curve {14, 17, 20, 23} = 21 Using Progression 1;
//+
Transfinite Curve {3, 6, 9, 12} = 31 Using Progression 1;
//+
Transfinite Curve {15, 18, 21, 24} = 31 Using Progression 1;

//+
Transfinite Surface {1} = {1, 2, 6, 5};
//+
Transfinite Surface {2} = {2, 3, 7, 6};
//+
Transfinite Surface {3} = {3, 4, 8, 7};
//+
Transfinite Surface {4} = {5, 6, 10, 9};
//+
Transfinite Surface {5} = {6, 7, 11, 10};
//+
Transfinite Surface {6} = {7, 8, 12, 11};
//+
Transfinite Surface {7} = {9, 10, 14, 13};
//+
Transfinite Surface {8} = {10, 11, 15, 14};
//+
Transfinite Surface {9} = {11, 12, 16, 15};


//++++++++++++++++++++++++++++++++++++++++ Z = 0.1 +++++++++++++++++++++++++++++
//+
Point(17) = {0.0, 0.0, 0.2, 0.1};
//+
Point(18) = {0.1, 0.0, 0.2, 0.1};
//+
Point(19) = {0.3, 0.0, 0.2, 0.1};
//+
Point(20) = {0.6, 0.0, 0.2, 0.1};
//+
Point(21) = {0.0, 0.1, 0.2, 0.1};
//+
Point(22) = {0.1, 0.1, 0.2, 0.1};
//+
Point(23) = {0.3, 0.1, 0.2, 0.1};
//+
Point(24) = {0.6, 0.1, 0.2, 0.1};
//+
Point(25) = {0.0, 0.3, 0.2, 0.1};
//+
Point(26) = {0.1, 0.3, 0.2, 0.1};
//+
Point(27) = {0.3, 0.3, 0.2, 0.1};
//+
Point(28) = {0.6, 0.3, 0.2, 0.1};
//+
Point(29) = {0.0, 0.6, 0.2, 0.1};
//+
Point(30) = {0.1, 0.6, 0.2, 0.1};
//+
Point(31) = {0.3, 0.6, 0.2, 0.1};
//+
Point(32) = {0.6, 0.6, 0.2, 0.1};

//+
Line(25) = {17, 18};
//+
Line(26) = {18, 19};
//+
Line(27) = {19, 20};
//+
Line(28) = {21, 22};
//+
Line(29) = {22, 23};
//+
Line(30) = {23, 24};
//+
Line(31) = {25, 26};
//+
Line(32) = {26, 27};
//+
Line(33) = {27, 28};
//+
Line(34) = {29, 30};
//+
Line(35) = {30, 31};
//+
Line(36) = {31, 32};
//+
Line(37) = {17, 21};
//+
Line(38) = {21, 25};
//+
Line(39) = {25, 29};
//+
Line(40) = {18, 22};
//+
Line(41) = {22, 26};
//+
Line(42) = {26, 30};
//+
Line(43) = {19, 23};
//+
Line(44) = {23, 27};
//+
Line(45) = {27, 31};
//+
Line(46) = {20, 24};
//+
Line(47) = {24, 28};
//+
Line(48) = {28, 32};

//+
Curve Loop(10) = {25, 40, -28, -37};
//+
Surface(10) = {10};
//+
Curve Loop(11) = {26, 43, -29, -40};
//+
Surface(11) = {11};
//+
Curve Loop(12) = {27, 46, -30, -43};
//+
Surface(12) = {12};
//+
Curve Loop(13) = {28, 41, -31, -38};
//+
Surface(13) = {13};
//+
Curve Loop(14) = {29, 44, -32, -41};
//+
Surface(14) = {14};
//+
Curve Loop(15) = {30, 47, -33, -44};
//+
Surface(15) = {15};
//+
Curve Loop(16) = {31, 42, -34, -39};
//+
Surface(16) = {16};
//+
Curve Loop(17) = {32, 45, -35, -42};
//+
Surface(17) = {17};
//+
Curve Loop(18) = {33, 48, -36, -45};
//+
Surface(18) = {18};

//+
Transfinite Curve {25, 28, 31, 34} = 11 Using Progression 1;
//+
Transfinite Curve {37, 40, 43, 46} = 11 Using Progression 1;
//+
Transfinite Curve {26, 29, 32, 35} = 21 Using Progression 1;
//+
Transfinite Curve {38, 41, 44, 47} = 21 Using Progression 1;
//+
Transfinite Curve {27, 30, 33, 36} = 31 Using Progression 1;
//+
Transfinite Curve {39, 42, 45, 48} = 31 Using Progression 1;

//+
Transfinite Surface {10} = {17, 18, 22, 21};
//+
Transfinite Surface {11} = {18, 19, 23, 22};
//+
Transfinite Surface {12} = {19, 20, 24, 23};
//+
Transfinite Surface {13} = {21, 22, 26, 25};
//+
Transfinite Surface {14} = {22, 23, 27, 26};
//+
Transfinite Surface {15} = {23, 24, 28, 27};
//+
Transfinite Surface {16} = {25, 26, 30, 29};
//+
Transfinite Surface {17} = {26, 27, 31, 30};
//+
Transfinite Surface {18} = {27, 28, 32, 31};

//++++++++++++++++ In between Z=0 to Z=0.1 ++++++++++++++++++++++
//+
Line(49) = {1, 17};
//+
Line(50) = {2, 18};
//+
Line(51) = {3, 19};
//+
Line(52) = {4, 20};
//+
Line(53) = {5, 21};
//+
Line(54) = {6, 22};
//+
Line(55) = {7, 23};
//+
Line(56) = {8, 24};
//+
Line(57) = {9, 25};
//+
Line(58) = {10, 26};
//+
Line(59) = {11, 27};
//+
Line(60) = {12, 28};
//+
Line(61) = {13, 29};
//+
Line(62) = {14, 30};
//+
Line(63) = {15, 31};
//+
Line(64) = {16, 32};

//+
Curve Loop(19) = {-13, -53, 37, 49};
//+
Surface(19) = {19};
//+
Curve Loop(20) = {50, 40, -54, -16};
//+
Surface(20) = {20};
//+
Curve Loop(21) = {-19, -55, 43, 51};
//+
Surface(21) = {21};
//+
Curve Loop(22) = {-22, -56, 46, 52};
//+
Surface(22) = {22};
//+
Curve Loop(23) = {-14, -57, 38, 53};
//+
Surface(23) = {23};
//+
Curve Loop(24) = {-17, -58, 41, 54};
//+
Surface(24) = {24};
//+
Curve Loop(25) = {-20, -59, 44, 55};
//+
Surface(25) = {25};
//+
Curve Loop(26) = {-23, -60, 47, 56};
//+
Surface(26) = {26};
//+
Curve Loop(27) = {-15, -61, 39, 57};
//+
Surface(27) = {27};
//+
Curve Loop(28) = {-18, -62, 42, 58};
//+
Surface(28) = {28};
//+
Curve Loop(29) = {-21, -63, 45, 59};
//+
Surface(29) = {29};
//+
Curve Loop(30) = {-24, -64, 48, 60};
//+
Surface(30) = {30};

//+
Curve Loop(31) = {49, 25, -50, -1};
//+
Surface(31) = {31};
//+
Curve Loop(32) = {53, 28, -54, -4};
//+
Surface(32) = {32};
//+
Curve Loop(33) = {57, 31, -58, -7};
//+
Surface(33) = {33};
//+
Curve Loop(34) = {61, 34, -62, -10};
//+
Surface(34) = {34};
//+
Curve Loop(35) = {50, 26, -51, -2};
//+
Surface(35) = {35};
//+
Curve Loop(36) = {54, 29, -55, -5};
//+
Surface(36) = {36};
//+
Curve Loop(37) = {58, 32, -59, -8};
//+
Surface(37) = {37};
//+
Curve Loop(38) = {62, 35, -63, -11};
//+
Surface(38) = {38};
//+
Curve Loop(39) = {51, 27, -52, -3};
//+
Surface(39) = {39};
//+
Curve Loop(40) = {55, 30, -56, -6};
//+
Surface(40) = {40};
//+
Curve Loop(41) = {59, 33, -60, -9};
//+
Surface(41) = {41};
//+
Curve Loop(42) = {63, 36, -64, -12};
//+
Surface(42) = {42};

//+
Transfinite Curve {49, 50, 51, 52, 53, 54, 55, 56} = 11 Using Progression 1;
Transfinite Curve {57, 58, 59, 60, 61, 62, 63, 64} = 11 Using Progression 1;

//+
Transfinite Surface {19} = {1, 5, 21, 17};
//+
Transfinite Surface {20} = {2, 6, 22, 18};
//+
Transfinite Surface {21} = {3, 7, 23, 19};
//+
Transfinite Surface {22} = {4, 8, 24, 20};
//+
Transfinite Surface {23} = {5, 9, 25, 21};
//+
Transfinite Surface {24} = {6, 10, 26, 22};
//+
Transfinite Surface {25} = {7, 11, 27, 23};
//+
Transfinite Surface {26} = {8, 12, 28, 24};
//+
Transfinite Surface {27} = {9, 13, 29, 25};
//+
Transfinite Surface {28} = {10, 14, 30, 26};
//+
Transfinite Surface {29} = {11, 15, 31, 27};
//+
Transfinite Surface {30} = {12, 16, 32, 28};

//+
Transfinite Surface {31} = {1, 17, 18, 2};
//+
Transfinite Surface {32} = {5, 21, 22, 6};
//+
Transfinite Surface {33} = {9, 25, 26, 10};
//+
Transfinite Surface {34} = {13, 29, 30, 14};
//+
Transfinite Surface {35} = {2, 18, 19, 3};
//+
Transfinite Surface {36} = {6, 22, 23, 7};
//+
Transfinite Surface {37} = {10, 26, 27, 11};
//+
Transfinite Surface {38} = {14, 30, 31, 15};
//+
Transfinite Surface {39} = {3, 19, 20, 4};
//+
Transfinite Surface {40} = {7, 23, 24, 8};
//+
Transfinite Surface {41} = {11, 27, 28, 12};
//+
Transfinite Surface {42} = {15, 31, 32, 16};

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++  Common Volume +++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+
Surface Loop(1) = {20, 32, 1, 31, 19, 10};
//+
Volume(1) = {1};
//+
Surface Loop(2) = {20, 36, 11, 35, 2, 21};
//+
Volume(2) = {2};
//+
Surface Loop(3) = {22, 3, 39, 12, 21, 40};
//+
Volume(3) = {3};
//+
Surface Loop(4) = {23, 4, 13, 32, 33, 24};
//+
Volume(4) = {4};
//+
Surface Loop(5) = {5, 14, 25, 24, 37, 36};
//+
Volume(5) = {5};
//+
Surface Loop(6) = {15, 26, 6, 41, 40, 25};
//+
Volume(6) = {6};
//+
Surface Loop(7) = {27, 7, 34, 16, 33, 28};
//+
Volume(7) = {7};
//+
Surface Loop(8) = {38, 17, 8, 29, 28, 37};
//+
Volume(8) = {8};
//+
Surface Loop(9) = {42, 18, 30, 9, 41, 29};
//+
Volume(9) = {9};

//+
Transfinite Volume{1} = {1, 2, 6, 5, 17, 18, 22, 21};
//+
Transfinite Volume{2} = {2, 3, 7, 6, 18, 19, 23, 22};
//+
Transfinite Volume{3} = {3, 4, 8, 7, 19, 20, 24, 23};
//+
Transfinite Volume{4} = {5, 6, 10, 9, 21, 22, 26, 25};
//+
Transfinite Volume{5} = {6, 7, 11, 10, 22, 23, 27, 26};
//+
Transfinite Volume{6} = {7, 8, 12, 11, 23, 24, 28, 27};
//+
Transfinite Volume{7} = {9, 10, 14, 13, 25, 26, 30, 29};
//+
Transfinite Volume{8} = {10, 11, 15, 14, 26, 27, 31, 30};
//+
Transfinite Volume{9} = {11, 12, 16, 15, 27, 28, 32, 31};





//++++++++++++++++++++++ Z = 0.5 ++++++++++++++++++++++++++
//+
Point(33) = {0.0, 0.0, 0.5, 0.1};
//+
Point(34) = {0.1, 0.0, 0.5, 0.1};
//+
Point(35) = {0.3, 0.0, 0.5, 0.1};
//+
Point(36) = {0.6, 0.0, 0.5, 0.1};
//+
Point(37) = {0.0, 0.1, 0.5, 0.1};
//+
Point(38) = {0.1, 0.1, 0.5, 0.1};
//+
Point(39) = {0.3, 0.1, 0.5, 0.1};
//+
Point(40) = {0.6, 0.1, 0.5, 0.1};
//+
Point(41) = {0.0, 0.3, 0.5, 0.1};
//+
Point(42) = {0.1, 0.3, 0.5, 0.1};
//+
Point(43) = {0.3, 0.3, 0.5, 0.1};
//+
Point(44) = {0.6, 0.3, 0.5, 0.1};
//+
Point(45) = {0.0, 0.6, 0.5, 0.1};
//+
Point(46) = {0.1, 0.6, 0.5, 0.1};
//+
Point(47) = {0.3, 0.6, 0.5, 0.1};
//+
Point(48) = {0.6, 0.6, 0.5, 0.1};

//+
Line(65) = {33, 34};
//+
Line(66) = {34, 35};
//+
Line(67) = {35, 36};
//+
Line(68) = {37, 38};
//+
Line(69) = {38, 39};
//+
Line(70) = {39, 40};
//+
Line(71) = {41, 42};
//+
Line(72) = {42, 43};
//+
Line(73) = {43, 44};
//+
Line(74) = {45, 46};
//+
Line(75) = {46, 47};
//+
Line(76) = {47, 48};
//+
Line(77) = {33, 37};
//+
Line(78) = {37, 41};
//+
Line(79) = {41, 45};
//+
Line(80) = {34, 38};
//+
Line(81) = {38, 42};
//+
Line(82) = {42, 46};
//+
Line(83) = {35, 39};
//+
Line(84) = {39, 43};
//+
Line(85) = {43, 47};
//+
Line(86) = {36, 40};
//+
Line(87) = {40, 44};
//+
Line(88) = {44, 48};

//+
Curve Loop(43) = {65, 80, -68, -77};
//+
Surface(43) = {43};
//+
Curve Loop(44) = {66, 83, -69, -80};
//+
Surface(44) = {44};
//+
Curve Loop(45) = {67, 86, -70, -83};
//+
Surface(45) = {45};
//+
Curve Loop(46) = {68, 81, -71, -78};
//+
Surface(46) = {46};
//+
Curve Loop(47) = {69, 84, -72, -81};
//+
Surface(47) = {47};
//+
Curve Loop(48) = {70, 87, -73, -84};
//+
Surface(48) = {48};
//+
Curve Loop(49) = {71, 82, -74, -79};
//+
Surface(49) = {49};
//+
Curve Loop(50) = {72, 85, -75, -82};
//+
Surface(50) = {50};
//+
Curve Loop(51) = {73, 88, -76, -85};
//+
Surface(51) = {51};

//++++++++++++++++++++++ In Between Z = 0.2 and Z = 0.5 ++++++++++++++++++++++++++
//+
Line(89) = {17, 33};
//+
Line(90) = {18, 34};
//+
Line(91) = {19, 35};
//+
Line(92) = {20, 36};
//+
Line(93) = {21, 37};
//+
Line(94) = {22, 38};
//+
Line(95) = {23, 39};
//+
Line(96) = {24, 40};
//+
Line(97) = {25, 41};
//+
Line(98) = {26, 42};
//+
Line(99) = {27, 43};
//+
Line(100) = {28, 44};
//+
Line(101) = {29, 45};
//+
Line(102) = {30, 46};
//+
Line(103) = {31, 47};
//+
Line(104) = {32, 48};

//+
Curve Loop(52) = {89, 77, -93, -37};
//+
Surface(52) = {52};
//+
Curve Loop(53) = {90, 80, -94, -40};
//+
Surface(53) = {53};
//+
Curve Loop(54) = {91, 83, -95, -43};
//+
Surface(54) = {54};
//+
Curve Loop(55) = {92, 86, -96, -46};
//+
Surface(55) = {55};
//+
Curve Loop(56) = {93, 78, -97, -38};
//+
Surface(56) = {56};
//+
Curve Loop(57) = {94, 81, -98, -41};
//+
Surface(57) = {57};
//+
Curve Loop(58) = {95, 84, -99, -44};
//+
Surface(58) = {58};
//+
Curve Loop(59) = {96, 87, -100, -47};
//+
Surface(59) = {59};
//+
Curve Loop(60) = {97, 79, -101, -39};
//+
Surface(60) = {60};
//+
Curve Loop(61) = {98, 82, -102, -42};
//+
Surface(61) = {61};
//+
Curve Loop(62) = {99, 85, -103, -45};
//+
Surface(62) = {62};
//+
Curve Loop(63) = {100, 88, -104, -48};
//+
Surface(63) = {63};
//+
Curve Loop(64) = {89, 65, -90, -25};
//+
Surface(64) = {64};
//+
Curve Loop(65) = {93, 68, -94, -28};
//+
Surface(65) = {65};
//+
Curve Loop(66) = {97, 71, -98, -31};
//+
Surface(66) = {66};
//+
Curve Loop(67) = {101, 74, -102, -34};
//+
Surface(67) = {67};
//+
Curve Loop(68) = {90, 66, -91, -26};
//+
Surface(68) = {68};
//+
Curve Loop(69) = {94, 69, -95, -29};
//+
Surface(69) = {69};
//+
Curve Loop(70) = {98, 72, -99, -32};
//+
Surface(70) = {70};
//+
Curve Loop(71) = {102, 75, -103, -35};
//+
Surface(71) = {71};
//+
Curve Loop(72) = {91, 67, -92, -27};
//+
Surface(72) = {72};
//+
Curve Loop(73) = {95, 70, -96, -30};
//+
Surface(73) = {73};
//+
Curve Loop(74) = {99, 73, -100, -33};
//+
Surface(74) = {74};
//+
Curve Loop(75) = {103, 76, -104, -36};
//+
Surface(75) = {75};

//+
Surface Loop(10) = {52, 64, 43, 10, 53, 65};
//+
Volume(10) = {10};
//+
Surface Loop(11) = {44, 68, 53, 54, 69, 11};
//+
Volume(11) = {11};
//+
Surface Loop(12) = {45, 72, 55, 54, 12, 73};
//+
Volume(12) = {12};
//+
Surface Loop(13) = {46, 56, 65, 66, 57, 13};
//+
Volume(13) = {13};
//+
Surface Loop(14) = {47, 58, 57, 69, 70, 14};
//+
Volume(14) = {14};
//+
Surface Loop(15) = {48, 59, 73, 58, 15, 74};
//+
Volume(15) = {15};
//+
Surface Loop(16) = {49, 67, 60, 66, 16, 61};
//+
Volume(16) = {16};
//+
Surface Loop(17) = {50, 71, 61, 17, 70, 62};
//+
Volume(17) = {17};
//+
Surface Loop(18) = {51, 63, 75, 62, 18, 74};
//+
Volume(18) = {18};

//+
Transfinite Curve {101, 97, 93, 89, 102, 98, 94, 90, 103, 99, 95, 91, 104, 100, 96, 92} = 21 Using Progression 1;

//+
Transfinite Curve {65, 68, 71, 74} = 11 Using Progression 1;
//+
Transfinite Curve {77, 80, 83, 86} = 11 Using Progression 1;
//+
Transfinite Curve {66, 69, 72, 75} = 21 Using Progression 1;
//+
Transfinite Curve {78, 81, 84, 87} = 21 Using Progression 1;
//+
Transfinite Curve {67, 70, 73, 76} = 31 Using Progression 1;
//+
Transfinite Curve {79, 82, 85, 88} = 31 Using Progression 1;

//+
Transfinite Volume{10} = {17, 18, 22, 21, 33, 34, 38, 37};
//+
Transfinite Volume{11} = {18, 19, 23, 22, 34, 35, 39, 38};
//+
Transfinite Volume{12} = {19, 20, 24, 23, 35, 36, 40, 39};
//+
Transfinite Volume{13} = {21, 22, 26, 25, 37, 38, 42, 41};
//+
Transfinite Volume{14} = {22, 23, 27, 26, 38, 39, 43, 42};
//+
Transfinite Volume{15} = {23, 24, 28, 27, 39, 40, 44, 43};
//+
Transfinite Volume{16} = {25, 26, 30, 29, 41, 42, 46, 45};
//+
Transfinite Volume{17} = {26, 27, 31, 30, 42, 43, 47, 46};
//+
Transfinite Volume{18} = {27, 28, 32, 31, 43, 44, 48, 47};


//++++++++++++++++++++++++++++++++++++++++ Z = 1.0 +++++++++++++++++++++++++++++
//+
Point(49) = {0.0, 0.0, 1.0, 0.1};
//+
Point(50) = {0.1, 0.0, 1.0, 0.1};
//+
Point(51) = {0.3, 0.0, 1.0, 0.1};
//+
Point(52) = {0.6, 0.0, 1.0, 0.1};
//+
Point(53) = {0.0, 0.1, 1.0, 0.1};
//+
Point(54) = {0.1, 0.1, 1.0, 0.1};
//+
Point(55) = {0.3, 0.1, 1.0, 0.1};
//+
Point(56) = {0.6, 0.1, 1.0, 0.1};
//+
Point(57) = {0.0, 0.3, 1.0, 0.1};
//+
Point(58) = {0.1, 0.3, 1.0, 0.1};
//+
Point(59) = {0.3, 0.3, 1.0, 0.1};
//+
Point(60) = {0.6, 0.3, 1.0, 0.1};
//+
Point(61) = {0.0, 0.6, 1.0, 0.1};
//+
Point(62) = {0.1, 0.6, 1.0, 0.1};
//+
Point(63) = {0.3, 0.6, 1.0, 0.1};
//+
Point(64) = {0.6, 0.6, 1.0, 0.1};

//+
Line(105) = {49, 50};
//+
Line(106) = {50, 51};
//+
Line(107) = {51, 52};
//+
Line(108) = {53, 54};
//+
Line(109) = {54, 55};
//+
Line(110) = {55, 56};
//+
Line(111) = {57, 58};
//+
Line(112) = {58, 59};
//+
Line(113) = {59, 60};
//+
Line(114) = {61, 62};
//+
Line(115) = {62, 63};
//+
Line(116) = {63, 64};
//+
Line(117) = {49, 53};
//+
Line(118) = {53, 57};
//+
Line(119) = {57, 61};
//+
Line(120) = {50, 54};
//+
Line(121) = {54, 58};
//+
Line(122) = {58, 62};
//+
Line(123) = {51, 55};
//+
Line(124) = {55, 59};
//+
Line(125) = {59, 63};
//+
Line(126) = {52, 56};
//+
Line(127) = {56, 60};
//+
Line(128) = {60, 64};

//++++++++++++++++++++++ In Between Z = 0.5 and Z = 1.0 ++++++++++++++++++++++++++
//+
Line(129) = {33, 49};
//+
Line(130) = {34, 50};
//+
Line(131) = {35, 51};
//+
Line(132) = {36, 52};
//+
Line(133) = {37, 53};
//+
Line(134) = {38, 54};
//+
Line(135) = {39, 55};
//+
Line(136) = {40, 56};
//+
Line(137) = {41, 57};
//+
Line(138) = {42, 58};
//+
Line(139) = {43, 59};
//+
Line(140) = {44, 60};
//+
Line(141) = {45, 61};
//+
Line(142) = {46, 62};
//+
Line(143) = {47, 63};
//+
Line(144) = {48, 64};

//+
Curve Loop(76) = {105, 120, -108, -117};
//+
Surface(76) = {76};
//+
Curve Loop(77) = {106, 123, -109, -120};
//+
Surface(77) = {77};
//+
Curve Loop(78) = {107, 126, -110, -123};
//+
Surface(78) = {78};
//+
Curve Loop(79) = {108, 121, -111, -118};
//+
Surface(79) = {79};
//+
Curve Loop(80) = {109, 124, -112, -121};
//+
Surface(80) = {80};
//+
Curve Loop(81) = {110, 127, -113, -124};
//+
Surface(81) = {81};
//+
Curve Loop(82) = {111, 122, -114, -119};
//+
Surface(82) = {82};
//+
Curve Loop(83) = {112, 125, -115, -122};
//+
Surface(83) = {83};
//+
Curve Loop(84) = {113, 128, -116, -125};
//+
Surface(84) = {84};

//+
Curve Loop(85) = {129, 117, -133, -77};
//+
Surface(85) = {85};
//+
Curve Loop(86) = {130, 120, -134, -80};
//+
Surface(86) = {86};
//+
Curve Loop(87) = {131, 123, -135, -83};
//+
Surface(87) = {87};
//+
Curve Loop(88) = {132, 126, -136, -86};
//+
Surface(88) = {88};
//+
Curve Loop(89) = {133, 118, -137, -78};
//+
Surface(89) = {89};
//+
Curve Loop(90) = {134, 121, -138, -81};
//+
Surface(90) = {90};
//+
Curve Loop(91) = {135, 124, -139, -84};
//+
Surface(91) = {91};
//+
Curve Loop(92) = {136, 127, -140, -87};
//+
Surface(92) = {92};
//+
Curve Loop(93) = {137, 119, -141, -79};
//+
Surface(93) = {93};
//+
Curve Loop(94) = {138, 122, -142, -82};
//+
Surface(94) = {94};
//+
Curve Loop(95) = {139, 125, -143, -85};
//+
Surface(95) = {95};
//+
Curve Loop(96) = {140, 128, -144, -88};
//+
Surface(96) = {96};
//+
Curve Loop(97) = {129, 105, -130, -65};
//+
Surface(97) = {97};
//+
Curve Loop(98) = {133, 108, -134, -68};
//+
Surface(98) = {98};
//+
Curve Loop(99) = {137, 111, -138, -71};
//+
Surface(99) = {99};
//+
Curve Loop(100) = {141, 114, -142, -74};
//+
Surface(100) = {100};
//+
Curve Loop(101) = {130, 106, -131, -66};
//+
Surface(101) = {101};
//+
Curve Loop(102) = {134, 109, -135, -69};
//+
Surface(102) = {102};
//+
Curve Loop(103) = {138, 112, -139, -72};
//+
Surface(103) = {103};
//+
Curve Loop(104) = {142, 115, -143, -75};
//+
Surface(104) = {104};
//+
Curve Loop(105) = {131, 107, -132, -67};
//+
Surface(105) = {105};
//+
Curve Loop(106) = {135, 110, -136, -70};
//+
Surface(106) = {106};
//+
Curve Loop(107) = {139, 113, -140, -73};
//+
Surface(107) = {107};
//+
Curve Loop(108) = {143, 116, -144, -76};
//+
Surface(108) = {108};
//+
Surface Loop(19) = {76, 97, 85, 98, 86, 43};
//+
Volume(19) = {19};
//+
Surface Loop(20) = {77, 101, 87, 86, 102, 44};
//+
Volume(20) = {20};
//+
Surface Loop(21) = {78, 105, 88, 87, 106, 45};
//+
Volume(21) = {21};
//+
Surface Loop(22) = {79, 89, 46, 98, 90, 99};
//+
Volume(22) = {22};
//+
Surface Loop(23) = {80, 91, 90, 102, 103, 47};
//+
Volume(23) = {23};
//+
Surface Loop(24) = {81, 92, 91, 106, 107, 48};
//+
Volume(24) = {24};
//+
Surface Loop(25) = {82, 100, 93, 99, 94, 49};
//+
Volume(25) = {25};
//+
Surface Loop(26) = {83, 104, 103, 95, 94, 50};
//+
Volume(26) = {26};
//+
Surface Loop(27) = {96, 84, 108, 107, 95, 51};
//+
Volume(27) = {27};

//+
Transfinite Curve {129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144} = 31 Using Progression 1;

//+
Transfinite Curve {117, 120, 123, 126} = 11 Using Progression 1;
//+
Transfinite Curve {105, 108, 111, 114} = 11 Using Progression 1;
//+
Transfinite Curve {118, 121, 124, 127} = 21 Using Progression 1;
//+
Transfinite Curve {106, 109, 112, 115} = 21 Using Progression 1;
//+
Transfinite Curve {107, 110, 113, 116} = 31 Using Progression 1;
//+
Transfinite Curve {119, 122, 125, 128} = 31 Using Progression 1;

//+
Transfinite Volume{19} = {33, 34, 38, 37, 49, 50, 54, 53};
//+
Transfinite Volume{20} = {34, 35, 39, 38, 50, 51, 55, 54};
//+
Transfinite Volume{21} = {35, 36, 40, 39, 51, 52, 56, 55};
//+
Transfinite Volume{22} = {37, 38, 42, 41, 53, 54, 58, 57};
//+
Transfinite Volume{23} = {38, 39, 43, 42, 54, 55, 59, 58};
//+
Transfinite Volume{24} = {39, 40, 44, 43, 55, 56, 60, 59};
//+
Transfinite Volume{25} = {41, 42, 46, 45, 57, 58, 62, 61};
//+
Transfinite Volume{26} = {42, 43, 47, 46, 58, 59, 63, 62};
//+
Transfinite Volume{27} = {43, 44, 48, 47, 59, 60, 64, 63};

Transfinite Surface "*";


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+
//Recombine Surface {1, 2, 3, 4, 5, 6, 7, 8, 9};
//+
//Recombine Surface {10, 11, 12, 13, 14, 15, 16, 17, 18};
//Recombine Surface {19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
//Recombine Surface {31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42};
//Recombine Surface {43, 44, 45, 46, 47, 48, 49, 50, 51};
//Recombine Surface {52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//Recombine Surface {64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75};
//Recombine Surface {76, 77, 78, 79, 80, 81, 82, 83, 84};
//Recombine Surface {85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96}:
//Recombine Surface {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108};

Recombine Surface "*";
Recombine Volume "*";


//+
Physical Surface("XMIN") = {93, 60, 27, 89, 56, 23, 19, 52, 85};
//+
Physical Surface("XMAX") = {88, 92, 96, 63, 30, 26, 59, 55, 22};
//+
Physical Surface("ZMIN") = {9, 8, 7, 4, 5, 6, 3, 2, 1};
//+
Physical Surface("ZMAX") = {76, 77, 78, 79, 80, 81, 82, 83, 84};
//+
Physical Surface("YMIN") = {97, 101, 105, 64, 68, 72, 31, 35, 39};
//+
Physical Surface("YMAX") = {100, 104, 108, 75, 71, 67, 34, 38, 42};
//+
Physical Volume("AIR") = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};

//+
Mesh 3;
Mesh.RecombineAll = 1;
Mesh.Format = 32;	 //CGNS - need to select option through GUI to write this Structured mesh
//+Mesh.Format = 28;	//P3D
//+
PostProcessing.SaveMesh = 1;
