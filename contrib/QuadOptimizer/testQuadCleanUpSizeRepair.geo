// The interior vertex initially creates one edge shorter than 2. Shape-only
// smoothing is insufficient: QuadCleanUp must use its guarded size step.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Mesh.QuadqsTargetSize = 4;
Mesh.QuadqsMinimumEdgeLength = 2;
Mesh.QuadqsMaximumEdgeLength = 8;

Point(1) = {0, 0, 0};
Point(2) = {4, 0, 0};
Point(3) = {8, 0, 0};
Point(4) = {8, 4, 0};
Point(5) = {8, 8, 0};
Point(6) = {4, 8, 0};
Point(7) = {0, 8, 0};
Point(8) = {0, 4, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 6};
Line(6) = {6, 7};
Line(7) = {7, 8};
Line(8) = {8, 1};
Curve Loop(1) = {1:8};
Plane Surface(1) = {1};

Merge "testQuadCleanUpSizeRepair.msh";
OptimizeMesh "QuadCleanUp";
OptimizeMesh "QuadCleanUp";
