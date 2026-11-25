// Extruded mesh on surfaces meshed with the quasi-structured quadrangle
// algorithm, which subdivides and optimizes the 2D mesh after the first pass:
// the extruded curves and surfaces are made again from the final meshes of
// their sources (they used not to match them: the 3D extrusion failed)

Point(1) = {0, 0, 0}; Point(2) = {3, 0, 0}; Point(3) = {3, 2, 0};
Point(4) = {0, 2, 0}; Point(5) = {1.5, 0, 0}; Point(6) = {1, 2, 0};
Line(1) = {1, 5}; Line(2) = {5, 2}; Line(3) = {2, 3}; Line(4) = {3, 6};
Line(5) = {6, 4}; Line(6) = {4, 1}; Line(7) = {5, 6};
Curve Loop(1) = {1, 7, 5, 6};
Plane Surface(1) = {1};
Curve Loop(2) = {2, 3, 4, -7};
Plane Surface(2) = {2};

Extrude{0, 0, -1}{ Surface{1, 2}; Layers{4}; Recombine; }

Mesh.MeshSizeMax = 0.25;
Mesh.Algorithm = 11;
Mesh 3;

If(Mesh.NbHexahedra == 0)
  Error("No hexahedra created");
EndIf
If(Mesh.NbPrisms || Mesh.NbTriangles)
  Error("%g prisms and %g triangles left", Mesh.NbPrisms, Mesh.NbTriangles);
EndIf
