// Non-conformal refinement in 2D, with polygons at the hanging nodes
//
// A plate with holes, meshed with triangles on the left and quadrangles on
// the right, is refined with Plugin(NonConformalRefinement) in a thin band
// around a circular front. A single size field says where the small elements
// are; the plugin grades the sizes away from them: the elements sharing an
// edge differ by at most `levels' levels of refinement (`MaxLevelDifference'),
// i.e. their sizes by a factor 2^levels, with up to 2^levels - 1 hanging nodes
// on the edge (no limit if 0). The elements next to finer ones, which have
// hanging nodes, become polygons (in red). By default the sizes are only
// evaluated at the middle of the edges and at the centre of the elements
// (`SampleSpacing' is 0), and an element only partly in the band can stay
// coarse; with a positive `spacing', they are evaluated on a grid of points of
// the elements at most `spacing' apart: all the elements touching the band are
// then refined. The new nodes on the holes are placed on the geometry.

levels = DefineNumber[2, Name "Parameters/Level difference between neighbors",
                      Choices{0 = "0 (no limit)", 1 = "1", 2 = "2", 3 = "3",
                              4 = "4"}];
spacing = DefineNumber[0, Name "Parameters/Sample spacing",
                       Choices{0 = "0 (centre and edge midpoints)",
                               0.0015 = "1.5 mm (size in the band)",
                               0.006 = "6 mm", 0.024 = "2.4 cm"}];

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
h = 0.1;
Mesh.MeshSizeMax = h;
Mesh 2;

// the size field: 1.5 mm in a band of 6 mm on each side of a circle crossing
// both meshes and two of the holes, the size of the mesh elsewhere
fine = 0.0015;
Field[1] = MathEval;
Field[1].F = "Abs(Sqrt((x - 0.95)^2 + (y - 0.5)^2) - 0.4)";
Field[2] = Threshold;
Field[2].InField = 1;
Field[2].SizeMin = fine;
Field[2].SizeMax = h;
Field[2].DistMin = 0.006;
Field[2].DistMax = 0.00601;

Plugin(NonConformalRefinement).SizeField = 2;
Plugin(NonConformalRefinement).MaxLevel = 8;
Plugin(NonConformalRefinement).MaxLevelDifference = levels;
Plugin(NonConformalRefinement).SampleSpacing = spacing;
Plugin(NonConformalRefinement).OnGeometry = 1;
Plugin(NonConformalRefinement).Run;

// set up the view when the file is first opened only, so that changing a
// parameter keeps the current one
DefineConstant[ viewSet = {0, Name "Parameters/View set", Visible 0} ];
If(!viewSet)
  // color the elements by type
  Geometry.Points = 0;
  Geometry.Curves = 0;
  Mesh.SurfaceFaces = 1;
  Mesh.ColorCarousel = 0;
  Mesh.Color.Triangles = {160, 200, 240};
  Mesh.Color.Quadrangles = {170, 220, 160};
  Mesh.Color.Polygons = {240, 110, 90};
  SetNumber["Parameters/View set", 1];
EndIf
