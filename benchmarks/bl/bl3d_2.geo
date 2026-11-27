// Boundary layers on a capsule (a cylinder and a sphere) in a box
Merge "bl3d_2.brep";

Mesh.MeshSizeFactor = 0.1;

Mesh 3;

Plugin(BoundaryLayer).Volumes = {1};
Plugin(BoundaryLayer).Surfaces = {7, 8, 9};
Plugin(BoundaryLayer).Thickness = 1/40;
Plugin(BoundaryLayer).Size = 1/400;
Plugin(BoundaryLayer).Run;
