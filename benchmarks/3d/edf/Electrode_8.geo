// DESCRIPTION GENERALE D'UNE ELECTRODE
// ------------------------------------

Function Electrode

// Construction de la matrice de changement de repère

// Calcul de la norme du vecteur axe électrode

NormeK = Sqrt(Kx*Kx + Ky*Ky + Kz*Kz) ;

Kx = Kx / NormeK ;
Ky = Ky / NormeK ;
Kz = Kz / NormeK ; 

N = Sqrt( Kx*Kx + Ky*Ky);
 
If ( N == 0.)

  Ix = 1. ;
  Iy = 0. ;
  Iz = 0. ;

  Jx = 0. ;
  Jy = 1. ;
  Jz = 0. ;

EndIf

If ( N > 0.)

  Ix = - Ky / N ;
  Iy =   Kx / N ;
  Iz =   0. ;

  Jx = - Kx * Kz / N ;
  Jy = - Ky * Kz / N ;
  Jz =   N ;

EndIf


// CONSTRUCTION DE LA BOITE DE L'ELECTRODE
// ---------------------------------------

// Coordonnées des points de constructions de l'electrode dans son repère local
// cercle inférieur

X[0] = 0 ; Y[0] = 0 ; Z[0] = 0. ;
X[1] = R ; Y[1] = 0 ; Z[1] = 0. ;
X[2] = 0 ; Y[2] = R ; Z[2] = 0. ;
X[3] =-R ; Y[3] = 0 ; Z[3] = 0. ;
X[4] = 0 ; Y[4] =-R ; Z[4] = 0. ;

// Cercle supérieur

X[10] = 0 ; Y[10] = 0 ; Z[10] = L ;
X[11] = R ; Y[11] = 0 ; Z[11] = L ;
X[12] = 0 ; Y[12] = R ; Z[12] = L ;
X[13] =-R ; Y[13] = 0 ; Z[13] = L ;
X[14] = 0 ; Y[14] =-R ; Z[14] = L ;

// Coordonnées des points de constructions de l'electrode dans son repère global

For i In {0:4}

  x[i] = Ix*X[i] + Jx*Y[i] + Kx*Z[i] + xc;
  y[i] = Iy*X[i] + Jy*Y[i] + Ky*Z[i] + yc;
  z[i] = Iz*X[i] + Jz*Y[i] + Kz*Z[i] + zc;

EndFor

For i In {10:14}

  x[i] = Ix*X[i] + Jx*Y[i] + Kx*Z[i] + xc;
  y[i] = Iy*X[i] + Jy*Y[i] + Ky*Z[i] + yc;
  z[i] = Iz*X[i] + Jz*Y[i] + Kz*Z[i] + zc;

EndFor

// Définition des densité de discrétisation
 
kR = 1.;
kL = 0.99;

dpBoxSup = NbBoxSup +1;
dpBoxInf = NbBoxInf +1;

lcBoxSup =  R * Sin ( Pi/(2*NbBoxSup)) / Sin ( (Pi/2.)*(1-1/(2*NbBoxSup)) )  ;
lBoxSup  =  R * Sin ( Pi/(2*NbBoxSup)) / Sin ( (Pi/2.)*(1-1/(2*NbBoxSup)) )  ;

lcBoxInf = R * Sin (Pi/(2*NbBoxInf)) / Sin ( (Pi/2.)*(1-1/(2*NbBoxInf)) )  ;
lBoxInf  = R * Sin (Pi/(2*NbBoxInf)) / Sin ( (Pi/2.)*(1-1/(2*NbBoxInf)) )  ;

If ( lBoxSup >= (R/2.))
  lBoxSup = R/2. ;
// Printf ("Cas 1 : lBoxSup >= R/2 ");
EndIf

If ( lBoxInf >= (R/2.))
  lBoxInf = R/2. ;
// Printf ("Cas 2 : lBoxInf >= R/2 ");
EndIf   

If ( ( lBoxInf >= (L/2.) ) && (  lBoxSup >= (L/2.) ) )
  lcBoxInf = kR *L/2.;
  lcBoxSup = kR *L/2.;
  lBoxInf = kL *L/2.;
  lBoxSup = kL *L/2.;
// Printf ("Cas 3 : lBoxInf et lBoxSup >= L/2 ");
EndIf

// Constuction du cercle de base (centre de coordonnées xc,yc,zc)

p0 = newp; Point(p0) = {x[0], y[0],  z[0],  lcBoxInf} ;
p1 = newp; Point(p1) = {x[1], y[1],  z[1],  lBoxInf} ;
p2 = newp; Point(p2) = {x[2], y[2],  z[2],  lBoxInf} ;
p3 = newp; Point(p3) = {x[3], y[3],  z[3],  lBoxInf} ;
p4 = newp; Point(p4) = {x[4], y[4],  z[4],  lBoxInf} ;

