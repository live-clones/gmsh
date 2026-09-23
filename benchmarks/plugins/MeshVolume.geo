// Plugin(MeshVolume): area of a square (all, physical 3), length of its
// physical curve 1, everything; then volume and boundary area of a cube
Merge "data/square.msh";
Plugin(MeshVolume).Dimension = 2;
Plugin(MeshVolume).Run;
Plugin(MeshVolume).PhysicalGroup = 3;
Plugin(MeshVolume).Run;
Plugin(MeshVolume).Dimension = 1;
Plugin(MeshVolume).PhysicalGroup = 1;
Plugin(MeshVolume).Run;
Plugin(MeshVolume).Dimension = -1;
Plugin(MeshVolume).PhysicalGroup = -1;
Plugin(MeshVolume).Run;

NewModel;
Merge "data/cube.msh";
Plugin(MeshVolume).Dimension = 3;
Plugin(MeshVolume).Run;
Plugin(MeshVolume).Dimension = 2;
Plugin(MeshVolume).PhysicalGroup = 2;
Plugin(MeshVolume).Run;
Plugin(MeshVolume).Dimension = -1;
Plugin(MeshVolume).PhysicalGroup = -1;
Plugin(MeshVolume).Run;
