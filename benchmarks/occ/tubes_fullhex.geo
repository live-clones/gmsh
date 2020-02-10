// Gmsh project created on Wed Mar 27 07:12:43 2019
SetFactory("OpenCASCADE");

DefineConstant[
  Tc1= {0.2, Min -1, Max 1, Step 0.01, Name "Thickness C1"},
  Tc2= {0.2, Min -1, Max 1, Step 0.01, Name "Thickness C2"},
  Lc1= {5, Min 0, Max 10, Step 0.1, Name "Length C1"},
  Lc2= {5, Min 0, Max 10, Step 0.1, Name "Length C2"},
  Rc1= {2, Min 0, Max 5, Step 0.1, Name "Radius C1"},
  Rc2= {1, Min 0, Max 5, Step 0.1, Name "Radius C2"},
  Lcc= {0.1, Min 0, Max 1, Step 0.01, Name "Critical mesh size"},
  Lco= {0.2, Min 0, Max 1, Step 0.01, Name "Other mesh size"}
];

Cylinder(1) = {-Lc1/2, 0, 0, Lc1, 0, 0, Tc1 + Rc1, 2*Pi};
Cylinder(2) = {0, 0, 0, 0, Lc2, 0, Tc2 + Rc2, 2*Pi};

Cylinder(3) = {-Lc1/2, 0, 0, Lc1, 0, 0, Rc1, 2*Pi};
Cylinder(4) = {0, 0, 0, 0, Lc2, 0, Rc2, 2*Pi};

BooleanDifference{ Volume{1}; Delete; }{ Volume{3}; Delete; }
BooleanDifference{ Volume{2}; Delete; }{ Volume{4}; Delete; }
BooleanFragments{ Volume{1}; Delete; }{ Volume{2}; Delete; }
Recursive Delete { Volume{3,5}; }

Box(5) = {0, - Tc1 - Rc1 - 0.1, - (2*Tc1 + 2*Rc1 + 0.2),
          2*Lc1, 2*Tc1 + 2*Rc1 + 2*Lc2, 2*Tc1 + 2*Rc1 + 0.2};

BooleanIntersection{ Volume{1,2,4}; Delete; }{ Volume{5}; Delete; }

Box(6) = {Rc2+Tc2, - Tc1 - Rc1 - 0.1, - (2*Tc1 + 2*Rc1 + 0.2),
          2*Lc1, 2*Tc1 + 2*Rc1 + 2*Lc2, 2*Tc1 + 2*Rc1 + 0.2};

Coherence;
Recursive Delete { Volume{7}; }

Transfinite Line {:} = 10;
Transfinite Surface {:};
Recombine Surface {:};
Transfinite Volume {:};
Recombine Volume {:};
