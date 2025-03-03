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

Mesh.Smoothing = 2;
Mesh.MeshSizeFactor = 0.041;
Mesh.Algorithm = 5; // del2d
Mesh 2;

// spec output file
file = StrCat(StrPrefix(StrRelative(General.FileName)), ".val");

// validate number of elements
n = 847054;
Printf("Number of elements is %g (estimated %g)", Mesh.NbTriangles, n);
If ( Fabs(Mesh.NbTriangles - n) / Mesh.NbTriangles > 0.3 )
  Printf("Error: Number of elements is %g (estimated %g), outside of range",
         Mesh.NbTriangles, n) >> file;
  Error("Number of elements is %g (estimated %g), outside of range",
        Mesh.NbTriangles, n);
Else
  Printf("Successful Verification of requested %g elements", n) >> file;
EndIf

// validate number of nodes
nn = 437712;
Printf("Number of nodes is %g (estimated %g)", Mesh.NbNodes, nn);
If ( Fabs(Mesh.NbNodes - nn) / Mesh.NbNodes > 0.3 )
  Printf("Error: Number of nodes is %g (estimated %g), outside of range",
         Mesh.NbNodes, nn) >> file;
  Error("Number of nodes is %g (estimated %g), outside of range",
        Mesh.NbNodes, nn);
Else
  Printf("Successful Verification of requested %g nodes", nn) >> file;
EndIf

// validate mesh quality
Printf("Average mesh quality is %g", Mesh.AvgQuality);
If ( Mesh.AvgQuality < 0.75 )
  Printf("Error: Average mesh quality is %g, outside of range", Mesh.AvgQuality) >> file;
  Error("Average mesh quality is %g, outside of range", Mesh.AvgQuality);
Else
  Printf("Successful Verification of average mesh quality %g", Mesh.AvgQuality) >> file;
EndIf

// ********** End SPEC validation **********
