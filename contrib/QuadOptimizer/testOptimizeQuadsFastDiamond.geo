// The central thin quad has two opposite interior valence-three vertices.
// Fast must collapse this diamond as one quality-validated transaction, then
// reach a fixed point on the second invocation.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Point(1) = {0, 1, 0};
Point(2) = {0, 0, 0};
Point(3) = {1, 0, 0};
Point(4) = {2, 0, 0};
Point(5) = {2, 1, 0};
Point(6) = {2, 2, 0};
Point(7) = {1, 2, 0};
Point(8) = {0, 2, 0};
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

Mesh.QuadqsTargetSize = 1;
Mesh.QuadqsMinimumEdgeLength = 0.05;
Mesh.QuadqsMaximumEdgeLength = 5;
Merge "testOptimizeQuadsFastDiamond.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
