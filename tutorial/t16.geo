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

Block(1) = {0,0,0, 1,1,1};
Block(2) = {0,0,0, 0.5,0.5,0.5};
BooleanDifference(3) = { Volume{1}; Delete; }{ Volume{2}; Delete; };
x = 0 ; y = 0.75 ; z = 0 ; r = 0.09 ;
For t In {1:5}
  x += 0.166 ;
  z += 0.166 ;
  Sphere(3 + t) = {x,y,z,r};
EndFor
v() = BooleanFragments{ Volume{3}; Delete; }{ Volume{3+1:3+5}; Delete; };

s() = Unique(Abs(Boundary{ Volume{v()}; }));
l() = Unique(Abs(Boundary{ Surface{s()}; }));
p() = Unique(Abs(Boundary{ Line{l()}; }));
Characteristic Length{p()} = 0.055;

// Additional examples are available in the demos/boolean directory.
