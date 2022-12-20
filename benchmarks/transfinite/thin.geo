Rint = 1.5 ;//5,3
Rext = 2. ;//6,4

mp = 100;

//3 layers per skindepth (min)

th = 1e-3 ;
lplate = 1 ; // plate is 1 m

hCable = .2 ;  //distance cables - plate
rCable = 54.e-3/2 ;

dCable = .3 ;  // distance between cables

//Post - processing
xin = lplate/2 ;
xmax  = Rint/2 ;

h0 = 0.e-6 ;  h1 = 1. ;
h0p5 = 0.5 ; h1p5 = 1.5 ;
epsilon = 1e-6;

//Physical numbers

CABLE1 = 101;
CABLE2 = 102;

AIRUP  = 104;
AIRDWN = 105;

SHELL = 200 ;
SURFSHELLIN = 201 ;
SURFSHELLOUT = 202;

AIRINFUP  = 300;
AIRINFDWN = 301;

SURINFUP  = 400;
SURINFDWN = 401;

CUTLEFT = 500;
CUTRIGHT = 501;

/////////////////////////////////////////////////////////////////////////////



deltaX = 1 ;
murShell = 1 ;
sigmaShell = 1e6;
FINE = 1 ;


/////////////////////////////////////////////////////////////////////////////


Geometry.OldNewReg = 0;
Geometry.AutoCoherence = 1;

Mesh.CharacteristicLengthFactor = 1;
Mesh.Algorithm = 1;
Mesh.Smoothing = 5;

pint = (Rext-Rint)/5.  ;
pext = (Rext-Rint)/5.  ;

pCable = 9e-3;
pTole = 8e-3;

mu0 = 4.e-7 * Pi ;
//murShell = 1000 ;
//sigmaShell = 11.11e6 ;


//THIN = 0 ;
mk = 1 ; pmk = 1;

If(FINE)
  delta = th/deltaX ;
//delta = Sqrt(1/(mu0*murShell*sigmaShell*Freq*Pi));

 mk = (Ceil[3*th/delta]+1) ; //Number of divisions shielding
  Printf("mk %g", mk);
EndIf

mk = 4;
//-----------------------------------------------------------
//-----------------------------------------------------------


// Print Vector (for checking numbers)
//  IN:
//    vector[] : list of quantities to be printed
// OUT:
//    /
////////
Function PrintVector
vector_size_ = #vector[];
Printf("Vector: size: %g", vector_size_);
For i In {0:vector_size_-1}
  Printf(" %g", vector[i]);
EndFor 
Return
/* use e.g.:
vector[]=yourlist[]; Call PrintVector;
 */

// Definition of Circle
//  IN:
//    x0[0:2]        : Position of center
//    radius         : Circle radius
//    lc             : Mesh size for corner points

Function Def_GeoCircle
cen = newp; 
Point(cen)  = {x0[0],       x0[1],        x0[2], lc};
Point(newp) = {x0[0]+radius,x0[1],        x0[2], lc};
Point(newp) = {x0[0],       x0[1]+radius, x0[2], lc};
Point(newp) = {x0[0]-radius,x0[1],        x0[2], lc};
Point(newp) = {x0[0],       x0[1]-radius, x0[2], lc};

pcir[]= {newp-4,newp-3,newp-2,newp-1};

Circle(newl) = {pcir[0], cen, pcir[1]};
Circle(newl) = {pcir[1], cen, pcir[2]};
Circle(newl) = {pcir[2], cen, pcir[3]};
Circle(newl) = {pcir[3], cen, pcir[0]};

current_loop[]= {newl-4,newl-3,newl-2,newl-1};

If(Flag_Surf)
  If(!Flag_Hole)
    llnbr = newll ;
    Line Loop(llnbr) = current_loop[];
    surfcircle = news ;
    Plane Surface(surfcircle) = {newll-1};
  EndIf

  If(Flag_Hole)
    llnbr = newll;
    Line Loop(llnbr) = current_loop[];
    llnbrhole = newll;
    Line Loop(llnbrhole) = hole_loop[]; 
    surfring = news ;
    Plane Surface(surfring) = {llnbr,llnbrhole};
  EndIf
EndIf
Return

llnbrCable[]={};
//-----------------------------------------------------------
//-----------------------------------------------------------

