// Ce fichier est la description geometrique utilisee par GMSH pour 
// generer le fichier "four.msh".
//
// Copyright (C) 2003 Ali ABAKAR <abakar@edf.fr>
//
// - Modified on Wed Feb 19 13:48:25 2003 by Christophe Geuzaine

// DESCRIPTION DU FOUR
// -------------------

// Dimensions du Four (hauteur, Longueur, largeur en mètre)

HauteurFour = 1.4 ; LongueurFour = 14.;  LargeurFour = 8.8 ;
ProfondeurMarche = 1. ; LongueurMarche = 2. ;

// Paramètres maillage

Include "Param_test.geo";

// Description géomètrique du four

// Création des points
 
pf1 = newp; Point(pf1) = { LongueurFour,                LargeurFour/2., -ProfondeurMarche, lfour};
pf2 = newp; Point(pf2) = { LongueurFour-LongueurMarche, LargeurFour/2., -ProfondeurMarche, lfour};
pf3 = newp; Point(pf3) = { LongueurFour-LongueurMarche, LargeurFour/2.,                0., lfour};
pf4 = newp; Point(pf4) = {           0.,                LargeurFour/2.,                0., lfour};

pf5 = newp; Point(pf5) = { LongueurFour,                -LargeurFour/2., -ProfondeurMarche, lfour};
pf6 = newp; Point(pf6) = { LongueurFour-LongueurMarche, -LargeurFour/2., -ProfondeurMarche, lfour};
pf7 = newp; Point(pf7) = { LongueurFour-LongueurMarche, -LargeurFour/2.,                0., lfour};
pf8 = newp; Point(pf8) = {           0.,                -LargeurFour/2.,                0., lfour};

pf9  = newp; Point(pf9) = { LongueurFour, LargeurFour/2., HauteurFour, lfour};
pf10 = newp; Point(pf10) = {           0., LargeurFour/2., HauteurFour, lfour};
pf11 = newp; Point(pf11) = {           0.,-LargeurFour/2., HauteurFour, lfour};
pf12 = newp; Point(pf12) = { LongueurFour,-LargeurFour/2., HauteurFour, lfour};

// Construction des arêtes du four

// Arêtes horizontales du fond de la marche

lf1 = newreg; Line(lf1) = {pf1,pf2};
lf2 = newreg; Line(lf2) = {pf2,pf6};
lf3 = newreg; Line(lf3) = {pf6,pf5};
lf4 = newreg; Line(lf4) = {pf5,pf1};

// Arêtes horizontales du fond du four (partie supérieure)

lf5 = newreg; Line(lf5) = {pf3,pf4};
lf6 = newreg; Line(lf6) = {pf4,pf8};
lf7 = newreg; Line(lf7) = {pf8,pf7};
lf8 = newreg; Line(lf8) = {pf7,pf3};

// Arêtes horizontales dessus du four

lf9  = newreg; Line(lf9)  = {pf9 ,pf10};
lf10 = newreg; Line(lf10) = {pf10,pf11};
lf11 = newreg; Line(lf11) = {pf11,pf12};
lf12 = newreg; Line(lf12) = {pf12,pf9 };

// Arêtes verticales du four

lf13 = newreg; Line(lf13)  = {pf1 ,pf9};
lf14 = newreg; Line(lf14)  = {pf2 ,pf3};
lf15 = newreg; Line(lf15) = {pf4 ,pf10};
lf16 = newreg; Line(lf16) = {pf8 ,pf11};
lf17 = newreg; Line(lf17) = {pf6, pf7 };
lf18 = newreg; Line(lf18) = {pf5, pf12};

// Définition des contour(s) du dessus du four

DessusFour[0] = newreg; Line Loop(DessusFour[0]) = {lf9,lf10,lf11,lf12}; 

// Définitions des contours des bords du four

// Bord en y = LargeurFour/2.

BordFour[0] = newreg; Line Loop(BordFour[0]) = {lf1,lf14,lf5,lf15,-lf9, -lf13}; 

// Bord en x = 0.

BordFour[1] = newreg; Line Loop(BordFour[1]) = {lf6,lf16,-lf10,-lf15};

// Bord en y = - LargeurFour/2.

BordFour[2] = newreg; Line Loop(BordFour[2]) = {lf7,-lf17,lf3,lf18,-lf11,-lf16};

// Bord en x = LongueurFour

BordFour[3] = newreg; Line Loop(BordFour[3]) = {lf4, lf13,-lf12,-lf18}; 

// Définitions des contour(s) du fond du Four

FondFour[0] = newreg;  Line Loop(FondFour[0]) = {lf1,lf2,lf3,lf4};
FondFour[1] = newreg;  Line Loop(FondFour[1]) = {lf5,lf6,lf7,lf8};
FondFour[2] = newreg;  Line Loop(FondFour[2]) = {-lf8,lf14,-lf2,-lf17};

// Discrétisation des arêtes du four (Nb éléments / arête )

dLF = NbElLongF + 1;
dlF = NbElLargF + 1;
dhF = NbElHautF + 1;

Transfinite Line {lf5,lf7,lf9,lf11} = dLF;
Transfinite Line {lf4,lf6,lf8,lf10,lf12} = dlF;
Transfinite Line {lf2,lf8} = 2*dlF;
Transfinite Line {lf1,lf3,lf14,lf17,lf15,lf16} = dhF;
Transfinite Line {lf13,lf18} = 2*dhF;

