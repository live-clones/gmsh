// Plugin(Integrate): integrals over tetrahedra, hexahedra, triangles and
// quadrangles, model and list data, scalar, vector (flux over the boundary)
// and cell data; boundary only (Dimension); over time from the first step

Merge "data/cube.msh";
Merge "data/cube.pos";
views() = {0, 1, 3, 4, 5, 7};
For i In {0 : #views() - 1}
  Plugin(Integrate).View = views(i);
  Plugin(Integrate).Run;
EndFor
Plugin(Integrate).View = 0;
Plugin(Integrate).Dimension = 2;
Plugin(Integrate).Run;
Plugin(Integrate).Dimension = -1;
Plugin(Integrate).View = 4;
Plugin(Integrate).OverTime = 0;
Plugin(Integrate).Run;
Plugin(Integrate).OverTime = -1;

Merge "data/hexes.pos";
Plugin(Integrate).View = PostProcessing.NbViews - 4;
Plugin(Integrate).Run;
Merge "data/square.pos";
Plugin(Integrate).View = PostProcessing.NbViews - 4;
Plugin(Integrate).Run;
Plugin(Integrate).View = PostProcessing.NbViews - 4; // the vector view
Plugin(Integrate).Run;
Merge "data/quads.pos";
Plugin(Integrate).View = PostProcessing.NbViews - 4;
Plugin(Integrate).Run;
