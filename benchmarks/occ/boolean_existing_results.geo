SetFactory("OpenCASCADE");

// A boolean operation returns the entities of its result, each once, including
// the existing entities that are part of it: an input kept (no Delete) that the
// operation leaves unchanged, or a part of an input that coincides with an
// existing entity.

For preserve In {0:1}
  Geometry.OCCBooleanPreserveNumbering = preserve;
  o = 100 * preserve;

  // the intersection of a surface with a larger one containing it is that
  // surface
  Rectangle(o + 1) = {0, 0, 0, 100, 100};
  Rectangle(o + 2) = {10, 10, 0, 10, 10};
  s() = BooleanIntersection{ Surface{o + 2}; }{ Surface{o + 1}; };
  If(#s() != 1)
    Error("BooleanIntersection returned %g surfaces instead of 1 (preserve %g)",
          #s(), preserve);
  Else
    If(s(0) != o + 2)
      Error("BooleanIntersection returned surface %g, not %g (preserve %g)",
            s(0), o + 2, preserve);
    EndIf
  EndIf

  // the fragments of a surface and a curve inside it, both kept, are a new
  // surface (with the curve embedded) and the curve, each returned once
  r = news; Rectangle(r) = {0, 200, 0, 100, 100};
  p1 = newp; Point(p1) = {20, 250, 0};
  p2 = newp; Point(p2) = {80, 250, 0};
  l = newc; Line(l) = {p1, p2};
  e() = BooleanFragments{ Surface{r}; }{ Curve{l}; };
  If(#e() != 2)
    Error("BooleanFragments returned %g entities instead of 2 (preserve %g)",
          #e(), preserve);
  Else
    If(e(1) != l)
      Error("BooleanFragments returned curve %g, not %g (preserve %g)",
            e(1), l, preserve);
    EndIf
  EndIf

  // the part of a removed tool that lies on the internal face of two kept
  // volumes is that face; the part through a third volume is new
  b1 = newv; Box(b1) = {0, 0, 0, 1, 1, 1};
  b2 = newv; Box(b2) = {0, 0, 1, 1, 1, 1};
  w() = BooleanFragments{ Volume{b1}; Delete; }{ Volume{b2}; Delete; };
  b3 = newv; Box(b3) = {2, 0, 0.5, 1, 1, 1};
  t = news; Rectangle(t) = {-1, -1, 1, 5, 3};
  s() = BooleanIntersection{ Volume{w(), b3}; }{ Surface{t}; Delete; };
  If(#s() != 2)
    Error("BooleanIntersection returned %g surfaces instead of 2 (preserve %g)",
          #s(), preserve);
  EndIf
EndFor
