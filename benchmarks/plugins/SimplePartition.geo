// Plugin(SimplePartition): 2 x 2 x 2 slices of a tetrahedral mesh,
// nonuniform along X and Z
Merge "data/cube.msh";
Plugin(SimplePartition).NumSlicesX = 2;
Plugin(SimplePartition).NumSlicesY = 2;
Plugin(SimplePartition).NumSlicesZ = 2;
Plugin(SimplePartition).MappingX = "t^2";
Plugin(SimplePartition).MappingZ = "Sqrt(t)";
Plugin(SimplePartition).Run;

// slabs that do not reach the end of the box: the elements beyond are in the
// last slab (they were left out of the partitions)
Plugin(SimplePartition).NumSlicesX = 2;
Plugin(SimplePartition).NumSlicesY = 1;
Plugin(SimplePartition).NumSlicesZ = 1;
Plugin(SimplePartition).MappingX = "0.5 * t";
Plugin(SimplePartition).Run;
