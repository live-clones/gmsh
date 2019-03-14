SetFactory("OpenCASCADE");

Merge "Block.stp";

Wedge(2) = {-32, -2.1, -15.5, 40, 40, 60, 0};
//+
BooleanIntersection{ Volume{2}; Delete; }{ Volume{1}; Delete; }
//+
Physical Surface(1) = {57, 74, 1};
//+
Physical Surface(2) = {2};
//+
Physical Volume(3) = {1};
