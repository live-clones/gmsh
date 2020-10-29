SetFactory("OpenCASCADE");

// this step file contains several assemblies, with overlapping surfaces
vol() = ShapeFromFile("as1-tu-203.stp");

Mesh.Algorithm = 6;
Mesh.MeshSizeMin = 5;
Mesh.MeshSizeMax = 5;

SyncModel;

Physical Volume("Rod") = {};
Physical Volume("Nuts and bolts") = {};
Physical Volume("Left bracket") = {};
Physical Volume("Right bracket") = {};
Physical Volume("Plate") = {};

// the STEP names have been preserved after the subdivision process!
For i In {0 : #vol()-1}
  name = Str( Volume{vol(i)} );
  If(StrFind(name, "ROD-ASSEMBLY"))
    Physical Volume("Rod") += vol(i);
  ElseIf(StrFind(name, "nut-bolt-assembly"))
    Physical Volume("Nuts and bolts") += vol(i);
  ElseIf(StrFind(name, "L-BRACKET-ASSEMBLY::1"))
    Physical Volume("Left bracket") += vol(i);
  ElseIf(StrFind(name, "L-BRACKET-ASSEMBLY::2"))
    Physical Volume("Right bracket") += vol(i);
  ElseIf(StrFind(name, "PLATE"))
    Physical Volume("Plate") += vol(i);
  EndIf
EndFor
