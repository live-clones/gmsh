// A mixed triangle-quad one-ring has one edge shorter than 2. QuadCleanUp
// keeps the mixed topology but must move its sole interior vertex, then be
// geometrically idle on a second invocation.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Mesh.QuadqsTargetSize = 4;
Mesh.QuadqsMinimumEdgeLength = 2;
Mesh.QuadqsMaximumEdgeLength = 8;

Point(1) = {3, 0, 0};
Point(2) = {0, 3, 0};
Point(3) = {-3, 3, 0};
Point(4) = {-3, 0, 0};
Point(5) = {0, -3, 0};
Point(6) = {3, -3, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 6};
Line(6) = {6, 1};
Curve Loop(1) = {1:6};
Plane Surface(1) = {1};

Merge "testQuadCleanUpMixedSizeRepair.msh";
OptimizeMesh "QuadCleanUp";
OptimizeMesh "QuadCleanUp";
