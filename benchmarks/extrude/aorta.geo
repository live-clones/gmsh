Merge "aorta2.stl";
CreateTopology;

Merge "aortaRADIUS2.bgm";

Line Loop(60) = {1}; Plane Surface(61) = {60};
Line Loop(62) = {2}; Plane Surface(63) = {62};
Line Loop(64) = {3}; Plane Surface(65) = {64};
Line Loop(66) = {4}; Plane Surface(67) = {66};
Line Loop(68) = {5}; Plane Surface(69) = {68};

Mesh.Algorithm3D = 4;

Surface Loop(100) = {1, 61:69:2};
Volume(100) = 100;

