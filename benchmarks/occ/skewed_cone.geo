SetFactory("OpenCASCADE");
Cone(1) = {0,0,0, 1,0,0, 1,0};
s = DefineNumber[0, Name "skew", Min -2, Max 2, Step 0.1];
Affine{ 1,0,0,0, s,1,0,0, 0,0,1,0 }{ Volume{1}; }
