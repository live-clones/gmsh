Include "perforated_dat.pro";

Mesh.CharacteristicLengthFactor = 1. ;
Mesh.Algorithm3D = 4;

nbrHolesCir = Floor[Pi*x_ps/dhole];
bhole = (2*Pi*x_ps-nbrHolesCir*dhole)/nbrHolesCir;
Phi = (dhole+bhole)/x_ps;

//Phi = Pi/4;

//rfar  = ((x_ps > h_ps/2) ?  1.6 * x_ps : .7*h_ps) ;
//rfar2 = ((x_ps > h_ps/2) ?  1.9 * x_ps : .9*h_ps) ;






// Characteristic lengths
s = 1.; 

// Workpiece
lcwp = r/30*s ;

// transfinite
p_circ = Ceil[2*Pi*r/lcwp/20] ; //12 ; 
p_cut  = Ceil[r/lcwp/2] ; //20 ; 
nl     = Ceil[(h/2)/lcwp] + 1  ; //2 width divisions

// Passive shield
lc_hole = dhole/5*s ;

p_ps   = 10e-3*s ;

p_air  = rfar/15*s ;
p_air2 = rfar2/15*s ;

// Excitation coil
p_ec  = h_ec/4*s ;
p_wec = Ceil[w_ec/p_ec] ; //1 ;
p_hec = Ceil[h_ec/2/p_ec] ; //3 ;

// transfinite
delta = Sqrt[1/(mu0*1000*sigmaW*Pi)];//Freq = 1e3;
Printf("Skin depth workpiece = %g", delta);

nbrdelta = 8 ;
nsd = Ceil[nbrdelta*delta] ;
//nsd = 3*Ceil[w_ps/delta]; //3


//---------------------------------------------------------------------------------------
//------------------------W 0 R K P I E C E---------------------------------------------
//---------------------------------------------------------------------------------------

p0 = newp ; Point(p0) = { 0, 0, 0, lcwp};
p1 = newp ; Point(p1) = { r, 0, 0, lcwp};
p2 = p1+4;
p3 = p0+4;

l1 = newl ; Line(l1) = {p0,p1};

If(TRANS)
Transfinite Line {l1} = p_cut Using Progression 0.85 ;
EndIf

sur[] = Extrude {{0,0,1} , {0,0,0} , Phi } { 
  Line{l1}; Layers {p_circ,1} ; 
};
z0wp = sur[1]; 

vol[] = Extrude {0,0,h/2} { 
  Surface{z0wp}; Layers {nl,1} ; 
};

vWP[0] =vol[1];

topwp = vol[0];
phi0wp = vol[2]; 
sidewp = vol[3]; 
phi1wp = vol[4]; 

l2 = 11 ; l2_ = 15 ;
l3 = 6 ;  l3_ = 8  ;

//For n In {0:(#vol[]-1)} 
//Printf("n %g out of  %g", vol[n],#vol[]); EndFor


//---------------------------------------------------------------------------------------
// ------------------- EXCITATION COIL --------------------------------------------------
//---------------------------------------------------------------------------------------

pe[0] = newp ; Point(pe[0]) = { x_ec, 0, 0, p_ec};
pe[1] = newp ; Point(pe[1]) = { x_ec + w_ec, 0, 0, p_ec};
pe[2] = newp ; Point(pe[2]) = { x_ec + w_ec, 0, h_ec/2, p_ec};
pe[3] = newp ; Point(pe[3]) = { x_ec, 0, h_ec/2, p_ec};

le[0] = newl ; Line(le[0]) = {pe[0], pe[1]};
le[1] = newl ; Line(le[1]) = {pe[1], pe[2]};
le[2] = newl ; Line(le[2]) = {pe[2], pe[3]};
le[3] = newl ; Line(le[3]) = {pe[3], pe[0]};

lle = newl ; Line Loop(lle) = {le[]};
phi0ec = news ;Plane Surface(phi0ec) = {lle};

//Excitation Coil

If(TRANS)
Transfinite Line {le[0],le[2]}  = p_wec ;
Transfinite Line {le[1],le[3]}  = p_hec ;
Transfinite Surface{phi0ec} = {pe[]};
EndIf

nl_ec = 10 ;

For n In {0:0}
  vol[]=Extrude Surface { news-1, {0,0,1} , {0,0,0} , Phi } { Layers { nl_ec, 1 } ; };;
  vEC[n]=vol[1];
EndFor
  
phi1ec    = vol[0]; 
z0ec      = vol[2];
sideextec = vol[3]; 
topec     = vol[4];
sideinec  = vol[5]; 

le_[] = {29,30,31,32};

//For n In {0:(#vol[]-1)} 
//Printf("n %g out of  %g", vol[n],#vol[]); EndFor


//---------------------------------------------------------------------------------------
//-----------------------------Passive shield--------------------------------------------
//---------------------------------------------------------------------------------------

