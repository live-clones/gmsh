
x = .0;                                  
Point(1) = {0.0,0.0,0.0,.2+x};                                          
Point(2) = {1,0.0,0.0,.2+x};                                          
Point(3) = {1,1,0.0,.2+x};                                          
Point(4) = {0,1,0.0,.002+x};                                          
Line(1) = {4,3};                                          
Line(2) = {3,2};                                          
Line(3) = {2,1};                                          
Line(4) = {1,4};                                          
Line Loop(5) = {2,3,4,1};                                          
Plane Surface(6) = {5};                                          
Extrude {0,0.0,1}{                               
  Surface{6};
  Layers {{10,5,10},{.1,.9,1.}};                                  
  //Recombine;
}

