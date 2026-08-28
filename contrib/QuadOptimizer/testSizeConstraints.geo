// Fine-mesh edge requirements: target 4, inclusive interval [2, 8].
General.Terminal = 1;
General.AbortOnError = 1;

Mesh.QuadqsTargetSize = 4;
Mesh.QuadqsMinimumEdgeLength = 2;
Mesh.QuadqsMaximumEdgeLength = 8;

Point(1) = {0, 0, 0, 4};
Point(2) = {8, 0, 0, 4};
Point(3) = {8, 2, 0, 4};
Point(4) = {0, 2, 0, 4};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};

Transfinite Curve {1:4} = 2;
Transfinite Surface {1};
Recombine Surface {1};

Mesh 2;
OptimizeMesh "OptimizeQuads";
