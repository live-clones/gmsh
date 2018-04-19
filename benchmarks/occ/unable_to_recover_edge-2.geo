SetFactory("OpenCASCADE");

a() = ShapeFromFile("unable_to_recover_edge_2d-2.brep");

Field[1] = MathEval;
Field[1].F = "1504 + 794 * sin (x/500)";
Background Field = 1;

Mesh.Algorithm = 1;
Mesh 2;

nbtriangles = Mesh.NbTriangles;
If(nbtriangles == 0)
  Error("No triangle elements created!");
EndIf
