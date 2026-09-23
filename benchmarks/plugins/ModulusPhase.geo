// Plugin(ModulusPhase): in place, on scalar node data (model) on triangles
// and vector node data (list) on tetrahedra

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Plugin(ModulusPhase).View = 0;
Plugin(ModulusPhase).Run;
Merge "data/cube.pos";
Plugin(ModulusPhase).View = PostProcessing.NbViews - 3;
Plugin(ModulusPhase).RealPart = 2;
Plugin(ModulusPhase).ImaginaryPart = 0;
Plugin(ModulusPhase).Run;
