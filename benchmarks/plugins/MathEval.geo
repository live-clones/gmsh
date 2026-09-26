// Plugin(MathEval): scalar, vector and tensor expressions of node, cell, model
// and list data on triangles and tetrahedra, all steps or one, with OtherView
// on the same grid or interpolated, restricted to a physical group

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Merge "data/square.pos"; // views 4-7: the same as lists
Plugin(MathEval).View = 0;
Plugin(MathEval).Expression0 = "v0^2 + x*y";
Plugin(MathEval).Run; // 3 steps
Plugin(MathEval).View = 1;
Plugin(MathEval).Expression0 = "v1";
Plugin(MathEval).Expression1 = "-v0";
Plugin(MathEval).Expression2 = "v2 + z";
Plugin(MathEval).Run; // vector
Plugin(MathEval).View = 2;
Plugin(MathEval).Expression0 = "v0";
Plugin(MathEval).Expression1 = "";
Plugin(MathEval).Expression2 = "";
Plugin(MathEval).Expression4 = "v4 - v0";
Plugin(MathEval).Expression8 = "v8 * v0";
Plugin(MathEval).Run; // tensor
Plugin(MathEval).Expression4 = "";
Plugin(MathEval).Expression8 = "";
Plugin(MathEval).View = 3;
Plugin(MathEval).Expression0 = "2 * v0 - 1";
Plugin(MathEval).Run; // cell data
Plugin(MathEval).View = 0;
Plugin(MathEval).TimeStep = 2;
Plugin(MathEval).OtherView = 1;
Plugin(MathEval).OtherTimeStep = 0;
Plugin(MathEval).Expression0 = "v0 * Sqrt(w0^2 + w1^2)";
Plugin(MathEval).Run; // one step, other view on the same grid
Plugin(MathEval).TimeStep = -1;
Plugin(MathEval).OtherTimeStep = -1;
Plugin(MathEval).OtherView = 4;
Plugin(MathEval).ForceInterpolation = 1;
Plugin(MathEval).Expression0 = "v0 - w0";
Plugin(MathEval).Run; // list data interpolated onto the model data: ~0
Plugin(MathEval).ForceInterpolation = 0;
Plugin(MathEval).OtherView = -1;
Plugin(MathEval).View = 5;
Plugin(MathEval).Expression0 = "Sqrt(v0^2+v1^2+v2^2)";
Plugin(MathEval).Run; // list data
Plugin(MathEval).View = 0;
Plugin(MathEval).PhysicalGroup = 3;
Plugin(MathEval).Expression0 = "v0 + 1";
Plugin(MathEval).Run;
Plugin(MathEval).PhysicalGroup = -1;

Merge "data/cube.pos"; // tetrahedra as lists
cube = PostProcessing.NbViews - 4;
Plugin(MathEval).View = cube + 1;
Plugin(MathEval).Expression0 = "v0 * v1";
Plugin(MathEval).Run;
Plugin(MathEval).View = cube;
Plugin(MathEval).OtherView = cube + 3;
Plugin(MathEval).OtherTimeStep = 0;
Plugin(MathEval).ForceInterpolation = 1;
Plugin(MathEval).Dimension = 3;
Plugin(MathEval).Expression0 = "v0 - w0";
Plugin(MathEval).Run; // cell values interpolated in the volume elements
