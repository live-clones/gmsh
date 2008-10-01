/* --------------------------------------------------------------------------
    This is a gmsh geometry file
   --------------------------------------------------------------------------*/
 
res1  = 1e-1;
x = 1.0;
y = 0.1;

a0 = newp; Point(a0) = {0,0,0,res1};
a1 = newp; Point(a1) = {-x,0,0,res1};
a2 = newp; Point(a2) = {x,0,0,res1};

la1 = newl; Circle(la1) = {a1,a0,a2};
la2 = newl; Circle(la2) = {a2,a0,a1};
    
loop = newll; Line Loop(loop) = {la1,la2}; 

sa = news; Plane Surface(sa) = {loop};

Point(4) = {-2, -2, 0};
Point(5) = {2, -2, 0};
Point(6) = {2, 2, 0};
Point(7) = {-2, 2, 0};
Line(5) = {4, 5};
Line(6) = {5, 6};
Line(7) = {6, 7};
Line(8) = {7, 4};
Line Loop(9) = {7, 8, 5, 6};
Plane Surface(10) = {9, 3};

// specifying explicit element sizes as a function of the distance to
// the point a0 (square function here)
Field[1] = Attractor;
Field[1].EdgesList = {la1,la2,6};
Field[1].NNodesByEdge = 100;
Field[2] = MathEval;
Field[2].F = Sprintf("F1^2 + %g", res1/4);
Field[3] = Restrict;
Field[3].IField = 2;
Field[3].FacesList = {10};
Field[3].EdgesList = {la1,la2, 5:8};

Field[4] = MathEval;
Field[4].F = "0.2";
Field[5] = Restrict;
Field[5].IField = 4;
Field[5].FacesList = {sa};

Field[6] = Min;
Field[6].FieldsList = {3,5};

Background Field = 6;

Mesh.CharacteristicLengthExtendFromBoundary = 0;
