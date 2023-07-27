SetFactory("OpenCASCADE");
Box(1) = {0,0,0,1,1,1};
Box(2) = {1,0,0,2,2,2};
Box(3) = {3,0,0,4,4,4};
Box(4) = {7,0,0,8,8,8};
Coherence;
allv() = Volume{:};
For i In {0 : #allv() - 1}
  v = Mass Volume{allv(i)};
  lc = v^(1/3) / 5;
  Field[i + 1] = Constant;
  Field[i + 1].IncludeBoundary = 1;
  Field[i + 1].VIn = lc;
  Field[i + 1].VOut = 1000;
  Field[i + 1].VolumesList = {allv(i)};
  Printf("Max element size for volume %g: %f", i+1, lc);
EndFor
Field[#allv() + 1] = Min;
Field[#allv() + 1].FieldsList = {1:#allv()};
Background Field = #allv() + 1;
