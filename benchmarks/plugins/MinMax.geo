// Plugin(MinMax): min and max of tetrahedra, hexahedra and triangles, model
// and list data, scalar, vector, tensor and cell data; over time; with the
// argmin/argmax of each step

Merge "data/cube.msh";
Merge "data/cube.pos";
For v In {0 : 7}
  Plugin(MinMax).View = v;
  Plugin(MinMax).Run;
EndFor
Plugin(MinMax).View = 0;
Plugin(MinMax).OverTime = 1;
Plugin(MinMax).Run;
Plugin(MinMax).OverTime = 0;
Plugin(MinMax).Argument = 1;
Plugin(MinMax).Run;
Plugin(MinMax).View = 4;
Plugin(MinMax).Run;
Plugin(MinMax).Argument = 0;

Merge "data/hexes.pos";
Plugin(MinMax).View = PostProcessing.NbViews - 4;
Plugin(MinMax).Run;
Merge "data/square.pos";
Plugin(MinMax).View = PostProcessing.NbViews - 4;
Plugin(MinMax).Run;
