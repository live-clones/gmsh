// Plugin(ShowNeighborElements): keep a tetrahedron and the layer of
// tetrahedra around it visible, then delete the invisible elements with
// Plugin(Invisible)
Merge "data/cube.msh";
Plugin(ShowNeighborElements).Element1 = 100;
Plugin(ShowNeighborElements).Run;
Plugin(Invisible).Run;
