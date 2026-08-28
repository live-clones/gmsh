General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Mesh.QuadqsTargetSize = 4;
Mesh.QuadqsMinimumEdgeLength = 2;
Mesh.QuadqsMaximumEdgeLength = 8;
Mesh.Smoothing = 5;

Point(1) = {0, 0, 0};
Point(2) = {2, -0.1, 0};
Point(3) = {4, 0, 0};
Point(4) = {4, 2, 0};
Point(5) = {2, 2.1, 0};
Point(6) = {0, 2, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 6};
Line(6) = {6, 1};
Curve Loop(1) = {1:6};
Plane Surface(1) = {1};

Merge "testQuadCleanUpFixedPoint.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
