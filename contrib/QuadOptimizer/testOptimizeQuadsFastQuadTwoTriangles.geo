// A six-vertex disk made of one quadrangle and two adjacent triangles.
// Fast cleanup must replace the three cells by two valid quadrangles, then
// reach a fixed point on the second invocation.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Point(1) = {0, 0, 0};
Point(2) = {2, -0.2, 0};
Point(3) = {4, 0, 0};
Point(4) = {4, 3, 0};
Point(5) = {2, 3.2, 0};
Point(6) = {0, 3, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 6};
Line(6) = {6, 1};
Curve Loop(1) = {1:6};
Plane Surface(1) = {1};

Merge "testOptimizeQuadsFastQuadTwoTriangles.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
