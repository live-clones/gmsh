// Plugin(SimplePartition): 2 x 2 x 2 slices of a tetrahedral mesh,
// nonuniform along X and Z
Merge "data/cube.msh";
Plugin(SimplePartition).NumSlicesX = 2;
Plugin(SimplePartition).NumSlicesY = 2;
Plugin(SimplePartition).NumSlicesZ = 2;
Plugin(SimplePartition).MappingX = "t^2";
Plugin(SimplePartition).MappingZ = "Sqrt(t)";
Plugin(SimplePartition).Run;
