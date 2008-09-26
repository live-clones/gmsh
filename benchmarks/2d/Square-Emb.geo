/******************************      
Square uniformly meshed      
******************************/      
lc = .1;
lc2 = .01;
Point(1) = {0.0,0.0,0,lc};       
Point(2) = {1,0.0,0,lc};       
Point(3) = {1,1,0,lc};       
Point(4) = {0,1,0,lc};       

Point(11) = {0.2,0.2,0,lc2};       
Point(22) = {0.3,0.8,0,lc2};       
Point(33) = {0.8,0.8,0,lc2};       
Point(44) = {0.9,0.2,0,lc2};       


Line(1) = {3,2};       
Line(2) = {2,1};       
Line(3) = {1,4};       
Line(4) = {4,3};       
Spline(5) = {11,22,33,44};       
Line Loop(5) = {1,2,3,4};       
Plane Surface(6) = {5};       
Line {5} In  Surface {6};

Point(111) = {0.5,0.5,0,lc2/10};       
Point(112) = {0.53,0.5,0,lc2/10};       
Point(113) = {0.5,0.51,0,lc2/10};       
Point {111,112,113} In  Surface {6};
