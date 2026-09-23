// Plugin(Scal2Tens): tensors (9 components) and vectors (3) from scalar node
// and cell data, model and list, with missing components, on triangles and
// tetrahedra

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Plugin(Scal2Tens).View0 = 0;
Plugin(Scal2Tens).View4 = 0;
Plugin(Scal2Tens).View8 = 0;
Plugin(Scal2Tens).NameNewView = "diagonal";
Plugin(Scal2Tens).Run;
Plugin(Scal2Tens).NumberOfComponents = 3;
Plugin(Scal2Tens).View0 = 3;
Plugin(Scal2Tens).View2 = 3;
Plugin(Scal2Tens).NameNewView = "cell";
Plugin(Scal2Tens).Run;
Plugin(Scal2Tens).View2 = -1;
Plugin(Scal2Tens).View4 = -1;
Plugin(Scal2Tens).View8 = -1;
Merge "data/cube.pos"; // the same element lists are needed in all views
Plugin(Scal2Tens).NumberOfComponents = 9;
Plugin(Scal2Tens).View0 = PostProcessing.NbViews - 4;
Plugin(Scal2Tens).View5 = PostProcessing.NbViews - 4;
Plugin(Scal2Tens).View7 = PostProcessing.NbViews - 4;
Plugin(Scal2Tens).NameNewView = "list";
Plugin(Scal2Tens).Run;

// 6 components: a tensor view, the last 3 components 0 (the view was empty)
Plugin(Scal2Tens).NumberOfComponents = 6;
s = PostProcessing.NbViews - 5; // the scalar list view
Plugin(Scal2Tens).View0 = s;
Plugin(Scal2Tens).View1 = s;
Plugin(Scal2Tens).View2 = s;
Plugin(Scal2Tens).View3 = s;
Plugin(Scal2Tens).View4 = s;
Plugin(Scal2Tens).View5 = s;
Plugin(Scal2Tens).Run;
