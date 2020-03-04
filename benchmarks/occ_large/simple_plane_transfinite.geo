Merge "simple_plane.brep";

// all surfaces except air
s() = Surface {:};
s() -= {106,107,108}; // manual

// remove surfaces touching top - they can't be meshed with transfinite
notv() = {1,2,3,4};  // manual
nots() = Abs(Boundary{ Volume{notv()}; });
s() -= nots();

// re-add 2 that will connect to transfinite volumes
s() += {4,10};  // manual

// force curve meshing (should be change for boundary layer spacing!)
l() = Boundary{ Surface{s()}; };
Transfinite Curve{l()} = 10;

Transfinite Surface{s()};

// redefine some with explicit corners (3-sided surfs) for volume mesh compat
Transfinite Surface{14} = {1,11,7}; // manual
Transfinite Surface{15} = {8,7,11};  // manual
Transfinite Surface{65} = {45,46,47}; // manual
Transfinite Surface{75} = {40,47,41}; // manual
Transfinite Surface{77} = {42,46,43}; // manual

Transfinite Surface{96} = {56,50,57}; // manual
Transfinite Surface{97} = {55,49,58}; // manual
Transfinite Surface{99} = {56,57,54}; // manual
Transfinite Surface{100} = {55,58,53}; // manual

Recombine Surface{s()};

v() = Volume{:};
v() -= {notv(), 27}; // manual
Transfinite Volume{v()};

Recombine Volume{v()};

pp() = PointsOf{ Volume{notv()}; };
Characteristic Length{pp()} = 0.0005;

Field[1] = Box;
Field[1].VIn = 0.015;
Field[1].VOut = 1;
Field[1].XMin = -0.2;
Field[1].XMax = 1;
Field[1].YMin = -0.1;
Field[1].YMax = 0.2;
Field[1].ZMax = 0.2;
Field[1].ZMin = -0.2;
Field[1].Thickness = 1;
Background Field = 1;
