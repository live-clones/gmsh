//+
SetFactory("Discrete");
//+
Box(1) = {-.5, -.5, -.5, 1, 1, 1};
//+
Sphere(2) = {.0, 0, 0, .7};

BooleanIntersection{ Volume{2}; Delete; }{ Volume{1}; Delete; }
//+
Cylinder(3) = {-1, 0, 0, 2, 0, 0, 0.3};
//+
Cylinder(4) = {0, -1, -0, 0, 2, 0, .3};
//+
Cylinder(5) = {0, 0, -1, 0, 0, 2, .3};

BooleanUnion{ Volume{3}; Delete; }{ Volume{4,5}; Delete; }

BooleanDifference{ Volume{2}; Delete; }{ Volume{3}; Delete; }
