//////////////////////////////////
//				//
//	 COEUR TYPE PHX		//
//				//
//////////////////////////////////


i_mesh = 1;             // ( 1 : maillage sortie coeur + collecteur chaud - 0 : maillage sortie coeur uniquement) 


//////////////////////////////// 
// Caracteristiques geometriques
////////////////////////////////

ep_ass   = 120.;    	// entreplat des assemblages
pas_ass  = 130.;    	// pas des assemblages
diam_pnl = 120; 	// diametre ou entreplat des P.N.L.

R_ass     = 2.1;     	// ass. fissiles+fertiles : compris entre (nb_couronnes) et (nb_couronnes+1)
R_ref     = 0.;     	// ass. reflecteurs acier : compris entre (nb_couronnes) et (nb_couronnes+1)
R_pnl	  = 0.;     	// P.N.L (rondins)	  : compris entre (nb_couronnes) et (nb_couronnes+1)

// valeurs prises dans le cas de COEUR_SEUL
///////////////////////////////////////////
//R_ass     = 2.1;     	// ass. fissiles+fertiles : compris entre (nb_couronnes) et (nb_couronnes+1)
//R_ref     = 3.;     	// ass. reflecteurs acier : compris entre (nb_couronnes) et (nb_couronnes+1)
//R_pnl	  = 3.5;     	// P.N.L (rondins)	  : compris entre (nb_couronnes) et (nb_couronnes+1)

itype_PNL = 0;		// geometrie des P.N.L : 0 : hexagonale - 1 : Circulaire - 2 : Octogonale

r1   =   700.;     	// rayon de la virole partie inferieure
r2   =  1200.;     	// rayon de la virole partie superieure
r3   =   300.;		// rayon du bcc
r4   =   950.;		// rayon pour l'emplacement des pompes et des echangeurs
r5   =   200.;		// rayon des pompes et des echangeurs

h1   = 3500.; 		// hauteur du coeur
h1b  =  500.; 		// distance sortie coeur - "epaulement"
h2   =  500.; 		// distance "epaulement" - haut du collecteur chaud
h3   =  100.;		// distance sortie coeur - bcc
h4   =  100.;		// hauteur entree fluide echangeur


/////////////////////////////// 
// paramètres de discrétisation
///////////////////////////////
 
lcar  = 0.9*ep_ass;	// longeur caracteristique associee aux assemblages - reflecteurs - P.N.L.
lcar2 = 2.*lcar;	// longeur caracteristique associee a la partie inferieure de la virole du Collecteur Chaud (en-dessous de l'epaulement)
//lcar2 = 7.*lcar;	// longeur caracteristique associee a la partie inferieure de la virole du Collecteur Chaud (en-dessous de l'epaulement)
lcar3 = 10.*lcar;	// longeur caracteristique associee a la partie superieure de la virole du Collecteur Chaud (au-dessus de l'epaulement)

Mesh.Algorithm    = 6;  // 2D mesh algorithm (1=MeshAdapt+Delaunay, 4=MeshAdapt, 5=Delaunay, 6=Frontal)
Mesh.Algorithm3D  = 4;  // 3D mesh algorithm (1=Tetgen+Delaunay, 4=Netgen)
Mesh.OptimizeNetgen = 1;


//**********************************************************
//**********************************************************

x0=0.;
y0=0.;
rac3= 1.732050807568877294;
rac2= 1.414213562373095049;
nassemblage=-1;
nreflecteur=-1;
npnl=-1;
indice=-1;
indice2=-1;
indice3=-1;
indice4=-1;

kle = 0 ;// Cle discretisation
If(R_ass>0.) kle = kle+1 ; EndIf
If(R_ref>0.) kle = kle+2 ; EndIf
If(R_pnl>0.) kle = kle+4 ; EndIf


/////////////////////
Function assemblage
/////////////////////

p1=newp; Point(p1) = { xc+ep_ass/rac3      , yc          , 0., lcar } ;
p2=newp; Point(p2) = { xc+ep_ass/(2.*rac3) , yc+ep_ass/2., 0., lcar } ;
p3=newp; Point(p3) = { xc-ep_ass/(2.*rac3) , yc+ep_ass/2., 0., lcar } ;
p4=newp; Point(p4) = { xc-ep_ass/rac3      , yc          , 0., lcar } ;
p5=newp; Point(p5) = { xc-ep_ass/(2.*rac3) , yc-ep_ass/2., 0., lcar } ;
p6=newp; Point(p6) = { xc+ep_ass/(2.*rac3) , yc-ep_ass/2., 0., lcar } ;

