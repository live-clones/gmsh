Merge "surf1.stl";
Merge "surf2.stl";

Geometry.Tolerance = 1e-6;
Coherence Mesh;
CreateTopology;

Extrude {
  Surface {:};
  Layers{ {3}, {0.1} };
  Recombine;
}
