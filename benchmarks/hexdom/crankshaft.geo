// Hex-dominant mesh of a crankshaft, about 93,000 hexahedra: the options of
// -hybrid. "gmsh crankshaft.geo -3" gives the mesh of
// "gmsh ../step/SampleCrankshaft4A.stp -3 -hybrid -clmin 2.75 -clmax 2.75";
// finer with e.g. -setnumber h 1.5
SetFactory("OpenCASCADE");
v() = ShapeFromFile("../step/SampleCrankshaft4A.stp");

DefineConstant[
  h = {2.75, Min 0.5, Max 10, Step 0.05, Name "Parameters/Mesh size"}
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

// the elements seen through a cut at the middle of the shaft
Include "hexdom_view.opt";
bb() = BoundingBox Volume{v()};
General.Clip0A = 1;
General.Clip0B = 0;
General.Clip0C = 0;
General.Clip0D = -(bb(0) + bb(3)) / 2;
