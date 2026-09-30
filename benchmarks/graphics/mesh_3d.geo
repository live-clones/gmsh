// 3D mesh: a box with a spherical cavity, and a second box meshed with
// hexahedra, prisms and pyramids
SetFactory("OpenCASCADE");
DefineConstant[ N = 1 ];
Box(1) = {0, 0, 0, 1, 1, 1};
Sphere(2) = {0.5, 0.5, 0.5, 0.3};
BooleanDifference{ Volume{1}; Delete; }{ Volume{2}; Delete; }
Box(3) = {1.5, 0, 0, 1, 1, 1};
c[] = Curve In BoundingBox{1.4, -0.1, -0.1, 2.6, 1.1, 1.1};
s[] = Surface In BoundingBox{1.4, -0.1, -0.1, 2.6, 1.1, 1.1};
Transfinite Curve{c[]} = 4 * N + 1;
Transfinite Surface{s[]};
Recombine Surface{s[]};
Transfinite Volume{3};
Mesh.MeshSizeMax = 0.15 / N;
Mesh.SubdivisionAlgorithm = 0;
Mesh 3;
General.Trackball = 0;
General.RotationX = 300; General.RotationZ = 30;
