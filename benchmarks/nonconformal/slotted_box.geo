// Non-conformal refinement of the surface mesh of a box with a slot
//
// A thin box (5 m x 2 m x 2 m) with a 3 m x 2 mm slot on its top face, as in
// the shielding effectiveness study of A. Touzalin's thesis (2025). The surface
// is first meshed with triangles of about 25 cm (lambda/12 at 100 MHz), graded
// down to the width of the slot at its ends only.
// Plugin(NonConformalRefinement) then refines the elements around the slot,
// down to about 2 mm (h / 2^7). A single size field says where the small
// elements are, in a box around the slot; the plugin grades the sizes away
// from them: the elements sharing an edge differ by at most `levels' levels of
// refinement (`MaxLevelDifference'), i.e. their sizes by a factor 2^levels,
// with up to 2^levels - 1 hanging nodes on the edge (no limit if 0). The
// elements next to finer ones, which have hanging nodes, become polygons (in
// red). By default the sizes are evaluated on a grid of points of the
// elements, corners included, at most the width of the slot apart
// (`SampleSpacing'), so that no coarse element touches the slot. With
// `spacing' = 0, they are only evaluated at the middle of the edges and at the
// centre of the elements, and coarse elements can touch the slot.

levels = DefineNumber[2, Name "Parameters/Level difference between neighbors",
                      Choices{0 = "0 (no limit)", 1 = "1", 2 = "2", 3 = "3",
                              4 = "4"}];
spacing = DefineNumber[0.002, Name "Parameters/Sample spacing",
                       Choices{0 = "0 (centre and edge midpoints)",
                               0.002 = "2 mm (width of the slot)",
                               0.008 = "8 mm", 0.032 = "3.2 cm"}];

SetFactory("OpenCASCADE");

h = 0.25; // mesh size away from the slot
w = 0.002; // width of the slot
y0 = 2 - 0.424 - w; // position of the slot

// the faces of the box, with the slot cut out of the top one
Box(1) = {0, 0, 0, 5, 2, 2};
Delete{ Volume{1}; }
Rectangle(7) = {1, y0, 2, 3, w};
BooleanFragments{ Surface{1:6}; Delete; }{ Surface{7}; Delete; }
slot() = Surface In BoundingBox{0.99, 1.5, 1.99, 4.01, 1.6, 2.01};
slotPoints() = PointsOf{ Surface{slot()}; };
Delete{ Surface{slot()}; }

// the conforming mesh: h, graded down to the width of the slot at its ends
Field[1] = Distance;
Field[1].PointsList = {slotPoints()};
Field[2] = Threshold;
Field[2].InField = 1;
Field[2].SizeMin = w;
Field[2].SizeMax = h;
Field[2].DistMin = 2 * w;
Field[2].DistMax = 2 * h;
Background Field = 2;
Mesh.MeshSizeFromPoints = 0;
Mesh.MeshSizeExtendFromBoundary = 0;
Mesh 2;

// the size field: h / 2^7 in a box extending 2 such elements beyond the slot,
// and a size that keeps the conforming mesh elsewhere (an element is refined
// while its longest edge is larger than the size, hence the factors 1.4 and
// 1.5)
d = 2 * h / 2^7;
Field[3] = Box;
Field[3].VIn = 1.4 * h / 2^7;
Field[3].VOut = 1.5 * h;
Field[3].XMin = 1 - d;
Field[3].XMax = 4 + d;
Field[3].YMin = y0 - d;
Field[3].YMax = y0 + w + d;
Field[3].ZMin = 1.9;
Field[3].ZMax = 2.1;

Plugin(NonConformalRefinement).SizeField = 3;
Plugin(NonConformalRefinement).MaxLevel = 8;
Plugin(NonConformalRefinement).MaxLevelDifference = levels;
Plugin(NonConformalRefinement).SampleSpacing = spacing;
Plugin(NonConformalRefinement).Run;

// set up the view when the file is first opened only, so that changing a
// parameter keeps the current one
DefineConstant[ viewSet = {0, Name "Parameters/View set", Visible 0} ];
If(!viewSet)
  // color the elements by type (the edges take the color of their element when
  // the faces are not shown)
  Geometry.Points = 0;
  Geometry.Curves = 0;
  Mesh.SurfaceFaces = 1;
  Mesh.ColorCarousel = 0;
  Mesh.Color.Triangles = {235, 228, 215};
  Mesh.Color.Polygons = {240, 110, 90};
  General.TrackballQuaternion0 = 0.482963;
  General.TrackballQuaternion1 = 0.129410;
  General.TrackballQuaternion2 = 0.224144;
  General.TrackballQuaternion3 = 0.836516;
  SetNumber["Parameters/View set", 1];
EndIf
