SetFactory("OpenCASCADE");

Point(1) = {-0.8, 0.1, -0.2, 0.02};
Point(2) = {-0.5, 0.1, -0.2, 0.02};
Point(3) = {-0.6, 0, -0.1, 0.02};
Point(4) = {-0.7, -0, -0.1, 0.02};
Point(5) = {-0.7, 0.2, -0.2, 0.02};
Point(6) = {-0.6, 0.1, -0.1, 0.02};
Spline(1) = {1, 5, 2};
Spline(2) = {2, 6, 3};
Spline(3) = {3, 4, 1};
Curve Loop(1) = {1, 2, 3};

N = 3;
For i In {0:N-1}
  For j In {0:N-1}
    Point(7 + N*i + j) = {-0.7+0.01*i, 0.1+0.01*j, -0.2,  0.0025};
  EndFor
EndFor
// Same as 1, but passing through points 7 and 8

Surface(4) = {1} Using Point {7:7+N*N-1};
Point{7:7+N*N-1} In Surface{4};
