Include "CoilAboveACrack_dat.pro";

Mesh.Algorithm = 1;

// Characteristic lengths

s=2.2;

pPlate = dxPlate/16. *s;
pPlate2 = pPlate/2.;
pBox = (dyBox-dyPlate)/2. /4. *s * 2;

pCrack0 = lengthCrack/12. *s;
pCrack1 = lengthCrack/12. *s;

pCore = 2*Pi*rCore/32 *s;
pCoil = 2*Pi*rExtCoil/32 *s;


// GEOMETRY
// --------

// Plate
yy = rPlate*Sin[aPlate];
zz = zCentre - rPlate*Cos[aPlate];

Point(1)={-dxPlate/2., -yy, zz, pPlate};
Point(2)={ dxPlate/2., -yy, zz, pPlate};
Point(3)={ dxPlate/2.,  yy, zz, pPlate};
Point(4)={-dxPlate/2.,  yy, zz, pPlate};

Point(5)={-dxPlate/2., 0., zPlate, pPlate};
Point(6)={ dxPlate/2., 0., zPlate, pPlate};

Point(9) = {-dxPlate/2.,0., zCentre, pPlate};
Point(10) = {dxPlate/2.,0., zCentre, pPlate};

yy = rPlateInt*Sin[aPlate];
zz = zCentre - rPlateInt*Cos[aPlate];

Point(21)={-dxPlate/2., -yy, zz, pPlate};
Point(22)={ dxPlate/2., -yy, zz, pPlate2};
Point(23)={ dxPlate/2.,  yy, zz, pPlate2};
Point(24)={-dxPlate/2.,  yy, zz, pPlate};

// Box
Point(11)={-dxPlate/2.-dxBox0, -dyBox/2., 0, pBox};
Point(12)={ dxPlate/2.+dxBox1, -dyBox/2., 0, pBox};
Point(13)={ dxPlate/2.+dxBox1,  dyBox/2., 0, pBox};
Point(14)={-dxPlate/2.-dxBox0,  dyBox/2., 0, pBox};

// Crack

rr = rPlateInt;
aa = 2*Asin[widthCrack/2./rPlateInt];
yy = rr*Sin[aa/2.];
zz = zCentre - rr*Cos[aa/2.];

Point(51)={xCrack+lengthCrack, -yy, zz, pCrack0};
Point(52)={xCrack+lengthCrack, yy, zz, pCrack0};
Point(53)={xCrack, yy, zz, pCrack1};
Point(54)={xCrack, -yy, zz, pCrack1};

zz = zCentre - (rr+depthCrack)*Cos[aa/2.];

Point(55)={xCrack+lengthCrack, -yy, zz, pCrack0};
Point(56)={xCrack+lengthCrack, yy, zz, pCrack0};
Point(57)={xCrack, yy, zz, pCrack1};
Point(58)={xCrack, -yy, zz, pCrack1};

// Probe

Point(60)={xProbe, yProbe, zCore, pCore};

Point(61)={xProbe+rCore, yProbe, zCore, pCore};
Point(62)={xProbe, yProbe+rCore, zCore, pCore};
Point(63)={xProbe-rCore, yProbe, zCore, pCore};
Point(64)={xProbe, yProbe-rCore, zCore, pCore};


Point(70)={xProbe, yProbe, zCoil, pCoil};

Point(71)={xProbe+rExtCoil, yProbe, zCoil, pCoil};
Point(72)={xProbe, yProbe+rExtCoil, zCoil, pCoil};
Point(73)={xProbe-rExtCoil, yProbe, zCoil, pCoil};
Point(74)={xProbe, yProbe-rExtCoil, zCoil, pCoil};


// Lines

Line(1) = {11,12};
Line(2) = {12,13};
Line(3) = {13,14};
Line(4) = {14,11};
Line(5) = {1,2};
Circle(7) = {51,10,52};
Line(9) = {3,4};
Line(11) = {54,51};
Circle(12) = {54,9,53};
Line(13) = {53,52};
Circle(14) = {61,60,62};
Circle(15) = {62,60,63};
Circle(16) = {63,60,64};
Circle(17) = {64,60,61};
Circle(18) = {71,70,72};
Circle(19) = {72,70,73};
Circle(20) = {73,70,74};
Circle(21) = {74,70,71};

Line(25) = {21,22};
Line(26) = {23,24};


