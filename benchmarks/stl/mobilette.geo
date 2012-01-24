Mesh.Algorithm = 2; //(1=MeshAdapt, 2=Automatic, 5=Delaunay, 6=Frontal, 7=bamg)
Mesh.CharacteristicLengthMin=1.5;
Mesh.CharacteristicLengthMax=2.5;
Mesh.RemeshAlgorithm=1;
Mesh.RemeshParametrization=1;//(0) harmonic (1) conformal
Mesh.RecombinationAlgorithm=1;
//Mesh.RecombineAll=1;
Geometry.HideCompounds = 0;

// merge reclassified STL
Merge "mobilette-class.msh";

// oringinal STL is a bit coarse: refine it once!
RefineMesh;

CreateTopology;

ll[] = Line "*";
For j In {0 : #ll[]-1}
  Compound Line(newl) = ll[j];
EndFor

ss[] = Surface "*";
s = news;
For i In {0 : #ss[]-1}
  Compound Surface(s+i) = ss[i];
EndFor

Surface Loop(1) = {s : s + #ss[]-1};
Volume(1) = {1};

Physical Surface(1) = {s : s + #ss[]-1};
Physical Volume(1) = 1;
