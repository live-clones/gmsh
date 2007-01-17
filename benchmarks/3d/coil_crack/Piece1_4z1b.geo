Include "Piece_dat.pro";
//Defect

LAYERS = 1 ;

//   length x width x depth (mm)
//B  1 x 0.2 x 0.1
//D  1 x 0.4 x 0.2
length = 1 * mm ;
depth = 0.1 * mm ;//Shape: half disk
width = 2 * depth ;


//Mesh.Algorithm = 2 ; // 2D mesh algorithm (1=isotropic, 2=anisotropic, 3=triangle)
//Mesh.Algorithm3D = 1; // 3D mesh algorithm (1=isotropic, 4=netgen, 5=tetgen)
Mesh.RandomFactor = 0.0002 ;

Geometry.AutoCoherence = 1;

s = 1. ;

Freq = 100.e3 ;
mu0 = 4.e-7 * Pi ;
sigma = 1.798e6 ;//Titanium
delta =  Sqrt[1/(mu0*Freq*sigma*Pi)] ;// skin depth

Printf("Freq %g delta %g",Freq,delta);

pdwn = h1/2/s ;

pflaw = width/4/s;
pflaw2 = width/2/s;

ph1 = h1/3/s ;
ph2 = 14*pflaw ;
ph3 = 14*pflaw ;
ph3_ = 14*pflaw ;

pBox = 4*pdwn/s;

AngRot = Pi/16 ;
AngRot_ = -2*AngRot;

nDefect = Ceil[length/pflaw]; //20 ;
nAngle  = Ceil[AngRot*Rdwn/ph1] ;

Rlimup  = 0.8*Rup ;
Rlimdwn = 0.75*Rdwn;

// Box
xBox1 = Rlimdwn*1.2 ;
xBox2 = 0.4*Rup ; //-xBox1/3 ;
yBox1 = 2.*h2 ;
yBox2 = -0.8*h2 ;

zB[] = {0.35*xBox1,-0.35*xBox1};

//---------------------------------------------------------------------
//---------------------------------------------------------------------

//Defect Zone 1, centered around (h3+h2)/2
rr = Rup ;
aa = 2*Asin[width/2./rr];
zz = rr*Sin[aa/2];
xx = rr*Cos[aa/2];

//Piece
cen[0] = newp ; Point(cen[0])={0, 0, 0, pdwn};
cen[1] = newp ; Point(cen[1])={Rc,h2,0, ph2};//curve

cen[2] = newp ; Point(cen[2])={0,h1,0,ph1};
cen[3] = newp ; Point(cen[3])={0,h2,0,ph2};
cen[4] = newp ; Point(cen[4])={0,h3,0,ph3};

p[0] = newp ; Point(p[0])={Rlimdwn, 0, 0,pdwn};
p[1] = newp ; Point(p[1])={Rlimdwn, h1, 0,ph1};
p[2] = newp ; Point(p[2])={Rc, h1, 0, ph1};

p[3] = newp ; Point(p[3])={Rc-R10,h2,0,ph2};

p[4] = newp ; Point(p[4])={Rup, h3-length, 0, ph3};
p[5] = newp ; Point(p[5])={Rup, h3, 0, ph3};

p[6] = newp ; Point(p[6])={Rlimup, h3, 0, ph3_};
p[7] = newp ; Point(p[7])={Rlimup,  0, 0, pdwn};

lp[0] = newl ; Line(lp[0])={p[6],p[7]};//axis

lp[1] = newl ; Line(lp[1])={p[0],p[1]};
lp[2] = newl ; Line(lp[2])={p[1],p[2]};
lp[3] = newl ; Circle(lp[3])={p[2],cen[1],p[3]};
lp[4] = newl ; Line(lp[4])={p[3],p[4]};
lp[5] = newl ; Line(lp[5])={p[4],p[5]};
lp[6] = newl ; Line(lp[6])={p[5],p[6]};
lp[7] = newl ; Line(lp[7])={p[7],p[0]};

surf0 = news ; 
Line Loop(surf0) = {lp[1],lp[2],lp[3],lp[4],lp[5],lp[6],lp[0],lp[7]};
Plane Surface(surf0) = {surf0};

surf[]= Rotate {{0.0,1.0,0.0},{0.0,0.0,0.0},aa/2} {Surface{surf0};};
sRight =surf[0]; 
surf[]= Rotate {{0.0,1.0,0.0},{0.0,0.0,0.0},-aa} { Duplicata{Surface{sRight};} };
sLeft = surf[0];

//Defect
cend1 = newp ; Point(cend1)={Rup,h3-length,0,pflaw};
cend2 = newp ; Point(cend2)={0,h3-length,0,pflaw};

pd[0] = 10 ;
pd[1] = 28 ;

/*
pd[0] = newp ; Point(pd[0])={xx,h3-length,zz,pflaw};
pd[1] = newp ; Point(pd[1])={xx,h3-length,-zz,pflaw};
*/

pd[2] = newp ; Point(pd[2])={Rup-depth,h3-length,0,pflaw};


cd[0]= newl ; Circle(cd[0])={pd[0],cend1,pd[2]};
cd[1]= newl ; Circle(cd[1])={pd[2],cend1,pd[1]};
cd[2] = newl ;Circle(cd[2]) = {pd[0],cend2, pd[1]} ;

sDefect = news ;
Line Loop(sDefect) = {cd[2],-cd[1],-cd[0]};
Plane Surface(sDefect) = {sDefect};

If (LAYERS)
vol[]=Extrude Surface{sDefect, {0,length,0}} 
//;;
{Layers {{nDefect},{1}};};;
vDefect = vol[1];

