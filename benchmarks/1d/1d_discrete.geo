
Merge "1d_with_points.msh";
//Merge "1d_without_points.msh";

Delete Physicals;
Status 0; // to force remeshing of non-discrete curves

cl=0.0999;

//Point(1) = {0, 0, 0, cl};
Point(2) = {0, 1, 0, cl};
Point(3) = {1, 1, 0, cl};
//Point(4) = {1, 0, 0, cl};

Line(1)={1,2};
Line(2)={2,3};
Line(3)={3,4};

Line Loop(1) = {1,2,3,-4};
Plane Surface(1) = {1};
