// The 1D mesh of the annulus intersects itself: the 4 segments of the outer
// circle cut the 40 segments of the inner one. With several threads, the
// surface is left for a serial pass, which splits the curves; it used to be
// left without a mesh when Mesh.MaxRetries was 2 or less, with a warning only.

General.NumThreads = 4;
Mesh.MaxRetries = 2;

Point(1) = {0, 0, 0};
Point(2) = {1, 0, 0}; Point(3) = {0, 1, 0}; Point(4) = {-1, 0, 0}; Point(5) = {0, -1, 0};
Point(6) = {0.9, 0, 0}; Point(7) = {0, 0.9, 0}; Point(8) = {-0.9, 0, 0}; Point(9) = {0, -0.9, 0};
Circle(1) = {2, 1, 3}; Circle(2) = {3, 1, 4}; Circle(3) = {4, 1, 5}; Circle(4) = {5, 1, 2};
Circle(5) = {6, 1, 7}; Circle(6) = {7, 1, 8}; Circle(7) = {8, 1, 9}; Circle(8) = {9, 1, 6};
Curve Loop(1) = {1, 2, 3, 4}; Curve Loop(2) = {5, 6, 7, 8};
Plane Surface(1) = {1, 2};
Plane Surface(2) = {2};
Transfinite Curve{1, 2, 3, 4} = 2;
Transfinite Curve{5, 6, 7, 8} = 11;

Mesh 2;

// (the disk alone has about 300 triangles, the annulus as many)
If(Mesh.NbTriangles < 450)
  Error("The annulus was not meshed (%g triangles in all)", Mesh.NbTriangles);
EndIf