vol[] = Extrude Surface {sRight, {0.0,1.0,0.0}, {0.0,0.0,0.0},AngRot-aa/2}// ;;
  {Layers {{nAngle},{1}};}; ;
vPieceR=vol[1];

vol[] = Extrude Surface {sLeft, {0.0,1.0,0.0}, {0.0,0.0,0.0},-(AngRot-aa/2)}// ;;
  {Layers {{nAngle},{1}};}; ;
vPieceL=vol[1];
EndIf

If (!LAYERS)
vol[]=Extrude Surface{sDefect, {0,length,0}} ;;
vDefect = vol[1];

vol[] = Extrude Surface {sRight, {0.0,1.0,0.0}, {0.0,0.0,0.0},AngRot-aa/2} ;;
vPieceR=vol[1];

vol[] = Extrude Surface {sLeft, {0.0,1.0,0.0}, {0.0,0.0,0.0},-(AngRot-aa/2)};;
vPieceL=vol[1];
EndIf







Printf("vPieceR %g vPieceL %g",vPieceR,vPieceL);

Circle(124) = {14,1,6};
Circle(125) = {15,3,7};
Circle(126) = {19,3,8};
Circle(127) = {24,4,9};
Circle(128) = {36,5,12};
Circle(129) = {40,1,13};
Line Loop(130) = {124,2,-125,-11};
Ruled Surface(131) = {130};
Line Loop(132) = {126,4,-127,-13};
Ruled Surface(133) = {132};
Line Loop(134) = {127,5,21,-14};
Ruled Surface(135) = {134};
Line Loop(136) = {129,-1,-128,17};
Ruled Surface(137) = {136};
Line Loop(138) = {125,3,-126,-12};
Plane Surface(139) = {138};
Line Loop(140) = {124,-8,-129,18};
Plane Surface(141) = {140};
Line Loop(142) = {16,128,-7,-26,-25};
Plane Surface(143) = {142};

Surface Loop(144) = {131,-141,-9,139,133,135,-22,34,38,-143,10,-137};
Volume(145) = {144};
vPieceC=145;

//Include "Probe.geo";
Include "KDS70-2z1.geo";

For k In {0:1}
Point(newp)={ xBox2, yBox2,  zB[k], pBox};
Point(newp)={ xBox1, yBox2,  zB[k], pBox};
Point(newp)={ xBox1, yBox1,  zB[k], pBox};
Point(newp)={ xBox2, yBox1,  zB[k], pBox};

lbox[4*k] = newl ; Line(lbox[4*k])={newp-4,newp-3};
lbox[4*k+1] = newl ; Line(lbox[4*k+1])={newp-3,newp-2};
lbox[4*k+2] = newl ; Line(lbox[4*k+2])={newp-2,newp-1};
lbox[4*k+3] = newl ; Line(lbox[4*k+3])={newp-1,newp-4};

sbox[k] = news ; Line Loop(sbox[k]) = {newreg-4:newreg-1};
Plane Surface(sbox[k]) = {sbox[k]};
EndFor


lbv1 =newl; Line(lbv1)={newp-8,newp-4};
lbv2 =newl; Line(lbv2)={newp-7,newp-3};
lbv3 =newl; Line(lbv3)={newp-6,newp-2};
lbv4 =newl; Line(lbv4)={newp-5,newp-1};

sbox1 = news ; Line Loop(news) = {lbox[0],lbv2,-lbox[4],-lbv1};
Plane Surface(sbox1) = {sbox1};
sbox2 = news ; Line Loop(news) = {lbox[1],lbv3,-lbox[5],-lbv2};
Plane Surface(sbox2) = {sbox2};
sbox3 = news ; Line Loop(news) = {lbox[2],lbv4,-lbox[6],-lbv3};
Plane Surface(sbox3) = {sbox3};
sbox4 = news ; Line Loop(news) = {lbox[3],lbv1,-lbox[7],-lbv4};
Plane Surface(sbox4) = {sbox4};

Surface Loop(news) =  {sbox2,-sbox[0],sbox1,sbox[1],sbox3,sbox4};
Surface Loop(news) = 
{52,-131,141,80,81,56,-139,-133,60,64,-135,30,-110,-114,143,137,76,72,68,-118,-122,-94,-98,-102,-106,-123,39}; 
vAir= newv;
Volume(vAir) = {news-2,news-1,surftotprobe};//Rest Air

Characteristic Length{10,11,28,32}= pflaw ;//Watch out! Changing characteristic lenths of the flaw at the end
//Characteristic Length{66,93}= ph3 ;

//Transfinite Line{cd[0],cd[1],cd[2]} = 5 ;
//Transfinite Line{15,6} = nDefect+1 ;

//-------------------------------------------------------------------

Physical Volume (CRACK) = {vDefect};
Physical Volume(PIECE)={vPieceR,vPieceL,vPieceC};

Physical Surface(SKINPIECE) =
{72,143,-114,-118,137,141,-131,52,56,-139,-133,60,64,-135,22,-34,-38,68,81,76,80,-110,-123,-94,-98,-102,-106,-122};
Physical Surface(SKINPIECEWCRACK) =
{52,-131,141,80,81,56,-139,-133,60,64,-135,30,-110,-114,143,137,76,72,68,-118,-122,-94,-98,-102,-106,-123,39}; 

Physical Volume(AIR) = {vAir};
Physical Surface(SURFACEGH0) = {sbox[0],-sbox1,-sbox2,-sbox3,-sbox4,-sbox[1]};


