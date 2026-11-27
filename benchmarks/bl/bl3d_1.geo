// Boundary layers on five of the six sides of a box
SetFactory("OpenCASCADE");
Box(1) = {0, 0, 0, 1, 1, 1};

Mesh 3;

Plugin(BoundaryLayer).Volumes = {1};
Plugin(BoundaryLayer).Surfaces = {1, 2, 3, 5, 6};
Plugin(BoundaryLayer).Thickness = 1/40;
Plugin(BoundaryLayer).Size = 1/400;
Plugin(BoundaryLayer).Run;
