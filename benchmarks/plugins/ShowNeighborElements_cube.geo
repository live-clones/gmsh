// Plugin(ShowNeighborElements): keep a tetrahedron and its face neighbors
// visible, then delete the invisible elements with Plugin(Invisible)
Merge "data/cube.msh";
Plugin(ShowNeighborElements).Element1 = 100;
Plugin(ShowNeighborElements).Run;
Plugin(Invisible).Run;
