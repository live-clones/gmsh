// Mudanca de algumas coordenadas 22/05/2001 - Liège.

/* Desenho do servo motor em 3D  -   20/07/2000 */

/* Analise de um servomotor de imas permanentes - GRUCAD - julho de 2000 */

rR1 = 10.5e-03;
rR2 = 23.243e-03;
rR3 = 23.862e-03;
rR4 = 23.9e-03;
rR5 = 25.6e-03;

rS1 = 26.02e-03;
rS2 = 26.62e-03;
rS3 = 26.96e-03;
rS4 = 38.16e-03;
rS5 = 38.27e-03;
rS6 = 40.02e-03;
rS7 = 46.0e-03;

Gap = rS1-rR5;

rB1=rR5+Gap/3; rB1b=rB1;
//rB1=rR5+Gap/3.7; rB1b=rR5+Gap/2.3; //To see both different surfaces
rB2=rR5+Gap*2/3;


NbrDiv = 16;

A0 = 45.0;
/* Rotor position(deg):use 0 for the mesh and other angles for drawing*/
//A1 = 4.0001*45.0/NbrDiv;
A1 = 90. ;

deg2rad = Pi/180;

/* Mesh parameters */

s = 1.;

pR1 =(rR2-rR1)/10.*s;
pR2 =(rR2-rR1)/12.*s;

pS1 =(rS7-rS1)/7.*s;
pS2 =(rS7-rS1)/12.*s;
pS3 =(rS6-rS3)/10.*s;


// Uma das faces do servo motor

/* Rotor */

Point(1)={0,0,0,pR1};

A = 0.+A1; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(2)={rR1*cosA,rR1*sinA,0,pR1};
Point(3)={rR4*cosA,rR4*sinA,0,pR1};
Point(4)={rR5*cosA,rR5*sinA,0,pR1};

Point(5)={rB1*cosA,rB1*sinA,0,pR2};

A = 4.455+A1; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(6)={rR2*cosA,rR2*sinA,0,pR1};

A = 4.938+A1; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(7)={rR3*cosA,rR3*sinA,0,pR1};

A = 6.165+A1; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(8)={rR5*cosA,rR5*sinA,0,pR1};

A = 38.835+A1; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(9)={rR5*cosA,rR5*sinA,0,pR1};

A = 40.062+A1; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(10)={rR3*cosA,rR3*sinA,0,pR1};

A = 40.545+A1; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(11)={rR2*cosA,rR2*sinA,0,pR1};

A = 45.0+A1; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(12)={rR1*cosA,rR1*sinA,0,pR1};
Point(13)={rR4*cosA,rR4*sinA,0,pR1};
Point(14)={rR5*cosA,rR5*sinA,0,pR1};

Point(15)={rB1*cosA,rB1*sinA,0,pR2};

/* Gap */

Point(16)={rB1b,0,0,pS1};
Point(17)={rB2,0,0,pS1};

A = 45.0; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(18)={rB1b*cosA,rB1b*sinA,0,pS1};
Point(19)={rB2*cosA,rB2*sinA,0,pS1};


/* Stator */

Point(20)={rS1,0,0,pS1};
Point(21)={rS7,0,0,pS2};

A = 5.71+0; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(61)={rS7*cosA,rS7*sinA,0,pS3};
A = 5.71+15; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(62)={rS7*cosA,rS7*sinA,0,pS3};
A = 5.71+30; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(63)={rS7*cosA,rS7*sinA,0,pS3};

//A = 22.5; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
//Point(22)={rS7*cosA,rS7*sinA,0,pS2};

A = 45.0; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(23)={rS1*cosA,rS1*sinA,0,pS1};
Point(24)={rS7*cosA,rS7*sinA,0,pS2};

/* Pontos da ranhura 01 */

A2 = 0.0;

A = 2.77+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(25)={rS5*cosA,rS5*sinA,0,pS3};

A = 4.0+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(26)={rS3*cosA,rS3*sinA,0,pS3};

