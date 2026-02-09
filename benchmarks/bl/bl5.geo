//+
SetFactory("OpenCASCADE");
Rectangle(1) = {-1, -0.2, 0, 1, 0.5, 0};
//+
Rectangle(2) = {-0.5, 0.1, 0, 1, 0.5, 0};
//+
Rectangle(3) = {0.2, 0.4, 0, 1, 0.5, 0};
//+
BooleanUnion{ Surface{1}; Delete; }{ Surface{2}; Surface{3}; Delete; }
//+
MeshSize {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21} = 0.05;