indice++; c[indice]=newreg; Line(c[indice]) = { p1, p2 } ;
indice++; c[indice]=newreg; Line(c[indice]) = { p2, p3 } ;
indice++; c[indice]=newreg; Line(c[indice]) = { p3, p4 } ;
indice++; c[indice]=newreg; Line(c[indice]) = { p4, p5 } ;
indice++; c[indice]=newreg; Line(c[indice]) = { p5, p6 } ;
indice++; c[indice]=newreg; Line(c[indice]) = { p6, p1 } ;

nassemblage++; lbord[nassemblage]=newreg; 
Line Loop(lbord[nassemblage]) = { c[{ indice-5:indice }] } ;
ass[nassemblage]=newreg; Plane Surface(ass[nassemblage]) = { lbord[nassemblage] } ;


Return

/////////////////////
Function reflecteur
/////////////////////

p1=newp; Point(p1) = { xc+ep_ass/rac3      , yc          , 0., lcar } ;
p2=newp; Point(p2) = { xc+ep_ass/(2.*rac3) , yc+ep_ass/2., 0., lcar } ;
p3=newp; Point(p3) = { xc-ep_ass/(2.*rac3) , yc+ep_ass/2., 0., lcar } ;
p4=newp; Point(p4) = { xc-ep_ass/rac3      , yc          , 0., lcar } ;
p5=newp; Point(p5) = { xc-ep_ass/(2.*rac3) , yc-ep_ass/2., 0., lcar } ;
p6=newp; Point(p6) = { xc+ep_ass/(2.*rac3) , yc-ep_ass/2., 0., lcar } ;

indice2++; c2[indice2]=newreg; Line(c2[indice2]) = { p1, p2 } ;
indice2++; c2[indice2]=newreg; Line(c2[indice2]) = { p2, p3 } ;
indice2++; c2[indice2]=newreg; Line(c2[indice2]) = { p3, p4 } ;
indice2++; c2[indice2]=newreg; Line(c2[indice2]) = { p4, p5 } ;
indice2++; c2[indice2]=newreg; Line(c2[indice2]) = { p5, p6 } ;
indice2++; c2[indice2]=newreg; Line(c2[indice2]) = { p6, p1 } ;

nreflecteur++; lbord2[nreflecteur]=newreg; 
Line Loop(lbord2[nreflecteur]) = { c2[{ indice2-5:indice2 }] } ;
refl[nreflecteur]=newreg; Plane Surface(refl[nreflecteur]) = { lbord2[nreflecteur] } ;


Return

/////////////////////
Function pnl
/////////////////////


//*********
// Hexagone
//*********

If(itype_PNL==0)

lcar_pnl = lcar;

p1=newp; Point(p1) = { xc+diam_pnl/rac3      , yc            , 0., lcar_pnl } ;
p2=newp; Point(p2) = { xc+diam_pnl/(2.*rac3) , yc+diam_pnl/2., 0., lcar_pnl } ;
p3=newp; Point(p3) = { xc-diam_pnl/(2.*rac3) , yc+diam_pnl/2., 0., lcar_pnl } ;
p4=newp; Point(p4) = { xc-diam_pnl/rac3      , yc            , 0., lcar_pnl } ;
p5=newp; Point(p5) = { xc-diam_pnl/(2.*rac3) , yc-diam_pnl/2., 0., lcar_pnl } ;
p6=newp; Point(p6) = { xc+diam_pnl/(2.*rac3) , yc-diam_pnl/2., 0., lcar_pnl } ;

indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p1, p2 } ;
indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p2, p3 } ;
indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p3, p4 } ;
indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p4, p5 } ;
indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p5, p6 } ;
indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p6, p1 } ;

npnl++; lbord3[npnl]=newreg; 
Line Loop(lbord3[npnl]) = { c4[{ indice4-5:indice4 }] } ;
pnl[npnl]=newreg; Plane Surface(pnl[npnl]) = { lbord3[npnl] } ;

EndIf


//*******
// Cercle
//*******

If(itype_PNL==1)

