// Write views to VTK XML (.vtu) and read them back: a scalar on the nodes, a
// vector on the nodes and a scalar on the elements, in one file. x + 2 y +
// 3 z is different at every node of the box, so that the integral of the
// field over the mesh is right only if every value came back on the node it
// left from. (The mesh is of order 1, as Plugin(ModifyComponents) only sets
// the values at the corners of the elements.)

SetFactory("OpenCASCADE");
Box(1) = {0, 0, 0, 1, 2, 3};
Mesh.MeshSizeMin = 1; Mesh.MeshSizeMax = 1;
Mesh 3;

Plugin(NewView).NumComp = 1; Plugin(NewView).Type = "NodeData";
Plugin(NewView).Run;
Plugin(ModifyComponents).View = 0;
Plugin(ModifyComponents).Expression0 = "x + 2 * y + 3 * z";
Plugin(ModifyComponents).Run;
View[0].Name = "scalar";

Plugin(NewView).NumComp = 3; Plugin(NewView).Type = "NodeData";
Plugin(NewView).Run;
Plugin(ModifyComponents).View = 1;
Plugin(ModifyComponents).Expression0 = "x";
Plugin(ModifyComponents).Expression1 = "-y * y";
Plugin(ModifyComponents).Expression2 = "x * z";
Plugin(ModifyComponents).Run;
View[1].Name = "vector";

Plugin(NewView).NumComp = 1; Plugin(NewView).Type = "ElementData";
Plugin(NewView).Value = 5;
Plugin(NewView).Run;
View[2].Name = "constant";

Macro Measure
  // -> integral of the scalar, range of the scalar, largest vector, constant
  Plugin(Integrate).View = 0; Plugin(Integrate).Dimension = 3;
  Plugin(Integrate).Run;
  integral = View[PostProcessing.NbViews - 1].Max;
  Delete View[PostProcessing.NbViews - 1];
  smin = View[0].Min; smax = View[0].Max; vmax = View[1].Max;
  cmin = View[2].Min; cmax = View[2].Max;
Return

Call Measure;
// the integral of x + 2 y + 3 z over the box is 6 (1/2 + 2 + 9/2) = 42
If(Fabs(integral - 42) > 1e-8 || smin != 0 || smax != 14 || cmin != 5 || cmax != 5)
  Error("Unexpected views: integral %g, scalar in [%g, %g], constant in [%g, %g]", integral, smin, smax, cmin, cmax);
EndIf
vmax0 = vmax;

Mesh.SaveViews = 2; // (with the mesh)
For binary In {0 : 1}
  Mesh.Binary = binary;
  Save "vtu_views_out.vtu";
  Delete Model; Delete View[2]; Delete View[1]; Delete View[0];
  Merge "vtu_views_out.vtu";
  If(PostProcessing.NbViews != 3)
    Error("Binary %g: 3 views written, %g read", binary, PostProcessing.NbViews);
  EndIf
  Call Measure;
  If(Fabs(integral - 42) > 1e-8 || smin != 0 || smax != 14)
    Error("Binary %g: scalar read with integral %g in [%g, %g], expected 42 in [0, 14]", binary, integral, smin, smax);
  EndIf
  If(Fabs(vmax - vmax0) > 1e-12 || cmin != 5 || cmax != 5)
    Error("Binary %g: largest vector %g (expected %g), constant in [%g, %g] (expected 5)", binary, vmax, vmax0, cmin, cmax);
  EndIf
EndFor
Mesh.Binary = 0;
