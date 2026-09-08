// Two valid quadrangles sharing a vertex but no edge form a pinched
// (bow-tie) vertex link. Edge-incidence checks alone accept this input; the
// half-edge vertex-link invariant must reject it without modifying the face.
General.Terminal = 1;
General.NumThreads = 1;

Point(101) = {-2, -2, 0};
Point(102) = { 2, -2, 0};
Point(103) = { 2,  2, 0};
Point(104) = {-2,  2, 0};
Line(101) = {101, 102};
Line(102) = {102, 103};
Line(103) = {103, 104};
Line(104) = {104, 101};
Curve Loop(1) = {101:104};
Plane Surface(1) = {1};

Merge "testOptimizeQuadsFastBowTieVertexGuard.msh";
OptimizeMesh "OptimizeQuadsFast";
