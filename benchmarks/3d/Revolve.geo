lc = .1;          
Point(1) = {2.0,0.0,0.0,lc};          
Point(2) = {2.0,1,0.0,lc};          
Point(3) = {1,0,0.0,lc};          
Point(4) = {3,0,0.0,lc};          
Point(5) = {2,-1,0.0,lc};          
Line(1) = {4,2};          
         
Line(2) = {2,3};         
Line(3) = {3,5};         
Line(4) = {5,4};         
Line Loop(5) = {4,1,2,3};         
Plane Surface(6) = {5};         
       
Extrude Surface{6, {0.0,1,0}, {0,0.0,0.0},  3.14159/4};         
