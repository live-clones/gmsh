Mesh.CharacteristicLengthFromCurvature=1;
Mesh.MinimumCirclePoints=20;
l = .2;
Point(1) = {-1.1, -0.3, 0, l};
Point(2) = {-0.3, -0, 0, l};
Point(3) = {1, -0.3, 0, l};
Point(4) = {-0.3, -0.6, 0, l};
Point(5) = {0.7, -0.2, 0, l};
Point(6) = {0.7, -0.4, 0, l};
Spline(1) = {1, 4, 6, 3};
Spline(11) = {3 , 5 , 2 , 1};
Point(7) = {-1.4, .5, 0, l};
Point(8) = {-1.4, -1.1, 0, l};
Point(9) = {3.4, -1.1, 0, l};
Point(10) = {3.4, .5, 0, l};
Line(2) = {7, 10};
Line(3) = {9, 10};
Line(4) = {9, 8};
Line(5) = {8, 7};
Line Loop(6) = {2, -3, 4, 5};
Line Loop(7) = {1, 11};
Plane Surface(8) = {6, 7};

Point(11) = {2.2, -0.3, 0, l};
Line(9) = {3, 11};
Line {9} In Surface {8};

Field[1] = BoundaryLayer;
Field[1].EdgesList = {1, 11, 9};
Field[1].hfar = 0.1;
Field[1].hwall_n = 0.01;
Field[1].thickness = 0.1;
Field[1].ratio = 1.4;
Field[1].FanNodesList = {1, 11}; // try e.g. removing 11
Field[1].Quads = 1;
BoundaryLayer Field = 1;
