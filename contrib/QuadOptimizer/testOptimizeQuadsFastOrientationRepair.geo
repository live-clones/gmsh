// Two geometrically adjacent quads traverse their shared edge in the same
// direction because the right quad is reversed. This is a regular orientable
// cell complex: Fast must repair the local ordering instead of rejecting it.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Point(1) = {0, 0, 0};
Point(2) = {1, 0, 0};
Point(3) = {1, 1, 0};
Point(4) = {0, 1, 0};
Point(5) = {2, 0, 0};
Point(6) = {2, 1, 0};
Line(1) = {1, 2};
Line(2) = {2, 5};
Line(3) = {5, 6};
Line(4) = {6, 3};
Line(5) = {3, 4};
Line(6) = {4, 1};
Curve Loop(1) = {1:6};
Plane Surface(1) = {1};

Merge "testOptimizeQuadsFastOrientationRepair.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
