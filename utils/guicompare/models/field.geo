// A square with a size field on it, so that the size-field window has
// something in its list and something to show the options of.
Point(1) = {0, 0, 0, 0.2};
Point(2) = {1, 0, 0, 0.2};
Point(3) = {1, 1, 0, 0.2};
Point(4) = {0, 1, 0, 0.2};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};

Field[1] = Box;
Field[1].VIn = 0.02;
Field[1].VOut = 0.2;
Field[1].XMin = 0.3;
Field[1].XMax = 0.7;
Field[1].YMin = 0.3;
Field[1].YMax = 0.7;
Background Field = 1;
