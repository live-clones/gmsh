/******************************               
Square uniformly meshed               
******************************/               
lc = .149999;                
Point(1) = {0.0,0.0,0,lc};                
Point(2) = {1,0.0,0,lc};                
Point(3) = {1,1,0,lc};                
Point(4) = {0,1,0,lc};                
Line(1) = {3,2};                
Line(2) = {2,1};                
Line(3) = {1,4};                
Line(4) = {4,3};   
Point(55) = {0.2,.5,0,lc};                 
Line Loop(5) = {1,2,3,4};                
Plane Surface(6) = {5};                
Attractor Point {55} = {.01,.1,3.0};       
