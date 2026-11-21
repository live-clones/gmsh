SetFactory("OpenCASCADE");

// A curve loop that crosses itself (a figure eight) or touches itself does not
// bound a single plane surface: OpenCASCADE splits the face, and all the parts
// must be kept as surfaces (#3441). The first and fifth points are at the same
// location: OpenCASCADE merges them when it builds the loop.

For touch In {0:1}
  y = 3 * touch;
  d = 1 - 2 * touch; // the left lobe runs the other way if the loop touches
  p = newp;
  Point(p) = {0, y, 0};
  Point(p + 1) = {-1, y - d, 0};
  Point(p + 2) = {-2, y, 0};
  Point(p + 3) = {-1, y + d, 0};
  Point(p + 4) = {0, y, 0};
  Point(p + 5) = {1, y - 1, 0};
  Point(p + 6) = {2, y, 0};
  Point(p + 7) = {1, y + 1, 0};
  l = newl;
  For i In {0:7}
    Line(l + i) = {p + i, p + (i + 1) % 8};
  EndFor
  ll = newll;
  Curve Loop(ll) = {l:l + 7};
  Plane Surface(news) = {ll};

  s() = Surface{:};
  If(#s() != 2 * (touch + 1))
    Error("%g surfaces instead of %g (touch %g)", #s(), 2 * (touch + 1), touch);
  Else
    For i In {#s() - 2:#s() - 1}
      a = Mass Surface{s(i)};
      b() = Boundary{ Surface{s(i)}; };
      If(Fabs(a - 2) > 1e-6 || #b() != 4)
        Error("Surface %g has area %g and %g curves instead of 2 and 4 (touch %g)",
              s(i), a, #b(), touch);
      EndIf
    EndFor
  EndIf
EndFor

// the curve loop keeps its tag and the parts' wires get none: the next curve
// loop tag is still free
p = newp;
Point(p) = {0, 6, 0};
Point(p + 1) = {1, 6, 0};
Point(p + 2) = {0, 7, 0};
l = newl;
Line(l) = {p, p + 1};
Line(l + 1) = {p + 1, p + 2};
Line(l + 2) = {p + 2, p};
Curve Loop(ll + 1) = {l:l + 2};
Plane Surface(news) = {ll + 1};
