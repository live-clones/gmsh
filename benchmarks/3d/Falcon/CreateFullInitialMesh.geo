Merge "InitialMeshFalcon.msh";
Plugin(NewView).Run;
Plugin(Transform).A33 = -1;
Plugin(Transform).Tz = 2 * 0.272342;
Plugin(Transform).SwapOrientation = 1;
Plugin(Transform).Run;
Physical Surface(1) = 1; // keep same num
For i In {2 : 16}
Physical Surface(100 + i) = i;
EndFor
Save "tmp.msh";

Delete All;

Mesh.SwitchElementTags = 1;
Merge "tmp.msh";

Mesh.SwitchElementTags = 0;
Merge "InitialMeshFalcon.msh";

Geometry.Tolerance = 1.e-4;
Coherence Mesh;

Mesh.SaveAll = 1;
Save "FullInitialMeshFalcon.msh";
