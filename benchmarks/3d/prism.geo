Point(1) = {0.0,0.0,0.0,1.0};
Point(2) = {1,0.0,0.0,1.0};
Point(3) = {1,0.0,1,1.0};
Point(4) = {1,2,1,1.0};
Point(5) = {0,2,0,1.0};
Point(6) = {1,2,0,1.0};

Line(1) = {4,6};
Line(2) = {6,5};
Line(3) = {5,4};
Line(4) = {2,1};
Line(5) = {1,3};
Line(6) = {3,2};
Line(7) = {2,6};
Line(8) = {5,1};
Line(9) = {3,4};

Line Loop(10) = {9,-3,8,5};
Plane Surface(11) = {10};
Line Loop(12) = {-7,-6,9,1};
Plane Surface(13) = {12};
Line Loop(14) = {-4,7,2,8};
Plane Surface(15) = {14};
Line Loop(16) = {6,4,5};
Plane Surface(17) = {16};
Line Loop(18) = {1,2,3};
Plane Surface(19) = {18};

Surface Loop(20) = {13,15,17,-11,-19};
Volume(21) = {20};

Transfinite Line {1,2,3,4,5,6,7,8,9} = 3;

Transfinite Surface {17} = {1,3,2};
Transfinite Surface {15} = {1,2,6,5};
Transfinite Surface {11} = {1,3,4,5};
Transfinite Surface {13} = {3,2,6,4};
Transfinite Surface {19} = {5,4,6};

Transfinite Volume {21} = {1,3,2,5,4,6};

/*
Recombine Surface {17,19};
*/
Recombine Surface {11,13,15};

