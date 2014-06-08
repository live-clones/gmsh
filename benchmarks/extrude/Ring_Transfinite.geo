// Inner Radius
ri = 1;
//outer Radius of Ring
ro = 2;

// Number of Points in tangential direction
nphi = 8;

// Number of Points in radial direction
nr = 2;

// Generate Point on horizontal Line

cl__1 = 1;
Point(1) = {0, 0, 0, 1};
Point(2) = {ri, 0, 0, 1};
Point(3) = {ro, 0, 0, 1};
Point(4) = {-1*ri, 0, 0, 1};
Point(5) = {-1*ro, 0, 0, 1};

// inner and outer Circles
Circle(1) = {2, 1, 4};
Transfinite Line {1} = nphi/2+1 Using Progression 1;
Circle(2) = {3, 1, 5};
Transfinite Line {2} = nphi/2+1 Using Progression 1;
Circle(3) = {4, 1, 2};
Transfinite Line {3} = nphi/2+1 Using Progression 1;
Circle(4) = {5, 1, 3};
Transfinite Line {4} = nphi/2+1 Using Progression 1;
 
 // Horizontal lines
Line(5) = {2, 3};
Transfinite Line {5} = nr+1 Using Progression 1;

Line(6) = {4, 5};
Transfinite Line {6} = nr +1 Using Progression 1;

// Surfaces consisting of upper and lower half-ring
Line Loop(7) = {1, 6, -2, -5};
Plane Surface(8) = {7};
Transfinite Surface {8} = {2, 4, 5, 3};

Line Loop(9) = {5, -4, -6, 3};
Plane Surface(10) = {9};
Transfinite Surface {10} = {5, 3, 2, 4};

// Generate Quad-Grid
Recombine Surface {8, 10};
