// Plugin(Distance): Euclidean distance to all boundaries and to a physical
// curve or surface, scaled, and approximate PDE distance (also to a physical
// point), on triangles, quadrangles and tetrahedra

Merge "data/square.msh";
Delete View[3]; Delete View[2]; Delete View[1]; Delete View[0]; // model data
Plugin(Distance).Run; // all boundaries
Plugin(Distance).PhysicalLine = 1;
Plugin(Distance).Run;
Plugin(Distance).MinScale = 0.1;
Plugin(Distance).MaxScale = 2;
Plugin(Distance).Run;
Plugin(Distance).MaxScale = 0;
Plugin(Distance).Run; // shifted by MinScale
Plugin(Distance).MinScale = 0;
Plugin(Distance).DistanceType = 1;
Plugin(Distance).Run;
Plugin(Distance).DistanceType = 0;
Plugin(Distance).PhysicalLine = 0;

Delete Model;
Merge "data/quads.msh";
n = PostProcessing.NbViews;
For i In {1 : 4}
  Delete View[n - i];
EndFor
Plugin(Distance).Run;

Delete Model; // tetrahedra with a triangulated boundary
Point(1) = {0, 0, 0, 0.4};
Point(2) = {1, 0, 0, 0.4};
Point(3) = {1, 1, 0, 0.4};
Point(4) = {0, 1, 0, 0.4};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};
Extrude {0, 0, 1} { Surface{1}; }
Physical Point(1) = {1};
Physical Surface(2) = {1};
Mesh 3;
Plugin(Distance).Run;
Plugin(Distance).PhysicalSurface = 2;
Plugin(Distance).Run;
Plugin(Distance).DistanceType = 0.5;
Plugin(Distance).Run;
Plugin(Distance).PhysicalSurface = 0;
Plugin(Distance).PhysicalPoint = 1;
Plugin(Distance).Run;

// to the boundary quadrangles of hexahedra, and to a physical point (both
// crashed)
NewModel;
Merge "data/hexes.msh";
For i In {1 : 4}
  Delete View[PostProcessing.NbViews - 1];
EndFor
Plugin(Distance).PhysicalPoint = 0;
Plugin(Distance).PhysicalLine = 0;
Plugin(Distance).PhysicalSurface = 0;
Plugin(Distance).DistanceType = 0;
Plugin(Distance).Run;
Plugin(Distance).PhysicalSurface = 1;
Plugin(Distance).Run;
Plugin(Distance).PhysicalSurface = 0;
NewModel;
Point(1) = {0, 0, 0, 0.25}; Point(2) = {1, 0, 0, 0.25}; Point(3) = {0, 1, 0, 0.25};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 1};
Curve Loop(1) = {1, 2, 3}; Plane Surface(1) = {1};
Physical Point(1) = {1};
Mesh 2;
Plugin(Distance).PhysicalPoint = 1;
Plugin(Distance).Run;
