lc = 0.3;

// example of a purely hexahedral mesh using only transfinite
// mesh constraints
z=0.6;
deform=0.4;

Point(1) = {-2-deform,0,0,lc};
Point(2) = {-1,0,0,lc};
Point(3) = {-1,1,0,lc};
Point(4) = {-2,1,0,lc};
Point(5) = {-2,0-deform,z+deform,lc};
Point(6) = {-1,0,z,lc};
Point(7) = {-1,1,z,lc};
Point(8) = {-2,1,z,lc};
Line(1) = {4,3};
Line(2) = {3,2};
Line(3) = {2,1};
Line(4) = {1,4};
Line(6) = {5,6};
Line(7) = {6,7};
Line(8) = {7,8};
Line(9) = {8,5};
Line(10) = {1,5};
Line(11) = {4,8};
Line(12) = {2,6};
Line(13) = {3,7};
Line Loop(14) = {3,4,1,2};
Ruled Surface(15) = {14};
Line Loop(16) = {6,7,8,9};
Ruled Surface(17) = {16};
Line Loop(18) = {10,-9,-11,-4};
Ruled Surface(19) = {18};
Line Loop(20) = {8,-11,1,13};
Ruled Surface(21) = {20};
Line Loop(22) = {12,7,-13,2};
Ruled Surface(23) = {22};
Line Loop(24) = {6,-12,3,10};
Ruled Surface(25) = {24};
Surface Loop(1) = {17,-25,-23,-21,19,15};
Volume(1) = {1};
Transfinite Line{1:4,6:9} = 5 Using Progression 1.4;
Transfinite Line{10:13} = 10;

/*
Transfinite Surface {15} = {1,2,3,4};
Transfinite Surface {17} = {5,6,7,8};
Transfinite Surface {19} = {1,5,8,4};
Transfinite Surface {21} = {8,7,3,4};
Transfinite Surface {23} = {6,7,3,2};
Transfinite Surface {25} = {5,6,2,1};
*/

Transfinite Surface {15} = {1,2,3,4};


Transfinite Surface {17} = {5,6,7,8};
Transfinite Surface {19} = {1,5,8,4};
Transfinite Surface {21} = {8,7,3,4};
Transfinite Surface {23} = {6,7,3,2};
Transfinite Surface {25} = {5,6,2,1};


Transfinite Volume{1} = {1,2,3,4,5,6,7,8};
Recombine Surface{15:25:2};

