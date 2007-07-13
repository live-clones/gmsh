lc = 0.6;
Point(1) = {0,3,0,lc};
Point(2) = {0,4,0,lc};
Point(3) = {0,3,1,lc};
Point(4) = {0,3,-1,lc};
Point(5) = {0,2,0,lc};
Circle(1) = {2,1,3};
Circle(2) = {3,1,5};
Circle(3) = {5,1,4};
Circle(4) = {4,1,2};

Point(10) = {0,3+0.5,0,lc};
Point(11) = {0,3,-0.5,lc};
Point(12) = {0,3-0.5,0,lc};
Point(13) = {0,3,0.5,lc};

Line(5) = {11,10};
Line(6) = {10,13};
Line(7) = {13,12};
Line(8) = {12,11};

Line(9) = {10,2};
Line(10) = {13,3};
Line(11) = {12,5};
Line(12) = {11,4};

Transfinite Line {1:12} = 10;

Line Loop(13) = {-10,-6,9,1};
Plane Surface(14) = {13};
Line Loop(15) = {11,-2,-10,7};
Plane Surface(16) = {15};
Line Loop(17) = {-3,-11,8,12};
Plane Surface(18) = {17};
Line Loop(19) = {9,-4,-12,5};
Plane Surface(20) = {19};
Line Loop(21) = {6,7,8,5};
Plane Surface(22) = {21};
Transfinite Surface {14} = {10,13,3,2};
Transfinite Surface {16} = {12,5,3,13};
Transfinite Surface {18} = {11,4,5,12};
Transfinite Surface {20} = {4,11,10,2};
Transfinite Surface {22} = {11,12,13,10};

Recombine Surface {14:22:2};

Geometry.ExtrudeReturnLateralEntities = 0;

s[] = Extrude {{0,0,1}, {0,0,0}, 2*Pi/3}{
  Surface{14:22:2}; Recombine; Layers{10,1};
};

s[] = Extrude {{0,0,1}, {0,0,0}, 2*Pi/3}{
  Surface{s[{0:8:2}]}; Recombine; Layers{10,1};
};

Extrude {{0,0,1}, {0,0,0}, 2*Pi/3}{
  Surface{s[{0:8:2}]}; Recombine; Layers{10,1};
}
