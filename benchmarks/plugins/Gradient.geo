// Plugin(Gradient): scalar and vector node data on tetrahedra and hexahedra,
// as model data and as list data

Merge "data/cube.msh"; // views 0-3: scalar, vector, tensor, cell
Merge "data/cube.pos"; // views 4-7: the same as lists
views() = {0, 1, 4, 5}; // For ... In only takes a range
For i In {0 : #views() - 1}
  Plugin(Gradient).View = views(i);
  Plugin(Gradient).Run;
EndFor

Merge "data/hexes.pos";
Plugin(Gradient).View = PostProcessing.NbViews - 4;
Plugin(Gradient).Run;
