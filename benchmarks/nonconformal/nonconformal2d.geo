// Non-conformal refinement in 2D: Plugin(NonConformalRefinement) refines a
// mesh of triangles and quadrangles in a thin band, given by a single size
// field, and grades the sizes away from it: neighbors differ by at most
// `levels' levels of refinement (their sizes by 2^levels); the elements with
// hanging nodes become polygons (in red). With a positive `spacing' the field
// is sampled on a grid of each element: none touching the band stays coarse.

levels = DefineNumber[2, Name "Parameters/Level difference between neighbors",
                      Choices{0 = "0 (no limit)", 1 = "1", 2 = "2", 3 = "3",
                              4 = "4"}];
spacing = DefineNumber[0, Name "Parameters/Sample spacing",
                       Choices{0 = "0 (centre and edge midpoints)",
                               0.0015 = "1.5 mm (size in the band)",
                               0.006 = "6 mm", 0.024 = "2.4 cm"}];

// a plate split in two, with three holes
Point(1) = {0, 0, 0}; Point(2) = {1, 0, 0}; Point(3) = {2, 0, 0};
Point(4) = {2, 1, 0}; Point(5) = {1, 1, 0}; Point(6) = {0, 1, 0};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 5};
Line(5) = {5, 6}; Line(6) = {6, 1}; Line(7) = {2, 5};
cx() = {0.45, 1.5, 1.25}; cy() = {0.3, 0.65, 0.2}; cr() = {0.12, 0.18, 0.07};
For i In {0:2}
  p = newp; l = newc;
  Point(p) = {cx(i), cy(i), 0};
  Point(p + 1) = {cx(i) + cr(i), cy(i), 0};
  Point(p + 2) = {cx(i), cy(i) + cr(i), 0};
  Point(p + 3) = {cx(i) - cr(i), cy(i), 0};
  Point(p + 4) = {cx(i), cy(i) - cr(i), 0};
  Circle(l) = {p + 1, p, p + 2}; Circle(l + 1) = {p + 2, p, p + 3};
  Circle(l + 2) = {p + 3, p, p + 4}; Circle(l + 3) = {p + 4, p, p + 1};
  Curve Loop(10 + i) = {l, l + 1, l + 2, l + 3};
EndFor
Curve Loop(1) = {1, 7, 5, 6}; Plane Surface(1) = {1, 10};
Curve Loop(2) = {2, 3, 4, -7}; Plane Surface(2) = {2, 11, 12};

// triangles on the left, quadrangles on the right
Recombine Surface{2};
MeshAlgorithm Surface{2} = 8;
h = 0.1;
Mesh.MeshSizeMax = h;
Mesh 2;

// the size field: 1.5 mm within 6 mm of a circle, the mesh size elsewhere
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

// set up the view when the file is first opened only: changing a parameter
// then keeps the current one
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
