SetFactory("OpenCASCADE");

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthMin = 1;
Mesh.CharacteristicLengthMax = 1;

For i In {1:10}
  Point(i) = {i, Sin(i/9*2*Pi), 0};
EndFor
Line(1) = {1,10};
Bezier(2) = {1:10};
BSpline(3) = {1:10};
