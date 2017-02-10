// run "gmsh nested.geo -"

lc = 0.5;
Point(1) = {0, 0, 0, lc};     Point(2) = {-0.5, -0, 0, lc};
Point(3) = {0, -0.5, 0, lc}; Point(4) = {0, 0.5, 0, lc};
Point(5) = {0.5, -0, 0, lc};

Circle(1) = {2, 1, 3}; Circle(2) = {3, 1, 5};
Circle(3) = {5, 1, 4}; Circle(4) = {4, 1, 2};

Line Loop(5) = {4, 1, 2, 3};
Plane Surface(6) = {5};

Mesh.Algorithm = 6;
// Mesh.SecondOrderLinear = 1; // points on initial (linear) boundary mesh?

// generate initial mesh
Mesh 2;
Save "initial.msh";

// generate sequence of nested meshes
For i In {1:5}
  RefineMesh;
  Save Sprintf("nested_%g.msh", i);
EndFor

// generate sequence of (unrelated) refined meshes
For i In {1:5}
  Mesh.CharacteristicLengthFactor = 1 / 2^i;
  Mesh 1;
  Mesh 2;
  Save Sprintf("refined_%g.msh", i);
EndFor
