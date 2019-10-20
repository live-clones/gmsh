// Tri-periodic cubic domain with structured mesh

L = 1.;
nPts = 8+1;

Mesh.PartitionOldStyleMsh2 = 1;
Mesh.PreserveNumberingMsh2 = 1;

Point(1) = {0, 0, 0};
Point(2) = {L, 0, 0};
Point(3) = {L, L, 0};
Point(4) = {0, L, 0};
Point(5) = {0, 0, L};
Point(6) = {L, 0, L};
Point(7) = {L, L, L};
Point(8) = {0, L, L};

Line (1) = {5, 6};
Line (2) = {6, 2};
Line (3) = {2, 1};
Line (4) = {1, 5};
Line (5) = {8, 7};
Line (6) = {7, 3};
Line (7) = {3, 4};
Line (8) = {4, 8};
Line (9) = {5, 8};
Line (10) = {6, 7};
Line (11) = {2, 3};
Line (12) = {1, 4};

Line Loop (114) = {5, -10, -1, 9};
Plane Surface (14) = {114};
Line Loop (116) = {8, 5, 6, 7};
Plane Surface (16) = {116};
Line Loop (118) = {4, 9, -8, -12};
Plane Surface (18) = {118};
Line Loop (120) = {2, 11, -6, -10};
Plane Surface (20) = {120};
Line Loop (122) = {3, 12, -7, -11};
Plane Surface (22) = {122};
Line Loop (124) = {4, 1, 2, 3};
Plane Surface (24) = {124};

Surface Loop (1001) = {14, 16, 18, 20, 22, 24};
Volume (1) = {1001};

Transfinite Curve {1:12} = nPts;
Transfinite Surface {:};
Recombine Surface {:};
Transfinite Volume {:};

Physical Volume ("domain") = {1};
Physical Surface ("periodic") = {14, 16, 18, 20, 22, 24};

Mesh 3;

// Periodic surfaces in structured meshes must be defined AFTER meshing
Periodic Surface {20} = {18} Translate {L, 0, 0};
Periodic Surface {16} = {24} Translate {0, L, 0};
Periodic Surface {14} = {22} Translate {0, 0, L};

