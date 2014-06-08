Merge "bug_spheres.brep";

Mesh.RemeshAlgorithm = 1; // (0) no split (1) automatic (2) automatic only with metis
Mesh.RemeshParametrization = 7; // (0) harmonic (1) conformal spectral (7) conformal finite ele

ss[] = Surface "*";
s = 10000;
For i In {0 : #ss[]-1}
  Compound Surface(s+i) = ss[i];
EndFor
