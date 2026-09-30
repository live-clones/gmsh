// Plugin(Smooth): average nodal values of cell data (model data becomes node
// data), node data left as is, on triangles, quadrangles, tetrahedra and
// hexahedra, model and list data

Merge "data/square.msh"; // views 0-3
Merge "data/square.pos"; // views 4-7
views() = {3, 7, 0, 5};
For i In {0 : #views() - 1}
  Plugin(Smooth).View = views(i);
  Plugin(Smooth).Run;
EndFor

Merge "data/quads.pos"; // views 8-11
Plugin(Smooth).View = 11;
Plugin(Smooth).Run;

Merge "data/cube.pos"; // views 12-15
Plugin(Smooth).View = 15;
Plugin(Smooth).Run;
Plugin(Smooth).View = 14; // tensor
Plugin(Smooth).Run;

Merge "data/hexes.pos"; // views 16-19
Plugin(Smooth).View = 19;
Plugin(Smooth).Run;
