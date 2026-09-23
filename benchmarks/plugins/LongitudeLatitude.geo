// Plugin(LongitudeLatitude): triangles moved around the z axis above the
// origin, projected in longitude-latitude (across the date line): scalar
// data with 3 steps (list), vector data with 1 step (list and model)

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Merge "data/square.pos"; // views 4-7: the same as lists
Plugin(MathEval).View = 5;
Plugin(MathEval).TimeStep = 1;
Plugin(MathEval).Expression0 = "v0";
Plugin(MathEval).Expression1 = "v1";
Plugin(MathEval).Expression2 = "v2";
Plugin(MathEval).Run; // view 8: vector list, one step
Plugin(NewView).NumComp = 3;
Plugin(NewView).Value = 1;
Plugin(NewView).Run; // view 9: vector model data, one step
Plugin(Transform).Tx = -0.5;
Plugin(Transform).Ty = -0.5;
Plugin(Transform).Tz = 1;
views() = {4, 8, 9};
For i In {0 : #views() - 1}
  Plugin(Transform).View = views(i);
  Plugin(Transform).Run;
  Plugin(LongitudeLatitude).View = views(i);
  Plugin(LongitudeLatitude).Run;
EndFor
