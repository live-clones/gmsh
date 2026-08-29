// PACK creates one concave quad and one triangle. The terminal validity pass
// splits the bad quad. A different pair of the resulting three triangles
// forms one strictly valid, specification-compliant quadrangle.
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
