// Plugin(Eigenvectors): symmetric tensor node data on triangles (model data),
// and on tetrahedra and hexahedra (list data), scaled or not

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Plugin(Eigenvectors).View = 2;
Plugin(Eigenvectors).Run;
Plugin(Eigenvectors).ScaleByEigenvalues = 0;
Plugin(Eigenvectors).Run;
Plugin(Eigenvectors).ScaleByEigenvalues = 1;
Merge "data/cube.pos";
Plugin(Eigenvectors).View = PostProcessing.NbViews - 2;
Plugin(Eigenvectors).Run;
Merge "data/hexes.pos";
Plugin(Eigenvectors).View = PostProcessing.NbViews - 2;
Plugin(Eigenvectors).Run;
