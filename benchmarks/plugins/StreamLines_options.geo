// Plugin(StreamLines): adaptive steps, backward and both ways, and stop at low
// speed, on the rotating vector field in tetrahedra, model and list data

Merge "data/cube.msh";
Merge "data/cube.pos";
Plugin(StreamLines).X0 = 0.6; Plugin(StreamLines).Y0 = 0.5; Plugin(StreamLines).Z0 = 0.3;
Plugin(StreamLines).X1 = 0.9; Plugin(StreamLines).Y1 = 0.5; Plugin(StreamLines).Z1 = 0.3;
Plugin(StreamLines).X2 = 0.6; Plugin(StreamLines).Y2 = 0.5; Plugin(StreamLines).Z2 = 0.7;
Plugin(StreamLines).NumPointsU = 4;
Plugin(StreamLines).NumPointsV = 2;
Plugin(StreamLines).DT = 0.2;
Plugin(StreamLines).MaxIter = 20;
Plugin(StreamLines).TimeStep = 0;
views() = {1, 5};
For i In {0 : #views() - 1}
  Plugin(StreamLines).View = views(i);
  Plugin(StreamLines).Tolerance = 1e-6;
  Plugin(StreamLines).Run;
  Plugin(StreamLines).Tolerance = 0;
  Plugin(StreamLines).Direction = -1;
  Plugin(StreamLines).Run;
  Plugin(StreamLines).OtherView = 0;
  Plugin(StreamLines).Direction = 0;
  Plugin(StreamLines).Tolerance = 1e-6;
  Plugin(StreamLines).Run;
  Plugin(StreamLines).Tolerance = 0;
  Plugin(StreamLines).Direction = 1;
  Plugin(StreamLines).OtherView = -1;
  Plugin(StreamLines).MinSpeed = 0.25;
  Plugin(StreamLines).Run;
  Plugin(StreamLines).MinSpeed = 0;
EndFor
