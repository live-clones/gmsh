SetFactory("OpenCASCADE");
DefineConstant[
  N = {10, Min 1, Max 20, Step 1, Name "Number of cubes"}
  n = {5, Min 1, Max 100, Step 1, Name "Number of elements per edge"}
];

// create N connected cubes, each double of the size of the previous one
off = 0;
For i In {1:N}
  l = 2^(i - 1);
  Box(i) = {off, 0, 0, l, l, l};
  off += l;
EndFor
Coherence;

// create a Constant field for each volume, targetting a n elements per edge
all() = Volume{:};
For i In {0 : #all() - 1}
  v = Mass Volume{all(i)};
  lc = v^(1/3) / n;
  Field[i + 1] = Constant;
  Field[i + 1].IncludeBoundary = 1;
  Field[i + 1].VIn = lc;
  Field[i + 1].VOut = 1e200;
  Field[i + 1].VolumesList = {all(i)};
  Printf("Max element size for volume %g: %f", i+1, lc);
EndFor
Field[#all() + 1] = Min;
Field[#all() + 1].FieldsList = {1:#all()};
Background Field = #all() + 1;
