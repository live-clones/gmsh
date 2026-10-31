// An STL triangulation in the discrete CAD modeler: its surfaces are split
// where the normals of its triangles turn by more than 40 degrees, its curves
// are along these edges, and its volume is the space they bound. It is then
// drilled by a boolean difference.

SetFactory("Discrete");

v() = ShapeFromFile("../../tutorials/t13_data.stl", 40 * Pi / 180);
Cylinder(100) = {35, -50, -176, 0, 100, 0, 5};
BooleanDifference{ Volume{v(0)}; Delete; }{ Volume{100}; Delete; }

Mesh.MeshSizeMax = 3;
