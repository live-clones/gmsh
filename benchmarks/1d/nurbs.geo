
lc = 0.01;

Point(1) = {0,0,0,lc};
Point(2) = {1,0,0,2*lc};
Point(3) = {1,1,0,0.1*lc};
Point(4) = {0,1,0,4*lc};

// A knot represents a parameter interval (and can be 0).
// There are (N + D + 1) knots
// A point with a knot multiplicity of (D+1) belongs to the nurbs

Nurbs(1) = {1,2,3,4} Knots {0,0,0,0, 1, 1,1,1} Order 3;


//Nurbs(1) = {1,2,3,4} Knots {0,0,0,0, 1,1,1,1} Order 3;
//Nurbs(2) = {1,2,3,4} Knots {0,0,1, 1 } Order 3;

