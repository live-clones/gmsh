Point(1) = {0, 0, 0, 0.1};
Point(2) = {0, 1, 0, 0.1};
Point(3) = {0, 1, 1, 0.1};
Point(4) = {0, 0, 1, 0.1};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1:4};
s() = {1};
Plane Surface(s(0)) = {1};
// N cubes to have representative number of surfaces
N = 5;
For i In {1:N}
  s() = Extrude{1, 0, 0}{ Surface{s(0)}; };
EndFor
// use Delaunay
Mesh.Algorithm = 5;
Mesh.Algorithm3D = 10;
Mesh 3;
n = 4.5 * N / (0.1 * Mesh.MeshSizeFactor)^3;

file1 = "spec.val";
Printf("Number of tet elements is %g (estimated %g)", Mesh.NbTetrahedra, n);

If ( (Mesh.NbTetrahedra - n) / Mesh.NbTetrahedra > 0.2 )
  Printf("Error: Number of tet elements is %g (estimated %g), outside of range", Mesh.NbTetrahedra, n) >> file1;
  Error("Number of tet elements is %g (estimated %g), outside of range", Mesh.NbTetrahedra, n);
Else
  Printf("Successful Verification of requested %g elements", n) >> file1;
EndIf
