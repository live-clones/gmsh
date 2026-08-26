//+
SetFactory("OpenCASCADE");
Rectangle(1) = {-0.5, -0.5, 0, 1, 1, 0};
//+
Point(5) = {-0.25, -0, 0, 1.0};
//+
Point(6) = {-0.16, 0.06, 0, 1.0};
//+
Point(7) = {-0.04, 0.09, 0, 1.0};
//+
Point(8) = {0.08, 0.07, 0, 1.0};
//+
Point(9) = {0.19, 0.02, 0, 1.0};
//+
Point(10) = {0.21, -0.06, 0, 1.0};
//+
Point(11) = {0.15, -0.12, 0, 1.0};
//+
Point(12) = {0.07, -0.11, 0, 1.0};
//+
Point(13) = {-0, -0.07, 0, 1.0};
//+
Point(14) = {-0.12, -0.06, 0, 1.0};
//+
Point(15) = {-0.23, -0.1, 0, 1.0};
//+
Point(16) = {-0.31, -0.05, 0, 1.0};
//+
BSpline(5) = {16, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//+
Curve Loop(2) = {3, 4, 1, 2};
//+
Plane Surface(2) = {2};
//+
Curve Loop(3) = {5};
//+
Plane Surface(3) = {3};
//+
Extrude {0, 0, .3} {
  Surface{3};
}
//+
Extrude {0, 0, 1} {
  Surface{1};
}
//+

BooleanDifference{ Volume{2}; Delete; }{ Volume{1}; Delete; }
//+
Recursive Delete {
  Surface{2};
}
//+
MeshSize {18, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17} = 0.02;
//+
MeshSize {21, 22, 3, 4, 19, 20, 1, 2} = 0.2;


Mesh 3;

// Boundary-layer wall faces: the airfoil surface and the tip cap. Surface 9 is
// the symmetry plane; it is not pushed as a wall, but the plugin automatically
// creates the closing quads on it from the adjacent wall boundary.
Plugin(BoundaryLayer).Surfaces = "4,5";
Plugin(BoundaryLayer).Volumes = "2";
Plugin(BoundaryLayer).Thickness = 0.08;
Plugin(BoundaryLayer).Size = 0.001;
Plugin(BoundaryLayer).Ratio = 1.2;
Plugin(BoundaryLayer).SmoothingLayers = 4;
Plugin(BoundaryLayer).HighOrder = 1;
Plugin(BoundaryLayer).Run;

Save "koen.msh";
