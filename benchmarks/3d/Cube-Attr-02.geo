lc = 0.3;
Point(1) = {0,0,0,lc};                              
Point(2) = {1,0,0,lc};                              
Point(3) = {1,1,0,lc};                              
Point(4) = {0,1,0,lc};                              
Line(1) = {4,3};                              
Line(2) = {3,2};                              
Line(3) = {2,1};                              
Line(4) = {1,4};                              
Line Loop(5) = {2,3,4,1};                              
Plane Surface(6) = {5};                              
Extrude Surface{6, {0,0.0,1}};
                         
Surface Loop(29) = {23,6,15,19,28,27};                        
Volume(30) = {29};                        

Point(55) = {0.3,0.3,0.3,1};                              
                    
Field[1] = Attractor;
Field[1].NodesList = {55};

Field[2] = Threshold;
Field[2].IField = 1;
Field[2].LcMin = lc/20;
Field[2].LcMax = lc;
Field[2].DistMin = 0.3;
Field[2].DistMax = 0.5;

Background Field = 2;
