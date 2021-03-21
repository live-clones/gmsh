// Extrusion bug with closed splines

SetFactory("OpenCASCADE");

lc = 0.025;

Point(1) = {0, 0, 0, lc};
Point(2) = {1, 0, 0, lc};
Point(3) = {1, 1, 0, lc};
Point(4) = {0, 1, 0, lc};

Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4};

Point(5) = {0.92, 0.174293, 0, lc};
Point(6) = {0.928278, 0.122108, 0, lc};
Point(7) = {0.92108, 0.0753213, 0, lc};
Point(8) = {0.877892, 0.0645244, 0, lc};
Point(9) = {0.827506, 0.107712, 0, lc};
Point(10) = {0.759126, 0.18509, 0, lc};
Point(11) = {0.663753, 0.300257, 0, lc};
Point(12) = {0.559383, 0.424422, 0, lc};
Point(13) = {0.467609, 0.507198, 0, lc};
Point(14) = {0.388432, 0.539589, 0, lc};
Point(15) = {0.320051, 0.53419, 0, lc};
Point(16) = {0.240874, 0.46581, 0, lc};
Point(17) = {0.168895, 0.363239, 0, lc};
Point(18) = {0.120308, 0.334447, 0, lc};
Point(19) = {0.0825193, 0.341645, 0, lc};
Point(20) = {0.0609254, 0.375835, 0, lc};
Point(21) = {0.0627249, 0.437018, 0, lc};
Point(22) = {0.11671, 0.516195, 0, lc};
Point(23) = {0.222879, 0.613368, 0, lc};
Point(24) = {0.332648, 0.658355, 0, lc};
Point(25) = {0.498201, 0.627763, 0, lc};
Point(26) = {0.706941, 0.514396, 0, lc};
Point(27) = {0.863496, 0.312853, 0, lc};
Spline(5) = {20 ... 27, 5 ... 20};
Curve Loop(2) = {5};

Plane Surface(1) = {1, 2};

Extrude {0, 0, 0.05} { Surface{1}; Layers{2}; Recombine; }

Mesh.ElementOrder = 2;
Mesh.SecondOrderLinear = 0;
Mesh.SecondOrderIncomplete = 0;
Mesh.Renumber = 0;
