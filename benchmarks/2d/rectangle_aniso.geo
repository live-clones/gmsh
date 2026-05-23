Mesh.Algorithm = 7; //Bamg
Mesh.MeshSizeExtendFromBoundary = 0;

L = 2;
H = 1;

Point(1) = {0, 0, 0};
Point(2) = {L, 0, 0};
Point(3) = {L, H, 0};
Point(4) = {0, H, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Line Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};

Field[2] = MathEvalAniso;
Field[2].m11 = "1./(x + 0.005)^2";
Field[2].m12 = "0";
Field[2].m13 = "0";
Field[2].m22 = "1/(0.005)^2";
Field[2].m23 = "0";
Field[2].m33 = "1/(0.1)^2";
Background Field = 2;
