// Same multi-domain model as mmg3d_multidomain_combined.geo, but exercising
// the per-region MMG3D path (Mesh.MMG3DCombineDomains = 0): each region is
// classified then meshed with its own independent MMG3D call.
SetFactory("OpenCASCADE");
Box(1) = {0, 0, 0, 1, 1, 1};
Box(2) = {1, 0, 0, 1, 1, 1};
BooleanFragments{ Volume{1}; Delete; }{ Volume{2}; Delete; }

Mesh.MeshSizeMin = 0.3;
Mesh.MeshSizeMax = 0.3;
Mesh.Algorithm3D = 7; // MMG3D
Mesh.MMG3DCombineDomains = 0;
