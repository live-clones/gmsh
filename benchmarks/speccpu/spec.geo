fact = 0.1;
Point(1) = {0, 0, 0, fact};
Point(2) = {0, 1, 0, fact};
Point(3) = {0, 1, 1, fact};
Point(4) = {0, 0, 1, fact};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1:4};
s() = {1};
Plane Surface(s(0)) = {1};

// N cubes to have representative number of surfaces
DefineConstant[ N = {5, Name "Number of cubes"} ];
For i In {1:N}
  s() = Extrude{1, 0, 0}{ Surface{s(0)}; };
EndFor


// ********** Begin SPEC validation **********

Mesh 3;
n = 4.5 * N / (fact * Mesh.MeshSizeFactor)^3;
file = StrCat(StrPrefix(StrRelative(General.FileName)), ".val");
Printf("Number of tet elements is %g (estimated %g)", Mesh.NbTetrahedra, n);
If ( Fabs(Mesh.NbTetrahedra - n) / Mesh.NbTetrahedra > 0.2 )
  Printf("Error: Number of tet elements is %g (estimated %g), outside of range", Mesh.NbTetrahedra, n) >> file;
  Error("Number of tet elements is %g (estimated %g), outside of range", Mesh.NbTetrahedra, n);
Else
  Printf("Successful Verification of requested %g elements", n) >> file;
EndIf

// ********** End SPEC validation **********