lcar_pnl = 0.5*diam_pnl;

centre_pnl=newp; Point(centre_pnl) = { xc, yc, 0., lcar_pnl } ;
//p_point = newreg ; Physical Point(p_point) = { centre_pnl } ;

p1=newp; Point(p1) = { xc+diam_pnl/2.	, yc,		  0.,	 lcar_pnl } ;
p2=newp; Point(p2) = { xc		, yc+diam_pnl/2., 0.,	 lcar_pnl } ;
p3=newp; Point(p3) = { xc-diam_pnl/2.	, yc,		  0.,	 lcar_pnl } ;
p4=newp; Point(p4) = { xc		, yc-diam_pnl/2., 0.,	 lcar_pnl } ;

indice4++; c4[indice4]=newreg; Circle(c4[indice4]) = { p1, centre_pnl, p2 } ;
indice4++; c4[indice4]=newreg; Circle(c4[indice4]) = { p2, centre_pnl, p3 } ;
indice4++; c4[indice4]=newreg; Circle(c4[indice4]) = { p3, centre_pnl, p4 } ;
indice4++; c4[indice4]=newreg; Circle(c4[indice4]) = { p4, centre_pnl, p1 } ;

npnl++; lbord3[npnl]=newreg; 
Line Loop(lbord3[npnl]) = { c4[{ indice4-3:indice4 }] } ;
pnl[npnl]=newreg; Plane Surface(pnl[npnl]) = { lbord3[npnl] } ;

EndIf


//*********
// Octogone
//*********

If(itype_PNL==2)

lcar_pnl = 0.5*diam_pnl;

p1=newp; Point(p1) = { xc+diam_pnl/2.	     , yc,		  	0.,  lcar_pnl } ;
p2=newp; Point(p2) = { xc+diam_pnl/(2.*rac2) , yc+diam_pnl/(2.*rac2),   0.,  lcar_pnl } ;
p3=newp; Point(p3) = { xc		     , yc+diam_pnl/2.,		0.,  lcar_pnl } ;
p4=newp; Point(p4) = { xc-diam_pnl/(2.*rac2) , yc+diam_pnl/(2.*rac2),   0.,  lcar_pnl } ;
p5=newp; Point(p5) = { xc-diam_pnl/2.	     , yc,		  	0.,  lcar_pnl } ;
p6=newp; Point(p6) = { xc-diam_pnl/(2.*rac2) , yc-diam_pnl/(2.*rac2),   0.,  lcar_pnl } ;
p7=newp; Point(p7) = { xc		     , yc-diam_pnl/2.,		0.,  lcar_pnl } ;
p8=newp; Point(p8) = { xc+diam_pnl/(2.*rac2) , yc-diam_pnl/(2.*rac2),   0.,  lcar_pnl } ;


indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p1, p2 } ;
indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p2, p3 } ;
indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p3, p4 } ;
indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p4, p5 } ;
indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p5, p6 } ;
indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p6, p7 } ;
indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p7, p8 } ;
indice4++; c4[indice4]=newreg; Line(c4[indice4]) = { p8, p1 } ;


npnl++; lbord3[npnl]=newreg; 
Line Loop(lbord3[npnl]) = { c4[{ indice4-7:indice4 }] } ;
pnl[npnl]=newreg; Plane Surface(pnl[npnl]) = { lbord3[npnl] } ;

EndIf

Return

////////////////////////
Function pompe_echangeur
////////////////////////

indice3++;

centre4=newp; Point(centre4) = { xc, yc, h1b, lcar3 } ;

p61=newp; Point(p61) = { xc+r5  , yc    , h1b, lcar3 } ;
p62=newp; Point(p62) = { xc     , yc+r5 , h1b, lcar3 } ;
p63=newp; Point(p63) = { xc-r5  , yc    , h1b, lcar3 } ;
p64=newp; Point(p64) = { xc     , yc-r5 , h1b, lcar3 } ;

c61=newreg; Circle(c61) = { p61, centre4, p62 } ;
c62=newreg; Circle(c62) = { p62, centre4, p63 } ;
c63=newreg; Circle(c63) = { p63, centre4, p64 } ;
c64=newreg; Circle(c64) = { p64, centre4, p61 } ;

