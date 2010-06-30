lc = 0.2;
//ep=0.35;
ep=2.2;
eh=ep/4;
em=ep-eh;
it=600;
diff=0.0;
Point(1) = {0, 0, 0, lc};
Point(2) = {2.2, 0, 0, lc};
Point(3) = {2.2, 2.2, 0, lc};
Point(4) = {0, 2.2, 0, lc};
Point(5) = {0, 0, ep, lc};
Point(6) = {2.2, 0, ep, lc};
Point(7) = {2.2, 2.2, ep, lc};
Point(8) = {0, 2.2, ep, lc};
Line (1) = {5, 6};
Line (2) = {6, 2};
Line (3) = {2, 1};
Line (4) = {1, 5};
Line (5) = {8, 7};
Line (6) = {7, 3};
Line (7) = {3, 4};
Line (8) = {4, 8};
Line (9) = {5, 8};
Line (10) = {6, 7};
Line (11) = {2, 3};
Line (12) = {1, 4};
Line Loop (1000014) = {5, -10, -1, 9};
Plane Surface (14) = {1000014};
Line Loop (1000016) = {8, 5, 6, 7};
Plane Surface (16) = {1000016};
Line Loop (1000018) = {4, 9, -8, -12};
Plane Surface (18) = {1000018};
Line Loop (1000020) = {2, 11, -6, -10};
Plane Surface (20) = {1000020};
Line Loop (1000022) = {3, 12, -7, -11};
Plane Surface (22) = {1000022};
Line Loop (1000024) = {4, 1, 2, 3};
Plane Surface (24) = {1000024};
Surface Loop (1000026) = {14, 16, 18, 24, 20, 22};
Volume (26) = {1000026};

Physical Volume(1)={26};
Physical Surface(10)={14:24:2};
/*
Periodic Line {1} = {5};
Periodic Line {3} = {7};
Periodic Line {9} = {10};
Periodic Line {12} = {11};
*/
Periodic Line {4} = {2} ;
Periodic Line {4} = {6} ;
Periodic Line {4} = {8} ;

Periodic Line {1} = {5} ;
Periodic Line {1} = {7} ;
Periodic Line {1} = {3} ;

Periodic Line {9} = {10} ;
Periodic Line {9} = {11} ;
Periodic Line {9} = {12} ;

Periodic Surface 24 {1,2,3,4} = 16 {5,6,7,8};
Periodic Surface 14 {10,5,9,1} = 22 {11,-7,12,-3};
Periodic Surface 18 {9,8,12,4} = 20 {10,-6,11,-2};
//Periodic Surface {14} = {22};
//Periodic Surface {18} = {20};
