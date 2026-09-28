// Plugin(StreamLines): stream lines of a rotating vector field in tetrahedra
// and hexahedra, model and list data, from a line and a grid of seeds, at a
// given step, carrying another scalar view, and unsteady

Merge "data/cube.msh";
Merge "data/cube.pos";
Plugin(StreamLines).X0 = 0.6; Plugin(StreamLines).Y0 = 0.5; Plugin(StreamLines).Z0 = 0.1;
Plugin(StreamLines).X1 = 0.9; Plugin(StreamLines).Y1 = 0.5; Plugin(StreamLines).Z1 = 0.1;
Plugin(StreamLines).X2 = 0.6; Plugin(StreamLines).Y2 = 0.5; Plugin(StreamLines).Z2 = 0.5;
Plugin(StreamLines).NumPointsU = 4;
Plugin(StreamLines).NumPointsV = 1;
Plugin(StreamLines).DT = 0.1;
Plugin(StreamLines).MaxIter = 30;
views() = {1, 5};
For i In {0 : #views() - 1}
  Plugin(StreamLines).View = views(i);
  Plugin(StreamLines).Run;
EndFor
Plugin(StreamLines).View = 1;
Plugin(StreamLines).NumPointsV = 3;
Plugin(StreamLines).TimeStep = 2;
Plugin(StreamLines).Run;
Plugin(StreamLines).NumPointsV = 1;
Plugin(StreamLines).TimeStep = 0;
Plugin(StreamLines).OtherView = 0;
Plugin(StreamLines).Run;
Plugin(StreamLines).OtherView = -1;
Plugin(StreamLines).TimeStep = -1;
Plugin(StreamLines).Run;
Plugin(StreamLines).TimeStep = 0;

Merge "data/hexes.pos";
Plugin(StreamLines).View = PostProcessing.NbViews - 3;
Plugin(StreamLines).Run;
