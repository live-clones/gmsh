lc = .5;               
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
            
Extrude Surface{6, {0.0,1,0}, {0,0.0,0.0}, 3.14159/2}
{    
   Layers {{5,10,5},{11,22,11},{.1,.9,1.}} ;    
} ;            
            
Coherence;              
Extrude Surface {6, {0,0.0,2}} ; 
Surface Loop(51) = {6,37,41,45,49,50}; 
Complex Volume(52) = {51}; 
Extrude Surface {45, {0,2,0.0}}
{    
   Layers {{2,2,2},{111,222,111},{.3,.6,1.}};    
} ; 
Coherence; 
Extrude Surface {65, {-1,0,0}};

Surface Loop(97) = {65,83,87,91,95,96};
Volume(98) = {97};
