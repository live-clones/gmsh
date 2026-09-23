// Plugin(CutSphere): a sphere through tetrahedra and hexahedra, model and list
// data, scalar, vector and tensor; ExtractVolume inside and outside; a circle
// through triangles

Merge "data/cube.msh";
Merge "data/cube.pos";
Plugin(CutSphere).Xc = 0.2;
Plugin(CutSphere).Yc = 0.3;
Plugin(CutSphere).Zc = 0.4;
Plugin(CutSphere).R = 0.6;
For v In {0 : 7}
  Plugin(CutSphere).View = v;
  Plugin(CutSphere).Run;
EndFor
Plugin(CutSphere).View = 0;
Plugin(CutSphere).ExtractVolume = 1;
Plugin(CutSphere).Run;
Plugin(CutSphere).ExtractVolume = -1;
Plugin(CutSphere).Run;
Plugin(CutSphere).ExtractVolume = 0;

Merge "data/hexes.pos";
Plugin(CutSphere).View = PostProcessing.NbViews - 4;
Plugin(CutSphere).Run;

Merge "data/square.pos";
Plugin(CutSphere).View = PostProcessing.NbViews - 4;
Plugin(CutSphere).Run;
