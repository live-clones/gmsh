l = 2;
L = l / 2;
n = L / 2;

d  = 4;
cl = l / d;

Point(1) = {-L,  L, -L, cl};
Point(2) = {-L,  0, -L, cl};
Point(3) = { L,  0, -L, cl};
Point(4) = { L, -L, -L, cl};

Point(5) = {-n,  L, -L, cl};
Point(6) = { n,  0, -L, cl};
Point(7) = {-n,  0, -L, cl};
Point(8) = { n, -L, -L, cl};

BSpline(1) = {1, 5, 6, 3};
BSpline(2) = {2, 7, 8, 4};

Line(3) = {2, 1};
Line(4) = {3, 4};

Line Loop(1) = {3, 1, 4, -2};
Plane Surface(1) = {1};

Geometry.ExactExtrusion=0;
Mesh.ElementOrder = 2;

Extrude{0, 0, 2 * L}{
  Surface{1}; Layers{10};
}

Hide{
  Point{ 5,  6,  7,  8};
  Point{14, 15, 24, 25};
}
