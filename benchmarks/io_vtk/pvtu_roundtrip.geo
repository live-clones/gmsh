// Write a partitioned mesh and two views as a .pvtu (a .vtu per partition)
// and read it back: the nodes on the interfaces, which every piece that
// touches them holds, must come back as one node each (they are told by
// their GlobalNodeIds), with the elements, the physical group and the data.

SetFactory("OpenCASCADE");
Box(1) = {0, 0, 0, 1, 2, 3};
Physical Volume(7) = {1};
Mesh.MeshSizeMin = 0.5; Mesh.MeshSizeMax = 0.5;
Mesh 3;
PartitionMesh 4;

Plugin(NewView).NumComp = 1; Plugin(NewView).Type = "NodeData";
Plugin(NewView).Run;
Plugin(ModifyComponents).View = 0;
Plugin(ModifyComponents).Expression0 = "x + 2 * y + 3 * z";
Plugin(ModifyComponents).Run;
View[0].Name = "scalar";
Plugin(NewView).NumComp = 1; Plugin(NewView).Type = "ElementData";
Plugin(NewView).Value = 5;
Plugin(NewView).Run;
View[1].Name = "constant";

Macro Measure
  // -> integral of the scalar, volume of physical group 7
  Plugin(Integrate).View = 0; Plugin(Integrate).Dimension = 3;
  Plugin(Integrate).Run;
  integral = View[PostProcessing.NbViews - 1].Max;
  Delete View[PostProcessing.NbViews - 1];
  Plugin(MeshVolume).PhysicalGroup = 7; Plugin(MeshVolume).Dimension = 3;
  Plugin(MeshVolume).Run;
  volume = View[PostProcessing.NbViews - 1].Max;
  Delete View[PostProcessing.NbViews - 1];
Return

nodes0 = Mesh.NbNodes; cells0 = Mesh.NbTetrahedra;
Mesh.Binary = 0; Save "pvtu_roundtrip_ascii_out.pvtu";
Mesh.Binary = 1; Save "pvtu_roundtrip_binary_out.pvtu";
Mesh.Binary = 0;
Delete View[1]; Delete View[0];
For binary In {0 : 1}
  Delete Model;
  If(!binary)
    Merge "pvtu_roundtrip_ascii_out.pvtu";
  Else
    Merge "pvtu_roundtrip_binary_out.pvtu";
  EndIf
  If(Mesh.NbNodes != nodes0 || Mesh.NbTetrahedra != cells0)
    Error("Binary %g: %g nodes and %g tetrahedra written, %g and %g read", binary, nodes0, cells0, Mesh.NbNodes, Mesh.NbTetrahedra);
  EndIf
  If(PostProcessing.NbViews != 2)
    Error("Binary %g: 2 views written, %g read", binary, PostProcessing.NbViews);
  EndIf
  Call Measure;
  // the integral of x + 2 y + 3 z over the box is 6 (1/2 + 2 + 9/2) = 42
  If(Fabs(integral - 42) > 1e-8 || Fabs(volume - 6) > 1e-8)
    Error("Binary %g: integral %g and volume of the physical group %g, expected 42 and 6", binary, integral, volume);
  EndIf
  If(View[1].Min != 5 || View[1].Max != 5)
    Error("Binary %g: element data in [%g, %g], expected 5", binary, View[1].Min, View[1].Max);
  EndIf
  Delete View[1]; Delete View[0];
EndFor
