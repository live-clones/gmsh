// A torus fused on each corner of a box, the corner at its centre: the box
// cuts the torus through the point where its two seams cross, so that both
// seams are in the loop of the toroidal surface, one piece of each walked
// twice and the other once. As in sphere_box_corner.geo, the curves of the
// loop cannot be ordered from their end points alone; and the pieces walked
// once bound the surface on one side only.

SetFactory("OpenCASCADE");

n = 0;
For i In {0:1}
  For j In {0:1}
    For k In {0:1}
      b = newv; Box(b) = {3 * n, 0, 0, 1, 0.7, 0.5};
      t = newv; Torus(t) = {3 * n + i, 0.7 * j, 0.5 * k, 0.3, 0.1};
      BooleanUnion{ Volume{b}; Delete; }{ Volume{t}; Delete; }
      n++;
    EndFor
  EndFor
EndFor

Mesh.MeshSizeMax = 0.05;

Mesh 3;

nbtets = Mesh.NbTetrahedra;
If(nbtets == 0)
  Error("No tetrahedral elements created!");
EndIf
