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

Mesh.MeshSizeFactor = 0.1;
Mesh.Algorithm = 5; // del2d
Mesh.Algorithm3D = 10; // hxt
Mesh 3;
n = 9.06218e+07;
file = StrCat(StrPrefix(StrRelative(General.FileName)), ".val");
Printf("Number of tet elements is %g (estimated %g)", Mesh.NbTetrahedra, n) >> file;
If ( Fabs(Mesh.NbTetrahedra - n) / Mesh.NbTetrahedra > 0.03 )
  Printf("Error: Number of tet elements is %g (estimated %g), outside of range", Mesh.NbTetrahedra, n) >> file;
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
