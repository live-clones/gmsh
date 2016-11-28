/*********************************************************************
 *
 *  Gmsh tutorial 15
 *
 *  Embedded points, lines and surfaces
 *
 *********************************************************************/

// We start one again by including the first tutorial:
Include "t1.geo";

// We change the mesh size to generate coarser mesh
lc = lc * 4;
Characteristic Length {1:4} = lc;

// We define a new point
Point(5) = {0.02, 0.02, 0, lc};

// One can force this point to be included ("embedded") in the 2D mesh, using
// the "Point In Surface" command:
Point{5} In Surface{1};

// In the same way, one can force a curve to be embedded in the 2D mesh using
// the "Line in Surface" command:
Point(6) = {0.02, 0.12, 0, lc};
Point(7) = {0.04, 0.18, 0, lc};
Line(5) = {6, 7};
Line{5} In Surface{1};

// One can also embed points and lines in a volume using the "Line/Point In
// Volume" commands:
Extrude {0, 0, 0.1}{ Surface {1}; }

p = newp;
Point(p) = {0.07, 0.15, 0.025, lc};
Point{p} In Volume {1};

l = newl;
Point(p+1) = {0.025, 0.15, 0.025, lc};
Line(l) = {7, p+1};
Line{l} In Volume {1};

// Finally, one can also embed a surface in a volume using the "Surface In
// Volume" command:
Point(p+2) = {0.02, 0.12, 0.05, lc};
Point(p+3) = {0.04, 0.12, 0.05, lc};
Point(p+4) = {0.04, 0.18, 0.05, lc};
Point(p+5) = {0.02, 0.18, 0.05, lc};
Line(l+1) = {p+2, p+3};
Line(l+2) = {p+3, p+4};
Line(l+3) = {p+4, p+5};
Line(l+4) = {p+5, p+2};
ll = newll;
Line Loop(ll) = {l+1:l+4};
s = news;
Plane Surface(s) = {ll};
Surface{s} In Volume{1};
