// Plugin(MeshSizeFieldView): MathEval, Box and Min fields evaluated on scalar
// and vector node data and on cell data, on triangles and tetrahedra (model
// data only: list data logs an error)
Merge "data/square.msh";
Field[1] = MathEval;
Field[1].F = "0.1 + x + 2 * y";
Field[2] = Box;
Field[2].VIn = 0.05; Field[2].VOut = 0.5;
Field[2].XMin = 0.2; Field[2].XMax = 0.6;
Field[2].YMin = 0.2; Field[2].YMax = 0.6;
Field[3] = Min;
Field[3].FieldsList = {1, 2};
Plugin(MeshSizeFieldView).MeshSizeField = 1;
views() = {0, 1, 3};
For i In {0 : #views() - 1}
  Plugin(MeshSizeFieldView).View = views(i);
  Plugin(MeshSizeFieldView).Run;
EndFor
Plugin(MeshSizeFieldView).MeshSizeField = 3;
Plugin(MeshSizeFieldView).View = 2;
Plugin(MeshSizeFieldView).Component = 4;
Plugin(MeshSizeFieldView).Run;
Plugin(MeshSizeFieldView).Component = 0;

NewModel; // fields belong to the model
Merge "data/cube.msh";
Field[1] = Box;
Field[1].VIn = 0.05; Field[1].VOut = 0.5;
Field[1].XMin = 0.2; Field[1].XMax = 0.6;
Field[1].YMin = 0.2; Field[1].YMax = 0.6;
Field[1].ZMin = 0; Field[1].ZMax = 0.5;
Plugin(MeshSizeFieldView).MeshSizeField = 1;
Plugin(MeshSizeFieldView).View = PostProcessing.NbViews - 4;
Plugin(MeshSizeFieldView).Run;
Plugin(MeshSizeFieldView).View = PostProcessing.NbViews - 1;
Plugin(MeshSizeFieldView).Run;
