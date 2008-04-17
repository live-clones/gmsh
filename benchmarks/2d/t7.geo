/********************************************************************* 
 *
 *  Gmsh tutorial 7
 * 
 *  Anisotropic meshes, attractors
 *
 *********************************************************************/

lc = .3;

Point(1) = {0.0,0.0,0,lc};
Point(2) = {1.2,-0.2,0,lc};
Point(3) = {1,1,0,lc};
Point(4) = {0,1,0,lc};

Line(1) = {3,2};
Line(2) = {2,1};
Line(3) = {1,4};
Line(4) = {4,3};

Line Loop(5) = {1,2,3,4};
Plane Surface(6) = {5};

Point(5) = {0.1,0.2,0,lc};
Point(11) = {0.4,0.7,-1,lc};
Point(12) = {0.5,0.5,0,lc};
Point(22) = {0.9,0.9,1,lc};

Line(5) = {11,22};

Spline(7) = {4,5,12,2};

num_pts = 100;
lc_min = 0.005;
lc_max = lc;
r_min = 0.01;
r_max = 0.5;
Attractor Line{7,5,3,2} = {r_min, lc_min, lc_max, num_pts, r_max / r_min};

