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

//Mesh.MeshSizeFactor = 0.025;
//Mesh.Algorithm = 5; // del2d
//Mesh.ElementOrder = 2;
Mesh 2;
//n = 2.2e6;
n = 847054;
file = StrCat(StrPrefix(StrRelative(General.FileName)), ".val");
Printf("Number of tri elements is %g (estimated %g)", Mesh.NbTriangles, n) >> file;
If ( Fabs(Mesh.NbTriangles - n) / Mesh.NbTriangles > 0.03 )
  Printf("Error: Number of tri elements is %g (estimated %g), outside of range", Mesh.NbTriangles, n) >> file;
Else
  Printf("Successful Verification of requested %g elements", n) >> file;
EndIf

// validate number of nodes
nn = 437712;
Printf("Number of nodes is %g (estimated %g)", Mesh.NbNodes, nn) >> file;
If ( Fabs(Mesh.NbNodes - nn) / Mesh.NbNodes > 0.2 )
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
// Plugin(MeshVolume).Run;
minQ = View[0].Min;
maxQ = View[0].Max;
// intQ = View[1].Min;
volQ = 0;
avgQ = 1;
Printf("Min/Avg/Max quality is %g / %g / %g (mesh volume is %g)",
       minQ, avgQ, maxQ, volQ) >> file;
If ( minQ < 0.1 )
  Printf("Error: Min mesh quality is %g, outside of range", minQ) >> file;
Else
  Printf("Successful Verification of min mesh quality %g", minQ) >> file;
EndIf

// ********** End SPEC validation **********
