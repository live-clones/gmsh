SetFactory("OpenCASCADE");

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthMin = 0.1;
Mesh.CharacteristicLengthMax = 0.1;

// build volume through closed line loops
Disk(1) = {0,0,0, 0.2};
Disk(2) = {0.1,0.04,1, 0.3};
Disk(3) = {0.03,-0.08,2, 0.25};
For i In {1:3}
  Line Loop(i) = Boundary{ Surface{i}; };
  Delete { Surface{i}; }
EndFor
ThruSections(1) = {1:3};

// build volume through closed line loops
Disk(4) = {1,0,0, 0.2};
Disk(5) = {1.1,0.04,1, 0.3};
Disk(6) = {1.03,-0.08,2, 0.25};
For i In {4:6}
  Line Loop(i) = Boundary{ Surface{i}; };
  Delete { Surface{i}; }
EndFor
Ruled ThruSections(2) = {4:6};

// build surfaces through closed or open line "loops"
Disk(7) = {2,0,0, 0.2};
Disk(8) = {2.1,0.04,1, 0.3};
Disk(9) = {2.03,-0.08,2, 0.25};
For i In {7:9}
  Line Loop(i) = Boundary{ Surface{i}; };
  Delete { Surface{i}; }
EndFor
a() = ThruSections{7:9};

Disk(10) = {3,0,0, 0.2};
Disk(11) = {3.1,0.04,1, 0.3};
Disk(12) = {3.03,-0.08,2, 0.25};
For i In {10:12}
  Line Loop(i) = Boundary{ Surface{i}; };
  Delete { Surface{i}; }
EndFor
b() = Ruled ThruSections{10:12}; // builds ruled surfaces

n = 100;
Point(n+1) = {0,-2,0};
Point(n+2) = {0.5,-1.5,0};
Point(n+3) = {0,-1.5,0};
Circle(n+1) = {n+1,n+3,n+2};
Point(n+4) = {0,-2,1};
Point(n+5) = {0.7,-1.3,1};
Point(n+6) = {0,-1.3,1};
Circle(n+2) = {n+4,n+6,n+5};

Line Loop(n+1) = {n+1}; // not a loop... just a wire
Line Loop(n+2) = {n+2};
c() = ThruSections{n+1,n+2};
