//+
SetFactory("OpenCASCADE");
Cylinder(1) = {-0.5, -0, 0, 1, 0, 0, 0.25, 2*Pi};
//+
Sphere(2) = {-0.5, 0, 0, 0.25, -Pi/2, Pi/2, 2*Pi};
//+
BooleanUnion{ Volume{2}; Delete; }{ Volume{1}; Delete; }
//+
Box(2) = {-1.1, -.5, 0, 2, 1, 0.5};
//+
BooleanDifference{ Volume{2}; Delete; }{ Volume{1}; Delete; }
