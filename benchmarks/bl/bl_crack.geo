// Boundary layers on both sides of a curve embedded in a surface: at the two
// ends of the curve the layers are pinched, i.e. they taper to zero thickness
// and end with triangles.
SetFactory("OpenCASCADE");

Rectangle(1) = {0, 0, 0, 1, 1};
Point(5) = {0.3, 0.5, 0};
Point(6) = {0.7, 0.5, 0};
Line(5) = {5, 6};
Curve{5} In Surface{1};

Mesh.MeshSizeMax = 0.05;
Mesh 2;

Plugin(BoundaryLayer).Surfaces = {1};
Plugin(BoundaryLayer).Curves = {5};
Plugin(BoundaryLayer).Thickness = 0.03;
Plugin(BoundaryLayer).Size = 0.003;
Plugin(BoundaryLayer).Run;
