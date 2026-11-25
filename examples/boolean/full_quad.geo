// create geometry with some mesh sizes on boundaries
SetFactory("OpenCASCADE");
Rectangle(1) = {0,0,0, 10,10};
Rectangle(2) = {2,4,0, 2,1};
Rectangle(3) = {5,5,0, 1,2};
Rectangle(4) = {2,6,0, 1,1};
Rectangle(5) = {7,2,0, 2,2};
Rotate {{0, 0, 1}, {5, 5, 0}, Pi/4} { Surface{3}; }
Rotate {{0, 0, 1}, {2, 6, 0}, Pi/3} { Surface{4}; }
MeshSize{ PointsOf{ Surface{1}; } } = 0.5;
MeshSize{ PointsOf{ Surface{2:5}; } } = 0.05;
BooleanDifference{ Surface{1}; Delete; }{ Surface{2:5}; Delete; }

// replace default mesh size interpolation with "Extend" field, to decrease
// sizes smoothly away from boundaries
Mesh.MeshSizeExtendFromBoundary = 0;
Field[1] = Extend;
Field[1].SurfacesList = {Surface{:}};
Field[1].SizeMax = 0.5;
Field[1].Ratio = 1.2;
Background Field = 1;

// recombine triangular mesh into quads
Recombine Surface{:};

// use frontal-Delaunay for quads
Mesh.Algorithm = 8;
// use simple full-quad (fast) or blossom full-quad (more expensive) to
// guarantee full-quad mesh by subdivision
Mesh.RecombinationAlgorithm = 3; // or 2
