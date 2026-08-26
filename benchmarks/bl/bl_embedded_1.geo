//+
SetFactory("OpenCASCADE");
Rectangle(1) = {-0.5, -0.5, 0, 1, 1, 0};
//+
Point(5) = {-0.3, -0, 0, 1.0,.1};
//+
Point(6) = {0.3, -0, 0, 1.0,.1};
//+
Line(5) = {5, 6};

Line{5} In Surface {1};//+
MeshSize {1, 2, 3, 4, 5, 6} = 0.05;