pompeb[indice3]=newreg; Line Loop(pompeb[indice3]) = { c61 , c62 , c63 , c64  } ;
surf5[indice3] =newreg; Plane Surface(surf5[indice3])  = { pompeb[indice3] } ;

centre5=newp; Point(centre5) = { xc, yc, h1b+h4, lcar3 } ;

p71=newp; Point(p71) = { xc+r5  , yc    , h1b+h4, lcar3 } ;
p72=newp; Point(p72) = { xc     , yc+r5 , h1b+h4, lcar3 } ;
p73=newp; Point(p73) = { xc-r5  , yc    , h1b+h4, lcar3 } ;
p74=newp; Point(p74) = { xc     , yc-r5 , h1b+h4, lcar3 } ;

c71=newreg; Circle(c71) = { p71, centre5, p72 } ;
c72=newreg; Circle(c72) = { p72, centre5, p73 } ;
c73=newreg; Circle(c73) = { p73, centre5, p74 } ;
c74=newreg; Circle(c74) = { p74, centre5, p71 } ;

l9 = newreg; Line(l9)   = { p61 , p71 } ;
l10 = newreg; Line(l10) = { p62 , p72 } ;
l11 = newreg; Line(l11) = { p63 , p73 } ;
l12 = newreg; Line(l12) = { p64 , p74 } ;

surf_lat9 = newreg; Line Loop(surf_lat9)   = { l9 , c71 , -l10 , -c61 } ; sl9[indice3]  = newreg; Ruled Surface(sl9[indice3])  = { surf_lat9  } ;
surf_lat10 = newreg; Line Loop(surf_lat10) = { l10, c72 , -l11 , -c62 } ; sl10[indice3] = newreg; Ruled Surface(sl10[indice3]) = { surf_lat10 } ;
surf_lat11 = newreg; Line Loop(surf_lat11) = { l11, c73 , -l12 , -c63 } ; sl11[indice3] = newreg; Ruled Surface(sl11[indice3]) = { surf_lat11 } ;
surf_lat12 = newreg; Line Loop(surf_lat12) = { l12, c74 , -l9  , -c64 } ; sl12[indice3] = newreg; Ruled Surface(sl12[indice3]) = { surf_lat12 } ;

centre6=newp; Point(centre6) = { xc, yc, h1b+h2, lcar3 } ;

p81=newp; Point(p81) = { xc+r5  , yc    , h1b+h2, lcar3 } ;
p82=newp; Point(p82) = { xc     , yc+r5 , h1b+h2, lcar3 } ;
p83=newp; Point(p83) = { xc-r5  , yc    , h1b+h2, lcar3 } ;
p84=newp; Point(p84) = { xc     , yc-r5 , h1b+h2, lcar3 } ;

c81=newreg; Circle(c81) = { p81, centre6, p82 } ;
c82=newreg; Circle(c82) = { p82, centre6, p83 } ;
c83=newreg; Circle(c83) = { p83, centre6, p84 } ;
c84=newreg; Circle(c84) = { p84, centre6, p81 } ;

pompeh[indice3]=newreg; Line Loop(pompeh[indice3]) = { c81 , c82 , c83 , c84  } ;
surf6[indice3] =newreg; Plane Surface(surf6[indice3])  = { pompeh[indice3] } ;

l13 = newreg; Line(l13) = { p71 , p81 } ;
l14 = newreg; Line(l14) = { p72 , p82 } ;
l15 = newreg; Line(l15) = { p73 , p83 } ;
l16 = newreg; Line(l16) = { p74 , p84 } ;

surf_lat13 = newreg; Line Loop(surf_lat13) = { l13, c81 , -l14 , -c71 } ; sl13[indice3] = newreg; Ruled Surface(sl13[indice3]) = { surf_lat13 } ;
surf_lat14 = newreg; Line Loop(surf_lat14) = { l14, c82 , -l15 , -c72 } ; sl14[indice3] = newreg; Ruled Surface(sl14[indice3]) = { surf_lat14 } ;
surf_lat15 = newreg; Line Loop(surf_lat15) = { l15, c83 , -l16 , -c73 } ; sl15[indice3] = newreg; Ruled Surface(sl15[indice3]) = { surf_lat15 } ;
surf_lat16 = newreg; Line Loop(surf_lat16) = { l16, c84 , -l13 , -c74 } ; sl16[indice3] = newreg; Ruled Surface(sl16[indice3]) = { surf_lat16 } ;

