// A convex pentagon whose initial and best T+Q diagonals both leave
// absolute shape violations. The Fast mixed swap must nevertheless accept
// the strict affected-support improvement, then be at a fixed point.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Point(1) = {2.7374054999784984, 2.3215421580419393, 0};
Point(2) = {1.3221012648927631, 2.3896423571881090, 0};
Point(3) = {0.1827097157294040, 2.1486985816389588, 0};
Point(4) = {3.3520629187033770, 0.2556129750225806, 0};
Point(5) = {3.5489065788630414, 1.6159054589977639, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 1};
Curve Loop(1) = {1:5};
Plane Surface(1) = {1};

Merge "testOptimizeQuadsFastMixedBadImprovement.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
