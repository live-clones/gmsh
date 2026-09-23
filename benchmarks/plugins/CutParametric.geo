// Plugin(CutParametric): a sphere inside tetrahedra and hexahedra as points or
// quadrangles, model and list data, scalar, vector and tensor; a circle as
// lines through triangles

Merge "data/cube.msh";
Merge "data/cube.pos";
Plugin(CutParametric).X = "0.5 + 0.4 * Cos(u) * Sin(v)";
Plugin(CutParametric).Y = "0.5 + 0.4 * Sin(u) * Sin(v)";
Plugin(CutParametric).Z = "0.5 + 0.4 * Cos(v)";
Plugin(CutParametric).MinU = 0;
Plugin(CutParametric).MaxU = 2 * Pi;
Plugin(CutParametric).NumPointsU = 12;
Plugin(CutParametric).MinV = 0;
Plugin(CutParametric).MaxV = Pi;
Plugin(CutParametric).NumPointsV = 7;
For v In {0 : 7}
  Plugin(CutParametric).View = v;
  Plugin(CutParametric).Run;
EndFor
Plugin(CutParametric).View = 0;
Plugin(CutParametric).ConnectPoints = 1;
Plugin(CutParametric).Run;

Merge "data/hexes.pos";
Plugin(CutParametric).View = PostProcessing.NbViews - 4;
Plugin(CutParametric).Run;

Merge "data/square.pos";
Plugin(CutParametric).Z = "0";
Plugin(CutParametric).MaxV = 0;
Plugin(CutParametric).NumPointsV = 1;
Plugin(CutParametric).View = PostProcessing.NbViews - 4;
Plugin(CutParametric).Run;