Return


/////////////////////////////
// Generation des assemblages 
/////////////////////////////

   xc = x0;
   yc = y0;
   
   nbass=0;
   
   R_ass2= R_ass*R_ass;
   
   ind_max = Floor(1.16*R_ass)+1;
   

For i In { -ind_max:ind_max }
 For j In { -ind_max:ind_max }
 
 R_ij2 = i*i+j*j+i*j;

 If (R_ij2<=R_ass2)
   xc = x0+i*0.5*rac3*pas_ass;
   yc = y0+i*0.5*pas_ass+j*pas_ass;
   Call assemblage;
   nbass++;
 EndIf
 
 EndFor
EndFor

Printf(" %g assemblages créés " , nbass ) ;

/////////////////////////////
// Generation des reflecteurs 
/////////////////////////////

If (R_ref>0.)

   xc = x0;
   yc = y0;
   
   nbrefl=0;

   R_ref2 = R_ref*R_ref;

   ind_max = Floor(1.16*R_ref)+1;

For i In { -ind_max:ind_max }
 For j In { -ind_max:ind_max }
 
 R_ij2 = i*i+j*j+i*j;

 If (R_ij2>R_ass2)
  If (R_ij2<=R_ref2)
   xc = x0+i*0.5*rac3*pas_ass;
   yc = y0+i*0.5*pas_ass+j*pas_ass;
   Call reflecteur;
   nbrefl++;
  EndIf
 EndIf
 
 EndFor
EndFor

Printf(" %g reflecteurs créés " , nbrefl ) ;

EndIf

/////////////////////////////
// Generation des P.N.L. 
/////////////////////////////

If (R_pnl>0.)

   xc = x0;
   yc = y0;
   
   nbpnl=0;
   
   R_pnl2=R_pnl*R_pnl;

   ind_max = Floor(1.16*R_pnl)+1;

For i In { -ind_max:ind_max }
 For j In { -ind_max:ind_max }
 
 R_ij2 = i*i+j*j+i*j;

 If(R_ref==0.)
  R_ref2 = R_ass2;
 EndIf 
 
 If (R_ij2>R_ref2)
  If (R_ij2<=R_pnl2)
   xc = x0+i*0.5*rac3*pas_ass;
   yc = y0+i*0.5*pas_ass+j*pas_ass;
   Call pnl;
   nbpnl++;
  EndIf
 EndIf
 
 EndFor
EndFor

Printf(" %g P.N.L créés " , nbpnl ) ;

EndIf


//////////////////////////////////////////
// Generation de la cuve primaire (virole)
//////////////////////////////////////////

centre=newp; Point(centre) = { x0, y0, 0., lcar2 } ;

p11=newp; Point(p11) = { x0+r1 , y0    , 0., lcar2 } ;
p12=newp; Point(p12) = { x0    , y0+r1 , 0., lcar2 } ;
p13=newp; Point(p13) = { x0-r1 , y0    , 0., lcar2 } ;
p14=newp; Point(p14) = { x0    , y0-r1 , 0., lcar2 } ;

c11=newreg; Circle(c11) = { p11, centre, p12 } ;
c12=newreg; Circle(c12) = { p12, centre, p13 } ;
c13=newreg; Circle(c13) = { p13, centre, p14 } ;
c14=newreg; Circle(c14) = { p14, centre, p11 } ;

virole=newreg; Line Loop(virole) = { c11 , c12 , c13 , c14  } ;

/////////////////////////////////
// Generation de la partie coeur
/////////////////////////////////


If (kle==1) // assemblages seuls
inter_ass =newreg; Plane Surface(inter_ass)  = { virole , lbord[] } ;
EndIf

If (kle==3) // assemblages + reflecteurs
inter_ass =newreg; Plane Surface(inter_ass)  = { virole , lbord[], lbord2[] } ;
EndIf

If (kle==5) // assemblages + PNL
inter_ass =newreg; Plane Surface(inter_ass)  = { virole , lbord[], lbord3[] } ;
EndIf

If(kle==7) // assemblages + reflecteurs + PNL
inter_ass =newreg; Plane Surface(inter_ass)  = { virole , lbord[], lbord2[], lbord3[] } ;
EndIf


If (i_mesh==0)