ps1 = newp ; Point(ps1) = { x_ps, 0., 0, p_ps};
ps2 = newp ; Point(ps2) = { x_ps, 0., h_ps/2, p_ps};
lps  = newl; Line(lps)  = {ps1,ps2};

sur[] = Extrude Line { lps, {0,0,1} , {0,0,0}, Phi };;
sPSin[0] = sur[1];
lps_ = sur[0]; 
loopin = newl ; Line Loop(loopin) = {lps,sur[2],-sur[0],sur[3]};

lpsin = sur[3];

N = 10;
x0 = 0 ;
x1 = x_ps + 2 * w_ps ;

loopshin[] = {};

For ih In {1:nbrHoles/2}
  auxlin[]={}; 
  auxpnt[]={};

  For i In {1:N}
    angh = i * 2 * Pi / N;
    cRoth = Cos(angh);
    sRoth = Sin(angh);
    auxpnt[] += newp;
    Point(newp) = { x0, rh*cRoth, h_ps/2-(2*ih-1/2)*dhole + rh*sRoth, lc_hole};
    auxpnt[] += newp;
    Point(newp) = { x1, rh*cRoth, h_ps/2-(2*ih-1/2)*dhole + rh*sRoth, lc_hole};
    auxlin[] += newl;
    Line(auxlin[i-1]) = {newp-2, newp-1};
    lin[]= Rotate {{0.,0.,1.},{0.,0.,0.},Phi/2} {Line{auxlin[i-1]}; };
    Hide { Point{newp-2:newp-1}; }
  EndFor

  ppin[]  = Intersect Line {auxlin[0]:auxlin[N-1]} Surface {sPSin[0]};

  hin[ih-1]  = newl ; Spline(hin[ih-1])  = {ppin[],   ppin[0]};

  Delete { Line{auxlin[0]:auxlin[N-1]}; Point{auxpnt[0]:auxpnt[2*N-1]}; }

  loopshin[]+= newl;
  Line Loop(loopshin[ih-1]) = {hin[ih-1]};
EndFor

Delete { Surface{sPSin[0]}; }
Ruled Surface(sPSin[0]) = {loopin, loopshin[]};


//Boundary layers
vol[] = Extrude {Surface{sPSin[0]}; Layers{3, -w_ps};};
vPS[0] = vol[1];

extPS  = vol[0];//top
phi0PS = vol[2];//side phi0
topPS  = vol[3];//side h=h_ps/2 
phi1PS = vol[4];//side phi1
z0PS   = vol[5];//side h=0

holes[] = {};
For ih In {1:nbrHoles/2}
  holes[] += vol[6+ih-1];
EndFor

bndextPS[]= Boundary{Surface{extPS};};

//For n In {0:(#bndextPS[]-1)} 
//Printf("n %g out of  %g", bndextPS[n],#bndextPS[]); EndFor


//---------------------------------------------------------------------------------------
//----------------------------------  A I R ---------------------------------------------
//---------------------------------------------------------------------------------------

pa0 = newp ; Point(pa0) = { rfar, 0, 0, p_air};
pa1 = newp ; Point(pa1) = { 0, 0, rfar, p_air};
pnt[]= Rotate {{0.,0.,1.},{0.,0.,0.},Phi} { Duplicata{Point{pa0};} };
pa3 = pnt[0];

lacir1 = newl ; Circle(lacir1) = {pa0,p0,pa1};
lacir2 = newl ; Circle(lacir2) = {pa0,p0,pa3};
lacir3 = newl ; Circle(lacir3) = {pa3,p0,pa1};

Line Loop(newl)={-lacir1,lacir2,lacir3};
surair= newl ; Ruled Surface(surair) = {newl-1};

pa0_ = newp ; Point(pa0_) = { rfar2, 0, 0, p_air2};
pa1_ = newp ; Point(pa1_) = { 0, 0, rfar2, p_air2};
pnt[]= Rotate {{0.,0.,1.},{0.,0.,0.},Phi} { Duplicata{Point{pa0_};} };
pa3_ = pnt[0];

lacir1_ = newl ; Circle(lacir1_) = {pa0_,p0,pa1_};
lacir2_ = newl ; Circle(lacir2_) = {pa0_,p0,pa3_};
lacir3_ = newl ; Circle(lacir3_) = {pa3_,p0,pa1_};

Line Loop(newl)={-lacir1_,lacir2_,lacir3_};
surairinf= newl ; Ruled Surface(surairinf) = {newl-1};

la1 = newl ; Line(la1) = {p1,pe[0]};
la2 = newl ; Line(la2) = {pe[1],ps1};

pbl0 = ps1 + 3*N*nbrHoles/2 + 12 ;
la3 = newl ; Line(la3) = {pbl0,pa0};
pbl1 = pbl0 + 10 ;
la3_ = newl ; Line(la3_) = {pbl1,pa3};

