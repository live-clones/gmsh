// Boundary layers on a blade and on the casing above it, with a tip gap thinner
// than twice their thickness: the layers are reduced to a third of the gap
// each, with the first layer kept at its requested height.
SetFactory("OpenCASCADE");

g = 0.03; // tip gap
t = 0.02; // thickness of the layers

Box(1) = {0, 0, 0, 1, 1, 1};
Box(2) = {0.3, 0.4, 0, 0.4, 0.2, 1 - g};
BooleanDifference{ Volume{1}; Delete; }{ Volume{2}; Delete; }

// walls: the sides and the tip of the blade (not its foot, which is a hole in
// the bottom of the box), and the casing (z = 1)
eps = 1e-6;
blade() = Surface In BoundingBox {0.3 - eps, 0.4 - eps, -eps,
                                  0.7 + eps, 0.6 + eps, 1 - g + eps};
casing() = Surface In BoundingBox {-eps, -eps, 1 - eps, 1 + eps, 1 + eps, 1 + eps};

Mesh.MeshSizeMax = 0.05;
Mesh 3;

Plugin(BoundaryLayer).Volumes = {1};
Plugin(BoundaryLayer).Surfaces = {blade(), casing()};
Plugin(BoundaryLayer).Thickness = t;
Plugin(BoundaryLayer).Size = t / 20;
Plugin(BoundaryLayer).Ratio = 1.3;
Plugin(BoundaryLayer).SmoothingLayers = 4;
Plugin(BoundaryLayer).Run;
