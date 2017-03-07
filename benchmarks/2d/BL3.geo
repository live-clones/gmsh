//Mesh.CharacteristicLengthExtendFromBoundary = 0;
//Mesh.CharacteristicLengthMin = 0.1;
//Mesh.CharacteristicLengthMax = 0.1;
//+
Point(1) = {-1.7, -0.3, 0, .1};
//+
Point(2) = {-1.2, -0, 0, .1};
//+
Point(3) = {-0.5, -0.3, 0, .1};
//+
Point(4) = {-0.4, -0.7, 0, .1};
//+
Point(5) = {-0.8, -0.8, 0, .1};
//+
Point(6) = {-1.2, -0.5, 0, .1};
//+
Point(7) = {-1.8, -0.5, 0, .1};
//+
Point(8) = {-1.1, 0.6, 0, .1};
//+
Point(9) = {-0.5, 0.7, 0, .1};
//+
Point(10) = {-0.1, 0.2, 0, .1};
//+
Point(11) = {-0.3, -0.1, 0, .1};
//+
Point(12) = {-0.7, 0.2, 0, .1};
//+
Point(13) = {-1.1, 0.4, 0, 1.0};
//+
Point(14) = {-1.5, 0.5, 0, .1};
//+
Point(15) = {-2.3, 1.1, 0, .1};
//+
Point(16) = {-2.3, -1, 0, .1};
//+
Point(17) = {0.7, -1, 0, .1};
//+
Point(18) = {0.5, 1.1, 0, .1};
//+
Line(1) = {15, 16};
//+
Line(2) = {16, 17};
//+
Line(3) = {17, 18};
//+
Line(4) = {18, 15};
//+
Spline(5) = {14, 8, 9, 10, 11, 12, 13, 14};
//+
Spline(6) = {2, 3, 4, 5, 6, 7, 1, 2};
//+
Field[1] = BoundaryLayer;
//+
Field[1].EdgesList = {5, 6, 1};
//+
Field[1].hfar = 0.1;
//+
Field[1].hwall_n = 0.001;
//+
Field[1].ratio = 1.4;
//+
Field[1].thickness = .35;
BoundaryLayer Field = 1;
//+
Line Loop(7) = {1, 2, 3, 4};
//+
Line Loop(8) = {5};
//+
Line Loop(9) = {6};
//+
Plane Surface(10) = {7, 8, 9};
//+
Characteristic Length {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14} = 0.1;
//+
Field[1].FanNodesList = {14};
//+
Characteristic Length {17, 16, 5, 4, 6, 7, 3, 1, 11, 2, 10, 12, 13, 14, 8, 9, 15, 18} = 0.1;
//+
//Field[1].Quads = 1;
//+
//Field[1].thickness = 1;
//+
Field[1].NodesList = {15, 16};
