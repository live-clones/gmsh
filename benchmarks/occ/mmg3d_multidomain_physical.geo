// Same multi-domain model as mmg3d_multidomain_combined.geo, but with
// distinct Physical Volume tags on each region: checks that per-tet MMG3D
// region routing does not interfere with (and does not depend on) physical
// group assignment.
SetFactory("OpenCASCADE");
Box(1) = {0, 0, 0, 1, 1, 1};
Box(2) = {1, 0, 0, 1, 1, 1};
BooleanFragments{ Volume{1}; Delete; }{ Volume{2}; Delete; }

Physical Volume("matA") = {1};
Physical Volume("matB") = {2};

Mesh.MeshSizeMin = 0.3;
Mesh.MeshSizeMax = 0.3;
Mesh.Algorithm3D = 7; // MMG3D
