// A convex pentagon split by its poor 1-3 diagonal. The initial triangle is
// nearly flat; switching to diagonal 2-4 makes both elements satisfy every
// absolute shape specification. A second Fast invocation must be idle.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Point(1) = {0, 0, 0};
Point(2) = {2, -0.1, 0};
Point(3) = {4, 0, 0};
Point(4) = {4, 4, 0};
Point(5) = {0, 4, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 1};
Curve Loop(1) = {1:5};
Plane Surface(1) = {1};

Merge "testOptimizeQuadsFastMixedSwap.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
