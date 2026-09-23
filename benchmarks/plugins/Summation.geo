// Plugin(Summation) with its defaults, the only setting a .geo file can reach
// (option names have spaces): a copy of the last view, model data with 3 steps
// on triangles, and list data on hexahedra

Merge "data/square.msh"; // views 0-3
Delete View[3];
Delete View[2]; // last view: vector, 3 steps
Plugin(Summation).Run;

Merge "data/hexes.pos"; // views 3-6
Plugin(Summation).Run;
