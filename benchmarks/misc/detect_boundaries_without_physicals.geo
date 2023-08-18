SetFactory("OpenCASCADE");

Box(1) = {0,0,0, 1,1,1};
Box(2) = {1,0,0, 0.5,0.5, 0.5};
Coherence;
Physical Volume(1) = {1};
Physical Surface(2) = {1,3,5};

bnd() = Abs(CombinedBoundary{ Volume{:}; });
phys() = Physical Surface{:};
For i In {0:#phys()-1}
  bnd() -= Physical Surface{phys(i)};
EndFor
If(#bnd())
  Warning("%g boundary entities are not in physical groups!", #bnd());
EndIf
