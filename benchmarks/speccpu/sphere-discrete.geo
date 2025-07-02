// merge a surface mesh (any format will work: .msh, .unv, etc.)

Merge "sphere-surf.stl";

// add a geometrical volume

Surface Loop(1) = {1};
Volume(1) = {1};

// use this to force a coarse mesh inside
Mesh.MeshSizeExtendFromBoundary = 0;
Mesh.MeshSizeMax = 0.5;

// ********** Begin SPEC validation **********

Mesh.MeshSizeFactor = 0.070;
Mesh.Algorithm3D = 10; // hxt
Mesh 3;

// spec output file
file = StrCat(StrPrefix(StrRelative(General.FileName)), ".val");

// validate number of elements
n = 360989;
Printf("Number of elements is %g (estimated %g)", Mesh.NbTetrahedra, n);
If ( Fabs(Mesh.NbTetrahedra - n) / Mesh.NbTetrahedra > 0.3 )
  Printf("Error: Number of elements is %g (estimated %g), outside of range",
         Mesh.NbTetrahedra, n) >> file;
  Error("Number of elements is %g (estimated %g), outside of range",
        Mesh.NbTetrahedra, n);
Else
  Printf("Successful Verification of requested %g elements", n) >> file;
EndIf

// validate number of nodes
nn = n / 5;
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
