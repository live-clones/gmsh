// the built-in CAD kernel, when creating a copy of a surface (using
// "Duplicata"), will automatically create/use the curves with the orientation
// corresponding to the orientation of the curve loop. So in order to avoid
// surprises, one should define the curves with the correct orientation at the
// beginning.

// See https://gitlab.onelab.info/gmsh/gmsh/-/issues/1640

Geometry.CopyMeshingMethod = 1;

Point(1) = {1, 0, 0};
Point(2) = {2, 0, 0};
Point(3) = {0, 1, 0};
Point(4) = {0, 2, 0};

Line(1) = {1,2};
Line(2) = {2,4};
Line(3) = {4,3};
Line(4) = {3,1};

Transfinite Curve {2,4} = 5;
Transfinite Curve {1,-3} = 5 Using Progression 0.5;

Curve Loop(1) = {1,2,3,4};

Plane Surface(1) = {1};

Geometry.AutoCoherence = 1;

Symmetry {1, 0, 0} {Duplicata{Surface{1};}}
Symmetry {0, 1, 0} {Duplicata{Surface{1,5};}}

Transfinite Surface {:};
Recombine Surface {:};
