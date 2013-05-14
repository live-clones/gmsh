Include "magnet_data.pro";

DefineConstant[ h = {0.14, Min 0.1, Max 0.2, Step 0.01,
                     Path "Parameters/Geometry",
                     Label "Core height (m)"} ] ;

DefineConstant[ l = {0.14, Min 0.05, Max 0.2, Step 0.01,
                     Path "Parameters/Geometry",
                     Label "Core width (m)"} ] ;

DefineConstant[ d = {0.03, Min 0.01, Max 0.05, Step 0.002,
                     Path "Parameters/Geometry",
                     Label "Core tickness (m)"} ] ;

DefineConstant[ e = {5e-3, Min 5e-4, Max d, Step 1e-3,
                     Path "Parameters/Geometry",
                     Label "Air gap (m)", Highlight "LightYellow"} ] ;

DefineConstant[ ha = {0.03, Min 0.01, Max 0.1, Step 0.01,
                     Path "Parameters/Geometry",
                     Label "Magnet height (m)"} ] ;

lc0 = d / 5 ;
lc1 = e / 2 ;
lc2 = (Val_Rext - Val_Rint) / 8. ;

Point(1) = {0, 0, 0, lc0};
Point(2) = {-l/2, 0, 0, lc0};
Point(3) = {-l/2, h/2, 0, lc0};
Point(4) = {l/2, 0, 0, lc1};
Point(5) = {l/2, h/2, 0, lc0};
Point(6) = {-l/2, ha/2, 0, lc0};
Point(7) = {-l/2+d, ha/2, 0, lc0};
Point(8) = {-l/2+d, 0, 0, lc0};
Point(9) = {l/2-d, 0, 0, lc1};
Point(10) = {l/2-d, h/2-d, 0, lc0};
Point(11) = {-l/2+d, h/2-d, 0, lc0};
Point(12) = {l/2, e/2, 0, lc1};
Point(13) = {l/2-d, e/2, 0, lc1};

Point(30) = {Val_Rint, 0, 0, lc2};
Point(31) = {Val_Rext, 0, 0, lc2};
Point(32) = {0, Val_Rint, 0, lc2};
Point(33) = {0, Val_Rext, 0, lc2};
Point(34) = {-Val_Rext, 0, 0, lc2};
Point(35) = {-Val_Rint, 0, 0, lc2};

Line(1) = {34, 35};
Line(2) = {35, 2};
Line(3) = {2, 8};
Line(4) = {8, 1};
Line(5) = {1, 9};
Line(6) = {9, 4};
Line(7) = {4, 30};
Line(8) = {30, 31};
Line(9) = {2, 6};
Line(10) = {6, 3};
Line(11) = {3, 5};
Line(12) = {5, 12};
Line(13) = {12, 4};
Line(14) = {9, 13};
Line(15) = {13, 10};
Line(16) = {10, 11};
Line(17) = {11, 7};
Line(18) = {7, 8};
Line(19) = {7, 6};
Line(20) = {13, 12};
Circle(21) = {35, 1, 32};
Circle(22) = {32, 1, 30};
Circle(23) = {34, 1, 33};
Circle(24) = {33, 1, 31};

Line Loop(25) = {21, 22, 8, -24, -23, 1};
Plane Surface(26) = {25};
Line Loop(27) = - {22, -7, -13, -12, -11, -10, -9, -2, 21};
Plane Surface(28) = {27};
Line Loop(29) = - {11, 12, -20, 15, 16, 17, 19, 10};
Plane Surface(30) = {29};
Line Loop(31) = {19, -9, 3, -18};
Plane Surface(32) = {31};
Line Loop(33) = - {20, 13, -6, 14};
Plane Surface(34) = {33};
Line Loop(35) = {15, 16, 17, 18, 4, 5, 14};
Plane Surface(36) = {35};

// physical entities (for which elements will be saved)
Physical Surface(AIR) = {28, 36};
Physical Surface(AIR_INF) = {26};
Physical Surface(AIR_GAP) = {34};
Physical Surface(MAGNET) = {32};
Physical Surface(CORE) = {30};
Physical Line(LINE_INF) = {23, 24};
Physical Line(LINE_X) = {1:8};
