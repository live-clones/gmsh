/******************************  
Square non uniformly 
meshed  
******************************/  
lc = .1;   
Point(1) = {0.0,0.0,0,lc*.1};   
Point(2) = {1,0.0,0,lc};   
Point(3) = {1,1,0,lc};   
Point(4) = {0,1,0,lc};   
Line(1) = {3,2};   
Line(2) = {2,1};   
Line(3) = {1,4};   
Line(4) = {4,3};   
Line Loop(5) = {1,2,3,4};   
Plane Surface(6) = {5};   
