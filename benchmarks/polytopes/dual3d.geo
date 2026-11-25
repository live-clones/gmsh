// The dual of a 3D mesh of tetrahedra, pyramids and hexahedra, made of
// polyhedra: Plugin(DualMesh) replaces each node by the polyhedron around it.
// With `voronoi' set, the tetrahedra are represented by their circumcentres
// and the polyhedra are the Voronoi cells of the nodes where the mesh is
// Delaunay, which optimizing the tetrahedra (`optimize') breaks.

voronoi = DefineNumber[0, Name "Parameters/Voronoi", Choices{0, 1}];
optimize = DefineNumber[1, Name "Parameters/Optimize tetrahedra",
                        Choices{0, 1}];

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

Mesh.MeshSizeMax = 0.25;
Mesh.Optimize = optimize;
Mesh 3;

Plugin(DualMesh).Voronoi = voronoi;
Plugin(DualMesh).Run;

// set up the view when the file is first opened only: changing a parameter
// then keeps the current one
DefineConstant[ viewSet = {0, Name "Parameters/View set", Visible 0} ];
If(!viewSet)
  // show the polyhedra cut by the plane y = 0
  Geometry.Points = 0;
  Geometry.Curves = 0;
  Geometry.Surfaces = 0;
  Mesh.SurfaceFaces = 0;
  Mesh.SurfaceEdges = 0;
  Mesh.VolumeFaces = 1;
  Mesh.VolumeEdges = 1;
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
