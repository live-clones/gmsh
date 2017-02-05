SetFactory("OpenCASCADE");

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthMin = 1;
Mesh.CharacteristicLengthMax = 1;

Macro dendrite
  For i In {1:5}
    z = -2+7*i;
    r = 0.4 + 0.2*Sin(2*Pi*i/5.);
    Point(nump+1) = {x,y,z};
    Point(nump+2) = {x+r,y,z};
    Point(nump+3) = {x,y+r,z};
    Point(nump+4) = {x-r,y,z};
    Point(nump+5) = {x,y-r,z};
    Circle(numc+1) = {nump+2,nump+1,nump+3};
    Circle(numc+2) = {nump+3,nump+1,nump+4};
    Circle(numc+3) = {nump+4,nump+1,nump+5};
    Circle(numc+4) = {nump+5,nump+1,nump+2};
    edges~{i}() = {numc+1:numc+4};
    nump += 5;
    numc += 4;
  EndFor
  numr += 1;
  ThruSections(numr) = {edges~{1}(),edges~{2}(),edges~{3}(),edges~{4}(),edges~{5}()};
  reg() += numr;
Return

Sphere(1) = {0, 0, 0, 7};

reg() = {};
nump = 0; numc = 0; numr = 100;
For x In{-2:2:2}
  For y In{-2:2:2}
    Call dendrite;
  EndFor
EndFor

DefineConstant[
  op = {0, Choices{0="None", 1="Union", 2="Intersection", 3="Difference", 4="Fragments"},
    Name "Boolean operation" }
  sph = {0, Choices{0,1}, Visible op == 4,
         Name "Fuse sphere fragments?" }
];

// boolean operations can explicitly create an entity tag with the form
// "op(tag)={}{};", or let Gmsh decide with the form "op{}{}". The first form
// can only be used if the result of the boolean operation is a single
// entity. Only the second form returns the list of created entities.

If(op == 1)
  BooleanUnion(100) = { Volume{1}; Delete; }{ Volume{reg()}; Delete; };
ElseIf(op == 2)
  aa() = BooleanIntersection { Volume{1}; Delete; }{ Volume{reg()}; Delete; };
  Printf("intersection created volumes ", aa());
ElseIf(op == 3)
  BooleanDifference(100) = { Volume{1}; Delete; }{ Volume{reg()}; Delete; };
ElseIf(op == 4)
  BooleanFragments { Volume{1}; Delete; }{ Volume{reg()}; Delete; }
  If(sph)
    BooleanUnion{ Volume{1}; Delete; }{ Volume{2:#reg()+1}; Delete;}
  EndIf
EndIf
