SetFactory("OpenCASCADE");

DefineConstant[
  rmin = {0.05, Min 0.01, Max 0.9, Step 0.01, Name "Min radius"}
  rmax = {0.1, Min 0.01, Max 0.9, Step 0.01, Name "Max radius"}
  n = {10, Min 1, Max 100, Step 1, Name "Number of spheres"}
  field = {0, Choices{0,1}, Name "Use mesh size field?"}
];

For i In {1:n}
  r = rmin + Rand(rmax - rmin);
  x = Rand(1);
  y = Rand(1);
  z = Rand(1);
  Sphere(i) = {x, y, z, r};
  //Sphere(i) = {x, y, z, r,  -Pi/3, Pi/3};
  //Cylinder(i) = {x-r, y, z, x+r, y, z, r};
  p = newp;
  Point(p) = {x, y, z};
  Field[i] = Distance;
  Field[i].NodesList = {p};
  Field[n+i] = Threshold;
  Field[n+i].IField = i;
  Field[n+i].LcMin = r / 6;
  Field[n+i].LcMax = 0.3;
  Field[n+i].DistMin = r;
  Field[n+i].DistMax = 4*r;
EndFor

Block(n+1) = {-2*rmax,-2*rmax,-2*rmax, 1+4*rmax,1+4*rmax,1+4*rmax};

BooleanFragments{ Volume{n+1}; Delete; }{ Volume{1:n}; Delete; }

Field[2*n+1] = Min;
Field[2*n+1].FieldsList = {n+1:2*n};

If(field)
  Background Field = 2*n+1;
  Mesh.CharacteristicLengthExtendFromBoundary = 0;
  //Field[2*n+2] = Octree;
  //Field[2*n+2].InField = 2*n+1;
  //Background Field = 2*n+2;
Else
  Mesh.CharacteristicLengthFromCurvature = 1;
  Mesh.MinimumElementsPerTwoPi = 10;
EndIf
