// The edges and faces of a mesh (Mesh.CreateEdges, Mesh.CreateFaces) are saved
// in MSH 4.1 and 4.2 files, in ASCII and in binary, and read back: prisms and
// hexahedra, whose faces are triangles and quadrangles.

Point(1) = {0, 0, 0}; Point(2) = {1, 0, 0}; Point(3) = {1, 1, 0};
Point(4) = {0, 1, 0}; Point(5) = {2, 0, 0}; Point(6) = {2, 1, 0};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 1};
Line(5) = {2, 5}; Line(6) = {5, 6}; Line(7) = {6, 3};
Curve Loop(1) = {1, 2, 3, 4}; Plane Surface(1) = {1};
Curve Loop(2) = {5, 6, 7, -2}; Plane Surface(2) = {2};
Recombine Surface{2};
Mesh.MeshSizeMax = 0.2;
Extrude {0, 0, 1} { Surface{1, 2}; Layers{5}; Recombine; }
Mesh 3;

Mesh.CreateEdges = 1;
Mesh.CreateFaces = 1;
// (MSH 4.1 files hold the triangles and the quadrangles, 4.2 files blocks of
// faces with the same number of nodes)
files[] = Str("faces_out.msh", "faces_binary_out.msh", "faces_41_out.msh",
              "faces_41_binary_out.msh");
For i In {0 : 3}
  Mesh.MshFileVersion = (i < 2) ? 4.2 : 4.1;
  Mesh.Binary = i % 2;
  Save Str(files[i]);
EndFor
Mesh.MshFileVersion = 4.2;
Mesh.Binary = 0;
Mesh.CreateEdges = 0;
Mesh.CreateFaces = 0;
edges = Mesh.NbEdges;
faces = Mesh.NbFaces;
If(!edges || !faces)
  Error("No edges or faces created (%g and %g)", edges, faces);
EndIf

For i In {0 : 3}
  Delete Model;
  Merge Str(files[i]);
  If(Mesh.NbEdges != edges || Mesh.NbFaces != faces)
    Error(StrCat(Str(files[i]), ": %g edges and %g faces read, expected %g and %g"), Mesh.NbEdges, Mesh.NbFaces, edges, faces);
  EndIf
EndFor
