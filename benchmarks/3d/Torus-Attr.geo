lc = .2;              
Point(1) = {2.0,0.0,0.0,lc};              
Point(2) = {2.0,1,0.0,lc};              
Point(3) = {1,0,0.0,lc};              
Point(4) = {3,0,0.0,lc};              
Point(5) = {2,-1,0.0,lc};              
Circle(1) = {4,1,2};              
             
Circle(2) = {2,1,3};             
Circle(3) = {3,1,5};             
Circle(4) = {5,1,4};             
Line Loop(5) = {4,1,2,3};             
Plane Surface(6) = {5};             
           
Extrude Surface(6, {0.0,1,0}, {0,0.0,0.0}, 1.5*3.14159/2);             
           
Coherence;             
Attractor Line (1,.1,2.0) = {22};   
