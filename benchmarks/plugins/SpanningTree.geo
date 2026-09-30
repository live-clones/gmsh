// Plugin(SpanningTree): a tree spanning the nodes of the physical curves 1
// and 2 then of the physical surface 3 of a triangle mesh, in a new group
Merge "data/square.msh";
Plugin(SpanningTree).PhysicalCurves = "1, 2";
Plugin(SpanningTree).PhysicalSurfaces = "3";
Plugin(SpanningTree).Run;
