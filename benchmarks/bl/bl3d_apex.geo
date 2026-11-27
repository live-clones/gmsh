// Boundary layer on one of the four sides of a pyramid: at the apex two curves
// leave the wall, so that no node can slide along a single one of them. The
// layers are pinched there, i.e. they taper to zero thickness.
Point(1) = {0, 0, 0};
Point(2) = {1, 0, 0};
Point(3) = {1, 1, 0};
Point(4) = {0, 1, 0};
Point(5) = {0.5, 0.5, 1};
For i In {1:4}
  Line(i) = {i, i % 4 + 1}; // base
  Line(4 + i) = {i, 5}; // to the apex
EndFor
Curve Loop(1) = {1:4};
Plane Surface(1) = {1};
For i In {1:4}
  Curve Loop(1 + i) = {i, 4 + i % 4 + 1, -(4 + i)};
  Plane Surface(1 + i) = {1 + i};
EndFor
Surface Loop(1) = {1:5};
Volume(1) = {1};

Mesh.MeshSizeMax = 0.1;
Mesh 3;

Plugin(BoundaryLayer).Volumes = {1};
Plugin(BoundaryLayer).Surfaces = {2};
Plugin(BoundaryLayer).Thickness = 0.03;
Plugin(BoundaryLayer).Size = 0.003;
Plugin(BoundaryLayer).Run;
