lc = 0.1;
Point(1) = {2.0,0.0,0.0,lc};
Point(2) = {2.0,1,0.0,lc};
Point(3) = {1,0,0.0,lc};
Point(4) = {3,0,0.0,lc};
Point(5) = {2,-1,0.0,lc};
Circle(1) = {4,1,2};

Circle(2) = {2,1,3};
Circle(3) = {3,1,5};
Circle(4) = {5,1,4};
Line Loop(5) = {4,1,2,3};
Plane Surface(6) = {5};

Extrude { {0.0,1,0}, {0,0.0,0.0}, 1*3.14159} { Surface{6}; }
//Recombine Surface {6, 27, 23, 15, 19, 28};

// ********** Begin SPEC validation **********

Mesh.MeshSizeFactor = 0.3;
Mesh.Algorithm = 5; // del2d
Mesh.Algorithm3D = 10; // hxt
Mesh 3;
n = 3.3e6;
file = StrCat(StrPrefix(StrRelative(General.FileName)), ".val");
Printf("Number of tet elements is %g (estimated %g)", Mesh.NbTetrahedra, n);
If ( Fabs(Mesh.NbTetrahedra - n) / Mesh.NbTetrahedra > 0.2 )
  Printf("Error: Number of tet elements is %g (estimated %g), outside of range", Mesh.NbTetrahedra, n) >> file;
  Error("Number of tet elements is %g (estimated %g), outside of range", Mesh.NbTetrahedra, n);
Else
  Printf("Successful Verification of requested %g elements", n) >> file;
EndIf

// ********** End SPEC validation **********
