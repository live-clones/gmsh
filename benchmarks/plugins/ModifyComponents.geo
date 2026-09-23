// Plugin(ModifyComponents): in-place changes of node data (model and list) and
// cell data (list) on triangles and tetrahedra, all steps or one, some
// components only, with Time/TimeStep, OtherView on the same grid or not

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Merge "data/square.pos"; // views 4-7: the same as lists
Plugin(ModifyComponents).View = 0;
Plugin(ModifyComponents).Expression0 = "v0 * Time + TimeStep + x";
Plugin(ModifyComponents).Run; // all steps
Plugin(ModifyComponents).View = 1;
Plugin(ModifyComponents).TimeStep = 1;
Plugin(ModifyComponents).Expression0 = "";
Plugin(ModifyComponents).Expression2 = "v0 * v1";
Plugin(ModifyComponents).Run; // third component of step 1 only
Plugin(ModifyComponents).TimeStep = -1;
Plugin(ModifyComponents).View = 2;
Plugin(ModifyComponents).Expression2 = "";
Plugin(ModifyComponents).Expression4 = "-v4";
Plugin(ModifyComponents).Expression8 = "v8 + y";
Plugin(ModifyComponents).Run; // tensor
Plugin(ModifyComponents).Expression4 = "";
Plugin(ModifyComponents).Expression8 = "";
Plugin(ModifyComponents).View = 4;
Plugin(ModifyComponents).Expression0 = "Sin(v0)";
Plugin(ModifyComponents).Run; // list data
Plugin(ModifyComponents).View = 5;
Plugin(ModifyComponents).OtherView = 4;
Plugin(ModifyComponents).Expression0 = "w0";
Plugin(ModifyComponents).Expression1 = "w0 * v1";
Plugin(ModifyComponents).Run; // other view on the same grid
Plugin(ModifyComponents).View = 0;
Plugin(ModifyComponents).OtherView = 5;
Plugin(ModifyComponents).OtherTimeStep = 2;
Plugin(ModifyComponents).Expression0 = "v0 + w2";
Plugin(ModifyComponents).Expression1 = "";
Plugin(ModifyComponents).Run; // list data interpolated onto model data
Plugin(ModifyComponents).OtherTimeStep = -1;
Plugin(ModifyComponents).View = 7;
Plugin(ModifyComponents).OtherView = 0;
Plugin(ModifyComponents).ForceInterpolation = 1;
Plugin(ModifyComponents).OtherTimeStep = 1;
Plugin(ModifyComponents).Expression0 = "v0 - w0";
Plugin(ModifyComponents).Run; // forced interpolation
Plugin(ModifyComponents).ForceInterpolation = 0;
Plugin(ModifyComponents).OtherView = -1;
Plugin(ModifyComponents).OtherTimeStep = -1;

Merge "data/cube.pos"; // tetrahedra as lists
Plugin(ModifyComponents).View = PostProcessing.NbViews - 3;
Plugin(ModifyComponents).Expression0 = "v0 * z";
Plugin(ModifyComponents).Expression1 = "v1 * z";
Plugin(ModifyComponents).Run;

// element data: one value per element, changed once (it was squared once per
// node), with the coordinates of the barycenter
NewModel;
Merge "data/square.msh";
Plugin(ModifyComponents).View = PostProcessing.NbViews - 1;
Plugin(ModifyComponents).OtherView = -1;
Plugin(ModifyComponents).TimeStep = -1;
Plugin(ModifyComponents).ForceInterpolation = 0;
Plugin(ModifyComponents).Expression0 = "v0^2 + x";
Plugin(ModifyComponents).Expression1 = "";
Plugin(ModifyComponents).Expression2 = "";
Plugin(ModifyComponents).Expression3 = "";
Plugin(ModifyComponents).Expression4 = "";
Plugin(ModifyComponents).Expression5 = "";
Plugin(ModifyComponents).Expression6 = "";
Plugin(ModifyComponents).Expression7 = "";
Plugin(ModifyComponents).Expression8 = "";
Plugin(ModifyComponents).Run;
