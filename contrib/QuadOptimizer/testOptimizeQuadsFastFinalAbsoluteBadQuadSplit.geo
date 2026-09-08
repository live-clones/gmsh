// One convex planar quadrangle that fails the absolute maximum-angle
// specification. All its edges and both diagonals satisfy [h/2, 2h]. The
// final repair must preserve this physically valid quad and report its quality
// violation. A second optimizer invocation must leave it unchanged as well.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;
Mesh.Smoothing = 0;
Mesh.QuadqsTargetSize = 2;
Mesh.QuadqsMinimumEdgeLength = 1;
Mesh.QuadqsMaximumEdgeLength = 4;

Point(1) = {0, 0, 0};
Point(2) = {2, 0, 0};
Point(3) = {3, 0.1, 0};
Point(4) = {0, 2, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1:4};
Plane Surface(1) = {1};

Merge "testOptimizeQuadsFastFinalAbsoluteBadQuadSplit.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
