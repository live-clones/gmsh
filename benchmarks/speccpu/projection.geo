//
Point(1) = {0,0,0,1};
Point(2) = {0,10,0,1};
Line(1) = {2,1};
Extrude { {50.0,0.0,0.0}, {1,0,0}, {0,5,0}, 2*Pi}{ Line {1}; Recombine;Layers{50};}
//
Point(1000) = {0,0,20,1};
Point(2000) = {0,10,20,1};
Line(1000) = {2000,1000};
Extrude { {50.0,0.0,0.0}, {1,0,0}, {0,5,20}, 2*Pi} { Line {1000}; }

// ********** Begin SPEC validation **********

Mesh.MeshSizeFactor = 0.025;
Mesh.Algorithm = 5; // del2d
//Mesh.ElementOrder = 2;
Mesh 2;
n = 2.2e6;
file = StrCat(StrPrefix(StrRelative(General.FileName)), ".val");
Printf("Number of tri elements is %g (estimated %g)", Mesh.NbTriangles, n);
If ( Fabs(Mesh.NbTriangles - n) / Mesh.NbTriangles > 0.2 )
  Printf("Error: Number of tri elements is %g (estimated %g), outside of range", Mesh.NbTriangles, n) >> file;
  Error("Number of tri elements is %g (estimated %g), outside of range", Mesh.NbTriangles, n);
Else
  Printf("Successful Verification of requested %g elements", n) >> file;
EndIf

// ********** End SPEC validation **********
