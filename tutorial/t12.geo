/*********************************************************************
 *
 *  Gmsh tutorial 12
 *
 *  Cross-patch meshing with compounds
 *
 *********************************************************************/

// Compound geometrical entities can be defined to compute a new parametrization
// of groups of elementary geometrical entities. This parametrization can then
// be used for remeshing the compound as if it were a single CAD entity.

lc = 0.1;

Point(1) = {0, 0, 0, lc};       Point(2) = {1, 0, 0, lc};
Point(3) = {1, 1, 0.5, lc};     Point(4) = {0, 1, 0.4, lc};
Point(5) = {0.3, 0.2, 0, lc};   Point(6) = {0, 0.01, 0.01, lc};
Point(7) = {0, 0.02, 0.02, lc}; Point(8) = {1, 0.05, 0.02, lc};
Point(9) = {1, 0.32, 0.02, lc};

Line(1) = {1, 2}; Line(2) = {2, 8}; Line(3) = {8, 9};
Line(4) = {9, 3}; Line(5) = {3, 4}; Line(6) = {4, 7};
Line(7) = {7, 6}; Line(8) = {6, 1}; Spline(9) = {7, 5, 9};
Line(10) = {6, 8};

Line Loop(11) = {5, 6, 9, 4};     Surface(1) = {11};
Line Loop(13) = {9, -3, -10, -7}; Surface(5) = {13};
Line Loop(15) = {10, -2, -1, -8}; Surface(10) = {15};

// Treat lines 2, 3 and 4 as a single line
Compound Line{2, 3, 4}; // FIXME: not (re)implemeted yet
// Idem with lines 6, 7 and 8
Compound Line{6, 7, 8}; // FIXME: not (re)implemeted yet

// Treat surfaces 12, 14 and 16 as a single surface
Compound Surface{1, 5, 10};
