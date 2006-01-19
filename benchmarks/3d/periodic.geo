// original file from benarafa@alpes.cea.fr

Lc = 0.003 ;
nb_layers = 12;
use_prisms = 1;

Point(1) = {0.,0.,0.,Lc};
L = 0.045;
R = 0.01085;
Point(2) = {R,0.,0.,Lc};
Point(3) = {-R,0.,0.,Lc};
Point(4) = {0.,R,0.,Lc};
Point(5) = {0.,-R,0.,Lc};
Point(6) = {0.5*L,-0.5*L,0.,Lc};
Point(7) = {-0.5*L,-0.5*L,0.,Lc};
Point(8) = {-0.5*L,0.5*L,0.,Lc};
Point(9) = {0.5*L,0.5*L,0.,Lc};
Point(10) = {0.5*L-R,0.5*L,0.,Lc};
Point(11) = {0.5*L,0.5*L-R,0.,Lc};
Point(12) = {-0.5*L+R,0.5*L,0.,Lc};
Point(13) = {-0.5*L+R,-0.5*L,0.,Lc};
Point(14) = {-0.5*L,-0.5*L+R,0.,Lc};
Point(15) = {0.5*L,-0.5*L+R,0.,Lc};
Point(16) = {-0.5*L,0.5*L-R,0.,Lc};

Point(17) = {0.5*L-R,-0.5*L,0.,Lc};
Line(1) = {12,10};
Line(2) = {16,14};
Line(3) = {11,15};
Line(4) = {13,17};
Circle(5) = {10,9,11};
Circle(6) = {15,6,17};
Circle(7) = {13,7,14};
Circle(8) = {16,8,12};
Circle(9) = {4,1,2};
Circle(10) = {2,1,5};
Circle(11) = {5,1,3};

Circle(12) = {3,1,4};
Line Loop(13) = {3,6,-4,7,-2,8,1,5};
Line Loop(14) = {10,11,12,9};
Plane Surface(15) = {13,14};
Physical Line(16) = {5,6,7,8,12,9,10,11};
Physical Line(17) = {1,4};
Physical Line(18) = {2,3};
Physical Surface(19) = {15};

If(use_prisms)
  Extrude Surface {15, {0.,0.,2.*R}}{Layers{nb_layers,83,1}; Recombine; };
EndIf

If(!use_prisms)
  Extrude Surface {15, {0.,0.,2.*R}};
  Transfinite Line {27,55,1,59,23,43,4,39,21,34,3,35,25,51,2,47} = (nb_layers+1) Using Progression 1.;
  Transfinite Surface {52} = {16,14,33,37};
  Transfinite Surface {36} = {11,15,19,18};
  Transfinite Surface {44} = {13,17,24,28};
  Transfinite Surface {60} = {12,10,46,42};
  Surface Loop(82) = {81,36,15,40,44,48,52,56,60,64,68,72,76,80};
  Volume(83) = {82};
EndIf