A = 5.52+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(27)={rS1*cosA,rS1*sinA,0,pS3};

A = 5.56+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(28)={rS2*cosA,rS2*sinA,0,pS3};

A = 5.56+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(29)={rS4*cosA,rS4*sinA,0,pS3};

A = 5.65+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(30)={rS6*cosA,rS6*sinA,0,pS3};

A = 9.35+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(31)={rS6*cosA,rS6*sinA,0,pS3};

A = 9.44+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(32)={rS4*cosA,rS4*sinA,0,pS3};

A = 9.44+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(33)={rS2*cosA,rS2*sinA,0,pS3};

A = 9.48+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(34)={rS1*cosA,rS1*sinA,0,pS3};

A = 11.0+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(35)={rS3*cosA,rS3*sinA,0,pS3};

A = 12.23+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(36)={rS5*cosA,rS5*sinA,0,pS3};

/* Pontos da ranhura 02 */

A2 = 15.0;

A = 2.77+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(37)={rS5*cosA,rS5*sinA,0,pS3};

A = 4.0+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(38)={rS3*cosA,rS3*sinA,0,pS3};

A = 5.52+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(39)={rS1*cosA,rS1*sinA,0,pS3};

A = 5.56+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(40)={rS2*cosA,rS2*sinA,0,pS3};

A = 5.56+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(41)={rS4*cosA,rS4*sinA,0,pS3};

A = 5.65+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(42)={rS6*cosA,rS6*sinA,0,pS3};

A = 9.35+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(43)={rS6*cosA,rS6*sinA,0,pS3};

A = 9.44+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(44)={rS4*cosA,rS4*sinA,0,pS3};

A = 9.44+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(45)={rS2*cosA,rS2*sinA,0,pS3};

A = 9.48+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(46)={rS1*cosA,rS1*sinA,0,pS3};

A = 11.0+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(47)={rS3*cosA,rS3*sinA,0,pS3};

A = 12.23+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(48)={rS5*cosA,rS5*sinA,0,pS3};

/* Pontos da ranhura 03 */

A2 = 30.0;

A = 2.77+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(49)={rS5*cosA,rS5*sinA,0,pS3};

A = 4.0+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(50)={rS3*cosA,rS3*sinA,0,pS3};

A = 5.52+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(51)={rS1*cosA,rS1*sinA,0,pS3};

A = 5.56+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(52)={rS2*cosA,rS2*sinA,0,pS3};

A = 5.56+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(53)={rS4*cosA,rS4*sinA,0,pS3};

A = 5.65+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(54)={rS6*cosA,rS6*sinA,0,pS3};

A = 9.35+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(55)={rS6*cosA,rS6*sinA,0,pS3};

A = 9.44+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(56)={rS4*cosA,rS4*sinA,0,pS3};

A = 9.44+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(57)={rS2*cosA,rS2*sinA,0,pS3};

A = 9.48+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(58)={rS1*cosA,rS1*sinA,0,pS3};

A = 11.0+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(59)={rS3*cosA,rS3*sinA,0,pS3};

A = 12.23+A2; sinA=Sin(A*deg2rad);cosA=Cos(A*deg2rad);
Point(60)={rS5*cosA,rS5*sinA,0,pS3};


// linhas e circulos do rotor

Line(1)={1,2};
Line(2)={2,3};
Line(3)={3,4};
Line(4)={4,5};
Line(5)={3,7};
Line(6)={6,7};
Line(7)={7,8};
Line(8)={6,11};
Line(9)={11,10};
Line(10)={10,9};
Line(11)={1,12};
Line(12)={12,13};
Line(13)={13,14};
Line(14)={14,15};
Line(15)={13,10};
Circle(16)={2,1,12};
Circle(17)={4,1,8};
Circle(18)={8,1,9};
Circle(19)={9,1,14};
Circle(20)={5,1,15};

/* linhas e circulos do entreferro */

Line(21)={16,17};
Line(22)={17,20};
Line(23)={18,19};
Line(24)={19,23};
Circle(25)={16,1,18};
Circle(26)={17,1,19};