// CONSTRUCTION DES ELECTRODES
// ---------------------------

Include "Electrode_8.geo" ;

// 1ère barrière d'électrodes
// --------------------------

// Rayon et Hauteur Electrode

r = 0.076/2.; l = 0.35; 

// Vecteur axe electrode

Kx = 0 ; Ky = 0. ; Kz = 1. ;
xc = 1.5 ;
L = 0.8 ;

// ELECTRODE I

t = 1;
R = 1. ;
yc = 0 ; zc = 0 ;

Call Electrode;

// ELECTRODE II

t = t + 1 ;
R = 0.5 ;
L = 0.8 ;
yc = 3.5 ; zc = 0 ; 

Call Electrode;

// ELECTRODE III

t = t+1;
yc = -3.5 ; zc = 0 ;
Call Electrode;

// 2ème barrière d'électrodes
// --------------------------

xc = xc + 2.5 ;

// ELECTRODE I

t = t+1;
R = 1. ;
yc = 0 ; zc = 0 ;

Call Electrode;

// ELECTRODE II

t = t + 1 ;
R = 0.5 ;
L = 0.8 ;
yc = 3.5 ; zc = 0 ; 

Call Electrode;

// ELECTRODE III

t = t+1;
yc = -3.5 ; zc = 0 ;

Call Electrode;

// 3ème barrière d'électrodes
// --------------------------

// ELECTRODE I

xc = xc + 2.25 ;
t = t+1;
R = 1. ;
yc = 0 ; zc = 0 ;

Call Electrode;

// ELECTRODE II

t = t + 1 ;
R = 0.5 ;
L = 0.8 ;
yc = 3.5 ; zc = 0 ; 

Call Electrode;

// ELECTRODE III

t = t+1;
yc = -3.5 ; zc = 0 ;

Call Electrode;

// 4ème barrière d'électrodes
// --------------------------

xc = xc + 2.5 ;

// ELECTRODE I

t = t+1;
R = 1. ; 
yc = 0 ; zc = 0 ;

Call Electrode;

// ELECTRODE II

t = t + 1 ;
R = 0.5 ;
L = 0.8 ;
yc = 3.5 ; zc = 0 ; 

Call Electrode;

// ELECTRODE III

t = t+1;
yc = -3.5 ; zc = 0 ;

Call Electrode;

// 5ième barrière d'électrodes
// ---------------------------

xc = xc + 2.25 ;
R = 0.4 ; L = 0.8 ;
// Rayon et Hauteur Electrode
r = 0.05/2.; l = 0.35;

// ELECTRODE I

t = t+1;
yc = 0 ; zc = 0 ;

Call Electrode;

// ELECTRODE II

t = t + 1 ;
yc = 0.9 ; zc = 0 ; 

Call Electrode;

// ELECTRODE III

t = t+1;
yc = yc + 0.9 ; zc = 0 ;

Call Electrode;

// ELECTRODE IV

t = t+1;
yc = yc + 0.9 ; zc = 0 ;

Call Electrode;

// ELECTRODE V

t = t+1;
yc = yc + 0.9 ; zc = 0 ;

Call Electrode;

// ELECTRODE VI

t = t+1;
yc = -0.9 ; zc = 0 ;

Call Electrode;

// ELECTRODE VII

t = t+1;
yc = yc -0.9 ; zc = 0 ;

Call Electrode;

// ELECTRODE VIII

t = t+1;
yc = yc -0.9 ; zc = 0 ;

Call Electrode;

// ELECTRODE IX

t = t+1;
yc = yc -0.9 ; zc = 0 ;

Call Electrode;


// CONSTRUCTION DES FACES DE LA GEOMETRIE COMPLETE
// -----------------------------------------------

// Surface du Fond du Four - trace(s) Electrode(s)

Plane Surface(FondFour[0]) = { FondFour[0]};
Plane Surface(FondFour[1]) = { FondFour[1],ContBaseBoiteElect[]};
Plane Surface(FondFour[2]) = { FondFour[2]}; 

// Surface dessus du Four - trace(s) Electrode(s)

Plane Surface(DessusFour[0]) = {DessusFour[0]};

// Surface Bords du Four - trace(s) Electrode(s)

Plane Surface(BordFour[0]) = { BordFour[0]};
Plane Surface(BordFour[1]) = { BordFour[1]};
Plane Surface(BordFour[2]) = { BordFour[2]};
Plane Surface(BordFour[3]) = { BordFour[3]};

// CONSTRUCTION DES VOLUMES DE LA GEOMETRIE COMPLETE
// -------------------------------------------------

FrontExtFour = newreg;
Surface Loop(FrontExtFour) = {FondFour[],DessusFour[],BordFour[]}; 

Verre = newreg ;
Volume(Verre) = {FrontExtFour,FrontElect[]};
Physical Volume(Verre) = {Verre};

// SUMMARY OF PHYSICAL ENTITIES
// ----------------------------

Printf("Physical Volume(Verre): %g ", Verre) ;

For i In {1: t}
  Printf("Physical Volume(Boite %g): %g", i, BoiteElect[i-1]) ;
EndFor

For i In {1: t}
  Printf("Physical Surface(Electrode %g): %g", i, BordElect[i-1]) ;
EndFor

For i In {1: t}
  Printf("Physical Surface(Boite %g): %g", i, FrontElect[i-1]) ;
EndFor
