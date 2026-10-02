// Even quantization adds a midpoint to this odd five-segment boundary.
// Blossom rejects the two inverted pairs in the resulting four-triangle mesh.
// V2 must recover one valid quad while retaining the other two triangles and
// every boundary segment, including the midpoint.
SetFactory("Built-in");
Point(1) = {0, 0, 0, 10};
Point(2) = {2, 0, 0, 10};
Point(3) = {1.5, 2.6, 0, 10};
Point(4) = {4, 4, 0, 10};
Point(5) = {0, 4, 0, 10};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 1};
Curve Loop(1) = {1:5};
Plane Surface(1) = {1};

Mesh.Algorithm = 9;
Mesh.RecombineAll = 1;
Mesh.RecombineMinimumQuality = 0;
Mesh.MeshSizeMin = 10;
Mesh.MeshSizeMax = 10;
Mesh.MshFileVersion = 2.2;
