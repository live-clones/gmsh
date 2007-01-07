
Point(1)={0,0,0,1};
Point(2)={1,0,0,1};
Point(3)={0,1,0,1};
//Circle(1) = {2,1,3};
Line(1) = {2,3};
Line(2) = {2,1};
Line(3) = {1,3};
Line Loop(4) = {1,-3,-2};
Ruled Surface(5) = {4};

Transfinite Line{1,2,3} = 20;
//Transfinite Surface{5} = {3,1,2};
Transfinite Surface{5} = {2,1,3};
//Transfinite Surface{5} = {1,2,3};

/*
Point(10)={3+0,0,0,1};
Point(11)={3+1,0,0,1};
Point(12)={3+0,1,0,1};
Point(13)={3+1,1,0,1};
Point(14)={3+0.5,0.5,0,1};
Circle(6) = {13,14,12};
Line(7) = {13,11};
Line(8) = {11,10};
Line(9) = {10,12};
Line Loop(10) = {7,8,9,-6};
Ruled Surface(11) = {10};

Transfinite Line{6,7,8,9} = 20;
Transfinite Surface{11} = {11,10,12,13};

*/
