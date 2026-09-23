// Plugin(DiscretizationError): distance from supersampled triangles and
// quadrangles to a curved surface of revolution, and to a plane (zero)

Point(1) = {1, 0, 0, 0.5};
Point(2) = {0, 0, 0, 0.5};
Point(3) = {0, 0, 1, 0.5};
Circle(1) = {1, 2, 3}; // quarter circle in the xz plane
Extrude {{0, 0, 1}, {0, 0, 0}, Pi / 2} { Curve{1}; } // eighth of a sphere
Point(10) = {2, 0, 0, 0.5};
Point(11) = {3, 0, 0, 0.5};
Point(12) = {3, 1, 0, 0.5};
Line(10) = {10, 11}; Line(11) = {11, 12}; Line(12) = {12, 10};
Curve Loop(10) = {10, 11, 12};
Plane Surface(10) = {10};
Mesh 2;
Plugin(DiscretizationError).SuperSamplingNodes = 4;
Plugin(DiscretizationError).Run;

Delete Meshes;
Mesh.RecombineAll = 1;
Mesh 2;
Plugin(DiscretizationError).SuperSamplingNodes = 3;
Plugin(DiscretizationError).Run;
