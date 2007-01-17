
//BEGIN PARAMS

//Include "dimensions_dat.pro";

// Dimensions lamination stack

//Include "freq3d.dat";

u = 1e-3;

nlam = 10 ;

d = 0.5*u ; //thickness of laminations
lambda = 0.9 ;//90%-98%

e = d*(1-lambda)/lambda ;//thickness isolation

W2 = 50*u/4 ; //Half thickness of stack
D2 = 1. * u ; //Half gap 

T = nlam*(d+e) ;

wind = 4*u ;

//W2 = T ;
//dd = W2*Sqrt(2)+2*d ;


dd = W2*1.5 ;//Radius inductor
dd2 = W2*1.2 ;//indxz

rind = dd;
rind2 = dd2;

xBox = dd*1.4 ;

Rint = xBox ;
Rext = xBox*1.2 ;

x0 = 0 ; y0 = 0 ; z0 = 0; 
z1 = (nlam-1)*(d+e)+d/2 ;

AXISY = 100;
AXISX = 101;
LIM_UP    = 102;
LIM_RIGHT = 103;

SKININD = 200;
IND = 500 ;
CUTIND = 400 ;
CUTINDAIR = 300;

ELEC0 = 600 ;
ELEC1 = 601 ;

LAMINATION = 1000;
ISOLATION  = 2000;

AIR = 3000;
AIRINF = 3001;

SURFACEGINF  = 4000;
SURFACEGE0 = 4001;//Side
SURFACEGH0 = 4002;//Symmetry 
SURFACEAIR = 4003;

SURFBACK = 4010;
SURFLEFT = 4011;
SURFFRONT = 4012;
SURFRIGHT = 4013;

SURFBACKI = 4020;
SURFLEFTI = 4021;
SURFFRONTI = 4022;
SURFRIGHTI = 4023;

SURFUP = 4030;
SURFDWN = 4031;

SKINLAM = 5000;

//END PARAMS

//-----------------------------------------------------------------

HOMO = 0 ;
GAP = 1 ;

// Some gmsh parameters

Geometry.OldNewReg = 0;
Geometry.AutoCoherence = 1;

//Mesh.Algorithm = 1 ;

TRANSIND = 1 ;

s = 1.5 ;

// L a m i n a t i o n s :
//------------------------------------------------------------------

lc     = s * W2/16;//W2/20;
lcind  = s * wind/5;
lcind2 = lcind ; 

lcbox    = lc*2;
lcboxi    = lcind ;
lcboxout = lc*2;

ndive = 1 ;

If(HOMO)
ndivlam = 2 ;
ndivlam_half = 1 ;
EndIf
If(!HOMO)
ndivlam = 8 ;
EndIf



//nind = 20;
nind = Ceil[Pi*dd/2/lcind]+1 ;

valProgression = 1. ;
valBump = 0.1 ;
//valBump = 1 ;

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


//---------------------------------------------------------------------

x0 = 0 ; y0 = 0 ; z0 = 0; 

p0 = newp ; Point(p0)={x0,y0,z0,lc};
p1 = newp ; Point(p1)={x0+W2,y0,z0,lc};

p2 = newp ; Point(p2)={x0+W2,y0+W2,z0,lc};
p3 = newp ; Point(p3)={x0,y0+W2,z0,lc};

l0 = newl ; Line(l0) = {p0,p1};  
l1 = newl ; Line(l1) = {p1,p2};  
l2 = newl ; Line(l2) = {p2,p3};  
l3 = newl ; Line(l3) = {p3,p0};  

surflam0 = news;
Line Loop (surflam0) = {l0,l1,l2,l3};
Plane Surface(surflam0) = {surflam0};

Transfinite Line{l0,l3} = Ceil[W2/lc]+1 Using Bump valBump ;
Transfinite Line{l1,l2} = Ceil[W2/lc]+1 Using Bump valBump ;
Transfinite Surface{surflam0} = {p0,p1,p2,p3};

vollam[]={}; voliso[]={};
lback[]={}; lleft[]={};lfront[]={};lright[]={};
lbacki[]={};llefti[]={};lfronti[]={};lrighti[]={};
lup[] = {};ldwn[] = {};
lupi[]={};

If(!HOMO)
bumpvector[] = {}; bumpvector1[] = {};
lvector[] = {}; lvector1[] = {};

alpha = 1.5 ; cte  = 0.;

For i In{0:ndivlam/2-1}
cte += alpha^i; 
EndFor

a = T/2/cte;

