
// this is a simple example for which computing a bounding box with
// bbox*=1.5 fails...

Point (1) = {0,   0,   0, 1};
Point (2) = {0.1, 0.1, 0, 1};
Point (3) = {0.1, 0.2, 0, 1};
Line (1) = {1, 2};
Line (2) = {2, 3};
Line (3) = {3, 1};
Line Loop(1) = {1, 2, 3};
Plane Surface(1) = {1};
