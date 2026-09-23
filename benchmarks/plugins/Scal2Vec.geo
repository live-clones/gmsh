// Plugin(Scal2Vec): vectors from scalar node and cell data, model and list,
// with missing components, 3 steps or 1, on triangles (model) and hexahedra (list)

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Plugin(Scal2Vec).ViewX = 0;
Plugin(Scal2Vec).ViewZ = 0;
Plugin(Scal2Vec).NameNewView = "zero y";
Plugin(Scal2Vec).Run;
Plugin(Scal2Vec).ViewX = -1;
Plugin(Scal2Vec).ViewY = 3;
Plugin(Scal2Vec).ViewZ = -1;
Plugin(Scal2Vec).NameNewView = "cell y";
Plugin(Scal2Vec).Run;
Merge "data/hexes.pos";
Plugin(Scal2Vec).ViewX = PostProcessing.NbViews - 4;
Plugin(Scal2Vec).ViewY = -1;
Plugin(Scal2Vec).ViewZ = PostProcessing.NbViews - 4;
Plugin(Scal2Vec).NameNewView = "list";
Plugin(Scal2Vec).Run;
