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
Delete { 
 Surface(6); 
} 
Delete { 
 Surface(15); 
} 
Delete { 
 Surface(28); 
} 
Delete { 
 Surface(23); 
} 
Delete { 
 Surface(27); 
} 
