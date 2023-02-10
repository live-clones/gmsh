SetFactory("OpenCASCADE");
Box(1) = {0,0,0, 1,1,1};
Physical Surface("Zone_1") = {1,2};
Physical Surface("Zone_2") = {4,5,6};

s() = Physical Surface{:};
For i In {0:#s()-1}
  name = Str(Physical Surface{s(i)});
  If (!StrCmp(name, "Zone_1"))
    Printf("my physical surface is made of", Physical Surface{s(i)});
  EndIf
EndFor