For i In {0:ndivlam/2-1}
lvector1[] += 1 ;
testv = a*alpha^i/(T/2)/2;
If(i>0)
  testv += bumpvector1[i-1];
EndIf
bumpvector1[] += testv   ;
EndFor

For i In {0:#bumpvector1[]-1}//Half lamination
bumpvector2[i] = 2*bumpvector1[i];
Printf("%g %g",lvector1[i],bumpvector2[i]);
EndFor

bumpvector[]={bumpvector1[]};//Complete lamination
For i In {0:ndivlam/2-1}
If(i<ndivlam/2-1)
bumpvector[ndivlam/2+i] = 
bumpvector[ndivlam/2+i-1]+ bumpvector[ndivlam/2-1-i]-bumpvector[ndivlam/2-2-i] ;
EndIf

If(i==ndivlam/2-1)
bumpvector[ndivlam/2+i] = 1;
EndIf
EndFor
lvector[] ={lvector1[],lvector1[]};

ldwn[]+= surflam0;//Watch Out: this is half a lamination
vol[]= Extrude Surface { surflam0, {0,0,d/2}} {Layers {ndivlam/2,1} ; };;
vollam[] += vol[1];
lup[] += news-1;
lfront[]  += news-5 ;
lright[]  += news-4 ;
lback[] += news-3 ;
lleft[] += news-2 ;

For i In {1:nlam-1}
vol[] = Extrude Surface {news-1, {0,0,e}} {Layers {{ndive},{1}} ; };;
voliso[]  += vol[1];
lupi[]    += news-1 ;
lfronti[] += news-5 ;
lrighti[] += news-4 ;
lbacki[]  += news-3 ;
llefti[]  += news-2 ;

ldwn[]+= news-1 ;
vol[] = Extrude Surface { news-1, {0,0,d}} {Layers {lvector[],bumpvector[]} ; };;
vollam[] += vol[1];
lup[]    += news-1 ;
lfront[] += news-5 ;
lright[] += news-4 ;
lback[]  += news-3 ;
lleft[]  += news-2 ;
EndFor

vol[]=Extrude Surface { news-1, {0,0,e/2}} {Layers {{ndive},{1}} ; };;
voliso[] += vol[1];
lupi[]    += news-1 ;
lfronti[]  += news-5 ;
lrighti[]  += news-4 ;
lbacki[] += news-3 ;
llefti[] += news-2 ;

borderRight[] = {};
borderLeft[] = {};

For i In{0:2*nlam-1}
borderRight[] += 11+i*16;
borderLeft[]  += 17+i*16;
EndFor
paxetop = 5 + 40*(2*nlam-1);
EndIf



If(HOMO)
ldwn[]+= surflam0;//Watch Out: this is half a lamination
vol[]= Extrude Surface { surflam0, {0,0,d/2+e}} {Layers {ndivlam_half,1} ; };;
vollam[] += vol[1];
lup[] += news-1;
lfront[]  += news-5 ;
lright[]  += news-4 ;
lback[] += news-3 ;
lleft[] += news-2 ;

lvector[] = {ndivlam};
bumpvector[] = {1};

For i In {1:nlam-2}
ldwn[]+= news-1 ;
vol[] = Extrude Surface { news-1, {0,0,d+e}} {Layers {lvector[],bumpvector[]} ; };;
vollam[] += vol[1];
lup[]    += news-1 ;
lfront[] += news-5 ;
lright[] += news-4 ;
lback[]  += news-3 ;
lleft[]  += news-2 ;
EndFor

ldwn[]+= news-1 ;
vol[]=Extrude Surface { news-1, {0,0,d+e/2}} {Layers {{lvector[]},{bumpvector[]}} ; };;
vollam[] += vol[1];
lup[]    += news-1 ;
lfront[] += news-5 ;
lright[] += news-4 ;
lback[]  += news-3 ;
lleft[]  += news-2 ;

borderRight[] = {};
borderLeft[] = {};

For i In{0:nlam-1}
borderRight[] += 11+i*16;
borderLeft[]  += 17+i*16;
EndFor
paxetop = 5 + 40*(nlam-1);

EndIf


// I N D U C T O R

pi1 = newp ; Point(pi1)= {x0+rind2,      y0,        z0, lcind};
pi2 = newp ; Point(pi2)= {x0+rind2+wind, y0,        z0, lcind};
pi3 = newp ; Point(pi3)= {x0+rind2+wind, y0+wind/2, z0, lcind2};
pi4 = newp ; Point(pi4)= {x0+rind2,      y0+wind/2, z0, lcind2};

li1 = newl ; Line(li1)= {pi1,pi2};
li2 = newl ; Line(li2)= {pi2,pi3};
li3 = newl ; Line(li3)= {pi3,pi4};
li4 = newl ; Line(li4)= {pi4,pi1};

lineloopind = newl;
Line Loop (lineloopind) = {li1,li2,li3,li4};
surfind = news;
Plane Surface(surfind) = {lineloopind};

If (TRANSIND)
Transfinite Line{li1,li3} = Ceil[wind/lcind] ;
Transfinite Line{li2,li4} = Ceil[wind/2/lcind] ;
Transfinite Surface{surfind} = {pi1,pi2,pi3,pi4};
vol[] = Extrude{{0,1,0},{0,0,0}, -Pi/2}{Surface{surfind}; Layers {{nind},{1}}; };
volind = vol[1];
EndIf

If (!TRANSIND)
vol[] = Extrude{{0,1,0},{0,0,0}, -Pi/2}{Surface{surfind}; };
volind = vol[1];
EndIf

Transfinite Line{li1,li3} = Ceil[wind/lcind] ;
Transfinite Line{li2,li4,li2+4,li4+4} = Ceil[wind/2/lcind]+1 ;

symind   = surfind + 2 ;
skinind1 = surfind + 3 ;
skinind2 = surfind + 4 ;
skinind3 = surfind + 5 ;
surfind_ = surfind + 6 ;

// Air
pb0 = newp ; Point(pb0)={Rint,y0,z0,lcboxi};
pb1 = newp ; Point(pb1)={0,y0,Rint,lcboxi};
pb2 = newp ; Point(pb2)={0,Rint,z0,lcbox};

// center p0
cs1 = newl; Circle(cs1)={pb0,p0,pb1};
cs2 = newl; Circle(cs2)={pb1,p0,pb2};
cs3 = newl; Circle(cs3)={pb0,p0,pb2};

lcutr1 = newl ; Line(lcutr1) = {p1,pi1};
lcutr2 = newl ; Line(lcutr2) = {pi2,pb0};
laxe0 = newl ;  Line(laxe0)  = {paxetop,pi1+4};
laxe1 = newl ;  Line(laxe1)  = {pi2+4,pb1};
lcutl = newl ;  Line(lcutl)  = {p3,pb2};

pb0_ = newp ; Point(pb0_)={Rext,y0,z0,lcboxout};
pb1_ = newp ; Point(pb1_)={0,y0,Rext,lcboxout};
pb2_ = newp ; Point(pb2_)={0,Rext,z0,lcboxout};

// center p0
cs1_ = newl; Circle(cs1_)={pb0_,p0,pb1_};
cs2_ = newl; Circle(cs2_)={pb1_,p0,pb2_};
cs3_ = newl; Circle(cs3_)={pb0_,p0,pb2_};

lairinf1 = newl ; Line(lairinf1) = {pb0,pb0_};
lairinf2 = newl ; Line(lairinf2) = {pb1,pb1_};
lairinf3 = newl ; Line(lairinf3) = {pb2,pb2_};

surfge0_1 = news ;
Line Loop(surfge0_1) = 
{lcutr1,-li4,-li3,-li2,lcutr2,cs3,-lcutl,-l2,-l1};
Plane Surface(surfge0_1) = {surfge0_1};

surfge0_inf1 = news ;
Line Loop(surfge0_inf1) = {lairinf1,cs3_,-lairinf3,-cs3};
Plane Surface(surfge0_inf1) = {surfge0_inf1};

surfge0_2 = news ;
Line Loop(surfge0_2) = 
{laxe0,-(li4+4),-(li3+4),-(li2+4),laxe1,cs2,-lcutl,
borderLeft[],(borderLeft[#borderLeft[]-1]-9)};
Plane Surface(surfge0_2) = {surfge0_2};

surfge0_inf2 = news ;
Line Loop(surfge0_inf2) = {lairinf3,-cs2_,-lairinf2,cs2};
Plane Surface(surfge0_inf2) = {surfge0_inf2};


surfgh0_1 = news ;
Line Loop(surfgh0_1) = 
{borderRight[],-(borderRight[#borderRight[]-1]-6),laxe0,-(li4+6),-lcutr1};
Plane Surface(surfgh0_1) = {surfgh0_1};

surfgh0_2 = news ;
Line Loop(surfgh0_2) = {lcutr2, cs1,-laxe1,-(li1+10)};
Plane Surface(surfgh0_2) = {surfgh0_2};

surfgh0_inf = news ;
Line Loop(surfgh0_inf) = {lairinf1,cs1_,-lairinf2,-cs1};
Plane Surface(surfgh0_inf) = {surfgh0_inf};

surfinf_in = news ;
Line Loop(surfinf_in) = {cs3,-cs2,-cs1};
Ruled Surface(surfinf_in) = {surfinf_in};

surfinf_out = news;
Line Loop(surfinf_out) = {cs1_,cs2_,-cs3_};
Ruled Surface(surfinf_out) = {surfinf_out};


If(!HOMO)
Surface Loop(newsl) = 
{skinind3,-surfge0_2,surfgh0_1,surfge0_1,
 lright[],lrighti[],lback[],lbacki[],lupi[#voliso[]-1],
-surfinf_in,surfgh0_2,skinind1,skinind2};
EndIf

If(HOMO)
Surface Loop(newsl) = 
{skinind3,-surfge0_2,surfgh0_1,surfge0_1,
 lright[],lback[],lup[#vollam[]-1],
-surfinf_in,surfgh0_2,skinind1,skinind2};
EndIf
volair = newv;
Volume(volair) = {newsl-1};

Surface Loop(newsl) = {surfge0_inf2,surfge0_inf1,-surfgh0_inf,surfinf_out,surfinf_in};
volairinf = newv;
Volume(volairinf) = {newsl-1};


//--------------------------------------------------------

If(!HOMO)
For i In {0:#vollam[]-1}
  Physical Volume (LAMINATION+i)= {vollam[i]};
  If(i==0)
    //Physical Surface(SKINLAM+i)= {lup[i],lfront[i],lright[i],lback[i],lleft[i]};
    Physical Surface(SKINLAM+i)= {lup[i],lright[i],lback[i]};
  EndIf
  If(i>0)
    //Physical Surface(SKINLAM+i)= {lup[i],ldwn[i],lfront[i],lright[i],lback[i],lleft[i]};
    Physical Surface(SKINLAM+i)= {lup[i],ldwn[i],lright[i],lback[i]};
  EndIf
EndFor
Physical Volume(ISOLATION)  = {voliso[]};

Physical Surface(SURFACEGE0) = 
{surfge0_1,surfge0_2,surfge0_inf1,surfge0_inf2, surflam0, lleft[],llefti[],surfind_,surfind};
Physical Surface(CUTIND) = {lfront[],lfronti[],surfgh0_1};
Physical Surface(SURFACEGH0) = {lfront[],lfronti[],symind,surfgh0_1,surfgh0_2,surfgh0_inf};
EndIf

If(HOMO)
  Physical Volume (LAMINATION) = {vollam[]};
  Physical Surface(SKINLAM)    = {lup[#vollam[]-1],lright[],lback[]};
  Physical Surface(SURFACEGE0) = 
{surfge0_1,surfge0_2,surfge0_inf1,surfge0_inf2,surflam0,lleft[],surfind_,surfind};
Physical Surface(CUTIND) = {lfront[],surfgh0_1};
Physical Surface(SURFACEGH0) = {lfront[],symind,surfgh0_1,surfgh0_2,surfgh0_inf};
EndIf

Physical Volume(AIR)  = {volair};
Physical Volume(AIRINF)  = {volairinf};

Physical Volume(IND) = {volind};
Physical Surface(SKININD) = {skinind1,skinind2,skinind3};
Physical Surface(ELEC0) = {surfind};
 
Physical Surface(SURFACEGINF) = {surfinf_out};


POST = 0;
If(POST)
db= 1e-4;

//perpendicular to the laminations
pp0 = newp ; Point(pp0)={W2/2,db, z0+1e-6,lc};
pp1 = newp ; Point(pp1)={W2/2,db, z1-1e-6,lc};
Line(newl)={pp0,pp1};

pp2 = newp ; Point(pp2)={W2-db,W2/2, z0+1e-6,lc};
pp3 = newp ; Point(pp3)={W2-db,W2/2, z1-1e-6,lc};
Line(newl)={pp2,pp3};

//paralel to the laminations
pp0_ = newp ; Point(pp0_)={W2-db, db   , 2*(d+e)+e/2,lc};
pp1_ = newp ; Point(pp1_)={W2-db, W2-db, 2*(d+e)+e/2,lc};
Line(newl)={pp0_,pp1_};

pp2_ = newp ; Point(pp2_)={db,    db, 2*(d+e)+e/2,lc};
pp3_ = newp ; Point(pp3_)={W2-db, db, 2*(d+e)+e/2,lc};
Line(newl)={pp2_,pp3_};

EndIf
