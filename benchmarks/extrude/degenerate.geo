lc = 1;
n = 15;

Point(1) = {0,0,0,lc};
Point(2) = {1,0,0,lc};
Point(3) = {2,0,0,lc};
Point(4) = {2,0,0,lc};
Point(5) = {10,0,0,lc};
Point(6) = {11,0,0,lc};
Point(7) = {0,11,0,lc};
Point(8) = {0,10,0,lc};
Point(9) = {0,1,0,lc};
Point(10) = {1,1,0,lc};
Point(11) = {2,1,0,lc};

Line(1) = {1,2};
Line(2) = {2,4};
Line(3) = {4,5};
Line(4) = {5,6};

Circle(5) = {6,1,7};
Circle(6) = {5,1,8};

Line(7) = {7,8};
Line(8) = {8,9};
Line(9) = {9,1};
Line(10) = {9,10};
Line(11) = {4,11};
Line(12) = {11,10};
Line(13) = {10,2};

// Bore
Line Loop(14) = {13,-1,-9,10};
Plane Surface(15) = {14};

Extrude Surface { 15, {0,1,0} , {0,0,0} , Pi/2 } { 
  Recombine ; Layers { n, 200, 1 } ; 
};


// Induc
Line Loop(16) = {2,11,12,13};
Plane Surface(17) = {16};
Physical Surface(100) = {17};

Extrude Surface { 17, {0,1,0} , {0,0,0} , Pi/2 } { 
  Recombine ; Layers { n, 201, 1 } ; 
};

Physical Surface(101) = {24, 117, 113};
Physical Surface(102) = {122};
Physical Surface(103) = {109};

Physical Volume(1) = {201};

// Air
Line Loop(18) = {-10,-8,-6,-3,11,12};
Plane Surface(19) = {18};
Physical Surface(104) = {15,19};

Extrude Surface { 19, {0,1,0} , {0,0,0} , Pi/2 } { 
  Recombine ; Layers { n, 202, 1 } ; 
};

Physical Surface(105) = {32, 149};
Physical Surface(106) = {136};
Physical Surface(107) = {27, 140};

Physical Volume(2) = {201, 202};

// AirInf
Line Loop(20) = {-7,-5,-4,6};
Plane Surface(21) = {20};
Physical Surface(108) = {21};
Physical Surface(109) = {166};
Physical Surface(110) = {158};
Physical Surface(111) = {162};

Extrude Surface { 21, {0,1,0} , {0,0,0} , Pi/2 } { 
  Recombine ; Layers { n, 203, 1 } ; 
};


Physical Volume(3) = {203};

// Symetrie 
/*
 Symmetry { 0,1,0,0 } {
    Duplicata{ Surface{24}; }
   }
 Symmetry { 0,1,0,0 } {
    Duplicata{ Surface{117}; }
   }
 Symmetry { 0,1,0,0 } {
    Duplicata{ Surface{113}; }
   }
 Physical Surface(200) = {167, 172, 177};
 
 Symmetry { 0,1,0,0 } {
    Duplicata{ Surface{17}; }
   }
 Symmetry { 0,1,0,0 } {
    Duplicata{ Surface{122}; }   
   }
 Physical Surface(201) = {201, 202};
 
 Symmetry { 0,1,0,0 } {
    Duplicata{ Surface{15}; }
   }
 Symmetry { 0,1,0,0 } {
    Duplicata{ Surface{19}; }
   }
 Symmetry { 0,1,0,0 } {
    Duplicata{ Surface{21}; }
   }
 Physical Surface(202) = {203, 208, 212};
   
 Symmetry { 0,1,0,0 } {
    Duplicata{ Surface{32}; }
   }
 Symmetry { 0,1,0,0 } {
    Duplicata{ Surface{149}; }
   }
 Symmetry { 0,1,0,0 } {
    Duplicata{ Surface{166}; }
   }
 Physical Surface(203) = {215, 220,224};
*/
// bug ???

Symmetry { 0,1,0,0 } { Duplicata{ Surface{158}; } }

Physical Surface(204) = {215, 220,224};
