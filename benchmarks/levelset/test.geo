lc = 0.1;
Point(1) = {0.0,0.0,0.0,lc};
Point(2) = {1,0.0,0.0,lc};
Point(3) = {1,1,0.0,lc};
Point(4) = {0,1,0.0,lc};
Line(1) = {4,3};
Line(2) = {3,2};
Line(3) = {2,1};
Line(4) = {1,4};
Line Loop(5) = {2,3,4,1};
Plane Surface(6) = {5};
Extrude {0,0.0,1} {
  Surface{6};
}

Physical Point (1) = {1};
Physical Point (2) = {2};
Physical Point (3) = {3};
Physical Point (4) = {4};
Physical Line (1) = {1};
Physical Line (2) = {2};
Physical Line (3) = {3};
Physical Line (4) = {4};
Physical Surface("back") = {6};
Physical Surface("right") = {15};
Physical Surface("bottom") = {19};
Physical Surface("left") = {23};
Physical Surface("top") = {27};
Physical Surface("front") = {28};

Physical Volume("vol") = {1};

Mesh 3;

// Definition of the levelsets
Levelset MathEval (1) = "x^2+y^2-0.8";
Levelset Plane (2) = {0,0,1,-0.5};
Levelset Union (3) = {1,2};
Levelset CutMesh {3};

