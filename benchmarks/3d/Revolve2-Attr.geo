lc = .3;                
Point(2) = {3.0,-1.0,0.0,lc};                
Point(3) = {1,-1,0.0,lc};                
Point(4) = {3,1,0.0,lc};                
Point(5) = {1,1,0.0,lc};                
Line(1) = {4,2};                           
Line(2) = {2,3};               
Line(3) = {3,5};               
Line(4) = {5,4};               
Line Loop(5) = {4,1,2,3};               
Plane Surface(6) = {5};               
             
Extrude Surface(6, {0.0,1,0}, {0,0.0,0.0},  3.14159/2);               
             
Coherence;               
  
Attractor Line (.1,.1,1.0) = {14};  
Surface Loop(29) = {15,6,19,23,27,28};
Complex Volume(30) = {29};
