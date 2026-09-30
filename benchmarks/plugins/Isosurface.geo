// Plugin(Isosurface): isosurfaces of tetrahedra and hexahedra, model and list
// data, 3 steps; another view (vector, tensor, fixed step) drawn on it;
// isovolumes on both sides; isolines of triangles and quadrangles

Merge "data/cube.msh";
Merge "data/cube.pos";
Plugin(Isosurface).Value = 1.2;
views() = {0, 4};
For i In {0 : #views() - 1}
  Plugin(Isosurface).View = views(i);
  Plugin(Isosurface).Run;
EndFor
Plugin(Isosurface).View = 0;
Plugin(Isosurface).OtherView = 1;
Plugin(Isosurface).Run;
Plugin(Isosurface).OtherTimeStep = 2;
Plugin(Isosurface).Run;
Plugin(Isosurface).OtherView = 2;
Plugin(Isosurface).OtherTimeStep = 0;
Plugin(Isosurface).Run;
Plugin(Isosurface).OtherView = -1;
Plugin(Isosurface).OtherTimeStep = -1;
Plugin(Isosurface).ExtractVolume = 1;
Plugin(Isosurface).Run;
Plugin(Isosurface).ExtractVolume = -1;
Plugin(Isosurface).View = 4;
Plugin(Isosurface).Run;
Plugin(Isosurface).ExtractVolume = 0;

Merge "data/hexes.pos";
Plugin(Isosurface).View = PostProcessing.NbViews - 4;
Plugin(Isosurface).Run;

Merge "data/square.pos";
Plugin(Isosurface).View = PostProcessing.NbViews - 4;
Plugin(Isosurface).Run;
Merge "data/quads.pos";
Plugin(Isosurface).View = PostProcessing.NbViews - 4;
Plugin(Isosurface).Run;
