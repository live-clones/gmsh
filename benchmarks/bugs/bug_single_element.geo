
// the old 2D algo chokes on this:

Point(1) = {0, 0, 24.5, 90};
Point(3) = {0, 24.5, 0, 90};
Point(5) = {0, 0, 0, 90};
Point(7) = {100, 42.5, 17.5, 90};

Circle (1) = {1, 5, 3}; // this is bad
// Line (1) = {1, 3}; // this is OK
Line (9) = {1, 7};
Line (11) = {3, 7};

Line Loop (1) = {9, -11, -1}; // this is bad
// Line Loop (1) = {-11, -1, 9}; // this is OK

Ruled Surface (2) = {1};
