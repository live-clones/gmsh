//+
Point(1) = {-10.0, -10.0, 0, 0.1};
//+
Point(2) = {-10.0, 10.0, 0, 0.1};
//+
Point(3) = {-3.0, -10.0, 0, 0.1};
//+
Point(4) = {-3.0, 10.0, 0, 0.1};
//+
Point(5) = {11.0, -10.0, 0, 0.1};
//+
Point(6) = {11.0, 10.0, 0, 0.1};
//+
Point(7) = {40.0, -10.0, 0, 0.1};
//+
Point(8) = {40.0, 10.0, 0, 0.1};
//+
Point(9) = {-10.0, -3.75, 0, 0.1};
//+
Point(10) = {-10.0, 3.75, 0, 0.1};
//+
Point(11) = {40.0, -3.75, 0, 0.1};
//+
Point(12) = {40.0, 3.75, 0, 0.1};
//+
Point(13) = {-3.25, -4.25, 0, 0.1};
//+
Point(14) = {-3.25, 4.25, 0, 0.1};
//+
Point(15) = {9.5, -3.5, 0, 0.1};
//+
Point(16) = {9.5, 3.5, 0, 0.1};
//+
Point(17) = {0.0, 0.0, 0, 0.1};
//+
Point(18) = {-4.128, 0.0, 0, 0.1};
//+
Point(19) = {9.792, 0.0, 0, 0.1};
//+
Point(20) = {2.9, -4.783, 0, 0.1};
//+
Point(21) = {2.9, 4.783, 0, 0.1};
//+
Point(22) = {-0.707107, -0.707107, 0, 0.1};
//+
Point(23) = {-0.707107, 0.707107, 0, 0.1};
//+
Point(24) = {0.707107, 0.707107, 0, 0.1};
//+
Point(25) = {0.707107, -0.707107, 0, 0.1};
//+
Point(26) = {0.0, 1.0, 0, 0.1};
//+
Point(27) = {0.0, -1.0, 0, 0.1};
//+
Point(28) = {1.0, 0.0, 0, 0.1};
//+
Point(29) = {-1.0, 0.0, 0, 0.1};
//+
Circle(1) = {23, 17, 24};
//+
Circle(2) = {24, 17, 25};
//+
Circle(3) = {25, 17, 22};
//+
Circle(4) = {22, 17, 23};
//+
Spline(5) = {14, 21, 16};
//+
Spline(6) = {16, 19, 15};
//+
Spline(7) = {15, 20, 13};
//+
Spline(8) = {13, 18, 14};
//+
Line(9) = {23, 14};
//+
Line(10) = {24, 16};
//+
Line(11) = {25, 15};
//+
Line(12) = {22, 13};
//+
Line(13) = {1, 3};
//+
Line(14) = {3, 5};
//+
Line(15) = {5, 7};
//+
Line(16) = {2, 4};
//+
Line(17) = {4, 6};
//+
Line(18) = {6, 8};
//+
Line(19) = {1, 9};
//+
Line(20) = {9, 10};
//+
Line(21) = {10, 2};
//+
Line(22) = {7, 11};
//+
Line(23) = {11, 12};
//+
Line(24) = {12, 8};
//+
Line(25) = {13, 3};
//+
Line(26) = {13, 9};
//+
Line(27) = {14, 10};
//+
Line(28) = {14, 4};
//+
Line(29) = {16, 6};
//+
Line(30) = {16, 12};
//+
Line(31) = {15, 5};
//+
Line(32) = {15, 11};
//+
Curve Loop(1) = {25, -13, 19, -26};
//+
Surface(1) = {1};
//+
Curve Loop(2) = {14, -31, 7, 25};
//+
Surface(2) = {2};
//+
Curve Loop(3) = {32, -22, -15, -31};
//+
Surface(3) = {3};
//+
Curve Loop(4) = {20, -27, -8, 26};
//+
Surface(4) = {4};
//+
Curve Loop(5) = {6, 32, 23, -30};
//+
Surface(5) = {5};
//+
Curve Loop(6) = {27, 21, 16, -28};
//+
Surface(6) = {6};
//+
Curve Loop(7) = {28, 17, -29, -5};
//+
Surface(7) = {7};
//+
Curve Loop(8) = {29, 18, -24, -30};
//+
Surface(8) = {8};
//+
Curve Loop(9) = {8, -9, -4, 12};
//+
Surface(9) = {9};
//+
Curve Loop(10) = {9, 5, -10, -1};
//+
Surface(10) = {10};
//+
Curve Loop(11) = {10, 6, -11, -2};
//+
Surface(11) = {11};
//+
Curve Loop(12) = {11, 7, -12, -3};
//+
Surface(12) = {12};
//+
Transfinite Curve {13, 26, 27, 16} = 41 Using Progression 1.0;
//+
Transfinite Curve {14, 7, 3, 1, 5, 17} = 61 Using Progression 1.0;
//+
Transfinite Curve {15, 32, 30, 18} = 121 Using Progression 1.0;
//+
Transfinite Curve {19, 25, 31, 22} = 51 Using Progression 1.0;
//+
Transfinite Curve {20, 8, 4, 2, 6, 23} = 61 Using Progression 1.0;
//+
Transfinite Curve {21, 28, 29, 24} = 51 Using Progression 1.0;
//+
Transfinite Curve {9, 10, 11, 12} = 91 Using Progression 1.025;
//+
Transfinite Surface {1} = {1, 3, 13, 9};
//+
Transfinite Surface {2} = {3, 5, 15, 13};
//+
Transfinite Surface {3} = {5, 7, 11, 15};
//+
Transfinite Surface {4} = {9, 13, 14, 10};
//+
Transfinite Surface {5} = {15, 11, 12, 16};
//+
Transfinite Surface {6} = {10, 14, 4, 2};
//+
Transfinite Surface {7} = {14, 16, 6, 4};
//+
Transfinite Surface {8} = {16, 12, 8, 6};
//+
Transfinite Surface {9} = {22, 23, 14, 13};
//+
Transfinite Surface {10} = {24, 16, 14, 23};
//+
Transfinite Surface {11} = {25, 15, 16, 24};
//+
Transfinite Surface {12} = {22, 13, 15, 25};
//+
Recombine Surface {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//+
Physical Curve("INLET") = {21, 20, 19};
//+
Physical Curve("OUTLET") = {24, 23, 22};
//+
Physical Curve("TOP") = {18, 17, 16};
//+
Physical Curve("BOTTOM") = {13, 14, 15};
//+
Physical Curve("CYLINDER") = {3, 2, 1, 4};
//+
Physical Surface("AIR") = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//+
Mesh 2;
Mesh.RecombineAll = 1;
Mesh.Format = 32;		//CGNS - need to choose option through GUI to write out Structured mesh - command prompt version won't do
//+Mesh.Format = 28;	//P3D
//+
PostProcessing.SaveMesh = 1;
