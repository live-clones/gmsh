SetFactory("OpenCASCADE");

Point(1) = {0,0,0}; Point(2) = {0,0,-40};
Line(1) = {1,2};

Box(1)={-50,-50,-50,100,100,100};
N=9;
For i In {1:N}
  Cylinder(1+i) = {0, 0, -4*i, 0, 0, -4, 0.01, 2*Pi};
EndFor
BooleanFragments{ Volume{1}; Delete; }{ Volume{1+1:1+N}; Delete; }
Physical Volume ( "c",11 ) = {1+1:1+N};
Physical Volume ( "d",12 ) = {1+N+1};

Field[1] = Distance;
Field[1].NNodesByEdge = 10000;
Field[1].EdgesList = {1};

Field[2] = Threshold;
Field[2].IField = 1;
Field[2].LcMin = 0.02;
Field[2].LcMax = 20;
Field[2].DistMin = 0.05;
Field[2].DistMax = 10;

Field[3] = Min;
Field[3].FieldsList = {2};
Background Field = 3;