c1 = newreg; Circle(c1) = {p1,p0,p2};
c2 = newreg; Circle(c2) = {p2,p0,p3};
c3 = newreg; Circle(c3) = {p3,p0,p4};
c4 = newreg; Circle(c4) = {p4,p0,p1};

// Constuction du cercle supérieur
 
p10 = newp; Point(p10) = {x[10], y[10],  z[10],  lcBoxSup} ;
p11 = newp; Point(p11) = {x[11], y[11],  z[11],  lBoxSup} ;
p12 = newp; Point(p12) = {x[12], y[12],  z[12],  lBoxSup} ;
p13 = newp; Point(p13) = {x[13], y[13],  z[13],  lBoxSup} ;
p14 = newp; Point(p14) = {x[14], y[14],  z[14],  lBoxSup} ;

c11 = newreg; Circle(c11) = {p11,p10,p12};
c12 = newreg; Circle(c12) = {p12,p10,p13};
c13 = newreg; Circle(c13) = {p13,p10,p14};
c14 = newreg; Circle(c14) = {p14,p10,p11};

// Construction des génératrices
 
l1 = newreg; Line(l1) = {p1,p11};
l2 = newreg; Line(l2) = {p2,p12};
l3 = newreg; Line(l3) = {p3,p13};
l4 = newreg; Line(l4) = {p4,p14};

// Constructions des contours

// cercle supérieur 

ll1 = newreg; Line Loop(ll1) = {c11,c12,c13,c14}; 

// Bords de la boite

ll2 = newreg; Line Loop(ll2) = {c1,l2,-c11,-l1};  
ll3 = newreg; Line Loop(ll3) = {c2,l3,-c12,-l2};  
ll4 = newreg; Line Loop(ll4) = {c3,l4,-c13,-l3};  
ll5 = newreg; Line Loop(ll5) = {c4,l1,-c14,-l4};  

// cercle inférieur

ll6 = newreg; Line Loop(ll6) = {c1,c2,c3,c4};  


// CONSTRUCTION DE L'ELECTRODE
// ---------------------------


// Coordonnées des points de constructions de l'electrode dans son repère local
// cercle inférieur

X[21] = r ; Y[21] = 0 ; Z[21] = 0. ;
X[22] = 0 ; Y[22] = r ; Z[22] = 0. ;
X[23] =-r ; Y[23] = 0 ; Z[23] = 0. ;
X[24] = 0 ; Y[24] =-r ; Z[24] = 0. ;

// Cercle supérieur

X[30] = 0 ; Y[30] = 0 ; Z[30] = l ;
X[31] = r ; Y[31] = 0 ; Z[31] = l ;
X[32] = 0 ; Y[32] = r ; Z[32] = l ;
X[33] =-r ; Y[33] = 0 ; Z[33] = l ;
X[34] = 0 ; Y[34] =-r ; Z[34] = l ;

// Coordonnées des points de constructions de l'electrode dans son repère global

For i In {21:24}

  x[i] = Ix*X[i] + Jx*Y[i] + Kx*Z[i] + xc;
  y[i] = Iy*X[i] + Jy*Y[i] + Ky*Z[i] + yc;
  z[i] = Iz*X[i] + Jz*Y[i] + Kz*Z[i] + zc;

EndFor

For i In {30:34}

  x[i] = Ix*X[i] + Jx*Y[i] + Kx*Z[i] + xc;
  y[i] = Iy*X[i] + Jy*Y[i] + Ky*Z[i] + yc;
  z[i] = Iz*X[i] + Jz*Y[i] + Kz*Z[i] + zc;

EndFor

// Définition des densités de discrétisation
 
kr = 1.;
kl = 1.;

dpESup = NbElSup +1;
dpEInf = NbElInf +1;

lcElecSup = kr * r * Sin ( Pi/(2*NbElSup)) / Sin ( (Pi/2.)*(1-1/(2*NbElSup)) )  ;
lElecSup  = kl * r * Sin ( Pi/(2*NbElSup)) / Sin ( (Pi/2.)*(1-1/(2*NbElSup)) )  ;

lcElecInf = kr * r * Sin ( Pi/(2*NbElInf)) / Sin ( (Pi/2.)*(1-1/(2*NbElInf)) )  ;
lElecInf  = kl * r * Sin ( Pi/(2*NbElInf)) / Sin ( (Pi/2.)*(1-1/(2*NbElInf)) )  ;

// Constuction du cercle de base (centre de coordonnées xc,yc,zc)

p21 = newp; Point(p21) = {x[21], y[21],  z[21],  lElecInf} ;
p22 = newp; Point(p22) = {x[22], y[22],  z[22],  lElecInf} ;
p23 = newp; Point(p23) = {x[23], y[23],  z[23],  lElecInf} ;
p24 = newp; Point(p24) = {x[24], y[24],  z[24],  lElecInf} ;

