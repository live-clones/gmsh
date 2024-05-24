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

Mesh.Smoothing = 3;
Mesh.MeshSizeFactor = 0.1;
Mesh.Algorithm = 5; // del2d
Mesh.Algorithm3D = 10; // hxt
Mesh 3;

// spec output file
file = StrCat(StrPrefix(StrRelative(General.FileName)), ".val");

// validate number of elements
n = 9.06218e+07;
Printf("Number of elements is %g (estimated %g)", Mesh.NbTetrahedra, n) >> file;
If ( Fabs(Mesh.NbTetrahedra - n) / Mesh.NbTetrahedra > 0.03 )
  Printf("Error: Number of elements is %g (estimated %g), outside of range", Mesh.NbTetrahedra, n) >> file;
Else
  Printf("Successful Verification of requested %g elements", n) >> file;
EndIf

// validate number of nodes
nn = 1.47395e+07;
Printf("Number of nodes is %g (estimated %g)", Mesh.NbNodes, nn) >> file;
If ( Fabs(Mesh.NbNodes - nn) / Mesh.NbNodes > 0.1 )
  Printf("Error: Number of nodes is %g (estimated %g), outside of range",
         Mesh.NbNodes, nn) >> file;
Else
  Printf("Successful Verification of requested %g nodes", nn) >> file;
EndIf

// validate mesh quality
Printf("Minimum mesh quality is %g", Mesh.MinQuality);
If ( Mesh.MinQuality < 0.1 )
  Printf("Error: Minimum mesh quality is %g, outside of range", Mesh.MinQuality) >> file;
  Error("Minimum mesh quality is %g, outside of range", Mesh.MinQuality);
Else
  Printf("Successful Verification of minimum mesh quality %g", Mesh.MinQuality) >> file;
EndIf

// ********** End SPEC validation **********
