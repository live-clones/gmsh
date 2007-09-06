
N = 10;

lc1 = 0.1;
lc2 = 0.5;

For i In {1:N}
  angle = i * 2 * Pi / N;
  Point(2 * i) = { 2 * Cos(angle), 1 + Sin(angle), -5, lc1};
  Point(2 * i + 1) = { 2 * Cos(angle), 1 + Sin(angle), 5, lc1};
  Line(i) = {2 * i, 2 * i + 1};
EndFor

Point(1000) = {-5, -5, 3, lc2};
Point(1001) = {-1.7,-5.3,3, lc2};
Point(1002) = {1.6,-5.1,3, lc2};
Point(1003) = {5.1,-3.7,2, lc2};
Point(1004) = {-4.7,-1.5,-1, lc2};
Point(1005) = {-5.3,1,-2, lc2};
Point(1006) = {-4.4,4.2,1, lc2};
Point(1007) = {-1,3.5,3, lc2};
Point(1008) = {2.6,4.2,3, lc2};
Point(1009) = {5.5,3.2,1, lc2};
Point(1010) = {5.4, 1.1,-2, lc2};
Point(1011) = {5.8,-1.4,-1, lc2};

Spline(11) = {1003,1011,1010,1009};
Spline(12) = {1009,1008,1007,1006};
Spline(13) = {1006,1005,1004,1000};
Spline(14) = {1000,1001,1002,1003};
Line Loop(15) = {11,12,13,14};
Ruled Surface(16) = {15};

pp[] = Intersect Line {1:N} Surface {16};

Spline(1000) = {pp[], pp[0]};

Delete { Surface{16}; }
Hide { Line{1:N}; Point{1:2*N}; }

Line Loop(16) = {1000};
Ruled Surface(16) = {15, 16};
