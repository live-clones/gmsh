// A block with a boss and a bore, rounded with the discrete CAD modeler: the
// fillets of convex curves remove the solid between the rolling ball and the
// curve, those of concave ones fill the space between them; the curves
// continuing the given ones tangentially are filleted too, and three fillets
// of the same radius meeting at a point are joined by a piece of the ball
SetFactory("Discrete");

Box(1) = {0, 0, 0, 4, 3, 1};
Cylinder(2) = {2, 1.5, 1, 0, 0, 0.8, 0.8};
v() = BooleanUnion{ Volume{1}; Delete; }{ Volume{2}; Delete; };
Cylinder(3) = {2, 1.5, -1, 0, 0, 3, 0.4};
v() = BooleanDifference{ Volume{v(0)}; Delete; }{ Volume{3}; Delete; };

e = 1e-3;
// the vertical edges of the block
c() = {};
For i In {0:1}
  For j In {0:1}
    x = 4 * i; y = 3 * j;
    c() += Curve In BoundingBox{x - e, y - e, -e, x + e, y + e, 1 + e};
  EndFor
EndFor
v() = Fillet{v(0)}{c()}{0.4};

// one edge of the top of the block: the loop of the top continues it
c() = Curve In BoundingBox{0.4 - e, -e, 1 - e, 3.6 + e, e, 1 + e};
v() = Fillet{v(0)}{c()}{0.15};

// the foot of the boss (concave), its top and the ends of the bore (convex)
foot() = Curve In BoundingBox{1.2 - e, 0.7 - e, 1 - e, 2.8 + e, 2.3 + e, 1 + e};
v() = Fillet{v(0)}{foot()}{0.2};
top() = Curve In BoundingBox{1.2 - e, 0.7 - e, 1.8 - e, 2.8 + e, 2.3 + e, 1.8 + e};
v() = Fillet{v(0)}{top()}{0.08};
bottom() = Curve In BoundingBox{1.6 - e, 1.1 - e, -e, 2.4 + e, 1.9 + e, e};
v() = Fillet{v(0)}{bottom()}{0.08};

Mesh.MeshSizeMax = 0.1;
