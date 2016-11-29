General.MeshDiscrete = 1;
Merge "t13_data.msh";
Mesh.Algorithm=6;
Mesh.CharacteristicLengthMax = 1;
// Since the original mesh is a bit coarse, we refine it once
RefineMesh;
CreateTopology;