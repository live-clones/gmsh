//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
size = 5;

R=315.0/2.0; //Radius

Point(0)  = {0, 0, 0, size};

// Blende C1 ==============================

C1Psi = Pi/2;
C1Phi = Pi;
alC1 = Asin(33.5/2.0/R);

x1=R*Cos(alC1)*Sin(C1Psi)*Cos(C1Phi);
y1=R*Cos(alC1)*Sin(C1Psi)*Sin(C1Phi);
z1=R*Cos(alC1)*Cos(C1Psi);

Point(100)  = {x1,y1,z1,size};

x2 =  R*Sin(C1Psi+alC1)*Cos(C1Phi);
y2 = R*Sin(C1Psi+alC1)*Sin(C1Phi);
z2 = R*Cos(C1Psi+alC1);

Point(200)  = {x2,y2,z2,size};

Rotate { {x1,y1,z1} , {0,0,0}, Pi/2} {Duplicata {  Point{200} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, -Pi/2} {Duplicata {  Point{200} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, Pi} {Duplicata {  Point{200} ; }}

Circle(1) = {201,100,203};
Circle(2) = {203,100,202};
Circle(3) = {202,100,200};
Circle(4) = {200,100,201};

// Blende C01 ==============================

C01Psi = Pi/2;
C01Phi = Pi/2;
alC01 = Asin(7.5/2.0/R);

x1=R*Cos(alC01)*Sin(C01Psi)*Cos(C01Phi);
y1=R*Cos(alC01)*Sin(C01Psi)*Sin(C01Phi);
z1=R*Cos(alC01)*Cos(C01Psi);

Point(300)  = {x1,y1,z1,size};

x2 =  R*Sin(C01Psi+alC01)*Cos(C01Phi);
y2 = R*Sin(C01Psi+alC01)*Sin(C01Phi);
z2 = R*Cos(C01Psi+alC01);

Point(400)  = {x2,y2,z2,size};

Rotate { {x1,y1,z1} , {0,0,0}, Pi/2} {Duplicata {  Point{400} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, -Pi/2} {Duplicata {  Point{400} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, Pi} {Duplicata {  Point{400} ; }}

Circle(5) = {401,300,403};
Circle(6) = {403,300,402};
Circle(7) = {402,300,400};
Circle(8) = {400,300,401};

// Port1 ==============================

P1Psi =  Asin((20.0+34.0)/R);// noch nachmessen!
P1Phi = 0;
alP1 = Asin(34.0/2.0/R);

x1=R*Cos(alP1)*Sin(P1Psi)*Cos(P1Phi);
y1=R*Cos(alP1)*Sin(P1Psi)*Sin(P1Phi);
z1=R*Cos(alP1)*Cos(P1Psi);

Point(500)  = {x1,y1,z1,size};

x2 =  R*Sin(P1Psi+alP1)*Cos(P1Phi);
y2 = R*Sin(P1Psi+alP1)*Sin(P1Phi);
z2 = R*Cos(P1Psi+alP1);


Point(600)  = {x2,y2,z2,size};

Rotate { {x1,y1,z1} , {0,0,0}, Pi/2} {Duplicata {  Point{600} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, -Pi/2} {Duplicata {  Point{600} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, Pi} {Duplicata {  Point{600} ; }}

Circle(9) = {601,500,603};
Circle(10) = {603,500,602};
Circle(11) = {602,500,600};
Circle(12) = {600,500,601};

// Port2 ==============================

P2Psi =  0;//
P2Phi = 0;
alP2 = Asin(34.0/2.0/R);

x1=R*Cos(alP2)*Sin(P2Psi)*Cos(P2Phi);
y1=R*Cos(alP2)*Sin(P2Psi)*Sin(P2Phi);
z1=R*Cos(alP2)*Cos(P2Psi);

Point(700)  = {x1,y1,z1,size};

x2 =  R*Sin(P2Psi+alP2)*Cos(P2Phi);
y2 = R*Sin(P2Psi+alP2)*Sin(P2Phi);
z2 = R*Cos(P2Psi+alP2);

Point(800)  = {x2,y2,z2,size};

Rotate { {x1,y1,z1} , {0,0,0}, Pi/4} {Duplicata {   Point{800} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, Pi/2} {Duplicata {   Point{800} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, Pi*3/4} {Duplicata {  Point{800} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, Pi} {Duplicata {     Point{800} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, -Pi*3/4} {Duplicata {  Point{800} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, -Pi/2} {Duplicata {  Point{800} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, -Pi/4} {Duplicata {  Point{800} ; }}

//Circle(120) =  {800,700,801};
Circle(130) =  {801,700,803};
//Circle(140) = {802,700,803};
//Circle(150) = {803,700,804};
Circle(160) = {803,700,805};
Circle(170) = {805,700,807};
//Circle(180) = {806,700,807};
Circle(190) = {807,700,801};

// Port3 ==============================

P3Psi =  -Asin((20.0+34.0)/R);// auch noch nachmessen!
P3Phi = 0;
alP3 = Asin(34.0/2.0/R);

x1=R*Cos(alP3)*Sin(P3Psi)*Cos(P3Phi);
y1=R*Cos(alP3)*Sin(P3Psi)*Sin(P3Phi);
z1=R*Cos(alP3)*Cos(P3Psi);

Point(900)  = {x1,y1,z1,size};

x2 =  R*Sin(P3Psi+alP3)*Cos(P3Phi);
y2 = R*Sin(P3Psi+alP3)*Sin(P3Phi);
z2 = R*Cos(P3Psi+alP3);

Point(1000)  = {x2,y2,z2,size};

Rotate { {x1,y1,z1} , {0,0,0}, Pi/2} {Duplicata {   Point{1000} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, -Pi/2} {Duplicata {  Point{1000} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, Pi} {Duplicata {     Point{1000} ; }}

Circle(17) = {1001,900,1003};
Circle(18) = {1003,900,1002};
Circle(19) = {1002,900,1000};
Circle(20) = {1000,900,1001};

// TempSen1 ==============================

TS1Psi = Pi/2 ;
TS1Phi = -Pi/2 ;
alTS1 = Asin(5/R);

x1=R*Cos(alTS1)*Sin(TS1Psi)*Cos(TS1Phi);
y1=R*Cos(alTS1)*Sin(TS1Psi)*Sin(TS1Phi);
z1=R*Cos(alTS1)*Cos(TS1Psi);

Point(1100)  = {x1,y1,z1,size};

x2 =  R*Sin(TS1Psi+alTS1)*Cos(TS1Phi);
y2 = R*Sin(TS1Psi+alTS1)*Sin(TS1Phi);
z2 = R*Cos(TS1Psi+alTS1);

Point(1200)  = {x2,y2,z2,size};

Rotate { {x1,y1,z1} , {0,0,0}, Pi/2} {Duplicata {   Point{1200} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, -Pi/2} {Duplicata {  Point{1200} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, Pi} {Duplicata {     Point{1200} ; }}

Circle(21) = {1201,1100,1203};
Circle(22) = {1203,1100,1202};
Circle(23) = {1202,1100,1200};
Circle(24) = {1200,1100,1201};

// TempSen2 ==============================

TS2Psi = Pi/2 ;
TS2Phi = 0 ;
alTS2 = Asin(5/R);

x1=R*Cos(alTS2)*Sin(TS2Psi)*Cos(TS2Phi);
y1=R*Cos(alTS2)*Sin(TS2Psi)*Sin(TS2Phi);
z1=R*Cos(alTS2)*Cos(TS2Psi);

Point(1300)  = {x1,y1,z1,size};

x2 =  R*Sin(TS2Psi+alTS2)*Cos(TS2Phi);
y2 = R*Sin(TS2Psi+alTS2)*Sin(TS2Phi);
z2 = R*Cos(TS2Psi+alTS2);

Point(1400)  = {x2,y2,z2,size};

Rotate { {x1,y1,z1} , {0,0,0}, Pi/2} {Duplicata {   Point{1400} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, -Pi/2} {Duplicata {  Point{1400} ; }}
Rotate { {x1,y1,z1} , {0,0,0}, Pi} {Duplicata {     Point{1400} ; }}

Circle(25) = {1401,1300,1403};
Circle(26) = {1403,1300,1402};
Circle(27) = {1402,1300,1400};
Circle(28) = {1400,1300,1401};

// Punkt der unteren Späre ==============================

pUsPsi = Pi ;
pUsPhi = 0 ;

x1=R*Sin(pUsPsi)*Cos(pUsPhi);
y1=R*Sin(pUsPsi)*Sin(pUsPhi);
z1=R*Cos(pUsPsi);

Point(1500)  = {x1,y1,z1,size};

// Stützpunkte Äquator ==============================

Sp1Psi = Pi/3;
Sp1Phi = 0.0;

x2 =  R*Sin(Sp1Psi)*Cos(Sp1Phi);
y2 = R*Sin(Sp1Psi)*Sin(Sp1Phi);
z2 = R*Cos(Sp1Psi);

Point(2000)  = {x2,y2,z2,size};
Point(2030)  = {x2,y2,-z2,size};

x1 = 0;
y1 = 0;
z1=R*Cos(Sp1Psi);

Point(1600)  = {x1,y1,z1,size};
Point(1700)  = {x1,y1,-z1,size};

Rotate { {x1,y1,z1} ,{0,0,0},  Pi/4} {Duplicata {   Point{2000} ; }}
Rotate { {x1,y1,z1} ,{0,0,0},  Pi*3/4} {Duplicata {  Point{2000} ; }}
Rotate { {x1,y1,z1} ,{0,0,0},  -Pi/4} {Duplicata {   Point{2000} ; }}
Rotate { {x1,y1,z1} ,{0,0,0},  -Pi*3/4} {Duplicata {  Point{2000} ; }}

Rotate { {x1,y1,z1} ,{0,0,0},  Pi/4} {Duplicata    {   Point{2030} ; }}
Rotate { {x1,y1,z1} ,{0,0,0},  Pi*3/4} {Duplicata  {   Point{2030} ; }}
Rotate { {x1,y1,z1} ,{0,0,0},  -Pi/4} {Duplicata   {   Point{2030} ; }}
Rotate { {x1,y1,z1} ,{0,0,0},  -Pi*3/4} {Duplicata {   Point{2030} ; }}

//Circle(29) = {1703,1700,1704};
//Circle(30) = {1603,1600,1604};
//Circle(31) = {1703,0,1603};
//Circle(32) = {1604,0,1704};

Circle(200) = {1500,0,2035};
Circle(201) = {1500,0,2036};
Circle(202) = {1500,0,2037};
Circle(203) = {1500,0,2038};

Circle(204) = {2035,1700,2037};
Circle(205) = {2037,1700,2038};
Circle(206) = {2038,1700,2036};
Circle(207) = {2036,1700,2035};

Circle(208) = {2031,0,2035};
Circle(209) = {2033,0,2037};
Circle(210) = {2034,0,2038};
Circle(211) = {2032,0,2036};

Circle(212) = {2031,1600,2032};
Circle(213) = {2032,1600,2034};
Circle(214) = {2034,1600,2033};
Circle(215) = {2033,1600,2031};

Circle(216) = {2031,0,801};
Circle(217) = {2033,0,807};

Circle(218) = {2032,0,803};
Circle(219) = {2034,0,805};
//

Line Loop(220) = {4,1,2,3};
Ruled Surface(221) = {220} In Sphere{0};
Line Loop(222) = {213,210,206,-211};
Ruled Surface(223) = {222,220} In Sphere{0};
