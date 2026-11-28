// Second-order boundary layers on half a capsule (a cylinder and a sphere) cut
// by a side of the box around it
Merge "bl3d_3.brep";

Mesh.MeshSizeFactor = 0.1;

Mesh 3;

Plugin(BoundaryLayer).Volumes = {1};
Plugin(BoundaryLayer).Surfaces = {7:10};
Plugin(BoundaryLayer).Thickness = 1/5;
Plugin(BoundaryLayer).Size = 1e-5;
Plugin(BoundaryLayer).Ratio = 2;
Plugin(BoundaryLayer).SmoothingLayers = 4;
Plugin(BoundaryLayer).HighOrder = 2;
Plugin(BoundaryLayer).Run;
