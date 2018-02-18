// SetFactory("OpenCASCADE");
Point(1) = {0  , 0  , 0, 0.2};
Point(2) = {-0.1, 0.5, 0, 0.2};
Point(3) = {-1, 0.8, 0, 0.2};
Point(4) = {0  , 1  , 0, 0.2};
Point(5) = {1  , 1  , 0, 0.2};
Point(6) = {1  , 0  , 0, 0.2};
Spline(1) = {1, 2, 3, 4, 5, 6};
//BSpline(1) = {1, 2, 3, 4, 5, 6};

Line(2) = {6, 1};
Line Loop(1) = {1, 2};
Plane Surface(1) = {1};
Mesh.CharacteristicLengthFromCurvature = 1;
Mesh.MinimumCirclePoints = 50; // points per 2*pi
