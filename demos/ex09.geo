/* 
   Gmsh demo file (C) 2000 C. Geuzaine, J.-F. Remacle

   More complex 3D  with geometric transformations and extrusion

   All important comments are marked with "README"
*/

r1 = .1;
l1 = 1.;
l2 = .8;
l3 = .1;
r2 = 1.1;
lc = .08;
lc2 = .05;
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

Circle(31) = {16,10,9};
Circle(32) = {31,25,14};
Circle(33) = {46,40,29};
Circle(34) = {61,55,44};
Circle(35) = {8,70,59};
Point(newp) = {rint,0,0,lc};
Point(newp) = {rext,0,0,lc};
Point(newp) = {-rint,0,0,lc};
Point(newp) = {-rext,0,0,lc};
Point(newp) = {0,rint,0,lc};
Point(newp) = {0,rext,0,lc};
Point(newp) = {0,-rint,0,lc};
Point(newp) = {0,-rext,0,lc};
Circle(36) = {75,1,73};
Circle(37) = {73,1,77};
Circle(38) = {77,1,71};
Circle(39) = {71,1,75};
Circle(40) = {76,1,74};
Circle(41) = {74,1,78};
Circle(42) = {78,1,72};
Circle(43) = {72,1,76};

Line Loop(44) = {-8,-7,11,12,10,9,31,-2,-1,5,6,4,3,35,-26,-25,29,30,28,27,34,-20,-19,23,24,22,21,33,-14,-13,17,18,16,15,32};
Line Loop(45) = {40,41,42,43};
Plane Surface(46) = {44,45};
Line Loop(47) = {36,37,38,39};
Plane Surface(48) = {45,47};

Extrude(46, {0,0,.2});
Coherence;
Extrude(48, {0,0,.2});
Coherence;
Extrude(238, {0,0,.2});
Coherence;

Surface Loop(274) = {235,-48,46,88,-189,-207,91,-94,-97,-100,-103,-106,109,112,-115,-118,-121,-124,-127,130,133,-136,-139,-142,-145,-148,151,154,-157,-160,-163,-166,-169,172,175,-178,-181,-184,-187,247,250,253,255,273,264,229,232,267,270,272,237};
Complex Volume(275) = {274};

Physical Volume(1000) = 275;



