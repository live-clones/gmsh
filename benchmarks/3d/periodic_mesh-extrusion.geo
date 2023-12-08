// Periodic mesh created by rotational extrusion

L = 1.;
nPts = 8+1;

Mesh.PartitionOldStyleMsh2 = 1;
Mesh.PreserveNumberingMsh2 = 1;

Point(1) = {0, 0, 0};
Point(2) = {L, 0, 0};
Point(3) = {L, L, 0};
Point(4) = {0, L, 0};

Line (1) = {1, 2};
Line (2) = {2, 3};
Line (3) = {3, 4};
Line (4) = {4, 1};

Line Loop (10) = {1, 2, 3, 4};
Plane Surface (11) = {10};


Transfinite Curve {1:4} = nPts;
Transfinite Surface {11};
Recombine Surface {11};

Extrude { {1, 0, 0}, {0, -L/5., 0}, Pi/4. } { Surface{11}; Layers{nPts}; Recombine; }

Physical Volume ("domain") = {1};
Physical Surface ("periodic") = {11, 20, 24, 28, 32, 33};

Mesh 3;

// Periodic surfaces in extruded meshes must be defined AFTER meshing
Periodic Surface {33} = {11} Rotate { {1, 0, 0}, {0, -L/5., 0}, Pi/4. };

