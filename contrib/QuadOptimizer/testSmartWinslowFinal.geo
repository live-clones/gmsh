// An asymmetric four-quad star: the Smart Laplacian and Winslow objectives
// have different minimizers, so both final phases must move its free node.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;
Mesh.Smoothing = 3;
Point(1) = {0, 0, 0};
Point(2) = {.9, 0, 0};
Point(3) = {2, 0, 0};
Point(4) = {2, 1.2, 0};
Point(5) = {2, 2, 0};
Point(6) = {1.3, 2, 0};
Point(7) = {0, 2, 0};
Point(8) = {0, .8, 0};
For i In {1:7}
  Line(i) = {i, i+1};
EndFor
Line(8) = {8, 1};
Curve Loop(1) = {1:8};
Plane Surface(1) = {1};
Merge "testSmartWinslowFinal.msh";
OptimizeMesh "OptimizeQuadsFast";
