SetFactory("OpenCASCADE");

// With Geometry.OCCBooleanPreserveNumbering = 2, the physical groups of the
// entities split by boolean operations go to their pieces (#2092, #1786,
// #2179), and periodic surfaces stay periodic (#338; see
// boolean_split_periodic.py for the check of the mesh)
Geometry.OCCBooleanPreserveNumbering = 2;

// the bottom curve of the upper rectangle is split in two by Coherence (#2092)
Rectangle(1) = {0, 0, 0, 1, 0.5, 0};
Rectangle(2) = {0.5, 0.5, 0, 1, 0.5, 0};
L() = Boundary{ Surface{2}; };
Physical Curve("BottomOfUpperRectangle", 1) = {L(0)};
Coherence;
c() = Physical Curve{1};
If(#c() != 2)
  Error("Physical curve 1 has %g curves instead of 2", #c());
EndIf
For i In {0:#c() - 1}
  bb() = BoundingBox Curve{ c(i) };
  If(Fabs(bb(1) - 0.5) > 1e-6 || Fabs(bb(4) - 0.5) > 1e-6 ||
     bb(0) < 0.5 - 1e-6 || bb(3) > 1.5 + 1e-6)
    Error("Curve %g is not on the bottom of the upper rectangle", c(i));
  EndIf
EndFor
Delete All;
Delete Physicals;
SetFactory("OpenCASCADE");

// the bottom plate of a T is split in two by the vertical one (#1786)
Rectangle(1) = {0, 0, 0, 2, 1, 0};
Rectangle(2) = {1, 0, 0, 1, 1, 0};
Rotate{ {0, 1, 0}, {1, 0, 0}, -Pi/2 }{ Surface{2}; }
Physical Surface("bottom plate", 1) = {1};
Physical Surface("vertical plate", 2) = {2};
Coherence;
s() = Physical Surface{1};
If(#s() != 2)
  Error("Physical surface 1 has %g surfaces instead of 2", #s());
EndIf
For i In {0:#s() - 1}
  bb() = BoundingBox Surface{ s(i) };
  If(Fabs(bb(2)) > 1e-6 || Fabs(bb(5)) > 1e-6)
    Error("Surface %g is not in the bottom plate", s(i));
  EndIf
EndFor
s() = Physical Surface{2};
If(#s() != 1)
  Error("Physical surface 2 has %g surfaces instead of 1", #s());
EndIf
Delete All;
Delete Physicals;
SetFactory("OpenCASCADE");

// two volumes sliced by a plane keep their material (#2179)
Box(1) = {0, 0, 0, 1, 1, 1};
Box(2) = {1, 0, 0, 1, 1, 1};
Physical Volume("steel", 1) = {1};
Physical Volume("wood", 2) = {2};
Rectangle(100) = {-1, -1, 0.5, 4, 3, 0};
BooleanFragments{ Volume{1, 2}; Delete; }{ Surface{100}; Delete; }
For p In {1:2}
  v() = Physical Volume{p};
  If(#v() != 2)
    Error("Physical volume %g has %g volumes instead of 2", p, #v());
  EndIf
  For i In {0:#v() - 1}
    bb() = BoundingBox Volume{ v(i) };
    If(Fabs(bb(0) - (p - 1)) > 1e-6 || Fabs(bb(3) - p) > 1e-6)
      Error("Volume %g is not in physical volume %g", v(i), p);
    EndIf
  EndFor
EndFor
Delete All;
Delete Physicals;
SetFactory("OpenCASCADE");

// a periodic cube with spheres on two opposite faces (#338)
Box(1) = {0, 0, 0, 1, 1, 1};
Periodic Surface{2} = {1} Translate{1, 0, 0};
Sphere(2) = {0, 0.5, 0.5, 0.2};
Sphere(3) = {1, 0.5, 0.5, 0.2};
BooleanFragments{ Volume{1}; Delete; }{ Volume{2, 3}; Delete; }
Physical Volume("matrix", 1) = {1};
Mesh.MeshSizeMax = 0.1;
