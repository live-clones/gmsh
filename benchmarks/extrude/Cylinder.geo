// Cylinder //
//----------//

Mesh.Algorithm = 2;

N = 0.5;

bl          = 0.025;
NBL         = 10*N;
NBL_PROG    = 1.1;
N_CYL       = 100*N;
CYL_PROG    = 0.99;
Delta_0     = 0.5*3.1415*(0.5+bl)*(CYL_PROG-1)/(CYL_PROG*(CYL_PROG^N_CYL-1));
Delta_N     = Delta_0*CYL_PROG^N_CYL;
h_square    = 0.75;
l_rectangle = 10.;
m_box       = 0.02/N;
N_LARGEBOX  = 11*N;
L_LARGEBOX  = 100;

// CYLINDER //

Point(11) = {   0,   0,0,1};
Point(12) = {   0, 0.5,0,1};
Point(13) = { 0.5,   0,0,1};
Point(14) = {   0,-0.5,0,1};
Point(15) = {-0.5,   0,0,1};

Circle(21) = {12,11,13};
Circle(22) = {13,11,14};
Circle(23) = {14,11,15};
Circle(24) = {15,11,12};

// 15 , 24 //


// BOUNDARY LAYER //

Point(16) = {      0, 0.5+bl,0,Delta_0};
Point(17) = { 0.5+bl,      0,0,Delta_N};
Point(18) = {      0,-0.5-bl,0,Delta_0};
Point(19) = {-0.5-bl,      0,0,Delta_N};

Line(25) = {12,16};
Line(26) = {13,17};
Line(27) = {14,18};
Line(28) = {15,19};

Circle(29) = {16,11,17};
Circle(210)= {17,11,18};
Circle(211)= {18,11,19};
Circle(212)= {19,11,16};

Line Loop(213) = {-25,21,26,-29};
Line Loop(214) = {-26,22,27,-210};
Line Loop(215) = {-27,23,28,-211};
Line Loop(216) = {-28,24,25,-212};

Ruled Surface(31) = {213};
Ruled Surface(32) = {214};
Ruled Surface(33) = {215};
Ruled Surface(34) = {216};

Transfinite Line{29,-210,211,-212,21,-22,23,-24} = Floor(N_CYL) Using Progression CYL_PROG;
Transfinite Line{25,26,27,28}                    = Floor(NBL)   Using Progression NBL_PROG;

Transfinite Surface{31} = {16,12,13,17};
Transfinite Surface{32} = {17,13,14,18};
Transfinite Surface{33} = {18,14,15,19};
Transfinite Surface{34} = {19,15,12,16};

Recombine Surface{31,32,33,34};

// 19 , 216 , 34 //


// SQUARE //

Point(111)={-h_square,-h_square,0,m_box*3};
Point(112)={-h_square, h_square,0,m_box*3};
Point(113)={ h_square, h_square,0,m_box};
Point(114)={ h_square,-h_square,0,m_box};

Line(217) = {111,112};
Line(218) = {112,113};
Line(219) = {113,114};
Line(220) = {114,111};

Line Loop(221) = {-217,-218,-219,-220};
Line Loop(222) = {-29,-210,-211,-212};

Plane Surface(35) = {221,222};

// 114 , 222 , 35 //


// RECTANGLE //

Point(115) = {h_square+l_rectangle,-h_square,0,m_box};
Point(116) = {h_square+l_rectangle, h_square,0,m_box};

Line(223) = {114,115};
Line(224) = {115,116};
Line(225) = {116,113};

Line Loop(226) = {223,224,225,219};

Ruled Surface(36) = {226};

Transfinite Line{224,219} = Floor(2*h_square/m_box)   Using Progression 1;
Transfinite Line{223,225} = Floor(l_rectangle/m_box)  Using Progression 1;

Transfinite Surface{36} = {114,115,116,113};
Recombine Surface{36};

// 116 , 226 , 36 //



// EXTERIOR //

Point(117) = {-L_LARGEBOX,-L_LARGEBOX,0,2*L_LARGEBOX/N_LARGEBOX};
Point(118) = { L_LARGEBOX,-L_LARGEBOX,0,2*L_LARGEBOX/N_LARGEBOX};
Point(119) = { L_LARGEBOX, L_LARGEBOX,0,2*L_LARGEBOX/N_LARGEBOX};
Point(120) = {-L_LARGEBOX, L_LARGEBOX,0,2*L_LARGEBOX/N_LARGEBOX};

Line(227) = {117,118};
Line(228) = {118,119};
Line(229) = {119,120};
Line(230) = {120,117};

Line(231) = {117,111};
Line(232) = {118,115};
Line(233) = {119,116};
Line(234) = {120,112};


Line Loop(235) = {-231,227,232,-223,220};
Line Loop(236) = {-232,228,233,-224};
Line Loop(237) = {-233,229,234,218,-225};
Line Loop(238) = {-234,230,231,217};

Plane Surface(37)  = {235};
Plane Surface(38)  = {236};
Plane Surface(39)  = {237};
Plane Surface(310) = {238};

Recombine Surface{37,38,39,310};

// 120 , 238 , 310 //


// EXTRUSION //

out1[]  = Extrude{0,0,0.1}{Surface{31}; Layers{4,1} ; Recombine;};
out2[]  = Extrude{0,0,0.1}{Surface{32}; Layers{4,1} ; Recombine;};
out3[]  = Extrude{0,0,0.1}{Surface{33}; Layers{4,1} ; Recombine;};
out4[]  = Extrude{0,0,0.1}{Surface{34}; Layers{4,1} ; Recombine;};
out5[]  = Extrude{0,0,0.1}{Surface{35}; Layers{4,1} ; Recombine;};
out6[]  = Extrude{0,0,0.1}{Surface{36}; Layers{4,1} ; Recombine;};
out7[]  = Extrude{0,0,0.1}{Surface{37}; Layers{4,1} ; Recombine;};
out8[]  = Extrude{0,0,0.1}{Surface{38}; Layers{4,1} ; Recombine;};
out9[]  = Extrude{0,0,0.1}{Surface{39}; Layers{4,1} ; Recombine;};
out10[] = Extrude{0,0,0.1}{Surface{310}; Layers{4,1} ; Recombine;};

Physical Volume(1)  = {out1[1],out2[1],out3[1],out4[1],out5[1],out6[1],out7[1],out8[1],out9[1],out10[1]};
Physical Surface(2) = {31,32,33,34,35,36,37,38,39,310}; // Z_DOWN //
Physical Surface(3) = {out1[0],out2[0],out3[0],out4[0],out5[0],out6[0],out7[0],out8[0],out9[0],out10[0]}; // Z_UP //
Physical Surface(4) = {476}; // Y_DOWN //
Physical Surface(5) = {525}; // Y_UP   //
Physical Surface(6) = {551}; // INLET  //
Physical Surface(7) = {502}; // OUTLET //
Physical Surface(8) = {389,323,345,367}; // CYLINDER //


