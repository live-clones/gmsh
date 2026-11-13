// Non-conformal refinement in 2D, with polygons at the hanging nodes
//
// A plate with holes, meshed with triangles on the left and quadrangles on
// the right, is refined with Plugin(NonConformalRefinement) around a circular
// front, where the sizes jump by `jump' at the edges of a thin band, and near
// the holes. The elements next to finer ones, which have hanging nodes, become
// polygons (in red); nothing constrains the levels of neighboring elements
// (`Balance' is 0), and the sizes are only evaluated at the middle of the edges
// and at the centre of the elements (`SampleCorners' is 0), so that the jumps
// are kept. The new nodes on the holes are placed on the geometry.

jump = DefineNumber[16, Name "Parameters/Size jump at the front",
                    Choices{2 = "2", 4 = "4", 8 = "8", 16 = "16"}];

SetFactory("OpenCASCADE");

Rectangle(1) = {0, 0, 0, 1, 1};
Rectangle(2) = {1, 0, 0, 1, 1};
Disk(3) = {0.45, 0.3, 0, 0.12};
Disk(4) = {1.5, 0.65, 0, 0.18};
Disk(5) = {1.25, 0.2, 0, 0.07};
BooleanDifference{ Surface{1, 2}; Delete; }{ Surface{3:5}; Delete; }
BooleanFragments{ Surface{:}; Delete; }{}

// triangles on the left, quadrangles on the right
s() = Surface In BoundingBox{0.99, -1, -1, 3, 2, 1};
Recombine Surface{s()};
MeshAlgorithm Surface{s()} = 8;
Mesh.MeshSizeMax = 0.1;
Mesh 2;

// refine around a circular front crossing both meshes: 1.5 mm in a band of 6
// mm on each side of the circle, jumping by `jump' outside it and growing to
// the size of the mesh further away...
fine = 0.0015;
Field[5] = MathEval;
Field[5].F = "Abs(Sqrt((x - 0.95)^2 + (y - 0.5)^2) - 0.38)";
Field[6] = Threshold;
Field[6].InField = 5;
Field[6].SizeMin = fine;
Field[6].SizeMax = jump * fine;
Field[6].DistMin = 0.006;
Field[6].DistMax = 0.00601;
Field[6].StopAtDistMax = 1;
Field[7] = MathEval;
Field[7].F = Sprintf("%g + 0.5 * Abs(Sqrt((x - 0.95)^2 + (y - 0.5)^2) - 0.38)",
                     jump * fine);
Field[1] = Min;
Field[1].FieldsList = {6, 7};

// ... and near the holes
holes() = Curve In BoundingBox{0.01, 0.01, -1, 1.99, 0.99, 1};
Field[2] = Distance;
Field[2].CurvesList = {holes()};
Field[2].Sampling = 200;
Field[3] = Threshold;
Field[3].InField = 2;
Field[3].SizeMin = 0.012;
Field[3].SizeMax = 0.1;
Field[3].DistMin = 0;
Field[3].DistMax = 0.15;
Field[3].StopAtDistMax = 1;
Field[4] = Min;
Field[4].FieldsList = {1, 3};

Plugin(NonConformalRefinement).SizeField = 4;
Plugin(NonConformalRefinement).MaxLevel = 8;
Plugin(NonConformalRefinement).Balance = 0;
Plugin(NonConformalRefinement).SampleCorners = 0;
Plugin(NonConformalRefinement).OnGeometry = 1;
Plugin(NonConformalRefinement).Run;

// color the elements by type
Geometry.Points = 0;
Geometry.Curves = 0;
Mesh.SurfaceFaces = 1;
Mesh.ColorCarousel = 0;
Mesh.Color.Triangles = {160, 200, 240};
Mesh.Color.Quadrangles = {170, 220, 160};
Mesh.Color.Polygons = {240, 110, 90};
