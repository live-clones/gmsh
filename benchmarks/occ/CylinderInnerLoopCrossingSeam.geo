SetFactory("OpenCASCADE");

a() = ShapeFromFile("CylinderInnerLoopCrossingSeam.brep");

Mesh.Algorithm = 6;

nbtriangles = Mesh.NbTriangles;
If(nbtriangles == 0)
  Error("No triangular elements created!");
EndIf
