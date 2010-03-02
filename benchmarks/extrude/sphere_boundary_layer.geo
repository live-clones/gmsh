lc = 1;

Point(1) = {0.0,0.0,0.0,lc};
Point(2) = {1,0.0,0.0,lc};
Point(3) = {0,1,0.0,lc};
Circle(1) = {2,1,3};
Point(4) = {-1,0,0.0,lc};
Point(5) = {0,-1,0.0,lc};
Circle(2) = {3,1,4};
Circle(3) = {4,1,5};
Circle(4) = {5,1,2};
Point(6) = {0,0,-1,lc};
Point(7) = {0,0,1,lc};
Circle(5) = {3,1,6};
Circle(6) = {6,1,5};
Circle(7) = {5,1,7};
Circle(8) = {7,1,3};
Circle(9) = {2,1,7};
Circle(10) = {7,1,4};
Circle(11) = {4,1,6};
Circle(12) = {6,1,2};

Line Loop(13) = {2,8,-10};
Ruled Surface(14) = {13};
Line Loop(15) = {10,3,7};
Ruled Surface(16) = {15};
Line Loop(17) = {-8,-9,1};
Ruled Surface(18) = {17};
Line Loop(19) = {-11,-2,5};
Ruled Surface(20) = {19};
Line Loop(21) = {-5,-12,-1};
Ruled Surface(22) = {21};
Line Loop(23) = {-3,11,6};
Ruled Surface(24) = {23};
Line Loop(25) = {-7,4,9};
Ruled Surface(26) = {25};
Line Loop(27) = {-4,12,-6};
Ruled Surface(28) = {27};

old = Geometry.ExtrudeReturnLateralEntities;
Geometry.ExtrudeReturnLateralEntities = 0;
tmp[] = Extrude {
  Surface{14:28:2}; Layers{5, 0.2}; Recombine; // 14:28:2 means itterate from 14 to 28 by steps of 2
};
Geometry.ExtrudeReturnLateralEntities = old;

Point(100) = {-1.5,-1.5,-1.5, lc};
Point(101) = {-1.5,1.5,-1.5, lc};
Point(102) = {1.5,-1.5,-1.5, lc};
Point(103) = {1.5,1.5,-1.5, lc};
Point(104) = {-1.5,-1.5,1.5, lc};
Point(105) = {-1.5,1.5,1.5, lc};
Point(106) = {1.5,-1.5,1.5, lc};
Point(107) = {1.5,1.5,1.5, lc};
Line(165) = {100, 102};
Line(166) = {102, 103};
Line(167) = {103, 101};
Line(168) = {101, 100};
Line(169) = {100, 104};
Line(170) = {104, 106};
Line(171) = {106, 102};
Line(172) = {101, 105};
Line(173) = {105, 107};
Line(174) = {107, 103};
Line(175) = {105, 104};
Line(176) = {106, 107};
Line Loop(177) = {167, 168, 165, 166};
Plane Surface(178) = {177};
Line Loop(179) = {166, -174, -176, 171};
Plane Surface(180) = {179};
Line Loop(181) = {171, -165, 169, 170};
Plane Surface(182) = {181};
Line Loop(183) = {176, -173, 175, 170};
Plane Surface(184) = {183};
Line Loop(185) = {172, 175, -169, -168};
Plane Surface(186) = {185};
Line Loop(187) = {172, 173, 174, 167};
Plane Surface(188) = {187};

Surface Loop(1000) = {14:28:2}; // the sphere (only need for internal mesh)
Surface Loop(1001) = {tmp[{0:14:2}]};  // The outside of the BL
Surface Loop(1002) = {188, 186, 184, 180, 178, 182}; // the box (entire farfield surface loop)

//Volume(1000) = {1000}; /// inside the sphere
Volume(1001) = {1002, 1001}; /// FarField

Mesh.Algorithm3D = 4;
