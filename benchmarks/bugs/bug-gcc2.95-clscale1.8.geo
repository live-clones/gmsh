ep = 0.9;
Ri = 22.5;
PI = 3.14159;
tag = ep/8;
posinit = 0.2 ;
espch = 0.4 ;
ht = espch;
espcv = 0.0349;
an = espcv;

chr = 23.15;
cvr = 22.95;
zcha = posinit;
Rcha = 0.04 ;
taf = Rcha;
tetainit = an/2;
dm=taf*0.8;

ep1= 0.55 ;
ep2= 0.35;


Point(1) = {Ri,0,0,tag};
Point(2) = {Ri+ep1,0,0,tag/2};
Point(3) = {(Ri+ep1)*(Cos(an)),(Ri+ep1)*(Sin(an)),0,tag/2};
Point(4) = {Ri*(Cos(an)),Ri*(Sin(an)),0,tag};


Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};

Point(238) = {cvr*(Cos(tetainit)),cvr*(Sin(tetainit)),0,taf/2};
Point(239) = {cvr*(Cos(tetainit))+Rcha,cvr*(Sin(tetainit)),0.,taf/2};
Point(240) = {cvr*(Cos(tetainit))-Rcha,cvr*(Sin(tetainit)),0.,taf/2};
Point(241) = {cvr*(Cos(tetainit)),cvr*(Sin(tetainit))-Rcha,0.,taf/2};
Point(242) = {cvr*(Cos(tetainit)),cvr*(Sin(tetainit))+Rcha,0.,taf/2};

Circle(41) = {239,238,242};
Circle(42) = {242,238,240};
Circle(43) = {240,238,241};
Circle(44) = {241,238,239};


Line Loop(45) = {41,42,43,44};
Plane Surface(46) = {45};



Line Loop(47) = {3,4,1,2};
Plane Surface(48) = {47,45};
Extrude Surface {48, {0,0,0.4}};
Line Loop(91) = {57,54,55,56};
Plane Surface(92) = {91};



Surface Loop(93) = {92,89,46,77,81,85};
Volume(94) = {93};


Point(5) = {Ri+ep,0,0,tag};
Point(6) = {Ri+ep,0,ht,tag};
Point(7) = {(Ri+ep)*(Cos(an)),(Ri+ep)*(Sin(an)),0,tag};
Point(8) = {(Ri+ep)*(Cos(an)),(Ri+ep)*(Sin(an)),ht,tag};


Line(5) = {2,5};
Line(6) = {5,6};
Line(7) = {6,252};
Line(8) = {7,8};
Line(9) = {8,243};
Line(10) = {7,3};
Line(11)={5,7};
Line(12) = {6,8};


Point(13) = {chr,0,zcha,taf/2};
Point(14) = {chr+Rcha,0,zcha,taf/2};
Point(15) = {chr-Rcha,0,zcha,taf/2};
Point(16) = {chr,0,zcha+Rcha,taf/2};
Point(17) = {chr,0,zcha-Rcha,taf/2};

Circle(13) = {14,13,16};
Circle(14) = {16,13,15};
Circle(15) = {15,13,17};
Circle(16) = {17,13,14};


Line Loop(95) = {16,13,14,15};
Plane Surface(96) = {95};

Line Loop(97) = {-7,-6,-5,68};
Plane Surface(98) = {97,95};


Line Loop(99) = {12,-8,-11,6};
Plane Surface(100) = {99};
Extrude Surface {96, {0,0,1}, {0,0,0}, 0.0349};


Line Loop(123) = {-9,-8,10,59};
Line Loop(124) = {102,103,104,105};
Plane Surface(125) = {123,124};




Surface Loop(126) = {122,109,96,113,117,121};
Volume(127) = {126};


Line Loop(128) = {-9,-12,7,53};
Ruled Surface(129) = {128};


Line Loop(130) = {-10,-11,-5,2};
Ruled Surface(131) = {130};


Surface Loop(132) = {113,98,129,125,100,131,73,117,121,109};
Volume(133) = {132};


Surface Loop(134) = {77,48,61,65,69,73,90,81,85,89};
Volume(135) = {134};

//Transfinite Surface {121} = {252,2,3,243};
//Transfinite Line {53,68,2,59} = 10 Using Progression 1;
//Transfinite Line {53} = 15 Using Progression 1;
//Transfinite Line {68} = 15 Using Progression 1;
//Transfinite Line {64} = 5 Using Progression 1;
//Transfinite Line {2} = 10 Using Progression 1;
Characteristic Length {252} = dm;
Characteristic Length {243} = dm;
Characteristic Length {2} = dm;
Characteristic Length {3} = dm;

// surface basse du cable gauche-CVB
Physical Surface(200) = {46};

// surface basse du beton gauche-SB
Physical Surface(110) = {48};

// surface haute du beton gauche-SH
Physical Surface(1120) = {90};

// surface haute du cable gauche-CVH
Physical Surface(210) = {92};

// surface interne-SI
Physical Surface(150) = {65};

// surface droite beton gauche - SD
Physical Surface(1140) = {61};

// surface gauche beton gauche -SG
Physical Surface(1130) = {69};

// cable vertical à gauche - CABLEV
Physical Volume(170) = {94};

//cable horizontal surface gauche -CHG
Physical Surface(180) = {96};

//surface gauche beton droit avec trou -SG
Physical Surface(130) = {98};

//cable horizontal surface droite - CHD
Physical Surface(190) = {122};

//surface gauche beton droit avec trou - SD
Physical Surface(140) = {125};

// cable horizontal à droite - CABLEH
Physical Volume(160) = {127};

//surface haute beton droit -SH
Physical Surface(120) = {129};

//surface basse beton droit - SB
Physical Surface(1110) = {131};

// volume beton droite  - BETON
Physical Volume(100) = {133};

//volume beton gauche - BETON 
Physical Volume(1100) = {135};

Physical Point(220) = {1};
