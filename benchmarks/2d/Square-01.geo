/******************************      
Square uniformly meshed      
******************************/      
lc = .49999;       
Point(1) = {0.0,0.0,0,lc};       
Point(2) = {1,0.0,0,lc};       
Point(3) = {1,1,0,lc};       
Point(4) = {0,1,0,lc};       
Line(1) = {3,2};       
Line(2) = {2,1};       
Line(3) = {1,4};       
Line(4) = {4,3};       
Line Loop(5) = {1,2,3,4};       
Plane Surface(6) = {5};       
//Attractor Point{2} = {0.05,0.05,2};
//Mesh.Algorithm = 2;
Transfinite Line {4,-2} = 130 Using Bump 5;
Transfinite Line {1,3} = 5 Using Progression 1;
