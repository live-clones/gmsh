// A torus fused on the middle of an edge of a box: both seams of the torus are
// cut, and a piece of each bounds the toroidal surface on one side only. With
// both sides taken as boundary, points of the surface were found outside of it
// and its mesh was left unrefined, with duplicate triangles.

SetFactory("OpenCASCADE");

Box(1) = {0, 0, 0, 1, 0.7, 0.5};
Torus(2) = {0.5, 0.7, 0.5, 0.3, 0.1};
BooleanUnion{ Volume{1}; Delete; }{ Volume{2}; Delete; }

Mesh.MeshSizeMax = 0.1;

Mesh 3;

nbtets = Mesh.NbTetrahedra;
If(nbtets == 0)
  Error("No tetrahedral elements created!");
EndIf
