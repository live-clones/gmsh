
//BLOSSOM_QUAD
Mesh.Algorithm = 8; //delquad
Mesh.RecombinationAlgorithm=1;//blossom

//REPARAM
//Mesh.RemeshParametrization=1; //(0) harmonic (1) conformal 
//Mesh.RemeshAlgorithm=0; //(0) nosplit (1) automatic (2) split metis

Mesh.CharacteristicLengthFactor=0.08;

Merge "Cone_1.brep";

Recombine Surface{1};