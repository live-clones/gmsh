// Two boxes glued into a conformal multi-domain model via fragment(): MMG3D
// used to fail on the second (empty) region here.
// Exercises the combined single-call MMG3D path.
SetFactory("OpenCASCADE");
Box(1) = {0, 0, 0, 1, 1, 1};
Box(2) = {1, 0, 0, 1, 1, 1};
BooleanFragments{ Volume{1}; Delete; }{ Volume{2}; Delete; }

Mesh.MeshSizeMin = 0.3;
Mesh.MeshSizeMax = 0.3;
Mesh.Algorithm3D = 7; // MMG3D
Mesh.MMG3DCombineDomains = 1;
