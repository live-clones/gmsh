// The reflex boundary vertex 1 owns one connected T-Q-Q-T fan. The dedicated
// boundary_t_qn_t rule must remove both terminal triangles, and the complete
// half-edge catalog must then close to a valid manifold fixed point.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;
Mesh.Smoothing = 0;

Point(1) = {0, 0, 0};
Point(2) = {1, -1, 0};
Point(3) = {2, 0, 0};
Point(4) = {2, 2, 0};
Point(5) = {0, 3, 0};
Point(6) = {-2, 2, 0};
Point(7) = {-2, 0, 0};
Point(8) = {-1, -1, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 6};
Line(6) = {6, 7};
Line(7) = {7, 8};
Line(8) = {8, 1};
Curve Loop(1) = {1:8};
Plane Surface(1) = {1};

Merge "testOptimizeQuadsFastBoundaryTriangleQuadFan.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
