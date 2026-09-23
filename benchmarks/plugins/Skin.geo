// Plugin(Skin): the boundary of views on tetrahedra, hexahedra, triangles and
// quadrangles, model and list data, scalar, vector, tensor and cell data;
// the skin of the mesh itself (FromMesh)

Merge "data/cube.msh";
Merge "data/cube.pos";
For v In {0 : 7}
  Plugin(Skin).View = v;
  Plugin(Skin).Run;
EndFor
Merge "data/hexes.pos";
Plugin(Skin).View = PostProcessing.NbViews - 4;
Plugin(Skin).Run;
Merge "data/quads.pos";
Plugin(Skin).View = PostProcessing.NbViews - 4;
Plugin(Skin).Run;
Merge "data/square.pos";
Plugin(Skin).View = PostProcessing.NbViews - 3;
Plugin(Skin).Run;
