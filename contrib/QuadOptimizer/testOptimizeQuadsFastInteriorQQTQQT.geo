// Complete interior T-Q-Q-T-Q-Q star around vertex 11. The dedicated
// half-edge rule must replace B=10, I=1 by six quads with B=10, I=2, then
// leave the all-quad result unchanged on a second Fast invocation.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;
Mesh.Smoothing = 0;

Point(1) = {3, 0, 0};
Point(2) = {2.4270509831248424, 1.7633557568774194, 0};
Point(3) = {0.9270509831248424, 2.8531695488854605, 0};
Point(4) = {-0.9270509831248420, 2.8531695488854610, 0};
Point(5) = {-2.4270509831248420, 1.7633557568774196, 0};
Point(6) = {-3, 0, 0};
Point(7) = {-2.4270509831248430, -1.7633557568774192, 0};
Point(8) = {-0.9270509831248427, -2.8531695488854605, 0};
Point(9) = {0.9270509831248417, -2.8531695488854610, 0};
Point(10) = {2.4270509831248420, -1.7633557568774200, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 6};
Line(6) = {6, 7};
Line(7) = {7, 8};
Line(8) = {8, 9};
Line(9) = {9, 10};
Line(10) = {10, 1};
Curve Loop(1) = {1:10};
Plane Surface(1) = {1};

Merge "testOptimizeQuadsFastInteriorQQTQQT.msh";
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
