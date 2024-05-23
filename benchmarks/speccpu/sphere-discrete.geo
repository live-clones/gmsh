// merge a surface mesh (any format will work: .msh, .unv, etc.)

Merge "sphere-surf.stl";

// add a geometrical volume

Surface Loop(1) = {1};
Volume(1) = {1};

// use this to force a coarse mesh inside
Mesh.MeshSizeExtendFromBoundary = 0;
Mesh.MeshSizeMax = 0.5;

// ********** Begin SPEC validation **********
Mesh 2;
Mesh 3;
n = 360989;
file = StrCat(StrPrefix(StrRelative(General.FileName)), ".val");
Printf("Number of tet elements is %g (estimated %g)", Mesh.NbTetrahedra, n) >> file;
If ( Fabs(Mesh.NbTetrahedra - n) / Mesh.NbTetrahedra > 0.04 )
  Printf("Error: Number of tet elements is %g (estimated %g), outside of range", Mesh.NbTetrahedra, n) >> file;
Else
  Printf("Successful Verification of requested %g elements", n) >> file;
EndIf

// validate number of nodes
nn = n / 6;
Printf("Number of nodes is %g (estimated %g)", Mesh.NbNodes, nn) >> file;
If ( Fabs(Mesh.NbNodes - nn) / Mesh.NbNodes > 0.1 )
  Printf("Error: Number of nodes is %g (estimated %g), outside of range",
         Mesh.NbNodes, nn) >> file;
Else
  Printf("Successful Verification of requested %g nodes", nn) >> file;
EndIf

// validate mesh quality
Plugin(AnalyseMeshQuality).ICNMeasure = 1;
Plugin(AnalyseMeshQuality).CreateView = 1;
Plugin(AnalyseMeshQuality).Run;
Plugin(Integrate).View = 0;
Plugin(Integrate).Run;
Plugin(MeshVolume).Run;
minQ = View[0].Min;
maxQ = View[0].Max;
intQ = View[1].Min;
volQ = View[2].Min;
avgQ = intQ / volQ;
Printf("Min/Avg/Max quality is %g / %g / %g (mesh volume is %g)",
       minQ, avgQ, maxQ, volQ) >> file;
If ( minQ < 0.1 )
  Printf("Error: Min mesh quality is %g, outside of range", minQ) >> file;
Else
  Printf("Successful Verification of min mesh quality %g", minQ) >> file;
EndIf

// ********** End SPEC validation **********
