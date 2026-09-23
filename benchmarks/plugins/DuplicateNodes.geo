// Plugin(DuplicateNodes): zero-measure quadrangles along every edge of a
// triangle mesh, also on its boundary curves
Merge "data/square.msh";
Plugin(DuplicateNodes).InsertMode = 0;
Plugin(DuplicateNodes).Insert1DElement = 1;
Plugin(DuplicateNodes).Run;
