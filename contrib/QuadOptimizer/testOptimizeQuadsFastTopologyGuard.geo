// A triangle embedded in a quadrangle is not a regular surface cell complex:
// both cells traverse edges 1->2 and 2->3 in the same direction. Fast must
// reject the face before trying any cavity or collapse.
General.Terminal = 1;
General.NumThreads = 1;

Point(1) = {0, 0, 0};
Point(2) = {2, 0, 0};
Point(3) = {1, 1, 0};
Point(4) = {-1, 1, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1:4};
Plane Surface(1) = {1};

Merge "testOptimizeQuadsFastTopologyGuard.msh";
OptimizeMesh "OptimizeQuadsFast";
