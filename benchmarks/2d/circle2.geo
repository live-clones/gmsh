lc = 0.5;

Point(1) = {0, 0, 0, lc};
Point(2) = {0, 2, 0, lc};
Point(3) = {2, 0, 0, lc};
Point(4) = {0, -2, 0, lc};
Point(5) = {-2, 0, 0, lc};
Circle(1) = {2, 1, 5};
Circle(2) = {5, 1, 4};
Circle(3) = {4, 1, 3};
Circle(4) = {3, 1, 2};

Point(22) = {0, 1, 0, lc};
Point(33) = {1, 0, 0, lc};
Point(44) = {0, -1, 0, lc};
Point(55) = {-1, 0, 0, lc};
Circle(11) = {22, 1, 55};
Circle(22) = {55, 1, 44};
Circle(33) = {44, 1, 33};
Circle(44) = {33, 1, 22};


Line Loop(45) = {44, 11, 22, 33};
Line Loop(46) = {4, 1, 2, 3};
Plane Surface(47) = {45, 46};


