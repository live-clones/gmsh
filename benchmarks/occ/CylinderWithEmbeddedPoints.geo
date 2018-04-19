// This example shows the possibility of inserting embedded points and lines on
// periodic surfaces

SetFactory("OpenCASCADE");
Cylinder(1) = {-0.5, 0, 0, 1, 0, 0, 0.5, 2*Pi};

Point(3) = {0, .5, 0, .01};
Point {3} In Surface {1};

Point(4) = {-.5, 0, 0, .01};
Point {4} In Surface {3};

Characteristic Length {2, 1} = 0.1;

//Point(5) = {0, 0.6, 0.3, .001};
//Point(6) = {0, 0.6, -0.2, .01};
//Line(4) = {6, 5};
Rectangle(4) = {0.2, 0.2, -0.2, .5, 0.5};
Rotate {{0, 1, 0}, {0, 0, 0}, Pi/4} { Surface{4}; }
BooleanFragments{ Surface{1}; Delete; }{ Surface{4}; Delete; }
Curve{5} In Surface {1};

Characteristic Length {7, 5} = 0.01;
