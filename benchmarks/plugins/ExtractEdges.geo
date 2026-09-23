// Plugin(ExtractEdges): the sharp edges of the boundary triangles of a cube
// (angle 40 and 100 degrees), then the boundary edges of a flat square with
// and without IncludeBoundary
Merge "data/cube.msh";
Plugin(ExtractEdges).Run;
Plugin(ExtractEdges).Angle = 100;
Plugin(ExtractEdges).Run;
Plugin(ExtractEdges).Angle = 40;

NewModel;
Merge "data/square.msh";
Plugin(ExtractEdges).Run;
Plugin(ExtractEdges).Angle = 0;
Plugin(ExtractEdges).IncludeBoundary = 0;
Plugin(ExtractEdges).Run;
