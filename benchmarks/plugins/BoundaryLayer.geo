// Plugin(BoundaryLayer): quadrangle layers along three sides of a square
// meshed with triangles, finer at one corner
l = 0.1;
Point(1) = {0, 0, 0, l}; Point(2) = {1, 0, 0, l};
Point(3) = {1, 1, 0, l / 5}; Point(4) = {0, 1, 0, l};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};
Mesh 2;
Plugin(BoundaryLayer).Surfaces = "1";
Plugin(BoundaryLayer).Curves = "1, 2, 3";
Plugin(BoundaryLayer).Thickness = 0.02;
Plugin(BoundaryLayer).Size = 0.002;
Plugin(BoundaryLayer).Run;
