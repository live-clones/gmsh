fast = 1;

// create geometry with some mesh sizes on boundaries
SetFactory("OpenCASCADE");
Rectangle(1) = {0,0,0, 10,10};
Rectangle(2) = {2,4,0, 2,1};
Rectangle(3) = {5,5,0, 1,2};
Rectangle(4) = {2,6,0, 1,1};
Rectangle(5) = {7,2,0, 2,2};
Rotate {{0, 0, 1}, {5, 5, 0}, Pi/4} { Surface{3}; }
Rotate {{0, 0, 1}, {2, 6, 0}, Pi/3} { Surface{4}; }
MeshSize{ PointsOf{ Surface{1}; } } = fast ? 0.5 : 1;
MeshSize{ PointsOf{ Surface{2:5}; } } = fast ? 0.05 : 0.1;
BooleanDifference{ Surface{1}; Delete; }{ Surface{2:5}; Delete; }

// replace default mesh size interpolation with "Extend" field, to decrease
// sizes smoothly away from boundaries
Mesh.MeshSizeExtendFromBoundary = 0;
Field[1] = Extend;
Field[1].CurvesList = {Curve{:}};
Field[1].DistMax = 2;
Field[1].SizeMax = fast ? 0.5 : 1;
Field[1].Power = 1;
Background Field = 1;

// recombine triangular mesh into quads
Recombine Surface{:};

If(fast)
  // use frontal-Delaunay for quads - pretty fast
  Mesh.Algorithm = 8;
  // use simple full-quad (fast) or blossom full-quad (more expensive) to
  // guarantee full-quad mesh by subdivision
  Mesh.RecombinationAlgorithm = 3; // or 2
Else
  // use new experimental quasi-structured quad algorithm - even better, but
  // much slower (warning: mesh size should be specified as twice the desired
  // size)
  Mesh.Algorithm = 11;
EndIf
