// Plugin(SphericalRaise): raise along the radius of a sphere of node data on
// triangles (model data: moves the mesh), of node and cell data on triangles
// and tetrahedra (list data), with an offset, one step or another

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Plugin(SphericalRaise).View = 0;
Plugin(SphericalRaise).Xc = 0.5;
Plugin(SphericalRaise).Yc = 0.5;
Plugin(SphericalRaise).Zc = -1;
Plugin(SphericalRaise).Raise = 0.1;
Plugin(SphericalRaise).Run;
Merge "data/square.pos";
Plugin(SphericalRaise).View = 4;
Plugin(SphericalRaise).TimeStep = 2;
Plugin(SphericalRaise).Offset = -1;
Plugin(SphericalRaise).Run;
Plugin(SphericalRaise).View = 7;
Plugin(SphericalRaise).TimeStep = 0;
Plugin(SphericalRaise).Offset = 0.5;
Plugin(SphericalRaise).Raise = -0.2;
Plugin(SphericalRaise).Run;
Merge "data/cube.pos";
Plugin(SphericalRaise).View = PostProcessing.NbViews - 4;
Plugin(SphericalRaise).Xc = 0;
Plugin(SphericalRaise).Yc = 0;
Plugin(SphericalRaise).Zc = 0;
Plugin(SphericalRaise).Offset = 0;
Plugin(SphericalRaise).TimeStep = 1;
Plugin(SphericalRaise).Run;
