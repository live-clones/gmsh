// essai.geo
// plaque subductante

// definition des quantites

coef = 1e3; // coefficient multiplicateur --> en kilometres
taille_maille = 15*coef;
taille_maille2 = 20*coef;
taille_maille3 = 5*coef;


// axe des z
zero = 0; //"niveau de la mer"
base_croute = -10*coef; 
baselitho = -50*coef; // base de la lithosphere oceanique
baselitho_cont = -100*coef; // base de la lithosphere continentale
dessous = 1* (baselitho_cont + base_croute);
epaisseur_litho = base_croute - baselitho; // epaisseur de la lithosphere oceanique, signe positif
epaisseur_litho_cont = zero - baselitho_cont; // epaisseur de la lithosphere continentale, signe positif
centre = -200*coef; //centre du cercle de la zone de contact
rayon = -1*centre; //taille du rayon (nombre positif)
centre_bas = centre + base_croute;


// axe des y
devant = 0;
milieu = 10*coef;
derriere = 20*coef;


//axe des x
zonecontacth = 0*coef; // est fixe a base_croute le point en z=0
alpha = Acos ((rayon - epaisseur_litho_cont)/centre);
largeur_zonecontact = Tan(alpha)* (rayon - epaisseur_litho_cont); // calcul de la largeur selon x de la zone de contact entre les deux plaques
zonecontactb = zonecontacth + largeur_zonecontact; // abcisse du point a la base de la lithosphere
droite = 500*coef;

gamma = Atan (baselitho_cont/zonecontactb);
beta = Pi + ( (Pi/2) - gamma );
baselitho_arc = baselitho_cont + epaisseur_litho * Sin (beta); //selon z



// definition des points

Point (113) = {zonecontacth, derriere, baselitho, taille_maille2}; //
Point (114) = {droite, derriere, baselitho, taille_maille2}; //
Point (115) = {droite, derriere, base_croute, taille_maille}; //
Point (116) = {zonecontacth, derriere, base_croute, taille_maille}; //
Point (120) = {zonecontactb, derriere, dessous, taille_maille3}; //

Point (121) = {zonecontacth, milieu, baselitho, taille_maille2}; //
Point (122) = {droite, milieu, baselitho, taille_maille2}; //
Point (123) = {droite, milieu, base_croute, taille_maille}; //
Point (124) = {zonecontacth, milieu, base_croute, taille_maille}; //
Point (126) = {zonecontactb, milieu, dessous, taille_maille3}; //

Point (137) = {zonecontacth, milieu, centre_bas, taille_maille2}; //
Point (138) = {zonecontacth, derriere, centre_bas, taille_maille2}; //

// definition des lignes

Line (116) = {120, 113}; //
Line (117) = {113, 114}; //
Line (118) = {114, 115}; //
Line (119) = {115, 116}; //
Circle (120) = {116, 138, 120};  //

Line (126) = {126, 121}; //
Line (127) = {121, 122};//
Line (128) = {122, 123}; //
Line (129) = {123, 124}; //
Circle (130) = {124, 137, 126}; //

Line (132) = {126, 120}; //

Line (134) = {124,116}; //
Line (136) = {121, 113}; //

Line (138) = {123, 115}; //
Line (140) = {122, 114}; //


// definition des surfaces
Line Loop (108) = {-120,-119,-118,-117,-116};                  Plane Surface (108)={108};
Line Loop (109) = {126,127,128,129,130};                  Plane Surface (109) = {109};
Line Loop (111) = {116,-136,-126,132};                  Ruled Surface (111) = {111};
Line Loop (113) = {117,-140,-127,136};                  Plane Surface (113) = {113};
Line Loop (115) = {120,-132,-130,134};                  Ruled Surface (115) = {115};
Line Loop (117) = {119,-134,-129,138};                  Plane Surface (117) = {117};
Line Loop (119) = {118,-138,-128,140};                  Plane Surface (119) = {119};

// definition du volume
Surface Loop (3) = {108,109,111,113,115,117,119};         Volume (3) = {3};

