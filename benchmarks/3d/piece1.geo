
r1 = .1;
l1 = 1.;
l2 = .8;
l3 = .1;
r2 = 1.1;
lc = .1;
lc2 = .04;
rint = .2;
rext = .3;
Point(1) = {0.0,0.0,0.0,lc};
Point(2) = {l1,0.0,0.0,lc2};
Point(3) = {l1-r1,0.0,0.0,lc2};
Point(4) = {l1,r1,0.0,lc2};
Point(5) = {l1,-r1,0.0,lc2};
Point(6) = {l1+l2,r1,0.0,lc};
Point(7) = {l1+l2,-r1,0.0,lc};
Point(8) = {l1+l2,-r1-l3,0.0,lc};
Point(9) = {l1+l2,r1+l3,0.0,lc};

Line(1) = {4,6};
Line(2) = {6,9};
Line(3) = {7,8};
Line(4) = {5,7};
Circle(5) = {4,2,3};
Circle(6) = {3,2,5};
r = 2*3.14159/5;
Point(10) = { (l1 + r2) * Cos(r/2) , (l1 + r2) * Sin(r/2), 0.0, lc};
Rotate({0.0,0.0,1.0},{0.0,0.0,0.0},r) {
  Duplicata {
   Line(1); 
   Line(2);
 Line(3); 
 Line(4); 
 Line(5); 
 Line(6); 
Point(10);  
 }
}
Rotate({0.0,0.0,1.0},{0.0,0.0,0.0},2*r) {
  Duplicata {
   Line(1); 
   Line(2);
 Line(3); 
 Line(4); 
 Line(5); 
 Line(6); 
 Point(10);  
 }
}
Rotate({0.0,0.0,1.0},{0.0,0.0,0.0},3*r) {
  Duplicata {
   Line(1); 
   Line(2);
 Line(3); 
 Line(4); 
 Line(5); 
 Line(6); 
 Point(10);  
 }
}
Rotate({0.0,0.0,1.0},{0.0,0.0,0.0},4*r) {
  Duplicata {
   Line(1); 
   Line(2);
 Line(3); 
 Line(4); 
 Line(5); 
 Line(6); 
 Point(10);  
 }
}
Coherence;
Point(newp) = {rint,0,0,lc};
Point(newp) = {rext,0,0,lc};
Point(newp) = {-rint,0,0,lc};
Point(newp) = {-rext,0,0,lc};
Point(newp) = {0,rint,0,lc};
Point(newp) = {0,rext,0,lc};
Point(newp) = {0,-rint,0,lc};
Point(newp) = {0,-rext,0,lc};
Circle(31) = {43,64,74};
Circle(32) = {16,37,47};
Circle(33) = {9,10,20};
Circle(34) = {97,118,8};
Circle(35) = {101,91,70};
Circle(36) = {119,1,123};
Circle(37) = {123,1,121};
Circle(38) = {121,1,125};
Circle(39) = {125,1,119};
Circle(40) = {120,1,124};
Circle(41) = {124,1,122};
Circle(42) = {122,1,126};
Circle(43) = {126,1,120};
Line Loop(44) = {-21,-22,-24,-23,19,20,-35,-27,-28,-30,-29,25,26,34,-3,-4,-6,-5,1,2,33,-9,-10,-12,-11,7,8,32,-15,-16,-18,-17,13,14,31};
Line Loop(45) = {43,40,41,42};
Plane Surface(46) = {44,45};
Line Loop(47) = {38,39,36,37};
Plane Surface(48) = {45,47};
Extrude Surface (46, {0.0,0.0,0.2});
Coherence;
Extrude Surface (48, {0.0,0.0,0.2});
Coherence;
Extrude Surface (287, {0.0,0.0,0.2});
Coherence;
/*
Delete {
 Surface(287);
}
Delete {
 Surface(266);
}
Delete {
 Surface(262);
}
Delete {
 Surface(270);
}
Delete {
 Surface(236);
}
Delete {
 Surface(258);
}
Delete {
 Surface(232);
}
Delete {
 Surface(244);
}
Delete {
 Surface(240);
}
Delete {
 Line(239);
}
Delete {
 Line(230);
}
Delete {
 Line(231);
}
Delete {
 Line(235);
}
Coherence;
*/
Surface Loop(330) = {245,92,46,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,172,176,180,184,188,192,196,200,204,208,212,216,220,224,228,48,274,278,282,286,328,316,320,324,329,300,304,308,312};
Complex Volume(331) = {330};
