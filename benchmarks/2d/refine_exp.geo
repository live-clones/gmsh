Point(1) = {0,0,0};
Point(2) = {1,0,0};
Point(3) = {1,1,0};
Point(4) = {0,1,0};
Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};
Line Loop(5) = {1,2,3,4};
Plane Surface(6) = {5};

// computes the distance to point 1
Field[1] = Distance;
Field[1].NodesList = {1};

// computes a function of the value computed by field 1 ("F1")
Field[2] = MathEval;
Field[2].F = "Exp(-7*(1-F1))";

// applies field 2 as background mesh
Background Field = 2;

