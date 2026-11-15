// The dual of a 2D mesh of triangles and quadrangles, made of polygons:
// Plugin(DualMesh) replaces each node by the polygon around it. With `voronoi'
// set, the triangles are represented by their circumcentres and the polygons
// are the Voronoi cells of the nodes where the mesh is Delaunay.

voronoi = DefineNumber[0, Name "Parameters/Voronoi", Choices{0, 1}];

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
  MeshSize{p + 1, p + 2, p + 3, p + 4} = 2 * Pi * cr(i) / 24;
EndFor
Curve Loop(1) = {1, 7, 5, 6}; Plane Surface(1) = {1, 10};
Curve Loop(2) = {2, 3, 4, -7}; Plane Surface(2) = {2, 11, 12};

// triangles on the left, quadrangles on the right, finer near the holes
Recombine Surface{2};
MeshAlgorithm Surface{2} = 8;
Mesh.MeshSizeMax = 0.08;
Mesh 2;

Plugin(DualMesh).Voronoi = voronoi;
Plugin(DualMesh).Run;

// set up the view when the file is first opened only: changing a parameter
// then keeps the current one
DefineConstant[ viewSet = {0, Name "Parameters/View set", Visible 0} ];
If(!viewSet)
  Geometry.Points = 0;
  Geometry.Curves = 0;
  Mesh.SurfaceFaces = 1;
  SetNumber["Parameters/View set", 1];
EndIf
