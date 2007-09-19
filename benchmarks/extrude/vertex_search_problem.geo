mm = 1e-3 ;
a = 20e-6 ; // grand rayon de l'Ã©lipse (en ÂµT)
b = 10e-6 ; // petit rayon de l'Ã©lipse (en ÂµT)
Phase = 0 ; // dÃ©phasage (je pense que je ne m'en servirai pas)
r_tete = 90*mm ;
ep_peau = 2*mm;
ep_os = 2*mm ;
r_g    = 70 *mm;
d_g    = 15*mm ; //dÃ©placement du centre du cerveau par rapport au centre de la tÃªte
centre_x_oeil = 73.1 *mm ;
centre_y_oeil = 30.1 *mm ;// centre_y_oeil * sin(23) ;
cote_casque = 390*mm ;
bord_casque = 6*mm ;
diam_spire	= 310*mm ;
Largeur_ind 	= 35*mm ;
Hauteur_ind	= 40*mm ;
s = 5;
lc_ind12 	= (Largeur_ind/5)*s/3 ;  

//Geometry.OldNewReg = 1;
//Geometry.AutoCoherence = 1;
//Mesh.CharacteristicLengthFactor = 1. ;

pIdev_int1 = newp; Point(pIdev_int1) = {cote_casque/2+bord_casque,diam_spire/2,0.,lc_ind12};
pIdev_int2 = newp; Point(pIdev_int2) = {cote_casque/2+bord_casque,diam_spire/2+Largeur_ind,0.,lc_ind12};
pIdev_ext1 = newp; Point(pIdev_ext1) = {cote_casque/2+bord_casque+Hauteur_ind,diam_spire/2,0.,lc_ind12};
pIdev_ext2 = newp; Point(pIdev_ext2) = {cote_casque/2+bord_casque+Hauteur_ind,diam_spire/2+Largeur_ind,0.,lc_ind12};

lIdev_int1 = newl ; Line (lIdev_int1) = {pIdev_int2, pIdev_int1};
lIdev_cotint1 = newl ; Line (lIdev_cotint1) = {pIdev_int1, pIdev_ext1};
lIdev_ext1 = newl ; Line (lIdev_ext1) = {pIdev_ext1, pIdev_ext2};
lIdev_cotext1 = newl ; Line (lIdev_cotext1) = {pIdev_ext2, pIdev_int2};

llIdev1 = newreg ; Line Loop (llIdev1) = {lIdev_int1,lIdev_cotint1,lIdev_ext1,lIdev_cotext1};
psIdev1 = newreg ; Plane Surface(psIdev1) = {llIdev1};


TRANS = 1; 
ns = 4 ;
If(TRANS)
Transfinite Line {lIdev_int1,lIdev_cotint1,lIdev_ext1, lIdev_cotext1}  = ns ;
Transfinite Surface {psIdev1} = {pIdev_int2,pIdev_int1,pIdev_ext1,pIdev_ext2};
EndIf

Recombine Surface{newreg-1} ;  

vol[]=Extrude Surface { newreg-1, {1,0,0} , {0,0,0} , Pi/4 }
{ Layers { 2, 1 } ; Recombine; };;
vIdev1[0] = vol[1];

