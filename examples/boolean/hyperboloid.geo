SetFactory("OpenCASCADE");

N = 20;
a = 1;
c = 2;
umin = -1;
umax = 1;

// 1 sheet by revolving a hyperbola
x0 = 0;
For i In {0:N-1}
  u = umin + (umax - umin) / (N - 1) * i;
  x = x0 + a * Sqrt(1 + u^2);
  y = x0 + c * u;
  Point(1+i) = {x, y, 0};
EndFor
Point(100) = {x0, -c, 0};
Point(101) = {x0, c, 0};
Line(1) = {100, 1};
Spline(2) = {1:N};
Line(3) = {N, 101};
Line(4) = {101, 100};
Curve Loop(1) = {1:4};
Plane Surface(1) = {1};
Extrude{{0,1,0}, {0,0,0}, 2*Pi} { Surface{1}; }
Recursive Delete { Surface{:}; } // delete construction shapes

// 1 sheet by rotating a line and using ThruSections
x0 = 3;
Point(200) = {x0-Sqrt(2)*a, -c, 0};
Point(201) = {x0, c, -Sqrt(2)*a};
Line(200) = {200, 201};
Wire(200) = 200;
For i In {1:N-1}
  tmp() = Rotate{{0,1,0}, {x0,0,0}, i*2*Pi/(N - 1)}{ Duplicata{ Curve{200};} };
  Wire(200 + i) = tmp();
EndFor
ThruSections{200:200+N-1}
Delete { Curve{:}; }

// 2 sheets by revolution
x0 = 6;
For i In {0:N-1}
  u = umax / (N - 1) * i;
  x = x0 + a * Sinh(u);
  y = c * Cosh(u);
  Point(1000+i) = {x, y, 0};
  Point(2000+i) = {x, -y, 0};
EndFor
Spline(1000) = {1000:1000+N-1};
Spline(2000) = {2000:2000+N-1};
Extrude{{0,1,0}, {x0,0,0}, 2*Pi} { Curve{1000,2000}; }

Mesh.MeshSizeFromCurvature = 20;
