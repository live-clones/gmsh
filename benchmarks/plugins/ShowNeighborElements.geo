// Plugin(ShowNeighborElements): keep two triangles and 2 layers of elements
// around them visible, then delete the invisible elements with
// Plugin(Invisible)
Merge "data/square.msh";
Plugin(ShowNeighborElements).NumLayers = 2;
Plugin(ShowNeighborElements).Element1 = 40;
Plugin(ShowNeighborElements).Element2 = 70;
Plugin(ShowNeighborElements).Run;
Plugin(Invisible).Run;
