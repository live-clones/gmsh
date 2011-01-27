//-*- C++ -*-
/*********************************************       
Cube uniformly meshed along all three axes      
**********************************************/       
lc = 0.2; //.05;     
// Radius of the cylinder:
R = 0.5; 
// Length of the cylinder:
L = 5; 

Point(0) = {0, 0, 0, lc}; 
Point(1) = {R, 0, 0, lc}; 
Point(2) = {0, R, 0, lc};
Point(3) = {-R, 0, 0, lc};
Point(4) = {0, -R, 0, lc};

Circle(1) = {1,0,2};
Circle(2) = {2,0,3};
Circle(3) = {3,0,4};
Circle(4) = {4,0,1};

nb_pts_edge = 5;
nb_layers = 30;

For iLine In {1:4}
	Transfinite Line{iLine} = nb_pts_edge;
EndFor

Line Loop(1) = {1,2,3,4};
Plane Surface(1) = {1};

out[] = Extrude{0, 0, L}{Surface{1}; Layers{nb_layers};};

Extrude { Surface{13,17,21,25}; Layers{5, 0.1}; Recombine; Using Index[0]; }
Extrude { Surface{-13,-17,-21,-25}; Layers{5, 0.1}; Recombine; Using Index[1]; }


