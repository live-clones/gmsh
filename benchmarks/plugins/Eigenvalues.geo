// Plugin(Eigenvalues): symmetric tensor node data on triangles (model data),
// and on tetrahedra and hexahedra (list data)

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Plugin(Eigenvalues).View = 2;
Plugin(Eigenvalues).Run;
Merge "data/cube.pos";
Plugin(Eigenvalues).View = PostProcessing.NbViews - 2;
Plugin(Eigenvalues).Run;
Merge "data/hexes.pos";
Plugin(Eigenvalues).View = PostProcessing.NbViews - 2;
Plugin(Eigenvalues).Run;
