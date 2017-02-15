SetFactory("OpenCASCADE");

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthMin = 0.2;
Mesh.CharacteristicLengthMax = 0.2;

Point(1) = {0,0,0};
Point(2) = {1,0,0};
Point(3) = {1,1,0};
Point(4) = {0,1,0};
Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};
Line Loop(1) = {1,2,3,4};
Plane Surface(1) = {1};

Point(5) = {0.2,0.2,0};
Point(6) = {0.5,0.2,0};
Point(7) = {0.5,0.5,0};
Point(8) = {0.2,0.5,0};
Line(5) = {5,6};
Line(6) = {6,7};
Line(7) = {7,8};
Line(8) = {8,5};
Line Loop(2) = {5,6,7,8};
Plane Surface(2) = {2};

Disk(3) = {0.6, 0.6, 0, 0.5, 0.3};

BooleanFragments{ Surface{1}; Delete; }{ Surface{2:3}; Delete; }

For i In {0:5}
  Point(100+i) = {-0.1, Sin(i/9*2*Pi), i};
EndFor
Point(106) = {-0.1, -2, 6};

BSpline(100) = {100:105};
Line(101) = {105:106};

Wire(100) = {100,101};

a() = Extrude { Surface{1:5}; } Using Wire {100};
Delete{ Surface{1:5}; }
