// Non-conformal refinement in 3D, with polyhedra at the hanging nodes
//
// A dome meshed with tetrahedra sits on a cylinder meshed with hexahedra, with
// pyramids at their interface. Plugin(NonConformalRefinement) refines this
// mixed mesh around a spherical front crossing both parts, where the sizes
// jump by `jump' at the edges of a thin band. The elements next to finer ones,
// which have hanging nodes, become polyhedra (in red); nothing constrains the
// levels of neighboring elements (`Balance' is 0). By default the sizes are
// only evaluated at the middle of the edges and at the centre of the elements
// (`SampleSpacing' is 0), and an element only partly in the band can stay
// coarse; with a positive `spacing', they are evaluated on a grid of points of
// the elements at most `spacing' apart: all the elements touching the band are
// then refined, and the sizes only jump where the field does, at the edges of
// the band. The new nodes on the boundary are placed on the geometry. A
// clipping plane shows the layer of elements it cuts.

jump = DefineNumber[8, Name "Parameters/Size jump at the front",
                    Choices{2 = "2", 4 = "4", 8 = "8", 16 = "16"}];
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

Mesh.MeshSizeMax = 0.3;
Mesh 3;

// refine around a spherical front crossing the cylinder and the dome: 2.5 cm
// in a band of 2.5 cm on each side of the sphere, jumping by `jump' outside it
// and growing to the size of the mesh further away
fine = 0.025;
Field[2] = MathEval;
Field[2].F = "Abs(Sqrt((x + 1.2)^2 + y^2 + (z + 0.2)^2) - 2)";
Field[3] = Threshold;
Field[3].InField = 2;
Field[3].SizeMin = fine;
Field[3].SizeMax = jump * fine;
Field[3].DistMin = fine;
Field[3].DistMax = fine + 1e-5;
Field[3].StopAtDistMax = 1;
Field[4] = MathEval;
Field[4].F = Sprintf(
  "%g + 0.5 * Abs(Sqrt((x + 1.2)^2 + y^2 + (z + 0.2)^2) - 2)", jump * fine);
Field[1] = Min;
Field[1].FieldsList = {3, 4};

Plugin(NonConformalRefinement).SizeField = 1;
Plugin(NonConformalRefinement).MaxLevel = 8;
Plugin(NonConformalRefinement).Balance = 0;
Plugin(NonConformalRefinement).SampleSpacing = spacing;
Plugin(NonConformalRefinement).OnGeometry = 1;
Plugin(NonConformalRefinement).Run;

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
