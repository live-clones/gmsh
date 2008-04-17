lc = .15;
Point(1) = {0.0,0.0,0,lc};
Point(2) = {1,0.0,0,lc};
Point(3) = {1,1,0,lc};
Point(4) = {0,1,0,lc};
Line(1) = {3,2};
Line(2) = {2,1};
Line(3) = {1,4};
Line(4) = {4,3};
Point(55) = {0.2,.5,0,lc};
Line Loop(5) = {1,2,3,4};
Plane Surface(6) = {5};

// Point and line attractors (shortcuts for Threshold fields,
// automatically added to the list of char length fields)

num_pts = 100; // number of points on the attractor, unused for points
lc_min = lc/20; // lc inside r_min
lc_max = lc; // lc outside r_max
r_min = 0.15;
r_max = 0.5;
Attractor Point{1,55} = {r_min, lc_min, lc_max, num_pts, r_max / r_min};
Attractor Line{1} = {r_min, lc_min, lc_max, num_pts, r_max / r_min};

// Function field

Function Field(1) = "Cos(4*3.14*x) * Sin(4*3.14*y) / 10 + 0.101";
Characteristic Length Field{1};
