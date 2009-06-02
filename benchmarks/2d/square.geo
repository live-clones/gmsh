lc=0.2;
Point(1) = {0, 0, 0,lc};
Point(2) = {0, 1, 0,lc};
Point(3) = {1, 1, 0,lc};
Point(4) = {1, 0, 0,lc};
Line(1) = {2, 3};
Line(2) = {3, 4};
Line(3) = {4, 1};
Line(4) = {1, 2};

Line Loop(5) = {1, 2, 3, 4};
Plane Surface(10) = {5};

