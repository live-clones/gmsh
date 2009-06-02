Point(1) = {0.2, 0.8, 0,0.005};
Point(2) = {0.6, 0.8, 0, 0.05};
Point(3) = {0.6, 0.6, 0, 0.05};
Point(4) = {0.5, 0.6, 0, 0.05};
Point(5) = {0.5, 0.5, 0, 0.05};
Point(6) = {0.6, 0.5, 0, 0.05};
Point(7) = {0.6, 0.3, 0, 0.2};
Point(8) = {0.2, 0.3, 0, 0.2};
Line(1) = {2, 1};
Line(2) = {1, 8};
Line(3) = {8, 7};
Line(4) = {7, 6};
Line(5) = {6, 5};
Line(6) = {5, 4};
Line(7) = {4, 3};
Line(8) = {3, 2};
Line Loop(9) = {8, 1, 2, 3, 4, 5, 6, 7};
Plane Surface(10) = {9};

// Nice little hack to generate periodic surface meshes on
// non-extrudable geometries: first extrude the surface, then delete
// all the "middle" entities :-)

Extrude {{0, 1, 0}, {0, 0, 0}, Pi/3} {
  Surface{10}; Layers{1};
}
Delete {
  Volume{1};
  Surface{27, 51, 23, 47, 43, 31, 35, 39};
  Line{26, 22, 46, 21, 42, 38, 30, 34};
}

// Add a funky looking volume in between
Point(100) = {0.25, 0.3, -0.2, 0.2};
Point(101) = {0.25, 0.5, -0.2, 0.2};
Point(102) = {0.25, 0.6, -0.2, 0.2};
Point(103) = {0.25, 0.8, -0.2, 0.2};
Line(53) = {22, 100};
Line(54) = {100, 7};
Line(55) = {30, 101};
Line(56) = {101, 26};
Line(57) = {34, 102};
Line(58) = {102, 9};
Line(59) = {10, 103};
Line(60) = {6, 101};
Line(61) = {101, 5};
Line(62) = {102, 4};
Line(63) = {3, 102};
Line(64) = {2, 103};
Line(65) = {1, 14};
Line(66) = {8, 18};
Line(67) = {103, 102};
Line(68) = {102, 101};
Line(69) = {101, 100};
Line Loop(70) = {54, 4, 60, 69};
Plane Surface(71) = {70};
Line Loop(72) = {5, -61, -60};
Plane Surface(73) = {72};
Line Loop(74) = {6, -62, 68, 61};
Plane Surface(75) = {74};
Line Loop(76) = {62, 7, 63};
Plane Surface(77) = {76};
Line Loop(78) = {8, 64, 67, -63};
Plane Surface(79) = {78};
Line Loop(80) = {59, 67, 58, 12};
Plane Surface(81) = {80};
Line Loop(82) = {58, -19, 57};
Plane Surface(83) = {82};
Line Loop(84) = {18, 57, 68, -55};
Plane Surface(85) = {84};
Line Loop(86) = {55, 56, 17};
Plane Surface(87) = {86};
Line Loop(88) = {16, -56, 69, -53};
Plane Surface(89) = {88};
Line Loop(90) = {65, -13, 59, -64, 1};
Plane Surface(91) = {90};
Line Loop(92) = {3, -54, -53, -15, -66};
Plane Surface(93) = {92};
Line Loop(94) = {14, -66, -2, 65};
Plane Surface(95) = {94};
Surface Loop(96) = {91, 95, 52, 81, 79, 10, 93, 71, 73, 75, 77, 85, 83, 87, 89};
Volume(97) = {96};


Physical Surface("Periodic faces") = {10, 52};
Physical Volume("Volume in between") = {97};

// Use the frontal algo to make sure that the periodic surface mesh is
// not modified when meshing the volume
Mesh.Algorithm3D = 4;
