// Boundary layers on half a capsule and on a hole bounded by splines, in a box
Merge "bl3d_5.brep";

Mesh.MeshSizeFactor = 0.15;

Mesh 3;

Plugin(BoundaryLayer).Volumes = {1};
Plugin(BoundaryLayer).Surfaces = {7:13};
Plugin(BoundaryLayer).Thickness = 1/160;
Plugin(BoundaryLayer).Size = 1/1600;
Plugin(BoundaryLayer).Run;
