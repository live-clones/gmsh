// Plugin(SimplePartition): 4 uniform slices along X (the defaults) of a
// quadrangle mesh, then repartitioned in 3 x 2
Merge "data/quads.msh";
Plugin(SimplePartition).Run;
Plugin(SimplePartition).NumSlicesX = 3;
Plugin(SimplePartition).NumSlicesY = 2;
Plugin(SimplePartition).Run;
