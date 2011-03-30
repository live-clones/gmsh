Merge "aorta2.stl";
CreateTopology;

Merge "aortaRADIUS2.bgm";

out1[] = Extrude{Surface{1}; Layers{4, 0.5}; Using Index[0]; Using View[0]; };
//out2[] = Extrude{Surface{1}; Layers{4, -0.5}; Using Index[1]; Using View[0]; };

Line Loop(60) = {9}; Plane Surface(61) = {60};
Line Loop(62) = {7}; Plane Surface(63) = {62};
Line Loop(64) = {10}; Plane Surface(65) = {64};
Line Loop(66) = {11}; Plane Surface(67) = {66};
Line Loop(68) = {8}; Plane Surface(69) = {68};

Mesh.Algorithm3D = 4;

Surface Loop(100) = {32, 61:69:2};
Volume(100) = 100;

