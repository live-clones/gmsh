SetFactory("OpenCASCADE");

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthMin = 0.1;
Mesh.CharacteristicLengthMax = 0.1;

// build volume through (closed) line loops
Circle(1) = {0,0,0, 0.2};
Circle(2) = {0.1,0.04,1, 0.3};
Circle(3) = {0.03,-0.08,2, 0.25};
For i In {1:3}
  Line Loop(i) = i;
EndFor
ThruSections(1) = {1:3};

Circle(4) = {1,0,0, 0.2};
Circle(5) = {1.1,0.04,1, 0.3};
Circle(6) = {1.03,-0.08,2, 0.25};
For i In {4:6}
  Line Loop(i) = i;
EndFor
Ruled ThruSections(2) = {4:6};

// build surfaces through (closed) line loops
Circle(7) = {2,0,0, 0.2};
Circle(8) = {2.1,0.04,1, 0.3};
Circle(9) = {2.03,-0.08,2, 0.25};
For i In {7:9}
  Line Loop(i) = i;
EndFor
ThruSections{7:9}

Circle(10) = {3,0,0, 0.2};
Circle(11) = {3.1,0.04,1, 0.3};
Circle(12) = {3.03,-0.08,2, 0.25};
For i In {10:12}
  Line Loop(i) = i;
EndFor
Ruled ThruSections{10:12}

// build surfaces through (open) wires
Circle(13) = {4,0,0, 0.2, Pi/3};
Circle(14) = {4.1,0.04,1, 0.3, Pi/2};
Circle(15) = {4.03,-0.08,2, 0.25, Pi/3};
For i In {13:15}
  Wire(i) = i;
EndFor
ThruSections{13:15}

Circle(16) = {5,0,0, 0.2, Pi/3};
Circle(17) = {5.1,0.04,1, 0.3, Pi/2};
Circle(18) = {5.03,-0.08,2, 0.25, Pi/3};
For i In {16:18}
  Wire(i) = i;
EndFor
Ruled ThruSections{16:18}