Circle(31) = {1,9,5};
Circle(32) = {5,9,4};
Circle(33) = {2,10,6};
Circle(34) = {6,10,3};

Circle(41) = {21,9,24};
Circle(43) = {22,10,23};

Line(51) = {1,21};
Line(52) = {2,22};
Line(53) = {4,24};
Line(54) = {3,23};

Line(61) = {5,6};

Circle(65) = {55,10,56};
Line(66) = {58,55};
Circle(67) = {58,9,57};
Line(68) = {57,56};

Line(71) = {58,54};
Line(72) = {55,51};
Line(73) = {56,52};
Line(74) = {57,53};

// Surfaces

Line Loop(301) = {15,16,17,14};
Plane Surface(302) = {301};



volCORE[] = Extrude Surface {302, {0,0,zCoil-zCore}};;
volCORE0_1[] = Extrude Surface {324, {0,0,dzCoil}};;
volCORE0_2[] = Extrude Surface {346, {0,0,dzCore-dzCoil-(zCoil-zCore)}};;

Line Loop(369) = {18,19,20,21};
Line Loop(370) = {306,307,304,305};
Plane Surface(371) = {369,370};

volCOIL[] = Extrude Surface {371, {0,0,dzCoil}};;


Line Loop(414) = {43,-54,-34,-33,52};
Plane Surface(415) = {414};
Line Loop(416) = {41,-53,-32,-31,51};
Plane Surface(417) = {416};
Line Loop(418) = {25,-52,-5,51};
Plane Surface(419) = {418};
Line Loop(420) = {-53,-9,54,26};
Plane Surface(421) = {420};
Line Loop(422) = {33,-61,-31,5};
Ruled Surface(423) = {422};
Line Loop(424) = {34,9,-32,61};
Ruled Surface(425) = {424};

Line Loop(426) = {11,-72,-66,71};
Plane Surface(427) = {426};
Line Loop(428) = {13,-73,-68,74};
Plane Surface(429) = {428};

Line Loop(430) = {13,-7,-11,12};
Ruled Surface(431) = {430};
Line Loop(432) = {65,-68,-67,66};
Ruled Surface(433) = {432};
Line Loop(434) = {7,-73,-65,72};
Ruled Surface(435) = {434};
Line Loop(436) = {12,-74,-67,71};
Ruled Surface(437) = {436};

Line Loop(438) = {43,26,-41,25};
Ruled Surface(439) = {438,430};

Line Loop(440) = {2,3,4,1};
Plane Surface(441) = {440};

volAIR[] = Extrude Surface {441, {0,0,zBox1}};;
Delete { Volume{volAIR[1]}; }

Characteristic Length {101, 108, 103, 113} = pCore*1;
/*
Surface Loop(466) = {337,371,384,388,392,396,413,341,345,333};
Volume(467) = {466}; // Coil
*/
Surface Loop(468) = {427,439,415,421,417,425,423,419,429,435,433,437};
Volume(469) = {468}; // Plate

Surface Loop(470) = {431,429,435,433,437,427};
Volume(471) = {470}; // Crack

Surface Loop(472) = {441,450,454,458,462,463};
Surface Loop(473) = {431,439,415,421,417,425,423,419};
Surface Loop(474) = {323,302,311,315,319,371,384,388,392,396,413,363,367,355,359,368};
Volume(475) = {472,473,474};
/*
Surface Loop(464) = {324,333,337,341,345,367,355,359,363,368};
Volume(465) = {464}; // Core0
Surface Loop(476) = {324,311,302,315,319,323};
Volume(477) = {476}; // Core
*/

// Physical regions

Physical Volume(CORE0) = {volCORE0_1[1], volCORE0_2[1]};

Physical Volume(CORE) = {volCORE[1]};

Physical Volume(COIL) = {volCOIL[1]};

Physical Volume(PLATE) = {469};

Physical Volume(CRACK) = {471};

Physical Volume(AIR) = {475};

Physical Surface(SKINCORE) = {359,337,315,302,311,333,355,368,363,341,319,323,345,367};

Physical Surface(SKINCOIL) = {337,371,384,388,392,396,413,341,345,333};
Physical Surface(SKINCOIL2) = {333, 337, 341, 345};

Physical Surface(CUTCOIL) = {324};

Physical Surface(SKINPLATE) = {427,439,415,421,417,425,423,419,429,435,433,437};

Physical Surface(SURFACEGH0) = {441,450,454,458,462,463};
