// Boundary layers on part of the boundary of the union of three rectangles
//+
SetFactory("OpenCASCADE");
Rectangle(1) = {-1, -0.2, 0, 1, 0.5, 0};
//+
Rectangle(2) = {-0.5, 0.1, 0, 1, 0.5, 0};
//+
Rectangle(3) = {0.2, 0.4, 0, 1, 0.5, 0};
//+
BooleanUnion{ Surface{1}; Delete; }{ Surface{2}; Surface{3}; Delete; }
//+
MeshSize {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21} = 0.05;

Mesh 2;

Plugin(BoundaryLayer).Surfaces = {1};
Plugin(BoundaryLayer).Curves = {13:19};
Plugin(BoundaryLayer).Thickness = 0.05;
Plugin(BoundaryLayer).Size = 0.01;
Plugin(BoundaryLayer).Ratio = 1.1;
Plugin(BoundaryLayer).Run;
