Mesh.RemeshParametrization=1; //(0) harmonic (1) conformal 
Mesh.RemeshAlgorithm=0; //(0) nosplit (1) automatic (2) split metis

Mesh.CharacteristicLengthFactor=0.2;
//Mesh.Algorithm = 8; //(1=MeshAdapt, 2=Automatic, 5=Delaunay, 6=Frontal, 7=bamg, 8=delquad)
//Mesh.RecombinationAlgorithm = 1;

Merge "capot.brep";

Compound Line(1000) = {47,50};
Compound Line(1001) = {44,46};

Compound Surface(100) = {1, 8, 15, 17, 16, 18, 9, 2, 3, 10, 7, 14, 11, 4, 12, 5, 6, 13} ;

Physical Surface(100)={100};
Recombine Surface {100};
