// Boundary layers on both sides of a curve separating two surfaces: the curve
// ends on the boundary, where each side gets its own node sliding along it.
SetFactory("OpenCASCADE");

Rectangle(1) = {0, 0, 0, 1, 1};
Point(5) = {0.5, 0, 0};
Point(6) = {0.5, 1, 0};
Line(5) = {5, 6};
BooleanFragments{ Surface{1}; Delete; }{ Curve{5}; Delete; }

eps = 1e-6;
walls() = Curve In BoundingBox {0.5 - eps, -eps, -eps, 0.5 + eps, 1 + eps, eps};

Mesh.MeshSizeMax = 0.05;
Mesh 2;

Plugin(BoundaryLayer).Surfaces = {Surface{:}};
Plugin(BoundaryLayer).Curves = {walls()};
Plugin(BoundaryLayer).Thickness = 0.03;
Plugin(BoundaryLayer).Size = 0.003;
Plugin(BoundaryLayer).Run;