lblayer0 = -lpsin + 20 + (nbrHoles/2-1)*12 ;
lblayer1 = -lpsin + 20 + (nbrHoles/2-1)*12 - 3 ;
lblayer2 = -lpsin + 20 + (nbrHoles/2-1)*12 + 3 + nbrHoles/2;

lblayer1_ = lblayer1 + 2 ;
lblayer2_ = lblayer2 + 4 ;

la4 = newl ; Line(la4) = {p3,pa1};
la5 = newl ; Line(la5) = {pa0,pa0_};
la6 = newl ; Line(la6) = {pa1,pa1_};

sur[] = Extrude Line { la1, {0,0,1} , {0,0,0}, Phi };;
z0air0=sur[1];
la1_=sur[0];
sur[] = Extrude Line { la2, {0,0,1} , {0,0,0}, Phi };;
z0air1=sur[1];
la2_=sur[0];

Line Loop(newl)={lblayer0,la3,lacir2,-la3_ };
z0air2=news; Plane Surface(z0air2) = {newl-1};

sur[] = Extrude Line { la5, {0,0,1} , {0,0,0}, Phi };;
z0airinf=sur[1];
la5_=sur[0];

Line Loop(newl)={lacir1,la6,-lacir1_,-la5};
surairphi0inf = newl ; Plane Surface(surairphi0inf) = {newl-1};
Line Loop(newl) = {la5_,lacir3_,-la6,-lacir3};
surairphi1inf = newl ; Plane Surface(surairphi1inf) = {newl-1};

Surface Loop(news) = {surairinf,z0airinf,surairphi0inf,surair,surairphi1inf};
volairinf = newv ; Volume(volairinf) = {news-1};


Line Loop(newl) = {la4,-lacir1,-la3,lblayer1,-lblayer2,-lps,-la2,le[{1:3}],-la1,l2,-l3};
surairphi0=news ; Plane Surface(surairphi0) = {news-1};


Line Loop(newl) = {la4,-lacir3,-la3_,-lblayer1_,-lblayer2_,-lps_,-la2_,le_[{1:3}],-la1_,l2_,l3_};
surairphi1=news ; Plane Surface(surairphi1) = {news-1};


Surface Loop(news) = 
{z0air2,surairphi0,surairphi1,z0air1,z0air0,extPS,topPS,sPSin[0],
holes[],surair,sideextec,topec,sideinec,topwp,sidewp};
volair = newv ; Volume(volair) = {news-1};


Physical Volume(WORKPIECE)={vWP[]};
Physical Surface(SKINWORKPIECE)={sidewp,topwp};
Physical Surface(Z0WORKPIECE)={z0wp};
Physical Surface(PHI0WORKPIECE)={phi0wp};
Physical Surface(PHI1WORKPIECE)={phi1wp};

Physical Volume(PASSIVESHIELD)={vPS[]};
Physical Surface(SKINPASSIVESHIELD)={sPSin[0],topPS,extPS,holes[]};
Physical Surface(SKINPASSIVESHIELD2)={sPSin[0]};
Physical Surface(Z0PASSIVESHIELD)={z0PS};
Physical Surface(PHI0PASSIVESHIELD)={phi0PS};
Physical Surface(PHI1PASSIVESHIELD)={phi1PS};
Physical Surface(CUTPASSIVESHIELD)={z0air1,z0ec,z0air0,z0wp};
Physical Surface(SKINPASSIVESHIELDINT)={sPSin[0]};
Physical Surface(SKINPASSIVESHIELDEXT)={extPS};


Physical Line(LINPHI0SHELLINT) = {lps};
Physical Line(LINPHI1SHELLINT) = {lps_};

Physical Line(LINZ0SHELLINT) = {lpsin};


Physical Volume(EC)={vEC[]};
Physical Surface(SKINEC)={sideinec,topec,sideextec};
Physical Surface(SKINEC2)={sideinec};
Physical Surface(Z0EC)={z0ec};
Physical Surface(PHI0EC)={phi0ec};
Physical Surface(PHI1EC)={phi1ec};
Physical Surface(CUTEC)={z0wp,z0air0};

Physical Volume(AIR)   ={volair};
Physical Surface(SURAIR)   ={surair};
Physical Surface(Z0AIR0) = {z0air0};
Physical Surface(Z0AIR1) = {z0air1};
Physical Surface(Z0AIR2) = {z0air2};
Physical Surface(PHI0AIR) = {surairphi0};
Physical Surface(PHI1AIR) = {surairphi1};

Physical Volume(AIRINF)={volairinf};
Physical Surface(SURAIRINF) = {surairinf};
Physical Surface(Z0AIRINF) = {z0airinf};
Physical Surface(PHI0AIRINF) = {surairphi0inf};
Physical Surface(PHI1AIRINF) = {surairphi1inf};



