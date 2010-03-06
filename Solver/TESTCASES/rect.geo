Point(1) = {-.125, 0, 0, .05};
Point(2) = {.125, 0, 0, .05};
Point(3) = {.125, .5, 0, .05};
Point(4) = {-.125, .5, 0, .05};
Point(5) = {-.125, -.5, 0, .05};
Point(6) = {.125, -.5, 0, .05};
Line(1) = {5, 1};
Line(2) = {1, 2};
Line(3) = {2, 6};
Line(4) = {6, 5};
Line(5) = {1, 4};
Line(6) = {4, 3};
Line(7) = {3, 2};
Line Loop(8) = {7, -2, 5, 6};
Plane Surface(9) = {8};
Line Loop(10) = {3, 4, 1, 2};
Plane Surface(11) = {10};

Physical Surface("sprut") = {11, 9};
Physical Line("Walls") = {5, 7, 3, 4, 1};
Physical Line("Top") = {6};

Recombine Surface {9, 11};

Field[1] = MathEval;
Field[1].F = "0.01*1+0.01*100*(y*y)";
Background Field = 1;
