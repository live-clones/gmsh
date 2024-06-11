SetFactory("OpenCASCADE");

Rectangle(1) = {0,0,0, 1,1};

n = 100;
For i In {0:n}
  x1 = Rand(1);
  y1 = Rand(1);
  x2 = Rand(1);
  y2 = Rand(1);
  Point(100 + 2*i) = {x1, y1, 0};
  Point(100 + 2*i+1) = {x2, y2, 0};
  Line(100 + i) = {100 + 2*i, 100 + 2*i + 1};
EndFor

BooleanFragments{ Curve{100 : 100 + n}; Delete; }{ Surface{1}; Delete; }
