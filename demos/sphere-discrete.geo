// merge a surface mesh

Merge "sphere-surf.msh";

// delete all physical groups

Delete Physicals;

// add a geometrical volume

Surface Loop(29) = {28,26,16,14,20,24,22,18};
Volume(30) = {29};
