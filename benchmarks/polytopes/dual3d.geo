// The barycentric dual of a 3D mesh, made of polyhedra
//
// A dome meshed with tetrahedra sits on a cylinder meshed with hexahedra, with
// pyramids at their interface. Plugin(DualMesh) replaces this mixed mesh by
// its barycentric dual: each node becomes a polyhedron in each volume around
// it, whose vertices are the centres of the elements, the centres of their
// faces and the middles of their edges around the node, and the node itself
// if it lies on a curve. The polyhedra are subdivided into the tetrahedra of
// the barycentric subdivision of the elements, and the surfaces carry the
// polygons of the dual of their mesh. With `voronoi' set, the tetrahedra are
// represented by their circumcentres, and the polyhedra are the Voronoi cells
// of the nodes where the mesh is Delaunay. Setting `optimize' improves the
// quality of the tetrahedra, but breaks the Delaunay property. A clipping
// plane shows the layer of polyhedra it cuts.

voronoi = DefineNumber[0, Name "Parameters/Voronoi", Choices{0, 1}];
optimize = DefineNumber[1, Name "Parameters/Optimize tetrahedra",
                        Choices{0, 1}];

SetFactory("OpenCASCADE");

// the dome, whose base is meshed with quadrangles...
Sphere(1) = {0, 0, 1, 1, 0, Pi/2, 2*Pi};
base() = Surface In BoundingBox{-1.1, -1.1, 0.99, 1.1, 1.1, 1.01};
Recombine Surface{base()};
MeshAlgorithm Surface{base()} = 8;

// ... extruded downwards into hexahedra
Extrude{0, 0, -1}{ Surface{base()}; Layers{5}; Recombine; }

Mesh.MeshSizeMax = 0.25;
Mesh.Optimize = optimize;
Mesh 3;

Plugin(DualMesh).Voronoi = voronoi;
Plugin(DualMesh).Run;

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
General.ClipOnlyDrawIntersectingVolume = 1;
General.TrackballQuaternion0 = 0.564863;
General.TrackballQuaternion1 = 0.099601;
General.TrackballQuaternion2 = 0.142244;
General.TrackballQuaternion3 = 0.806707;
