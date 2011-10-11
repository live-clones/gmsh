lc = 0.1;
Point(1) = {0.0,0.0,0.0,lc};
Point(2) = {1,0.0,0.0,lc};
Point(3) = {1,1,0.0,lc};
Point(4) = {0,1,0.0,lc};
Line(1) = {4,3};
Line(2) = {3,2};
Line(3) = {2,1};
Line(4) = {1,4};
Line Loop(5) = {2,3,4,1};
Plane Surface(6) = {5};
Extrude {0,0.0,1} {
  Surface{6};
}

Mesh 3;
Levelset Plane (1) = {0,-1,0,0.5};
Levelset Plane (2) = {-1,0,0,0.5};
Levelset Sphere (3) = {{0.75,0.5,0.5},0.5};
Levelset Ellipsoid (4) = { {0,0,0}, {1,0,0}, 0.45, 0.25, 0.75 };
Levelset MathEval (5) = "(x-0.5)^2+(y-0.5)^2+(z-0.5)^2-0.5^2";
Levelset MathEval (6) = "-((x-0.5)^2+(y-0.5)^2+(z-0.5)^2-0.4^2)";
Levelset Sphere (7) = {{0.75,0.5,0.5},0.4};
Levelset Intersection (10) = {1,2,3};
Levelset Intersection (11) = {5,6};
Levelset Cut (12) = {3,7};

Levelset Point(13)={{0.5,0,0},{0.5,0.5,0.},{0.5,1,0},{0.5,0,0.5},{0.5,0,0.8},{0.5,0.5,0.5},{0.5,0.5,1},{0.5,1,0.5},{1.5,1,1}};

Levelset CutMeshTri {13};


