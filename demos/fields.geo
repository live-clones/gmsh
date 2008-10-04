lc = .15;
Point(1) = {0.0,0.0,0,lc};
Point(2) = {1,0.0,0,lc};
Point(3) = {1,1,0,lc};
Point(4) = {0,1,0,lc};
Point(5) = {0.2,.5,0,lc};
Line(1) = {3,2};
Line(2) = {2,1};
Line(3) = {1,4};
Line(4) = {4,3};
Line Loop(5) = {1,2,3,4};
Plane Surface(6) = {5};

// Attractor field on points 5 and on line 1. This field returns the
// distance to point 5 and to (100 equidistant points on) line 1.
Field[1] = Attractor;
Field[1].NodesList = {5};
Field[1].NNodesByEdge = 100;
Field[1].EdgesList = {1};

// Threshold field using the return value of the attractor field 1 in
// order to define a simple change in element size around the
// attractors (i.e., around point 5 and line 1)
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
Field[2].LcMin = lc / 30;
Field[2].LcMax = lc;
Field[2].DistMin = 0.15;
Field[2].DistMax = 0.5;

// MathEval field with a function depending on the model coordinates
Field[3] = MathEval;
Field[3].F = "Cos(4*3.14*x) * Sin(4*3.14*y) / 10 + 0.101";

// Attractor around point 1
Field[4] = Attractor;
Field[4].NodesList = {1};

// MathEval field with a function depending on the return value of the
// attractr field 4, i.e., depending on the distance to point 1 (here
// using a cubic law, with minumum element size = lc / 100)
Field[5] = MathEval;
Field[5].F = Sprintf("F4^3 + %g", lc / 100);

// Box field to impose a step change in element sizes inside a box
Field[6] = Box;
Field[6].VIn = lc / 15;
Field[6].VOut = lc;
Field[6].XMin = 0.3; 
Field[6].XMax = 0.6;
Field[6].YMin = 0.3;
Field[6].YMax = 0.6;

// Use minimum of all the fields as the background field
Field[7] = Min;
Field[7].FieldsList = {2, 3, 5, 6};
Background Field = 7;

// Don't extend the elements sizes from the boundary inside the domain
Mesh.CharacteristicLengthExtendFromBoundary = 0;
