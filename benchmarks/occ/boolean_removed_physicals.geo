SetFactory("OpenCASCADE");

// the physical groups no longer refer to the entities removed by OpenCASCADE
// operations: a group left without entities is deleted, which frees its tag
// (#3168)
Rectangle(1) = {0, 0, 0, 1, 1, 0};
Rectangle(2) = {2, 0, 0, 1, 1, 0};
Rectangle(3) = {4, 0, 0, 1, 1, 0};
Physical Surface("left", 1) = {1};
Physical Surface("middle", 2) = {2};
Physical Surface("right", 3) = {3};
Physical Surface("left and right", 4) = {1, 3};
Physical Curve("right boundary", 1) = {Boundary{ Surface{3}; }};

// rectangle 3 does not intersect rectangle 4: it is removed
Rectangle(4) = {0.5, -1, 0, 2, 3, 0};
BooleanIntersection{ Surface{1:3}; Delete; }{ Surface{4}; Delete; }
Recursive Delete{ Surface{2}; }

s() = Physical Surface{4};
If(#s() != 1 || s(0) != 1)
  Error("Physical surface 4 should only contain surface 1");
EndIf
s() = Physical Surface{2, 3};
c() = Physical Curve{1};
If(#s() || #c())
  Error("Physical surfaces 2 and 3 and physical curve 1 should be empty");
EndIf

// their tags are free again
Physical Surface("new middle", 2) = {1};
Physical Surface("new right", 3) = {1};
Physical Curve("new boundary", 1) = {Boundary{ Surface{1}; }};
c() = Physical Curve{1};
If(#c() != 4)
  Error("Physical curve 1 should contain the 4 curves of surface 1");
EndIf
