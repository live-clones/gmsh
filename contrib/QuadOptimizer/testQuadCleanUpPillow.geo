// The hole is bordered by triangles, so it does not initially have a complete
// quadrilateral ring. The outer row contains quads so QuadCleanUp visits the
// face. Pillow insertion starts with an infinitesimal duplicate of the hole
// boundary; it can satisfy the minimum length of 1 only after Winslow opens
// and validates the complete in-memory patch.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

Mesh.QuadqsPillowLayers = 1;
Mesh.QuadqsTargetSize = 4;
Mesh.QuadqsMinimumEdgeLength = 1;
Mesh.QuadqsMaximumEdgeLength = 10;

Point(1) = {-8, -8, 0};
Point(2) = {0, -8, 0};
Point(3) = {8, -8, 0};
Point(4) = {8, 0, 0};
Point(5) = {8, 8, 0};
Point(6) = {0, 8, 0};
Point(7) = {-8, 8, 0};
Point(8) = {-8, 0, 0};
Point(17) = {-2, -2, 0};
Point(18) = {0, -2, 0};
Point(19) = {2, -2, 0};
Point(20) = {2, 0, 0};
Point(21) = {2, 2, 0};
Point(22) = {0, 2, 0};
Point(23) = {-2, 2, 0};
Point(24) = {-2, 0, 0};

Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 6};
Line(6) = {6, 7};
Line(7) = {7, 8};
Line(8) = {8, 1};
Line(9) = {17, 18};
Line(10) = {18, 19};
Line(11) = {19, 20};
Line(12) = {20, 21};
Line(13) = {21, 22};
Line(14) = {22, 23};
Line(15) = {23, 24};
Line(16) = {24, 17};
Curve Loop(1) = {1:8};
Curve Loop(2) = {9:16};
Plane Surface(1) = {1, 2};

Merge "testQuadCleanUpPillow.msh";
OptimizeMesh "QuadCleanUp";
OptimizeMesh "QuadCleanUp";
