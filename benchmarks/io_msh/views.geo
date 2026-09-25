// Model-based views (node data, element data and element-node data, on
// triangles and quadrangles, with two steps) are saved in MSH files of versions
// 2.2, 4.1 and 4.2, in ASCII and in binary, read back on the same mesh and
// compared with the originals.

SetFactory("OpenCASCADE");
Rectangle(1) = {0, 0, 0, 1, 1};
Rectangle(2) = {1, 0, 0, 1, 1};
BooleanFragments{ Surface{1}; Delete; }{ Surface{2}; Delete; }
Recombine Surface{2};
Mesh.MeshSizeMax = 0.1;
Mesh 2;

// a list view with values that vary over the elements, at their nodes, for two
// steps
Plugin(NewView).Type = "NodeData";
Plugin(NewView).Run;
Plugin(MathEval).View = 0;
Plugin(MathEval).TimeStep = -1;
Plugin(MathEval).Expression0 = "Sin(3 * x) + y * y";
Plugin(MathEval).Run;
Plugin(MathEval).Expression0 = "Cos(5 * y) * x";
Plugin(MathEval).Run;
Delete View[0];
Combine TimeStepsFromAllViews;
// ... saved as element-node data (by default), node data and element data, each
// with the mesh of its elements
PostProcessing.SaveMesh = 1;
Save View[0] "views_out_enodal.msh";
PostProcessing.ForceNodeData = 1;
Save View[0] "views_out_nodal.msh";
PostProcessing.ForceNodeData = 0;
PostProcessing.ForceElementData = 1;
Save View[0] "views_out_elemental.msh";
PostProcessing.ForceElementData = 0;

files[] = Str("views_out_enodal.msh", "views_out_nodal.msh",
              "views_out_elemental.msh");
PostProcessing.SaveMesh = 0;
For i In {0 : 2}
  For v In {PostProcessing.NbViews - 1 : 0 : -1}
    Delete View[v];
  EndFor
  Delete Model;
  Merge Str(files[i]);
  If(PostProcessing.NbViews != 1 || View[0].NbTimeStep != 2)
    Error(StrCat(Str(files[i]), ": %g views read, with %g steps"), PostProcessing.NbViews, View[0].NbTimeStep);
  EndIf
  For version In {0 : 2}
    For binary In {0 : 1}
      Mesh.MshFileVersion = (version == 0) ? 2.2 : (version == 1) ? 4.1 : 4.2;
      Mesh.Binary = binary;
      Save View[0] "views_out.msh";
      Merge "views_out.msh";
      // the difference between the view read back and the original, at each
      // step
      For step In {0 : 1}
        Plugin(MathEval).View = 0;
        Plugin(MathEval).OtherView = 1;
        Plugin(MathEval).TimeStep = step;
        Plugin(MathEval).OtherTimeStep = step;
        Plugin(MathEval).Expression0 = "Fabs(v0 - w0)";
        Plugin(MathEval).Run;
        diff = View[PostProcessing.NbViews - 1].Max;
        If(diff > (binary ? 0 : 1e-14))
          Error(StrCat(Str(files[i]), ": step %g differs by %g in MSH %g (binary %g)"), step, diff, Mesh.MshFileVersion, binary);
        EndIf
        Delete View[PostProcessing.NbViews - 1];
      EndFor
      Delete View[1];
    EndFor
  EndFor
EndFor
