Point(1) = {0,0,0,1.0};
Point(2) = {1,0,0,1.0};
Point(3) = {.5,1,0,1.0};
Point(4) = {.75,.5,0,1.0};
Line(1) = {2,1};
Line(2) = {1,3};
Line(3) = {3,4};
Line(4) = {4,2};
Line Loop(5) = {1,2,3,4};
Ruled Surface(6) = {5};

Point(5) = {1,1,0.0,1.0};
Point(6) = {1,.5,0.0,1.0};
Line(7) = {3,5};
Line(8) = {5,6};
Line(9) = {6,4};
Line Loop(10) = {-3,7,8,9};
Ruled Surface(11) = {10};

Transfinite Line {2,4} = 5;
Transfinite Line {3,1,8} = 10;
Transfinite Line {7,9} = 10;

Transfinite Surface {6} = {1,2,4,3};
Transfinite Surface {11} = {4,6,5,3};

Recombine Surface {6,11};
