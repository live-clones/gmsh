//+
SetFactory("OpenCASCADE");
//+
Point(1) = {-0, 0, 0, 1.0};
//+
Point(2) = {1, 0, 0, 1.0};
//+
Point(3) = {0.2, 0.1, 0, 1.0};
//+
Point(4) = {0.5, 0.2, 0, 1.0};
//+
Point(5) = {0.7, 0.1, 0, 1.0};
//+
Point(6) = {0.2, -0.3, 0, 1.0};
//+
Point(7) = {0.6, -0.2, 0, 1.0};
//+
Point(8) = {0.9, -0.1, 0, 1.0};
//+
BSpline(1) = {2, 5, 4, 3, 1, 6, 7, 8, 2};
Rectangle(1) = {-0.5, -0.6, 0, 2, 1, 0};
//+
Curve Loop(4) = {4, 5, 2, 3};
//+
Curve Loop(5) = {1};
//+
Plane Surface(3) = {4, 5};
Plane Surface(4) = {5};
//+
Recursive Delete {
  Surface{1}; 
}
//+
MeshSize {1, 2, 3, 4, 5, 6, 7, 8, 9} = 0.02;
//+
MeshSize {13, 12, 11, 10} = 0.1;
