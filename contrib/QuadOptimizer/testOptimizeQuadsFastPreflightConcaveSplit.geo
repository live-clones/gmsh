// Blossom can create this pair from four perfectly regular triangles: the
// two quads lie on opposite sides of the chain 1-2-3, but both contain its
// two edges. Quad 1-2-3-4 is concave at 2 and the other quad is consistently
// reversed. Restoring diagonal 2-4, then reversing that second quad, must make
// the cell complex regular before Fast builds its half-edge index.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Point(1) = {0, 0, 0};
Point(2) = {1, 0.2, 0};
Point(3) = {2, 0, 0};
Point(4) = {1, 1, 0};
Point(5) = {1, -1, 0};
Line(1) = {1, 5};
Line(2) = {5, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1:4};
Plane Surface(1) = {1};
Point{2} In Surface{1};

Merge "testOptimizeQuadsFastPreflightConcaveSplit.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
