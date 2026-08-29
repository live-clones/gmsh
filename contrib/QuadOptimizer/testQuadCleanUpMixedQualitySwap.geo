// The same all-acceptable pentagon as the Fast quality-only regression. Full
// QuadCleanUp must visit mixed swaps during its OtherImprovement phase and
// reach a fixed point on the next invocation.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Mesh.QuadqsTargetSize = 2;
Mesh.QuadqsMinimumEdgeLength = 1;
Mesh.QuadqsMaximumEdgeLength = 4;

Point(1) = {0, 0, 0};
Point(2) = {2, 0, 0};
Point(3) = {3.3, 1.2, 0};
Point(4) = {2, 2, 0};
Point(5) = {0, 2, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 1};
Curve Loop(1) = {1:5};
Plane Surface(1) = {1};

Merge "testOptimizeQuadsFastMixedQualitySwap.msh";
OptimizeMesh "QuadCleanUp";
OptimizeMesh "QuadCleanUp";
