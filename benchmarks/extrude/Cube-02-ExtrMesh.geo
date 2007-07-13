
x = .0;                                        
Point(1) = {0.0,0.,0.0,.2+x};                                                
Point(2) = {1,0.,0.0,.2+x};                                                
Point(3) = {1,1,0.0,.2+x};                                                
Point(4) = {0,1,0.0,.2+x};                                                
Point(5) = {1,2,0.0,.2+x};                                                
Point(6) = {0,2,0.0,.2+x};                                                
Line(1) = {4,3};                                                
Line(2) = {3,2};                                                
Line(3) = {2,1};                                                
Line(4) = {1,4};                                                
Line Loop(5) = {2,3,4,1};                                                
Plane Surface(6) = {5};                                                
Extrude Surface {6, {0,0.0,1}}                                     
{                                     
  Layers { 120 };
} ;                                    
           
Line(29) = {4,6};        
Line(30) = {6,5};        
Line(31) = {5,3};        
Line Loop(32) = {-31,-30,-29,1};        
Plane Surface(33) = {32};        
Extrude Surface {33, {0,0.0,1}};        
Coherence;        
