// A sphere fused on each corner of a box. For the corners on the side of the
// seam, the corner falls on a pole of the sphere, which the seam, two
// meridians and the two pieces of the degenerate curve of the pole then
// share: the curves of the loop cannot be ordered from their end points alone.

SetFactory("OpenCASCADE");

n = 0;
For i In {0:1}
  For j In {0:1}
    For k In {0:1}
      b = newv; Box(b) = {3 * n, 0, 0, 1, 0.7, 0.5};
      s = newv; Sphere(s) = {3 * n + i, 0.7 * j, 0.5 * k, 0.3};
      BooleanUnion{ Volume{b}; Delete; }{ Volume{s}; Delete; }
      n++;
    EndFor
  EndFor
EndFor

Mesh.MeshSizeMax = 0.1;

Mesh 3;

nbtets = Mesh.NbTetrahedra;
If(nbtets == 0)
  Error("No tetrahedral elements created!");
EndIf
