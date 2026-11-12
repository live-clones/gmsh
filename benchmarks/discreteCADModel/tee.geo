// A flanged pipe tee with the discrete CAD modeler: the union of the pipes and
// of their flanges, minus the bores and the bolt holes
SetFactory("Discrete");
Geometry.DiscreteTolerance = 1e-3;

// the outside: the main pipe, the branch and their flanges
Cylinder(1) = {-1.95, 0, 0, 3.9, 0, 0, 0.5};
Cylinder(2) = {0, 0, 0, 0, 0, 1.45, 0.3};
Cylinder(3) = {-2, 0, 0, 0.12, 0, 0, 0.8};
Cylinder(4) = {1.88, 0, 0, 0.12, 0, 0, 0.8};
Cylinder(5) = {0, 0, 1.38, 0, 0, 0.12, 0.55};
tee() = BooleanUnion{ Volume{1}; Delete; }{ Volume{2:5}; Delete; };

// the inside: the bores, and the bolt holes through the flanges
holes() = {newv};
Cylinder(holes(0)) = {-2.5, 0, 0, 5, 0, 0, 0.4};
holes() += newv;
Cylinder(newv) = {0, 0, 0, 0, 0, 2, 0.22};
For i In {0:3}
  a = Pi / 4 + i * Pi / 2;
  holes() += newv;
  Cylinder(newv) = {-2.1, 0.65 * Cos(a), 0.65 * Sin(a), 4.2, 0, 0, 0.06};
  holes() += newv;
  Cylinder(newv) = {0.43 * Cos(a), 0.43 * Sin(a), 1.3, 0, 0, 0.3, 0.05};
EndFor
tee() = BooleanDifference{ Volume{tee()}; Delete; }{ Volume{holes()}; Delete; };

Mesh.MeshSizeMax = 0.06;
