Mesh.Algorithm=1;
Mesh.CharacteristicLengthFactor=1.5;

lc=0.1;
Point(1) = {0.1, 0.1, 0.1}; //,lc};
Point(2) = {0.1, 10, 0.1}; //,lc};
Point(3) = {10, 10, 0.1}; //,lc};
Point(4) = {10, 0.1, 0.1}; //,lc};
Line(1) = {2, 3};
Line(2) = {3, 4};
Line(3) = {4, 1};
Line(4) = {1, 2};

Line Loop(5) = {1, 2, 3, 4};
Plane Surface(6) = {5};

Physical Line("top") = {1};
Physical Line("bottom") = {3};
Physical Line("left") = {4};
Physical Line("right") = {2};
Physical Surface("inside") = {6};

Mesh 2;
Levelset Plane (1) = {0,1,0,-7};
//Levelset Point (1) = {{0.1, 2, 0},{3,2,0},{9,2,0},{5,2,0}, {0.1, 2.2, -1},{3,2.5,-1},{9,2,-1},{5,2,-1}, {0.2, 2, 1},{3,2,1},{9,2,1},{5,2,1}}; 

Levelset CutMeshTri {1};

Print "squareP_cut.msh";




