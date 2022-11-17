SetFactory("OpenCASCADE");
Point(1) = {-1, 0, 0};
Point(2) = {0, 3, -0.5};
Line(1) = {1, 2};
Wire(1) = 1;
N = 20;
For i In {1:N-1}
  a() = Rotate{{0,1,0}, {0,0,0}, i*2*Pi/(N - 1)}{ Duplicata{ Curve{1};} };
  Wire(i + 1) = a();
EndFor
ThruSections{1:N}
Delete { Curve{:}; }
Mesh.MeshSizeMax = 0.1;
