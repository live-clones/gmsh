// Boundary layers on both sides of a surface embedded in a volume: along the
// rim of the surface the layers are pinched, i.e. they taper to zero thickness
// and end with pyramids and tetrahedra.
SetFactory("OpenCASCADE");

Box(1) = {0, 0, 0, 1, 1, 1};
Rectangle(7) = {0.3, 0.3, 0.5, 0.4, 0.4};
Surface{7} In Volume{1};

Mesh.MeshSizeMax = 0.08;
Mesh 3;

Plugin(BoundaryLayer).Volumes = {1};
Plugin(BoundaryLayer).Surfaces = {7};
Plugin(BoundaryLayer).Thickness = 1 / 40;
Plugin(BoundaryLayer).Size = 1 / 400;
Plugin(BoundaryLayer).Run;
