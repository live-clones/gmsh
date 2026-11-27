// Boundary layers on both sides of a gap thinner than twice their thickness: a
// channel of height 0.3 with a step that leaves a gap g to the bottom wall. The
// layers are reduced to a third of the gap each, with the first layer kept at
// its requested height.
SetFactory("OpenCASCADE");

g = 0.03; // gap
t = 0.02; // thickness of the layers

Point(1) = {0, 0, 0};
Point(2) = {1, 0, 0};
Point(3) = {1, 0.3, 0};
Point(4) = {0.7, 0.3, 0};
Point(5) = {0.7, g, 0};
Point(6) = {0.3, g, 0};
Point(7) = {0.3, 0.3, 0};
Point(8) = {0, 0.3, 0};
For i In {1:8}
  Line(i) = {i, i % 8 + 1};
EndFor
Curve Loop(1) = {1:8};
Plane Surface(1) = {1};
MeshSize{:} = 0.02;

Mesh 2;

// walls: the bottom and the three sides of the step
Plugin(BoundaryLayer).Surfaces = {1};
Plugin(BoundaryLayer).Curves = {1, 4, 5, 6};
Plugin(BoundaryLayer).Thickness = t;
Plugin(BoundaryLayer).Size = t / 20;
Plugin(BoundaryLayer).Ratio = 1.3;
Plugin(BoundaryLayer).SmoothingLayers = 6;
Plugin(BoundaryLayer).Run;
