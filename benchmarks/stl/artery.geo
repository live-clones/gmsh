Mesh.RemeshParametrization=0; //(0) harmonic (1) conformal 
Mesh.RemeshAlgorithm=2; //(0) nosplit (1) automatic (2) split metis

Mesh.CharacteristicLengthFactor=0.05;

Merge "artery.stl";
CreateTopology;

Compound Surface(100)={1};
Physical Surface(101)={100};