Physical Line ("cuve_primaire_bas")  = { c11 , c12 , c13 , c14  } ;

	      Physical Line ("ass")  = { c[] } ;
If(R_ref>0.)  Physical Line ("refl") = { c2[] } ; EndIf
If(R_pnl>0.)  Physical Line ("pnl")  = { c4[] } ; EndIf

Physical Surface("inter_ass") = { inter_ass } ;


EndIf


If (i_mesh==1)

Physical Surface("ass") = { ass[] } ;


If(R_ref>0.)
Physical Surface("refl") = { refl[] } ;
EndIf

If(R_pnl>0.)
Physical Surface("pnl") = { pnl[] } ;
EndIf


Physical Surface("inter_ass") = { inter_ass } ;


/////////////////////////////////
// Génération du collecteur chaud
/////////////////////////////////


//*******************************************************************************
// extension de la cuve primaire jusqu'a l'epaulement collecteur chaud (virole1)
//*******************************************************************************

centreb=newp; Point(centreb) = { x0, y0, h1b, lcar2 } ;

p11b=newp; Point(p11b) = { x0+r1 , y0    , h1b, lcar2 } ;
p12b=newp; Point(p12b) = { x0    , y0+r1 , h1b, lcar2 } ;
p13b=newp; Point(p13b) = { x0-r1 , y0    , h1b, lcar2 } ;
p14b=newp; Point(p14b) = { x0    , y0-r1 , h1b, lcar2 } ;

c11b=newreg; Circle(c11b) = { p11b, centreb, p12b } ;
c12b=newreg; Circle(c12b) = { p12b, centreb, p13b } ;
c13b=newreg; Circle(c13b) = { p13b, centreb, p14b } ;
c14b=newreg; Circle(c14b) = { p14b, centreb, p11b } ;

virole1=newreg; Line Loop(virole1) = { c11b , c12b , c13b , c14b  } ;


//********************************************
// cuve du collecteur chaud (virole2b-virole2h)
//********************************************

p21=newp; Point(p21) = { x0+r2 , y0    , h1b, lcar2 } ;
p22=newp; Point(p22) = { x0    , y0+r2 , h1b, lcar2 } ;
p23=newp; Point(p23) = { x0-r2 , y0    , h1b, lcar2 } ;
p24=newp; Point(p24) = { x0    , y0-r2 , h1b, lcar2 } ;

c21=newreg; Circle(c21) = { p21, centreb, p22 } ;
c22=newreg; Circle(c22) = { p22, centreb, p23 } ;
c23=newreg; Circle(c23) = { p23, centreb, p24 } ;
c24=newreg; Circle(c24) = { p24, centreb, p21 } ;

virole2b=newreg; Line Loop(virole2b) = { c21 , c22 , c23 , c24  } ;

centre3=newp; Point(centre3) = { x0, y0, h2+h1b, lcar3 } ;

p31=newp; Point(p31) = { x0+r2 , y0    , h2+h1b, lcar3 } ;
p32=newp; Point(p32) = { x0    , y0+r2 , h2+h1b, lcar3 } ;
p33=newp; Point(p33) = { x0-r2 , y0    , h2+h1b, lcar3 } ;
p34=newp; Point(p34) = { x0    , y0-r2 , h2+h1b, lcar3 } ;

c31=newreg; Circle(c31) = { p31, centre3, p32 } ;
c32=newreg; Circle(c32) = { p32, centre3, p33 } ;
c33=newreg; Circle(c33) = { p33, centre3, p34 } ;
c34=newreg; Circle(c34) = { p34, centre3, p31 } ;

virole2h=newreg; Line Loop(virole2h) = { c31 , c32 , c33 , c34  } ;


//********************************************
// Generation du bcc (bccb-bcch)
//********************************************

centre2=newp; Point(centre2) = { x0, y0, h3, lcar } ;

p41=newp; Point(p41) = { x0+r3  , y0    , h3, lcar } ;
p42=newp; Point(p42) = { x0     , y0+r3 , h3, lcar } ;
p43=newp; Point(p43) = { x0-r3  , y0    , h3, lcar } ;
p44=newp; Point(p44) = { x0     , y0-r3 , h3, lcar } ;

