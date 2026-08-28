// No recombination, packing or size options are set here: the command-line
// QuadqsTargetSize must drive the complete PACK pipeline.
Point(1) = {0, 0, 0, 0.001};
Point(2) = {0.1, 0, 0, 0.001};
Point(3) = {0.1, 0.1, 0, 0.001};
Point(4) = {0, 0.1, 0, 0.001};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1:4};
Plane Surface(1) = {1};
