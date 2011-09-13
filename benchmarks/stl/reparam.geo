Mesh.RemeshParametrization=0; //(0) harmonic (1) conformal 
Mesh.RemeshAlgorithm=1; //(0) nosplit (1) automatic (2) split metis
//Mesh.Algorithm = 6; //(1=MeshAdapt, 2=Automatic, 5=Delaunay, 6=Frontal, 7=bamg) 

Mesh.CharacteristicLengthFactor=0.5;

Merge "reparamINPUT.msh";
CreateTopology;

Compound Line(10)={1};
Compound Line(20)={2};
Compound Line(30)={3};
Compound Line(40)={4};
Compound Surface(10)={5};
