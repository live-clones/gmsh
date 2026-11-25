// Non-conformal refinement of the surface mesh of a box (5 m x 2 m x 2 m) with
// a 3 m x 2 mm slot on its top face: Plugin(NonConformalRefinement) refines
// the 25 cm triangles down to 2 mm around the slot, given by a single size
// field, and grades the sizes away from it: neighbors differ by at most
// `levels' levels of refinement (their sizes by 2^levels); the elements with
// hanging nodes become polygons (in red). With a positive `spacing' the field
// is sampled on a grid of each element: none touching the slot stays coarse.

levels = DefineNumber[2, Name "Parameters/Level difference between neighbors",
                      Choices{0 = "0 (no limit)", 1 = "1", 2 = "2", 3 = "3",
                              4 = "4"}];
spacing = DefineNumber[0.002, Name "Parameters/Sample spacing",
                       Choices{0 = "0 (centre and edge midpoints)",
                               0.002 = "2 mm (width of the slot)",
                               0.008 = "8 mm", 0.032 = "3.2 cm"}];

h = 0.25; // mesh size away from the slot
w = 0.002; // width of the slot
y0 = 2 - 0.424 - w; // position of the slot

// the faces of the box, with the slot as a hole in the top one
Point(1) = {0, 0, 0}; Point(2) = {5, 0, 0}; Point(3) = {5, 2, 0};
Point(4) = {0, 2, 0}; Point(5) = {0, 0, 2}; Point(6) = {5, 0, 2};
Point(7) = {5, 2, 2}; Point(8) = {0, 2, 2};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 1};
Line(5) = {5, 6}; Line(6) = {6, 7}; Line(7) = {7, 8}; Line(8) = {8, 5};
Line(9) = {1, 5}; Line(10) = {2, 6}; Line(11) = {3, 7}; Line(12) = {4, 8};
Point(9) = {1, y0, 2}; Point(10) = {4, y0, 2};
Point(11) = {4, y0 + w, 2}; Point(12) = {1, y0 + w, 2};
Line(13) = {9, 10}; Line(14) = {10, 11}; Line(15) = {11, 12};
Line(16) = {12, 9};
Curve Loop(1) = {1, 2, 3, 4}; Plane Surface(1) = {1};
Curve Loop(2) = {5, 6, 7, 8}; Curve Loop(7) = {13, 14, 15, 16};
Plane Surface(2) = {2, 7};
Curve Loop(3) = {1, 10, -5, -9}; Plane Surface(3) = {3};
Curve Loop(4) = {2, 11, -6, -10}; Plane Surface(4) = {4};
Curve Loop(5) = {3, 12, -7, -11}; Plane Surface(5) = {5};
Curve Loop(6) = {4, 9, -8, -12}; Plane Surface(6) = {6};

// the conforming mesh: h, graded down to the width of the slot at its ends
Field[1] = Distance;
Field[1].PointsList = {9, 10, 11, 12};
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

// the size field: h / 2^7 up to 2 such elements from the slot, and a size
// that keeps the mesh elsewhere (an element is refined while its longest edge
// is larger than the size, hence the factors 1.4 and 1.5)
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

// set up the view when the file is first opened only: changing a parameter
// then keeps the current one
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