c41=newreg; Circle(c41) = { p41, centre2, p42 } ;
c42=newreg; Circle(c42) = { p42, centre2, p43 } ;
c43=newreg; Circle(c43) = { p43, centre2, p44 } ;
c44=newreg; Circle(c44) = { p44, centre2, p41 } ;

bccb=newreg; Line Loop(bccb) = { c41 , c42 , c43 , c44  } ;

p51=newp; Point(p51) = { x0+r3  , y0     , h2+h1b, lcar2 } ;
p52=newp; Point(p52) = { x0     , y0+r3  , h2+h1b, lcar2 } ;
p53=newp; Point(p53) = { x0-r3  , y0     , h2+h1b, lcar2 } ;
p54=newp; Point(p54) = { x0     , y0-r3  , h2+h1b, lcar2 } ;

c51=newreg; Circle(c51) = { p51, centre3, p52 } ;
c52=newreg; Circle(c52) = { p52, centre3, p53 } ;
c53=newreg; Circle(c53) = { p53, centre3, p54 } ;
c54=newreg; Circle(c54) = { p54, centre3, p51 } ;

bcch=newreg; Line Loop(bcch) = { c51 , c52 , c53 , c54  } ;


//********************************************
// Generation des 6 echangeurs et des 3 pompes
//********************************************

For i In { 0:2 }  // Pompes

  xc = (x0+r4)*Cos(i*2*Pi/3);
  yc = (y0+r4)*Sin(i*2*Pi/3);

Call pompe_echangeur ;
 
EndFor


alpha = Pi/6;

For i In { 0:2 }  // Echangeurs_gauche

  xc = (x0+r4)*Cos(i*2*Pi/3+alpha);
  yc = (y0+r4)*Sin(i*2*Pi/3+alpha);

Call pompe_echangeur ;
 
EndFor

For i In { 0:2 }  // Echangeurs_droite

  xc = (x0+r4)*Cos(i*2*Pi/3-alpha);
  yc = (y0+r4)*Sin(i*2*Pi/3-alpha);

Call pompe_echangeur ;
 
EndFor


///////////////////////////////////////////////////////
// Generation des surfaces et des volumes du collecteur
///////////////////////////////////////////////////////

l1 = newreg; Line(l1) = { p21 , p31 } ;  l5 = newreg; Line(l5) = { p41 , p51 } ; 
l2 = newreg; Line(l2) = { p22 , p32 } ;  l6 = newreg; Line(l6) = { p42 , p52 } ; 
l3 = newreg; Line(l3) = { p23 , p33 } ;  l7 = newreg; Line(l7) = { p43 , p53 } ; 
l4 = newreg; Line(l4) = { p24 , p34 } ;  l8 = newreg; Line(l8) = { p44 , p54 } ; 

l1b = newreg; Line(l1b) = { p11 , p11b } ;
l2b = newreg; Line(l2b) = { p12 , p12b } ;
l3b = newreg; Line(l3b) = { p13 , p13b } ;
l4b = newreg; Line(l4b) = { p14 , p14b } ;

surf_lat1 = newreg; Line Loop(surf_lat1) = { l1, c31 , -l2 , -c21 } ; sl1 = newreg; Ruled Surface(sl1) = { surf_lat1 } ;
surf_lat2 = newreg; Line Loop(surf_lat2) = { l2, c32 , -l3 , -c22 } ; sl2 = newreg; Ruled Surface(sl2) = { surf_lat2 } ;
surf_lat3 = newreg; Line Loop(surf_lat3) = { l3, c33 , -l4 , -c23 } ; sl3 = newreg; Ruled Surface(sl3) = { surf_lat3 } ;
surf_lat4 = newreg; Line Loop(surf_lat4) = { l4, c34 , -l1 , -c24 } ; sl4 = newreg; Ruled Surface(sl4) = { surf_lat4 } ;

surf_lat1b = newreg; Line Loop(surf_lat1b) = { l1b, c11b , -l2b , -c11 } ; sl1b = newreg; Ruled Surface(sl1b) = { surf_lat1b } ;
surf_lat2b = newreg; Line Loop(surf_lat2b) = { l2b, c12b , -l3b , -c12 } ; sl2b = newreg; Ruled Surface(sl2b) = { surf_lat2b } ;
surf_lat3b = newreg; Line Loop(surf_lat3b) = { l3b, c13b , -l4b , -c13 } ; sl3b = newreg; Ruled Surface(sl3b) = { surf_lat3b } ;
surf_lat4b = newreg; Line Loop(surf_lat4b) = { l4b, c14b , -l1b , -c14 } ; sl4b = newreg; Ruled Surface(sl4b) = { surf_lat4b } ;

