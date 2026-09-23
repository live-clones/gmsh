// Plugin(Curl): vector node data on tetrahedra (model data),
// triangles, quadrangles and hexahedra (list data), 3 time steps

Merge "data/cube.msh"; // views 0-3: scalar, vector, tensor, cell
Plugin(Curl).View = 1;
Plugin(Curl).Run;
Merge "data/cube.pos";
Plugin(Curl).View = PostProcessing.NbViews - 3;
Plugin(Curl).Run;
Merge "data/square.pos";
Plugin(Curl).View = PostProcessing.NbViews - 3;
Plugin(Curl).Run;
Merge "data/quads.pos";
Plugin(Curl).View = PostProcessing.NbViews - 3;
Plugin(Curl).Run;
Merge "data/hexes.pos";
Plugin(Curl).View = PostProcessing.NbViews - 3;
Plugin(Curl).Run;
