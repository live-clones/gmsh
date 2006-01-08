Point(1) = {2,5,0,0.1};
Point(2) = {5,5,0,0.1};
Point(3) = {2,10,0,0.1};
Point(4) = {2,0,0,0.1};
Point(5) = {7,5,0,0.1};
Circle(3) = {4,1,5};
Circle(4) = {5,1,3};

// this used to fail (due to the neg curves in the line loop) in
// gmsh <= 1.61

Ellipse(1) = {4,1,1,2};
Ellipse(2) = {2,1,1,3};
Line Loop(5) = {3,4,-2,-1};
Plane Surface(6) = {5};
Symmetry { 1.0,0.0,0.0,-2 } {  Surface{6}; }
//Rotate { {0.0,0,1}, {2,5,0.0}, Pi/7 } { Surface{6}; }



// this worked:
/*
Ellipse(1) = {2,1,1,4};
Ellipse(2) = {3,1,1,2};
Line Loop(5) = {3,4,2,1};
Plane Surface(6) = {5};
Symmetry { 1.0,0.0,0.0,-2 } {  Surface{6}; }
//Rotate { {0.0,0,1}, {2,5,0.0}, Pi/7 } { Surface{6}; }

*/
