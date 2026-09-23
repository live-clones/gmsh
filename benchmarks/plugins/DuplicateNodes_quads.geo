// Plugin(DuplicateNodes): pairs of triangles along every edge of a quadrangle
// mesh, elements shrunk by 0.25, nothing inserted on the boundary curves
Merge "data/quads.msh";
Plugin(DuplicateNodes).InsertMode = 1;
Plugin(DuplicateNodes).ShrinkFactor = 0.25;
Plugin(DuplicateNodes).Insert1DElement = 0;
Plugin(DuplicateNodes).Run;
