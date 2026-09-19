// a mesh of many entities (256 volumes, over 1500 surfaces and 3000 curves):
// the drawing then merges the arrays of each dimension (above 200 entities)
SetFactory("OpenCASCADE");
DefineConstant[ N = 8 ];
For i In {0 : N - 1}
  For j In {0 : N - 1}
    For k In {0 : 3}
      Box(newv) = {1.2 * i, 1.2 * j, 1.2 * k, 1, 1, 1};
    EndFor
  EndFor
EndFor
Mesh.MeshSizeMax = 0.5;
Mesh 3;
General.Trackball = 0;
General.RotationX = 300; General.RotationZ = 30;
