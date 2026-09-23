// Plugin(Particles): trajectories in a vector force field in tetrahedra,
// hexahedra and triangles, model and list data, with and without damping
// and stiffness, at a given step

Merge "data/cube.msh";
Merge "data/cube.pos";
Plugin(Particles).X0 = 0.6; Plugin(Particles).Y0 = 0.5; Plugin(Particles).Z0 = 0.1;
Plugin(Particles).X1 = 0.9; Plugin(Particles).Y1 = 0.5; Plugin(Particles).Z1 = 0.1;
Plugin(Particles).X2 = 0.6; Plugin(Particles).Y2 = 0.5; Plugin(Particles).Z2 = 0.5;
Plugin(Particles).NumPointsU = 4;
Plugin(Particles).NumPointsV = 1;
Plugin(Particles).DT = 0.1;
Plugin(Particles).MaxIter = 20;
views() = {1, 5};
For i In {0 : #views() - 1}
  Plugin(Particles).View = views(i);
  Plugin(Particles).Run;
EndFor
Plugin(Particles).View = 1;
Plugin(Particles).A1 = 2;
Plugin(Particles).A0 = 1;
Plugin(Particles).NumPointsV = 3;
Plugin(Particles).TimeStep = 2;
Plugin(Particles).Run;
Plugin(Particles).A1 = 0;
Plugin(Particles).A0 = 0;
Plugin(Particles).NumPointsV = 1;
Plugin(Particles).TimeStep = 0;

Merge "data/hexes.pos";
Plugin(Particles).View = PostProcessing.NbViews - 3;
Plugin(Particles).Run;

Merge "data/square.pos";
Plugin(Particles).Z0 = 0; Plugin(Particles).Z1 = 0; Plugin(Particles).Z2 = 0;
Plugin(Particles).View = PostProcessing.NbViews - 3;
Plugin(Particles).Run;
