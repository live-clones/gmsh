
/*
mesh 3d incorrectly leaves some 1d elements intact 

this results in 
- incorrect final 1d mesh
- hanging (non-connected) 2nd order nodes on curves
*/

/**
 * Cylindrical bicrystal test specimen.
 */
// define element size
ElemSize = 0.0015;
// define points
Point(1) = {0.0,0.0,0.0,ElemSize};
Point(2) = {0.003,0.0,0.0,ElemSize};
Point(3) = {0.0,0.003,0.0,ElemSize};
Point(4) = {-0.003,0.0,0.0,ElemSize};
Point(5) = {0.0,-0.003,0.0,ElemSize};
Point(11) = {0.0,0.0,0.0093,ElemSize};
Point(12) = {0.003,0.0,0.0093,ElemSize};
Point(13) = {0.0,0.003,0.0093,ElemSize};
Point(14) = {-0.003,0.0,0.0093,ElemSize};
Point(15) = {0.0,-0.003,0.0093,ElemSize};
Point(21) = {0.0,0.0,-0.0093,ElemSize};
Point(22) = {0.003,0.0,-0.0093,ElemSize};
Point(23) = {0.0,0.003,-0.0093,ElemSize};
Point(24) = {-0.003,0.0,-0.0093,ElemSize};
Point(25) = {0.0,-0.003,-0.0093,ElemSize};
// define lines
Circle(1) = {2,1,3};
Circle(2) = {3,1,4};
Circle(3) = {4,1,5};
Circle(4) = {5,1,2};
Circle(11) = {12,11,13};
Circle(12) = {13,11,14};
Circle(13) = {14,11,15};
Circle(14) = {15,11,12};
Line(15) = {2,12};
Line(16) = {3,13};
Line(17) = {4,14};
Line(18) = {5,15};
Circle(21) = {22,21,23};
Circle(22) = {23,21,24};
Circle(23) = {24,21,25};
Circle(24) = {25,21,22};
Line(25) = {2,22};
Line(26) = {3,23};
Line(27) = {4,24};
Line(28) = {5,25};
// define contours
Line Loop(1) = {1,2,3,4};
Line Loop(2) = {11,12,13,14};
Line Loop(3) = {21,22,23,24};
Line Loop(11) = {1,16,-11,-15};
Line Loop(12) = {2,17,-12,-16};
Line Loop(13) = {3,18,-13,-17};
Line Loop(14) = {4,15,-14,-18};
Line Loop(21) = {1,26,-21,-25};
Line Loop(22) = {2,27,-22,-26};
Line Loop(23) = {3,28,-23,-27};
Line Loop(24) = {4,25,-24,-28};
// define surfaces
Plane Surface(1) = {1};
Plane Surface(2) = {2};
Plane Surface(3) = {3};
Ruled Surface(11) = {11};
Ruled Surface(12) = {12};
Ruled Surface(13) = {13};
Ruled Surface(14) = {14};
Ruled Surface(21) = {21};
Ruled Surface(22) = {22};
Ruled Surface(23) = {23};
Ruled Surface(24) = {24};
// define shells
Surface Loop(1) = {-1,2,11,12,13,14};
Surface Loop(2) = {1,-3,-21,-22,-23,-24};
// define volumes
Volume(1) = {1};
Volume(2) = {2};
// meshing options
Mesh.ElementOrder = 2;
Mesh.CharacteristicLengthFactor = 3.5;
// link to physical domains
UpperCrystal = 1;
LowerCrystal = 2;
Top = 11;
Base = 12;
Physical Surface(Top) = {2};
Physical Surface(Base) = {3};
Physical Volume(UpperCrystal) = {1};
Physical Volume(LowerCrystal) = {2};
