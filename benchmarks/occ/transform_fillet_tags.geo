SetFactory("OpenCASCADE");

// Transformed entities keep their tags, as well as the entities on their
// boundary (#3465, #592); filleted volumes keep their tags, as well as their
// surfaces, curves and points left unchanged or modified into a single one
// (#706)

// a curve keeps its points, even if larger point tags exist
Point(1) = {0, 0, 0};
Point(2) = {1, 0, 0};
Point(100) = {1, 0.1, 0};
Line(1) = {1, 2};
Translate{0, 0, 1}{ Curve{1}; }
b() = Boundary{ Curve{1}; };
If(b(0) != 1 || b(1) != 2)
  Error("Translated curve 1 has points %g and %g instead of 1 and 2", b(0),
        b(1));
EndIf

// a volume keeps its surfaces, even if larger surface tags exist
Cylinder(1) = {10, 0, 0, 0, 0, 1, 0.5};
Cylinder(2) = {10, 0, 1, 0, 0, 1, 0.5};
Rotate{{0, 0, 1}, {10, 0, 0}, Pi / 3}{ Volume{1}; }
s() = Boundary{ Volume{1}; };
If(#s() != 3 || s(0) != 1 || s(1) != 2 || s(2) != 3)
  Error("Rotated volume 1 does not have surfaces 1, 2 and 3");
EndIf

// a point shared with a curve that is not translated stays with it: the
// translated curve gets a new one
Point(201) = {20, 0, 0};
Point(202) = {21, 0, 0};
Point(203) = {21, 1, 0};
Line(201) = {201, 202};
Line(202) = {202, 203};
b() = Boundary{ Curve{202}; };
Translate{0, 0, 1}{ Curve{201}; }
b() = Boundary{ Curve{202}; };
If(b(0) != 202 || b(1) != 203)
  Error("Curve 202 has points %g and %g instead of 202 and 203", b(0), b(1));
EndIf
b() = Boundary{ Curve{201}; };
If(b(0) != 201 || b(1) == 202)
  Error("Translated curve 201 has points %g and %g", b(0), b(1));
EndIf

// a filleted box keeps its tag and its 6 surfaces
Box(42) = {30, 0, 0, 1, 1, 1};
s() = Boundary{ Volume{42}; };
c() = Boundary{ Surface{s(0)}; };
Fillet{42}{ Abs(c(0)) }{0.2}
s2() = Boundary{ Volume{42}; };
n = 0;
For i In {0:#s() - 1}
  For j In {0:#s2() - 1}
    If(Abs(s(i)) == Abs(s2(j)))
      n++;
    EndIf
  EndFor
EndFor
If(#s2() != 7 || n != 6)
  Error("Filleted box 42 has %g surfaces, %g of the 6 of the box", #s2(), n);
EndIf
