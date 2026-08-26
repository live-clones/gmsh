SetFactory("Built-in");

lc = 0.12;

Point(1) = {0, 0, 0, lc};
Point(2) = {1, 0, 0, lc};
Point(3) = {1, 1, 0, lc};
Point(4) = {0, 1, 0, lc};

Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};

Curve Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};

Mesh.Algorithm = 6;
Mesh.MeshSizeExtendFromBoundary = 1;

Mesh 2;

Plugin(BoundaryLayer).Surfaces = "1";
Plugin(BoundaryLayer).Curves = "1,2,3,4";
Plugin(BoundaryLayer).IntersectPoints = "1,2,3,4";
Plugin(BoundaryLayer).Thickness = 0.22;
Plugin(BoundaryLayer).Size = 0.004;
Plugin(BoundaryLayer).Ratio = 1.25;
Plugin(BoundaryLayer).SmoothingLayers = 8;
Plugin(BoundaryLayer).SurfaceUntangler = 1;
Plugin(BoundaryLayer).HighOrder = 1;
Plugin(BoundaryLayer).Run;

Save "bl_square_intersect_points.msh";
