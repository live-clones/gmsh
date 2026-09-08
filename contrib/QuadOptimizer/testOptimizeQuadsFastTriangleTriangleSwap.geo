// A folded two-triangle disk. The alternative diagonal strictly improves
// both triangle shape and the angle between their consistently oriented
// normals; it must be selected once and never flipped back.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Point(1) = {0, 0, 0};
Point(2) = {0.01089304858, 3.78273958903, -5.37661581619};
Point(3) = {2.74374632567, 1.82216649055, -0.479625099539};
Point(4) = {0.968731433336, -1.75002890813, -0.420326086453};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1:4};
Surface(1) = {1};

Merge "testOptimizeQuadsFastTriangleTriangleSwap.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
