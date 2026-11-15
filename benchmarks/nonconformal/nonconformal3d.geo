// Non-conformal refinement in 3D, with polyhedra at the hanging nodes
//
// A dome meshed with tetrahedra sits on a cylinder meshed with hexahedra, with
// pyramids at their interface. Plugin(NonConformalRefinement) refines this
// mixed mesh in a thin band around a spherical front crossing both parts. A
// single size field says where the small elements are; the plugin grades the
// sizes away from them: the elements sharing an edge differ by at most
// `levels' levels of refinement (`MaxLevelDifference'), i.e. their sizes by a
// factor 2^levels, with up to 2^levels - 1 hanging nodes on the edge (no limit
// if 0). The elements next to finer ones, which have hanging nodes, become
// polyhedra (in red). By default the sizes are only evaluated at the middle of
// the edges and at the centre of the elements (`SampleSpacing' is 0), and an
// element only partly in the band can stay coarse; with a positive `spacing',
// they are evaluated on a grid of points of the elements at most `spacing'
// apart: all the elements touching the band are then refined. The new nodes on
// the boundary are placed on the geometry. A clipping plane shows the layer of
// elements it cuts.

levels = DefineNumber[2, Name "Parameters/Level difference between neighbors",
                      Choices{0 = "0 (no limit)", 1 = "1", 2 = "2", 3 = "3"}];
spacing = DefineNumber[0, Name "Parameters/Sample spacing",
                       Choices{0 = "0 (centre and edge midpoints)",
                               0.025 = "2.5 cm (size in the band)",
                               0.05 = "5 cm", 0.1 = "10 cm"}];

SetFactory("OpenCASCADE");

// the dome, whose base is meshed with quadrangles...
Sphere(1) = {0, 0, 1, 1, 0, Pi/2, 2*Pi};
base() = Surface In BoundingBox{-1.1, -1.1, 0.99, 1.1, 1.1, 1.01};
Recombine Surface{base()};
MeshAlgorithm Surface{base()} = 8;

// ... extruded downwards into hexahedra
Extrude{0, 0, -1}{ Surface{base()}; Layers{5}; Recombine; }

h = 0.3;
Mesh.MeshSizeMax = h;
Mesh 3;

// the size field: 2.5 cm in a band of 2.5 cm on each side of a sphere crossing
// the cylinder and the dome, the size of the mesh elsewhere
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

// set up the view when the file is first opened only, so that changing a
// parameter keeps the current one
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
  General.ClipOnlyDrawIntersectingVolume = 1;
  General.TrackballQuaternion0 = 0.564863;
  General.TrackballQuaternion1 = 0.099601;
  General.TrackballQuaternion2 = 0.142244;
  General.TrackballQuaternion3 = 0.806707;
  SetNumber["Parameters/View set", 1];
EndIf
