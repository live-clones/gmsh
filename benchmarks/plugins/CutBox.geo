// Plugin(CutBox): an oblique box inside tetrahedra and hexahedra, model and
// list data, scalar, vector and tensor; volume (hexahedra) or boundary
// (quadrangles), points only, a flat box (its boundary: lines)

Merge "data/cube.msh";
Merge "data/cube.pos";
Plugin(CutBox).X0 = 0.1; Plugin(CutBox).Y0 = 0.2; Plugin(CutBox).Z0 = 0.1;
Plugin(CutBox).X1 = 0.8; Plugin(CutBox).Y1 = 0.3; Plugin(CutBox).Z1 = 0.1;
Plugin(CutBox).X2 = 0.2; Plugin(CutBox).Y2 = 0.9; Plugin(CutBox).Z2 = 0.2;
Plugin(CutBox).X3 = 0.1; Plugin(CutBox).Y3 = 0.2; Plugin(CutBox).Z3 = 0.7;
Plugin(CutBox).NumPointsU = 5;
Plugin(CutBox).NumPointsV = 4;
Plugin(CutBox).NumPointsW = 3;
For v In {0 : 7}
  Plugin(CutBox).View = v;
  Plugin(CutBox).Run;
EndFor
Plugin(CutBox).View = 0;
Plugin(CutBox).Boundary = 0;
Plugin(CutBox).Run;
Plugin(CutBox).ConnectPoints = 0;
Plugin(CutBox).Run;
Plugin(CutBox).ConnectPoints = 1;
Plugin(CutBox).Boundary = 1;
Plugin(CutBox).NumPointsW = 1;
Plugin(CutBox).Run;
Plugin(CutBox).NumPointsW = 3;

Merge "data/hexes.pos";
Plugin(CutBox).View = PostProcessing.NbViews - 4;
Plugin(CutBox).Run;

// the boundary of a box one point thick along U (it read past the end of the
// values along W)
Plugin(CutBox).View = 0;
Plugin(CutBox).NumPointsU = 1;
Plugin(CutBox).NumPointsV = 4;
Plugin(CutBox).NumPointsW = 3;
Plugin(CutBox).ConnectPoints = 1;
Plugin(CutBox).Boundary = 1;
Plugin(CutBox).Run;
