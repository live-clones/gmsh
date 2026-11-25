SetFactory("OpenCASCADE");

// With Geometry.OCCBooleanPreserveNumbering = 2, the entities on the boundary
// of the arguments of boolean operations keep their tags if they are left
// unchanged or modified into a single one (#2078, #2092)
Geometry.OCCBooleanPreserveNumbering = 2;

Macro CheckSurfaces
  For i In {0:#expected() - 1}
    found = 0;
    For j In {0:#s() - 1}
      If(Abs(s(j)) == expected(i))
        found = 1;
      EndIf
    EndFor
    If(!found)
      Error("Surface %g is not on the boundary of volume %g", expected(i), v);
    EndIf
  EndFor
  If(#s() != #expected())
    Error("Volume %g has %g surfaces instead of %g", v, #s(), #expected());
  EndIf
Return

// a box keeps its 6 surfaces when a cylinder is cut out of it, and the hole
// keeps the lateral surface (7) and the bottom (9) of the cylinder; the mesh
// constraints of surface 2, left unchanged, are kept too (checked at the end)
Box(1) = {0, 0, 0, 1, 1, 1};
Cylinder(2) = {0.5, 0.5, 0.5, 0, 0, 1, 0.2};
Transfinite Curve{ Boundary{ Surface{2}; } } = 5;
Transfinite Surface{2};
Recombine Surface{2};
BooleanDifference{ Volume{1}; Delete; }{ Volume{2}; Delete; }
v = 1;
s() = Boundary{ Volume{v}; };
expected() = {1:7, 9};
Call CheckSurfaces;
bb() = BoundingBox Surface{6};
If(Fabs(bb(2) - 1) > 1e-6 || Fabs(bb(5) - 1) > 1e-6)
  Error("Surface 6 is not the top of the box");
EndIf

// the same with the tag of the result given explicitly
Box(11) = {10, 0, 0, 1, 1, 1};
Cylinder(12) = {10.5, 0.5, 0.5, 0, 0, 1, 0.2};
s() = Boundary{ Volume{11}; };
c() = Boundary{ Volume{12}; };
BooleanDifference(13) = { Volume{11}; Delete; }{ Volume{12}; Delete; };
v = 13;
expected() = {Abs(s()), Abs(c(0)), Abs(c(2))};
s() = Boundary{ Volume{v}; };
Call CheckSurfaces;

// the curves of two touching rectangles that are not split keep their tags
Rectangle(100) = {20, 0, 0, 1, 0.5};
Rectangle(101) = {20.5, 0.5, 0, 1, 0.5};
c1() = Boundary{ Surface{100}; };
c2() = Boundary{ Surface{101}; };
kept() = Abs(c1({0, 1, 3}));
kept() += Abs(c2({1:3}));
bb() = {};
For i In {0:#kept() - 1}
  bb() += BoundingBox Curve{kept(i)};
EndFor
BooleanFragments{ Surface{100, 101}; Delete; }{}
For i In {0:#kept() - 1}
  b() = BoundingBox Curve{kept(i)};
  same = 1;
  For j In {0:5}
    If(Fabs(b(j) - bb(6 * i + j)) > 1e-6)
      same = 0;
    EndIf
  EndFor
  If(!same)
    Error("Curve %g of the rectangles is not the same curve", kept(i));
  EndIf
EndFor

Mesh 2;
If(Mesh.NbQuadrangles != 16)
  Error("%g quadrangles instead of the 4 x 4 of surface 2", Mesh.NbQuadrangles);
EndIf
