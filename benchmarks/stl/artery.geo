Mesh.RemeshParametrization=1; //(0) harmonic (1) conformal 
Mesh.RemeshAlgorithm=1; //(0) nosplit (1) automatic (2) split metis

Mesh.CharacteristicLengthFactor=0.05;

//merge the stl triangulation
Merge "artery.stl";
CreateTopology;

Compound Surface(100)={1} ;

Physical Surface(101)={100};
