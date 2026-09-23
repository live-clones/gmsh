// Plugin(Invisible): delete the elements of a 3D mesh with no node in a box,
// then reverse (and keep) those with a node in a smaller box (Inside)
Merge "data/cube.msh";
Plugin(Invisible).XMin = 0; Plugin(Invisible).XMax = 0.6;
Plugin(Invisible).YMin = 0; Plugin(Invisible).YMax = 1;
Plugin(Invisible).ZMin = 0; Plugin(Invisible).ZMax = 1;
Plugin(Invisible).Run;
Plugin(Invisible).XMax = 0.2;
Plugin(Invisible).Inside = 1;
Plugin(Invisible).DeleteElements = 0;
Plugin(Invisible).ReverseElements = 1;
Plugin(Invisible).Run;