c21 = newreg; Circle(c21) = {p21,p0,p22};
c22 = newreg; Circle(c22) = {p22,p0,p23};
c23 = newreg; Circle(c23) = {p23,p0,p24};
c24 = newreg; Circle(c24) = {p24,p0,p21};

// Constuction du cercle supérieur
 
p30 = newp; Point(p30) = {x[30], y[30],  z[30],  lcElecSup} ;
p31 = newp; Point(p31) = {x[31], y[31],  z[31],  lElecSup} ;
p32 = newp; Point(p32) = {x[32], y[32],  z[32],  lElecSup} ;
p33 = newp; Point(p33) = {x[33], y[33],  z[33],  lElecSup} ;
p34 = newp; Point(p34) = {x[34], y[34],  z[34],  lElecSup} ;

c31 = newreg; Circle(c31) = {p31,p30,p32};
c32 = newreg; Circle(c32) = {p32,p30,p33};
c33 = newreg; Circle(c33) = {p33,p30,p34};
c34 = newreg; Circle(c34) = {p34,p30,p31};

// Construction des génératrices
 
l11 = newreg; Line(l11) = {p21,p31};
l12 = newreg; Line(l12) = {p22,p32};
l13 = newreg; Line(l13) = {p23,p33};
l14 = newreg; Line(l14) = {p24,p34};

// Constructions des contours

// cercle supérieur 

ll21 = newreg; Line Loop(ll21) = {c31,c32,c33,c34}; 

// Bords de l'electrode

ll22 = newreg; Line Loop(ll22) = {c21,l12,-c31,-l11};  
ll23 = newreg; Line Loop(ll23) = {c22,l13,-c32,-l12};  
ll24 = newreg; Line Loop(ll24) = {c23,l14,-c33,-l13};  
ll25 = newreg; Line Loop(ll25) = {c24,l11,-c34,-l14};  

// cercle inférieur

ll26 = newreg; Line Loop(ll26) = {c21,c22,c23,c24}; 
 

// CONSTRUCTION DES SURFACES DE ELECTRODE
// --------------------------------------

// Disque supérieur 

ps1 = newreg;  Plane Surface(ps1) = {ll21};

// Bords de l'electrode

rs1 = newreg; Ruled Surface(rs1) = {ll22};
rs2 = newreg; Ruled Surface(rs2) = {ll23};
rs3 = newreg; Ruled Surface(rs3) = {ll24};
rs4 = newreg; Ruled Surface(rs4) = {ll25};

BordElect[t-1] = newreg ;
Physical Surface(BordElect[t-1]) = { rs1, rs2, rs3, rs4, ps1};

// CONSTRUCTION DES SURFACES DE LA BOITE
// -------------------------------------

// Disque supérieur 

ps3 = newreg; Plane Surface(ps3) = {ll1};

// Bords de l'electrode

rs5 = newreg; Ruled Surface(rs5) = {ll2};
rs6 = newreg; Ruled Surface(rs6) = {ll3};
rs7 = newreg; Ruled Surface(rs7) = {ll4};
rs8 = newreg; Ruled Surface(rs8) = {ll5};

// Définition de la frontière électrode-boite

FrontElect[t-1] = newreg ;
Surface Loop (FrontElect[t-1])    = { ps3,  rs5,  rs6,  rs7,  rs8};
Physical Surface(FrontElect[t-1]) = { ps3,  rs5,  rs6,  rs7,  rs8};

// Anneau inférieur

ps4 = newreg; Plane Surface(ps4) = {ll6,ll26};

// Construction du volume de la boite

BoiteElect[t-1] = newreg ;
Surface Loop (BoiteElect[t-1]) = { ps4, rs5, rs6, rs7, rs8, ps3, rs1, rs2, rs3, rs4, ps1};
Volume(BoiteElect[t-1]) = BoiteElect[t-1];
Physical Volume(BoiteElect[t-1]) = BoiteElect[t-1];

// Définition du contour de la base de boîte d'electrode

ContBaseBoiteElect[t-1]= newreg ;
Line Loop (ContBaseBoiteElect[t-1]) = {c1,c2,c3,c4} ;

// DISCRETISATION DES ARETES
// -------------------------

// Discrétisation du contour circulaire de la boite (Nb de Noeuds / quart périmètre)

// Transfinite Line {c1,c2,c3,c4} = dpBoxInf;
// Transfinite Line {c11,c12,c13,c14} = dpBoxSup;
// Transfinite Line {l1,l2,l3,l4} = dpBoxGen;

// Discrétisation du contour circulaire de l'électrode (Nb de Noeuds / quart périmètre)

// Transfinite Line {c21,c22,c23,c24} = dpEInf;
// Transfinite Line {c31,c32,c33,c34} = dpESup;
// Transfinite Line {l11,l12,l13,l14} = dpEGen;

Return



