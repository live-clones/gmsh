// Maillage de l Hypervapotron partie solide

//Mesh.Algorithm                   = 3    ;
//Mesh.Smoothing                   = 4    ; 
//Mesh.CharacteristicLengthFactor  = 6  ;
//Mesh.Algorithm3D                 = 4    ;


lc1 = .00025 *10     ;  
lc2 = .000392699  *10 ;

r  = .0015 ;
l1 = .005  ;
l2 = .003  ;
l3 = .0025 ;
l4 = .007  ;
l5 = .001  ;
l6 = .004  ;
l7 = .027  ;
l8 = .017  ;
l9 = .019  ;
   
//Point (0)  = { 0         , 0         , 0   , lc1 } ;
      
Point (1) = { 0         , 2*l1      , l2+l5   , lc1 }; 
Point (2) = { l1        , 2*l1      , l2+l5   , lc1 };
Point (3) = { l1        , 2*l1+l3   , l2+l5   , lc1 };
Point (4) = { l1+r      , 2*l1+l3+r , l2+l5   , lc1 };
Point (5) = { l1+l2     , 2*l1+l3   , l2+l5   , lc1 };
Point (6) = { l1+l2     , 2*l1      , l2+l5   , lc1 };
Point (7) = { l1+2*l2   , 2*l1      , l2+l5   , lc1 };
Point (8) = { l1+2*l2   , 2*l1+l3   , l2+l5   , lc1 };
Point (9) = { l1+2*l2+r , 2*l1+l3+r , l2+l5   , lc1 };
Point (10) = { l1+3*l2   , 2*l1+l3   , l2+l5   , lc1 };
Point (11) = { l1+3*l2   , 2*l1      , l2+l5   , lc1 };
Point (12) = { 2*l1+3*l2 , 2*l1      , l2+l5   , lc1 };
Point (13) = { 2*l1+3*l2 , 2*l1+l6   , l2+l5   , lc1 };
Point (14) = { 0         , 2*l1+l6   , l2+l5   , lc1 };

Point (15) = { l1+r      , 2*l1+l3   , l2+l5   , lc1 } ;
Point (16) = { l1+2*l2+r , 2*l1+l3   , l2+l5   , lc1 } ;

Point (17) = { 0         , 2*l1      , l2+l5+l9   , lc1 };
Point (18) = { l1        , 2*l1      , l2+l5+l9   , lc1 };
Point (19) = { l1        , 2*l1+l3   , l2+l5+l9   , lc1 };
Point (20) = { l1+r      , 2*l1+l3+r , l2+l5+l9   , lc1 };
Point (21) = { l1+l2     , 2*l1+l3   , l2+l5+l9   , lc1 };
Point (22) = { l1+l2     , 2*l1      , l2+l5+l9   , lc1 };
Point (23) = { l1+2*l2   , 2*l1      , l2+l5+l9   , lc1 };
Point (24) = { l1+2*l2   , 2*l1+l3   , l2+l5+l9   , lc1 };
Point (25) = { l1+2*l2+r , 2*l1+l3+r , l2+l5+l9   , lc1 };
Point (26) = { l1+3*l2   , 2*l1+l3   , l2+l5+l9   , lc1 };
Point (27) = { l1+3*l2   , 2*l1      , l2+l5+l9   , lc1 };
Point (28) = { 2*l1+3*l2 , 2*l1      , l2+l5+l9   , lc1 };
Point (29) = { 2*l1+3*l2 , 2*l1+l6   , l2+l5+l9   , lc1 };
Point (30) = { 0         , 2*l1+l6   , l2+l5+l9   , lc1 };

Point (31) = { l1+r      , 2*l1+l3   , l2+l5+l9   , lc1 } ;
Point (32) = { l1+2*l2+r , 2*l1+l3   , l2+l5+l9   , lc1 } ;

Point (33) = { 0         , 2*l1+l6   , l2         , lc1 } ;
Point (34) = { 0         , l1        , l2         , lc1 } ;
Point (35) = { 0         , 0         , 0          , lc1 } ;
Point (36) = { 0         , l8        , 0          , lc1 } ;

Point (37) = { l9        , 2*l1+l6   , l2         , lc1 } ;
Point (38) = { l9        , l1        , l2         , lc1 } ;
Point (39) = { l9        , 0         , 0          , lc1 } ;
Point (40) = { l9        , l8        , 0          , lc1 } ;

Point (41) = { 0         , 2*l1+l6   , l7-l2      , lc1 } ;
Point (42) = { 0         , l1        , l7-l2      , lc1 } ;
Point (43) = { 0         , 0         , l7         , lc1 } ;
Point (44) = { 0         , l8        , l7         , lc1 } ;
    
Point (45) = { l9        , 2*l1+l6   , l7-l2      , lc1 } ;
Point (46) = { l9        , l1        , l7-l2      , lc1 } ;
Point (47) = { l9        , 0         , l7         , lc1 } ;
Point (48) = { l9        , l8        , l7         , lc1 } ;
   
Line (1) = {1, 2};
Line (2) = {2, 3};
Circle (3) = {3, 15, 4};
Circle (4) = {4, 15, 5};
Line (5) = {5, 6};
Line (6) = {6, 7};
Line (7) = {7, 8};
Circle (8) = {8, 16, 9};
Circle (9) = {9, 16, 10};
Line (10) = {10, 11};
Line (11) = {11, 12};
Line (12) = {12, 13};
Line (14) = {14, 1};

Line (15) = {17, 18};
Line (16) = {18, 19};
Circle (17) = {19, 31, 20};
Circle (18) = {20, 31, 21};
Line (19) = {21, 22};
Line (20) = {22, 23};
Line (21) = {23, 24};
Circle (22) = {24, 32, 25};
Circle (23) = {25, 32, 26};
Line (24) = {26, 27};
Line (25) = {27, 28};
Line (26) = {28, 29};
Line (28) = {30, 17};


