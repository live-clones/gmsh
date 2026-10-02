General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

SetFactory("OpenCASCADE");
Circle(1) = {0, 0, 0, 1, 0, 1.5};
out[] = Extrude {0, 0, 1} { Curve{1}; };

Merge "testOptimizeQuadsFastCurved.msh";
Mesh.Smoothing = 5;
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
