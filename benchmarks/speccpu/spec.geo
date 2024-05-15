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

// spec output file
file = StrCat(StrPrefix(StrRelative(General.FileName)), ".val");

// validate number of elements
n = 4.5 * N / (fact * Mesh.MeshSizeFactor)^3;
Printf("Number of tet elements is %g (estimated %g)", Mesh.NbTetrahedra, n);
If ( Fabs(Mesh.NbTetrahedra - n) / Mesh.NbTetrahedra > 0.2 )
  Printf("Error: Number of tet elements is %g (estimated %g), outside of range",
         Mesh.NbTetrahedra, n) >> file;
  Error("Number of tet elements is %g (estimated %g), outside of range",
        Mesh.NbTetrahedra, n);
Else
  Printf("Successful Verification of requested %g elements", n) >> file;
EndIf

// validate number of nodes
nn = n / 5;
Printf("Number of nodes is %g (estimated %g)", Mesh.NbNodes, nn);
If ( Fabs(Mesh.NbNodes - nn) / Mesh.NbNodes > 0.2 )
  Printf("Error: Number of nodes is %g (estimated %g), outside of range",
         Mesh.NbNodes, nn) >> file;
  Error("Number of nodes is %g (estimated %g), outside of range",
        Mesh.NbNodes, nn);
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
       minQ, avgQ, maxQ, volQ);
If ( minQ < 0.1 )
  Printf("Error: Min mesh quality is %g, outside of range", minQ) >> file;
  Error("Min mesh quality is %g, outside of range", minQ);
Else
  Printf("Successful Verification of min mesh quality %g", minQ) >> file;
EndIf

// ********** End SPEC validation **********
