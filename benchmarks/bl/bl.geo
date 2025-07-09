SetFactory("OpenCASCADE");
l = 8.e-2;
Rectangle(1) = {0,0,0, 1,1};
MeshSize {1, 2, 4} = l;
MeshSize {3} = l/10;

Mesh 2;
Plugin(BoundaryLayer).Surfaces = "1";
Plugin(BoundaryLayer).Curves = "1,2,3";
Plugin(BoundaryLayer).Width = l/10;
Plugin(BoundaryLayer).Run;
