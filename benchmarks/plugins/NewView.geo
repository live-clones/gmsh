// Plugin(NewView): node and element data with one or several components,
// on a physical group, with a given tag, on a triangle mesh

Merge "data/square.msh";
Plugin(NewView).Value = 2;
Plugin(NewView).Run;
Plugin(NewView).NumComp = 3;
Plugin(NewView).Value = -1.5;
Plugin(NewView).ViewTag = 100;
Plugin(NewView).Run;
Plugin(NewView).ViewTag = -1;
Plugin(NewView).Type = "ElementData";
Plugin(NewView).NumComp = 9;
Plugin(NewView).Value = 0.5;
Plugin(NewView).Run;
Plugin(NewView).NumComp = 1;
Plugin(NewView).PhysicalGroup = 3;
Plugin(NewView).Run;
Plugin(NewView).PhysicalGroup = 1;
Plugin(NewView).Run;
