// Plugin(Bubbles): the .geo file of the Voronoi cells of a triangulation of
// the z = 0 plane, shrunk or not

Point(1) = {0, 0, 0, 0.3};
Point(2) = {1, 0, 0, 0.3};
Point(3) = {1, 1, 0, 0.3};
Point(4) = {0, 1, 0, 0.3};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};
Mesh 2;
Plugin(Bubbles).Run;
Plugin(Bubbles).ShrinkFactor = 0.2;
Plugin(Bubbles).OutputFile = "shrunk.geo";
Plugin(Bubbles).Run;
