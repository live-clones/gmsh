// The parallel Delaunay algorithm (pdel3d) on two volumes sharing a face, with
// an embedded point, a mesh size field and quadrangles on the boundary
// (pyramids)

Mesh.Algorithm3D = 11;
General.NumThreads = 4;

Point(1) = {0, 0, 0, 0.1};
Extrude {1, 0, 0} { Point{1}; }
Extrude {0, 1, 0} { Line{1}; }
Extrude {0, 0, 1} { Surface{5}; }
Translate {1, 0, 0} { Duplicata { Volume{1}; } }
Coherence;

Point(100) = {0.5, 0.5, 0.5, 0.02};
Point{100} In Volume{1};

Field[1] = Ball;
Field[1].XCenter = 1.5;
Field[1].YCenter = 0.5;
Field[1].ZCenter = 0.5;
Field[1].Radius = 0.2;
Field[1].VIn = 0.03;
Field[1].VOut = 0.1;
Background Field = 1;

Recombine Surface{5};