surf_lat5 = newreg; Line Loop(surf_lat5) = { l5, c51 , -l6 , -c41 } ; sl5 = newreg; Ruled Surface(sl5) = { surf_lat5 } ;
surf_lat6 = newreg; Line Loop(surf_lat6) = { l6, c52 , -l7 , -c42 } ; sl6 = newreg; Ruled Surface(sl6) = { surf_lat6 } ;
surf_lat7 = newreg; Line Loop(surf_lat7) = { l7, c53 , -l8 , -c43 } ; sl7 = newreg; Ruled Surface(sl7) = { surf_lat7 } ;
surf_lat8 = newreg; Line Loop(surf_lat8) = { l8, c54 , -l5 , -c44 } ; sl8 = newreg; Ruled Surface(sl8) = { surf_lat8 } ;

surf1 =newreg; Plane Surface(surf1)  = { virole2b , pompeb[], virole1 } ;
surf3 =newreg; Plane Surface(surf3)  = { virole2h , pompeh[], bcch } ;
surf4 =newreg; Plane Surface(surf4)  = { bccb } ;

collecteur[0] = newreg ;


If (kle==1) // assemblages seuls
Surface Loop(collecteur[0]) = { surf1, surf3, surf4, inter_ass,
 				ass[], 
				sl1, sl2, sl3, sl4, sl1b, sl2b, sl3b, sl4b, sl5, sl6, sl7, sl8 ,
				sl9[], sl10[], sl11[], sl12[],
				sl13[], sl14[],	sl15[], sl16[]  } ;
EndIf

If (kle==3) // assemblages + reflecteurs
Surface Loop(collecteur[0]) = { surf1, surf3, surf4, inter_ass,
 				ass[], refl[], 
				sl1, sl2, sl3, sl4, sl1b, sl2b, sl3b, sl4b, sl5, sl6, sl7, sl8 ,
				sl9[], sl10[], sl11[], sl12[],
				sl13[], sl14[],	sl15[], sl16[]  } ;
EndIf
 
If (kle==5) // assemblages + PNL
Surface Loop(collecteur[0]) = { surf1, surf3, surf4, inter_ass,
 				ass[], pnl[], 
				sl1, sl2, sl3, sl4, sl1b, sl2b, sl3b, sl4b, sl5, sl6, sl7, sl8 ,
				sl9[], sl10[], sl11[], sl12[],
				sl13[], sl14[],	sl15[], sl16[]  } ;
EndIf

If(kle==7) // assemblages + reflecteurs + PNL
Surface Loop(collecteur[0]) = { surf1, surf3, surf4, inter_ass,
 				ass[], refl[], pnl[], 
				sl1, sl2, sl3, sl4, sl1b, sl2b, sl3b, sl4b, sl5, sl6, sl7, sl8 ,
				sl9[], sl10[], sl11[], sl12[],
				sl13[], sl14[],	sl15[], sl16[]  } ;
EndIf

vol = newreg ; Volume(vol) = { collecteur[] } ;


Physical Surface("surf") = { surf1, surf3, surf4,
			     sl1, sl2, sl3, sl4, sl5, sl6, sl7, sl8,
			     sl9[ { 0:2 } ], sl10[ { 0:2 } ], sl11[ { 0:2 } ], sl12[ { 0:2 } ],
			     sl13[], sl14[], sl15[], sl16[]  } ;

Physical Surface("cuve_primaire_bas") = { sl1b, sl2b, sl3b, sl4b } ;

Physical Surface("echg1") = { sl9[ { 3,6 } ], sl10[ { 3,6 } ], sl11[ { 3,6 } ], sl12[ { 3,6 } ]  } ;
Physical Surface("echg2") = { sl9[ { 4,7 } ], sl10[ { 4,7 } ], sl11[ { 4,7 } ], sl12[ { 4,7 } ]  } ;
Physical Surface("echg3") = { sl9[ { 5,8 } ], sl10[ { 5,8 } ], sl11[ { 5,8 } ], sl12[ { 5,8 } ]  } ;

Physical Volume("dom") = { vol } ;

EndIf
