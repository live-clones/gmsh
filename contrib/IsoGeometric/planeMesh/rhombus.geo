// Rhombus shape geometry
dx = 20;
dy = dx/2;
p = 1;

Point(1) = {-dx, 0, 0, p};
Point(2) = {0, -dy, 0, p};
Point(3) = {+dx, 0, 0, p};
Point(4) = {0, +dy, 0, p};

Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};


Curve Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};

/*
Physical Point("start_0") = {1};
Physical Point("end_0") = {2};
*/

/*
Physical Point("start_1") = {3};
Physical Point("end_1") = {4};
*/
/*
Physical Point("start_2") = {1};
Physical Point("end_2") = {3};
*/
/*
Physical Point("start_4") = {1};
Physical Point("end_4") = {4};
*/


Physical Point("vertices") = {1,2,3,4};
Physical Curve("edges") = {1,2,3,4};
Physical Surface("surface") = {1};
