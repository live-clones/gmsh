// Plugin(CutGrid): an oblique grid through tetrahedra and hexahedra, model
// and list data, scalar, vector and tensor; quadrangles, points, a line of
// points; a grid in the plane of triangles

Merge "data/cube.msh";
Merge "data/cube.pos";
Plugin(CutGrid).X0 = 0.1; Plugin(CutGrid).Y0 = 0.1; Plugin(CutGrid).Z0 = 0.2;
Plugin(CutGrid).X1 = 0.9; Plugin(CutGrid).Y1 = 0.2; Plugin(CutGrid).Z1 = 0.4;
Plugin(CutGrid).X2 = 0.2; Plugin(CutGrid).Y2 = 0.9; Plugin(CutGrid).Z2 = 0.7;
Plugin(CutGrid).NumPointsU = 6;
Plugin(CutGrid).NumPointsV = 5;
For v In {0 : 7}
  Plugin(CutGrid).View = v;
  Plugin(CutGrid).Run;
EndFor
Plugin(CutGrid).View = 0;
Plugin(CutGrid).ConnectPoints = 0;
Plugin(CutGrid).Run;
Plugin(CutGrid).ConnectPoints = 1;
Plugin(CutGrid).NumPointsV = 1;
Plugin(CutGrid).Run;
Plugin(CutGrid).NumPointsV = 5;

Merge "data/hexes.pos";
Plugin(CutGrid).View = PostProcessing.NbViews - 4;
Plugin(CutGrid).Run;

Merge "data/quads.pos";
Plugin(CutGrid).Z0 = 0; Plugin(CutGrid).Z1 = 0; Plugin(CutGrid).Z2 = 0;
Plugin(CutGrid).View = PostProcessing.NbViews - 4;
Plugin(CutGrid).Run;