/* linhas e circulos do estator */
Line(27)={20,21};
Line(28)={23,24};
Circle(29)={20,1,27};
Circle(30)={34,1,39};
Circle(31)={46,1,51};
Circle(32)={58,1,23};
Circle(33)={21,1,61};
Circle(34)={61,1,62};
Circle(89)={62,1,63};
Circle(90)={63,1,24};

Line(91)={30,61};
Line(92)={42,62};
Line(93)={54,63};

/* linhas e circulos da ranhura 01 */
Line(35)={27,28};
Line(36)={28,26};
Line(37)={26,25};
Circle(38)={25,29,30};
Line(39)={30,31};
Circle(40)={31,32,36};
Line(41)={36,35};
Line(42)={35,33};
Line(43)={33,34};
Line(44)={26,35};

/* linhas e circulos da ranhura 02 */
Line(45)={39,40};
Line(46)={40,38};
Line(47)={38,37};
Circle(48)={37,41,42};
Line(49)={42,43};
Circle(50)={43,44,48};
Line(51)={48,47};
Line(52)={47,45};
Line(53)={45,46};
Line(54)={38,47};

/* linhas e circulos da ranhura 03 */
Line(55)={51,52};
Line(56)={52,50};
Line(57)={50,49};
Circle(58)={49,53,54};
Line(59)={54,55};
Circle(60)={55,56,60};
Line(61)={60,59};
Line(62)={59,57};
Line(63)={57,58};
Line(64)={50,59};

/* superficies do rotor */

Line Loop(65) = {-11,1,16};
Plane Surface(66) = {65};
Line Loop(67) = {12,15,-9,-8,6,-5,-2,16};
Plane Surface(68) = {67};
Line Loop(69) = {7,-17,-3,5};
Plane Surface(70) = {69};
Line Loop(71) = {-18,-7,-6,8,9,10};
Plane Surface(72) = {71};
Line Loop(73) = {-19,-10,-15,13};
Plane Surface(74) = {73};
Line Loop(75) = {18,19,14,-20,-4,17};
Plane Surface(76) = {75};

/* superficies do entreferro (banda de movimento) */

Transfinite Line{20,25,26}=NbrDiv+1 Using Power 1.;
Transfinite Line{21,23}=2;
Line Loop(77) = {-23,-25,21,26};
Plane Surface(78) = {77};
Transfinite Surface{78}={16,17,19,18};
Recombine Surface{78};  // For Hexahedra in the Moving Band

/* superficies do estator */

Line Loop(79) = {24,-32,-63,-62,-64,-56,-55,-31,-53,-52,-54,-46,-45,-30,-43,-42,-44,-36,-35,-29,-22,26};
Plane Surface(80) = {79};


Line Loop(94) = {37,38,91,-33,-27,29,35,36};
Plane Surface(95) = {94};
Line Loop(96) = {42,43,30,45,46,47,48,92,-34,-91,39,40,41};
Plane Surface(97) = {96};
Line Loop(98) = {52,53,31,55,56,57,58,93,-89,-92,49,50,51};
Plane Surface(99) = {98};
Line Loop(100) = {62,63,32,28,-90,-93,59,60,61};
Plane Surface(101) = {100};
/*
Line Loop(81) = {37,38,39,40,41,42,43,30,45,46,47,48,49,50,51,52,53,31,55,56,57,58,59,60,61,62,63,32,28,-90,-89,-34,-33,-27,29,35,36};
Plane Surface(82) = {81};
*/
/* superficie da ranhura 01 */

Line Loop(83) = {-41,-40,-39,-38,-37,44};
Plane Surface(84) = {83};

/* superficie da ranhura 02 */

Line Loop(85) = {-51,-50,-49,-48,-47,54};
Plane Surface(86) = {85};

/* superficie da ranhura 03 */
Line Loop(87) = {-61,-60,-59,-58,-57,64};
Plane Surface(88) = {87};

