If(!PostProcessing.NbViews)
  Merge "../../tutorials/view1.pos";
  Merge "../../tutorials/view1.pos";
EndIf
DefineConstant[
  DD = {0, Name "Plane", Min -0.1, Max 0, Step 0.01,
    Help "Variable utilisée dans le script CutPlane"},
  ss = {"cutplane.script", Name "Cut Plane", Macro "Gmsh",
    Help Str["Lancer le script CutPlane", "Ca demande simplement à Gmsh de parser le fichier"],
    AutoCheck 0}
];

View[0].IntervalsType = 1;
CopyOptions View[0,1];
