l = 1;
Point(1) = {-2,-1,0,l};
Point(2) = {-2,1,0,l};
Point(3) = {0,-1,0,l};
Point(4) = {0,1,0,l};
Point(5) = {-3,-2,0,l};
Point(6) = {-3,2,0,l};
Point(7) = {1,-2,0,l};
Point(8) = {1,2,0,l};

Line(1) = {6,8};
Line(2) = {8,7};
Line(3) = {7,5};
Line(4) = {5,6};
Line(5) = {2,1};
Line(6) = {1,3};
Line(7) = {3,4};
Line(8) = {4,2};

/*
Loop(9) = {5,6,7,8};
Plane Surface(10) = {9};

Loop(11) = {2,3,4,1};
Plane Surface(12) = {11,9};


Transfinite Line {5,6,7,8} = 3;

Physical Point(9999) = {2};

Physical Line(2222) = {6,7};
Physical Line(3333) = {-7,-6};

Physical Association(111111)= {3333,2222};
*/

Line Loop(9) = {5,6,7,8};
Plane Surface(10) = {9};

Physical Surface(1111) = 10 ;
