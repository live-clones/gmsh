// every kind of built-in kernel entity: points, lines, arcs of circles and
// ellipses, splines, B-splines, Bezier curves, compound curves, plane, ruled
// and spherical surfaces, volumes, extrusions (translation with layers,
// rotation, twist), transformed copies, embedded and orphan entities
lc = 0.2;
p1 = newp; Point(p1) = {0, 0, 0, lc}; p2 = newp; Point(p2) = {1, 0, 0, lc};
p3 = newp; Point(p3) = {1, 1, 0, lc}; p4 = newp; Point(p4) = {0, 1, 0, lc};
p5 = newp; Point(p5) = {0.5, 1.4, 0, lc}; p6 = newp; Point(p6) = {-0.3, 0.5, 0, lc};
p7 = newp; Point(p7) = {0.5, 0.5, 0, lc};
l1 = newc; Line(l1) = {p1, p2};
l2 = newc; Ellipse(l2) = {p2, p7, p7, p3};
l3 = newc; Spline(l3) = {p3, p5, p4};
l4 = newc; BSpline(l4) = {p4, p6, p1};
cl = newcl; Curve Loop(cl) = {l1, l2, l3, l4};
s1 = news; Plane Surface(s1) = {cl};
p9 = newp; Point(p9) = {0.5, 0.5, 0, lc};
Point{p9} In Surface{s1};
ex1[] = Extrude {0, 0, 0.5} { Surface{s1}; Layers{3}; Recombine; };

// ruled surfaces (4 and 3 sides)
q1 = newp; Point(q1) = {3, 0, 0, lc}; q2 = newp; Point(q2) = {4, 0, 0, lc};
q3 = newp; Point(q3) = {4, 1, 0.3, lc}; q4 = newp; Point(q4) = {3, 1, 0, lc};
q5 = newp; Point(q5) = {3.5, -1, 0.3, lc};
m1 = newc; Line(m1) = {q1, q2}; m2 = newc; Line(m2) = {q2, q3};
m3 = newc; Line(m3) = {q3, q4}; m4 = newc; Line(m4) = {q4, q1};
m5 = newc; Line(m5) = {q2, q5}; m6 = newc; Line(m6) = {q5, q1};
cl1 = newcl; Curve Loop(cl1) = {m1, m2, m3, m4}; r1 = news; Surface(r1) = {cl1};
cl2 = newcl; Curve Loop(cl2) = {m1, m5, m6}; r2 = news; Surface(r2) = {cl2};

// arcs of circles on a sphere
o = newp; Point(o) = {6, 0.5, 0, lc};
a1 = newp; Point(a1) = {6.5, 0.5, 0, lc}; a2 = newp; Point(a2) = {6, 1, 0, lc};
a3 = newp; Point(a3) = {6, 0.5, 0.5, lc};
k1 = newc; Circle(k1) = {a1, o, a2}; k2 = newc; Circle(k2) = {a2, o, a3};
k3 = newc; Circle(k3) = {a3, o, a1};
cl3 = newcl; Curve Loop(cl3) = {k1, k2, k3};
r3 = news; Surface(r3) = {cl3} In Sphere {o};

// Bezier curve, compound curve
b1 = newp; Point(b1) = {0, 3, 0, lc}; b2 = newp; Point(b2) = {0.5, 4, 0, lc};
b3 = newp; Point(b3) = {1, 3, 0, lc}; b4 = newp; Point(b4) = {2, 3.5, 0, lc};
z1 = newc; Bezier(z1) = {b1, b2, b3};
z2 = newc; Line(z2) = {b3, b4};
Compound Curve{z1, z2};

// extrusions: rotation of a curve, twist of a surface
d1 = newp; Point(d1) = {3, 3, 0, lc}; d2 = newp; Point(d2) = {3.5, 3, 0, lc};
y1 = newc; Line(y1) = {d1, d2};
Extrude {{0, 1, 0}, {3, 3, 0}, Pi / 2} { Curve{y1}; }
e1 = newp; Point(e1) = {5, 3, 0, lc}; e2 = newp; Point(e2) = {5.5, 3, 0, lc};
e3 = newp; Point(e3) = {5.5, 3.5, 0, lc}; e4 = newp; Point(e4) = {5, 3.5, 0, lc};
n1 = newc; Line(n1) = {e1, e2}; n2 = newc; Line(n2) = {e2, e3};
n3 = newc; Line(n3) = {e3, e4}; n4 = newc; Line(n4) = {e4, e1};
cl4 = newcl; Curve Loop(cl4) = {n1, n2, n3, n4};
s4 = news; Plane Surface(s4) = {cl4};
Extrude {{0, 0, 1}, {0, 0, 1}, {5.25, 3.25, 0}, Pi / 4} { Surface{s4}; }

// transformed copies
Translate {0, 6, 0} { Duplicata { Volume{ex1[1]}; } }
Symmetry {1, 0, 0, -3} { Duplicata { Surface{r1, r2}; } }
Dilate {{6, 0.5, 0}, 0.5} { Duplicata { Surface{r3}; } }

// orphan point and curve
f1 = newp; Point(f1) = {-1, -1, 0, lc};
f2 = newp; Point(f2) = {-1, 2, 0, lc}; f3 = newp; Point(f3) = {-1.5, 2, 0, lc};
Line(newc) = {f2, f3};

General.Trackball = 0;
General.RotationX = 300; General.RotationZ = 20;
