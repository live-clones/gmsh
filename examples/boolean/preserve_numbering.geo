SetFactory("OpenCASCADE");

// With Geometry.OCCBooleanPreserveNumbering = 2, the entities on the boundary
// of the arguments of boolean operations keep their tags when they are left
// unchanged or modified into a single entity: physical groups and mesh
// constraints can be defined on the original entities, before the boolean
// operations, and remain valid after them
Geometry.OCCBooleanPreserveNumbering = 2;

// a plate, whose surfaces 1 to 6 are the faces x = 0, x = 4, y = 0, y = 2,
// z = 0 and z = 0.5
Box(1) = {0, 0, 0, 4, 2, 0.5};

// a hole, whose wall will be the lateral surface (7) of a cylinder
Cylinder(2) = {3, 1, -0.1, 0, 0, 0.7, 0.4};

// a rib, whose top will be the face z = 1 (15) of a box
Box(3) = {0, 0.9, 0.5, 2.5, 0.2, 0.5};

// physical groups and mesh constraints on the original entities
Physical Surface("clamped", 1) = {1};
Physical Surface("loaded", 2) = {2};
Physical Surface("hole", 3) = {7};
Physical Surface("rib top", 4) = {15};
Transfinite Curve{ Boundary{ Surface{2}; } } = 9;
Transfinite Surface{2};
MeshSize{ PointsOf{ Surface{1}; } } = 0.05;

// the boolean operations keep them valid: the clamped face now includes the end
// of the rib
BooleanDifference{ Volume{1}; Delete; }{ Volume{2}; Delete; }
v() = BooleanUnion{ Volume{1}; Delete; }{ Volume{3}; Delete; };

// the volume of the union is a new one
Physical Volume("solid", 5) = {v()};

Mesh.MeshSizeMax = 0.2;
