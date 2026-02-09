//+
SetFactory("OpenCASCADE");
Box(1) = {-0.5, -0.5, 0, 1, 1, 1};
//+
Box(2) = {-0.25, -0.25, -0.25, .5, .5, .5};
//+
BooleanDifference{ Volume{1}; Delete; }{ Volume{2}; Delete; }
