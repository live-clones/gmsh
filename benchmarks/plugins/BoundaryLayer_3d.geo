// Plugin(BoundaryLayer): prism layers on the top of a tetrahedral cube, 3
// smoothing layers, ratio 1.5
l = 0.5;
Point(1) = {0, 0, 0, l}; Point(2) = {1, 0, 0, l};
Point(3) = {1, 1, 0, l}; Point(4) = {0, 1, 0, l};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};
Extrude {0, 0, 1} { Surface{1}; }
Mesh 3;
Plugin(BoundaryLayer).Volumes = "1";
Plugin(BoundaryLayer).Surfaces = "26";
Plugin(BoundaryLayer).Thickness = 0.05;
Plugin(BoundaryLayer).Size = 0.01;
Plugin(BoundaryLayer).Ratio = 1.5;
Plugin(BoundaryLayer).SmoothingLayers = 3;
Plugin(BoundaryLayer).Run;
