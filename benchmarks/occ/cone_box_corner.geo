// A cone fused on each corner of a box, the corner at mid-height on its axis:
// as in sphere_box_corner.geo, the curves of the loop of the conical surface
// cannot be ordered from their end points alone.

SetFactory("OpenCASCADE");

n = 0;
For i In {0:1}
  For j In {0:1}
    For k In {0:1}
      b = newv; Box(b) = {3 * n, 0, 0, 1, 0.7, 0.5};
      c = newv; Cone(c) = {3 * n + i, 0.7 * j, 0.5 * k - 0.2, 0, 0, 0.4, 0.3, 0};
      BooleanUnion{ Volume{b}; Delete; }{ Volume{c}; Delete; }
      n++;
    EndFor
  EndFor
EndFor

v() = Volume{:}; s() = Surface{:};
If(#v() != 8 || #s() != 64)
  Error("%g volumes and %g surfaces instead of 8 and 64", #v(), #s());
EndIf

Mesh.MeshSizeMax = 0.1;

Mesh 3;

nbtets = Mesh.NbTetrahedra;
If(nbtets == 0)
  Error("No tetrahedral elements created!");
EndIf
