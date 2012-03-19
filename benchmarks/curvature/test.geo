 Mesh.RemeshParametrization=0; //(0) harmonic (1) conformal
 Mesh.RemeshAlgorithm=1; //(0) nosplit (1) automatic (2) split only with metis 
 
 Mesh.Algorithm=1; //(1=MeshAdapt, 2=Automatic, 5=Delaunay, 6=Frontal, 7=bamg, 8=delquad)

 //Mesh.CharacteristicLengthFactor= 0.1;

 Mesh.CharacteristicLengthFromCurvature=1; //-clcurv
 Mesh.CharacteristicLengthFromPoints = 0;
 Mesh.CharacteristicLengthMin = 0.001;
 Mesh.CharacteristicLengthMax = 3.00;
 Mesh.LcIntegrationPrecision=1.e-5;
 Mesh.MinimumCirclePoints=20; 
 Mesh.CharacteristicLengthExtendFromBoundary=0;

 Merge "Sphere.stl";
 //Merge "TorusInput.stl";


 //Merge "DistanceFromOrigin.bgm";
 //Merge "hop.bgm";
 //Background Mesh View[0];
 //Field[1] = MathEval;	
 //Field[1].F = "0.1*sqrt(x^2 + y^2 + z^2)";
 //Background Field = 1;

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


Physical Surface(1) = {s : s + #ss[]-1};
