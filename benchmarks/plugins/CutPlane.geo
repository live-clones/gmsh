// Plugin(CutPlane): a plane through tetrahedra and hexahedra, model and list
// data, scalar, vector and tensor; ExtractVolume on both sides

Merge "data/cube.msh";
Merge "data/cube.pos";
Plugin(CutPlane).A = 1;
Plugin(CutPlane).B = 0.3;
Plugin(CutPlane).C = 0.2;
Plugin(CutPlane).D = -0.7;
For v In {0 : 7}
  Plugin(CutPlane).View = v;
  Plugin(CutPlane).Run;
EndFor
Plugin(CutPlane).View = 0;
Plugin(CutPlane).ExtractVolume = 1;
Plugin(CutPlane).Run;
Plugin(CutPlane).ExtractVolume = -1;
Plugin(CutPlane).Run;
Plugin(CutPlane).ExtractVolume = 0;

NewModel; // a second mesh in the same model would mix with the first
Merge "data/hexes.msh";
Plugin(CutPlane).View = PostProcessing.NbViews - 4;
Plugin(CutPlane).Run;
