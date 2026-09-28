// Plugin(Probe): a point inside tetrahedra, hexahedra, triangles and
// quadrangles, model and list data, scalar, vector, tensor and cell data

Merge "data/cube.msh";
Merge "data/cube.pos";
Plugin(Probe).X = 0.31;
Plugin(Probe).Y = 0.62;
Plugin(Probe).Z = 0.43;
For v In {0 : 7}
  Plugin(Probe).View = v;
  Plugin(Probe).Run;
EndFor
Merge "data/hexes.pos";
Plugin(Probe).View = PostProcessing.NbViews - 4;
Plugin(Probe).Run;
Merge "data/square.pos";
Plugin(Probe).Z = 0;
Plugin(Probe).View = PostProcessing.NbViews - 4;
Plugin(Probe).Run;
Merge "data/quads.pos";
Plugin(Probe).View = PostProcessing.NbViews - 3;
Plugin(Probe).Run;
