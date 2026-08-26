SetFactory("OpenCASCADE");
//+
Point(1) = {0, 0, 0, 1.0};
//+
Point(2) = {1, 0.99, 0, 1.0};
//+
Point(3) = {0.03, 0.12, 0, 1.0};
//+
Point(4) = {0.07, 0.18, 0, 1.0};
//+
Point(5) = {0.13, 0.19, 0, 1.0};
//+
Point(6) = {0.16, 0.18, 0, 1.0};
//+
Point(7) = {0.19, 0.14, 0, 1.0};
//+
Point(8) = {0.21, 0.12, 0, 1.0};
//+
Point(9) = {0.25, 0.09, 0, 1.0};
//+
Point(10) = {0.32, 0.09, 0, 1.0};
//+
Point(11) = {0.39, 0.15, 0, 1.0};
//+
Point(12) = {0.4, 0.21, 0, 1.0};
//+
Point(13) = {0.4, 0.3, 0, 1.0};
//+
Point(14) = {0.4, 0.36, 0, 1.0};
//+
Point(15) = {0.46, 0.49, 0, 1.0};
//+
Point(16) = {0.52, 0.51, 0, 1.0};
//+
Point(17) = {0.59, 0.49, 0, 1.0};
//+
Point(18) = {0.59, 0.49, 0, 1.0};
//+
Point(19) = {0.63, 0.42, 0, 1.0};
//+
Point(20) = {0.67, 0.36, 0, 1.0};
//+
Point(21) = {0.74, 0.36, 0, 1.0};
//+
Point(22) = {0.76, 0.37, 0, 1.0};
//+
Point(23) = {0.81, 0.41, 0, 1.0};
//+
Point(24) = {0.84, 0.45, 0, 1.0};
//+
Point(25) = {0.86, 0.57, 0, 1.0};
//+
Point(26) = {0.88, 0.66, 0, 1.0};
//+
Point(27) = {0.89, 0.75, 0, 1.0};
//+
Point(28) = {0.88, 0.86, 0, 1.0};
//+
Point(29) = {0.86, 0.88, 0, 1.0};
//+
Point(30) = {0.83, 0.96, 0, 1.0};
//+
Point(31) = {0.83, 1.01, 0, 1.0};
//+
Point(32) = {0.84, 1.04, 0, 1.0};
//+
Point(33) = {0.93, 1.09, 0, 1.0};
//+
Point(34) = {0.97, 1.13, 0, 1.0};
//+
Point(35) = {1.01, 1.05, 0, 1.0};
//+
BSpline(1) = {1, 3, 4  ... 35, 2};
//+

Extrude {{0, 1, 0}, {-.3, 0, 0}, Pi/4} {
  Curve{1};
}
//+
MeshSize {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 1, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 53, 54, 55, 56, 57, 64, 65, 58, 66, 63, 59, 62, 60, 61, 67, 68, 70, 69} = 0.02;


Mesh 2;

Plugin(BoundaryLayer).Surfaces = "1";
Plugin(BoundaryLayer).Curves = "2,1,3,4";
Plugin(BoundaryLayer).Thickness = .1;
Plugin(BoundaryLayer).Size = .01;
Plugin(BoundaryLayer).Ratio = 1.2;
Plugin(BoundaryLayer).SmoothingLayers = 16;
Plugin(BoundaryLayer).HighOrder = 1;
Plugin(BoundaryLayer).MeanPlaneUntangler = 1;
Plugin(BoundaryLayer).MeanPlaneDebugPatches = 1;
Plugin(BoundaryLayer).ParametricQuadraturePoints = 7;
Plugin(BoundaryLayer).Run;
Save "bl2d_non_planar.msh";
