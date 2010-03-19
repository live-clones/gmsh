lc = 0.5*50;
Point(1) = {0, 0, 0, lc};
Point(2) = {100, 0, 0, lc};
Line(1) = {1, 2};

Physical Point("Inlet") = {1};
Physical Point("Outlet") = {2};
Physical Line("Line") = {1};
