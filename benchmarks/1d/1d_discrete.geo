
Merge "1d_with_points.msh";
//Merge "1d_without_points.msh";

Delete Physicals;
Status 0; // to force remeshing of non-discrete curves

cl=0.0999;

// uncomment point 1 and 4 if you merge "1d_without_points.msh"
//Point(1) = {0, 0, 0, cl};
//Point(4) = {1, 0, 0, cl};

p = newp;
Point(p) = {0, 1, 0, cl};
Point(p+1) = {1, 1, 0, cl};

Line(1)={1, p};
Line(2)={p, p+1};
Line(3)={p+1,4};

Line Loop(1) = {1,2,3,-4};
Plane Surface(1) = {1};
