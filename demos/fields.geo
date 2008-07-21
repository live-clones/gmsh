lc = .15;
Point(1) = {0.0,0.0,0,lc};
Point(2) = {1,0.0,0,lc};
Point(3) = {1,1,0,lc};
Point(4) = {0,1,0,lc};
Line(1) = {3,2};
Line(2) = {2,1};
Line(3) = {1,4};
Line(4) = {4,3};
Point(55) = {0.2,.5,0,lc};
Line Loop(5) = {1,2,3,4};
Plane Surface(6) = {5};

// Attractors field on points 1 and 55, and on line 1
Field[1] = Attractor;
Field[1].NNodesByEdge = 100;
Field[1].NodesList = {1,55};
Field[1].EdgesList = {1};

// Threshold field defined on the attractors
//
// LcMax -                         /------------------
//                               /
//                             /
//                           /
// LcMin -o----------------/
//        |                |       |
//     Attractor       DistMin   DistMax
Field[2] = Threshold;
Field[2].IField = 1;
Field[2].LcMin = lc/20;
Field[2].LcMax = lc;
Field[2].DistMin = 0.15;
Field[2].DistMax = 0.5;
//Field[2].Sigmoid = 1;

// Function field
Field[3] = MathEval;
Field[3].F = "Cos(4*3.14*x) * Sin(4*3.14*y) / 10 + 0.101";

// Use minimum of threshold and function field as background field
Field[4] = Min;
Field[4].FieldsList = {2, 3};

Background Field = 4;
