// Plugin(Divergence): vector node data on triangles (model data),
// tetrahedra, triangles, quadrangles and hexahedra (list data), 3 time steps

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Plugin(Divergence).View = 1;
Plugin(Divergence).Run;
Merge "data/cube.pos";
Plugin(Divergence).View = PostProcessing.NbViews - 3;
Plugin(Divergence).Run;
Merge "data/square.pos";
Plugin(Divergence).View = PostProcessing.NbViews - 3;
Plugin(Divergence).Run;
Merge "data/quads.pos";
Plugin(Divergence).View = PostProcessing.NbViews - 3;
Plugin(Divergence).Run;
Merge "data/hexes.pos";
Plugin(Divergence).View = PostProcessing.NbViews - 3;
Plugin(Divergence).Run;
