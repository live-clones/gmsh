/*********************************************************************
 *
 *  Gmsh tutorial 16
 *
 *  Constructive Solid Geometry, OpenCASCADE geometry kernel
 *
 *********************************************************************/

// Instead of constructing a model in a bottom-up fashion with Gmsh's built-in
// geometry kernel, starting with version 3 Gmsh allows you to directly use
// alternative geometry kernels. Let us use the OpenCASCADE kernel:

SetFactory("OpenCASCADE");

// And let's build the same model as in t5.geo, but using constructive solid
// geometry:

Box(1) = {0,0,0, 1,1,1};
Box(2) = {0,0,0, 0.5,0.5,0.5};
BooleanDifference(3) = { Volume{1}; Delete; }{ Volume{2}; Delete; };
x = 0 ; y = 0.75 ; z = 0 ; r = 0.09 ;
For t In {1:5}
  x += 0.166 ;
  z += 0.166 ;
  Sphere(3 + t) = {x,y,z,r};
  Physical Volume(t) = {3 + t};
EndFor
v() = BooleanFragments{ Volume{3}; Delete; }{ Volume{3 + 1 : 3 + 5}; Delete; };
Physical Volume(10) = v(#v()-1);

lcar1 = .1;
lcar2 = .0005;
lcar3 = .055;
eps = 1e-3;

Characteristic Length{ PointsOf{ Volume{:}; } } = lcar1;
Characteristic Length{ PointsOf{ Volume{3 + 1 : 3 + 5}; } } = lcar3;
p() = Point In BoundingBox{0.5-eps, 0.5-eps, 0.5-eps,
                           0.5+eps, 0.5+eps, 0.5+eps};
Characteristic Length{ p() } = lcar2;

// Additional examples are available in the demos/boolean directory.
