// Hex-dominant mesh of a pipe junction, about 115,000 hexahedra: the options
// of -hybrid. "gmsh piquage.geo -3" gives the mesh of
// "gmsh piquage.brep -3 -hybrid -clmin 0.003 -clmax 0.003"; about a million
// hexahedra with -setnumber h 0.0015
SetFactory("OpenCASCADE");
v() = ShapeFromFile("piquage.brep");

DefineConstant[
  h = {0.003, Min 0.001, Max 0.02, Step 0.0005, Name "Parameters/Mesh size"}
];
Mesh.MeshSizeMin = h;
Mesh.MeshSizeMax = h;

// the options set by -hybrid
Mesh.Algorithm = 9; // PACK, recombined into quads
Mesh.RecombineAll = 1;
Mesh.MeshSizeExtendFromBoundary = 0;
Mesh.Algorithm3D = 9; // flat filler and combination into hexes and prisms
Mesh.Recombine3DAll = 1;
Mesh.Recombine3DPrisms = 1;
Mesh.Recombine3DPyramids = 1;
Mesh.Smoothing = 3;

// the elements seen through a cut in the plane of the two pipes
Include "hexdom_view.opt";
bb() = BoundingBox Volume{v()};
General.Clip0A = 0;
General.Clip0B = 0;
General.Clip0C = 1;
General.Clip0D = -(bb(2) + bb(5)) / 2;
