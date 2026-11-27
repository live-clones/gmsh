// Boundary layers on both sides of a surface separating two volumes: the
// surface ends on the boundary, where each side gets its own nodes sliding
// along it.
SetFactory("OpenCASCADE");

Box(1) = {0, 0, 0, 1, 1, 0.5};
Box(2) = {0, 0, 0.5, 1, 1, 0.5};
BooleanFragments{ Volume{1}; Delete; }{ Volume{2}; Delete; }

eps = 1e-6;
walls() = Surface In BoundingBox {-eps, -eps, 0.5 - eps, 1 + eps, 1 + eps, 0.5 + eps};

Mesh.MeshSizeMax = 0.1;
Mesh 3;

Plugin(BoundaryLayer).Volumes = {Volume{:}};
Plugin(BoundaryLayer).Surfaces = {walls()};
Plugin(BoundaryLayer).Thickness = 0.05;
Plugin(BoundaryLayer).Size = 0.005;
Plugin(BoundaryLayer).Run;