Line (29) = {1, 17};
Line (30) = {14, 30};
Line (31) = {12, 28};
Line (32) = {13, 29};

Line (33) = {2, 18};
Line (34) = {3, 19};
Line (35) = {4, 20};
Line (36) = {5, 21};
Line (37) = {6, 22};

Line (38) = {7, 23};
Line (39) = {8, 24};
Line (40) = {9, 25};
Line (41) = {10, 26};
Line (42) = {11, 27};

Line (43) = {14, 33};
Line (44) = {33, 34};
Line (45) = {34, 42};
Line (46) = {42, 41};
Line (47) = {41, 30};

Line (48) = {36, 35};
Line (49) = {35, 43};
Line (50) = {43, 44};
Line (51) = {44, 36};

Line (52) = {13, 37};
Line (53) = {37, 38};
Line (54) = {38, 46};
Line (55) = {46, 45};
Line (56) = {45, 29};

Line (57) = {40, 39};
Line (58) = {39, 47};
Line (59) = {47, 48};
Line (60) = {48, 40};

Line (61) = {36, 40};
Line (62) = {35, 39};
Line (63) = {44, 48};
Line (64) = {43, 47};

Line (65) = {34, 38};
Line (66) = {42, 46};
Line (67) = {33, 37};
Line (68) = {41, 45};

Line Loop(69) = {3,35,-17,-34};
Ruled Surface(70) = {69};
Line Loop(71) = {8,40,-22,-39};
Ruled Surface(72) = {71};
Line Loop(73) = {35,18,-36,-4};
Ruled Surface(74) = {73};
Line Loop(75) = {40,23,-41,-9};
Ruled Surface(76) = {75};
Line Loop(77) = {34,-16,-33,2};
Plane Surface(78) = {77};
Line Loop(79) = {19,-37,-5,36};
Plane Surface(80) = {79};
Line Loop(81) = {21,-39,-7,38};
Plane Surface(82) = {81};
Line Loop(83) = {24,-42,-10,41};
Plane Surface(84) = {83};
Line Loop(85) = {33,-15,-29,1};
Plane Surface(86) = {85};
Line Loop(87) = {38,-20,-37,6};
Plane Surface(88) = {87};
Line Loop(89) = {42,25,-31,-11};
Plane Surface(90) = {89};
Line(91) = {14,4};
Line(92) = {4,9};
Line(93) = {9,13};
Line(94) = {30,20};
Line(95) = {20,25};
Line(96) = {25,29};
Line Loop(97) = {28,15,16,17,-94};
Plane Surface(98) = {97};
Line Loop(99) = {19,20,21,22,-95,18};
Plane Surface(100) = {99};
Line Loop(101) = {24,25,26,-96,23};
Plane Surface(102) = {101};
Line Loop(103) = {14,1,2,3,-91};
Plane Surface(104) = {103};
Line Loop(105) = {4,5,6,7,8,-92};
Plane Surface(106) = {105};
Line Loop(107) = {93,-12,-11,-10,-9};
Plane Surface(108) = {107};
Line Loop(109) = {29,-28,-30,14};
Plane Surface(110) = {109};
Line Loop(111) = {30,94,-35,-91};
Plane Surface(112) = {111};
Line Loop(113) = {92,40,-95,-35};
Plane Surface(114) = {113};
Line Loop(115) = {93,32,-96,-40};
Plane Surface(116) = {115};
Line Loop(117) = {32,-26,-31,12};
Plane Surface(118) = {117};
Line Loop(119) = {67,-52,-93,-92,-91,43};
Plane Surface(120) = {119};
Line Loop(121) = {56,-96,-95,-94,-47,68};
Plane Surface(122) = {121};
Line Loop(123) = {44,45,46,47,28,-29,-14,43};
Plane Surface(124) = {123};
Line Loop(125) = {46,68,-55,-66};
Plane Surface(126) = {125};
Line Loop(127) = {56,-26,-31,12,52,53,54,55};
Plane Surface(128) = {127};
Line Loop(129) = {67,53,-65,-44};
Plane Surface(130) = {129};
Line Loop(131) = {66,-54,-65,45};
Plane Surface(132) = {131};

Surface Loop(145) = {86,78,70,-104,110,98,112};
Volume(146) = {145};
Surface Loop(147) = {100,-80,88,-82,72,-106,-74,-114};
Volume(148) = {147};
Surface Loop(149) = {108,-116,118,102,-84,-90,-76};
Volume(150) = {149};
Surface Loop(151) = {126,-124,-130,120,128,-122,102,-84,-90,108,-76,72,-106,-74,70,-104,86,78,98,100,-80,88,-82,132};
Volume(152) = {151};
Surface Loop(153) = {136,-144,138,-140,-142,-134};



// ext
Line Loop(154) = {48,49,50,51};
Line Loop(155) = {45,46,47,-30,43,44};
Plane Surface(156) = {154,155};
Line Loop(157) = {57,58,59,60};
Line Loop(158) = {32,-56,-55,-54,-53,-52};
Plane Surface(159) = {157,158};
Line Loop(160) = {63,-59,-64,50};
Plane Surface(161) = {160};
Line Loop(162) = {61,57,-62,-48};
Plane Surface(163) = {162};
Line Loop(164) = {62,58,-64,-49};
Plane Surface(165) = {164};
Line Loop(166) = {63,60,-61,-51};
Plane Surface(167) = {166};
Surface Loop(168) = {167,-161,-159,163,165,156,-130,120,116,-122,114,-112,126,132};
Volume(169) = {168};
