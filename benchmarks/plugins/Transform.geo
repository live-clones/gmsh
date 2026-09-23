// Plugin(Transform): affine maps of node data on triangles (model data: moves
// the mesh) and of scalar, vector and cell data on triangles and hexahedra
// (list data), with SwapOrientation (model data)

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Plugin(Transform).A11 = 0;
Plugin(Transform).A12 = -1;
Plugin(Transform).A21 = 1;
Plugin(Transform).A22 = 0;
Plugin(Transform).Tx = 2;
Plugin(Transform).Tz = 0.5;
Plugin(Transform).View = 0;
Plugin(Transform).SwapOrientation = 1;
Plugin(Transform).Run; // rotation + translation, 3 steps
Plugin(Transform).SwapOrientation = 0;
Merge "data/square.pos";
Plugin(Transform).View = 5;
Plugin(Transform).Run;
Plugin(Transform).A11 = 2;
Plugin(Transform).A12 = 0.5;
Plugin(Transform).A21 = 0;
Plugin(Transform).A22 = 1;
Plugin(Transform).A33 = 3;
Plugin(Transform).Tx = 0;
Plugin(Transform).Ty = -1;
Plugin(Transform).Tz = 0;
Plugin(Transform).View = 7;
Plugin(Transform).Run; // cell data
Merge "data/hexes.pos";
Plugin(Transform).View = PostProcessing.NbViews - 4;
Plugin(Transform).Run;
Plugin(Transform).A11 = -1;
Plugin(Transform).A12 = 0;
Plugin(Transform).A33 = 1;
Plugin(Transform).Ty = 0;
Plugin(Transform).View = PostProcessing.NbViews - 3;
Plugin(Transform).Run; // mirror

// element data on a mesh: each node moved once (they were moved once per
// element around them); the orientation of list data swapped
NewModel;
Merge "data/square.msh";
Plugin(Transform).View = PostProcessing.NbViews - 1;
Plugin(Transform).A11 = 1; Plugin(Transform).A12 = 0; Plugin(Transform).A13 = 0;
Plugin(Transform).A21 = 0; Plugin(Transform).A22 = 1; Plugin(Transform).A23 = 0;
Plugin(Transform).A31 = 0; Plugin(Transform).A32 = 0; Plugin(Transform).A33 = 1;
Plugin(Transform).Tx = 1; Plugin(Transform).Ty = 0; Plugin(Transform).Tz = 0;
Plugin(Transform).SwapOrientation = 0;
Plugin(Transform).Run;
Merge "data/square.pos";
Plugin(Transform).View = PostProcessing.NbViews - 4;
Plugin(Transform).Tx = 0;
Plugin(Transform).SwapOrientation = 1;
Plugin(Transform).Run;