Flag_Surf = 1;
radius = rCable; lc = pCable;
xc = -dCable/2 ; yc = -hCable ;
x0[]={xc,yc,0}; Flag_Hole = 0; 
Call Def_GeoCircle;
loopCable1[] = current_loop[];
llnbrCable[] += llnbr;
surfCable1 = surfcircle ;

xc = dCable/2 ; yc = -hCable ;
x0[]={xc,yc,0}; Flag_Hole = 0; 
Call Def_GeoCircle;
loopCable2[] = current_loop[];
llnbrCable[] += llnbr;
surfCable2 = surfcircle ;

vector[]=llnbrCable[]; Call PrintVector;

//----------------------------------
// B L I N D A G E

x1 = -lplate/2 ; x2 = lplate/2 ; y1 = 0. ; y2 = th;
p = 200;
Point(p+1) = {x1,y1,0, pTole};
Point(p+2) = {x2,y2,0, pTole};
Point(p+3) = {x1,y2,0, pTole};
Point(p+4) = {x2,y1,0, pTole};

r = newl;
Line(r+1) = {p+1,p+3};
Line(r+2) = {p+3,p+2};
Line(r+3) = {p+4,p+2};
Line(r+4) = {p+4,p+1};

Transfinite Line{r+1,r+3} = mk Using Progression pmk;
Transfinite Line{r+2,r+4} = mp Using Progression 1;
Line Loop(r+5) = {r+1,r+2,-r-3,r+4};
loopShield[] = {r+1,r+2,-r-3,r+4};

Plane Surface(r+6) = {r+5};
Transfinite Surface{r+6} = {p+1,p+3,p+2,p+4};
surfblin[]+= r+6;


// I N F I N I T Y
Flag_Surf = 0; Flag_Hole = 0; 

radius = Rint ; lc = pint;
xc = 0 ; yc = 0 ; 
x0[]={xc,yc,0};
Call Def_GeoCircle;
pcirIn[] = pcir[];
loopRint[] = current_loop[];

radius = Rext ; lc = pext;
xc = 0 ; yc = 0 ; 
x0[]={xc,yc,0};
Call Def_GeoCircle;
pcirExt[] = pcir[];
loopRext[] = current_loop[];

// A I R

lInL =newl; Line(lInL) = {pcirIn[2], p+1};
lInR= newl; Line(lInR) = {p+4, pcirIn[0]};

lInfL= newl; Line(lInfL) = {pcirIn[2], pcirExt[2]};
lInfR= newl; Line(lInfR) = {pcirIn[0], pcirExt[0]};

Line Loop(newll) = 
{lInL,loopShield[0],loopShield[1],loopShield[2],lInR,loopRint[0], loopRint[1]}; 
surfAirUp = news;
Plane Surface(surfAirUp) = {newll-1};

Line Loop(newll) = 
{-lInR, loopShield[3],-lInL,loopRint[2], loopRint[3]}; 
surfAirDwn = news;
Plane Surface(surfAirDwn) = {newll-1,llnbrCable[]};

Line Loop(newll) = 
{lInfR, loopRext[0],loopRext[1],-lInfL,-loopRint[1], -loopRint[0]}; 
surfAirInfUp  = news;
Plane Surface(surfAirInfUp) = {newll-1};

Line Loop(newll) = 
{lInfL, loopRext[2],loopRext[3],-lInfR,-loopRint[3], -loopRint[2]}; 
surfAirInfDwn = news;
Plane Surface(surfAirInfDwn) = {newll-1 };

// Physical Regions

Physical Surface(CABLE1) = {surfCable1};
Physical Surface(CABLE2) = {surfCable2};

Physical Surface(SHELL) = {surfblin[]};
Physical Line(SURFSHELLIN) = {loopShield[3]};

Physical Surface(AIRUP)  = {surfAirUp};
Physical Surface(AIRDWN) = {surfAirDwn};
Physical Surface(AIRINFUP) = {surfAirInfUp};
Physical Surface(AIRINFDWN) = {surfAirInfDwn};

Physical Line(SURINFUP) = {loopRext[0],loopRext[1]};
Physical Line(SURINFDWN) = {loopRext[2],loopRext[3]};

Physical Line(CUTLEFT)  = {lInfL,lInL};
Physical Line(CUTRIGHT) = {lInR,lInfR};

