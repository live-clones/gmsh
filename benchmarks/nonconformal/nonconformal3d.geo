// Non-conformal refinement in 3D: Plugin(NonConformalRefinement) refines a
// mesh of tetrahedra, pyramids and hexahedra in a thin band, given by a single
// size field, and grades the sizes away from it: neighbors differ by at most
// `levels' levels of refinement (their sizes by 2^levels); the elements with
// hanging nodes become polyhedra (in red). With a positive `spacing' the field
// is sampled on a grid of each element: none touching the band stays coarse.

levels = DefineNumber[2, Name "Parameters/Level difference between neighbors",
                      Choices{0 = "0 (no limit)", 1 = "1", 2 = "2", 3 = "3"}];
spacing = DefineNumber[0, Name "Parameters/Sample spacing",
                       Choices{0 = "0 (centre and edge midpoints)",
                               0.025 = "2.5 cm (size in the band)",
                               0.05 = "5 cm", 0.1 = "10 cm"}];

// a dome, whose base is meshed with quadrangles...
Point(1) = {0, 0, 1}; Point(2) = {1, 0, 1}; Point(3) = {0, 1, 1};
Point(4) = {-1, 0, 1}; Point(5) = {0, -1, 1}; Point(6) = {0, 0, 2};
Circle(1) = {2, 1, 3}; Circle(2) = {3, 1, 4};
Circle(3) = {4, 1, 5}; Circle(4) = {5, 1, 2};
Circle(5) = {2, 1, 6}; Circle(6) = {3, 1, 6};
Circle(7) = {4, 1, 6}; Circle(8) = {5, 1, 6};
Curve Loop(1) = {1, 2, 3, 4}; Plane Surface(1) = {1};
Curve Loop(2) = {1, 6, -5}; Surface(2) = {2};
Curve Loop(3) = {2, 7, -6}; Surface(3) = {3};
Curve Loop(4) = {3, 8, -7}; Surface(4) = {4};
Curve Loop(5) = {4, 5, -8}; Surface(5) = {5};
Surface Loop(1) = {1, 2, 3, 4, 5}; Volume(1) = {1};
Recombine Surface{1};
MeshAlgorithm Surface{1} = 8;

// ... extruded downwards into hexahedra
Extrude{0, 0, -1}{ Surface{1}; Layers{5}; Recombine; }

h = 0.3;
Mesh.MeshSizeMax = h;
Mesh 3;

// the size field: 2.5 cm within 2.5 cm of a sphere, the mesh size elsewhere
fine = 0.025;
Field[1] = MathEval;
Field[1].F = "Abs(Sqrt((x + 1.2)^2 + y^2 + (z + 0.2)^2) - 2)";
Field[2] = Threshold;
Field[2].InField = 1;
Field[2].SizeMin = fine;
Field[2].SizeMax = h;
Field[2].DistMin = fine;
Field[2].DistMax = fine + 1e-5;

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
  // show the elements cut by the plane y = 0, colored by type
  Geometry.Points = 0;
  Geometry.Curves = 0;
  Geometry.Surfaces = 0;
  Mesh.SurfaceFaces = 0;
  Mesh.SurfaceEdges = 0;
  Mesh.VolumeFaces = 1;
  Mesh.VolumeEdges = 1;
  Mesh.ColorCarousel = 0;
  Mesh.Color.Tetrahedra = {160, 200, 240};
  Mesh.Color.Hexahedra = {170, 220, 160};
  Mesh.Color.Pyramids = {200, 160, 230};
  Mesh.Color.Polyhedra = {240, 110, 90};
  General.Clip0A = 0;
  General.Clip0B = 1;
  General.Clip0C = 0;
  General.Clip0D = 0;
  Mesh.Clip = 1;
  General.ClipWholeElements = 1;
  General.TrackballQuaternion0 = 0.564863;
  General.TrackballQuaternion1 = 0.099601;
  General.TrackballQuaternion2 = 0.142244;
  General.TrackballQuaternion3 = 0.806707;
  SetNumber["Parameters/View set", 1];
EndIf
