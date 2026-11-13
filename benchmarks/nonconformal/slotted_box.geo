// Non-conformal refinement of the surface mesh of a box with a slot
//
// A thin box (5 m x 2 m x 2 m) with a 3 m x 2 mm slot on its top face, as in
// the shielding effectiveness study of A. Touzalin's thesis (2025). The surface
// is first meshed with triangles of about 25 cm (lambda/12 at 100 MHz), graded
// down to the width of the slot at its ends only.
// Plugin(NonConformalRefinement) then refines the elements in nested
// rectangular zones around the slot, each 2 elements wide, from elements of
// about 2 mm (h / 2^7) next to the slot to elements smaller than h, their size
// growing by `jump' from one zone to the next. The elements next to finer ones,
// which have hanging nodes, become polygons (in red); nothing constrains the
// levels of neighboring elements (`Balance' is 0). By default the sizes are
// evaluated on a grid of points of the elements, corners included, at most the
// width of the slot apart (`SampleSpacing'), so that no coarse element touches
// the slot: near the zones, the sizes then grow by 2 from one row of elements
// to the next. With `spacing' = 0, they are only evaluated at the middle of the
// edges and at the centre of the elements: the zones then end with the jumps
// of sizes, but coarse elements can touch the slot. With jump = 4, the zones
// have elements of 2, 8, 31 and 125 mm, up to 4, 20, 82 and 332 mm from the
// slot.

jump = DefineNumber[4, Name "Parameters/Size jump between zones",
                    Choices{2 = "2", 4 = "4", 8 = "8", 16 = "16"}];
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

// the nested boxes around the slot, of levels 7, 7 - k, 7 - 2 k... down to 1,
// with jump = 2^k, each extending 2 of its elements beyond the previous one (an
// element is refined while its longest edge is larger than the size, hence the
// factor 1.4 on the sizes h / 2^l of the levels, and the size 1.5 h away from
// the slot, which keeps the conforming mesh there)
k = Round(Log(jump) / Log(2));
zones = 0;
d = 0;
For l In {7:1:-k}
  i = zones;
  d += 2 * h / 2^l;
  Field[10 + i] = Box;
  Field[10 + i].VIn = 1.4 * h / 2^l;
  Field[10 + i].VOut = 1.5 * h;
  Field[10 + i].XMin = 1 - d;
  Field[10 + i].XMax = 4 + d;
  Field[10 + i].YMin = y0 - d;
  Field[10 + i].YMax = y0 + w + d;
  Field[10 + i].ZMin = 1.9;
  Field[10 + i].ZMax = 2.1;
  zones++;
EndFor
Field[20] = Min;
Field[20].FieldsList = {10:10 + zones - 1};

Plugin(NonConformalRefinement).SizeField = 20;
Plugin(NonConformalRefinement).MaxLevel = 8;
Plugin(NonConformalRefinement).Balance = 0;
Plugin(NonConformalRefinement).SampleSpacing = spacing;
Plugin(NonConformalRefinement).Run;

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
