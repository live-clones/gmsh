// Plugin(Lambda2): the three eigenvalues from velocity gradient tensors on
// triangles, tetrahedra and hexahedra, and from velocities on
// triangles and tetrahedra, list data only

Merge "data/square.pos"; // views 0-3: scalar, vector, tensor, cell
Plugin(Lambda2).View = 2;
Plugin(Lambda2).Run;
Plugin(Lambda2).View = 1;
Plugin(Lambda2).Run;
Merge "data/cube.pos";
Plugin(Lambda2).View = PostProcessing.NbViews - 2;
Plugin(Lambda2).Eigenvalue = 1;
Plugin(Lambda2).Run;
Plugin(Lambda2).View = PostProcessing.NbViews - 4;
Plugin(Lambda2).Eigenvalue = 3;
Plugin(Lambda2).Run;
Plugin(Lambda2).Eigenvalue = 2;
Merge "data/hexes.pos";
Plugin(Lambda2).View = PostProcessing.NbViews - 2;
Plugin(Lambda2).Run;
