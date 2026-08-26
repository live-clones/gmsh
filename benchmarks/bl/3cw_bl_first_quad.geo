Include "3cw.geo";

Mesh.MeshSizeFactor = 0.5;
Mesh.MeshSizeFromCurvature = 20;
Mesh.MeshSizeExtendFromBoundary = 0;
Mesh.NumSubEdges = 10;
Mesh 2;

Plugin(BoundaryLayer).Surfaces = "16";
Plugin(BoundaryLayer).Curves = "1,2,3,4,5,6,7";
Plugin(BoundaryLayer).Thickness = 40;
Plugin(BoundaryLayer).Size = 40;
Plugin(BoundaryLayer).Ratio = 1.5;
Plugin(BoundaryLayer).SmoothingLayers = 5;
Plugin(BoundaryLayer).HighOrder = 1;
Plugin(BoundaryLayer).Run;

Save "/tmp/3cw_bl_first_quad.msh";
