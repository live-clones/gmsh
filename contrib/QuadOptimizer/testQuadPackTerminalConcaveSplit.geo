// PACK must first create this single concave quad, then the unconditional
// terminal validity pass must split it even with the quality filter disabled.
SetFactory("Built-in");
Point(1) = {0, 0, 0, 10};
Point(2) = {2, 0, 0, 10};
Point(3) = {0.5, 0.5, 0, 10};
Point(4) = {0, 2, 0, 10};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};

Mesh.Algorithm = 9;
Mesh.RecombineAll = 1;
Mesh.RecombineMinimumQuality = 0;
Mesh.MeshSizeMin = 10;
Mesh.MeshSizeMax = 10;
Mesh.MshFileVersion = 2.2;
