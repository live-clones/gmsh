// Both quads share 1-2-3 and put their private corner on the same side of
// each shared segment. One quad is concave, but splitting it would merely
// hide the overlap. The non-mutating UV preflight must reject it first.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 2;

Point(1) = {0, 0, 0};
Point(2) = {2, 0, 0};
Point(3) = {2, 2, 0};
Point(4) = {1.5, 1, 0};
Point(5) = {0, 2, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 5};
Line(4) = {5, 1};
Curve Loop(1) = {1:4};
Plane Surface(1) = {1};
Point{4} In Surface{1};

Merge "testOptimizeQuadsFastOverlappingQuadsGuard.msh";
OptimizeMesh "OptimizeQuadsFast";
