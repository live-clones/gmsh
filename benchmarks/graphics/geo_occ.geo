// every kind of OpenCASCADE entity: points, lines, arcs, ellipses, splines,
// Bezier curves, wires, plane, filled, B-spline and Bezier surfaces, sections,
// extrusions, revolutions, pipes, fillets, chamfers, the primitive solids,
// booleans, transformed (B-spline) geometry and an imported STEP file
SetFactory("OpenCASCADE");

// curves
p1 = newp; Point(p1) = {0, 0, 0}; p2 = newp; Point(p2) = {1, 0, 0};
p3 = newp; Point(p3) = {1, 1, 0}; p4 = newp; Point(p4) = {0, 1, 0};
p5 = newp; Point(p5) = {0.5, 1.5, 0};
l = newc; Line(l) = {p1, p2};
Circle(newc) = {2, 0, 0, 0.3, 0, Pi / 2};
Ellipse(newc) = {3, 0, 0, 0.4, 0.2};
Spline(newc) = {p3, p5, p4};
BSpline(newc) = {p4, p5, p3, p2};
Bezier(newc) = {p1, p5, p2};

// surfaces: filling, rectangle, disk, B-spline, Bezier, sections
q1 = newp; Point(q1) = {0, 3, 0}; q2 = newp; Point(q2) = {1, 3, 0};
q3 = newp; Point(q3) = {1, 4, 0}; q4 = newp; Point(q4) = {0, 4, 0.3};
c1 = newc; Line(c1) = {q1, q2}; c2 = newc; Line(c2) = {q2, q3};
c3 = newc; Line(c3) = {q3, q4}; c4 = newc; Line(c4) = {q4, q1};
cl = newcl; Curve Loop(cl) = {c1, c2, c3, c4};
Surface(news) = {cl};
Rectangle(news) = {2, 3, 0, 1, 1, 0.2};
Disk(news) = {4, 3.5, 0, 0.5, 0.3};
For i In {0 : 1}
  x = 5 + 1.5 * i;
  r1 = newp; Point(r1) = {x, 3, 0}; r2 = newp; Point(r2) = {x + 1, 3, 0};
  r3 = newp; Point(r3) = {x + 1, 4, 0}; r4 = newp; Point(r4) = {x, 4, 0};
  m1 = newp; Point(m1) = {x + 0.5, 2.9, 0.3};
  m2 = newp; Point(m2) = {x + 1.1, 3.5, 0.3};
  u1 = newc; u2 = newc + 1; u3 = newc + 2; u4 = newc + 3;
  If(i == 0) // a B-spline filling from splines
    Spline(u1) = {r1, m1, r2}; Spline(u2) = {r2, m2, r3};
    Spline(u3) = {r3, r4}; Spline(u4) = {r4, r1};
  Else // a Bezier filling from Bezier curves
    Bezier(u1) = {r1, m1, r2}; Bezier(u2) = {r2, m2, r3};
    Bezier(u3) = {r3, r4}; Bezier(u4) = {r4, r1};
  EndIf
  cl = newcl; Curve Loop(cl) = {u1, u2, u3, u4};
  If(i == 0)
    BSpline Surface(news) = {cl};
  Else
    Bezier Surface(news) = {cl};
  EndIf
EndFor
k1 = newc; Circle(k1) = {9, 3.5, 0, 0.5};
k2 = newc; Circle(k2) = {9, 3.5, 1, 0.3};
w1 = newcl; Curve Loop(w1) = {k1}; w2 = newcl; Curve Loop(w2) = {k2};
ThruSections(newv) = {w1, w2};
k3 = newc; Circle(k3) = {10.5, 3.5, 0, 0.5};
k4 = newc; Circle(k4) = {10.5, 3.5, 1, 0.3};
w3 = newcl; Curve Loop(w3) = {k3}; w4 = newcl; Curve Loop(w4) = {k4};
Ruled ThruSections(newv) = {w3, w4};

// extrusions, revolution, pipe
s1 = news; Rectangle(s1) = {0, 6, 0, 1, 0.5};
Extrude {0, 0, 0.5} { Surface{s1}; }
s2 = news; Rectangle(s2) = {2, 6, 0, 0.5, 0.5};
Extrude {{0, 1, 0}, {3, 6, 0}, Pi / 2} { Surface{s2}; }
s3 = news; Disk(s3) = {5, 6, 0, 0.1};
t1 = newp; Point(t1) = {5, 6, 0}; t2 = newp; Point(t2) = {5, 6, 1};
t3 = newp; Point(t3) = {6, 7, 1.5};
b = newc; BSpline(b) = {t1, t2, t3};
w = newc; Wire(w) = {b};
Extrude { Surface{s3}; } Using Wire {w}

// solids, fillets, chamfers, booleans
Box(newv) = {0, 9, 0, 1, 1, 1};
Sphere(newv) = {2.5, 9.5, 0.5, 0.5};
Cylinder(newv) = {4, 9.5, 0, 0, 0, 1, 0.4};
Cone(newv) = {5.5, 9.5, 0, 0, 0, 1, 0.5, 0.1};
Wedge(newv) = {7, 9, 0, 1, 1, 1, 0.3};
Torus(newv) = {9.5, 9.5, 0.5, 0.6, 0.2};
v1 = newv; Box(v1) = {0, 12, 0, 1, 1, 1};
e() = Abs(Boundary{ Surface{Boundary{Volume{v1};}}; });
Fillet{v1}{e(0), e(1)}{0.2}
v2 = newv; Box(v2) = {2, 12, 0, 1, 1, 1};
e() = Abs(Boundary{ Surface{Boundary{Volume{v2};}}; });
s() = Boundary{Volume{v2};};
Chamfer{v2}{e(0)}{s(0)}{0.2}
v3 = newv; Box(v3) = {4, 12, 0, 1, 1, 1};
v4 = newv; Sphere(v4) = {5, 13, 1, 0.5};
BooleanDifference{ Volume{v3}; Delete; }{ Volume{v4}; Delete; }
v5 = newv; Box(v5) = {6.5, 12, 0, 1, 1, 1};
v6 = newv; Sphere(v6) = {7.5, 13, 1, 0.5};
BooleanFragments{ Volume{v5}; Delete; }{ Volume{v6}; Delete; }

// transformed into B-splines, and imported
v7 = newv; Cylinder(v7) = {0, 15, 0, 0, 0, 1, 0.4};
Dilate {{0, 15, 0}, {1, 2, 1}} { Volume{v7}; }
v() = ShapeFromFile("../../tutorials/t20_data.step");
Dilate {{0, 0, 0}, 0.02} { Volume{v()}; }
Translate {2, 15, 0} { Volume{v()}; }

// orphan entities
Point(newp) = {-1, -1, 0};
Circle(newc) = {-1, 2, 0, 0.3};

General.Trackball = 0;
General.RotationX = 300; General.RotationZ = 20;
