lc = 0.1;

Mesh.RemeshParametrization=1; //(0) harmonic (1) conformal 
Mesh.RemeshAlgorithm=1; //(0) nosplit (1) automatic (2) split only with metis ///Default: 1 

Merge "CubeAniso.msh";
CreateTopology;

Compound Surface(106) = {6};
Compound Surface(115) = {15};
Compound Surface(119) = {19};
Compound Surface(123) = {23};
Compound Surface(127) = {27};
Compound Surface(128) = {28};

Surface Loop(100) = {106,115,119,123,127,128};
Volume(1) = {100};

Field[2] = MathEvalAniso;
Field[2].m11 = "1./(0.1)^2";
Field[2].m12 = "0";
Field[2].m13 = "0";
Field[2].m22 = "y+1/(0.02)^2";
Field[2].m23 = "0";
Field[2].m33 = "1/(0.1)^2";
Background Field = 2;
