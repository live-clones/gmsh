// A mesh saved in a file per partition (MSH 4) comes with name.msh.geo, the
// script that reads the files back as they were.

SetFactory("OpenCASCADE");
Box(1) = {0, 0, 0, 1, 1, 1};
Mesh.MeshSizeMax = 0.25;
Mesh 3;
PartitionMesh 3;
num = Mesh.NbTetrahedra;
Mesh.PartitionSplitMeshFiles = 1;
Save "read_back_out.msh";
Mesh.PartitionSplitMeshFiles = 0;

Delete Model;
Merge "read_back_out.msh.geo";
If(Mesh.NbTetrahedra != num)
  Error("Read back %g tetrahedra, expected %g", Mesh.NbTetrahedra, num);
EndIf
