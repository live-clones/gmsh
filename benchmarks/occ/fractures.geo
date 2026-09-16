SetFactory("OpenCASCADE");
Rectangle(1) = {-0.6,-0.6, 0, 2.2, 2.2};
N = DefineNumber[20, Min 1, Max 200, Step 1, Name "Num fractures"];
For i In {2:N+1}
  h = 0.05+Rand(0.5);
  w = 0.01+Rand(0.1);
  x = Rand(1);
  y = Rand(1);
  alpha = Rand(2*Pi);
  Rectangle(i) = {x, y, 0, w, h};
  Rotate{{0,0,1},{x, y, 0}, alpha}{Surface{i};}
EndFor

Geometry.OCCParallel = 1;

diff = DefineNumber[0, Choices{0="Fragments", 1="Difference"}, Name "Type"];
If(diff)
  BooleanDifference{ Surface{1}; Delete; }{ Surface{2:N+1}; Delete; }
Else
  BooleanFragments{ Surface{1:N+1}; Delete; }{}
EndIf

Mesh.MeshSizeMin = 0.05;
Mesh.MeshSizeMax = 0.05;
