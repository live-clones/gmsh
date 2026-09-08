// Six quadrangles around one interior vertex form the B=12, I=1 valence-six
// cavity. Fast must split the singularity into two interior vertices, producing
// seven valid quadrangles, and the second pass must be a fixed point.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;
Mesh.Smoothing = 0;

Point(1) = {2, 0, 0};
Point(2) = {1.7320508075688772, 1, 0};
Point(3) = {1, 1.7320508075688772, 0};
Point(4) = {0, 2, 0};
Point(5) = {-1, 1.7320508075688772, 0};
Point(6) = {-1.7320508075688772, 1, 0};
Point(7) = {-2, 0, 0};
Point(8) = {-1.7320508075688772, -1, 0};
Point(9) = {-1, -1.7320508075688772, 0};
Point(10) = {0, -2, 0};
Point(11) = {1, -1.7320508075688772, 0};
Point(12) = {1.7320508075688772, -1, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 6};
Line(6) = {6, 7};
Line(7) = {7, 8};
Line(8) = {8, 9};
Line(9) = {9, 10};
Line(10) = {10, 11};
Line(11) = {11, 12};
Line(12) = {12, 1};
Curve Loop(1) = {1:12};
Plane Surface(1) = {1};

Merge "testOptimizeQuadsFastValenceSix.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
