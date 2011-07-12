//Mesh.CharacteristicLengthFactor=0.3;
Mesh.CharacteristicLengthFromCurvature=1; //-clcurv
Mesh.CharacteristicLengthMin = 0.1; //-clmin
Mesh.CharacteristicLengthMax = 2.5; //-clmax
Mesh.LcIntegrationPrecision=1.e-5; //-epslc1d

Mesh.MinimumCirclePoints=15; //default=7
Mesh.CharacteristicLengthExtendFromBoundary=0;

lc = 0.1;          
Point(1) = {2.0,0.0,0.0,lc};          
Point(2) = {2.0,1,0.0,lc};          
Point(3) = {1,0,0.0,lc};          
Point(4) = {3,0,0.0,lc};          
Point(5) = {2,-1,0.0,lc}; 
         
Circle(1) = {4,1,2};                 
Circle(2) = {2,1,3};         
Circle(3) = {3,1,5};         
Circle(4) = {5,1,4};         
Line Loop(5) = {4,1,2,3};   //Inlet      
Plane Surface(6) = {5};         
       
//out[] = Extrude Surface{6, {0.0,1,0}, {0,0.0,0.0}, 1*3.14159};
out[] = Extrude{ {0.0, 1.0, 0.0},{ 0.0, 0.0, 0.0 }, Pi } { Surface{6}; };         
//Recombine Surface {6, 27, 23, 15, 19, 28};

Physical Surface("Wall") = {out[2],out[3],out[4],out[5]};
