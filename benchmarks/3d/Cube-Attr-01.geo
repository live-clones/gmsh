/*****************************                  
cube meshed uniformly                  
*****************************/                  
Point(1) = {0.0,0.0,0.0,.2};                          
Point(2) = {1,0.0,0.0,.2};                          
Point(3) = {1,1,0.0,.2};                          
Point(4) = {0,1,0.0,.2};                          
Line(1) = {4,3};                          
Line(2) = {3,2};                          
Line(3) = {2,1};                          
Line(4) = {1,4};                          
Line Loop(5) = {2,3,4,1};                          
Plane Surface(6) = {5};                          
Extrude Surface (6, {0,0.0,1});                          
                     
Surface Loop(29) = {23,6,15,19,28,27};                    
Complex Volume(30) = {29};                    
                
Attractor Point(0.05,0.05,2) = {1,4,5,6,10,14};                                                                                               
/*    
Point(15) = {0,.5,.5,1.0};      
Attractor Point(0.05,0.05,2) = {15};                                                                                               
*/    
Point(16) = {-.5,.5,.5,1.0};      
Point(17) = {1.5,.5,.8,1.0};      
Line(30) = {16,17};      
Attractor Line(0.1,0.1,2) = {30};                                                                                               

Point(18) = {-.2,.7,1.3,1.0};      
Point(19) = {1.22,.1,-.8,1.0};      
Line(31) = {18,19};      
Attractor Line(0.01,0.01,2) = {31};                                                                                               
