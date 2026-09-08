// Complete B=6, I=1 interior star with cyclic face pattern Q-T-Q-T.
// The center must disappear and the best opposite-vertex diagonal must
// replace the four-cell mixed star by two quadrangles. The second pass checks
// that the all-quad result is a fixed point.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Point(1) = {0, 0, 0};
Point(2) = {1, 0, 0};
Point(3) = {2, 0.2, 0};
Point(4) = {2, 1, 0};
Point(5) = {1, 1, 0};
Point(6) = {0, 0.8, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 6};
Line(6) = {6, 1};
Curve Loop(1) = {1:6};
Plane Surface(1) = {1};

Merge "testOptimizeQuadsFastInteriorQTQT.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
