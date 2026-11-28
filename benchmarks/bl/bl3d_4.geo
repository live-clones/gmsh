// Boundary layers on a box-shaped notch in a box
Merge "bl3d_4.brep";

Mesh.MeshSizeFactor = 0.4;

Mesh 3;

Plugin(BoundaryLayer).Volumes = {1};
Plugin(BoundaryLayer).Surfaces = {7:11};
Plugin(BoundaryLayer).Thickness = 1/40;
Plugin(BoundaryLayer).Size = 1/40000;
Plugin(BoundaryLayer).Ratio = 1.4;
Plugin(BoundaryLayer).Run;
