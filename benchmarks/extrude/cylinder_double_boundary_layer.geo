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

out[] = Extrude{0, 0, L}{Line{1:4}; Layers{nb_layers};};

Extrude { Surface{out[{1, 5, 9, 13}]}; Layers{5, 0.1}; Recombine; Using Index[0]; }
Extrude { Surface{- out[{1, 5, 9, 13}]}; Layers{5, 0.1}; Recombine; Using Index[1]; }


Line Loop(197) = {132, 154, 176, 110};
Plane Surface(198) = {197};
Line Loop(199) = {134, 112, 178, 156};
Plane Surface(200) = {199};
Surface Loop(201) = {200, 152, 174, 196, 130, 198};
Volume(202) = {201};
