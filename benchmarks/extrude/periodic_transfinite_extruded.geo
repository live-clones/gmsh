// Periodicity constraints on a structured mesh, defined before meshing: the
// base square is transfinite, the cube is extruded from it with layers, and the
// cube is periodic in x, y and z. The node correspondence of the periodic
// surfaces is found by matching the nodes through the periodic transformations.

Point(1) = {0, 0, 0};
Point(2) = {1, 0, 0};
Point(3) = {1, 1, 0};
Point(4) = {0, 1, 0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};

Transfinite Curve{1, 3} = 6;
Transfinite Curve{2, 4} = 4;
Transfinite Surface{1};
Recombine Surface{1};

e[] = Extrude{0, 0, 1} { Surface{1}; Layers{5}; Recombine; };

// e[0] is the top surface, e[1] the volume and e[2..5] the lateral surfaces
// extruded from curves 1 (y = 0), 2 (x = 1), 3 (y = 1) and 4 (x = 0)
Periodic Surface{e[3]} = {e[5]} Translate{1, 0, 0};
Periodic Surface{e[4]} = {e[2]} Translate{0, 1, 0};
Periodic Surface{e[0]} = {1} Translate{0, 0, 1};
