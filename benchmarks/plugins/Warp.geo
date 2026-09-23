// Plugin(Warp): scalar node data warped by vector node data on triangles
// (model data: moves the mesh) and on triangles and hexahedra (list data),
// and cell data on quadrangles along smoothed normals

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Plugin(Warp).View = 0;
Plugin(Warp).OtherView = 1;
Plugin(Warp).TimeStep = 2;
Plugin(Warp).Factor = 0.1;
Plugin(Warp).Run;
Merge "data/square.pos";
Plugin(Warp).View = 4;
Plugin(Warp).OtherView = 5;
Plugin(Warp).TimeStep = 1;
Plugin(Warp).Run;
Merge "data/hexes.pos";
Plugin(Warp).View = PostProcessing.NbViews - 4;
Plugin(Warp).OtherView = PostProcessing.NbViews - 3;
Plugin(Warp).Factor = -0.2;
Plugin(Warp).Run;
Merge "data/quads.pos";
Plugin(Warp).View = -1; // the current view: cell data on quadrangles
Plugin(Warp).OtherView = -1; // normals times the cell values
Plugin(Warp).TimeStep = 0;
Plugin(Warp).SmoothingAngle = 30;
Plugin(Warp).Run;
