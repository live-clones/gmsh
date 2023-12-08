SetFactory("OpenCASCADE");

v = 0.01;
omega = 0.3;
c = 0.2;
p = 1;
For t In {0:41}
  x = (v * t + c) * Cos(omega * t);
  y = (v * t + c) * Sin(omega * t);
  Point(p++) = {x, y, 0};
EndFor
Spline(1) = {1:p-1};

l = 0.05;
Point(100) = {c-l,0,0};
Point(101) = {c+l,0,0};
Line(2) = {100, 101};
Wire(1) = {1};
Extrude{ Curve{2}; } Using Wire {1}
Recursive Delete { Curve{1}; Point{:}; }

h = 0.02;
Extrude{0,0,h} { Surface{1}; Layers{5}; Recombine; }
