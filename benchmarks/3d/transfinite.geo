Point(1) = {0.0,0.0,0.0,1.0};
Point(2) = {1,0.0,0.0,1.0};
Point(3) = {.5,.1,0.0,1.0};
Point(4) = {.5,.2,0.0,1.0};
Point(5) = {0,.5,0.0,1.0};
Point(6) = {1,.55,0.0,1.0};
Point(7) = {0,0,1,1.0};

Line(1) = {2,6};
Line(2) = {5,1};
Spline(3) = {1,3,2};
Spline(4) = {5,4,6};

Line Loop(5) = {-1,-3,-2,4};
Plane Surface(6) = {5};

Point(8) = {0,.5,1,1.0};
Point(9) = {1,.5,1,1.0};
Point(10) = {1,0,1,1.0};

Line(7) = {6,9};
Line(8) = {9,10};
Line(9) = {10,2};
Line(10) = {10,7};
Line(11) = {7,1};
Line(12) = {5,8};
Line(13) = {8,7};
Line(14) = {8,9};

Line Loop(15) = {14,-7,-4,12};
Ruled Surface(16) = {15};
Line Loop(17) = {7,8,9,1};
Ruled Surface(18) = {17};
Line Loop(19) = {-10,-8,-14,13};
Ruled Surface(20) = {19};
Line Loop(21) = {-11,-13,-12,2};
Ruled Surface(22) = {21};
Line Loop(23) = {-9,10,11,3};
Ruled Surface(24) = {23};

Surface Loop(25) = {16,20,24,18,6,22};
Complex Volume(26) = {25};

Transfinite Line {7,9,11,12} = 5;
Transfinite Line {3,10,14} = 10;
Transfinite Line {4} = 10 Using Bump 10;
Transfinite Line {1} = 20 Using Power 1.1;
Transfinite Line {2} = 20 Using Power 0.9;
Transfinite Line {8,13} = 20 ;

Transfinite Surface {6} = {1,2,6,5};
Transfinite Surface {20} = {7,10,9,8};
Transfinite Surface {18} = {10,2,6,9};
Transfinite Surface {22} = {7,1,5,8};
Transfinite Surface {16} = {8,9,6,5};
Transfinite Surface {24} = {7,10,2,1};

Transfinite Volume {26} = {7,10,2,1,8,9,6,5};

Recombine Surface {6,20,18,22,16,24};







