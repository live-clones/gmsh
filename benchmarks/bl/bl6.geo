SetFactory("OpenCASCADE");
l = 0.1;
Box(1) = {0,0,0, 1,1,1};
Mesh 2;
Plugin(BoundaryLayer).Surfaces = "1";
Plugin(BoundaryLayer).Curves = "1";
Plugin(BoundaryLayer).Thickness = l/10;
Plugin(BoundaryLayer).Size = l/100;
Plugin(BoundaryLayer).Run;
