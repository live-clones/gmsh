/********************************************************************* 
 *
 *  Gmsh tutorial 10
 * 
 *  General mesh size fields
 *
 *********************************************************************/

// In addition to specifying target mesh sizes at the points of the
// geometry (see t1) or using a background mesh (see t7), you can use
// general mesh size "Fields". 

// Let's create a simple rectangular geometry
lc = .15;
Point(1) = {0.0,0.0,0,lc}; Point(2) = {1,0.0,0,lc}; 
Point(3) = {1,1,0,lc};     Point(4) = {0,1,0,lc}; 
Point(5) = {0.2,.5,0,lc};

Line(1) = {3,2}; Line(2) = {2,1}; Line(3) = {1,4}; Line(4) = {4,3};

Line Loop(5) = {1,2,3,4}; Plane Surface(6) = {5};

// Say we would like to obtain mesh elements with size lc/30 near line
// 1 and point 5, and size lc elsewhere. To achieve this, we can use
// two fields: "Attractor", and "Threshold". We first define an
// Attractor field (Field[1]) on points 5 and on line 1. This field
// returns the distance to point 5 and to (100 equidistant points on)
// line 1.
Field[1] = Attractor;
Field[1].NodesList = {5};
Field[1].NNodesByEdge = 100;
Field[1].EdgesList = {1};

// We then define a Threshold field, which uses the return value of
// the Attractor Field[1] in order to define a simple change in
// element size around the attractors (i.e., around point 5 and line
// 1)
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

// Say we want to modulate the mesh element sizes using a mathematical
// function of the spatial coordinates. We can do this with the
// MathEval field:
Field[3] = MathEval;
Field[3].F = "Cos(4*3.14*x) * Sin(4*3.14*y) / 10 + 0.101";

// We could also combine MathEval with values coming from other
// fields. For example, let's define an Attractor around point 1
Field[4] = Attractor;
Field[4].NodesList = {1};

// We can then create a MathEval field with a function that depends on
// the return value of the Attractr Field[4], i.e., depending on the
// distance to point 1 (here using a cubic law, with minumum element
// size = lc / 100)
Field[5] = MathEval;
Field[5].F = Sprintf("F4^3 + %g", lc / 100);

// We could also use a Box field to impose a step change in element
// sizes inside a box
Field[6] = Box;
Field[6].VIn = lc / 15;
Field[6].VOut = lc;
Field[6].XMin = 0.3; 
Field[6].XMax = 0.6;
Field[6].YMin = 0.3;
Field[6].YMax = 0.6;

// Many other types of fields are available: see the reference manual
// for a complete list. You can also create fields directly in the
// graphical user interface by selecting Define->Fields in the Mesh
// module.

// Finally, let's use the minimum of all the fields as the background
// mesh field
Field[7] = Min;
Field[7].FieldsList = {2, 3, 5, 6};
Background Field = 7;

// Don't extend the elements sizes from the boundary inside the domain
Mesh.CharacteristicLengthExtendFromBoundary = 0;
