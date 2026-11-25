SetFactory("OpenCASCADE");
// boundary entities keep their tags through boolean operations
Geometry.OCCBooleanPreserveNumbering = 2;
Cylinder(1) = {-1.5, 0.5, 1.5, 1, 0, 0, 0.25, 2*Pi};
Cylinder(2) = {0,0,0, 0,0,3, 1};
BooleanIntersection(10) = { Volume{2}; }{ Volume{1}; Delete; };
Geometry.OCCUnionUnify = 0;
BooleanUnion { Volume{10}; Delete; }{ Volume{2}; Delete; }
Physical Surface("inlet", 19) = {5};
Physical Surface("outlet1", 20) = {6};
Physical Surface("outlet2", 21) = {7};
Physical Surface("wall", 22) = {8};
Physical Volume("tube", 23) = {1};
