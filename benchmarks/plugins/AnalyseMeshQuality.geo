// Plugin(AnalyseMeshQuality): views of J, IGE and ICN for tetrahedra, then
// for their boundary triangles, for hexahedra and quadrangles together; then
// hide the triangles of a square with ICN < 0.95, deleted by Plugin(Invisible)
Merge "data/cube.msh";
Plugin(AnalyseMeshQuality).JacobianDeterminant = 1;
Plugin(AnalyseMeshQuality).IGEMeasure = 1;
Plugin(AnalyseMeshQuality).ICNMeasure = 1;
Plugin(AnalyseMeshQuality).CreateView = 1;
Plugin(AnalyseMeshQuality).Run;
Plugin(AnalyseMeshQuality).DimensionOfElements = 2;
Plugin(AnalyseMeshQuality).Run;

NewModel;
Merge "data/hexes.msh";
Plugin(AnalyseMeshQuality).Recompute = 1;
Plugin(AnalyseMeshQuality).DimensionOfElements = 4;
Plugin(AnalyseMeshQuality).Run;

NewModel;
Merge "data/square.msh";
Plugin(AnalyseMeshQuality).DimensionOfElements = -1;
Plugin(AnalyseMeshQuality).CreateView = 0;
Plugin(AnalyseMeshQuality).HidingThreshold = 0.95;
Plugin(AnalyseMeshQuality).ThresholdGreater = 0;
Plugin(AnalyseMeshQuality).Run;
Plugin(Invisible).Run;
