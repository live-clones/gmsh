// Plugin(ModulusPhase): in place, on element data (model) with two steps: each
// value once, not once per node of its element

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Merge "data/square.msh";
Combine TimeStepsByViewName;
For i In {0 : PostProcessing.NbViews - 1}
  If(!StrCmp(View[i].Name, "cell_Combine"))
    Plugin(ModulusPhase).View = i;
  EndIf
EndFor
Plugin(ModulusPhase).RealPart = 0;
Plugin(ModulusPhase).ImaginaryPart = 1;
Plugin(ModulusPhase).Run;
