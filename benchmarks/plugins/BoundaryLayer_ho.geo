// Plugin(BoundaryLayer): second-order layers along the bottom of a square
lc = 0.1;
Point(1) = {0, 0, 0, lc}; Point(2) = {1, 0, 0, lc};
Point(3) = {1, 1, 0, lc}; Point(4) = {0, 1, 0, lc};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};
Mesh 2;
Plugin(BoundaryLayer).Surfaces = "1";
Plugin(BoundaryLayer).Curves = "1";
Plugin(BoundaryLayer).Thickness = 0.05;
Plugin(BoundaryLayer).Size = 0.005;
Plugin(BoundaryLayer).HighOrder = 2;
Plugin(BoundaryLayer).Run;
