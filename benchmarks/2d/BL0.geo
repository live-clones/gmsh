Mesh.CharacteristicLengthFromCurvature=1;
Mesh.MinimumCirclePoints=20;
l = .2;
Point(7) = {-1.4, 0.5, 0, l};
//+
Point(8) = {-1.4, -1.1, 0, l};
//+
Point(9) = {1.4, -1.1, 0, l};
//+
Point(10) = {1.4, 0.5, 0, l};
//+
Line(2) = {7, 10};
//+
Line(3) = {9, 10};
//+
Line(4) = {9, 8};
//+
Line(5) = {8, 7};
//+
Line Loop(7) = {2,-3,4,5};
//+
Plane Surface(8) = {7};
//+
Field[1] = BoundaryLayer;
//+
Field[1].EdgesList = {4};
//+
Field[1].hfar = 0.1;
//+
Field[1].hwall_n = 0.005;
//+
Field[1].thickness = 0.1;
//+
BoundaryLayer Field = 1;

//+
Field[1].ratio = 1.4;
//+
Field[1].NodesList = {8, 9};
