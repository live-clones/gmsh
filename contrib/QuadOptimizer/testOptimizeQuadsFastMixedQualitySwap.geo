// A convex pentagon split by diagonal 1-3. All cells pass the absolute
// specifications, but the triangle and quadrangle have four preferred shape
// violations. Diagonal 2-4 yields a good triangle plus a square, with no CAD
// vertex motion and a shorter, target-sized internal edge.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

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
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
