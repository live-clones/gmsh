theta = Pi/16;
Point(1) = {0,0,0,0.1};
Point(2) = {1,0,0,0.1};
Point(3) = {0,1,0,0.1};
Circle(1) = {2,1,3};
Rotate {{0,1,0}, {0,0,0}, theta} { Duplicata { Line{1}; } }
Rotate {{0,1,0}, {0,0,0}, -theta} { Duplicata { Line{1}; } }
Circle(4) = {5,1,2};
Circle(5) = {2,1,4};

// good parametrization
Line Loop(6) = {-1,-4,3};
Ruled Surface(7) = {6};

// bad parametrization
Line Loop(8) = {1,-2,-5};
Ruled Surface(9) = {8};
