Point(1) = {0,0,0,.2}; 
Point(2) = {0,1,0,.2}; 
Point(3) = {1,0,0,.2}; 
Point(4) = {0,0,.5,.2};

Line(7) = {3,4};
Circle(8) = {3,1,2};
Line(9) = {1,3};
Line(10) = {1,4};
Line(11) = {1,2};
Line(12) = {4,2};

Line Loop(13) = {9,8,-11};
Plane Surface(14) = {13};
Line Loop(15) = {10,12,-11};
Plane Surface(16) = {15};
Line Loop(17) = {-8,7,12};
Ruled Surface(18) = {17};
Line Loop(19) = {-10,9,7};
Plane Surface(20) = {19};