// Continue with 101 ...

// ----------------------------------------------------
// ----------------------------------------------------

L_ = 1000000 ;
S_ = 2000000 ;
V_ = 3000000 ;
P_ = 4000000 ;
N_ = 1000 ;


Physical Volume(1301) = {V_+N_+68}; // Rotor

//Physical Volume(1302) = {V_+N_+95, V_+N_+97, V_+N_+99, V_+N_+101}; // Stator

Physical Volume(1320) = {V_+N_+95}; // StatorSup0
Physical Volume(1321) = {V_+N_+97}; // StatorSup1
Physical Volume(1322) = {V_+N_+99}; // StatorSup2
Physical Volume(1323) = {V_+N_+101}; // StatorSup3

Physical Volume(1300) = {V_+N_+66}; // AirInt
Physical Volume(1303) = {V_+N_+76}; // AirRotor
Physical Volume(1304) = {V_+N_+80}; // AirStator
Physical Volume(1305) = {V_+N_+78}; // AirBM

Physical Volume(1310) = {V_+N_+72}; // Magnet

Physical Volume(1311) = {V_+N_+70}; // Cale1
Physical Volume(1312) = {V_+N_+74}; // Cale2

Physical Volume(1401) = {V_+N_+84}; // Ind1
Physical Volume(1402) = {V_+N_+86}; // Ind2
Physical Volume(1403) = {V_+N_+88}; // Ind3


Physical Surface(2001) = {L_+N_+16}; // SurfInt
Physical Surface(2002) = {L_+N_+33,L_+N_+34,L_+N_+89,L_+N_+90}; // SurfExt

Physical Surface(1011) = {L_+N_+ 1, L_+N_+2, L_+N_+3, L_+N_+4, L_+N_+21,L_+N_+22, L_+N_+27}; // SurfA
Physical Surface(1012) = {L_+N_+11,L_+N_+12,L_+N_+13,L_+N_+14, L_+N_+23,L_+N_+24, L_+N_+28}; // SurfB


Physical Surface(1501) = {L_+N_+20}; // SurfR
Physical Surface(1502) = {L_+N_+25}; // SurfBM

Physical Line(2021) = {P_+N_+15}; // PointR
Physical Line(2022) = {P_+N_+18}; // PointBM

// SurfR (PointR) & SurfBM (PointBM) are lines (points) located at the same
// position, but with distinct nodes


// For h-formulation (cut ...)
Physical Surface(2210) = {L_+N_+37,L_+N_+38,/*L_+N_+39,*/L_+N_+40,L_+N_+41,L_+N_+44}; // SkinInd1
Physical Surface(2211) = {L_+N_+91}; // CutInd1
Physical Surface(2212) = {L_+N_+39}; // SkinInd1_2

Physical Surface(2220) = {L_+N_+47,L_+N_+48,/*L_+N_+49,*/L_+N_+50,L_+N_+51,L_+N_+54}; // SkinInd2
Physical Surface(2221) = {L_+N_+92}; // CutInd2
Physical Surface(2222) = {L_+N_+49}; // SkinInd2_2

Physical Surface(2230) = {L_+N_+57,L_+N_+58,/*L_+N_+59,*/L_+N_+60,L_+N_+61,L_+N_+64}; // SkinInd3
Physical Surface(2231) = {L_+N_+93}; // CutInd3
Physical Surface(2232) = {L_+N_+59}; // SkinInd3_2


Physical Point(2015) = {2}; // PointRef


i = 0*S_+0*N_ ;
Physical Surface(2300) =
{ i+68, i+95,i+97,i+99,i+101, i+66,i+76,i+80,i+78, i+72, i+70,i+74, i+84,i+86,i+88 }; // SurfZ0

i = S_+1*N_ ;
Physical Surface(2301) =
{ i+68, i+95,i+97,i+99,i+101, i+66,i+76,i+80,i+78, i+72, i+70,i+74, i+84,i+86,i+88 }; // SurfZ1

