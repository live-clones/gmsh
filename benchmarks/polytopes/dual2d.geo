// The barycentric dual of a 2D mesh, made of polygons
//
// A plate with holes, meshed with triangles on the left and quadrangles on
// the right, is replaced by its barycentric dual with Plugin(DualMesh): each
// node becomes a polygon whose vertices are the centres of the elements and
// the middles of the edges around it, and the node itself on the boundary.
// The polygons are subdivided into the triangles of the barycentric
// subdivision of the elements. With `voronoi' set, the triangles are
// represented by their circumcentres, and the polygons are the Voronoi cells
// of the nodes where the mesh is Delaunay.

voronoi = DefineNumber[0, Name "Parameters/Voronoi", Choices{0, 1}];

SetFactory("OpenCASCADE");

Rectangle(1) = {0, 0, 0, 1, 1};
Rectangle(2) = {1, 0, 0, 1, 1};
Disk(3) = {0.45, 0.3, 0, 0.12};
Disk(4) = {1.5, 0.65, 0, 0.18};
Disk(5) = {1.25, 0.2, 0, 0.07};
BooleanDifference{ Surface{1, 2}; Delete; }{ Surface{3:5}; Delete; }
BooleanFragments{ Surface{:}; Delete; }{}

// triangles on the left, quadrangles on the right, finer near the holes
s() = Surface In BoundingBox{0.99, -1, -1, 3, 2, 1};
Recombine Surface{s()};
MeshAlgorithm Surface{s()} = 8;
Mesh.MeshSizeMax = 0.08;
Mesh.MeshSizeFromCurvature = 24;
Mesh 2;

Plugin(DualMesh).Voronoi = voronoi;
Plugin(DualMesh).Run;

Geometry.Points = 0;
Geometry.Curves = 0;
Mesh.SurfaceFaces = 1;
